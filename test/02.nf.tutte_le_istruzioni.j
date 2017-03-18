.class public Main
.super java/lang/Object


.method public static main ([Ljava/lang/String;)V

  iadd
  idiv
  imul
  ineg
  irem
  ishl
  ishr
  isub
  ladd
  ldiv
  lmul
  lneg
  lrem
  lshl
  lshr
  lsub
  ldc_w 1000
  ldc_w "prova stringa"
  ldc2_w 1000000
  sipush 1
  goto label
  if_icmpeq label
  if_icmpge label
  if_icmpgt label
  if_icmple label
  if_icmplt label
  if_icmpne label
  ifeq label
  ifge label
  ifgt label
  ifle label
  iflt label
  ifne label
  lcmp
  nop
  i2c
  i2s
  i2l
  l2i
  dup
  dup2
  pop
  pop2
  swap
  getstatic Main/f d
  invokestatic Main/m d
  putstatic Main/f d
  iload n
  istore n
  lload n
  lstore n
  invokevirtual java/io/PrintStream/println(T)V
  new java/io/BufferedReader
  invokespecial java/io/InputStreamReader/<init> (Ljava/io/InputStream;)V
  lreturn

.end method

.end class
