function y = myMSE(x1,x2)
    %% Calculate mean square error of two sequences
    x1_length = length(x1);
    x2_length = length(x2);
    % check whether both data have the same length 
    if x1_length ~= x2_length
        fprintf("Two data should have the same length");
        y = -1; %indicate an error
        pause;
    else
        N = x1_length;
        MSE = 0;
        for i = 1:N
            MSE = MSE + (x1(i)-x2(i))^2;
        end
        MSE = MSE/N;
        y = MSE;
    end
    
end