# DEBUG = False

def init(DEBUG=True):
    import random
    alphabet = {}
    used =     {}

    top = 0
    now = 0
    randArr = []

    for i in range(0, ord('z') - ord('a') + 1):
        alphabet[chr(ord('a') + i)] = i + now
        alphabet[i + now] = chr(ord('a') + i)
        randArr.append(chr(ord('a') + i))
        used[chr(ord('a') + i)] = False
        if DEBUG == True:
            print(chr(ord('a') + i), i + now)
        top+= 1
    if DEBUG == True:
        print("\n\n")
    now = top

    ###############################################################################

    if DEBUG == True:
        print(f"\n\n{randArr}")
    random.shuffle(randArr)
    if DEBUG == True:
        print(f"\n\n{randArr}")

    matr = []
    for i in range(0, now):
        matr.append([])
        for j in range(0, now):
                matr[i].append(randArr[(i + j) % now])
                if DEBUG == True:
                    print(matr[i][j], ' ', end='')
        if DEBUG == True:
            print()

    if DEBUG == True:
        print(alphabet)

    return matr, randArr, alphabet
# print(matr)

# matr, randArr, alphabet = init(DEBUG)
#
# text = input('TEXT: ')
# key = input('Password: ')

def chipher(text, key, matr, alphabet, DEBUG=True):
    ciphertext = ''
    top = 0 # position on key

    for i in range(0, len(text)):
        top%= len(key)
        if DEBUG == True:
            print(f'alphabet[text[{i}]]: {alphabet[text[i]]}')
            print(f'alphabet[text[{top}]]: {alphabet[text[top]]}')
        ciphertext+= matr[alphabet[text[i]]][alphabet[key[top]]]
        top+= 1

    # print(ciphertext)
    return ciphertext

# print(chipher(text, key, matr, alphabet, DEBUG))

def dechipher(chiphertext, key, sz, matr, alphabet, DEBUG=True): # size of randArr or number of different symbols in dictinary
    text = ''
    top = 0

    def fun(symb, column):
        for i in range(0, sz):
            if matr[i][column] == symb:
                return i
        return None

    for i in range(0, len(chiphertext)):
        top%= len(key)

        if DEBUG == True:
            x = fun(chiphertext[i], top)
            if DEBUG == True:
                print(f'fun({chiphertext[i]}, alphabet[key[{top}]]): {x}')

        text+= alphabet[fun(chiphertext[i], alphabet[key[top]])]
        top+= 1

    return text

# print(dechipher(chipher(text, key, matr, alphabet, DEBUG), key, len(randArr), matr, alphabet, DEBUG))
