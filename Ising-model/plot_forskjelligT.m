clear 'all'
%NB: all the systems start with an ordered spin configuration

infoN40 = importdata('forskjelligTN40.dat');
%MCnumber = 3000*N*N
temperaturesN40 = infoN40(:, 1);
energyN40 = infoN40(:, 2);
magnetN40 = infoN40(:, 3);
heat_capacityN40 = (infoN40(:, 4));
susceptibilityN40 = infoN40(:, 5);

infoN60 = importdata('forskjelligTN60.dat');
%MCnumber = 1400*N*N

temperaturesN60 = infoN60(:, 1);
energyN60 = infoN60(:, 2);
magnetN60 = infoN60(:, 3);
heat_capacityN60 = infoN60(:, 4);
susceptibilityN60 = infoN60(:, 5);

infoN100 = importdata('forskjelligTN100.dat');
%MCnumber = 480*N*N
temperaturesN100 = infoN100(:, 1);
energyN100 = infoN100(:, 2);
magnetN100 = infoN100(:, 3);
heat_capacityN100 = infoN100(:, 4);
susceptibilityN100 = infoN100(:, 5);

infoN140 = importdata('forskjelligeTN140.dat');
temperaturesN140 = infoN140(:, 1);
energyN140 = infoN140(:, 2);
magnetN140 = infoN140(:, 3);
heat_capacityN140 = infoN140(:, 4);
susceptibilityN140 = infoN140(:, 5);

figure(1)
plot(temperaturesN40, susceptibilityN40, '+-')
hold 'on'
plot(temperaturesN60, susceptibilityN60, '+-')
plot(temperaturesN100, susceptibilityN100, '+-')
plot(temperaturesN140, susceptibilityN140, '+-')
hold 'off'
legend('N = 40', 'N = 60', 'N = 100', 'N = 140');
xlabel('Temperature [T_c]'); ylabel('Susceptibility [1/kT]');

figure(2)
plot(temperaturesN40, heat_capacityN40, '+-')
hold 'on'
plot(temperaturesN60, heat_capacityN60, '+-')
plot(temperaturesN100, heat_capacityN100, '+-')
plot(temperaturesN140, heat_capacityN140, '+-')
hold 'off'
legend('N = 40', 'N = 60', 'N = 100', 'N = 140');
xlabel('Temperature [T_c]'); ylabel('Heat Capacity [1/kT^2]');

figure(3)
plot(temperaturesN40, energyN40, '+-')
hold 'on'
plot(temperaturesN60, energyN60, '+-')
plot(temperaturesN100, energyN100, '+-')
plot(temperaturesN140, energyN140, '+-')
hold 'off'
legend('N = 40', 'N = 60', 'N = 100', 'N = 140');
xlabel('Temperature [T_c]'); ylabel('Energy expectation value [J]');

figure(4)
plot(temperaturesN40, magnetN40, '+-')
hold 'on'
plot(temperaturesN60, magnetN60, '+-')
plot(temperaturesN100, magnetN100, '+-')
plot(temperaturesN140, magnetN140, '+-')
hold 'off'
legend('N = 40', 'N = 60', 'N = 100', 'N = 140');
xlabel('Temperature [T_c]'); ylabel('Magnetization expectation value ');