import pandas as pd
from sqlalchemy import create_engine
#connection
connection_string = "postgresql+psycopg2://postgres:njmk1514@localhost:5432/postgres"
 # format aise hai hai 

engine=create_engine(connection_string)
#load data from postgres table
df=pd.read_sql(
   sql= "SELECT * FROM dataset.diabetes_copy",
   con=engine
)
print(df.head())