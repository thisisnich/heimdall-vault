print("Hello World")
print("Here's another string")
print('He said: "Today is my Birthday!"')
print("Mon Tue Wed Thu Fri")
print("The 3 primary colours are:\n1. Red\n2. Blue\n3. Green")
def add(a, b):
    return a + b
print(add(5, 3))

students = ['Max', 'Monika', 'Christ', 'Frank']
print(students[0])
print(students[1])
print(students[0:2])
print(students[1:3])
students.append('Tom')
students.remove('Tom')
students.remove('Max')
# Sort remaining students alphabetically
students.sort()
print(students)

myList = ['abc', 688, "python programming", 33, 5, 6]
myList.append('end')
myList.insert(0, 'begin')
print(myList)

for item in myList:
    print(item)

for i in range(0,11):
    print(i)
for i in range(len(myList)):
    print(myList[i])
x = 6
guess = int(input("Enter a number: "))
if guess == x:
    print("You guessed correctly!")
elif guess > x:
    print("Your guess is too high!")
elif guess < x:
    print("Your guess is too low!")


for i in range(len("Hello")):
    print("Hello"[:i])

    
def guess_game(secret_number=6):
    """Simple number guessing game module."""
    try:
        guess = int(input("Enter a number: "))
        if guess == secret_number:
            print("You guessed correctly!")
        elif guess > secret_number:
            print("Your guess is too high!")
        else:
            print("Your guess is too low!")
    except ValueError:
        print("Please enter a valid number.")

# Example usage
if __name__ == "__main__":
    guess_game()
