# WARP-WatchDog
Warp出口ip监控工具

安装使用(下载安装):
```
wget https://github.com/HXHGTS/WARP-WatchDog/releases/latest/download/watchdog -O watchdog && chmod +x watchdog && ./watchdog
```

安装使用(编译安装)(Centos7/8):
```
yum install -y gcc && wget https://raw.githubusercontent.com/HXHGTS/WARP-WatchDog/main/main.c -O watchdog.c && chmod +x watchdog.c && gcc -o watchdog watchdog.c && ./watchdog
```
安装使用(编译安装)(Debian9/10/11):
```
apt install -y build-essential && wget https://raw.githubusercontent.com/HXHGTS/WARP-WatchDog/main/main.c -O watchdog.c && chmod +x watchdog.c && gcc -o watchdog watchdog.c && ./watchdog
```

后台守护进程(Centos7/8):
```
echo "*/5 * * * * ./watchdog > /dev/null" > /var/spool/cron/root
```

后台守护进程(Debian9/10/11):
```
echo "*/5 * * * * ./watchdog > /dev/null" > /var/spool/cron/crontabs/root
```
