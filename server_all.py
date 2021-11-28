import socket
import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 115200)

HOST = '192.168.0.45' 
# Server IP or Hostname
PORT = 12345
# Pick an open Port (1000+ recommended), must match the client sport
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('Socket created')

#managing error exception
try:
   s.bind((HOST, PORT))
except socket.error:
   print('Bind failed ')

s.listen(5)
print('Socket awaiting messages')
(conn, addr) = s.accept()
print('Connected')

# awaiting for message
while True:
#   d = conn.recv(1024)
#   data = d.decode()
#   print('I sent a message back in response to: ' + data)
#   reply = ''
#   reply = data
#   conn.send(reply.encode())
    d = conn.recv(1024)
    print("power",d.decode())
    conn.send(d)
    
#    d = d.encode()
    ser.write(d)
    time.sleep(0.5)

conn.close() 
# Close connections

