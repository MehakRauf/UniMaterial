# Write a list comprehension which, from a list, generates a lowercased version of each string that has
# length greater than five. 

original_list = ["Apple", "banana", "Orange", "grapefruit", "plum"]
new_list=[]
for fruit in original_list:
     if len(fruit) > 5:
          new_list.append(fruit.lower())

print(new_list)
