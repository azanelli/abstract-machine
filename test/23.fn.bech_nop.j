.class public Main
.super java/lang/Object


.method public static main ([Ljava/lang/String;)V

l0:    ldc_w 0
l1:    istore 1
l2:    iload 1
l3:    ldc_w 100000000
l5:    if_icmpge l17

l8:    nop

l111:    ldc_w 1
l112:    iload 1
l113:    iadd
l114:    istore 1

l14:    goto l2

l17:    return

.end method

.end class
