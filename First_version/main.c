#include "interface.h"

void Command_List();

void Command_List(){
    printf("Add - добавление новой матрицы\n");
    printf("Command list - выведение списка команд\n");
    printf("Delete - удаление одной из матриц\n");
    printf("Exit - завершение программы\n");
    printf("Multy on - умножение матрицы на число\n");
    printf("Multy mat - перемножение матриц\n");
    printf("Print matrix - вывод одной из матриц\n");
    printf("Print all - вывод всех существующих матриц\n");
    printf("Summa - сложение матриц\n");
    printf("Transporation - транспонирование матрицы\n");
}

int main(){
    printf("Приветствую тебя дорогой пользователь. Я простенькая программа, созданная для работы с матрицами\n");
    Matrix list[10];
    int count = 0;
    int exit = 1;
    while(exit){
        printf("Не мог бы ты ввести команду: ");
        char command[20];
        scanf("%19s", command);
        
        if(strcmp(command, "Add") == 0) Add_Matrix(list, &count);
        else if(strcmp(command, "Command") == 0) Command_List();
        else if(strcmp(command, "Delete") == 0) Delete_Matrix(list, &count);
        else if(strcmp(command, "Exit") == 0) exit = 0;
        else if(strcmp(command, "Multy") == 0){
            char subcmd[10];
            scanf("%9s", subcmd);
            if(strcmp(subcmd, "on") == 0){
                Multy_on(list);
            }
            else if(strcmp(subcmd, "mat") == 0){
                Matrix result = Multy_mat(list);
                if(count < 10) {
                    list[count++] = result;
                } else {
                    printf("Прости, моя память переполнена.\n");
                    Free_Matrix(&result);
                }
            }
        }
        else if(strcmp(command, "Transporation") == 0){
            Matrix result = Trans(list);
                if(count < 10) {
                    list[count++] = result;
                } else {
                    printf("Прости, моя память переполнена.\n");
                    Free_Matrix(&result);
                }
        }
        else if(strcmp(command, "Print") == 0){
            char subcmd[10];
            scanf("%9s", subcmd);
            if(strcmp(subcmd, "matrix") == 0){
                Print(list);
            }
            else if(strcmp(subcmd, "all") == 0){
                Print_All(list, count);
            }
        }
        else if(strcmp(command, "Summa") == 0) Sum(list);
        else printf("Прости, я не знаю такую команду, вы можете посмотреть имеющиеся команды по команде Command list\n");
    }
    Exit(list, count);

    return 0;
}