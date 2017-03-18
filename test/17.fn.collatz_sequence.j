.class public Main
.super java/lang/Object

.method public static <clinit> ()V
return
.end method

.method public static main ([Ljava/lang/String;)V
ldc_w 0
istore 3
l1:
iload 3
ldc_w 0
if_icmpne l2
ldc_w 0
ldc_w 1
isub
istore 1
l3:
iload 1
ldc_w 0
if_icmpge l4
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "Enter a positive integer to see its Collatz sequence, or zero to exit: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
new java/io/BufferedReader
dup
new java/io/InputStreamReader
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/io/InputStreamReader/<init> (Ljava/io/InputStream;)V
invokespecial java/io/BufferedReader/<init> (Ljava/io/Reader;)V
invokevirtual java/io/BufferedReader/readLine ()Ljava/lang/String;
invokestatic java/lang/Integer/parseInt (Ljava/lang/String;)I
istore 1
goto l3
l4:
iload 1
ldc_w 0
if_icmpne l5
ldc_w 1
istore 3
goto l6
l5:
ldc_w 0
istore 2
l7:
iload 1
ldc_w 1
if_icmpeq l8
iload 2
ldc_w 1
iadd
istore 2
iload 1
ldc_w 2
irem
ldc_w 0
if_icmpne l9
iload 1
ldc_w 2
idiv
istore 1
goto l10
l9:
ldc_w 3
iload 1
imul
ldc_w 1
iadd
istore 1
l10:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w ""
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/print (I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w " "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
goto l7
l8:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 2
invokevirtual java/io/PrintStream/print (I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w " numbers in the sequence
"
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
l6:
goto l1
l2:
ldc_w 0
return
.end method

.end class
