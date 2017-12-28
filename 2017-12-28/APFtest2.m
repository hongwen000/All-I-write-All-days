function APFtest2()
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
        fsurf(@(X,Y) 0.03 * (X - centerx .^ 2 + Y - centery .^ 2) + getreject(X,Y,getobspos(timenow)), [-10 10 -10 10]);
        %view(0,90);
        title(['Time:', num2str(timenow), '  ', 'FPS', num2str(1.0/interval)])
    end
end

function obspos = getobspos(timenow)
    global speed
    global R
    omega = speed / R;
    idx = (1:4)';
    arc = mod((omega * timenow + idx .* (pi / 2)), (2 * pi));
    x = R .* cos(arc);
    y = R .* sin(arc);
    obspos = [x, y];
end

function reject = getreject(x,y,pos)
    global centerx
    global centery
    reject = 0;
    for idx = 1:4
        tab1 = sqrt((x - pos(idx,1)) .^ 2 + (y - pos(idx,2)) .^ 2);
    	tab2 = 0.2 * (1 ./ tab1 - 1 / 2) .^ 2 * ((x - centerx) .^ 2 + (y - centery) .^ 2);
        reject = reject +tab2 .* (tab1 <= 2);
    end
    reject = reject * (reject < 5);
end

