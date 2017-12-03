#Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
#Aluno: Leonardo Rezende Costa
#Professor: Maxwell Diógenes Bandeira de Melo

.text
main:
li $v0, 4 #comando de printar string
la $a0, ler_a #printar msg para entrar primeiro numero
syscall #chamada de sistema para printar

li $v0, 5 #ler inteiro
syscall #chamada de sistema para ler
move $s3, $v0 #armazena o numero A em $s3



li $t2, 1 #variavel (i) de teste para raiz (de 0 até A)
loop: #laço para testar as raizes
move $t1, $t2 #copia o valor da variavel para ser usada no procedimento multi
bgt $t1, $s3, loop_fim #condicional para o loop
jal multi
beq $s2, $s3 loop_fim #testa se encontrou a raiz
add $t2,$t2,1 #incrementa i
j loop
loop_fim:
bgt $t2, $s3, resultado_falso #testa se o "i" é maior que "A". Se é, o número não tem raiz
li $v0, 4 #comando de printar string
la $a0, raiz #printar msg de resultado
syscall #chamada de sistema para printar
li $v0, 1 #print int
move $a0, $t2	#move o resultado para ser printado
syscall
j fim

resultado_falso: #pula pra cá se o número não tiver raiz
li $v0, 4 #comando de printar string
la $a0, nao_tem_raiz #printar msg de resultado
syscall #chamada de sistema para printar


fim:
li $v0, 10 #encerrar programa
syscall #chamada para encerrar programa





multi: #procedimento de multiplicação
li $t0, 0 #inicia o registrador que é o resultado com zero
loop_m:
beq $t1, $zero, retorno #se i==0, pula para o retorno
add $t0, $t0, $t2 #adiciona i em t0 (somando "i" vezes)
sub $t1, $t1, 1 #decrementa i
j loop_m
retorno:
move $s2, $t0 #armazena o resultado em $s2
jr $ra # volta para onde estava

.data
ler_a: .asciiz "Digite o numero: "
raiz: .asciiz "\nRaiz: "
nao_tem_raiz: .asciiz "\nNao tem raiz."