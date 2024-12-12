# Readability test using Coleman-Liau index
from cs50 import get_string


def main():
    # Prompt the user for some text
    text = get_string("Text: ")

# Count the number of letters, words and sentences in the text
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

# Compute the Coleman-Liau index
    L = letters / words * 100
    S = sentences / words * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    grade_level = round(index)

# Print grade level
    if grade_level < 1:
        print("Before Grade 1")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade_level}")


# Function to count letters
def count_letters(text):
    count_l = 0
    for char in text:
        if char.isalpha():
            count_l += 1
    return count_l

# Function to count words
def count_words(text):
    words = text.split()
    return len(words)

# Function to count sentences
def count_sentences(text):
    count_s = 0
    for char in text:
        if char in ['.', '!', '?']:
            count_s += 1
    return count_s


main()
