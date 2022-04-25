import csv
def readfilePos(path):
    file = open(path)
    csvreader = csv.reader(file,delimiter=';')
    header = []
    header = next(csvreader)[1:]
    time = []
    positions = []
    for row in csvreader:
        positions.append(row)
    for row in positions:
        for i in range(0,len(row)):
            row[i]=int(row[i])
    file.close()
    file = open(path)
    csvreader = csv.reader(file, delimiter=';')
    for row in csvreader:
        time.append(row[0])
    time = time[1:]
    for i in range(0, len(time)):
        time[i] = int(time[i])
    file.close()
    xes = []
    yes = []
    for row in positions:
        xes.append(row[1::2])
        yes.append(row[0::2])
    for row in yes:
        del row[0]
    return xes, yes , time


def readfileN(path):
    list1=[]
    list2=[]
    f=open(path,newline='')
    csv_reader = csv.reader(f)
    list1.append(next(csv_reader))
    list1=list1[0]
    list1 = list1[1:-1]
    for i in range(0,len(list1)):
        list1[i]=int(list1[i])
    list2.append(next(csv_reader))
    list2 = list2[0]
    list2 = list2[1:-1]
    for i in range(0, len(list2)):
        list2[i] = int(list2[i])
    return list1,list2

