from cs50 import get_float

# Prompt input for amout of changes
while True:
    c = get_float("Change owe: ")
    if c >= 0.01:
        break
# convert amount of change for interger calculation
a = int(c * 100)
# calculating amount of 25 cent
c25 = a // 25
a %= 25

# calculating amount of 10
c10 = a // 10
a %= 10

# calculating amount of 5
c5 = a // 5
a %= 5

# calculating amount of 1
c1 = a

# calculating total number of coins
t = int(c25 + c10 + c5 + c1)

print(f"{t}")
