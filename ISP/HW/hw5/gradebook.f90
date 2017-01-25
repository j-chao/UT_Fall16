! Justin Chao
! gradebook.f90 prompts for student names and grades, and outputs the array of students, 
! and the average grade.

module students

type student
    character(len=20)   :: name
    real                :: grade
end type student

end module


program gradebook
use students
implicit none

type(student), dimension(10) :: stClass
integer                      :: i, low, high, low_idx, high_idx
integer                      :: classSize = 10
real                         :: average = 0

! prompt for user input of 10 students
do i=1, classSize
    print *, 'Enter name of student'
    read '(a)', stClass(i)%name
    print *, 'Enter grade of student'
    read *, stClass(i)%grade
end do

low = stClass(1)%grade
low_idx = 1
high = stClass(1)%grade
high_idx = 1

! determine lowest and highest grades
! calculate class grade average
do i=1, classSize
    if (stClass(i)%grade < low) then 
        low = stClass(i)%grade
        low_idx = i
    end if
    if (stClass(i)%grade > high) then
        high = stClass(i)%grade
        high_idx = i
    end if

average = average + stClass(i)%grade
end do

average = average/classSize

! print list of students
do i=1, classSize
    if (i == low_idx) then
        write (*,'("Name: ",a, " Grade: ",f8.3, " (lowest score)")') &
            stClass(i)%name, stClass(i)%grade
    else if (i == high_idx) then
        write (*,'("Name: ",a, " Grade: ",f8.3, " (highest score)")') &
            stClass(i)%name, stClass(i)%grade
    else
        write (*,'("Name: ",a, " Grade: ",f8.3)') &
            stClass(i)%name, stClass(i)%grade
    end if
end do

! print class grade average
write (*, '("Class Grade Average: ", f8.3)') &
    average

end program
