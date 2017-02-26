program ex02
real a(20)
integer i,k
do k=1,4
    write(*,*)k,"line=?"
    read(*,*) a(5*k-4),a(5*k-3),a(5*k-2),a(5*k-1),a(5*k)
end do
a(1:20)=a(20:1:-1)
write(*,"(10F8.3,/,10F8.3)") a
end