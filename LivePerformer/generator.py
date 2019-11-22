import random

def random_yes():
    m = random.randint(1, 1000)
    n = m
    k = 2
    while n * k > m:
        n = random.randint(0, 1000)
        k = random.randint(1, 1000)
    return (n, m, k)

def main():
    capable = random.choice([True, False])
    n = 0
    m = 0
    k = 0
    if capable:
        [n, m, k] = random_yes()
    else:
        # This may also be 'Yes', but probably no
        n = random.randint(0, 1000)
        k = random.randint(1, 1000)
        m = random.randint(1, 1000)
    print(f'{n} {m} {k}')


if __name__ == '__main__':
    main()
