.class public Main
.super java/lang/Object


.field public static   S  S 
.field public static C  C 
.field public static I I 
.field public static    J J

.field public static Global_Variable_Char C  
.field public static Global_Variable_Short S


.method public static main ([Ljava/lang/String;)V

l0:    getstatic java/lang/System/out Ljava/io/PrintStream;
l3:    getstatic   Main/J  J
l6:    invokevirtual java/io/PrintStream/print (J)V

l9:    getstatic java/lang/System/out Ljava/io/PrintStream;
l12:    ldc_w "
"
l14:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l17:    getstatic java/lang/System/out Ljava/io/PrintStream;
l20:    getstatic Main/I I
l23:    invokevirtual java/io/PrintStream/print (I)V

l26:    getstatic java/lang/System/out Ljava/io/PrintStream;
l29:    ldc_w "
"
l31:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l34:    getstatic java/lang/System/out Ljava/io/PrintStream;
l37:    getstatic Main/C C
l40:    invokevirtual java/io/PrintStream/print (C)V

l43:    getstatic java/lang/System/out Ljava/io/PrintStream;
l46:    ldc_w "
"
l48:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l51:    getstatic java/lang/System/out Ljava/io/PrintStream;
l54:    getstatic Main/S S
l57:    invokevirtual java/io/PrintStream/print (I)V

l60:    getstatic java/lang/System/out Ljava/io/PrintStream;
l63:    ldc_w "
"
l65:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

        getstatic java/lang/System/out Ljava/io/PrintStream;
        ldc_w 32770
        putstatic Main/Global_Variable_Short S
        getstatic Main/Global_Variable_Short S
        invokevirtual java/io/PrintStream/print (I)V
        getstatic java/lang/System/out Ljava/io/PrintStream;
        ldc_w "
"
        invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

        getstatic java/lang/System/out Ljava/io/PrintStream;
        ldc_w 65540
        putstatic Main/Global_Variable_Char C
        getstatic Main/Global_Variable_Char C
        invokevirtual java/io/PrintStream/print (I)V
        getstatic java/lang/System/out Ljava/io/PrintStream;
        ldc_w "
"
        invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l68:    return

.end method


.method public static <clinit> ()V

l0:    sipush 10
l2:    putstatic  Main/S   S  

l5:    ldc_w 97
l7:    putstatic Main/C C 

l10:    getstatic Main/S S
l13:    getstatic Main/C  C 
l16:    imul
l17:    putstatic Main/I I

l20:    getstatic Main/I I
l23:    getstatic Main/I I
l26:    imul
l27:    i2l
l28:    putstatic Main/J J
l31:    return

.end method


.end class
