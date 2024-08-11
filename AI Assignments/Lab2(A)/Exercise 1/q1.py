# Exercise 1:
# (I)Cabinets and Boxes are objects that are mostly in cubic shape. Make a program that takes
# inputs like height, width and depth from user and then calculate volume of the cube:
# volume = height ∗ width ∗ depth
# After calculating volume of cube, compare it with following ranges and print the relevant label:

def get_volume_label(volume):
    if volume <= 10:
        return "Extra Small"
    elif volume <= 25:
        return "Small"
    elif volume <= 75:
        return "Medium"
    elif volume <= 100:
        return "Large"
    elif volume <= 250:
        return "Extra Large"
    else:
        return "Extra-Extra Large"

# Get input from user
height = float(input("Enter height (in cm): "))
width = float(input("Enter width (in cm): "))
depth = float(input("Enter depth (in cm): "))

# Calculate volume
volume = height * width * depth

# Get volume label
label = get_volume_label(volume)

# Print the relevant label
print("Volume Label: " + label)
