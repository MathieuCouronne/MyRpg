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
    in_c = {'c': [], 'h': []}
    for line in lines:
        match = search("\/\/", line.rstrip())
        if match and name[-1] == 'c':
            in_c['c'].append(match.pos)
        elif match and name[-1] == 'h' and (line[match.span()[1]] != ' ' or (line[match.span()[1]] == ' ' and line[match.span()[1] + 1].islower())):
            in_c['h'].append(match.pos)
    if len(in_c['c']) != 0:
        amount = len(in_c['c'])
        print(f"{amount} comments {'has' if amount == 1 else 'have'} been detected in {name}")
    elif len(in_c['h']) != 0:
        amount = len(in_c['h'])
        print(f"{amount} invalid comments {'has' if amount == 1 else 'have'} been detected in header {name}")


for filename in filenames:
    relative = filename.relative_to(relativity)
    with open(filename) as file:
        lines = [line.rstrip() for line in file]
    manage_comments(str(relative), lines)
