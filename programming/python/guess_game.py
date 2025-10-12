import random

print("Number Guess Game")
print("Select a number between 1 and 100")

n = random.randint(1, 100)
#print(f"(DEBUG) The secret number is: {n}")  # test amaçlı

g = 0

while True:
    try:
        guess = int(input("Your guess: "))
        g += 1
        
        if guess < n:
            print("Please enter a bigger number")
        elif guess > n:
            print("Please enter a smaller number")
        else:
            print(f"🎉 Congrats! You found it in {g} guesses. The number was: {n}")
            break
    except ValueError:
        print("Please enter a valid number!")
