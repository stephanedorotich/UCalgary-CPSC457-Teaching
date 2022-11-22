# Author: Stéphane Dorotich
# CPSC 457
# Use freely

import sys
import random
import time

def makeFakeFAT(n_blocks: int):
    random.seed(time.time())
    
    ## Produce random number.
    ## -1 has a ~12.5% chance, every other number is evenly distributed
    term_blocks = int(n_blocks/8)+1
    total = n_blocks + term_blocks

    for i in range(n_blocks):
        rand_num = random.randrange(0, total)
        if (rand_num >= n_blocks):
            print(-1)
        else: print(rand_num)

def usage_error(progName: str):
    print("Usage:\n\t" + progName + " n", end="")
    print("\t\t0 <= n < 1,000,000")
    exit(-1)

if __name__ == "__main__":
    if (len(sys.argv) != 2):
        usage_error(sys.argv[0])

    n_blocks = 0
    try:
        n_blocks = int(sys.argv[1])
    except:
        pass
    
    if (n_blocks == 0) or (n_blocks >= 1000000):
        usage_error(sys.argv[0])
    
    makeFakeFAT(n_blocks)