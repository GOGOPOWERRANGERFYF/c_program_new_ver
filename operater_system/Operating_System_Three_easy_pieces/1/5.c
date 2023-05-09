/**
 * 第5章 插叙：进程API 
 *                          补充：插叙
 *     本章将介绍更多系统实践方面的内容，包括特别关注操作系统的API及其使用方式。
 *     ...
 * 
 *     本章将讨论UNIX系统中的进程创建。UNIX系统采用了一种非常有趣的创建新进程的
 * 方式，即通过一对系统调用：fork()和exec()。进程还可以通过第三个系统调用wait(),来等
 * 待其创建的子进程执行完成。本章将详细介绍这些接口，通过一些简单的例子来激发兴趣。
 * 
 *                      关键问题：如何创建并控制进程
 *     ...
 * 
 * 5.1 fork()系统调用
 *     系统调用fork()用于创建新进程[C63]。但要小心，这可能是你使用过的最奇怪的接口。
 * ...
 *     #include <stdio.h>
 *     #include <stdlib.h>
 *     #include <unistd.h>
 *     
 *     ...
 * 
 * 5.2 wait()系统调用
 * 
 *     ...
 * 
 * 
 * 5.3 最后是exec()系统调用
 * 
 *     ...
 * 
 * 
 * 
*/