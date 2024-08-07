import re

# Define the regular expressions
int_const = r'^[+-]?[0-9]+$'
flt_const = r'^[+-]?[0-9]*\.[0-9]+$'
# for char and string 
# cannot occur without \
A = r"[\\|'|\"]"
# cannot and can occur with \
B = r"[bntro]"
# cannot occur with \
C = r"[@+]"

char_const = rf"(\\{A}|\\{B}|{B}|{C})"

string_const = rf"({char_const})*"

# Define the identifier (ID)
#NO CONSECUTIVE _ 
#STARTS WITH _ OR ALPHABET

ID_1 = r"^([a-zA-Z]|_)([a-zA-Z0-9]*_[a-zA-Z0-9]+)*([a-zA-Z0-9]+)?(_|[a-zA-Z0-9]|)$"
#ENDS WITH ALPHABET OR DIGITS 
#STARTS WITH _ OR ALPHABET
ID_2 = r"^([a-zA-Z]|_)([a-zA-Z0-9]|_)*([a-zA-Z0-9])$"


test_string = input("Enter a string: ")

if re.match(int_const, test_string):
    print(f"'{test_string}' : int_const")
elif re.match(flt_const, test_string):
    print(f"'{test_string}' : flt_const")
elif re.match(ID_1, test_string):
    print(f"'{test_string}' : ID1")
elif re.match(ID_2, test_string):
    print(f"'{test_string}' : ID2")
elif re.match(char_const, test_string):
    print(f"'{test_string}' : char_const")
elif re.match(string_const, test_string):
    print(f"'{test_string}' : string_const")
else:
    print(f"'{test_string}' does not match any pattern")
