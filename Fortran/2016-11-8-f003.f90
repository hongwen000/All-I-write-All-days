program integer 
    integer A(5,4)
    integer i,j
    do i=1,4
        read(*,*) A(1:5,i)
    end do
!    A(1:20)=A(20:1:-1)
    write(*,"(1x,10i4,/,10i4)") A
    end

