clear; clc; %clf;
a=load("datadla.txt");
figure(1)
plot(a(:,1),a(:,2),'.')
title('DLA')
xlabel('Συντεταγμένες x')
ylabel('Συντεταγμένες y')
% axis([300 350 25 75])
 hold on
% r=200;
% th = 0:pi/50:2*pi;
% xc = r * cos(th)+ r;
% yc = r * sin(th)+ r; 
% plot(xc, yc)

l=[10 20 30 40 50 60 70 80 90 100];
s(10)=0;
sf(20)=0;
for k=1:10
    for N=1:20
        num=(200+l(k)/2-(200-l(k)/2))*rand+(200-l(k)/2);
        min=num-l(k)/2;
        max=num+l(k)/2;
        for i=1:length(a(:,1))
            if (a(i,1)>=min) && (a(i,1)<=max) && (a(i,2)>=min) && (a(i,2)<=max)
                s(k)=s(k)+1;
            end
        end
    end
    ss(k)=s(k)/20;
end

figure(2)
plot(log10(l),log10(ss),'*')
title('Προσδιορισμός Φρακταλικής Διάστασης M(L)')
xlabel('Μήκος πλευράς τετραγώνων - log(L)')
ylabel('Πλήθος σωματιδίων - log(M)')
hold on
p=polyfit(log10(l),log10(ss),1);
yfit=polyval(p,log10(l));
plot(log10(l),yfit)
legend({['y=',num2str(p(1)),'*x + ','(',num2str(p(2)),')']},'location','west');

% axis([0 400 0 400])
% hold on
% plot(b(:,1),b(:,2),'r.')
% p1=plot(a(1:8283,1),a(1:8283,2),'.');
% set(p1,'color',[0 0 1])
% axis([0 1000 0 1000])
% hold on
% p2=plot(a(8284:16566,1),a(8284:16566,2),'.');
% set(p2,'color',[0.8 0.8 0.9])
% p3=plot(a(16567:24848,1),a(16567:24848,2),'.');
% set(p3,'color',[0.6 0.6 0.8])
% p4=plot(a(24849:33131,1),a(24849:33131,2),'.');
% set(p4,'color',[0.4 0.4 0.5])
% p5=plot(a(33132:41414,1),a(33132:41414,2),'.');
% set(p5,'color',[0.2 0.2 0.1])
% r=350;
% % plot(b(:,1),b(:,2),'.')
% th = 0:pi/50:2*pi;
% xc = r * cos(th)+ r;
% yc = r * sin(th)+ r; 
% plot(xc, yc)