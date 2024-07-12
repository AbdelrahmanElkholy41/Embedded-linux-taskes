import socket

# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Set the SO_REUSEADDR option to allow reuse of the address
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# Bind the socket to an IP address and port
s.bind(("127.0.0.1", 5000))  # Pass the IP address and port as a tuple

# Listen for incoming connections
s.listen(5)
print("Server listening on 192.168.1.9:5000")

while True:
    # Accept a connection from a client
    client, address = s.accept()
    print(f"Connection from {address} has been established.")

    # Receive data from the client
    r = client.recv(1024)
    print(f"{address} sent this message: {r.decode('UTF-8')}")

    # Prompt the user to enter a message to send to the client
    m = input("Enter message: ")
    me = m.encode('UTF-8')
    
    # Send the message to the client
    client.send(me)

    # Close the connection with the client
    client.close()
