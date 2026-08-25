import numpy as np
import time
# print(np.__version__)
# n=1_000_000

# mylist=list(range(n))

# np_array=np.arange(n)
# # print(len(mylist))
# # print(len(np_array))

# t1=time.time()
# result=[x*2 for x in mylist]
# t2=time.time()

# t3=time.time()
# result2=[x*2 for x in np_array]
# t4=time.time()

# print(t2-t1)
# print(t4-t3)
# arr1=np.array([1,2,3,4,5])
# print(arr1)
# print(type(arr1))
# arr2=np.array([[1,2,3],[3,4,5]])
# print(arr2)
# arr3=np.array([[[1,2,3],[3,4,5]],[[10,11,12],[12,13,14]]])
# print(arr3)

# numPy Array attributes
# arr2=np.array([[1,2,3],[3,4,5]])
# print(arr2.shape)
# print(arr2.size)
# print(arr2.ndim)
# print(arr2.dtype)
# arr=np.array([[10,20,30], 
#               [40,50,60],
#               [60,70,80]])

# print(arr)
# print("---------------------------------------------------------------------------------")
# print(arr[0][2]) #particular index
# print("---------------------------------------------------------------------------------")
# print(arr[0]) #pura row hi print hoga
# print("---------------------------------------------------------------------------------")
# print(arr[:,1]) #give me all rows but 1st indexed column
arr=np.array([1,2,3,4])
arr1=np.array([4,5,6,7])
print("Addtion: ",arr+arr1)
print("Subtraction: ",arr-arr1)
print("Multiplication: ",arr*arr1)
print("Division: ",arr/arr1)



