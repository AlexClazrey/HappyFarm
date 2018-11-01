
你最应该做的：
用CodeBlocks+cygwin编译，它的项目设置里面已经把参数调好了，这个程序依赖libncurses，在cygwin里面可以安装。

你觉得自己挺能干的：
不想用cygwin和CodeBlocks的话，
链接时用参数链接libncurses.so libpanel.so，还有ncurses.h panel.h一共四个文件需要网上找来。
导入到别的IDE也好，手动编译也好都可以。
手动编译的话最方便的方法是把所有的.cpp .h别忘了在src外面的main.cpp倒在一起-同一个文件夹里然后执行：
g++ -pedantic -Wall -std=c++11 -fexceptions -g -c *.cpp
g++ -o main.exe *.o -lncurses -lpanel
