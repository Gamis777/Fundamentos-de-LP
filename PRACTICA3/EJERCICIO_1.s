.data 
    out_string: .asciiz "\nIngrese un primer numero:\n"
	out_string1: .asciiz "\nIngrese un segundo  numero:\n "
	out_string2: .asciiz "\nLa suma es:\n"
	out_string3: .asciiz "\nLa resta es:\n"
	out_string4: .asciiz "\nLa multiplicacion es:\n "
	out_string5: .asciiz "\nLa  division es:\n "
	out_string6: .asciiz "\nEl  promedio es:\n"
.text
main: 	
la $a0, out_string
li $v0, 4 #mostrar texto
syscall

li $v0, 6   #pido por teclado un numero
syscall
mov.s $f1,$f0  # se almacena el registro en f0

la $a0, out_string1   
li $v0, 4
syscall

li $v0, 6
syscall
mov.s $f2,$f0

li $v0, 4
la $a0,out_string2
syscall

#---suma---
li $v0,2  
add.s $f12,$f1,$f2 #suma se almacenaa en el f12
syscall

#resta
li $v0, 4
la $a0,out_string3
syscall

#---resta---
li $v0,2 
sub.s $f12, $f1, $f2
syscall


li $v0, 4  #mostrar texto o cadena
la $a0,out_string4
syscall

#---multiplicacion---
li $v0,2 
mul.s $f12, $f1, $f2
syscall


li $v0, 4  #mostrar textoo cadena
la $a0,out_string5
syscall


#---division---

li $v0, 2  #   para imprimir  flotantes
div.s $f12,$f1,$f2
syscall


li $v0, 4   #mostrar textoo cadena
la $a0,out_string6
syscall


#---promedio---
li $v0, 2 
li.s $f10, 2.0 #  para  sacar  el promedio
add.s $f12,$f1,$f2 
div.s $f12,$f12,$f10

syscall

jr$ra
