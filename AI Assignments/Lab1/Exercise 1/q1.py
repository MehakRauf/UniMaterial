# Write a Python program to swap 4 variables values (input four values.
# Sample input:
# Before swapping
# a=2,b=56,c=78,d=9
# After Swapping
# a=,9,b=78,c=56,d=2

# swap
a=int(input("Enter the value of a: "))
b=int(input("Enter the value of b: "))
c=int(input("Enter the value of c: "))
d=int(input("Enter the value of d: "))

# Using temporary variables
temp1=a
temp2=b
a=d
b=c
c=temp2
d=temp1
print("The value of a is ",a ,"\nThe value of b is ",b,"\nThe value of c is ",c ,"\nThe value of d is ",d)

# Using direct method
a,b,c,d=d,c,b,a
print("The value of a is ",a ,"\nThe value of b is ",b,"\nThe value of c is ",c ,"\nThe value of d is ",d)
