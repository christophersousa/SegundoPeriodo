#!/bin/bash

echo '\n\nFeito por:' $1
echo -n $1 | md5sum
arqCmd=.comandos.txt

history>$arqCmd

function validaHistory() {
	if grep -q "$1" $2; then
    	echo $3 - Ok
	else
    	echo $3 - '?'
	fi
}

function procuraArquivo() {
	if [ $(find ./ -name $1 | wc -l) -gt 0 ]
	then
		echo $2 - Ok
	else
		echo $2 - '?'
	fi
}

# colocar as validações a partir daqui

echo -e '\n=== Validando os passos da atividade ==='

echo -e "arquivo inst1.txt"
validaHistory "ls" $arqCmd "1"
validaHistory "du" $arqCmd "2"
validaHistory "du -h" $arqCmd "3"
validaHistory "df" $arqCmd "4"
validaHistory "fdisk -l" $arqCmd "5"
validaHistory "cd a" $arqCmd "6"

echo -e "\narquivo inst2.txt"
validaHistory "whereis ls" $arqCmd "7"
validaHistory "pwd" $arqCmd "8"
validaHistory "cd /" $arqCmd "9"
validaHistory "ls" $arqCmd "10"
validaHistory "cd" $arqCmd "11"
validaHistory "file inst2.txt" $arqCmd "12"

echo -e "\narquivo inst3.txt"
validaHistory "file arq.txt" $arqCmd "13"
validaHistory "nano arq.txt" $arqCmd "14"
validaHistory "cd s" $arqCmd "15"
validaHistory "find . -name arq2.txt" $arqCmd "16"
validaHistory "find . -name arq*" $arqCmd "17"
validaHistory "cat arq2.txt | grep LA" $arqCmd "18"
validaHistory "grep" $arqCmd "19"
procuraArquivo "alunos.txt" "20"
validaHistory "grep ANA *.*" $arqCmd "21"
validaHistory "grep -r ANA *.*" $arqCmd "22"
validaHistory "grep -r ANA *.txt" $arqCmd "23"
validaHistory "cd p" $arqCmd "24"

echo -e "\narquivo inst4.txt"
validaHistory "head noticia.txt" $arqCmd "25"
validaHistory "head -n3 noticia.txt" $arqCmd "26"
validaHistory "tail noticia.txt" $arqCmd "27"
validaHistory "tail -n5 noticia.txt" $arqCmd "28"
