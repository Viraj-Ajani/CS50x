def lc(text):
    """ To count no. of letters present in given input."""
    letter = 0
    for i in range(len(text)):
        if (ord(text[i]) >= 65 and ord(text[i]) <= 90) or (ord(text[i]) >= 97 and ord(text[i]) <= 122):
            letter += 1
            
    return letter
    

def wc(text):
    """ To count no. of words present in given input."""
    word = 1
    for i in range(len(text)):
        if ord(text[i]) == 32:
            word += 1
            
    return word
    

def sc(text):
    """ To count no. of sentences present in given input."""
    sentence = 0
    for i in range(len(text)):
        if ord(text[i]) == 33 or ord(text[i]) == 46 or ord(text[i]) == 63:
            sentence += 1
    
    return sentence


# Reading Text form user
Text = input("Text : ")

# Calculating letters per 100 words and sentence per 100 words
L = lc(Text) / wc(Text) * 100
S = sc(Text) / wc(Text) * 100

# Calculating index
index = 0.0588 * L - 0.296 * S - 15.8

# Printing Grade
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print("Grade", round(index))