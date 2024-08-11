# (ii)Try the scenrio below:
# Make a program that lists the countries in the set
clist =['Canada','USA','Mexico','Australia']
print("The countries in the list are: ")
for country in clist:
    print(country)
print("-----------")

# 1. Create a loop that counts from 0 to 100
print("The count from 0 to 100 is: ")
for i in range(101):
    print(i)
print("-----------")

# 2. Make a multiplication table using a loop
n=int(input("Enter the number of which you want to print the table: "))
print("The table of " ,n," is : ")
for i in range(1,11):
    print(n*i)
print("-----------")

# 3. Output the numbers 1 to 10 backwards using a loop
print("The backward count is: ")
for i in range(10,0,-1):
    print(i)    
print("-----------")

# 4. Create a loop that counts all even numbers to 10
print("The count of even numbers is: ")
count = 0
while count <= 10:
    if count % 2 == 0:
        print(count)
    count += 1
print("-----------")

# 5. Create a loop that sums the numbers from 100 to 200
sum_numbers = 0

for num in range(100, 201):
    sum_numbers += num

print("Sum of numbers from 100 to 200:", sum_numbers)
print("-----------")

