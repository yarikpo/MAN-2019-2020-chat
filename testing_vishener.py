import vishener as vi
import time

DEBUG = False

matr, randArr, alphabet = vi.init(DEBUG)

test_number = 5000
string_size = 10000
key_size = 2000

text = 'a' * string_size
key = 'z' * key_size

tests_number = 1
col = 0

for _ in range(0, tests_number):
    start_time = time.time()
    # x = 1
    # for i in range(0, 100000):
    #     x *= 3
    for i in range(0, test_number):
        ciphertext = vi.chipher(text, key, matr, alphabet, DEBUG)
        ciphertext = vi.dechipher(ciphertext, key, len(randArr), matr, alphabet, DEBUG)
    end_time = time.time()
    col+= end_time - start_time


print(col / tests_number / test_number)
