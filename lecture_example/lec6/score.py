from cs50 import get_int

#scores = [72, 73, 33]

#average = sum(scores) / len(scores)
#print(f"Average: {average}")

scores = []
for i in range(3):
    score = get_int("Score: ")
    #scores.append(score) # can also be wrote such as bellow
    scores = scores + [score]

average = sum(scores) / len(scores)
print(f"Average: {average}")
