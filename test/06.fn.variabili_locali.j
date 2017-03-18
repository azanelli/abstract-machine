.class public Main
.super java/lang/Object


.method public static main ([Ljava/lang/String;)V
  ldc_w 2000000000
  istore 0

  ldc2_w 2000000000
  lstore 1

  sipush 2000000000
  istore 3

  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 0
  invokevirtual java/io/PrintStream/print (I)V

  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

  getstatic java/lang/System/out Ljava/io/PrintStream;
  lload 1
  invokevirtual java/io/PrintStream/print (J)V

  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 3
  invokevirtual java/io/PrintStream/print (I)V

  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V


  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 3
  iload 0
  lload 1
  lstore 0
  istore 1
  istore 0
  iload 0
  invokevirtual java/io/PrintStream/print (I)V

  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V


  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc2_w 1000
  ldc2_w 1001
  ldc2_w 1002
  lstore 0
  lstore 2
  lstore 4
  lload 0
  lstore 1
  lload 4
  lstore 3
  lload 1
  lstore 2
  lload 2
  invokevirtual java/io/PrintStream/print (J)V

  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w 10
  ldc_w 11
  ldc_w 12
  istore 0
  istore 2
  istore 4
  iload 0
  istore 1
  iload 4
  istore 3
  iload 1
  istore 2
  iload 4
  invokevirtual java/io/PrintStream/print (I)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V


  return
.end method


.end class
