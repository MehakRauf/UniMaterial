# import random

# score = 0

# print("== Number Guessing Game ==")

# def play_game():
#     global score
#     attempts = 0
#     target_number = random.randint(1, 100)
    
#     hints = ["Higher", "Lower"]

#     while True:
#         guess = input("Enter your guess (1-100): ")

#         guess = int(guess)
#         attempts += 1

#         if guess == target_number:
#             print("Congratulations! You guessed the correct number in", attempts, "attempts.")
#             score += 1
#             break
#         elif guess < target_number:
#             print(hints[0])
#         else:
#             print(hints[1])
    
# for round in range(3):
#     play_game()
#     print("Your score after" ,round+1," round is: ", score)
#     print("-----")
#     round+=1


def factorial(n):
    fac=1
    for i in range (1,n+1):
        fac=fac *i
    return fac
print(factorial(6))