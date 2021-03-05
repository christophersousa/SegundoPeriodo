def procurar_conta(numero, contas):
    for i in range(len(contas)):
        if numero == contas[i].numero:
            return i