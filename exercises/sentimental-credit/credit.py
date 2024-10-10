# TODO

length = 0

def main():

    # get card number
    global length

    while True:
        number = input('Number: ')
        length = len(number)
        if length > 12 and length < 17 and number.isnumeric():
            break

    if not checksum(number):
        print('INVALID')
        return

    card = get_type(number)
    print(card)


#checksum returns True if number is legit
def checksum(number):

    total = 0
    multiple = 0

    for i in range(2, length + 1, 2):
        multiple = 2 * int(number[-i])
        for char in str(multiple):
            total += int(char)

    for j in range(1, length + 1, 2):
        total += int(number[-j])

    if (total % 10) == 0:
        return True

    return False


def get_type(number):

    mastercard = [51, 52, 53, 54, 55]
    amex = [34, 37]

    if int(number[0]) == 4:
        return 'VISA'

    if int(number[:2]) in mastercard:
        return 'MASTERCARD'

    if int(number[:2]) in amex:
        return 'AMEX'

    return 'INVALID'


main()