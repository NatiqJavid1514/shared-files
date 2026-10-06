import numpy as np
import matplotlib.pyplot as plt
np.set_printoptions(suppress=True)


#sample dataset
x=np.array([1,2,3])
y=np.array([2,4,6])

#f(x)=w*x
#y= w*x
#abh we will give this data and find this w

w=1.0

#learning rate
lr=0.01

def loss(w):
    y_pred=w*x
    return np.mean((y_pred-y)**2)
def dloss(w):
    y_pred=w*x
    return np.mean(2*x*(y_pred-y))
print("start w: ",w, "loss: ",loss(w))
for step in range(30):
    slope=dloss(w)
    w=w-lr*slope
    print("step ",step+1, "w: ",round(w,3),"loss: ",round(loss(w),3))


