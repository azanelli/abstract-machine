.class public Main
.super java/lang/Object

.method public static foo1 (III)J
  invokestatic Main/foo2 (  ) V
  ldc2_w 109203
  lreturn
.end method

.method public static foo2   ( ) V
  ldc_w 100
  ldc2_w 1000
  ldc_w 10
  ldc_w 1
  invokestatic Main/foo3( IJCS   )I
  return
.end method

.method public static foo3 (     IJCS)I
  ldc_w 1
  ireturn
.end method

.method public static foo4(J  )   C
  ldc_w 10
  ireturn
.end method

.method public static main ([Ljava/lang/String;)V
  ldc_w 1
  ldc_w 2
  ldc_w 3
  invokestatic Main/foo1 (  III  )  J
  invokestatic Main/foo4(J)C
  return
.end method

.end class
