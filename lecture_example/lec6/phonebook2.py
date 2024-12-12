# dictionary of people
people = [
    {"name": "Hamza", "number": "1263"},
    {"name": "Toya", "number": "8294"},
    {"name": "Faiq", "number": "5268"},
]

name = input("Name: ")

for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")
