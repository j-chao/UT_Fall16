program arrayDemo

implicit none

integer :: i, j
integer, dimension(10,10) :: a = 1

do i=1,10
   do j=1, 10

      a(i,j) = 1;

   end do
end do

call arrayRead(a)
contains

subroutine arrayRead(b)
integer i, j
integer, dimension (:,:) :: b

print *, size(b), size(b,1), size(b,2)
do i = 1, size(b,1)
   do j = 1, size(b,2)

     print *, b(i,j)

   end do
end do
end subroutine

end program
