# HOW TO BUILD

Need gcc:

  Debug version:
    gcc codegen.c -o codegen_debug
    
  Release version:
    gcc -Os -flto -o codegen codegen.c
    strip .\codegen.exe
