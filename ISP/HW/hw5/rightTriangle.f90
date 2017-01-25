! Justin Chao
! rightTriangle.f90 determines if a given triangle is a right triangle,
! and calculates the hypotenuse, angles, and area.

module modTriangle

double precision, parameter :: Pi = 3.141592653589793
type , public :: triangle
    double precision    :: side_a, side_b, side_h, angle_a, angle_b, angle_h, area
end type

contains

    function calcHypo (tri)
        type(triangle)      :: tri
        double precision    :: calcHypo
        calcHypo = sqrt(tri%side_a**2 + tri%side_b**2)
    end function

    function isRight (tri)
        type(triangle)      :: tri
        logical             :: isRight
        ! check if any sides are <= 0
        if (tri%side_a <= 0 .or. tri%side_b <=0 .or. tri%side_h <=0) then
            isRight = .false.
        end if
        ! check if side_a^2 + side_b^2 = side_h^2
        if (tri%side_a**2 + tri%side_b**2 == tri%side_h**2) then 
            isRight = .true.
        else
            isRight = .false.
        end if
    end function

    function calcAngles (tri)
        type(triangle)      :: tri
        tri%angle_a = asin(tri%side_a / tri%side_h) * 180 / Pi
        tri%angle_b = asin(tri%side_b / tri%side_h) * 180 / Pi
        tri%angle_h = 90
    end function

    function calcArea (tri)
        type(triangle)      :: tri
        double precision    :: calcArea
        calcArea = (tri%side_a * tri%side_b)/2
    end function

end module

program rightTraingle
use modTriangle
implicit none
type(triangle)  :: myT
integer         :: angles

! prompt for 2 sides
print '(/a14/)', 'PROGRAM START'
print *, 'Enter a value for side 1: '
read *, myT%side_a
print *, 'Enter a value for side 2: '
read *, myT%side_b
print *, 'Enter a value for the hypotenuse (0 to calculate): '
read *, myT%side_h

! calculate Hypotenuse if prompted
if (myT%side_h == 0) then
    myT%side_h = calcHypo (myT)
end if

! print if triangle is not a right triangle and return/end program
if (isRight (myT) .eqv. .false.) then
    print '(/a57)', 'The following side lengths do not form a right triangle:'
    print '(f8.2)', myT%side_a, myT%side_b, myT%side_h
    print '(/a12/)', 'END PROGRAM'
    STOP
end if 

! print triangle attributes
angles = calcAngles (myT)
print '(/a7)', 'Sides: '
print '(f8.2)', myT%side_a, myT%side_b

print '(/a11)', 'Hypotenuse: '
print '(f8.2)', myT%side_h

print '(/a8)', 'Angles: '
print '(f8.2)', myT%angle_a, myT%angle_b, myT%angle_h

print '(/a5)', 'Area: '
print '(f8.2)', calcArea(myT)

print '(/a12/)', 'END PROGRAM'
end program
