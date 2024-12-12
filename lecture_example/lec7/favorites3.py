# guide to open csv file in python
import csv
from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file) # read your csv file as dictionary
    counts = Counter ()

    for row in reader:
        favorite = row["language"] # just need to change this row label to change the data020
        counts[favorite] += 1

#too sort output by rank
#for favorite in soted(counts, key=counts.get, reverse=True):
#    print(f"{favorite}: {counts}")

favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite]}")
