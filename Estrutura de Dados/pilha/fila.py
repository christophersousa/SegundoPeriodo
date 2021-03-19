class filaexpetion(Exception):
    def __init__(self, mensagem):
        super().__init__(mensagem)


class fila:
    def __init__(self):
        self.__dado = []
    
    def vazia (self):
        return self.__dado == 0
    
    def tamanho (self):
        return len(self.__dado)
    
    def inicio(self):
        if self.vazia():
            raise filaexpetion == 'A fila está vazia'
        return self.__dado[0]
    
    def inserir (self, dado):
        self.__dado.append(dado)
    
    def remover (self):
        if self.vazia():
            raise filaexpetion =='A fila está vazia'

        return self.__dado.pop(0)
    
    def __str__(self):
        return self.__dado.__str__()
    
    def print(self):
        print(self.__str__())

    def modificar(self, novo_dado):

        if self.vazia():
            raise filaexpetion == 'A fila está vazia'

        self.__dado[0] = novo_dado

        return True
