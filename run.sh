clang -g -O1 -c -emit-llvm --target=x86_64-unknown-linux-gnu -I$JAVA_HOME/languages/llvm/include/graalvm/llvm main.c
$JAVA_HOME/bin/javac -cp . SystemInfoLLVM.java
$JAVA_HOME/bin/java -cp . SystemInfoLLVM
