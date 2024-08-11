# (iii) Try the exercise below:
# 1. Make a program that lists the countries in the set below using a while loop.
# clist =
# ["Canada","USA","Mexico"]

print("The countries in the list are: ")
clist = ["Canada","USA","Mexico"]
i = 0
while i < len(clist):
    print(clist[i])
    i += 1
print("-----------")

# 2. What’s the difference between a while loop and a for loop?
# A while loop repeatedly executes a block of code as long as a given condition is true.
# A for loop, on the other hand, is used to iterate over a sequence
# (such as a list, tuple, or range) or other iterable objects.
print("-----------")


# 3. Can you sum numbers in a while loop?
# Yes we can sum numbers using while loop
total = 0
i = 1
while i <= 10:
    total += i
    i += 1
print("Sum of numbers from 1 to 10:", total)
print("-----------")

# 4. Can a for loop be used inside a while loop?
# Yes we can  use for in while loop
# Program to print a pattern using while loop and nested for loop

# Prompt the user for the number of rows
rows = int(input("Enter the number of rows: "))

# Initialize the row counter
row_count = 1

# This will print the numbers in the form of a triangle
# Start the outer while loop
while row_count <= rows:
    # Start the nested for loop to print columns
    for col_count in range(1, row_count + 1):
        print(col_count, end=' ')
    
    # Move to the next line after each row
    print()
    
    # Increment the row counter
    row_count += 1
 
print("-----------")
