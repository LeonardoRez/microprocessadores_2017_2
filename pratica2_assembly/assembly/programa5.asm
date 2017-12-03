#Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
#Aluno: Leonardo Rezende Costa
#Professor: Maxwell Diógenes Bandeira de Melo

#PROGRAMA QUE CONFERE SE NUMERO É PERFEITO
.text
main: 
#printar msg
li $v0, 4 #print string
la $a0, entrada#preparar msg
syscall 

#ler numero
li $v0, 5 #ler int
syscall
move $s0, $v0 # scanf("%d",&a)

li $t0, 1 #int i = 1
li $t1, 1 #int r = 1

loopmain:
add $t0, $t0, 1 #i++
bge $t0, $s0, fimloopmain #if i >= a, break
jal resto_div
bne $s7, $zero, loopmain # if (resto_div(a,i) != 0), volta pro começo do loop
add $t1, $t1, $t0 # r += i
j loopmain
fimloopmain:
bne $t1, $s0, print_falso
li $v0, 4 #print string
la $a0, verd #prepara msg
syscall #printa a msg
j fim #pula para o fim

print_falso:
li $v0, 4 #print string
la $a0, falso #prepara msg
syscall #printa a msg

fim:
li $v0, 10 #encerra o programa
syscall


resto_div:
move $t4, $s0 #fazendo copia de a para não alterar valor na main
move $t5, $t0 #fazendo copia de i para não alterar valor na main
loopr:
ble $t4, $zero, fimloopr #if a <= 0, break
sub $t4, $t4, $t5 # a -= i
j loopr
fimloopr:
bne $t4, $zero, return2 #retorna resto
move $s7, $t4 #retorna resto
jr $ra #encerra o procedimento

return2:
add $s7, $t4, $t5 #retorna o resto, que é o número negativo + i
jr $ra #encerra o procedimento


.data
entrada: .asciiz "Digite o numero: "
verd: .asciiz "\nO numero é perfeito"
falso: .asciiz "\nO numero não é perfeito"