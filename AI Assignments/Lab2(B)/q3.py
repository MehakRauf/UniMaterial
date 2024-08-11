# Write a program to compute quotient and remainder of a number without using division ('/') operator
# and modulo ('%') operator. Also mention procedure for calculating

def compute_quotient_and_remainder(dividend, divisor):
    quotient = 0
    remainder = 0

    # Determine the sign of the quotient
    sign = 1
    if dividend < 0:
        dividend = -dividend
        sign = -sign
    if divisor < 0:
        divisor = -divisor
        sign = -sign

    # Compute the quotient and remainder
    while dividend >= divisor:
        dividend -= divisor
        quotient += 1

    remainder = dividend * sign

    return quotient, remainder

dividend = -13
divisor = 4
quotient, remainder = compute_quotient_and_remainder(dividend, divisor)

print(f"Quotient: {quotient}")
print(f"Remainder: {remainder}")
