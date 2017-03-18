.class public Main
.super java/lang/Object


.method public static main ([Ljava/lang/String;)V

l0:    ldc_w 100
l2:    istore 1

l3:    ldc_w 7
l5:    istore 2

l6:    getstatic java/lang/System/out Ljava/io/PrintStream;
l9:    iload 1
l10:    ineg
l11:    invokevirtual java/io/PrintStream/print (I)V

l14:    getstatic java/lang/System/out Ljava/io/PrintStream;
l17:    ldc_w "
"
l19:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l22:    getstatic java/lang/System/out Ljava/io/PrintStream;
l25:    iload 1
l26:    iload 2
l27:    iadd
l28:    invokevirtual java/io/PrintStream/print (I)V

l31:    getstatic java/lang/System/out Ljava/io/PrintStream;
l34:    ldc_w "
"
l36:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l39:    getstatic java/lang/System/out Ljava/io/PrintStream;
l42:    iload 1
l43:    iload 2
l44:    isub
l45:    invokevirtual java/io/PrintStream/print (I)V

l48:    getstatic java/lang/System/out Ljava/io/PrintStream;
l51:    ldc_w "
"
l53:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l56:    getstatic java/lang/System/out Ljava/io/PrintStream;
l59:    iload 1
l60:    iload 2
l61:    imul
l62:    invokevirtual java/io/PrintStream/print (I)V

l65:    getstatic java/lang/System/out Ljava/io/PrintStream;
l68:    ldc_w "
"
l70:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l73:    getstatic java/lang/System/out Ljava/io/PrintStream;
l76:    iload 1
l77:    iload 2
l78:    idiv
l79:    invokevirtual java/io/PrintStream/print (I)V

l82:    getstatic java/lang/System/out Ljava/io/PrintStream;
l85:    ldc_w "
"
l87:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l90:    getstatic java/lang/System/out Ljava/io/PrintStream;
l93:    iload 1
l94:    iload 2
l95:    irem
l96:    invokevirtual java/io/PrintStream/print (I)V

l99:    getstatic java/lang/System/out Ljava/io/PrintStream;
l102:    ldc_w "
"
l104:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l107:    ldc2_w 100000
l110:    lstore 3

l111:    ldc2_w 7000
l114:    lstore 5

l116:    getstatic java/lang/System/out Ljava/io/PrintStream;
l119:    lload 3
l120:    lneg
l121:    invokevirtual java/io/PrintStream/print (J)V

l124:    getstatic java/lang/System/out Ljava/io/PrintStream;
l127:    ldc_w "
"
l129:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l132:    getstatic java/lang/System/out Ljava/io/PrintStream;
l135:    lload 3
l136:    lload 5
l138:    ladd
l139:    invokevirtual java/io/PrintStream/print (J)V

l142:    getstatic java/lang/System/out Ljava/io/PrintStream;
l145:    ldc_w "
"
l147:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l150:    getstatic java/lang/System/out Ljava/io/PrintStream;
l153:    lload 3
l154:    lload 5
l156:    lsub
l157:    invokevirtual java/io/PrintStream/print (J)V

l160:    getstatic java/lang/System/out Ljava/io/PrintStream;
l163:    ldc_w "
"
l165:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l168:    getstatic java/lang/System/out Ljava/io/PrintStream;
l171:    lload 3
l172:    lload 5
l174:    lmul
l175:    invokevirtual java/io/PrintStream/print (J)V

l178:    getstatic java/lang/System/out Ljava/io/PrintStream;
l181:    ldc_w "
"
l183:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l186:    getstatic java/lang/System/out Ljava/io/PrintStream;
l189:    lload 3
l190:    lload 5
l192:    ldiv
l193:    invokevirtual java/io/PrintStream/print (J)V

l196:    getstatic java/lang/System/out Ljava/io/PrintStream;
l199:    ldc_w "
"
l201:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l204:    getstatic java/lang/System/out Ljava/io/PrintStream;
l207:    lload 3
l208:    lload 5
l210:    lrem
l211:    invokevirtual java/io/PrintStream/print (J)V

l214:    getstatic java/lang/System/out Ljava/io/PrintStream;
l217:    ldc_w "
"
l219:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l222:    ldc_w 2000000000
l224:    istore 7

l226:    ldc_w 4
l227:    istore 8

l229:    getstatic java/lang/System/out Ljava/io/PrintStream;
l232:    iload 7
l234:    iload 8
l236:    imul
l237:    invokevirtual java/io/PrintStream/print (I)V

l240:    getstatic java/lang/System/out Ljava/io/PrintStream;
l243:    ldc_w "
"
l245:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l248:    ldc2_w 2000000000
l251:    lstore 9

l253:    ldc2_w 4
l256:    lstore 11

l258:    getstatic java/lang/System/out Ljava/io/PrintStream;
l261:    lload 9
l263:    lload 11
l265:    lmul
l266:    invokevirtual java/io/PrintStream/print (J)V

l269:    getstatic java/lang/System/out Ljava/io/PrintStream;
l272:    ldc_w "
"
l274:    invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

l277:    return

.end method

