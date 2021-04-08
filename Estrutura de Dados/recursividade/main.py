def fatorial (n):

    if n == 0 or n == 1:
        return 1

    x = n -1
    y = fatorial(x)
    return n * y

if __name__ == '__main__':
    n = fatorial(5)
    print(n)
