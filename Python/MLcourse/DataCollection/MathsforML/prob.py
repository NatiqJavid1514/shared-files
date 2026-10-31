import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt

np.random.seed(42)

#DICE SIMULATION AND PROBABIITy
# n=1000
# outcomes=np.random.choice([1,2,3,4,5,6],size=n)
# one=np.sum(outcomes==1)
# two=np.sum(outcomes==2)
# three=np.sum(outcomes==3)
# four=np.sum(outcomes==4)
# five=np.sum(outcomes==5)
# six=np.sum(outcomes==6)
# print("Probability of getting a one is: ",one/n )


#CONDITIONAL PROBABILITY
data=pd.DataFrame({
    "Likes_ML":np.random.choice([1,0],100,p=[0.6,0.4])
})

#Deep learning depends on whether the student likes ML
# data["Likes_DL"]=[np.random.choice([1,0],p=[0.7,0.3]) if ml else
#                   np.random.choice([1,0],p=[0.2,0.8])
#                   for ml in data["Likes_ML"]]      # basic logic of this code is if A person likes ML there is a 70% chance he
#                                                    #like DL as well if he doesnt then 20 80% probability is there

# p_ml=np.sum(data["Likes_ML"]==1)
# p_dl=np.sum(data["Likes_DL"]==1)
# p_dl_ml=np.sum(data["Likes_DL"]==1 & data["Likes_ML"]==1)

# print("probability of ML: ",p_ml/100)
# print("probability of DL: ",p_dl/100)


#DEPENDENT NA INDEPENDENT EVENTS

#distribution 

preds=np.random.rand(10)
print("Model prediction Probability: ",preds)

labels=preds>0.5
print(labels)