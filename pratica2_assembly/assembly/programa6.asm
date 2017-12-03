#Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
#Aluno: Leonardo Rezende Costa
#Professor: Maxwell Diógenes Bandeira de Melo

#Faça um programa que indique se um número é primo. O número deverá ser digitado pelo usuário.
.text
main:
li $v0, 4 #printa string
la $a0, entrada #prepara msg
syscall

li $v0, 5 # le inteiro
syscall #scanf()
move $s0, $v0 # a = numero lido

jal verifica_primo

beq $s7, $zero, naoprimo 
li $v0, 4 #print string
la $a0, verd #printa "o numero é primo"
syscall
j fim

naoprimo:
li $v0, 4 #printa string
la $a0, falso #printa "o numero não é primo"
syscall

fim:
li $v0, 10 #encerra programa
syscall



verifica_primo:
move $t8, $ra #backup do ponto de retorno do procedimento
move $t1, $s0 #faz copia de A
blt $t1, 2, returnf #se a < 2, retorna falso
li $t2, 2 #i = 2
loop_p:
bge $t2, $t1, fimloop_p #if i >= a, break
jal resto_div #verifica se a % i == 0
beq $s6, $zero, returnf #se for, retorna falso
add $t2, $t2, 1 #se nao for, continua testando
j loop_p
fimloop_p:
li $s7, 1 #return true
jr $t8 #encerra o procedimento

returnf:
move $s7, $zero #return false
jr $t8 #encerra o procedimento


resto_div:
move $t4, $t1 #fazendo copia de a para não alterar valor na main
move $t5, $t2 #fazendo copia de i para não alterar valor na main
loopr:
ble $t4, $zero, fimloopr # if a <= i, break
sub $t4, $t4, $t5 # a -= i
j loopr
fimloopr:
bne $t4, $zero, return2
move $s6, $t4 #armazena o resto (que é zero)
jr $ra #encerra o procedimento

return2:
add $s6, $t4, $t5 #faz a correção do resto e armazena
jr $ra #encerra o procedimento

.data
entrada: .asciiz "Digite o numero: "
verd: .asciiz "O numero é primo"
falso: .asciiz "O numero NÃO é primo"
