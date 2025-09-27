##SUM OF LISt
##def listsum(list):
##    if len(list)==1:
##        return list[0]
##    else:
##        return list[0]+listsum(list[1:])
##print (listsum([1,2,3,4,5]))

##SUM OF LIST OF LISTS
##def recursive(data):
##    total=0
##    for element in data:
##        if type(element)==type([]):
##            total=total+recursive(element)
##        else:
##            total=total+element
##    return total
##print (recursive([[0,1,1],[1,1,0],[1,0,0]]))
## no. to string
##def tostring(n,base):
##    no = "0123456789ABCDEF"
##    if n<base:
##        return no[n]
##    else:
##        return tostring(n//base,base)+ no[n%base]
##print(tostring(11100,16))
#factorial
##def factorial(n):
##    if n==1 or n==0:
##        return n
##    else:
##        return (n*factorial(n-1))
##   
##print (factorial (5))
##POWER
##def pow(base,n):
##    if n==0:
##        return 1
##    if n>0 :
##        return base*pow(base,n-1)
##    else:
##        return 1/base*pow(base,n+1)
##print(pow(-2,-3))       
##def fibonacci(n):
##    if n==2 or n==1:
##        return 1
##    else:
##        return fibonacci(n-1)+fibonacci (n-2)
##print(fibonacci(7))
##SUM of a whole no.
##def sum(n):
##    if n==0:
##        return 0
##    else:
##        return n%10+sum(int(n/10))
##print(sum(345))
##sum of natural numbers upto the entered no.
##def sum(num):
##    if num <= 0:
##        return num
##    else:
##        return num+sum(num-1)
##print(sum(6))
##SUM OF ThE POSITIVE  
##def sum(n):
##    if  n<0:
##        return n
##    else:
##        return n+sum(n-2)
##print(sum(10))
##calculate the harmonic sum
##def sum(n):
##    if n<2:
##        return 1
##    else:
##        returnvalue= 1/n+sum(n-1)
##    return returnvalue
##print(sum(8))
##GEOMETRIC SEQUENCE
##a=int(input("Enter the first term: "))
##r=int(input("Enter the common ratio: "))
##n=int(input("Enter the no. of terms: "))
##for i in range(1,n+1):
##    t=a*r**(i-1)
##    print(t)
##GEOMETRIC SERIES SUM
####def geometric(n):
####    if n<0:
####        returnvalue= 0
####    else:
####        returnvalue= (pow(2,n))+geometric(n-1)
####    return returnvalue
####print(geometric(4))
##POWER OF numbers
####def power(a,b):
####    if b==0:
####        return 1
####    if b>0:
####        return a*power(a,b-1)
####    else:
####        return 1/a *power(a,b+1)
####print(power(2,-3))
##GCD (Greatest Common Division)
##def gcd(a,b):
##    low=min(a,b)
##    high=max(a,b)
##    if low==0:
##        return high
##    if low==1:
##        return 1
##    else:
##        return gcd(low,high%low)
##print(gcd(12,14))




















































