    program Console6

    implicit none
    
    real A(5,3)
    real sum,sum_inter
    integer i,j
    i=1
    j=1
    sum=0
    data A/1,1,1,2,2,2,3,3,3,4,4,4,5,5,5/
    do i=1,3
         do j=1,5
             sum=sum+A(j,i)
         end do 
    end do
    sum_inter=sum(A)
    end program Console6

