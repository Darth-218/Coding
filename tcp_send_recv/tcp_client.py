import socket
import threading

host = "127.0.0.1"
port = 5000

client = socket.socket()
client.connect((host, port))

print(f"Connected to {host} at port {port}\n")

while True:
    print("[-]", end=" ")
    data = input()
    client.send(data.encode())
    response = client.recv(4096)
    print("[+]", response.decode())
