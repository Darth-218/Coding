import socket, sys
# listen on a port
# execute a file when receiving a connection
# run a command on connection
# upload a file to a destination when receiving a connection

def listen(addr: tuple[str, int], connections: int = 5, buffer_size: int = 4096, mode: str = "TCP"):
    listener = socket.socket()

    listener.bind(addr)
    listener.listen(connections)

    while True:
        client, _ = listener.accept()
        print(client.recv(buffer_size))
        client.close()


def send(addr: tuple[str, int]):
    client = socket.socket()

    client.connect(addr)

    data = sys.stdin.read()
    client.send(data.encode())
