! Name:        Justin Chao
! UT EID:      jc55395
! Course:      Introduction to Scientific Programming
! Assignment:  Fortran Quiz Question 1: Control Structures

program ControlStructures
implicit none
integer :: i, j
real    :: sum, average
real, dimension(10, 10) :: A, transA
real, dimension(10)     :: arrayCols, arrayRows, traceA

write (*,'(A/)') "========================== PROGRAM START =========================="
write (*, '(A)') "...Initializing 10x10 matrix A with random numbers"
call random_number(A)
A = A*10

call printMatrix(A)

! sum cols of matrix A into new arrayCols
do i=1, 10
    do j=1, 10
        arrayCols(i) = arrayCols(i) + A(j,i)
    enddo
enddo
write (*,'(/A)') "...Row sums of matrix A"
call printArray(arrayCols)

! sum rows of matrix A into new arrayRows
do i=1, 10
    do j=1, 10
        sum = sum + A(i,j)
    enddo
    arrayRows(i) = sum
enddo
write (*,'(//A)') "...Row sums of matrix A"
call printArray(arrayRows)

! trace of matrix A as traceA
sum = 0
FORALL (i=1:10) traceA(i) = A(i,i)
write (*,'(//A)') "...Trace of matrix A"
do i=1, 10
    sum = sum + traceA(i)
enddo
write (*,"(3f8.3)") sum

! transpose of matrix A as transA
FORALL (i=1:10, j=1:10) transA (i,j) = A (j,i)
write (*,'(/A)') "...Transpose of matrix A"
call printMatrix (transA)

! calculate average and replace matrix accordingly, as binA
sum = 0
do i=1, 10
    do j=1, 10
        sum = sum + A(i,j)
    enddo
enddo
average = sum/100

do i=1, 10
    do j=1, 10
        if (A(i,j) > average) then
            A(i,j) = 1
        else
            A(i,j) = 0
        endif
    enddo
enddo
write (*,'(//A)') "...matrix A with replaced values"
call printMatrix(A)


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
