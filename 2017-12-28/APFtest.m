function APFtest()
    global timenow
    timenow = 0;
    global new_t
    global old_t
    global obspos
    obspos = zeros(4,2);
    global speed
    speed = 0.33;
    timeresultion = 1;
    [X, Y] = meshgrid(-10: 0.1: 10);
    global centerx
    global centery
    centerx = 0;
    centery = 0;
    global dX;
    dX = X - centerx;
    global dY;
    dY = Y - centery;
    global R;
    R = 5;
    while true
        new_t = cputime;
        interval = new_t - old_t;
        old_t = new_t;
        pause(timeresultion);
        timenow = timeresultion + timenow;
        t_tic = cputime;
        Z = getattract();
        for idx = 1:4
            [obspos(idx,1), obspos(idx,2)] = getobspos(idx, timenow);
            Z = Z + getreject(X,Y,obspos(idx,1),obspos(idx,2));
        t_toc = cputime;
        Z = Z .* (Z < 2000);
        surf(X,Y,Z);
        view(0,90);
        title(['Time:', num2str(timenow), '  ', 'FPS', num2str(1.0/interval), '  ', 'CalcRate:', num2str(1.0/(t_toc - t_tic))])
        end
    end
end

function [x,y] = getobspos(idx, timenow)
    global speed
    global R
    omega = speed / R;
    arc = mod((omega * timenow + idx * (pi / 2)), (2 * pi));
    x = R * cos(arc);
    y = R * sin(arc);
end

function attract = getattract()
    global dX;
    global dY;
    attract = 0.03 * (dX .^ 2 + dY .^ 2);
end

function reject = getreject(x,y,xpos,ypos)
    global centerx
    global centery
    tab1 = sqrt((x - xpos) .^ 2 + (y - ypos) .^ 2);
    tab2 = 0.2 * (1 ./ tab1 - 1 / 2) .^ 2 * ((x - centerx) .^ 2 + (y - centery) .^ 2);
    reject = tab2 .* (tab1 <= 2);
end

