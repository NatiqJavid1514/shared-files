import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

x=np.linspace(0,10,50)
y=np.sin(x)
# print(x)
# plt.plot(x,y,color="red",linestyle="--",marker="o", label="sin(x)")

# plt.title("My first graph")
# plt.xlabel("x-axis")
# plt.ylabel("y-axis")
# plt.legend()
# plt.grid(True)
# plt.show()
# students=["Nats","Bob","Babar"]
# scores=[100,200,300]
# plt.bar(students,scores, color="orange",label="NATS GRAPH")
# plt.legend()
# plt.title("first bar graph")
# plt.xlabel("x-axis")
# plt.ylabel("y-axis")
# plt.show()
# np.random.seed(42)
# x=np.random.randn(50)
# y=np.random.randn(50)
# plt.scatter(x,y,color="green")
# plt.title("Scatter plot")
# plt.xlabel("Feature 1")
# plt.ylabel("Feature 2")
# plt.show()

# data=np.random.randn(1000)
# plt.hist(data,bins=30,color="skyblue",edgecolor="black")
# plt.show()
labels=["c++","java","c","python"]
sizes=[50,20,10,20]
plt.pie(sizes,labels=labels)
plt.title("my first pie chart")
plt.show()