function [a1,b1] = first_order_regression(k,y,u)
% first order regression using least square method
% retrun parameters a1, b1 
if k < 3
    % k should be greater than 2 otherwise index error
    % will occur
    fprintf("Index error, k must be greater than 2\n");
    pause;
end
N = round(length(y)/2); % regression bases on first half's data
phi = zeros(length(k:N),2);
%build the phi matrix for first order model
for i = k:N
    phi(i-k+1,1) = y(i-1);
    phi(i-k+1,2) = u(i-1);
end
theta_hat = inv(phi'*phi)*phi'*y(k:N);
a1 = -theta_hat(1);
b1 = theta_hat(2);
end