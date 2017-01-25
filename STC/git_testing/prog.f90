program invsqrt
integer, parameter :: N=1000000
real a(N);
    do i=1,N; 
        a(i)=i; 
    end do

    call isqrt(a,N);
    print*,"N a(1) a(N): ", N,a(1),a(N)

end program
