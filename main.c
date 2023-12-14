// Autor: OpenAI GPT-3.5
// Data: 2023-12-13
// Este código é uma adaptação feita pelo OpenAI GPT-3.5.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

char **parseErrors(const char *enum_name, const char *filePath);
char *trimWhitespace(char *str);
int isComment(char *line);

int main() {
    // Exemplo de uso
    // char **errors = parseErrors("lk_diagnostic_code_e", "lk_app_diagnostics.h");
    char **errors = parseErrors("lk_errors_t", "lk_errors.h");

    if (errors == NULL) {
        printf("Erro ao analisar os erros\n");
        return 1;
    }

    // Imprime a lista resultante
    // for (int i = 0; errors[i] != NULL; i++) {
    //     printf("%s %u\n", errors[i], i);
    //     // free(errors[i]);
    // }

    for(int i = 0; errors[i] != NULL; i++)
    {
        printf("Enum %u String: %s\n", i, errors[i]);
    }

    // for(int i = 232; i < 233; i++)
    // {
    //     printf("Enum %u error %s\n", i, errors[i]);
    // }

    // Libera a memória alocada para a lista
    free(errors);

    return 0;
}

char **parseErrors(const char *enum_name, const char *filePath) {
    FILE *file;
    char line_vet[MAX_LINE_LENGTH];
    int inside_enum = 0;

    // Abre o arquivo para leitura
    file = fopen(filePath, "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Encontre o início do enum
    while (fgets(line_vet, sizeof(line_vet), file) != NULL) {
        if (strstr(line_vet, "enum") != NULL) {
            inside_enum = 1;
            break;
        }
    }

    if (!inside_enum) {
        fclose(file);
        return NULL;
    }

    // Processa as linhas do enum
    int index = 0;
    char **result_list = malloc(MAX_LINE_LENGTH * sizeof(char *));
    if (result_list == NULL) {
        perror("Erro de alocação de memória");
        exit(1);
    }

    // Ignora a primeira linha com a chave de abertura
    fgets(line_vet, sizeof(line_vet), file);

    int line_count = 0;

    enum{
        IGNORE_MULTI_LINE_0 = 0,
        IGNORE_MULTI_LINE_1,
        IGNORE_MULTI_LINE_2,
    };

    int ignore_multi_line = IGNORE_MULTI_LINE_0;

    while (fgets(line_vet, sizeof(line_vet), file) != NULL) {
        if (strstr(line_vet, enum_name) != NULL) {
            // Fim do enum
            break;
        }

        char *line = line_vet;

        // Encontra e remove comentários
        char *commentStart = strstr(line, "//");
        if (commentStart != NULL) {
            *commentStart = '\0'; // Remove tudo após o //
        }

        char *multLineCommentStart = strstr(line, "/*");
        char *multLineCommentStop = strstr(line, "*/");

        if(multLineCommentStart != NULL && multLineCommentStop != NULL && ignore_multi_line == IGNORE_MULTI_LINE_0)
        {
            *multLineCommentStart = '\0';
            ignore_multi_line = IGNORE_MULTI_LINE_0;
        }
        else if(multLineCommentStart != NULL && ignore_multi_line == IGNORE_MULTI_LINE_0)
        {
            *multLineCommentStart = '\0';
            ignore_multi_line = IGNORE_MULTI_LINE_1;
        }
        else if(multLineCommentStop != NULL && ignore_multi_line)
        {
            ignore_multi_line = IGNORE_MULTI_LINE_0;

            line = multLineCommentStop + 2;
        }

        // Ignora linhas comentadas e a última linha com a chave de fechamento
        if (/*isComment(line) || */strstr(line, "}") != NULL) {
            continue;
        }

        if(ignore_multi_line == IGNORE_MULTI_LINE_2)
        {
            continue;
        }

        char *equalStart = strstr(line, "=");
        if (equalStart != NULL) {
            char *commaStart = strstr(line, ",");
            if(commaStart != NULL)
            {
                *commaStart = '\0'; //Clean comma
            }
            int number = atoi(equalStart + 1); //Ignore "="
            // printf("Number: %d\n", number);
            // printf("String: %s\n", equalStart);
            *equalStart = '\0'; // Remove tudo após o //

            //insert empty string on array until number

            char empty_string[] = "";
            while(number > index)
            {
                result_list[index] = malloc(strlen(empty_string) + 1);
                strcpy(result_list[index++], empty_string);
            }
        }

        char *trimmedLine = strtok(line, ",");
        while (trimmedLine != NULL) {
            // Remove espaços em branco e verifica se não é uma string vazia
            char *enumString = trimWhitespace(trimmedLine);
            if (*enumString != '\0') {
                result_list[index] = malloc(strlen(enumString) + 1);
                strcpy(result_list[index], enumString);
                index++;
            }
            trimmedLine = strtok(NULL, ",");
        }

        if(ignore_multi_line)
        {
            ignore_multi_line = IGNORE_MULTI_LINE_2;
        }
    }

    // Fecha o arquivo
    fclose(file);

    // Retorna a lista resultante
    result_list[index] = NULL; // Adiciona um marcador de final de lista
    return result_list;
}

// Função para remover espaços em branco no início e no final de uma string
char *trimWhitespace(char *str) {
    char *end;

    // Remover espaços no início
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // String vazia ou apenas espaços
    if (*str == 0) {
        return str;
    }

    // Remover espaços no final
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Adicionar terminador nulo
    end[1] = '\0';

    return str;
}

// Função para verificar se a linha é um comentário /* ... */
int isComment(char *line) {
    char *start = strstr(line, "/*");
    char *end = strstr(line, "*/");

    if (start != NULL && end != NULL && end > start) {
        return 1; // É um comentário /* ... */
    }

    return 0;
}
