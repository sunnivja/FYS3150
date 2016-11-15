 clear 'all'
% info = importdata('N20T1orderedsystem.dat');
% info2 = importdata('N20T1randomsystem.dat');
% MC_cycles = info(:, 1);
% Energy_exp = info(:, 2);
% Energy_exp_squared = info(:, 3);
% Magnetic_moment_exp = info(:, 4);
% Magnetic_moment_exp_squared = info(:, 5);
% accepted_states = info(:, 6);
% 
% figure(1)
% plot(MC_cycles, accepted_states)
% hold 'on'
% plot(MC_cycles, info2(:, 6))
% xlabel('Number of MC cycles')
% ylabel('Number of accepted states')
% legend('Ordered system', 'Random system')
% 
% figure(2)
% plot(MC_cycles, info(:, 2))
% hold 'on'
% plot(MC_cycles, info2(:, 2))
% xlabel('Number of MC cycles')
% ylabel('Energy expectation value [TJk_B]')
% legend('Ordered system', 'Random system')
% 
% figure(3)
% plot(MC_cycles, info(:, 4))
% hold 'on'
% plot(MC_cycles, info2(:, 4))
% xlabel('Number of MC cycles')
% ylabel('Magnetization expectation value')
% legend('Ordered system', 'Random system')

% figure(4)
info3 = importdata('N20T1energies.dat');
var(info3(5000:3000000, 2)./400)
plot(histogram(info3(5000:3000000, 2)./400, 10, 'Normalization', 'probability'))
xlabel('Energy [kT/J]')
ylabel('Probability')
%subfigure(2, 1, 2)
%plot(MC_cycles(5000:10000), Energy_exp_squared(5000:10000) - Energy_exp(5000:10000).^2)
%hold('on')
%plot(Energy_exp_squared - Energy_exp.^2)

 %plot(MC_cycles, info(:, 4))
 %hold('on')
 %plot(MC_cycles, info2(:, 4))
 %xlabel('Number of Monte Carlo cycles')
 %ylabel('Energy expectation value [J]')
 %legend('Ordered system', 'Random system')
%probability_distribution = histogram(Energy_exp(300:1090), 10, 'Normalization', 'probability');
%plot(hist)
