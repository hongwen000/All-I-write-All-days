program GrADS1127
    parameter(ml=0,ms=195,mt=672)
    integer nlev,nflag,irec,ist,it
    integer y(ms,mt),m(ms,mt),rain(ms,mt)
    parameter(nflag=1,nlev=nflag+ml)
    character*8 stid(ms)
    character*10 endstn
    real lat(ms),lon(ms),dtime(ms,mt)
    real ps(ms,mt),us(ms,mt)
    endstn = 'end_time'
         dtime=0.0
         open(unit=15,file='/Users/lixinrui/f.txt',form='formatted',status='old',access='sequential')
         do ist=1,ms
             do it=1,mt
                  read(15,100) y(ist,it),m(ist,it),stid(ist),lat(ist),lon(ist),rain(ist,it)
100                format(I8,I8,A8,F8.2,F8.2,I8)
             end do
         end do
        open(11,file='output.dat',form='unformatted',access='stream',status='new')
        do it=1,mt
            do ist=1,ms
                write(11) stid(ist),lat(ist),lon(ist),dtime(ist,it),nlev,nflag
                write(11) y(ist,it),m(ist,it),stid(ist),lat(ist),lon(ist),rain(ist,it)
            end do
            write(11)endstn,0.0,0.0,0.0,0,0
        end do
end
