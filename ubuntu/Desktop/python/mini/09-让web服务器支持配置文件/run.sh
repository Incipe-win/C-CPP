##########################################################################
# File Name: run.sh
# Author: incipe
# Mail: chaoh7461@gmail.com
# Created Time: 2020年03月07日 星期六 18时41分08秒
#########################################################################
#!/bin/zsh
PATH=/home/edison/bin:/home/edison/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/work/tools/gcc-3.4.5-glibc-2.3.6/bin
export PATH
python3 web_server.py 6789 mini_frame:application
