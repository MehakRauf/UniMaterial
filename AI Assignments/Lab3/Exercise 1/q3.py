# . a Python program to extract year, month, date and time using Lambda.
import re

extract_date = lambda datetime : (re.findall(r'\d+' ,datetime))
datenTime= "2022-05-15 10:30:2"

date_time=extract_date(datenTime)
y = []
for i in date_time:
    y.append(int(i))

print("Year: ", y[0])
print("Month: ", y[1])
print("Day: ", y[2])
print("Hours: ", y[3])

if(len(y) >= 5):
    print("Minutes: ", y[4])
if(len(y) >= 6):
    print("Seconds: ", y[5])
