#Client
# TCP Client Code
 
# Set the server address to variable host
x = input()
x = x.split()
host = x[0]
port = int(x[1])              # Sets the variable port to 4446

file = x[2]
 
from socket import *             # Imports socket module
 
s = socket(AF_INET, SOCK_STREAM)      # Creates a socket
s.connect((host,port))          # Connect to server address
msg = "GET /"+file+" HTTP/1.1"

s.send(msg.encode())
msg = s.recv(4096)            # Receives data upto 4096 bytes and stores in variables msg

flag = int(msg.split()[1])
if(flag == 200):
    print ("\n", msg.decode()) 
    full_msg = "\nFile Detatils from server : \n"
    while True:
        msg = s.recv(4096)            # Receives data upto 4096 bytes and stores in variables msg
        msg = msg.decode()
        if "done" in msg:
            break
        full_msg += msg
    print (full_msg) 
else:
    print ("\n", msg.decode())   
s.close()                            # Closes the socket 
# End of code
