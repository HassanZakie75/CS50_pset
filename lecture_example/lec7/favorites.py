# guide to open csv file in python
import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file) # read your csv file as dictionary
    #for row in reader:
        #favorite = row["language"]
        #print(favorite)
    # how to count the input
    scratch, c, python = 0, 0, 0 # setting the variables
    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Pyhton: {python}")

