##FACTORIAL
##def factorial(n):
##    if n==0 or n==1 or n==2:
##        return n
##    else:
##        return n*factorial(n-1)
##print(factorial(3))
##FIBONACCI
##def fibonacci(n):
##    if n==0 or n==1:
##        return n
##    else:
##        return fibonacci(n-1)+fibonacci(n-2)
##print(fibonacci(6))
##SUM OF DIGITS OF A NUMBER
##def sumdigit(n):
##    if n==0:
##        return 0
##    else:
##        return int(n%10)+sumdigit(int(n/10))
##print(sumdigit(123))
##def sumnatural(n):
##    if n==0 or n==1:
##        return n
##    else :
##        return n+sumnatural(n-1)
##print(sumnatural(6))
##POWER
##def power(x,n):
##    if n==0:
##        return 1
##    if n<0:
##        return 1/x*power(x,n+1)
##    else:
##        return x*power(x,n-1)
##print(power(2,-2))
##SUM OF LIST
##def sum(list):
##    if len(list)==1:
##        return list[0]
##    else:
##        return list[0]+sum(list[1:])
##print(sum([1,2,3,4,5]))
##sum of list of lists
def sum(list):
    total=0
    for element in list:
        if type(element)==type([]):
            total=total+sum(element)
        else:
            total= total+element
    return total
list=[[1,1,1],[1,0,1],[1,0,1],[1,0,1],[1,1,0]]
print(sum(list))
for j in list:
    for i in range(len(j)):
        if j[i]==1:
           print(i)
        else:
            if j[i]==0:
                print("the line stops here.")
##TO CALCULATE THE SUM AS N+(N-2)
##def sum(n):
##    total=0
##    if n==0 or n==1:
##        return n
##    else:
##        return n+sum(n-2)
##print(sum(6))
##SUM OF HARMONIC SERIES
##def harmonicsum(n):
##    if n==0 or n==1:
##        return 1
##    else:
##        return 1/n+harmonicsum(n-1)
##print(harmonicsum(5))
##GEOMETRIC MEAN
##def geometric(n):
##    if n<0:
##        return n
##    else:
##        return 1/(pow(2,n))+geometric(n-1)
##print(geometric(5))
##GCD
##def gcd(a,b):
##    low=min(a,b)
##    high=max(a,b)
##    if low==0:
##        return high
##    elif low==1:
##        return low
##    else:
##        return gcd(low,high%low)
##print(gcd(36,30))
##BINARY SEARCH
##def binary(list,n,l,u):
##    while l<=u:
##        mid=(l+u)//2
##        if list[mid]==n:
##            return True        
##        else:
##            if list[mid]<n:
##                return binary(list,n,mid+1,u) 
##            else:
##                return binary(list,n,l,mid-1)
##    return False
##list=[1,2,3,4,5,6]
##if binary(list,7,0,len(list)-1):
##    print("FOUND")
##else:
##    print("NOT FOUND ")




























