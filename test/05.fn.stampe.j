.class public Main
.super java/lang/Object

.method public static main ([Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w " stringa di lettere, numeri, punteggiatura, un po'
lunga con una serie di a-capo:
... ::: -_!£$%%&/()= \\ [] @@@@
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ">|	|<         \" ' :: \:
  |<
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w ">|\t|<         \" ' :: \:\n  |<\n"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w 2147483647
  invokevirtual java/io/PrintStream/print(I)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w 2147483647
  invokevirtual java/io/PrintStream/print(C)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc2_w 7000000000
  invokevirtual java/io/PrintStream/print(J)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w 64
  invokevirtual java/io/PrintStream/print(I)V
  
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w 64
  invokevirtual java/io/PrintStream/print(C)V

  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc_w "
"
  invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
  
  return
.end method

.end class
