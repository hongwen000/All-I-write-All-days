import socket
import time

address = ('127.0.0.1', 31500)
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    sleep(0.001)
    s.sendto("msg", address)
s.close()


