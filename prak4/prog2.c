/* ---------------------------------------------------- */
/* ИМЯ: Фролов Даниил */
/* СРОК: 21/09/2025 */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ: Практическая работа №4 */
/* ИМЯ ФАЙЛА: prog2.c */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ: */
/* Создание процессов с циклами вывода счётчика (MAX_COUNT=200) */
/* ---------------------------------------------------- */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 200

/* ---------------------------------------------------- */
/* ФУНКЦИЯ ChildProcess: Выполнение дочернего процесса */
/* НАЗНАЧЕНИЕ: Цикл вывода значений счётчика от дочернего */
/* ПАРАМЕТРЫ: Нет */
/* ВЫЗЫВАЕМЫЕ ФУНКЦИИ: printf, getpid */
/* ---------------------------------------------------- */
void ChildProcess(void);

/* ---------------------------------------------------- */
/* ФУНКЦИЯ ParentProcess: Выполнение родительского процесса */
/* НАЗНАЧЕНИЕ: Цикл вывода значений счётчика от родительского */
/* ПАРАМЕТРЫ: Нет */
/* ВЫЗЫВАЕМЫЕ ФУНКЦИИ: printf, getpid */
/* ---------------------------------------------------- */
void ParentProcess(void);

int main() {
    pid_t pid;
    printf("Main: PID %d, PPID %d\n", getpid(), getppid());
    pid = fork();
    if (pid > 0) {
        ParentProcess();
    } else if (pid == 0) {
        ChildProcess();
    } else {
        perror("fork");
        return 1;
    }
    return 0;
}

void ChildProcess(void) {
    int i;
    printf("Child process started: PID %d, PPID %d\n", getpid(), getppid());
    for (i = 1; i <= MAX_COUNT; i++) {
        printf("   This line is from child, value = %d\n", i);
    }
    printf("Child process PID %d terminates.\n", getpid());
}

void ParentProcess(void) {
    int i;
    printf("Parent process started: PID %d, PPID %d\n", getpid(), getppid());
    for (i = 1; i <= MAX_COUNT; i++) {
        printf("   This line is from parent, value = %d\n", i);
    }
    printf("Parent process PID %d terminates.\n", getpid());
}
