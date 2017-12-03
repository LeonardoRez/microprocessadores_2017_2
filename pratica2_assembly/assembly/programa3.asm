#Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
#Aluno: Leonardo Rezende Costa
#Professor: Maxwell Diógenes Bandeira de Melo

#Faça um programa que faça uma ordenação crescente e decrescente em um vetor aleatório. 
#A resposta, portanto, será mostrada em dois vetores.

#esse algorítmo seguiu a mesma lógica do bubble sort (implementada na versão em C deste exercício), mas sem chamar em procedimento

.data
vet: .word 3,0,1,5,2,9,7,5
crescente: .word 0,0,0,0,0,0,0,0
decrescente: .word 0,0,0,0,0,0,0,0
bn:  .asciiz "\n"
v: .asciiz ","
msg1: .asciiz "vet[] = "
msg2: .asciiz "crescente[] = "
msg3: .asciiz "decrescente[] = "

# t0 = tamanho dos vetores
# t1 =  flag
# t2 = i
# t3 = controla o endereço atual na lista
# t4 e t5 = variaveis temporárias que recebem v[i] e v[i+1] pra comparar
# t6 = valor que controla o endereço de acesso de 'crescente' e 'decrescente' na hora da copia
#
#
# s0 = endereço base da vet
# s1 = endereço base do vetor crescente
# s2 = endereço base do vetor decrescente
# s7 = variavel temporaria pra copiar os valores de um vetor para o outro
#
.text
main:

#--------------------------REGISTRADORES QUE CONTROLAM OS VETORES--------------------------
la $s0, vet         # armazenar endereço base
la $s1, crescente # armazenar endereço base
la $s2, decrescente # armazenar endereço base
li $t0, 8 #(tamanho do vetor) 
move $t3, $s0 #variavel que vai controlar o endereço de acesso de 'vet'

#--------------------------CÓPIA DO VET NOS DOIS VETORES RESULTADO--------------------------
move $t2, $t0 # i = tam
move $t6, $s1 #variavel que vai controlar o endereço de acesso de 'crescente' e 'decrescente' na hora da cópia
copiavet1:
	beq $t2, $zero, fim_copiavet1 #se i == 0, break
	
	lw $s7, 0($t3)
	sw $s7, 0($t6) # crescente[j] = vet[i]
	add $t3, $t3, 4 # i++
	add $t6, $t6, 4 # j++
	
	sub $t2, $t2, 1 # i--
	j copiavet1
fim_copiavet1:

move $t2, $t0 # i = tam
move $t6, $s2 #variavel que vai controlar o endereço de acesso de 'crescente' e 'decrescente' na hora da cópia
copiavet2:
	beq $t2, $zero, fim_copiavet2 #se i == 0, break
	
	lw $s7, 0($t3)
	sw $s7, 0($t6) # crescente[j] = vet[i]
	add $t3, $t3, 4 # i++
	add $t6, $t6, 4 # j++
	
	sub $t2, $t2, 1 # i--
	j copiavet2
fim_copiavet2:

#--------------ORDENAÇÃO--------------

loop1:
	li $t1, 0 # flag
	move $t2, $t0 # i = tamanho do vetor
	sub $t2, $t2, 1 # i--
	move $t3, $s1 #t3 = &crescente[0]
	loop2:
		beq $t2, $zero, fimloop2 #se i == 0, break
		
		lw $t4, 0($t3) # a = vet[i]
		add $t3, $t3, 4 #deslocando mais 4 endereços de memória
		lw $t5, 0($t3) # b = vet[i+1]
		
		ble $t4, $t5, ipp1 #se a < b, não faz nada
		sw $t4, 0($t3) # v[i+1] = a
		sub $t3, $t3, 4 #deslocando menos 4 endereços de memória
		sw $t5, 0($t3) # v[i] = b
		add $t3, $t3, 4 #deslocando mais 4 endereços de memória
		li $t1, 1 #setando flag pra true
		
		ipp1:
		sub $t2, $t2, 1 # i--
		j loop2
	fimloop2:
	beq $t1, $zero, fimloop1 #flag não foi ativada
	j loop1
fimloop1:

loop3:
	li $t1, 0 # flag
	move $t2, $t0 # i = tamanho do vetor
	sub $t2, $t2, 1 # i--
	move $t3, $s2 #t3 = &decrescente[0]
	loop4:
		beq $t2, $zero, fimloop4 #se i == 0, break
		
		lw $t4, 0($t3) # a = vet[i]
		add $t3, $t3, 4 #deslocando mais 4 endereços de memória
		lw $t5, 0($t3) # b = vet[i+1]
		
		bge $t4, $t5, ipp2 #se a < b, não faz nada
		sw $t4, 0($t3) # v[i+1] = a
		sub $t3, $t3, 4 #deslocando menos 4 endereços de memória
		sw $t5, 0($t3) # v[i] = b
		add $t3, $t3, 4 #deslocando mais 4 endereços de memória
		li $t1, 1 #setando flag pra true
		
		ipp2:
		sub $t2, $t2, 1 # i--
		j loop4
	fimloop4:
	beq $t1, $zero, fimloop3 #flag não foi ativada
	j loop1
fimloop3:

#--------------------------------imprimindo resultado--------------------------------

#imprime descrescente
move $t2, $t0 # i = tam
move $t3, $s0 #variavel que vai controlar o endereço de acesso do vetor original

li $v0, 4 #quebra linha
la $a0, bn #quebra linha
syscall #quebra linha

li $v0, 4 #imprimie terceira msg
la $a0, msg1 #imprimie terceira msg
syscall #imprimie terceira msg

li $v0, 1 #comando para printar int
lw $a0, 0($t3) #prepara pra printar o primeiro numero
syscall #printa v[0]
add $t3, $t3, 4 # i++
sub $t2, $t2, 1 # i--
imprimevet1:
	beq $t2, $zero, fim_imprimevet1 #se i == 0, break
	
	li $v0, 4
	la $a0, v
	syscall
	
	li $v0, 1 #comando para printar int
	lw $a0, 0($t3) #prepara string
	syscall #printa v[i]
	
	add $t3, $t3, 4 # i++
	
	sub $t2, $t2, 1 # i--
	j imprimevet1
fim_imprimevet1:


#imprime descrescente
move $t2, $t0 # i = tam
move $t3, $s1 #variavel que vai controlar o endereço de acesso de crescente

li $v0, 4 #quebra linha
la $a0, bn #quebra linha
syscall #quebra linha

li $v0, 4 #imprimie terceira msg
la $a0, msg2 #imprimie terceira msg
syscall #imprimie terceira msg

li $v0, 1 #comando para printar int
lw $a0, 0($t3) #prepara pra printar o primeiro numero
syscall #printa v[0]
add $t3, $t3, 4 # i++
sub $t2, $t2, 1 # i--
imprimevet2:
	beq $t2, $zero, fim_imprimevet2 #se i == 0, break
	
	li $v0, 4
	la $a0, v
	syscall
	
	li $v0, 1 #comando para printar int
	lw $a0, 0($t3) #prepara string
	syscall #printa v[i]
	
	add $t3, $t3, 4 # i++
	
	sub $t2, $t2, 1 # i--
	j imprimevet2
fim_imprimevet2:

#imprime descrescente
move $t2, $t0 # i = tam
move $t3, $s2 #variavel que vai controlar o endereço de acesso de decrescente

li $v0, 4 #quebra linha
la $a0, bn #quebra linha
syscall #quebra linha

li $v0, 4 #imprimie terceira msg
la $a0, msg3 #imprimie terceira msg
syscall #imprimie terceira msg

li $v0, 1 #comando para printar int
lw $a0, 0($t3) #prepara pra printar o primeiro numero
syscall #printa v[0]
add $t3, $t3, 4 # i++
sub $t2, $t2, 1 # i--
imprimevet3:
	beq $t2, $zero, fim_imprimevet3 #se i == 0, break
	
	li $v0, 4
	la $a0, v
	syscall
	
	li $v0, 1 #comando para printar int
	lw $a0, 0($t3) #prepara string
	syscall #printa v[i]
	
	add $t3, $t3, 4 # i++
	
	sub $t2, $t2, 1 # i--
	j imprimevet3
fim_imprimevet3:


#--------------------------FIM DO ALGORITMO--------------------------
li $v0, 10 #código para encerrar a execução
syscall #chamada para finalizar a execução