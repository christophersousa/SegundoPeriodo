#!/usr/bin/env python3
import socket
import sys

HOST = '127.0.0.1' # IP do Servidor
PORT = 40000 # Porta que o Servidor escuta

if len(sys.argv) > 1:
	HOST = sys.argv[1]

print('Servidor:', HOST+':'+str(PORT))
serv = (HOST, PORT)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(serv)

print('Para sair use CTRL+C\n')
while True:
	try:
		msg = input('Mensagem: ')
	except: break
	sock.send(str.encode(msg))
	msg = sock.recv(1024)
	if not msg: break
	msg = msg.decode()
	print('Recebi:', msg)
sock.close()
import socket

HOST = '127.0.0.1'     # Endereco IP do Servidor
PORT = 40000           # Porta que o Servidor esta

serv = (HOST, PORT)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(serv)
msg = 'Oi Mundo Socket!'
sock.send(str.encode(msg))
msg = sock.recv(1024)
if msg:
    msg = msg.decode()
    print('Recebi:', msg)
sock.close()
