#include <stdio.h>

int solutions[1000][20]; // 存储所有方案
int solution_count = 0;   // 方案计数
int current[20];          // 当前正在构建的方案

// DFS函数
// pos: 当前在方案中的位置
// start: 下一次跑步的最小圈数
// remaining: 剩余需要跑的圈数
void dfs(int pos, int start, int remaining) {
    // 如果剩余圈数为0，说明找到了一个有效方案
    if (remaining == 0) {
        // 确保至少跑了两次
        if (pos > 1) {
            // 将当前方案保存到解决方案数组中
            for (int i = 0; i < pos; i++) {
                solutions[solution_count][i] = current[i];
            }
            // 标记方案结束
            solutions[solution_count][pos] = -1;
            solution_count++;
        }
        return;
    }
    
    // 尝试所有可能的圈数
    for (int i = start; i <= remaining; i++) {
        // 确保圈数是正整数
        if (i > 0) {
            current[pos] = i;
            // 递归调用：位置+1，下一次最小圈数为i+1，剩余圈数减少i
            dfs(pos + 1, i + 1, remaining - i);
        }
    }
}

int main() {
    // 使用DFS生成所有方案
    dfs(0, 1, 20);
    
    // 输出方案总数
    printf("方案总数: %d\n", solution_count);
    
    // 输出所有方案
    for (int i = 0; i < solution_count; i++) {
        printf("(");
        for (int j = 0; solutions[i][j] != -1; j++) {
            printf("%d", solutions[i][j]);
            if (solutions[i][j + 1] != -1) {
                printf(",");
            }
        }
        printf(")");
        if (i < solution_count - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}