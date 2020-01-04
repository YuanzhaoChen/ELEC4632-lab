%% ELEC4632 lab 5
clear
close all
clc
load SysIdenData_1.mat
t = LogData.time;
y_act = LogData.signals(1).values(:,2);
y_actm = LogData.signals(1).values(:,1);
u_act = LogData.signals(2).values;
figure()
plot(t,y_act)
title('Raw data')
xlabel('Time (sec)')
ylabel('Pump Voltage (V)')
grid on
% truncate the first period, keep data afer 800.25 seconds
index = find((t==585));
y_act = y_act(index:end);
y_actm = y_actm(index:end);
u_act = u_act(index:end);
t = t(1:length(u_act));
Ts = (t(end)-t(1))/(length(t)-1); % find sampling time
%Ts = t(2)-t(1);
fprintf('sampling time according to calculation is %d\n',Ts);
figure()
subplot(2,1,1)
hold on
plot(t,y_act,'b');

xlabel('Time (sec)');
ylabel('WaterLevel (V)');
title('Actual signal');
grid on
plot(t,y_actm,'r');
legend('Noised-Reduced Output','Measured Output');
hold off
subplot(2,1,2)
plot(t,u_act);
xlabel('Time (sec)');
ylabel('Pump voltage (V)');
title('Actual Input Signal');
legend('Actual input');
ylim([0 2.5]);
grid on

% remove input offset
u_offset = u_act(1);
u = u_act - u_offset;

figure()
subplot(2,1,2)
plot(t,u)
xlabel('Time (sec)');
ylabel('Pump Voltage (V)');
title('Actual Offset-Free Input Signal');
ylim([-0.5 0.5])
legend('Actual Input');
grid on
% remove output offset
count = 0;
i = 1;
while(u_act(i+1) == u_act(i))
    i=i+1;
    count = count + 1;
end
y_offset = mean(y_act(1:count));
y = y_act - y_offset;
subplot(2,1,1);
plot(t,y,'r')
grid on
xlabel('Time (sec)');
ylabel('Water Level (V)');
title('Actual Offset-Free Output Signal');
legend('Actual Output');

N = round(length(y)/2);
% start from k = 10, k should be greater than 2 
k = 10;
phi = zeros(length(k:N),4);

for i = k:N
    phi(i-k+1,1) = y(i-1);
    phi(i-k+1,2) = y(i-2);
    phi(i-k+1,3) = u(i-1);
    phi(i-k+1,4) = u(i-2);
end

theta_hat = inv(phi'*phi)*phi'*y(k:N);
a1 = -theta_hat(1);
a2 = -theta_hat(2);
b1 = theta_hat(3);
b2 = theta_hat(4);

%[a1,a2,b1,b2] = second_order_regression(k,y,u);
H = tf([b1 b2],[1 a1 a2],Ts);
fprintf('Info about second order state space model is below:\n');
sys = ss(H)

figure()
%simulate second half
subplot(2,1,1)
b = [b1 b2];
a = [1 a1 a2];
y_simulate_2nd_Half = filter(b,a,u(N:end));
plot(t(N:end),y_simulate_2nd_Half,'--');
hold on
plot(t(N:end),y(N:end),'r');
grid on
xlabel('Time (sec)');
ylabel('Water Level (V)');
legend('Simulated Output','Actual Output');
title('Offset-Free Model Verification (2^{nd} Half)');
hold off
% simulate entire
subplot(2,1,2)
y_simulate_entire_2nd_order = filter(b,a,u);
plot(t,y_simulate_entire_2nd_order,'--');
hold on
plot(t,y,'r')
grid on
xlabel('Time (sec)');
ylabel('Water Level (V)');
legend('Simulated Output','Actual Output');
title('Offset-Free Model Verification (Entire)');
MSE_val = immse(y,y_simulate_entire_2nd_order)

% state space model
G = [0 1; -a2 -a1;];
H = [0; 1;];
C = [b2 b1];
D = 0;
% observer form
G_obsrv = G';
H_obsrv = C';
C_obsrv = H';
D_obsrv = 0 ;
sys = ss(G_obsrv,H_obsrv,C_obsrv,D_obsrv,Ts)
D_obsrv = 0 ;


load SFControlData_0.mat
sim('lab5_model.slx')
treal = SFLogData.time;
yref = SFLogData.signals(1).values(:,1);
yreal = SFLogData.signals(1).values(:,2);
input_simulated = sim_in.signals.values;
output_simulated = sim_out.signals.values(:,2);
t_simulated = sim_in.time;
ureal = SFLogData.signals(2).values;

figure()
subplot(2,1,1)
plot(treal,yref,'g')
hold on
plot(treal,yreal,'r')
plot(t_simulated,output_simulated + y_offset,'b')
grid on
ylabel('Water Level(V)')
xlabel({'Time(sec)';'(a)'})
title({'PID Control Results';'Output Signal'})
legend('Reference Output','Actual Output','Simulated Output')

subplot(2,1,2)
plot(treal,ureal,'r')
hold on
plot(t_simulated,input_simulated + u_offset,'b')
xlabel('Pump Voltage (V)')
ylabel({'Time (sec)';'(b)'})
title('Control Input Signal')
legend('Actual Output','Simulated Output')
grid on



