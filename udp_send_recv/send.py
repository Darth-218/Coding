import socket, time

target_host = "localhost"
target_port = 5000

sender = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

for a in ["a", "b", "c"]:
    sender.sendto(a.encode(), (target_host, target_port))
    time.sleep(1)
