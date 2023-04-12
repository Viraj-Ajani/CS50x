# Prompting user for height b/w 1 to 8
while True:
    height = input("Enter height: ")
    try:
        height = int(height)
        if height > 0 and height < 9:
            break
    except:
        continue
    
for i in range(height):
    # Printing spaces
    for j in range(height - i - 1):
        print(" ", end="")
        
    # Printing #    
    for j in range(i+1):
        print("#", end="")
        
    print("  ", end="")
    
    for j in range(i+1):
        print("#", end="")
    
    print()
