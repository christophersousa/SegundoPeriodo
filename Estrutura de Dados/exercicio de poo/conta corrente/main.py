from ContaCorrente import ContaCorrente
from procurar_conta import procurar_conta


contas = []
print('Para sair do laço difite "sair"')
while True:
    nome = input('\nDigite seu nome : ').title()

    if nome == 'Sair':
        break

    number = int(input('Digite seu número da conta com 4 digitos: '))

    if number < 1000:
        print('\nFalha!\nNúmero invalido ou Insuficiente')
        continue
    

    saldo = int(input('Seu Saldo: '))

    conta = ContaCorrente(nome, number, saldo)
    contas.append(conta)


while True:
    n = int(input('Digite o número do titular da conta: '))
    ind = procurar_conta(n,contas)

    print(f'\nOlá, senhor {contas[ind].titular}')
    print('Titular: {}\nSaldo: {}'.format(contas[ind].titular, contas[ind].saldo))
    
    while True:
        menu = '\nOpição 1 = Sacar \nOpição 2 = Depositar \nOpição 3 = Saldo Atual\nOpição 4 = Fnalizar Operação \nDigite sua opção: '
        acao = int(input(menu))

        if acao == 1:
            valor = int(input('\nValor: '))
            print(contas[ind].sacar(valor))
            print('Saldo atualizado: {}'.format(contas[ind].saldo))
        
        elif acao == 2:
            valor = int(input('\nValor: '))
            print(contas[ind].depositar(valor))
            print('Saldo atualizado: {}'.format(contas[ind].saldo))
        
        elif acao == 3:
            print('\nSaldo atual: {}'.format(contas[ind].saldo))
        
        elif acao == 4:
            break
    cont = input('\nDeseja continuar a operação? ').upper()
    
    if cont != 'SIM' and cont != 'S':
        break



    
