#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 桶的容量
#define CAP_3L 3
#define CAP_5L 5
#define CAP_8L 8

// 状态节点结构
typedef struct StateNode {
    int state[3];             // (3L桶, 5L桶, 8L桶)的水量
    struct StateNode* parent; // 父节点，用于回溯路径
    struct StateNode** children; // 子节点数组
    int child_count;          // 子节点数量
} StateNode;

// 状态历史记录
StateNode** state_history = NULL; //
int history_size = 0;             //
int history_capacity = 0;         //

// 创建新状态节点
StateNode* createStateNode(int a, int b, int c, StateNode* parent) {
    StateNode* newNode = (StateNode*)malloc(sizeof(StateNode));
    newNode->state[0] = a;//杯子1
    newNode->state[1] = b;//杯子2
    newNode->state[2] = c;//杯子3
    newNode->parent = parent;//父节点地址
    newNode->children = NULL;//子节点暂定为空
    newNode->child_count = 0;//子节点数量为0
    return newNode;
}

// 检查状态是否在历史记录中
bool isStateInHistory(int a, int b, int c) {
    for (int i = 0; i < history_size; i++) {
        if (state_history[i]->state[0] == a &&
            state_history[i]->state[1] == b &&
            state_history[i]->state[2] == c) {
            return true;
        }
    }
    return false;
}

// 添加状态到历史记录
void addToHistory(StateNode* node) {
    if (history_size >= history_capacity) {
        history_capacity = history_capacity == 0 ? 10 : history_capacity * 2;
        state_history = realloc(state_history, history_capacity * sizeof(StateNode*));
    }
    state_history[history_size++] = node;
}

// 检查是否达到目标状态
bool isGoalState(int a, int b, int c) {
    return a == 4 || b == 4 || c == 4;
}

// 从桶i向桶j倒水
bool pourWater(int* state, int from, int to, int* new_state) {
    int capacities[3] = {CAP_3L, CAP_5L, CAP_8L};
    
    // 复制原状态
    for (int i = 0; i < 3; i++) {
        new_state[i] = state[i];
    }
    
    // 检查是否可以倒水
    if (state[from] == 0 || state[to] == capacities[to]) {
        return false; // 源桶为空或目标桶已满
    }
    
    // 计算倒水量
    int pour_amount = state[from];
    if (state[from] > (capacities[to] - state[to])) {
        pour_amount = capacities[to] - state[to];
    }
    
    // 执行倒水
    new_state[from] -= pour_amount;
    new_state[to] += pour_amount;
    
    return true;
}

// 生成所有可能的下一步状态
void generateNextStates(StateNode* current) {
    int child_states[6][3]; // 最多6种可能的倒水操作
    int child_count = 0;
    
    // 尝试所有可能的倒水组合
    for (int from = 0; from < 3; from++) {
        for (int to = 0; to < 3; to++) {
            if (from != to) {
                int new_state[3];
                if (pourWater(current->state, from, to, new_state)) {
                    // 检查是否是新状态
                    if (!isStateInHistory(new_state[0], new_state[1], new_state[2])) {
                        for (int i = 0; i < 3; i++) {
                            child_states[child_count][i] = new_state[i];
                        }
                        child_count++;
                    }
                }
            }
        }
    }
    
    // 创建子节点
    if (child_count > 0) {
        current->children = (StateNode**)malloc(child_count * sizeof(StateNode*));
        current->child_count = child_count;
        
        for (int i = 0; i < child_count; i++) {
            StateNode* child = createStateNode(
                child_states[i][0], 
                child_states[i][1], 
                child_states[i][2], 
                current
            );
            current->children[i] = child;
            addToHistory(child);
        }
    }
}

// 打印状态
void printState(int state[3]) {
    printf("(%d, %d, %d)", state[0], state[1], state[2]);
}

// 打印解决方案路径
void printSolutionPath(StateNode* goal) {
    if (goal->parent != NULL) {
        printSolutionPath(goal->parent);
    }
    printState(goal->state);
    if (isGoalState(goal->state[0], goal->state[1], goal->state[2])) {
        printf(" <- 目标!\n");
    } else {
        printf(" -> ");
    }
}

// 深度优先搜索解决方案
StateNode* findSolutionDFS(StateNode* current) {
    if (current == NULL) return NULL;
    
    // 检查是否达到目标
    if (isGoalState(current->state[0], current->state[1], current->state[2])) {
        return current;
    }
    
    // 生成下一步状态
    generateNextStates(current);
    
    // 递归搜索子节点
    for (int i = 0; i < current->child_count; i++) {
        StateNode* result = findSolutionDFS(current->children[i]);
        if (result != NULL) {
            return result;
        }
    }
    
    return NULL;
}

// 释放内存
void freeTree(StateNode* root) {
    if (root == NULL) return;
    
    for (int i = 0; i < root->child_count; i++) {
        freeTree(root->children[i]);
    }
    
    if (root->children != NULL) {
        free(root->children);
    }
    
    free(root);
}

int main() {
    // 初始化历史记录
    state_history = NULL;
    history_size = 0;
    history_capacity = 0;
    
    // 创建初始状态
    StateNode* root = createStateNode(0, 0, 8, NULL);
    addToHistory(root);
    
    printf("开始搜索解决方案...\n");
    printf("初始状态: ");
    printState(root->state);
    printf("\n");
    
    // 搜索解决方案
    StateNode* solution = findSolutionDFS(root);
    
    if (solution != NULL) {
        printf("\n找到解决方案!\n");
        printf("路径: ");
        printSolutionPath(solution);
    } else {
        printf("未找到解决方案\n");
    }
    
    // 统计状态数量
    printf("\n总共探索了 %d 个状态\n", history_size);
    
    // 清理内存
    freeTree(root);
    free(state_history);
    
    return 0;
}