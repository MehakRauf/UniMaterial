# Play with some of the list functions. You can find the methods you can call on an object via the dir
# and get information about them via the help command: 

# List
list=['a','b','c','d']
list.reverse()
list.remove('a')
print("The list after reversing and removing 'a' " ,list)
list.append('r')
list.reverse()
list.append('i')
list.append('e')
list.sort()
print("the list after appending 'r', reversing, then appending 'i' and 'e' and then sorting the list is: ",list)
