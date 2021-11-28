import socket

HOST = '192.168.0.45'

PORT = 12345

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST,PORT))

while True:
    command = str(input('Enter your command: '))
    s.sendall(command .encode())
    reply = s.recv(1024)
    if reply == 'Terminate':
        break
    print(reply.decode())