import pandas as pd


def readfilePos(path):
    df=pd.read_csv(path, delimiter = ";")
    df = df.stack().str.replace(',', '.').unstack()
    time = df.iloc[:,0]
    z = df.iloc[:,1::2]
    r = df.iloc[:,2::2]
    return time, z, r


