# a Python program to square and cube every number in a given list of integers using Lambda. 

square = lambda i : i * i
cube = lambda i : i * square(i)

n= int(input("Enter the number: "))
print("The square of the number is: ", square(n))
print("The cube of the number is: ", cube(n))

