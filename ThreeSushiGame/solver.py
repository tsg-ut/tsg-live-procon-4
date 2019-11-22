def optimal(c):
    if c == 'G':
        return 'S'
    return 'T'

hands = map(optimal, list(input()))
print(''.join(hands))
