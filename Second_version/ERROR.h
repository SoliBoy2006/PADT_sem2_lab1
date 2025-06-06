#ifndef ERROR_H
#define ERROR_H

typedef enum {
    ERROR_OK,                   // Нет ошибки
    ERROR_NULL_POINTER,         // Нулевой указатель
    ERROR_INVALID_SIZE,         // Неверный размер
    ERROR_TYPE_MISMATCH,        // Несоответствие типов
    ERROR_INDEX_OUT_OF_RANGE,   // Индекс вне диапазона
    ERROR_MEMORY_ERROR,         // Ошибка выделения памяти
    ERROR_NOT_SQUARE,           // Матрица не квадратная
    ERROR_SINGULAR,             // Вырожденная матрица (для обратной и LU)
    ERROR_INCOMPATIBLE_SIZES,   // Несовместимые размеры
    ERROR_FILE_OPEN,            // Ошибка открытия файла
    ERROR_FILE_READ,           // Ошибка чтения файла
    ERROR_FILE_WRITE,          // Ошибка записи в файл
    ERROR_INVALID_FORMAT,      // Неверный формат данных
    ERROR_OPERATION_FAILED,    // Общая ошибка операции
    ERROR_DIVISION_BY_ZERO     // Деление на ноль
} ErrorCode;

extern ErrorCode last_error;

const char* error_string(ErrorCode error);

void set_error(ErrorCode error);

void reset_error();

ErrorCode last_error = ERROR_OK;

static const char* error_messages[] = {
    "Нет ошибки",                    
    "Нулевой указатель",               
    "Неверный размер",               
    "Несоответствие типов",           
    "Индекс вне диапазона",            
    "Ошибка выделения памяти",         
    "Матрица не квадратная",          
    "Вырожденная матрица",             
    "Несовместимые размеры",           
    "Ошибка открытия файла",           
    "Ошибка чтения файла",            
    "Ошибка записи в файл",            
    "Неверный формат данных",         
    "Общая ошибка операции",           
    "Деление на ноль"                  
};

const char* error_string(ErrorCode error) {
    if (error < 0 || error > ERROR_DIVISION_BY_ZERO) {
        return "Неизвестная ошибка";
    }
    return error_messages[error];
}

void set_error(ErrorCode error) {
    last_error = error;
    printf("Ошибка: %s\n", error_string(error));
}

void reset_error() {
    last_error = ERROR_OK;
} 

#endif