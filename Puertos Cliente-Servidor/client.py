import socket
import threading
import json
import time
 
def listen(username):
    while True:
        try:
            data, address = s.recvfrom(1024)
            data = data.decode("utf-8")
            data = json.loads(data)
            if data[0] != username:
                print(data[0] + ": " + data[1])
            else:
                if data[1] == "YA NO ESTA CON NOSOTROS":
                    print("Saliendo...")
                    break
        except:
            print("YA NO ESTA CON NOSOTROS")
            break
 
HOST = '127.0.0.1' 
PORT = 8085    
ADDRESS = (HOST,PORT)
 
s = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
#s.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 1)
try:
    print("\nConectando al servidor... escribe salir para desconectarte\n")
    s.connect((HOST, PORT))
except:
    print("FALLO EN LA CONEXION")
 
print("Usuario:")
username = input()

s.sendto(bytes((json.dumps((username, "Conectando"))), "utf-8"), ADDRESS)
s.sendto(bytes(json.dumps((username, " entro")), "utf-8"), ADDRESS,)
print("\n")
listen_thread = threading.Thread(target = listen, args = (username,))
listen_thread.start()

while True:
    print("\n")
    data = input()
    if data == "salir":
        s.sendto(bytes((json.dumps((username, "salir"))), "utf-8"), ADDRESS)
        s.settimeout(1)
        time.sleep(1)
        break
    else:
        print("\n")
        data_to_send =(username, data)
        data_to_send = bytes(json.dumps(data_to_send),"utf-8")
        s.sendto(data_to_send, ADDRESS)