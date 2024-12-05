#!/usr/bin/env python3

from english_dictionary.scripts.read_pickle import get_dict
import requests

WORD_LEN = 5

def generate_en_words():
    english_dict = get_dict()

    en_words = []
    for w in english_dict.keys():
        if len(w) == WORD_LEN:
            en_words.append(w.lower())
    en_words = set(en_words)
    return en_words

def generate_ru_words():
    response = requests.get('https://raw.githubusercontent.com/danakt/russian-words/master/russian.txt')
    text = response.content.decode('cp1251')
    ru_words = []
    for w in text.split('\n'):
        if w.isalpha() and len(w) == WORD_LEN:
            ru_words.append(w.lower())
    ru_words = set(ru_words)
    return ru_words

def make_dict(name, words):
    with open(name, 'w') as f:
        for word in words:
            f.write(word)
            f.write("\n")

en_words = generate_en_words()
ru_words = generate_ru_words()

make_dict('en_dict.txt', en_words)
make_dict('ru_dict.txt', ru_words)
