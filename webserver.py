from socket import *  #import file

serverSocket = socket(AF_INET, SOCK_STREAM)      # make socket

host="127.1.1.1"                              # Set the server address to variable host
port=4040                                       # Sets the variable port to 4446

serverSocket.bind((host,port))                   # Binds the socket. Note that the input to

while True:
    serverSocket.listen(1)  # Sets socket to listening state with a  queue for 1 host
    print ("Ready to serve ")
    connectionSocket, addr = serverSocket.accept()               # Accepts incoming request from client and returns
    try:
        message = connectionSocket.recv(4096)
        message = message.decode()
        print(message)
        filename = message.split()[1]
        print(filename)
        f = open(filename[1:])
        outputdata = f.read()
        f.close()
        msg = "HTTP/1.1 200 OK\r\n\r\n"
        connectionSocket.send(msg.encode())
        for i in range(0,len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
        
        msg = "File send done"
        connectionSocket.send(msg.encode())
        connectionSocket.close()             #close clint socket
    except IOError:
        msg = "HTTP/1.1 404 FILE_NOT_FOUND\r\n\r\n"
        connectionSocket.send(msg.encode())       #send to clint

        connectionSocket.close()                      #close clint socket

serverSocket.close()


