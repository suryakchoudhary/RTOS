# Day- 1

## RTS

- The term “real-time system” refers to hardware and software components that perform real-time application functions and can respond to events within predictable and specific time constraints. The real time system is characterised by seveier consequences if the logical as well as timing correctness of the system is not met.

- It is of two types:

    - *Hard Real Time System:* In these types of systems, the timing/deadline is not so strictly followed. Missing the deadline is sometimes allowed.

    - *Soft Real Time System:* In these types of systems, the timing/deadline is not so strictly followed. Missing the deadline may have disastrous consequences.

## RTOS

- A real-time operating system (RTOS) is a program that schedules execution in a timely manner, manages system resources, and provides a consistent foundation for developing application code.

- Every RTOS has a kernel. On the other hand, an RTOS can be a combination of various modules, including the kernel, a file system, networking protocol stacks, and other components required for a particular application.

- It is of three types-

    - *Hard Real-Time operating system:* These operating systems guarantee that critical tasks be completed within a range of time(with correctness in logic as well as time). For example, a robot is hired to weld a car body. If the robot welds too early or too late, the car cannot be sold, so it is a hard real-time system that requires complete car welding by robot hardly on the time. 

    - *Soft real-time operating system:* This operating system provides some relaxation in the time limit. For example – Multimedia systems, digital audio systems etc. Explicit, programmer-defined and controlled processes are encountered in real-time systems. A separate process is changed with handling a single external event. The process is activated upon occurrence of the related event signalled by an interrupt. 

        - To understand how scheduling works, this section describes the following topics:

            - *Schedulable entities:*

            - *Multitasking:* Multitasking is the ability of the operating system to handle multiple activities within set deadlines. A real-time kernel might have multiple tasks that it has to schedule to run.


            - *Context switching:* A context switch occurs when the scheduler switches from one task to another. The time it takes for the scheduler to switch from one task to another is the context switch time.

                - TCBs are system data structures that the kernel uses to maintain task-specific information. TCBs contain everything a kernel needs to know about a particular task. When a task is running, its context is highly dynamic. This dynamic context is maintained in the TCB. When the task is not running, its context is frozen within the TCB, to be restored the next time the task runs.


            - *Dispatcher:* The dispatcher is the part of the scheduler that performs context switching and changes the flow of execution. At any time an RTOS is running, the flow of execution, also known as flow of control, is passing through one of three areas: through an application task, through an ISR, or through the kernel. When a task or ISR makes a system call, the flow of control passes to the kernel to execute one of the system routines provided by the kernel. When it is time to leave the kernel, the dispatcher is responsible for passing control to one of the tasks in the user’s application. It will not necessarily be the same task that made the system call. It is the scheduling algorithms (to be discussed shortly) of the scheduler that determines which task executes next. It is the dispatcher that does the actual work of context switching and passing execution control.

            - *Scheduling algorithms:* As mentioned earlier, the scheduler determines which task runs by following a scheduling algorithm (also known as scheduling policy). Most kernels today support two common scheduling algorithms:

                - *Preemptive prioritybased scheduling:* Most real-time kernels use preemptive prioritybased scheduling by default. The task that gets to run at any point is the task with the highest priority among all other tasks ready to run in the system. 
                    - Real-time kernels generally support 256 priority levels, in which 0 is the highest and 255 the lowest. Some kernels appoint the priorities in reverse order, where 255 is the highest and 0 the lowest.

                    - task 1 is preempted by higher-priority task 2, which is then preempted by task 3. When task 3 completes, task 2 resumes; likewise, when task 2 completes, task 1 resumes.


                - *Round-robin scheduling:* Round-robin scheduling provides each task an equal share of the CPU execution time. Pure round-robin scheduling cannot satisfy real-time system requirements because in real-time systems, tasks perform work of varying degrees of importance.

                    - If a task in a round-robin cycle is preempted by a higher-priority task, its runtime count is saved and then restored when the interrupted task is again eligible for execution. This idea is illustrated in Figure 4.5, in which task 1 is preempted by a higher-priority task 4 but resumes where it left off when task 4 completes.


- Most RTOS kernels contain the following components:

    - *Scheduler:* is contained within each kernel and follows a set of algorithms that determines which task executes when. Some common examples of scheduling algorithms include round-robin and preemptive scheduling. The scheduler is at the heart of every kernel.


    - *Objects:* are special kernel constructs that help developers create applications for real-time embedded systems. Common kernel objects include tasks, semaphores, and message queues. The most common RTOS kernel objects are-

        - *Tasks:* are concurrent and independent threads of execution that can compete for CPU execution time.

        - *Semaphores:* are token-like objects that can be incremented or decremented by tasks for synchronization or mutual exclusion.

        - *Message Queues:* are buffer-like data structures that can be used for synchronization, mutual exclusion, and data exchange by passing messages between tasks.
        

    - *Services:* are operations that the kernel performs on an object or, generally operations such as timing, interrupt handling, and resource management.




