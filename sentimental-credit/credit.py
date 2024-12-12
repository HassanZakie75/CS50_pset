from cs50 import get_int


def main():
    # Prompt for credit card number
    while True:
        card_number = get_int("Number: ")
        if card_number > 0:
            break

    # Check the length of the input
    card_length = len(str(card_number))

    # Check 2 intial number of the credit card
    first_two_digits = int(str(card_number)[:2])
    first_digits = int(str(card_number)[:1])

    # Check length validity
    if card_length not in [13, 15, 16]:
        print("INVALID")
        exit()

    # If card is valid, check which does it belong too
    if luhn_checksum(card_number):
        if card_length == 15 and first_two_digits == 34 or first_two_digits == 37:
            print("AMEX")
        elif card_length == 13 or card_length == 16 and first_digits == 4:
            print("VISA")
        elif card_length == 16 and first_two_digits in [51, 52, 53, 54, 55]:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")

    # function for Luhn's algorithm checksum


def luhn_checksum(card_number):

    # setting up intial variables
    checksum = 0
    card_num = str(card_number)
    digits = len(str(card_num))

    # note: range(start. stop, step)
    for i in range(digits - 1, -1, -2):
        checksum += int(card_num[i])
    for i in range(digits - 2, -1, -2):
        digit = int(card_num[i]) * 2
        checksum += digit // 10 + digit % 10
    return checksum % 10 == 0


main()
