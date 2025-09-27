#LINEAR SEARCH
##pos=-1
##def linearsearch(list,n):
##    i=0
##    while i<len(list):
##        if list[i]==n:
##            globals()['pos']=i
##            return True
##        i=i+1
##    return False
##n=int(input("Eter the number you want to search: "))
##if linearsearch([1,2,3,4,5,6,7,9,10,8],n):
##    print("found",n,"at",pos+1)
##else:
##    print ("not found")
##BINARY SEARCH
##pos=-1
##def binarysearch(list,n):
##    l=0
##    u=len(list)-1
##    while l<=u:
##        mid=(l+u)//2
##        if list[mid]==n:
##            globals()['pos']=mid
##            return True
##        else:
##            if list[mid]<n:
##                l=mid
##            else:
##                u=mid
##    return False
##n=7
##list=[1,2,3,4,5,6,7,8]   
##if binarysearch(list,n):
##    print("found at ",pos)
##else:
##    print("not")
##QUICK SORT
##list=[7,1,2,3,8,9,5,4,10,6]
##sublist=[]
##for i in list:
##    if i < list[0]:
##        sublist.append(i)
##sublist2=[]
##for i in list:
##    if i >list[0]:
##        sublist2.append(i)
##final=[]
##final.append(sublist)
##final.append(list[0])
##final.append(sublist2)
##print(final)
##j=[]
##for i in final[0]:
##    j.append(i)
##j.append(list[0])
##for i in final[2]:
##    j.append(i)
##print(j)
#SELECTION SORT
##def selection(list):
##    for i in range(len(list)-1):
##        minpos=i
##        for j in range(i,len(list)):
##            if list[j]<list[minpos]:
##                minpos=j
##        temp=list[i]
##        list[i]=list[minpos]
##        list[minpos]=temp
##        print(list)
##list=[3,2,5,4,6,8,7,9]
##selection(list)
##print("the final list is: ",list)
####BUBBLE SORT
##def bubble(list):
##    for i in range(len(list)-1,0,-1):
##        for j in range (i):
##            if list[j]>list[j+1]:
##                temp=list[j]
##                list[j]=list[j+1]
##                list[j+1]=temp
##                print(list)
##list=[3,0,2,4,5,8,7,6,1]
##bubble(list)
