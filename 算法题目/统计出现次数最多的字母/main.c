#include <stdio.h>
#include <string.h>
#include <ctype.h>

void find_most_frequent_letters(const char* sentence)
{
    int count[26] = {0};

    for(int i = 0; sentence[i] != '\0'; i++) {//一直循环到输入字符串包含\0为止
        char c = sentence[i];
        
        if(isalpha(c)) {  //isalpha函数判断是否为字母 是字母返回非零值
            c = tolower(c); //tolower函数转化为小写
            count[c - 'a']++;//对于的数字数组加1
        }
    }
    
    int max_count = 0;
    for(int i = 0; i < 26; i++) {//找到最大的字符
        if(count[i] > max_count) {
            max_count = count[i];
        }
    }
    
    printf("%d", max_count);
    for(int i = 0; i < 26; i++) {//输出最大的字符
        if(count[i] == max_count && max_count > 0) {
            printf("%c ", 'a' + i);
        }
    }
    printf("\n");
}

int main() {
    char sentence[1000];//存储输入的字符串
    fgets(sentence, sizeof(sentence), stdin);//从标准输入流stdin读取sizeof(sentence)个字符到sentence
    sentence[strcspn(sentence, "\n")] = '\0';//找到第一个换行符/n，并替换为0x00。
    find_most_frequent_letters(sentence);//
    return 0;
}