#!/usr/bin/env python3
import socket

HOST = '127.0.0.1'     # Endereco IP do Servidor
PORT = 40000           # Porta que o Servidor escuta

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv = (HOST, PORT)
sock.bind(serv)
sock.listen(50)
con, cliente = sock.accept()
print('Conectado com', cliente)
while True:
    msg = con.recv(1024)
    if not msg: break
    print(cliente, 'mensagem:', msg.decode())
    con.send(msg)
print('Desconectando do cliente', cliente)
con.close()
sock.close()
