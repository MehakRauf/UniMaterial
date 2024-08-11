# Write a Python program to print a specified list after removing the 0th, 4th and 5th elements
# Sample List : ['Red', 'Green', 'White', 'Black', 'Pink', 'Yellow',’Teapink’]
# Expected Output : ['Green', 'White', 'Black']


sample_list = ['Red', 'Green', 'White', 'Black', 'Pink', 'Yellow','Teapink']
to_remove = [0, 4, 5]
result=[]
for i in range(len(sample_list)) :
    if i not in to_remove:
        result.append(sample_list[i])
print(result)
