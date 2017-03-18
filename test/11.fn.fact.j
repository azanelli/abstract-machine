.class public Main
.super java/lang/Object

.method public static <clinit> ()V
  return
.end method

.method public static fact (I)I
  iload 0
  ldc_w 1
  if_icmpgt l1
  ldc_w 1
  istore 1
  goto l2
  l1:
  iload 0
  ldc_w 1
  isub
  invokestatic Main/fact (I)I
  istore 2
  iload 0
  iload 2
  imul
  istore 1
  l2:
  iload 1
  ireturn
.end method

.method public static main ([Ljava/lang/String;)V
  ldc_w 5
  istore 1
  iload 1
  invokestatic Main/fact (I)I
  istore 2
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "fact("
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 1
  invokevirtual java/io/PrintStream/print (I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ") = "
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 2
  invokevirtual java/io/PrintStream/print (I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  return
.end method

.end class
