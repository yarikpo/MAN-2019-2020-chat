import vishener as vi
import time

DEBUG = False

matr, randArr, alphabet = vi.init(DEBUG)

# text = input('type text here: ')
# key = input('type password here: ')

text = 'a' * 100000
key = 'z' * 200


start_time = time.time()


size = len(text)

ciphertext = vi.chipher(text, key, matr, alphabet, DEBUG)

if DEBUG == True:
    print('Ciphertext: ', ciphertext)
    print('Text: ', vi.dechipher(ciphertext, key, len(randArr), matr, alphabet, DEBUG))

#######################################################################################

textSize = 100000
keySize = 2000
times = 10

def addTextKey(text, key, textSize, keySize):
    resKey = key
    while len(resKey) < keySize:
        resKey = resKey + key
    resKey = resKey[:keySize]

    resText = text
    # resKey = str(abs(hash(resKey)))

    while len(resText) < textSize:
        resText = resText + resKey
    resText = resText[:textSize]

    return resText, resKey

newText, newKey = addTextKey(text, key, textSize, keySize)
if DEBUG == True:
    print((newText, newKey))

def buildBlocks(newText, newKey, times):
    global matr, alphabet
    mas = []
    cipherMas = []
    cipherMas.append(newKey)

    block = ""
    for i in range(0, len(newText)):
        block+= newText[i]
        if len(block) % len(newKey) == 0:
            mas.append(block)
            block = ""

    for i in range(0, len(mas)):
        cipherMas.append(vi.chipher(mas[i], cipherMas[i], matr, alphabet, False))

    for j in range(0, times - 1):
        cipherMas[0] = cipherMas[len(cipherMas) - 1]
        for i in range(0, len(mas)):
            cipherMas[i + 1] = vi.chipher(mas[i], cipherMas[i], matr, alphabet, False)

    return cipherMas

cipherMas = buildBlocks(newText, newKey, times)
# print(buildBlocks(newText, newKey, times))

# print(cipherMas)

def decipherBlocks(cipherMas, newKey, size, times):
    global randArr, matr, alphabet

    for _ in range(0, times - 1):
        i = len(cipherMas)
        while i != 0:
            i-= 1
            # print(i)
            cipherMas[i] = vi.dechipher(cipherMas[i], cipherMas[i - 1], len(randArr), matr, alphabet, False)
        cipherMas[0] = vi.dechipher(cipherMas[0], cipherMas[len(cipherMas) - 1], len(randArr), matr, alphabet, False)

    i = len(cipherMas)
    # print('last')
    while i != 1:
        i-= 1
        # print(i)
        cipherMas[i] = vi.dechipher(cipherMas[i], cipherMas[i - 1], len(randArr), matr, alphabet, False)
    cipherMas[0] = vi.dechipher(cipherMas[0], newKey, len(randArr), matr, alphabet, False)


    result = ""
    top = 0
    for i in range(1, len(cipherMas)):
        for j in cipherMas[i]:
            if top == size:
                break
            result+= j
            top+= 1
        if top == size:
            break
    return result

# print("[value]")
# print(decipherBlocks(cipherMas, newKey, size, times))

end_time = time.time()

print(end_time - start_time)
