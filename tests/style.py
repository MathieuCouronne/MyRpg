#!/usr/bin/env python3
from pathlib import Path
from re import search

filenames = []
directories = ['../src', '../include']
relativity = Path('..')

for directory in directories:
    for file in Path(directory).rglob("*.[ch]"):
        filenames.append(file)


def manage_comments(name, lines):
    errors = {'c': [], 'h': [], 'pathes': []}
    for i, line in enumerate(lines):
        match_comments = search("\/\/", line)
        match_magic_pathes = search("\.\/.*", line)
        if match_magic_pathes and name[-1] != 'h':
            errors['pathes'].append(i)
        if match_comments and name[-1] == 'c':
            errors['c'].append(i)
        elif match_comments and name[-1] == 'h' and (line[match_comments.span()[1]] != ' ' or (line[match_comments.span()[1]] == ' ' and line[match_comments.span()[1] + 1].islower())):
            errors['h'].append(i)
    if not name.islower():
        print(f"File {name} is not in lowercase.")
    if not lines[-1][-1] == '\n':
        print(f"File {name} doesn't have a line break at end of file.")
    if len(errors['pathes']):
        amount = len(errors['pathes'])
        print(f"{amount} {'path has' if amount == 1 else 'pathes have'} been detected in {name}.")
    if len(errors['c']) != 0:
        amount = len(errors['c'])
        print(f"{amount} comments {'has' if amount == 1 else 'have'} been detected in {name}.")
    elif len(errors['h']) != 0:
        amount = len(errors['h'])
        print(f"{amount} invalid comments {'has' if amount == 1 else 'have'} been detected in header {name}.")


for filename in filenames:
    relative = filename.relative_to(relativity)
    with open(filename) as file:
        lines = [line for line in file]
    manage_comments(str(relative), lines)
