program main
    implicit none
    integer A(2,3),C(3,2),D(3),E(1:2,1:3),F(1:3)
    integer i,j
    real B(2,3)
    data A/1,4,2,5,3,6/
    data B/-1.1,-4.1,-2.1,-5.1,-3.1,-6.1/
    data D/1,2,3/
    data C/1,3,5,2,4,6/
    where(A<=2)
        B=ABS(B)
    elsewhere
        B=B+1
    end where
    do i=1,2
        write(*,*) B(i,:)
    end do
    end



