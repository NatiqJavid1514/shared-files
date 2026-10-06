import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

sns.set_theme(style="whitegrid")

df=sns.load_dataset("tips")

# print(df.info())
 #measure of central tendency

# print(df.columns)
col=df["total_bill"]
mean_val=np.mean(col)
# print(mean_val)
median_val=np.median(col)
mode_val=col.mode()[0]
# print(mean_val, median_val, mode_val)

# sns.histplot(col,kde=True, color="skyblue")
# plt.axvline(mean_val,color="red",label=f"Mean: {mean_val}")
# plt.axvline(median_val,color="green",label=f"Median: {median_val}")
# plt.title("Distribution of the Total bill")
# plt.legend()
# plt.show()



#Measure of Spread
# data_range=col.max() - col.min()

# print(data_range)

# variance=np.var(col)
# print(variance)

#inter quartile range
# q1=np.percentile(col,25)
# q2=np.percentile(col,75)
# iqr=q2-q1
# print(iqr)
plt.figure(figsize=(6,3))

#plot 1: Tip distribution
# plt.subplot(1,2,1)
# sns.histplot(df["tip"],kde=True,color="orange")
# plt.title(f"Distribution on Tips (Skew: {df["tip"].skew():.2f})")


# #total bill distribution
# plt.subplot(1,2,2)
# sns.histplot(df["total_bill"],kde=True,color="purple")
# plt.title(f"Distribution on Total Bill (Skew: {df["total_bill"].skew():.2f})")

# plt.tight_layout()
# plt.show()
# sns.boxplot(x=df["total_bill"])
# plt.title("Box plot of total bill")
# plt.show()
q1=df["total_bill"].quantile(0.25)
q3=df["total_bill"].quantile(0.75)
iqr=q3-q1
lowerbound=q1-1.5 * iqr
upperbound=q3+1.5 *iqr

# outliers=df[(df["total_bill"]<lowerbound)| (df["total_bill"]>upperbound)]
# print(outliers)
numericaldf=df.select_dtypes(include=[np.number])
corr_matrix=numericaldf.corr()

print(corr_matrix)

sns.heatmap(corr_matrix,annot=True,cmap="coolwarm",linewidths=0.5)
plt.title("Correlation Heatmap")
plt.show()
print(corr_matrix.loc["total_bill","tip"])






