#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_vogal(char t)
{
  if (t == 'a' || t == 'A' || t == 'e' || t == 'E' || t == 'i' || t == 'I' || t =='o' || t=='O' || t == 'u' || t == 'U')
    return 1;

  return 0;
}

int contaVogais (char *s) {
    char vogais [] = "aeiou";
    int count = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (check_vogal(s[i])) count++;
    }
    return count;
}

int retiraVogais (char *s) {
    int length = 0, i;
    for (length = 0; s[length] != 0; length++);

    for (i = 1; i < length; i++) {
        if (check_vogal(s[i-1]) && check_vogal(s[i])) {
            for (int j = i; j < length; j++) {
                char aux = s[j];
                s[j] = s[j+1];
                s[j-1] = aux;
            }
            length--;
            i--;
        }
    }
    s[i] = '\0';
    return 0;
}

int duplicaVogais (char *s) {
    int i, count = 0;
    for (i = 0; s[i] != 0; i++);

    for (int j = 0; j < i; j++) {
        if (check_vogal(s[j])) {
            char aux = s[j];
            for (int k = i; k > j; k--) {
                s[k] = s[k-1];
            }
            i++;
            s[j] = aux;
            j++;
            count++;
        }
    }
    return count;
}


int main () {
    char str[50] = "Esta e uma string com duplicados";
    int count = duplicaVogais(str);
    printf("%s\n", str);
    printf("Adicionados: %d\n", count);
}