#include <stdio.h>

// 枚举类型：用符号名(symbolic name)表示整数常量(integer constant);
// 这些符号常量(symbolic constant)的术语为枚举符(enumerator);
enum identifier {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, \
A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W,};

enum token_type {IF};

typedef struct token {
    enum token_type t_type;
    char * lexeme; // lexeme 词素,词位
} token;

token next_token(token token_arg);

int main(int argc, char * argv[]) {
    char char_var = getchar();
    printf("%c\n", char_var);

    token token1 = {"token1"};
    next_token(token1);
    return 0;
}

token next_token(token token_arg) {
    printf("%s\n", token_arg.lexeme);
    return token_arg;
}
