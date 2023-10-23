%% Constantes
% Definición de las constantes utilizadas en el cálculo del campo magnético.

I = 100000000; % Corriente en Amperios
mue0 = 4*pi*10^(-7); % Permeabilidad magnética en el vacío
xstep = 0.5; % Paso de discretización en la dirección x
ystep = 0.5; % Paso de discretización en la dirección y
zstep = 0.5; % Paso de discretización en la dirección z
nx = 10; % Número de intervalos en la dirección x
ny = 10; % Número de intervalos en la dirección y
nz = 10; % Número de intervalos en la dirección z
RL = 1; % Radio del bucle de corriente
nL = 30; % Número de elementos en el bucle de corriente
count = 0; % Contador de iteraciones

%% Creación de la malla tridimensional
% Se crea una malla tridimensional utilizando los pasos de discretización
% y los intervalos definidos en las direcciones x, y y z.

xm = 0:xstep:nx;
ym = 0:ystep:ny;
zm = 0:zstep:nz;
[X, Y, Z] = meshgrid(xm, ym, zm);
Bx = zeros(size(X));
By = zeros(size(X));
Bz = zeros(size(X));

%% Creación del bucle de corriente
% Se crea un bucle de corriente cerrado mediante una parametrización de un
% bucle circular en el plano xy.

phi = linspace(0, 2*pi, nL);
xL = RL * cos(phi);
yL = RL * sin(phi);
zL = zeros(size(xL));
L = [xL', yL', zL'] + 0.5 * [nx * ones(size(xL')), ny * ones(size(xL')), nz * ones(size(xL'))];

%% Bucle principal
% Se itera sobre todos los puntos de la malla tridimensional y se calcula
% el campo magnético en cada punto debido al bucle de corriente.

for z = 0:zstep:nz
    for y = 0:ystep:ny
        for x = 0:xstep:nx
            for i = 1:1:nL
                count = count + 1;
                
                if i == nL
                    dL = L(end, :) - L(1, :);
                    vec = (L(end, :) + L(1, :)) * 0.5;
                else
                    dL = L(i+1, :) - L(i, :);
                    vec = (L(i+1, :) + L(i, :)) * 0.5;
                end
                
                vecR = [x, y, z];
                vecd = vecR - vec;
                
                dB = mue0 * I / (4*pi) * cross(dL', vecd') / (norm(vecd)^2);
                current_point = find(X == x & Y == y & Z == z);
                
                Bx(current_point) = Bx(current_point) + dB(1);
                By(current_point) = By(current_point) + dB(2);
                Bz(current_point) = Bz(current_point) + dB(3);
                
                %disp(num2str(count / ((nL) * (length(Bx(1, 1, :)) * length(Bx(1, :, 1)) * length(Bx(:, 1, 1))))));
            end
        end
    end
end
    
%% Procesamiento posterior
% Se realiza un procesamiento posterior para visualizar el campo magnético
% y el bucle de corriente en una figura tridimensional.

quiver3(X, Y, Z, Bx, By, Bz, 5);
hold on;
plot3(L(:, 1), L(:, 2), L(:, 3));
gca.PlotBoxAspectRatioMode = 'manual';

% Las líneas relacionadas con las líneas de flujo están comentadas en el código.
% Si deseas habilitarlas, puedes descomentarlas eliminando el símbolo "%" al inicio de cada línea.

% streamline(X, Y, Z, Bx, By, Bz, sX+nx/2, sY+ny/2, sZ+nx/2);
% streamline(X, Y, Z, Bx, By, Bz, L(1, 1), L(1, 2), L(1, 3)-1);
 streamline(X, Y, Z, Bx, By, Bz, X, Y, Z);