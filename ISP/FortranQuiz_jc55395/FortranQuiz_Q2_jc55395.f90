! Name:        Justin Chao
! UT EID:      jc55395
! Course:      Introduction to Scientific Programming
! Assignment:  Fortran Quiz Question 2: Arrays

program Arrays
implicit none
integer :: i, j
real    :: X
real, dimension(10)    :: A, B
real, dimension(10,10) :: C, D

write (*,'(A/)') "========================== PROGRAM START =========================="
write (*, '(A)') "...Initializing x, arrays, and matrices with random numbers"
call random_number(X)
call random_number(A)
call random_number(B)
call random_number(C)
call random_number(D)

write (*, '(A)', advance='no') "x:"
write (*, "(3f8.3)") x

write (*, '(/A)', advance='no') "array A:"
call printArray(A)

write (*, '(//A)', advance='no') "array B:"
call printArray(B)

write (*, '(//A)') "matrix C:"
call printMatrix(C)

write (*, '(/A)') "matrix D:"
call printMatrix(D)

! set A equal to B
forall (i=1:10) A(i) = B(i)
write (*, '(/A)') "...set A equal to B"
write (*, '(A)', advance='no') "array A:"
call printArray(A)
    
! set all elements of A equal to X
forall (i=1:10) A(i) = X
write (*, '(//A)') "...set all elements of A equal to X"
write (*, '(A)', advance='no') "array A:"
call printArray(A)

! set A equal to first row of C
forall (i=1:10) A(i) = C(1,i)
write (*, '(//A)') "...set A equal to first row of C"
write (*, '(A)', advance='no') "array A:"
call printArray(A)

! set first 3 elements of A equal to last 3 elements of C
do i=1, 3
    A(i) = C(10, 7+i)
enddo
write (*, '(//A)') "...set first 3 elements of A equal to last 3 elements of C"
write (*, '(A)', advance='no') "array A:"
call printArray(A)

! set C equal to D
forall (i=1:10, j=1:10) C(i,j) = D(i,j)
write (*, '(//A)') "...set C equal to D"
write (*, '(A)') "matrix C:"
call printMatrix(C)


write (*,'(//A/)') "=========================== END PROGRAM ==========================="
end program

! Subroutines
subroutine printMatrix (matrix)
    real, dimension(10, 10) :: matrix
    integer :: i, j
    do i=1, 10
        do j=1, 10
            write (*,"(3f8.3)",advance="no") matrix(i,j)
        enddo
        print *
    enddo
end subroutine printMatrix

subroutine printArray (array)
    real, dimension(10) :: array
    integer :: i
    do i=1, 10
        write (*,"(3f8.3)", advance="no") array(i)
    enddo
end subroutine printArray
