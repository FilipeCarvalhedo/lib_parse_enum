#include "lib_parse_enum.h"

#include "string.h"

int main() {
    // Exemplo de uso
    char **errors = lib_parse_enum("ex_errors_t", "../ex_errors.h");

    if (errors == NULL) {
        printf("Erro ao analisar a lista\n");
        return 1;
    }

    for(int i = 0; errors[i] != NULL; i++)
    {
        printf("Enum %u String: %s\n", i, errors[i]);
    }

    // Libera a memória alocada para a lista
    free(errors);

    return 0;
}

