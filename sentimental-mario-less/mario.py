# print Mario's pyramid at the end of the stage using python
from cs50 import get_int

# While loop to check input is numerical and between 1 to 9
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break


for i in range(n):  # iterating for each row,
    for j in range(n - 1 - i):  # print " " for each row
        print(" ", end="")
    for j in range(i + 1):
        print("#", end="")  # print # for each row
    print()
