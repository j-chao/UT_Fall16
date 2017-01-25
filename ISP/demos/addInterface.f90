program addInterfaceDemo
implicit none

interface add

   subroutine add_ints(i, j, k)
      integer :: i, j, k
   end subroutine

   subroutine add_floats(x, y, z)
      real (kind=8):: x, y, z
   end subroutine

end interface add

integer :: a = 10, b = 5, d
real (kind=8) :: x = 1.5, y = 3.14, z

call add(a,b,d)
print *, a, b, d
call add(x, y, z)
print *, x, y, z

end program



subroutine add_ints(i, j, k)
   implicit none
   integer :: i, j, k
   print *, "adding ints"
   k = i + j
end subroutine

subroutine add_floats(x, y, z)
   implicit none
   real :: x, y, z
   print *, "adding reals"
   z = x + y
end subroutine
