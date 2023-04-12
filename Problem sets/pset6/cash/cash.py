# Prompting user for positive value
while True:
    change = input("Change owed: ")
    try:
        change = float(change) * 100
        change = int(change)
        if change > 0:
            break
    except:
        continue

coins = 0
while change > 0:
    if change - 25 >= 0:
        coins += 1
        change -= 25
    elif change - 10 >= 0:
        coins += 1
        change -= 10
    elif change - 5 >= 0:
        coins += 1
        change -= 5
    else:
        coins += 1
        change -= 1
        
print(coins)