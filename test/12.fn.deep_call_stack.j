.class public Main
.super java/lang/Object

.method public static <clinit> ()V
  return
.end method

.method public static h (I)I
  iload 0
  ireturn
.end method

.method public static g (I)I
  iload 0
  ldc_w 1
  isub
  invokestatic Main/h (I)I
  istore 1
  iload 1
  ireturn
.end method

.method public static f (I)I
  iload 0
  ldc_w 1
  isub
  invokestatic Main/g (I)I
  istore 1
  iload 1
  ireturn
.end method

.method public static main ([Ljava/lang/String;)V
  ldc_w 8
  istore 1
  iload 1
  invokestatic Main/f (I)I
  istore 2
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ""
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 1
  invokevirtual java/io/PrintStream/print (I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w " - 2 = "
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 2
  invokevirtual java/io/PrintStream/print (I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ".
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  ldc_w 5
  istore 1
  iload 1
  invokestatic Main/f (I)I
  istore 2
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ""
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 1
  invokevirtual java/io/PrintStream/print (I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w " - 2 = "
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 2
  invokevirtual java/io/PrintStream/print (I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ".
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  ldc_w 6
  istore 1
  iload 1
  invokestatic Main/f (I)I
  istore 2
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ""
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 1
  invokevirtual java/io/PrintStream/print (I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w " - 2 = "
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 2
  invokevirtual java/io/PrintStream/print (I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ".
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
  ldc_w 0
  return
.end method

.end class