@echo off
gcc -o ".\build.exe" ".\main\main.c" ".\common\random.c" ".\common\sort.c" -I ".\common"
