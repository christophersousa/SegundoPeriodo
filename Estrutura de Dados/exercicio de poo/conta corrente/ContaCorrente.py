class ContaCorrente:
    def __init__(self, nome_titular, numero, saldo):
        self.__numero = numero
        self.__saldo = saldo
        self.__nome = nome_titular
    
    #metodos de acesso
    @property
    def numero(self):
        return self.__numero
    
    @property
    def saldo(self):
        return self.__saldo

    @property
    def titular(self):
        return self.__nome

    #metodos de alteração

    @numero.setter
    def numero(self, novo):
        self.__numero = novo
    
    @titular.setter
    def titular(self, novo):
        self.__nome = novo
    

    def depositar(self, deposito):
        self.__saldo += deposito
        return 'Saldo atual: {}'.format(self.__saldo)
       
    
    def sacar(self, saque):
        if self.__saldo >= saque:
           self.__saldo -= saque
           return True
        else:
            return False
    
       






