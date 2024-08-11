# Write a program that calculates the user’s body mass index (BMI) and classify it as underweight,
# normal, overweight, or obese, based on the table from the United States Centers for Disease Control.

def calculate_bmi(weight, height):
    bmi = weight / (height ** 2)
    return bmi

def classify_bmi(bmi):
    if bmi < 18.4:
        return "Underweight"
    elif bmi < 24.9:
        return "Normal weight"
    elif bmi < 25.0:
        return "Overweight"
    else:
        return "Obese"

weight = float(input("Enter your weight in kilograms: "))
height = float(input("Enter your height in meters: "))
# 1.6764
bmi = calculate_bmi(weight, height)
classification = classify_bmi(bmi)

print("Your BMI is:", bmi)
print("Classification:", classification)
