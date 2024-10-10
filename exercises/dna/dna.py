import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print('Usage: python dna.py data.csv sequence.txt')
        return

    # TODO: Read database file into a variable
    database = []
    try:
        with open(sys.argv[1], 'r') as file:
            reader = csv.DictReader(file)
            header = reader.fieldnames
            for row in reader:
                database.append(row)

    except FileNotFoundError:
        print('File not found')
    except PermissionError:
        print('You do not have permission to access file')

    # TODO: Read DNA sequence file into a variable
    try:
        with open(sys.argv[2], 'r') as file:
            sequence = file.read()

    except FileNotFoundError:
        print('File not found')
    except PermissionError:
        print('You do not have permission to access file')

    # TODO: Find longest match of each STR in DNA sequence
    #creates a database to store the subsequence info of each sequence
    sequence_database = {}
    for i in range(len(header)):
        sequence_database[header[i]] = None

    # iterates over subsequence in header and stores longest match into sequence database
    for i in range(1, len(header), 1):
        subsequence = header[i]
        sequence_database[subsequence] = str(longest_match(sequence, subsequence))


    # TODO: Check database for matching profiles
    for i in range(len(database)):
        sequence_database['name'] = database[i]['name']
        if sequence_database == database[i]:
            print(sequence_database['name'])
            return

    print('No match')
    return


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


main()
