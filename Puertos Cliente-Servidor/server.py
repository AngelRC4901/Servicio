import socket
import json
import time
 
HOST = "127.0.0.1"
PORT = 8085
BUFFER_SIZE = 1024
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#s.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 1)
s.bind((HOST, PORT))
addresses = []
print("\n\t\t\t SERVIDOR INICIADO") 
while True:
   
    message, address = s.recvfrom(BUFFER_SIZE)
    message = json.loads(message)
    if message[1] == "Conectando":
        if address not in addresses:
            addresses.append(address)
            print("\n",message[0] + " entro")
    else:
        for addr in addresses:
            s.sendto(bytes((json.dumps(message)), "utf-8"), addr)
            print(message,"\n")
        if message[1] == "salir":
            print(message[0] + " YA NO ESTA CON NOSOTROS")
            s.sendto(bytes((json.dumps((message[0],"YA NO ESTA CON NOSOTROS"))), "utf-8"), addr)
            addresses.remove(address)