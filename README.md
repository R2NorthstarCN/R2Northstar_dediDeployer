# [CN]本地通过监测进程保证服务器重启
当前代码较为简陋,只完成了底层的逻辑映射,代码函数封装程度低,会不断更新!

# [ENG] A C++ Program that deploys multiple instances of r2ds with crash detect and auto-restart
Install:
Put this program anywhere you like, personally I like to put it in the same folder containing all the game server folders.
How to use:
Run the program.
Specify the number of server instances. this depends on how many copies of dedicated server files you have.
After hitting enter, a file location prompt will appear. locate your different r2ds.bat each time the prompt appears.
Server will start everytime you located one instance of r2ds.bat, and it will start the listening process after assigning all the r2ds instances.
