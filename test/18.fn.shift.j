.class public Main
.super java/lang/Object

.method public static main ([Ljava/lang/String;)V

l0:	ldc2_w 32
l3:	lstore 1

l4:ldc2_w 43242232
l7:lstore 3

l8:lload 1
l9:lload 3
l10:l2i
l11:lshl
l12:lstore 5

l14:    getstatic java/lang/System/out Ljava/io/PrintStream;
l17:    lload 5
l19:    invokevirtual java/io/PrintStream/print (J)V

l22:    getstatic java/lang/System/out Ljava/io/PrintStream;
l25:    ldc_w "
"
l27:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l30:    lload 1
l31:    lload 3
l32:    l2i
l33:    lshr
l34:    lstore 5

l36:    getstatic java/lang/System/out Ljava/io/PrintStream;
l39:    lload 5
l41:    invokevirtual java/io/PrintStream/print (J)V

l44:    getstatic java/lang/System/out Ljava/io/PrintStream;
l47:    ldc_w "
"
l49:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l52:    ldc_w 4003020
l54:    istore 7

l56:    sipush 321
l59:    istore 8

l61:    iload 7
l63:    iload 8
l65:    ishr
l66:    istore 9

l68:    getstatic java/lang/System/out Ljava/io/PrintStream;
l71:    iload 9
l73:    invokevirtual java/io/PrintStream/print (I)V

l76:    getstatic java/lang/System/out Ljava/io/PrintStream;
l79:    ldc_w "
"
l81:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l84:    iload 7
l86:    iload 8
l88:    ishl
l89:    istore 9

l91:    getstatic java/lang/System/out Ljava/io/PrintStream;
l94:    iload 9
l96:    invokevirtual java/io/PrintStream/print (I)V

l99:    getstatic java/lang/System/out Ljava/io/PrintStream;
l102:    ldc_w "
"
l104:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l107:    ldc2_w 400323020
l110:    lstore 10

l112:    sipush 932
l115:    istore 12

l117:    lload 10
l119:    iload 12
l121:    lshr
l122:    lstore 13

l124:    getstatic java/lang/System/out Ljava/io/PrintStream;
l127:    lload 13
l129:    invokevirtual java/io/PrintStream/print (J)V

l132:    getstatic java/lang/System/out Ljava/io/PrintStream;
l135:    ldc_w "
"
l137:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l140:    lload 10
l142:    iload 12
l144:    lshl
l145:    lstore 13

l147:    getstatic java/lang/System/out Ljava/io/PrintStream;
l150:    lload 13
l152:    invokevirtual java/io/PrintStream/print (J)V

l155:    getstatic java/lang/System/out Ljava/io/PrintStream;
l158:    ldc_w "
"
l160:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l163:    ldc_w 400323020
l165:    istore 15

l167:    ldc2_w 932
l170:    lstore 16

l172:    iload 15
l174:    lload 16
l176:    l2i
l177:    ishr
l178:    i2l
l179:    lstore 18

l181:    getstatic java/lang/System/out Ljava/io/PrintStream;
l184:    lload 18
l186:    invokevirtual java/io/PrintStream/print (J)V

l189:    getstatic java/lang/System/out Ljava/io/PrintStream;
l192:    ldc_w "
"
l194:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l197:    iload 15
l199:    lload 16
l201:    l2i
l202:    ishl
l203:    i2l
l204:    lstore 18

l206:    getstatic java/lang/System/out Ljava/io/PrintStream;
l209:    lload 18
l211:    invokevirtual java/io/PrintStream/print (J)V

l214:    getstatic java/lang/System/out Ljava/io/PrintStream;
l217:    ldc_w "
"
l219:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l222:    return

.end method

.end class
