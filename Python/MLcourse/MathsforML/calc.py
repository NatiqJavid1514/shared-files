import numpy as np
import matplotlib.pyplot as plt
np.set_printoptions(suppress=True)

# lets find slope of a line 
# simple line y=2x+1;
  
  #define line function

# def line_func(x):
#     return 2*x+1

# x=np.linspace(-3,3,100)
# y=line_func(x);
# #given  x and value find slope
# plt.figure(figsize=(6,4))
# plt.plot(x,y)
# plt.title("Line slope")
# plt.xlabel("x")
# plt.ylabel("y")
# plt.show()
# #to find slope randomly pick two points of line and get their y values;
# x1=-2;
# x2=1;
# y1=line_func(x1)
# y2=line_func(x2)
# print(x1)
# print(x2)
# print(y1)
# print(y2)

# #slope
# m=(y2-y1)/(x2-x1)
# print(m)




# Now for curve
def curvefunc(x):
    return x**2
x=np.linspace(-3,3,200)
y=curvefunc(x)
plt.figure(figsize=(6,3))
plt.plot(x,y)
plt.title("Curve y^2")
plt.xlabel("X")
plt.ylabel("Y")
plt.grid(alpha=0.8)
# plt.show()
def slopefunct(curvefunc,x1,h=0.0001):
    x2=x1+h
    y1=curvefunc(x1)
    y2=curvefunc(x2)
    slope=(y2-y1)/(x2-x1)
    return slope
print(slopefunct(curvefunc,-2))





