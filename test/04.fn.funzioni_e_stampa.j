.class public Main
.super java/lang/Object


.method public static foo1 ()C
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo1, "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  ldc_w 75
  ireturn
.end method


.method public static foo2 (C)S
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo2, "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  ldc_w 2
  ireturn
.end method


.method public static foo3 (S)I
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo3, "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  ldc_w 3
  ireturn
.end method


.method public static main ([Ljava/lang/String;)V
  ldc2_w 1000
  invokestatic Main/foo1 ()C
  invokestatic Main/foo2 (C)S
  invokestatic Main/foo3 (S)I
  invokestatic Main/foo4 (I)J
  invokestatic Main/foo5 (JJ)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  invokestatic Main/foo1 ()C
  invokevirtual java/io/PrintStream/print(C)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w 19
  invokestatic Main/foo2 (C)S
  invokevirtual java/io/PrintStream/print(I)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  invokestatic Main/foo1 ()C
  invokestatic Main/foo2 (C)S
  invokestatic Main/foo3 (S)I
  invokestatic Main/foo4 (I)J
  invokevirtual java/io/PrintStream/print(J)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "Hello, world!!!
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  
  return
.end method


.method public static foo4 (I)J
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo4, "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  ldc2_w 4
  lreturn
.end method


.method public static foo5 (JJ)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "foo5
  "
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  return
.end method


.end class
