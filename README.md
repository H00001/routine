# routine

![](https://img.shields.io/travis/changkun/modern-cpp-tutorial/master?style=flat-square) [![](https://img.shields.io/badge/language-English-blue.svg?style=flat-square)](./README.md) [![](https://img.shields.io/badge/€-donate-ff69b4.svg?style=flat-square)](./assets/donate.md) [![](https://img.shields.io/badge/chat-community-667ed5.svg?style=flat-square)](./assets/community.md) 



## What is routine

A fast routine implemented by C

Routine is a lightweight thread. Although it is a thread, it has advantages and features that threads do not have.

+ Context of routine change is faster than context of thread.
+ Routine is much lighter and easier to manipulate than thread.
+ The way to switch routine is cooperative, not preemptive.
+ Context of routine switching doesn't go into the kernel, so there's no need to interrupt or get trap.

## Get start

```bash
# make the project
make
# install the project
make install
```

