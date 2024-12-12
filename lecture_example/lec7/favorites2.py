# guide to open csv file in python
import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file) # read your csv file as dictionary
    counts = {}

    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

#for favorite in counts:
#    print(f"{favorite}: {counts[favorite]}")

#too sort output alphabetically
#for favorite in sorted(counts):
#    print(f"{favorite}: {counts[favorite]}")

#too sort output by rank
for favorite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favorite}: {counts[favorite]}")

