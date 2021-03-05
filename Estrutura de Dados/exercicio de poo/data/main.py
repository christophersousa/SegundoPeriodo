from data import data

dia = int(input('Dia:'))
mes = int(input('Mês:'))
ano = int(input('Ano:'))

Data = data(dia, mes, ano)

print(Data)
print (Data.mês())