# TODO

def main():

    text = input('Text: ')
    word_count = get_word_count(text)
    avg_letters = get_avg_letters(text, word_count)
    avg_sentence = get_avg_sentences(text, word_count)

    index = round((0.0588 * avg_letters) - (0.296 * avg_sentence) - 15.8)
    if index > 16:
        print('Grade 16+')
    elif index < 1:
        print('Before Grade 1')
    else:
        print(f'Grade {index}')


def get_word_count(text):

    word_list = text.split()
    word_count = len(word_list)

    return word_count


def get_avg_letters(text, word_count):

    letter_count = 0

    for char in text:
        if char.isalpha():
            letter_count += 1

    avg_letters = (letter_count / word_count) * 100

    return avg_letters


def get_avg_sentences(text, word_count):

    sentence_count = 0
    sentence_indicator = ['.', '!', '?']

    for char in text:
        if char in sentence_indicator:
            sentence_count += 1

    avg_sentence = (sentence_count / word_count) * 100

    return avg_sentence

main()