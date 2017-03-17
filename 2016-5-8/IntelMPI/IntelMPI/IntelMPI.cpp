// IntelMPI.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "mpi.h"
#include <iostream>

int main(int argc, char *argv[])
{
	int i, rank, size, namelen;
	char name[MPI_MAX_PROCESSOR_NAME];
	MPI::Status stat;

	MPI::Init(argc, argv);

	size = MPI::COMM_WORLD.Get_size();
	rank = MPI::COMM_WORLD.Get_rank();
	MPI::Get_processor_name(name, namelen);

	if (rank == 0) {

		std::cout << "Hello world: rank " << rank << " of " << size << " running on " << name << "\n";

		for (i = 1; i < size; i++) {
			MPI::COMM_WORLD.Recv(&rank, 1, MPI_INT, i, 1, stat);
			MPI::COMM_WORLD.Recv(&size, 1, MPI_INT, i, 1, stat);
			MPI::COMM_WORLD.Recv(&namelen, 1, MPI_INT, i, 1, stat);
			MPI::COMM_WORLD.Recv(name, namelen + 1, MPI_CHAR, i, 1, stat);
			std::cout << "Hello world: rank " << rank << " of " << size << " running on " << name << "\n";
		}

	}
	else {

		MPI::COMM_WORLD.Send(&rank, 1, MPI_INT, 0, 1);
		MPI::COMM_WORLD.Send(&size, 1, MPI_INT, 0, 1);
		MPI::COMM_WORLD.Send(&namelen, 1, MPI_INT, 0, 1);
		MPI::COMM_WORLD.Send(name, namelen + 1, MPI_CHAR, 0, 1);

	}

	MPI::Finalize();

	return (0);
}

