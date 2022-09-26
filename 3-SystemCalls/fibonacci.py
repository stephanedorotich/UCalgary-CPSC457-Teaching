import sys

def usage_error():
    print("Usage:\n\tpython fibonacci.py i\t\twhere i is the ith number of the fibonacci sequence to compute.")
    exit(-1)

def fib(n):
    if (n < 2):
        return n
    n1 = 0
    n2 = 1
    for _ in range(2, n+1):
        n3 = n1 + n2
        n1 = n2
        n2 = n3
    return n3


if __name__ == "__main__":
    if (len(sys.argv) != 2):
        usage_error()
    try:
        n = int(sys.argv[1])
        print(str(fib(n)))
    except:
        usage_error()