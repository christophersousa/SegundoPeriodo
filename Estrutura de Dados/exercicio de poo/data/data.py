class data:
    def __init__(self, dia, mes, ano):
        self.__dia = dia
        self.__mes = mes
        self.__ano = ano

    #modo de acesso
    def get__dia(self):
        return __dia

    def get__mes(self):
        return __mes
    
    def get__ano(self):
        return __ano 
    
    #modo de modificação
    def set__dia(self, novo_dia):
        self.__dia = novo_dia
    
    def set__mes(self, novo_mes):
        self.__mes = novo_mes
    
    def set__ano(self, novo_ano):
        self.__ano = novo_ano

    def mês (self):
        if (self.__mes == 1):
            return'Janeiro'

        elif (self.__mes == 2):
            return ' Fervereiro'

        elif (self.__mes == 3):
            return 'Março'

        elif (self.__mes == 4) :
            return'Abril'

        elif (self.__mes == 5):
            return 'Maio'

        elif (self.__mes == 6):
            return 'Junho'

        elif (self.__mes == 7):
            return 'Julho'

        elif (self.__mes == 8):
            return 'Agosto'

        elif (self.__mes == 9):
            return 'setembro'

        elif (self.__mes == 10):
            return 'Outubro'

        elif (self.__mes == 11):
            return 'Novembro'

        elif (self.__mes == 12):
            return 'Dezembro'
        
    
    def __str__(self):
        return 'Data: {}/{}/{}'.format(self.__dia, self.__mes, self.__ano)