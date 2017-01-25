! Name:        Justin Chao
! UT EID:      jc55395
! Course:      Introduction to Scientific Programming
! Assignment:  Fortran Quiz Question 3: Fortran IO

program FortranIO
implicit none
integer :: i, j
integer, dimension(100, 100) :: A, txtA, binA
real, dimension(100, 100)   :: B, C, txtB, binB

write (*,'(A/)') "========================== PROGRAM START =========================="
! create 2 100x100 matrices, one real, one integer.
! populate them with random numbers.
call random_number(C)
C = C*10
A = C
call random_number(B)
B = B*10

! print the matrices out using formatted write statements
write (*,'(A)') "matrix A:"
call printIntMatrix(A)

write (*,'(/A)') "matrix B:"
call printRealMatrix(B)

! write the 2 matrices out to 2 files, one text, one binary.
write (*,'(/A)') "...matrix A and B written to dataA.txt and dataB.txt"
open (1, file='dataA.txt', status='unknown')
open (2, file='dataB.txt', status='unknown')
    do i=1, 100
        do j=1, 100
            write (1, "(i8.2)",advance="no") A(j,i)
            write (2,*) B(j,i)
        enddo
        write (1, *)
        write (2, *)
    enddo
close (1)
close (2)


write (*,'(/A)') "...matrix A and B written to binaryDataA.bin and binaryDataB.bin"
open (3, file='binaryDataA.bin', form='unformatted', status='unknown')
open (4, file='binaryDataB.bin', form='unformatted', status='unknown')
write (3) A
write (4) B


close (3)
close (4)


! read the 2 matrices back out of the text file
! print the new matrices out using formatted write statements
write (*,'(/A)') "...reading matrix A from dataA.txt as txtA"
open (1, file='dataA.txt', status='unknown')
read (1, *) txtA
call printIntMatrix(txtA)

write (*,'(/A)') "...reading matrix B from dataB.txt as txtB"
open (1, file='dataB.txt', status='unknown')
read (1, *) txtB
call printRealMatrix(txtB)


! read the 2 matrices out from the binary file
! print the new matrices out using formatted write statement
write (*,'(/A)') "...reading matrix A from binaryDataA.bin as binA"
open (3, file='binaryDataA.bin', form='unformatted', status='unknown')
read (3) binA
call printIntMatrix(binA)

write (*,'(/A)') "...reading matrix B from binaryDataB.bin as binB"
open (4, file='binaryDataB.bin', form='unformatted', status='unknown')
read (4) binB
call printRealMatrix(binB)

close (1)
close (2)
close (3)
close (4)


! check that all matrices are equal
if (all(A == txtA .and. A == binA)) then
    write (*, '(/A)') 'matrices A, txtA, and binA are equal.'
else
    write (*, '(/A)') 'matrices A, txtA, and binA are not equal.'
endif

if (all(B == txtB .and. B == binB)) then
    write (*, '(/A)') 'matrices B, txtB, and binB are equal.'
else
    write (*, '(/A)') 'matrices B, txtB, and binB are not equal.'
endif

write (*,'(//A/)') "=========================== END PROGRAM ============================"
end program

! Subroutines
subroutine printIntMatrix (matrix)
    integer, dimension(100, 100) :: matrix
    integer :: i, j
    do i=1, 100
        do j=1, 100
            write (*, "(i8.2)",advance="no") matrix(i,j)
        enddo
        print *
    enddo
end subroutine printIntMatrix

subroutine printRealMatrix (matrix)
    real, dimension(100, 100) :: matrix
    integer :: i, j
    do i=1, 100
        do j=1, 100
            write (*,"(f8.3)",advance="no") matrix(i,j)
        enddo
        print *
    enddo
end subroutine printRealMatrix
