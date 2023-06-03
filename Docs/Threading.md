# Threading
To Thread a function first make a function like
```
thread_function_t Hello() {
    std::cout << "Hello from thread" << std::endl;
}
```
then pass the function to the **multithread_function** function
```
multithread_function(Hello);
```
