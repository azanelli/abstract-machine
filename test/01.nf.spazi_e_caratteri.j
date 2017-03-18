.class public Main
.super java/lang/Object


.method public static <clinit> ()V
l31:ldc_w 0
istore 3

l1:
l3:


    return

.end method


.method public static main ([Ljava/lang/String;)V
l31:
ldc_w 0
istore 3

l1:
l3:
getstatic    java/lang/System/out Ljava/io/PrintStream;

ldc_w "Enter : : \"a positive integer to see its Collatz sequence, or zero to exit: "
ldc_w "     ' '' \t >|	|< \"  \n
\""
l32: invokevirtual       java/io/PrintStream/print (Ljava/lang/String;)V

   new    java/io/BufferedReader           
dup  


l4:


istore 1
l10:getstatic java/lang/System/out Ljava/io/PrintStream;

ldc_w ""
getstatic  java/lang/System/out                 Ljava/io/PrintStream;        
ldc_w " "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  goto       l7      
        l8:      
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "    a   :   b
"
l33: ldc_w " numbers in the sequence
"
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
ldc_w        0
return



.end method

.end class
