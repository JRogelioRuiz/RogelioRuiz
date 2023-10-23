format long
radio = 0.5; 
Corriente = 1000000000;
mu0 = 4 * pi * 10^-7;
masaAnillo = 550;
momentoIman = 4*Corriente*pi*radio^2;
% Resistencia del material, en este caso Cobre
longEspira = 2*pi*radio;
resC = 1.72*10^-8;
% Área donde afecta la resistencia
areaEfectiva = longEspira*3;
% Resistencia a través de la espira o anillo
R = resC*(longEspira/areaEfectiva);

f = @(v) v;
g = @(z, v) -9.81 - ((9*(momentoIman^2)*(mu0^2)*(radio^4))/ ...
    (4*R * masaAnillo))*(z^2/(z^2 + radio^2)^5)*v;
h = 0.0001;
t = 0:h:7;
a = zeros(size(t));
v = zeros(size(t));
v(1) = 0;
s = zeros(size(t));
s(1) = 100;


for i = 1:length(t) - 1
    K1 = f(v(i));
    L1 = g(s(i), v(i));
    a(i) = L1;
    
    K2 = f(v(i) + L1 * h/2);
    L2 = g(s(i) + K1 * h/2,v(i) + L1 * h/2);
    
    K3 = f(v(i) + L2 * h/2);
    L3 = g(s(i)+ K2*h/2,v(i)+L2*h/2);
    
    K4 = f(v(i) + L3 * h);
    L4 = g(s(i) + K3 * h,v(i) + L3 * h);
    
    s(i + 1) = s(i) + (1/6)*(K1 + 2*K2 + 2*K3 + K4) * h;
    v(i + 1) = v(i) + (1/6)*(L1 + 2*L2 + 2*L3 + L4) * h;
end

plot(t,s)
title('Posición - Tiempo');
xlabel('t');
ylabel('s');

plot(t,v)
title('Velocidad - Tiempo');
xlabel('t');
ylabel('v');

plot(t,a)
title('Aceleración - Tiempo');
xlabel('t');
ylabel('a');