# 1-SetUp

## Objectives
Prepare students for remote linux development by:

- Installing WSL, Ubuntu, and VS Code
- Configure environment for remote development
- Familiarize students with Linux commands

note: Ubuntu is not required (but it's what I use.) You can use *Git bash*, *wsl from PowerShell*, or any other option you prefer.

**Mac users DO NOT need to install WSL or Ubuntu!**

## 1. Installation
- WSL: (Windows users only)
  - Press Windows key
  - Search "PowerShell"
  - Select the "Run as Administrator" option
  - ```wsl --install``` (or ```wsl --install -d Ubuntu```)
  - https://docs.microsoft.com/en-us/windows/wsl/install
  - https://www.omgubuntu.co.uk/how-to-install-wsl2-on-windows-10
  - Reboot your computer after install!
  - Some Windows machines need to be set to developer mode. Follow [this guide.](https://answers.microsoft.com/en-us/insider/forum/all/how-to-enable-the-windows-subsystem-for-linux/16e8f2e8-4a6a-4325-a89a-fd28c7841775)
- Ubuntu: (Windows users only)
  - Use Windows store
  - https://ubuntu.com/wsl
- VS Code: (All students)
  - https://code.visualstudio.com/download

## 2. Configure Environment
- Open VS Code and install extensions
  - Open Extensions with Ctrl + Shift + X
  - Install "Remote - SSH"
  - Install "Better C++ Syntax"
- Update apt
  - ```sudo apt update```
- Ensure that python3 is installed (it will be)
  - ```python3 --version```
- Ensure g++ compiler is installed
  - ```g++ --version```
  - ```sudo apt install g++```

## 3. Practice Linux Commands
### Exercise 0: SSH to University Servers
***
 - ```ssh first.last@linuxlab.cpsc.ucalgary.ca```
  - for help resetting the password to your CPSC account visit [ucalgary.service-now.com/it](https://ucalgary.service-now.com/it?id=kb_article&sys_id=29aedd1bdb3e63c0d1b63ccb7c961963)
  - for account problems visit: [itregport.ucalgary.ca](https://itregport.ucalgary.ca)

### Exercise 1: Exploring Linux Filesystem via Terminal
***
- Tab auto-complete!
- ```du -h --max-depth=1 ./``` check DiskUsage of directories.
  - Talk about CPSC account storage limits.
  - ```less readme.txt``` (at root dir of cpsc account), this file talks about usage limits.
  - Notice that ```./.vscode-server``` is BIG. This directory CAN BE DELETED to free up space (there is bloat.)
- ```ls, ls -l, ls -a```
- ```cd dirname, cd ., cd .., cd ../../../, cd ~```

### Exercise 2: Making files and directories
***
- ```clear```!!!
- ```mkdir 457```
- ```cd 457```
- ```echo "here is some text" > myfile.txt```
- ```less, ls, ls -l``` to view file content & info (eg. datetime created)
- ```nano``` or ```vim``` to edit myfile.txt
- ```wc, wc -l, wc -w, wc -m``` WordCount: lines, words, characters respectively.
- ```echo "print('Hello world')" > hello.py```
- ```python3 hello.py```

### Exercise 3: Removing files
***
- Move into ```t457/1-SetUp/```
- !!! CAUTION about permenancy of ```rm``` !!!!
- ```rm myfile.txt```
- Run ```python3 dummy_files.cpp 5```
- Move into the created ```dummyfiles``` directory.
- Remove files 1 by 1... -> (```rm file1.txt```)
- Run ```python3 dummy_files.cpp 300```
- "Is it still fine to remove files one by one?"
- Remove files using * -> (```rm file*```)
- Run ```python3 dummy_files.cpp``` again
- Remove dir using ```rm -rf files/``` (rf = recursive, force)

### Exercise 4: Getting Files To & From Server
***
SFTP (Secure File Transfer Protocol) is a great way for students to move files to and from the server. It's lightweight and works just like SSH!

- ```logout``` to close SSH connection.
- ```sftp first.last@linuxlab.cpsc.ucalgary.ca```
- Navigate **remote** filesystem with ```ls``` and ```cd``` commands. (```rm```, ```rmdir```, and ```mkdir``` all work)
- Navigate **local** filesystem with ```lls``` and ```lcd``` (local ls, and local cd) i.e. just us 'l' prefix
- Upload file using ```put some/file.txt```
- Download file using ```get some/file.txt```
- You can put/get entire directories using ```-r``` recursive option.
- ```quit``` or Ctrl + D (disconnect)
- Use ```less, ls, cd, ssh``` to verify put/get.
