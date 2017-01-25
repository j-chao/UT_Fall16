subroutine isqrt(a, n)
    integer :: n,i
    real    :: a(n)
!                   Vector inverse square
!                   Someone advised to
!                   making two separate loops.
!           combined both loops
    do i=1,n;
        a(i) = sqrt(a(i)); 
        a(i) = 1.0e0/a(i);
    end do
end subroutine
