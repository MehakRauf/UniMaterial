# a Python program to find if a given string starts with a given character using Lambda.

string=input("Enter the string: ")
character= input("Enter the character: ") 

check_string = (lambda char : (lambda str : str.startswith(char))) 
pass_character = (check_string(character))
result= pass_character(string)

if (result):
    print("The given string starts with the given character")
else : 
    print("The given string doesnot starts with the given character")