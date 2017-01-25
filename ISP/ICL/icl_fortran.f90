PROGRAM reading
IMPLICIT NONE
CHARACTER(len=20)                :: my_name
DOUBLE PRECISION a, b, c, Volume, dp_answer
DOUBLE PRECISION, PARAMETER      :: Pi = 3.141592653589793
INTEGER Res, int_answer
CHARACTER(len=1)                 :: Resp

! Hello <name>
print *, 'Enter your name'
read  *, my_name
print *, 'Hello ', my_name

Main: Do
    PRINT *, "What do you want to solve for? (Enter 0 to quit)"
    PRINT *, "1. Volume of sphere"
    PRINT *, "2. Volume of cuboid"
    PRINT *, "3. Conversion to integer"
    READ *, Res

    SELECT CASE (Res)
       CASE(1)
          CALL sphere()
       CASE(2)
          CALL cuboid()
       CASE(3) 
           CALL convert()
       CASE (0)
          EXIT Main
       CASE DEFAULT
          PRINT *, "Invalid input, please try again."
          CYCLE Main
    END SELECT
END DO Main

PRINT *, "Have a great day!"
STOP

CONTAINS
! ----------------------------------------------------------------
SUBROUTINE sphere
    PRINT *, "What is the radius of the sphere?"
    READ *, a

    Volume = (4./3.) * Pi * a ** 3

    PRINT *, "The volume of the sphere is: ", Volume

    PRINT *, "Find more (y/n)?"
    READ *, Resp
    SELECT CASE(Resp)
        CASE("n")
            PRINT *, "Have a great day!"
            STOP
        CASE Default
            RETURN
    END Select

END SUBROUTINE sphere

! ----------------------------------------------------------------
SUBROUTINE cuboid
    PRINT *, "What are the dimensions of the cuboid?"
    READ (*,*) a, b, c

    Volume = a * b * c

    PRINT *, "The volume of the cuboid is: ", Volume

    PRINT *, "Find more (y/n)?"
    READ *, Resp

    SELECT CASE(Resp)
        CASE("n")
            PRINT *, "Have a great day!"
            STOP
        CASE Default
            RETURN
    END Select

END SUBROUTINE cuboid


! ----------------------------------------------------------------
SUBROUTINE convert
    PRINT *, "Enter three numbers:"
    READ (*,*) a, b, c

    answer = (a * b * c)/7.

    print *, "(a * b * c) / 7 = ", int(answer)

    PRINT *, "Find more (y/n)?"
    READ *, Resp

    SELECT CASE(Resp)
        CASE("n")
            PRINT *, "Have a great day!"
            STOP
        CASE Default
            RETURN
    END Select

END SUBROUTINE convert

END PROGRAM reading
