# SimplePasswordManager
This is a very basic password manger written in c++

## Disclaimer
This is my first c++ program and I know that the code will not have been written particularly well!


I wrote this whilst bored in a Java lecture
## Description
This works by asking the user for a password. It then uses this password to decrypt the saved passwords. However because of the type of encryption (bitwise xor) it does not need to authenticate the user therefore taking away the possibility of someone else brute forcing the program.
When you request a password from the program it uses the password you have entered to decrypt the password and show it to the user.

## Usage
```./simplepasswordmanager```

## Setup
Copy ```simplepasswordmanager.cpp``` into the directory that you want the program in. Now run ```sudo mkdir manager```. 
When you have done this you then want to run ```g++ -o simplepasswordmanager simplepasswordmanager.cpp```. At this point you should be able to run the program however if you do not have permision to do this you will 
want to run ```sudo chmod +x simplepasswordmanager```.
