program main
    implicit none
    character(len=20)::string
    open(unit=10,file="test.txt")
    write(10,"(A20)")"Good morning."
    rewind(10)
    read(10,"(A20)") string
    write(*,"(A20)") string
    stop
    end
