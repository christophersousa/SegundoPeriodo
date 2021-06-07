import socket

print('')
print('*'*40)
print('         Aplicativo do cliente')
print('*'*40)

host = input('\nDigite o ip do servidor: ')
porta = int(input('Porta do servidor: '))

HOST = host  
PORT = porta 

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
dest = (HOST, PORT)

print('\nConectado com o servidor \nPara sair use CTRL+X\n')
msg = input('Digite uma mensagem: ')

while msg != '\x18':
    udp.sendto(msg.encode(), dest)
    print('Aguando resposta...')
    msg, servidor = udp.recvfrom(1024)
    print('\nRecebir a mensagem: {}\nServidor: {}'.format(msg.decode(), servidor))
    msg = input('Digite uma mensagem: ')
udp.close()
