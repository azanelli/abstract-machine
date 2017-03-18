.class public Main
.super java/lang/Object


.method public static foo1 ()C
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo1
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  ldc_w 75
  ireturn
.end method


.method public static foo2 (C)S
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo2: "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 0
  invokevirtual java/io/PrintStream/print(C)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  iload 0
  ireturn
.end method


.method public static foo3 (CSJI)I
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo3: "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 0
  invokevirtual java/io/PrintStream/print(I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 1
  invokevirtual java/io/PrintStream/print(I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  lload 2
  invokevirtual java/io/PrintStream/print(J)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  iload 4
  ireturn
.end method


.method public static foo4 (JI)J
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo4: "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 2
  invokevirtual java/io/PrintStream/print(I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  lload 0
  lreturn
.end method


.method public static foo5 (JJ)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo5: "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  lload 0
  invokevirtual java/io/PrintStream/print(J)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ", "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  lload 2
  invokevirtual java/io/PrintStream/print(J)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  return
.end method


.method public static main ([Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  sipush 1
  invokestatic Main/foo1 ()C
  invokestatic Main/foo2 (C)S
  istore 300
  ldc_w 84
  iload 300
  ldc2_w 1000
  ldc_w 100
  invokestatic Main/foo3 (CSJI)I
  istore 5000
  ldc2_w 2000
  iload 5000
  invokestatic Main/foo4 (JI)J
  ldc2_w 3000
  invokestatic Main/foo5 (JJ)V
  invokevirtual java/io/PrintStream/print(I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  return
.end method


.end class
