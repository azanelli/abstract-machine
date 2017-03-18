.class public Main
.super java/lang/Object

.method public static main ([Ljava/lang/String;)V

l0:    ldc2_w 1
l1:    lstore 1

l2:    ldc_w 0
l3:    istore 3

l4:    ldc_w 0
l5:    istore 4
l7:    iload 4
l9:    ldc_w 1000000
l11:    if_icmpge l31

l14:    iload 3
l15:    iload 4
l17:    iadd
l18:    istore 3

l19:    lload 1
l20:    iload 4
l22:    i2l
l23:    lmul
l24:    lstore 1

l251:    ldc_w 1
l252:    iload 4
l253:    iadd
l254:    istore 4

getstatic java/lang/System/out Ljava/io/PrintStream;
iload 4
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

l28:    goto l7

l31:    return

.end method

.end class
