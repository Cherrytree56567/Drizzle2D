#include "Threading.h"

namespace Drizzle2D {
    typedef void (*thread_function_t)(void);

    DWORD WINAPI ThreadFunc(LPVOID lpParam) {
        thread_function_t thread_func = (thread_function_t)lpParam;
        thread_func();
        return 0;
    }

    void multithread_function(thread_function_t thread_func) {
        HANDLE hThread;
        DWORD dwThreadId;

        hThread = CreateThread(NULL, 0, ThreadFunc, thread_func, 0, &dwThreadId);
        if (hThread == NULL) {
            printf("Error creating thread\n");
            return;
        }

        CloseHandle(hThread);

        printf("Thread started in the background\n");
    }
}