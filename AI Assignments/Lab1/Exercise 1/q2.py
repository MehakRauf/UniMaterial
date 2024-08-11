# Write a Python program to convert temperatures to and from celsius,
# Fahrenheit.
# Formula : c/5 = f-32/9
# Expected Output :
# Enter temp in Celsius: 60°C
# Temperature in Fahrenheit is :140

# temperature converter
f1=int(input('Enter the temperature in fahrenheit: '))
c1=int(input('Enter the temperature in celcius: '))
f=(c1 * 9/5) + 32
c=(f1-32)*5/9 
print('The temperature in celcius is: ',c)
print("The temperature in fahrenheit is: ",f)
