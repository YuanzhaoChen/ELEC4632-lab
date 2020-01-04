%clear;close all;clc
% t =[-10:0.1:10];
% mu = 1;
% sigma = 1;
% f = (1/(sigma*sqrt(2*pi)))*exp(-(t-mu).^2/(2*sigma^2));
% plot(t,f)
iterations = 8000;
up_array = zeros([1 iterations]); % store number of 'up' in each test
for j=1:iterations
    
    num_test = 10000;
    results = rand([1 num_test]);
    for i=1:length(results)
        if(results(i) > 0.5)
            results(i) = 1;
        else
            results(i) = 0;
        end
    end
    up_rate = length(find(results==1))/num_test;
    up_array(j) = up_rate;
    
end
hist(up_array)
fprintf('standard deviation for %d number of test is: %f\n',num_test,std(up_array))