def binary_search(list, toSearch) :
    index = 0
    flag = False
    l = 0
    u = len(list)-1
    while (l <= u) :
        mid = (l+u)//2
        if(list[mid] == toSearch) :
            index = mid
            flag = True
            break
        elif (list[mid] < toSearch) :
            l = mid+1
        else :
            u = mid-1
    if(flag) :
        print("The number is found at: " , index)
    else :
        print("The number is not found.")

list = []
n = int(input("Enter the number of enteries: "))
for i in range (0,n) :
    num = int(input("Enter the values: "))
    list.append(num)
toSearch = int(input("Enter the number you want to search: "))

list.sort()
binary_search(list,toSearch)
