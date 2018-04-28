##########step1###########
M=csvread('train.csv');
X=M(:,1);#nx1
Y=M(:,2);#nx1
Z=ones(size(X));#nx1
X1=[Z X]; #nx2
############step2#########
w=rand(2,1);  #2x1
#w=[0;0];
############step3#########
scatter(Y,X1(:,2),'r')
hold on
xlabel('feature');
ylabel('label');
w_t=transpose(w); #1x2
plot(X1*w,X1(:,2),'g');
hold off
############step4#########
scatter(Y,X1(:,2),'r')
hold on
w_dir=(pinv(transpose(X1)*X1))*(transpose(X1))*Y;
X_t=transpose(X1);
plot(transpose(w_dir)*X_t,X1(:,2),'g');
hold off
pause
##############Step5##########
scatter(Y,X1(:,2),'r');
hold on
title('It contains 12 plots');
for(j = 0:1100)
  diff=(X1*w .- Y);
  w=w-0.00000000001*transpose(transpose(diff)*(X1));
  if (rem(j,100) == 0)
    plot(transpose(transpose(w)*X_t),X1(:,2))
    hold on
    pause
  else
    continue
  end
end
hold off
pause
###########step6##############
scatter(Y,X1(:,2),'r')
hold on
xlabel('features')
ylabel('lables')
title('final drawing')
plot(transpose(transpose(w)*X_t),X1(:,2))

###########step7############
M_test=csvread('test.csv');
X_test=M_test(:,1);
Y_test=M_test(:,2);
one_test=ones(size(X_test),1);
X1_test=[one_test X_test];
y_pred1=(X1_test*w);
rms_err1=sum((y_pred1-Y_test).^2);
c=size(Y_test);
rms_err1=(rms_err1/c(1)).^0.5;
rms_err1
y_pred2=(X1_test*w_dir);
rms_err2=sum((y_pred2-Y_test).^2);
rms_err2=(rms_err2/c(1)).^0.5;
rms_err2=rms_err2(1)
