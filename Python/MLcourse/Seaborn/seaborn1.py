import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

tips=sns.load_dataset("tips")
# print(tips.shape)
# print(tips.head())
# print(tips.tail())
sns.set_palette("viridis")
sns.set_style("darkgrid")


#histogram - Distribution of total BILL
# plt.figure(figsize=(6,4))
# sns.histplot(tips["total_bill"],color="green",kde=True)
# plt.title(" distribution of total BILL")
# plt.xlabel("Total bill")
# plt.ylabel(" Frequency")
# plt.show()







# box plot for outliers 

# plt.figure(figsize=(6,4))
# sns.boxplot(x="day",y="total_bill",data=tips, palette="pastel",legend=False,hue="day")
# plt.title("Total bill vs day")
# plt.show()


#count plot 
# plt.figure(figsize=(6,4))
# sns.countplot(x="day",data=tips, palette="Set2",hue="sex")
# plt.title("Total bill vs day")
# plt.show()





#scatter plot
# plt.figure(figsize=(6,4))
# sns.scatterplot(x="tip",y="total_bill",data=tips, palette="Set2",hue="sex")
# plt.title("Bill vs tip relationship")
# plt.show()

#pair plot

# sns.pairplot(tips,hue="sex",diag_kind="kde")
# plt.suptitle("pair wise relationship")
# plt.show()


#HEATMAP
correlationmatrix=tips.corr(numeric_only=True)
plt.figure(figsize=(6,4))
sns.heatmap(correlationmatrix,annot=True,color="skyblue",linewidths=0.5)
plt.title("Feature correcation map")
plt.show()



















