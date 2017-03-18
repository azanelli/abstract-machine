.class public Main
.super java/lang/Object


.method public static main ([Ljava/lang/String;)V

ldc_w 666
dup
istore 0
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

ldc_w 555
pop
istore 0
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

ldc2_w 666666
dup2
lstore 0
getstatic java/lang/System/out Ljava/io/PrintStream;
lload 0
invokevirtual java/io/PrintStream/print(J)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

ldc2_w 555555
pop2
lstore 0
getstatic java/lang/System/out Ljava/io/PrintStream;
lload 0
invokevirtual java/io/PrintStream/print(J)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

ldc_w 444
ldc_w 333
swap
istore 0
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "666
"
dup
pop
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

return

.end method


.end class
