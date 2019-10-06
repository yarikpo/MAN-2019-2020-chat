import random

DEBUG = False
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

# for i in range(0, ord('Z') - ord('A') + 1):
#     alphabet[chr(ord('A') + i)] = i + now;
#     alphabet[i + now] = chr(ord('A') + i)
#     used[chr(ord('A') + i)] = False
#     print(chr(ord('A') + i), i + now)
#     top+= 1
#
# print("\n\n")
# now = top
#
# for i in range(0, ord('я') - ord('а') + 1):
#     alphabet[chr(ord('а') + i)] = i + now;
#     alphabet[i + now] = chr(ord('а') + i)
#     used[chr(ord('а') + i)] = False
#     print(chr(ord('а') + i), i + now)
#     top+= 1
#
#
# print("\n\n")
# now = top
#
# for i in range(0, ord('Я') - ord('А') + 1):
#     alphabet[chr(ord('А') + i)] = i + now;
#     alphabet[i + now] = chr(ord('А') + i)
#     used[chr(ord('А') + i)] = False
#     print(chr(ord('А') + i), i + now)
#     top+= 1
#
# print("\n\n")
# now = top
#
# for i in range(0, ord('9') - ord('0') + 1):
#     alphabet[chr(ord('0') + i)] = i + now;
#     alphabet[i + now] = chr(ord('0') + i)
#     used[chr(ord('0') + i)] = False
#     print(chr(ord('0') + i), i + now)
#     top+= 1

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
# print(matr)

text = input('TEXT: ')
key = input('Password: ')

def chipher(text, key):
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

print(chipher(text, key))

def dechipher(chiphertext, key):
    text = ''
    top = 0

    def fun(symb, column):
        for i in range(0, len(randArr)):
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

print(dechipher(chipher(text, key), key))
