import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(("localhost", 5000))

# Number of clients in a "queue"
server.listen(5)

client, addr = server.accept()

while True:
    response = client.recv(4096)
    client.send(b"recieved")
    print("[=]", response.decode())
