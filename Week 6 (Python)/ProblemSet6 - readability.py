from cs50 import get_string

# Values
letter = 0
word = 1
sentence = 0

# Take input from user
text = get_string("Text: ")

for c in text:
    if c.isalpha():
        letter += 1
    if c == " ":
        word += 1
    if c == "!" or c == "." or c == "?":
        sentence += 1
        
# Coleman-Liau Index
L = letter/word * 100
S = sentence/word * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print result
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade " + str(index))
