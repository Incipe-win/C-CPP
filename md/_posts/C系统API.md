open

查看man 2 open

int open(const char *pathname, int flags);

int open(const char *pathname, int flags, mode_t mode);

+ pathname 文件名
+ flags
  + 必选项
    + O_RDONLY 只读
    + O_WRONLY 只写
    + O_RDWR 读写
  + 可选项
    + O_APPEND 追加
    + O_CREAT 创建文件
      + O_EXCL 与 O_CREAT 一起使用，如果文件存在，则报错。
      + mode权限位，最终（mode & ~umask）
    + O_NONBLOCK 非阻塞
+ 返回值：返回最小的可用文件描述符，失败返回-1，设置errno

close

+ int close(int fd);
+ 返回值：成功0，失败-1，设置errno

read

+ ssize_t read(int fd, void *buf, size_t count);
+ fd文件描述符
+ buf缓冲区
+ count缓冲区大小
+ 返回值
  + 失败-1，设置errno
  + 成功返回读到的大小
  + 0代表读到文件末尾

write：

+ ssize_t write(int fd, const void *buf, size_t count);
+ fd文件描述符
+ buf缓冲区
+ count大小
+ 返回值：
  + 成功，返回写入的字节数
  + 失败，返回-1
  + 0代表未写入

lseek：

+ off_t lseek(int fd, off_t offset, int whence);
+ fd文件描述符
+ offset偏移量
+ whence
  + SEEK_SET 文件开始位置
  + SEEK_CUR 文件当前位置
  + SEEK_END 文件结尾
+ 返回值：
  + 成功：返回当前位置到开始的长度
  + 失败-1，设置errno

lseek作用：

+ 移动文件读写位置
+ 计算文件大小
+ 扩展文件

