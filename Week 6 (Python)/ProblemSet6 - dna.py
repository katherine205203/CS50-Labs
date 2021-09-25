from sys import argv, exit
import csv
import re
from collections import OrderedDict

    
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
    
# Open database file and create list of people as dictionaries
with open(argv[1], newline="") as database:
    people = csv.DictReader(database)
    header = people.fieldnames
    people = list(people)
    for person in people:
        person = dict(person)
        
# Open dna sequence
with open(argv[2]) as sequence:
    dnaprofile = sequence.read()
    
# Create profile for dna sequence matching
profile = OrderedDict.fromkeys(header)
profile.popitem(last=False)


# Recursive function to find longest match 
def findlongest(expression, string, longest):
    match = re.search(expression, string)
    
    # If no more matches, return current longest value
    if not match:
        return longest
        
    # If exits a longer one, update longest
    matchlength = match.end() - match.start()
    if matchlength > longest:
        longest = matchlength
        
    # Recursive call function on string, starting after end of match
    longest = findlongest(expression, string[match.end():], longest)
    return longest


# Update profile with number of sequences matched
for k, v in profile.items():
    longest = 0 
    longest = findlongest(rf"({k})+", dnaprofile, longest)
    longest /= len(k)
    profile[k] = int(longest)

# Check if match anyone
for person in people:
    match = True
    for k, v in profile.items():
        if v != int(person[k]):
            match = False
    if match:
        print(person["name"])
        exit()
print("No match")
