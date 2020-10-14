import socket   #for sockets
import sys  #for exit
 
#create an AF_INET, STREAM socket (TCP)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

 
print ('Socket Created\n')
 
dest_host = 'www.gmail.com'
dest_port = 80
 
try:
    dest_ip = socket.gethostbyname( dest_host )  #use dns to get ip
 
except socket.gaierror:
    #could not resolve
    print ('Hostname could not be resolved. Exiting\n')
    sys.exit()
     
print ('Ip address of ' + dest_host + ' is ' + dest_ip+'\n')
 
#Connect to remote server
s.connect((dest_ip , dest_port))   #Socket to socket connection




 
print ('Socket Connected to ' + dest_host + ' on ip ' + dest_ip+'\n')


#Send some data to remote server
message = "GET / HTTP/1.1\r\n\r\n"  #req msg
 
try :
    #Set the whole string
    s.sendall(message.encode())  #send to socket
except socket.error:
    #Send failed
    print ('Send failed')
    sys.exit()
 
print ('Message sent successfully')

#==========New Code================================ 

#Now receive data
reply = s.recv(4096)  #buffer of receiver
 
print (reply.decode())

#close the socket
s.close()
