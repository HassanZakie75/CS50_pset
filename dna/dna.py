# Program to identify which sequences of DNA belongs to whom. by Hassan Zakie
import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py databases/{size}.csv sequence/{number}.txt")
        sys.exit(1)

    database = sys.argv[1]
    sequence = sys.argv[2]

    # TODO: Read database file into a variable
    with open(f"{database}") as datafile:
        readData = csv.reader(datafile)

        # Read the value of the data without including the hearder
        subsequences = next(readData)[1:]
        profiles = list(readData)  # make a list of the database

    # TODO: Read DNA sequence file into a variable
    with open(f"{sequence}") as seqfile:
        seq = seqfile.read()

    # TODO: Find longest match of each STR in DNA sequence
    longest_matches = {}
    for subseq in subsequences:
        # make a new dictionary for str and count
        longest_matches[subseq] = longest_match(seq, subseq)

    # TODO: Check database for matching profiles
    for profile in profiles:
        match = True
        for subseq in subsequences:
            if int(profile[subsequences.index(subseq) + 1]) != longest_matches[subseq]:
                match = False
                break  # if the number not equal break, and repeat
        if match:
            print(f"{profile[0]}")
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()
