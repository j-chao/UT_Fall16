module lineMaster

type, public :: line3d

    real :: x1, y1, z1, x2, y2, z2

end type

contains

function length_x(line)
    type(line3d) :: line
    real :: length_x
    length_x = line%x1 - line%x2
end function

function length_y(line)
    type(line3d) :: line
    real :: length_y
    length_y = line%y1 - line%y2
end function

function length_z(line)
    type(line3d) :: line
    real :: length_z
    length_z = line%z1 - line%z2
end function

end module


program moduleDemo

use lineMaster

type(line3d) :: myline

myline%x1 = 2.5
myline%y1 = 3.5
myline%z1 = 4.5

myline%x2 = 0
myline%y2 = 0
myline%z2 = 0

print *, myline
print *, length_x(myline)
print *, length_y(myline)
print *, length_z(myline)

end program
