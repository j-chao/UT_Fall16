module demoModule
contains

    subroutine HelloPublic
        print *, "Hello World"
    end subroutine
    subroutine HelloPrivate
        print *, "Hello my little world"
    end subroutine    

end module


program HelloWorld

    use demoModule
    call HelloPublic
    call HelloPrivate

endprogram
