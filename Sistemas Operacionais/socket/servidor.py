import socket

HOST = ''
PORT = 5000

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

orig = (HOST, PORT)
udp.bind(orig)

print()
print('*'*40)
print('             servidor no ar...')
print('*'*40)

print('\nAguardando cliente...')

while True:
    msg, cliente = udp.recvfrom(1024)
    print('\nCliente conectado\nRecebir a mensagem: {}\nCliente: {}'.format(msg.decode(), cliente))
    print('Resposta...')
    respost = input('\nDigite uma mensagem: ')
    udp.sendto(respost.encode(), cliente)
udp.close()
