import socket

reciever = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

reciever.bind(("localhost", 5000))

while True:
    data, addr = reciever.recvfrom(4096)
    print(data.decode(), addr)
