from cs50 import get_float

# Check for positive input from user
while True:
    dollar = get_float("Change owed: ")
    if dollar > 0:
        break

# Change from dollar to cent  
cent = dollar * 100
coin = 0

# Number of coins
while True:
    if cent <= 0:
        break
    
    elif cent >= 25:
        cent = cent - 25
        coin += 1
        
    elif cent >= 10:
        cent = cent - 10
        coin += 1
    
    elif cent >= 5:
        cent = cent - 5
        coin += 1
        
    else:
        cent = cent - 1
        coin += 1
        
print("Number of coins: " + str(coin))
