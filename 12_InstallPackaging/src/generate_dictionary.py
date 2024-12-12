#!/usr/bin/env python3

## @package generate_dictionary
# This script generates english dictionary. Then it deletes all
# words, which length isn't five.

from english_dictionary.scripts.read_pickle import get_dict

## Length of words
WORD_LEN = 5

# generates dictionary without duplicate (all words consists of five letters)
def generate_en_words():
    english_dict = get_dict()

    en_words = []
    for w in english_dict.keys():
        if len(w) == WORD_LEN:
            en_words.append(w.lower())
    en_words = set(en_words)
    return en_words

# Save dictionary in file
#   name - name of the file
#   words - dictionary from generate_en_words() function
def make_dict(name, words):
    with open(name, 'w') as f:
        for word in words:
            f.write(word)
            f.write("\n")

en_words = generate_en_words()

make_dict('en_dict.txt', en_words)
