#server
# TCP Server Code
from socket import *                # Imports socket module

#host="127.0.0.1"                # Set the server address to variable host

host="127.168.2.75"                # Set the server address to variable host
port=4446                   # Sets the variable port to 4444

s = socket(AF_INET, SOCK_STREAM)   #make socket
s.bind((host,port))                 # Binds the socket. Note that the input to 


 #for clint                                           # the bind function is a tuple
s.listen(1)                         # Sets socket to listening state with a  queue
                                            # of 1 connection
print ("Listening for connections.. ")

q,addr=s.accept()               # Accepts incoming request from client and returns
                                            # socket and address to variables q and addr											
print("Connected with "+addr[0]+ ':' + str(addr[1]))

data=input("Enter data to be send:  ")  # Data to be sent is stored in variable data from
                                            # user
q.send(data.encode())                        # Sends data to client
s.close()
# End of code
