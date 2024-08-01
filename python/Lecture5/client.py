import socket

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Define the server address and port
server_address = '127.0.0.1'
server_port = 5000

# Connect to the server
client_socket.connect((server_address, server_port))

# Prompt the user to enter a message to send to the server
message = input("Enter message to send to server: ")
message_encoded = message.encode('UTF-8')

# Send the message to the server
client_socket.send(message_encoded)

# Receive the response from the server
response = client_socket.recv(1024)
print(f"Server responded with: {response.decode('UTF-8')}")

# Close the connection
client_socket.close()
