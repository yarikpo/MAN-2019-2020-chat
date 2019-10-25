import vishener as vi

DEBUG = True

matr, randArr, alphabet = vi.init(DEBUG)

text = input('type text here: ')
key = input('type password here: ')

ciphertext = vi.chipher(text, key, matr, alphabet, DEBUG)

if DEBUG == True:
    print('Ciphertext: ', ciphertext)
    print('Text: ', vi.dechipher(ciphertext, key, len(randArr), matr, alphabet, DEBUG))

#######################################################################################

textSize = 15
keySize = 5
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

    return mas, cipherMas

print(buildBlocks(newText, newKey, times))
