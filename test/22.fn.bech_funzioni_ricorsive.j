.class public Main
.super java/lang/Object

.field public static a J

.method public static ric (I)J

l0:    iload 0
l1:    ifne l6

l4:    ldc2_w 1
l5:    lreturn

l6:    iload 0
l7:    ldc_w 1
l8:    if_icmpne l15

l11:    getstatic Main/a J
l14:    lreturn

l15:    ldc2_w 2
l18:    iload 0
l19:    ldc_w 1
l20:    isub
l21:    invokestatic Main/ric (I)J
l24:    ladd
l25:    lreturn

.end method

.method public static main ([Ljava/lang/String;)V

l0:    getstatic java/lang/System/out Ljava/io/PrintStream;
l3:    ldc_w 10000
l5:    invokestatic Main/ric (I)J
l8:    invokevirtual java/io/PrintStream/print (J)V

l11:    getstatic java/lang/System/out Ljava/io/PrintStream;
l14:    ldc_w "
"
l16:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l19:    return

.end method

.method public static <clinit> ()V

l0:    ldc2_w 1
l3:    putstatic Main/a J
l6:    return

.end method

.end class
