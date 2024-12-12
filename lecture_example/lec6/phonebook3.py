# dictionary of people
#people = [
#    {"name": "Hamza", "number": "1263"},
#    {"name": "Toya", "number": "8294"},
#    {"name": "Faiq", "number": "5268"},
#]
# change list dictionary to one big dictionary
people = {
    "Hamza": "1263",
    "Toya": "8294",
    "Faiq": "5268",
}

name = input("Name: ")

if name in people:
    number = people[name]
    print(f"Found {number}")
else:
    print("Not Found")
