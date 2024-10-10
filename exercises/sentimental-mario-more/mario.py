# TODO

def main():

    # prompts user for a height greater than 0
    while True:
        height = int(input('Height: '))
        if height > 0:
            break

    # printing pyramid
    for i in range(height):
        up_count = i + 1
        down_count = height - up_count
        print(down_count * ' ', up_count * '#', ' ', up_count * '#', sep='')

main()