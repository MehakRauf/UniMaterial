# fruits = ['apple','orange','pear','banana']
# otherFruits=['grapes','cocunut']
# fruits=fruits+otherFruits
# print(fruits)

# shapes = ['circle','square','triangle','circle']
# setOfShapes = set(shapes) 
# favoriteShapes = ['circle','triangle','hexagon']
# setOfFavoriteShapes=set(favoriteShapes)
# setOfShapes.add('polygon')
# # Differnce
# Difference=setOfShapes - setOfFavoriteShapes
# print(Difference)
# # Union
# union=setOfShapes | setOfFavoriteShapes
# print(union)

# # Intersection
# intersection=setOfShapes & setOfFavoriteShapes
# print(intersection)

# Dictionaries
# These are same as hash maps in java 
# These don't store elements in an ordered form.

# studentIds = {'knuth': 42.0, 'turing': 56.0, 'nash': 92.0 }
# print(studentIds['knuth'])
# studentIds['nash']="ninety-two"
# print(studentIds)
# del studentIds['nash']
# print(studentIds)
# studentIds['knuth']=["forty two,42.0"]
# print(studentIds)
# print(studentIds.keys())
# print(studentIds.values())
# print(studentIds.items())
# print(len(studentIds))

# swap
# a=int(input("Enter the value of a: "))
# b=int(input("Enter the value of b: "))
# c=int(input("Enter the value of c: "))
# d=int(input("Enter the value of d: "))

# Using temporary variables
# temp1=a
# temp2=b
# a=d
# b=c
# c=temp2
# d=temp1
# print("The value of a is ",a ,"\nThe value of b is ",b,"\nThe value of c is ",c ,"\nThe value of d is ",d)

# Using direct method
# a,b,c,d=d,c,b,a
# print(a," ", b, " " ,c , " ",d)

# temperature converter
# f1=int(input('Enter the temperature in fahrenheit: '))
# c1=int(input('Enter the temperature in celcius: '))
# f=(c1 * 9/5) + 32
# c=(f1-32)*5/9 
# print('The temperature in celcius is: ',c)
# print("The temperature in fahrenheit is: ",f)

s=1
s1="fatima"
print(s1.find('c'))
print(s1.isupper())
print(s1.upper())

# List
# list=['a','b','c','d']
# list.reverse()
# list.remove('a')
# print("The list after reversing and removing 'a' " ,list)
# list.append('r')
# list.reverse()
# list.append('i')
# list.append('e')
# list.sort()
# print("the list after appending 'r', reversing, then appending 'i' and 'e' and then sorting the list is: ",list)

#Function to count the no. of strings with the given condition
# def count_strings(strings):
#     # Initialize a counter variable
#     count = 0
    
#     # Iterate over each string in the list
#     for string in strings:
#         # Check if the string length is 2 or more and the first and last character are the same
#         if len(string) >= 2 and string[0] == string[-1]:
#             count += 1
    
#     # Return the count of strings that satisfy the condition
#     return count

# # Test the function
# strings = ['abc', 'xyz', 'aba', '1221']
# result = count_strings(strings)
# print("The string count is: ", result)

# dic1={1:10, 2:20} 
# dic2={3:30, 4:40} 
# dic3={5:50,6:60} 
# result={}
# for d in (dic1,dic2,dic3):
#     result.update(d)

# print(result)

# x = 6
# if (type(x) is int):
#  print ("true")
# else:
#  print ("false") 

# x = 7.2
# if type(x) is not int:
#     print("true")
# else:
#     print("false")  
 
 
# list1=[1,2,3,4,5]  
# list2=[6,7,8,9]  
# for item in list1:      
#     if item in list2:  
#         print("overlapping")      
#     else:  
#         print("not overlapping") 

# dic1={1:10, 2:20}
# print(dic1.keys())
# print(dic1.values())
# print(dic1.get(1))
# dic1.clear()
# print(dic1)

# original_list = ["Apple", "banana", "Orange", "grapefruit", "plum"]
# new_list=[]
# for fruit in original_list:
#      if len(fruit) > 5:
#           new_list.append(fruit.lower())

# print(new_list)

# sample_list = ['Red', 'Green', 'White', 'Black', 'Pink', 'Yellow','Teapink']
# to_remove = [0, 4, 5]
# result=[]
# for i in range(len(sample_list)) :
#     if i not in to_remove:
#         result.append(sample_list[i])
# print(result)

# a = 60 /* 60 = 0011 1100 */
# b = 13 /* 13 = 0000 1101 */
# int c = 0
#  c = a & b /* 12 = 0000 1100 */
#  print("Line 1", c )
#  c = a | b /* 61 = 0011 1101 */
#  print("Line 2 ", c )
#  c = a ^ b /* 49 = 0011 0001 */
#  print("Line 3 ", c )
#  c = ~a /*-61 = 1100 0011 */
#  print("Line 4", c )
#  c = a << 2 /* 240 = 1111 0000 */
#  printf("Line 5 ", c );
#  c = a >> 2 /* 15 = 0000 1111 */
#  printf("Line 6 -", c );

# a = 60   # 60 = 0011 1100
# b = 13   # 13 = 0000 1101
# c = 0

# c = a & b     # 12 = 0000 1100
# print("Line 1:", c)

# c = a | b     # 61 = 0011 1101
# print("Line 2:", c)

# c = a ^ b     # 49 = 0011 0001
# print("Line 3:", c)

# c = ~a        # -61 = 1100 0011 (Sign bit in Python changes the result)
# print("Line 4:", c)

# c = a << 2    # 240 = 1111 0000
# print("Line 5:", c)

# c = a >> 2    # 15 = 0000 1111
# print("Line 6:", c)

# # Task 1: Introduction
# print("Welcome to the Python Program! Python is a popular programming language. It was created by Guido van Rossum, and released in 1991.")

# # Task 2: Terminal
# print("\n-- Terminal --")
# print("The terminal is an interface where you can run Python scripts and execute commands.")

# # Task 3: Python Interpreter
# print("\n-- Python Interpreter --")
# print("The Python Interpreter is a program that executes Python code line by line.")

# # Task 4: Variables
# print("\n-- Variables --")
# name = "Ali"
# age = 22
# print("My name is", name, "and I am", age, "years old.")

# # Task 5: Text Editor
# print("\n-- Text Editor --")
# print("A text editor is used to write and edit Python code. Examples include Sublime Text and Visual Studio Code.")

# # Task 6: Functions
# print("\n-- Functions --")
# def square(number):
#     return number ** 2

# result = square(15)
# print("The square of 15 is", result)

# # Task 7: Lists and Tuples
# print("\n-- Lists and Tuples --")
# fruits = ["apple", "banana", "orange"]
# colors = ("red", "green", "blue")
# print("Fruits:", fruits)
# print("Colors:", colors)

# # Task 8: Conditional Statements
# print("\n-- Conditional Statements --")
# num = 10
# if num > 0:
#     print("The number is positive.")
# elif num < 0:
#     print("The number is negative.")
# else:
#     print("The number is zero.")

# # Task 9: The For Loop
# print("\n-- The For Loop --")
# print("The table of 2 is: ")
# for i in range(1, 11):
#     print(i*2)

# # Task 10: User Input and the While Loop
# print("\n-- User Input and the While Loop --")
# count = 0
# while count < 3:
#     name = input("Enter your name: ")
#     print("Hello,", name)
#     count += 1
# a=6
# a//=3 

# a**=5
# print("floor divide=",a) 
# print("exponent=",a) 


# import random

# print("start")
# # Task 7: Lists
# choices = ["rock", "paper", "scissors"]

# # Task 9: The For Loop
# def get_choice():
#     choice = ""
#     while choice not in choices:
#         choice = input("Choose rock, paper, or scissors: ")
#     return choice

# # Task 6: Functions
# def play_round(user, computer):
#     if user == computer:
#         print("It's a tie!")
#     elif (user == "rock" and computer == "scissors") or (user == "paper" and computer == "rock") or (user == "scissors" and computer == "paper"):
#         print("You win!")
#         return True
#     else:
#         print("Computer wins!")
#         return False

# # Task 8: Conditional Statements
# def play_game():
#     user_score = 0
#     computer_score = 0
#     rounds = 0

#     while user_score < 3 and computer_score < 3:
#         user_choice = get_choice()
#         computer_choice = random.choice(choices)
#         rounds += 1
#         print("Round " + str(rounds) + ":")
#         print("You chose " + user_choice + ".")
#         print("Computer chose " + computer_choice + ".")
#         if play_round(user_choice, computer_choice):
#             user_score += 1
#             print("Your score is now " + str(user_score) + ".")
#         else:
#             computer_score += 1
#             print("Computer's score is now " + str(computer_score) + ".")

#     if user_score > computer_score:
#         print("Congratulations, you win the game!")
#     elif computer_score > user_score:
#         print("Sorry, you lose the game.")
#     else:
#         print("It's a tie!")

# # Task 5: Text Editor
# print("Welcome to Rock Paper Scissors!")

# # Task 6: Functions
# play_game()
