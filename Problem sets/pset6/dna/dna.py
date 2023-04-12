import sys
import csv

if len(sys.argv) != 3:
    sys.exit("Usage : python dna.py data.csv sequence.txt")

f1 = open(sys.argv[1], "r")
c = csv.DictReader(f1)
f2 = open(sys.argv[2], "r")
s = f2.read()
# print(s)
dic = {"AGATC": 0,
       "AATG": 0,
       "TATC": 0,
       "GAAA": 0,
       "TCTG": 0,
       "GATA": 0,
       "TCTAG": 0,
       "TTTTTTCT": 0
       }
       
b = {}        
for i in range(len(s)):
    b.setdefault(i, 0)
    if s[i:i + 4] == 'AATG':
        if b[i - 4] >= 0:
            b[i] = b[i - 4] + 1
        else:
            b[i] = 1
        dic['AATG'] = max(b.values())
        
b = {}        
for i in range(len(s)):
    b.setdefault(i, 0)
    if s[i:i + 5] == 'AGATC':
        if b[i - 5] >= 0:
            b[i] = b[i - 5] + 1
        else:
            b[i] = 1
        dic['AGATC'] = max(b.values())
        
b = {}        
for i in range(len(s)):
    b.setdefault(i, 0)
    if s[i:i + 4] == 'TATC':
        if b[i - 4] >= 0:
            b[i] = b[i - 4] + 1
        else:
            b[i] = 1
        dic['TATC'] = max(b.values())
    
b = {}        
for i in range(len(s)):
    b.setdefault(i, 0)
    if s[i:i + 4] == 'TCTG':
        if b[i - 4] >= 0:
            b[i] = b[i - 4] + 1
        else:
            b[i] = 1
        dic['TCTG'] = max(b.values())
        
b = {}        
for i in range(len(s)):
    b.setdefault(i, 0)
    if s[i:i + 4] == 'GAAA':
        if b[i - 4] >= 0:
            b[i] = b[i - 4] + 1
        else:
            b[i] = 1
        dic['GAAA'] = max(b.values())
        
b = {}        
for i in range(len(s)):
    b.setdefault(i, 0)
    if s[i:i + 4] == 'GATA':
        if b[i - 4] >= 0:
            b[i] = b[i - 4] + 1
        else:
            b[i] = 1
        dic['GATA'] = max(b.values())
        
b = {}        
for i in range(len(s)):
    b.setdefault(i, 0)
    if s[i:i + 5] == 'TCTAG':
        if b[i - 5] >= 0:
            b[i] = b[i - 5] + 1
        else:
            b[i] = 1
        dic['TCTAG'] = max(b.values())
        
b = {}        
for i in range(len(s)):
    b.setdefault(i, 0)
    if s[i:i + 8] == 'TTTTTTCT':
        if b[i - 8] >= 0:
            b[i] = b[i - 8] + 1
        else:
            b[i] = 1
        dic['TTTTTTCT'] = max(b.values())
# for i in range(len(s)):
#     if s[i:i + 4] == "AATG":
#         dic["AATG"] += 1
#     elif s[i:i + 5] == "AGATC":
#         dic["AGATC"] += 1
#     elif s[i:i + 4] == "TATC":
#         dic["TATC"] += 1
#     elif s[i:i + 4] == "TCTG":
#         dic["TCTG"] += 1
#     elif s[i:i + 4] == "GAAA":
#         dic["GAAA"] += 1
#     elif s[i:i + 4] == "GATA":
#         dic["GATA"] += 1
#     elif s[i:i + 5] == "TCTAG":
#         dic["TCTAG"] += 1
#     elif s[i:i + 8] == "TTTTTTCT":
#         dic["TTTTTTCT"] += 1

flag = 0
if "small.csv" in sys.argv[1]:
    for i in c:
        if int(i["AGATC"]) == dic["AGATC"] and int(i["AATG"]) == dic["AATG"] and int(i["TATC"]) == dic["TATC"]:
            print(i["name"])
            flag = 1
    if flag == 0:
        print("No Match")
else:
    # print(dic)
    for i in c:
        if int(i["AGATC"]) == dic["AGATC"] and int(i["AATG"]) == dic["AATG"] and int(i["TATC"]) == dic["TATC"] and int(i["TTTTTTCT"]) == dic["TTTTTTCT"] and int(i["TCTAG"]) == dic["TCTAG"] and int(i["GATA"]) == dic["GATA"] and int(i["GAAA"]) == dic["GAAA"] and int(i["TCTG"]) == dic["TCTG"]:                                                                   
            print(i["name"])
            flag = 1
    if flag == 0:
        print("No Match")