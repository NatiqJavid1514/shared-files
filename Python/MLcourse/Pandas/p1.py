import pandas as pd
s=pd.Series([10,20,30,40,50],name="marks")
data={
    "Name":["Nats","bats","cats"],
    "age":[10,20,30],
    "Score":[100,200,300]
}

print("hello world")
# print(s)
# print(s.mean())
# k=pd.DataFrame(data)
# print(k)
# k.to_csv("natsfile.csv")
# k=pd.read_csv("diabetes.csv")
# # print(k)
# print(k.shape)
k=pd.DataFrame(data)
# print(k.info())
# print(k["Name"])
# high_score=k[k["Score"]>100]
# print(high_score)
k["city"]=["Srinagar","New york ","Paris",]
print(k)

