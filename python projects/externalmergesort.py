list = [4,20,6,4,9,7,3,4,5]
list_1,list_2,j,i,z = [],[],0,0,0
list_1.append(list[0])
def l1(list):
    global i
    i=j
    while i < (len(list)-1):
        if i >= 0 and i<len(list)-1:
            if list[i] <= list[i+1]:
                list_1.append(list[i+1])
                i+=1
            else:
                list_2.append(list[i+1])
                i+=1
                break
    return list_1
def l2(list):
    global j
    j = i
    while j < (len(list)-1):
        if j >= 0 and j<len(list)-1:
            if list[j] <= list[j+1]:
                list_2.append(list[j+1])
                j+=1
            else:
                list_1.append(list[j+1])
                j+=1
                break
    return list_2
def merge(list_1,list_2):
    i,j=0,0
    global fin
    fin = []
    while (i<len(list_1)) and j<len(list_2):
        if list_1[i] <= list_2[j]:
            fin.append(list_1[i])
            i+=1
        elif list_1[i] >= list_2[j]:
            fin.append(list_2[j])
            j+=1
    while i<len(list_1):
        fin.append(list_1[i])
        i+=1
    while j<len(list_2):
        fin.append(list_2[j])
        j+=1
    return fin
for z in range(len(list)):
    for f in range(len(list)):
        lp = l1(list)
        lc = l2(list)
    list = merge(lp,lc)
    i,j,list_1,list_2=0,0,[],[]
    list_1.append(list[0])
print(list)

