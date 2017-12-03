#Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
#Aluno: Leonardo Rezende Costa
#Professor: Maxwell Diógenes Bandeira de Melo


.text
main:
li $v0, 4 #comando de printar string
la $a0, ler_a #printar msg para entrar primeiiro numero
syscall #chamada de sistema

li $v0, 5 #ler inteiro
syscall #chamada de sistema
move $s0, $v0 #armazena o numero A

li $v0, 4 #ler string
la $a0, ler_b #printar msg para entrar o segundo numero
syscall #chamada de sistema

li $v0, 5 #ler inteiro
syscall #chamada de sistema
move $s1, $v0 #armazena o número B

jal multi #chama o procedimento que armazenará o resultado em $s2

#print resultado
li $v0, 4 #print string
la $a0, resultado #imprime a mensagem de resultado
syscall
li $v0, 1 #print int
move $a0, $s2	#move o resultado para ser printado
syscall

#encerra o programa
li $v0, 10
syscall


multi: #procedimento de multiplicação
li $t0, 0 #inicia o registrador que é o resultado com zero
loop:
beq $s0, $zero, retorno #se A==0, pula para o retorno
add $t0, $t0, $s1 #adiciona B em t0 (somando "A" vezes)
sub $s0, $s0, 1 #decrementa A
j loop
retorno:
move $s2, $t0 #armazena o resultado em $s2
jr $ra # volta para onde estava



.data
ler_a: .asciiz "Digite o primeiro numero: "
ler_b: .asciiz "\nDigite o segundo numero: "
resultado: .asciiz "\nResultado da multiplicação: "