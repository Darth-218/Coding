import socket
import threading

host = "127.0.0.1"
port = 5000

server = socket.socket()
server.bind((host, port))

def recvHandle(client_socket: socket.socket) -> None:
    response = client_socket.recv(4096)
    print("[+]", response.decode())
    client_socket.send(b"ack")
    

server.listen()
client, addr = server.accept()
print(f"\nConnected from {addr[0]} at port {addr[1]}\n")

while True:
    # recvHandle(client)
    client_thread = threading.Thread(target=recvHandle, args=(client,))
    client_thread.start()

