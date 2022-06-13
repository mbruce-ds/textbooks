#! /usr/bin/python3

import sys

def euclid(m, n):
    r = m % n
    if r == 0:
        return n
    return euclid(n, r)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print('Pass two arguments (two natural numbers)')
        sys.exit()

    m = sys.argv[1]
    n = sys.argv[2]

    try:
        m = int(m)
        n = int(n)
        assert m > 0
        assert n > 0
    except (ValueError, AssertionError) as e:
        print('Pass natural numbers')
        sys.exit()

    r = euclid(m, n)
    print(f'The greatest common divisor of {m} and {n} is {r}.')
