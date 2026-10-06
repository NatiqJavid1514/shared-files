import os
import pandas as pd
import kagglehub
os.environ["KAGGLE_API_TOKEN"]="KGAT_572598f31162b7be902108ace67837c3"

path = kagglehub.dataset_download("alessandrolobello/the-ultimate-earthquake-dataset-from-1990-2023")

print("Path to dataset files:", path)
