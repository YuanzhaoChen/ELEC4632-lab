function [a1,a2,b1,b2] = second_order_regression(k,y,u)
% Second order model using least square method
% return parameters a1, a2, b1, b2

if k < 3
    % k should be greater than 2 otherwise index error
    % will occur
    fprintf("Index error, k must be greater than 2\n");
    pause;
end
N = round(length(y)/2); % regression bases on first half's data
%build the phi matrix for second order model
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
end