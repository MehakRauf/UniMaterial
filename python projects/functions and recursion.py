#TO CHECK A PALINDROME
##def palindrome(n):
##    s=n[ : :-1]
##    if s==n:
##        return True
##    return False
##n=input("the value you want to check: ")
##if palindrome(n):
##    print("yes")
##else:
##    print("not ")
##def palindrome(n):
##    rev=reversed(n)
##    if list(n)==list(rev):
##        return True
##    return False
##n=input("the value you want to check: ")
##if palindrome(n):
##    print("yes")
##else:
##    print("not")
##MAX OF THREE NO.
##def max(x,y):
##    if x>y:
##        return x
##    return y
##def max3(x,y,z):
##    if z>(max(x,y)):
##        return z
##    return max(x,y)
##
##print(max3(-5,-6,-7))
##MULTIPLY THE NO.S OF A LIST
##def sumoflist(list):
##    sum=1
##    for i in list:
##        sum=sum*i
##    return sum
##print(sumoflist([1,2,3,4,5,6]))
##REVERSE A NO
##def reversed(n):
##    s=n[ : :-1]
##    return s
##print(reversed("mehak"))
##FACTORIAL
##def factorial(n):
##    fac=1
##    while n>0 :
##        fac=fac*n
##        n=n-1
##    return fac
##print(factorial(6))
##CHECKING THE NO. IS IN RANGE
##def test_range(n):
##    if n in range(3,9):
##        print( n," is in the range")
##    else :
##        print("The number is outside the given range.")
##test_range(1)
##NO. OF UPPERCASE AND LOWERCASE
##def upperlower(s):
##    d={"upper":0, "lower":0}
##    for c in (s):
##        if c.isupper():
##            d["upper"]+=1
##        elif c.islower():
##            d["lower"]+=1
##    print("original string: ",s)
##    print("No. of uppercase: ",d["upper"])
##    print("No. of lowercase: ",d["lower"])
##upperlower("THE hello")
##creating new unique list
##def newlist(list):
##    newl=[]
##    for i in list:
##        if i not in newl:
##            newl.append(i)
##    print(newl)
##newlist([1,2,3,3,3,3,4,5])
##EXTRACTING EVEN NuMBERS
##def even(list):
##    newl=[]
##    for i in list:
##        if i%2==0:
##            newl.append(i)
##    print(newl)
##even([1,2,3,4,5,6,7,8])
##EXTRACTING PRIME NOS
##def prime(num):
##    if num==1:
##        return False
##    if num==2:
##        return True
##    for i in range(2,num):
##        if (num%i==0):
##            return False
##    return True
##print(prime(6))
##PERFECT NUMBER
##def perfect(n):
##    sum=0
##    for i in range(1,n):
##        if n%i==0:
##            sum=sum+i
##    return sum==n
##print(perfect(7))
##CHECKING A PALINDROME
def palindrome(n):
    s=n[::-1]
    if s==n:
        return True
    return False
print(palindrome('1'))

























    










