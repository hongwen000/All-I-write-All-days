


set _task= airpak.exe
set _svr=C:\Fluent.Inc\airpak2.1\bin.ntx86
set _des=C:\Fluent.Inc\ntbin\ntx86\
REM Set time back to 2012

cd %temp%
date /T > real_time.txt
sed -i "s/ .*//g" real_time.txt
sed "s/20[0-9][0-9]//g" real_time.txt > real_month_day.txt
echo 2012 > fake_time.txt
type real_month_day.txt >> fake_time.txt
sed -i ":a;N;$!ba;s/\n//g" fake_time.txt
sed -i "s/ //g" fake_time.txt
date < fack_time.txt

REM Start airpak
cd %_des%
set AIRPAK_INSTALL_LOCATION=%_des%..\..
set AIRPAK_ROOT=%AIRPAK_INSTALL_LOCATION%\airpak2.1
set FLUENT_INC=%AIRPAK_ROOT%\Fluent.Inc
set FLUENT_ARCH=ntx86
set FLUENT_LICENSE_PATH=%AIRPAK_INSTALL_LOCATION%\license\ntx86
set PATH=%AIRPAK_ROOT%\bin.ntx86;%PATH%
%AIRPAK_ROOT%\bin.ntx86\airpak %*

REM chek if airpak is running
:checkstart
for /L %%i in (1 1 3) do set /p a=.<nul&ping.exe /n 2 127.0.0.1>nul
for /f "tokens=5" %%n in ('qprocess.exe ^| find "%_task%" ') do (
if %%n==%_task% (goto checkstart) else goto reset
)

:reset
date < %temp%/real_time.txt
