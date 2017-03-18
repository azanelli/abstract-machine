.class public Main
.super java/lang/Object


.method public static main ([Ljava/lang/String;)V

goto L1
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "goto -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L1:getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "goto -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

ldc_w 10
ldc_w 10
if_icmpeq L2
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpeq -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L2: ldc_w 10
ldc_w 9
if_icmpeq L3
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpeq -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L4
L3:getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpeq -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L4: ldc_w 10
ldc_w 10
if_icmpge L5
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpge -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L5:ldc_w 10
ldc_w 11
if_icmpge L6
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpge -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L7
L6:getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpge -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L7: ldc_w 11
ldc_w 10
if_icmpgt L8
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpgt -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L8:ldc_w 10
ldc_w 10
if_icmpgt L9
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpgt -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L10
L9: getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpgt -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L10:ldc_w 10
ldc_w 10
if_icmple L11
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmple -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L11: ldc_w 11
ldc_w 10
if_icmple L12
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmple -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L13
L12:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmple -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L13:
ldc_w 10
ldc_w 11
if_icmplt L14
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmplt -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L14:
ldc_w 10
ldc_w 10
if_icmplt L15
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmplt -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L16
L15:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmplt -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L16:
ldc_w 10
ldc_w 11
if_icmpne L17
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpne -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L17:
ldc_w 10
ldc_w 10
if_icmpne L18
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpne -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L19
L18:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "if_icmpne -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L19:
ldc_w 0
ifeq L20
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifeq -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L20:
ldc_w 10
ifeq L21
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifeq -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L22
L21:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifeq -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L22:
ldc_w 0
ifge L23
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifge -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L23:
ldc_w -1
ifge L24
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifge -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L25
L24:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifge -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L25:
ldc_w 1
ifgt L26
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifgt -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L26:
ldc_w 0
ifgt L27
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifgt -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L28
L27:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifgt -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L28:
ldc_w 0
ifle L29
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifle -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L29:
ldc_w 1
ifle L30
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifle -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L31
L30:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifle -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L31:
ldc_w -2
iflt L32
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "iflt -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L32:
ldc_w 0
iflt L33
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "iflt -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L34
L33:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "iflt -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L34:
ldc_w -2
ifne L35
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifne -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L35:
ldc_w 0
ifne L36
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifne -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L37
L36:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "ifne -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L37:
ldc2_w 100
ldc2_w 100
lcmp
ifeq L38
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "lcmp -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L38:
ldc2_w 102
ldc2_w 101
lcmp
ifgt L39
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "lcmp -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L39:
ldc2_w 101
ldc2_w 102
lcmp
iflt L40
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "lcmp -> err
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L41

L40:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "lcmp -> ok
"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

L41:
return

.end method

.end class
