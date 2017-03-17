
subroutine cross_3d ( x1, y1, z1, x2, y2, z2, x3, y3, z3 )
!***************************************************
!! CROSS_3D computes the cross product of two vectors in 3D.
!
!  Definition:
!
!    The cross product in 3D can be regarded as the determinant of the
!    symbolic matrix:
!
!          |  i  j  k |
!      det | x1 y1 z1 |
!          | x2 y2 z2 |
!
!      = ( y1 * z2 - z1 * y2 ) * i
!      + ( z1 * x2 - x1 * z2 ) * j
!      + ( x1 * y2 - y1 * x2 ) * k
!  Modified:
!    19 April 1999
!  Author:
!    John Burkardt
!  Parameters:
!    Input, real X1, Y1, Z1, X2, Y2, Z2, the coordinates of the vectors.
!    Output, real X3, Y3, Z3, the cross product vector. 
  implicit none
  real(8) x1
  real(8) x2
  real(8) x3
  real(8) y1
  real(8) y2
  real(8) y3
  real(8) z1
  real(8) z2
  real(8) z3
  x3 = y1 * z2 - z1 * y2
  y3 = z1 * x2 - x1 * z2
  z3 = x1 * y2 - y1 * x2
end subroutine cross_3d