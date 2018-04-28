import numpy as np
import matplotlib.pyplot as plt
data=np.loadtxt('train.csv',delimiter=',',skiprows=1)
X_train=data[ : ,0]
Y_train=data[ : ,1]
X_train=X_train.reshape(X_train.size,1)
Y_train=Y_train.reshape(Y_train.size,1)
Y_train=Y_train/10
ones=np.ones(X_train.shape ,dtype=np.int16).reshape(X_train.size,1)
new_X_train=np.hstack((ones,X_train))
w=np.array([[0],[0]]).reshape(2,1)
#w=np.array([[5],[2]])
X_t=np.transpose(new_X_train)
plt.plot(Y_train,new_X_train[:,1],'ro')
plt.plot((((np.transpose(w)).dot(X_t))).T,new_X_train[:,1],'b-')
plt.xlabel('features')
plt.ylabel('labels')
w_direct=np.linalg.inv(new_X_train.T.dot(new_X_train)).dot(new_X_train.T.dot(Y_train))
plt.plot(w_direct.T.dot(X_t).T,new_X_train[:,1],'b-')
plt.show()




plt.plot(Y_train,new_X_train[:,1],'ro')
plt.xlabel('features')
plt.ylabel('labels')
plt.title("Training")
for j in range(0,1100):
    diff=(new_X_train.dot(w)-Y_train)
    w=w-0.00000000001*(diff.T.dot(new_X_train).T);
    if j%100==0:
        plt.plot(w.T.dot(X_t).T,new_X_train[:,1],'b-');

        # plt.plot(new_X_train.dot(w),new_X_train[:,1],'b-')
    else:
        continue
plt.show()



plt.plot(Y_train,new_X_train[:,1],'ro')
plt.xlabel('features')
plt.ylabel('labels')
plt.title("Final drawing")
plt.plot(w.T.dot(X_t).T,new_X_train[:,1],'b-')
plt.show()

d=np.loadtxt('test.csv',delimiter=',',skiprows=1)
X_test=data[ : ,0]
Y_test=data[ : ,1]

X_test=X_test.reshape(X_test.size,1)
Y_test=Y_test.reshape(Y_test.size,1)
Y_test=Y_test/10
ones=np.ones(X_test.shape ,dtype=np.int16).reshape(X_test.size,1)
new_X_test=np.hstack((ones,X_test))
y_pred1=new_X_test.dot(w)
rms_err1=((new_X_test.dot(w)-Y_test)**2).sum()
rms=rms_err1=(rms_err1/Y_test.size)**0.5
print "rms_err1=",rms_err1
y_pred2=new_X_test.dot(w_direct)
rms_err2=((new_X_test.dot(w_direct)-Y_test)**2).sum()
rms_err2=(rms_err2/Y_test.size)**0.5
print "rms_err2=",rms_err2
