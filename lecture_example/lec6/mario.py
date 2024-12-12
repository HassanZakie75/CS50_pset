from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0:
        break

for i in range(n):
    print("#")


for j in range(n):
    print("?",end="")
print()

# or you could do this

print("?" * n)


#print 3 * 3 block

for i in range(3):
    for j in range(3):
        print("#", end="")
    print()
# or can write like this

for i in range(3):
    print("o" * 3)
