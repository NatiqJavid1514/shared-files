import numpy as np
#Imagine we have 3 samples and 2 features
#Feature 1: Hours studied
#Feature 2: Number of practice questions
#target : pass (1)/fail(0)

x=np.array([
    [1,20], #sample1

    [2,35] #sample2
      #sample3

])
y=np.array([
    [2,3,4],
    [10,20,30]
])

z=np.dot(x,y)
print(z)




