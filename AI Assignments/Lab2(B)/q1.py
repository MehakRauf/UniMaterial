# Write a program that converts a positive integer into the Roman number system. The Roman number
# system has digits I (1), V (5), X (10), L (50), C(100), D(500) and M(1000). Numbers up to 3999 are
# formed according to the following rules

roman_dict = {
    1000: "M",
    900: "CM",
    500: "D",
    400: "CD",
    100: "C",
    90: "XC",
    50: "L",
    40: "XL",
    10: "X",
    9: "IX",
    5: "V",
    4: "IV",
    1: "I"
}

def to_roman(num):
    result = ""
    for key in roman_dict:
        while num >= key:
            result += roman_dict[key]
            num -= key
            print(result)
    return result

print(to_roman(1978))

