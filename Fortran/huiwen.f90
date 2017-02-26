program main
    integer a
    integer msd,lsd
    do a=100,999
        msd=a/100
        lsd=mod(a,10)
        if(msd == lsd) then
            print *, a
        end if
    end do
    end

