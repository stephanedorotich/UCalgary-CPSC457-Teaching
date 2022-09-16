import sys
import os

def usage_error():
    print("Usage:\n\tpython dummy_files.py number_of_files")
    sys.exit()

def create_dummy_files(i):
    s = 1;
    while s <= i:
        name = "./files/file" + str(s) + ".txt"
        if os.path.isfile(name):
            i+=1;
        else:
            f = open(name, 'w')
            f.write(name)
            f.close()
        s+=1

if __name__ == "__main__":
    if not (len(sys.argv) == 2):
        usage_error()    
    try:
        num_files = int(sys.argv[1])
        if num_files <= 0: raise ValueError()
        if not os.path.isdir('files'):
            os.mkdir('files')
        create_dummy_files(num_files)
        print(f'{num_files} file(s) created.')
    except:
        usage_error()
