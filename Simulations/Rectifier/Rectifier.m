clc;clear all;
n=1;
thvi=0;
maxth=2*pi;
for th=0:0.001:maxth
    sa(n)=sin(th);
    sb(n)=sin(th-(2*pi/3));
    sc(n)=sin(th+(2*pi/3));
    ia(n)=sin(th+thvi);
    ib(n)=sin(th-(2*pi/3)+thvi);
    ic(n)=sin(th+(2*pi/3)+thvi);
    sp(n)=max(max(sa(n),sb(n)),sc(n));
    sn(n)=min(min(sa(n),sb(n)),sc(n));
    if (sp(n)==sa(n))
        ip(n)=ia(n);
    end
    if (sp(n)==sb(n))
            ip(n)=ib(n);
    end
    if (sp(n)==sc(n))
         ip(n)=ic(n);
    end
    if (sn(n)==sa(n))
        in(n)=ia(n);
    end
    if (sn(n)==sb(n))
            in(n)=ib(n);
    end
    if (sn(n)==sc(n))
         in(n)=ic(n);
    end
    sd1(n)=sa(n)-sp(n);
    sd2(n)=sn(n)-sc(n);
    il(n)=ip(n)-in(n);
    n=n+1;
end

hold on;
% plot(0:0.001:maxth,il);
% plot(0:0.001:maxth,sp-sn);
% plot(0:0.001:maxth,il.*(sp-sn));
plot(0:0.001:maxth,il.*(sp-sn));
% plot(0:0.001:maxth,va);
% plot(0:0.001:maxth,il.*(sp-sn));
