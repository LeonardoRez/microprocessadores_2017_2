#Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
#Aluno: Leonardo Rezende Costa
#Professor: Maxwell Diógenes Bandeira de Melo


main:
#ENTRADA DO NUMERO
li $v0, 4 #printar string
la $a0, entrada #definir a msg que será printada
syscall #chamada de sistema para printar

li $v0, 5 #ler int
syscall #chamada de sistema para ler int
move $s5, $v0 #armazenar int lido no registrador $s5

#CHAMADA DE FATORIAL
jal fatorial
li $v0, 4 #printa string
la $a0, resultado #prepara string
syscall #imprime
li $v0, 1 #print int
move $a0, $t4 #prepara int
syscall #imprime resultado

#ENCERRANDO
li $v0, 10 #encerra a execução
syscall #chamada do sistema para finalizar programa



fatorial:
move $s7, $ra #fazendo backup do endereço da main
li $t4, 1 #t = 1
li $t5, 1 #i = 1
loopf:
bgt $t5, $s5, fim_loopf #se i > a, break
move $s0, $t5 #move i para ser usado como parametro
move $s1, $t4 #move t para ser usado como parametro
jal multi #efetua a multiplicação entre $s0 e $s1 e salva o resultado em $s2
move $t4, $s2
add $t5, $t5, 1 #i++
j loopf #volta para o loop
fim_loopf:
move $ra, $s7 #armazena o backup do retorno da main no $ra
jr $ra#volta para a main

multi: #procedimento de multiplicação
#s0 = A, $s1 = B, $s2 = Resultado
li $t0, 0 #inicia o registrador que é o resultado com zero
move $t3,$s0 #salva A em temp para nao sobrescrever 
loopm:
beq $t3, $zero, retorno #se A==0, pula para o retorno
add $t0, $t0, $s1 #adiciona B em t0 (somando "A" vezes)
sub $t3, $t3, 1 #decrementa A
j loopm
retorno:
move $s2, $t0 #armazena o resultado em $s2
jr $ra # volta para onde estava









.data
entrada: .asciiz "Digite o numero: "
resultado: .asciiz "\nResultado: "