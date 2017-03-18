.class public Main
.super java/lang/Object


.method public static main ([Ljava/lang/String;)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "char input: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

new java/io/BufferedReader
dup
new java/io/InputStreamReader
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/io/InputStreamReader/<init> (Ljava/io/InputStream;)V
invokespecial java/io/BufferedReader/<init> (Ljava/io/Reader;)V
invokevirtual java/io/BufferedReader/read ()I
istore 1

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "char letto: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/print (C)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V


getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "int input: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

new java/io/BufferedReader
dup
new java/io/InputStreamReader
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/io/InputStreamReader/<init> (Ljava/io/InputStream;)V
invokespecial java/io/BufferedReader/<init> (Ljava/io/Reader;)V
invokevirtual java/io/BufferedReader/readLine ()Ljava/lang/String;
invokestatic java/lang/Integer/parseInt (Ljava/lang/String;)I
istore 1

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "int letto: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/print (I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V


getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "long input: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

new java/io/BufferedReader
dup
new java/io/InputStreamReader
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/io/InputStreamReader/<init> (Ljava/io/InputStream;)V
invokespecial java/io/BufferedReader/<init> (Ljava/io/Reader;)V
invokevirtual java/io/BufferedReader/readLine ()Ljava/lang/String;
invokestatic java/lang/Long/parseLong (Ljava/lang/String;)J
lstore 1

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "long letto: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
lload 1
invokevirtual java/io/PrintStream/print (J)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V


getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "string input: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

getstatic java/lang/System/out Ljava/io/PrintStream;
new java/io/BufferedReader
dup
new java/io/InputStreamReader
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/io/InputStreamReader/<init> (Ljava/io/InputStream;)V
invokespecial java/io/BufferedReader/<init> (Ljava/io/Reader;)V
invokevirtual java/io/BufferedReader/readLine ()Ljava/lang/String;
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "string letto: "
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc_w "
"
invokevirtual java/io/PrintStream/print (Ljava/lang/String;)V

return

.end method


.end class
