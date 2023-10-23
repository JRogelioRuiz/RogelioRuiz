clc; clear; close all;

% Constante de Coulomb
k = 9*10^9;

% Input de las cargas y sus posiciones en el plano cartesiano
q1 = input("Valor de la carga: ") * k;
q2 = -1*q1; % q2 es el valor opuesto a q1 

q1_pos = [input("Posición X de la carga positiva: "), 0];
d = input("Distancia entre cargas: ");
q2_pos = [q1_pos(1) + d, 0];

% Vectores
[x,y,ex,ey,exn,eyn] = deal([]);

% Región de impresión
for i = q1_pos(1)-(d):q2_pos(1)+(d)
    for j = q1_pos(2)-(d):q2_pos(2)+(d)
        
        % Posición actual de i y j
        x(end+1) = i; 
        y(end+1) = j; 
        
        % Ecuación del campo eléctrico divida en numerador y denominador
        num1 = k*q1*(x(end)-q1_pos(1));
        num2 = k*q1*(x(end)-q2_pos(1));

        denom1 = (((x(end)-q1_pos(1))^2) + ((y(end)-q1_pos(2))^2))^(3/2);
        denom2 = (((x(end)-q2_pos(1))^2) + ((y(end)-q2_pos(2))^2))^(3/2);

        % Componente en x del campo eléctrico
        ex(end+1) = ((num1/denom1) - (num2/denom2)); 
        
        % Numerador again
        num1 = k*q1*(y(end)-q1_pos(2));
        num2 = k*q1*(y(end)-q2_pos(2));

        % Componente y del campo eléctrico
        ey(end+1) = ((num1/denom1) - (num2/denom2));

        % Normalizamos el valor de las componentes
        vlength = sqrt(((ex(end))^2) + ((ey(end))^2));
        exn(end+1) = ex(end)/vlength;
        eyn(end+1) = ey(end)/vlength;
    end
end


% Plot del campo
axis equal
subplot(1,1,1)

hold on
quiver(x,y,exn,eyn, "Color", "#5A5A5A") % Pone las flechas en el plot
plot(q1_pos(1), q1_pos(2), color ="#990000", Marker =".", MarkerSize = 69) %Representa el punto 1
plot(q2_pos(1), q2_pos(2), color ="#3E77B6", Marker =".", MarkerSize = 69) %Representa el punto 2
hold off
