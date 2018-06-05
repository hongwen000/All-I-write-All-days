program main
  implicit none
  real a(2, 3)
  call fun2(a, 2, 3)
  write (*, '(6f3.0)') a
end program main

subroutine fun2(aaa, m, n)
  integer m, n
  real aaa(m, n)
  aaa = 2
end subroutine fun2

