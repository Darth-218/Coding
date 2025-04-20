import socket

# AF_INET indicates that we're using standart IPv4 or hostname.
# SOCK_STREAM indicates that his is a TCP client.
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect(("localhost", 5000))

while True:
    data = input()
    if data == "-": break
    client.send(data.encode())
    response = client.recv(4096)
    print("[+]", response.decode())

