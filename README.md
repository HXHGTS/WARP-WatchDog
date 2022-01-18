# WARP-WatchDog
Warp出口ip监控工具

安装使用(下载安装):
```
wget https://github.com/HXHGTS/WARP-WatchDog/releases/latest/download/watchdog -O watchdog && chmod +x watchdog && ./watchdog
```
安装使用(编译安装):
```
wget https://raw.githubusercontent.com/HXHGTS/WARP-WatchDog/main/main.c -O watchdog.c && chmod +x watchdog.c && gcc -o watchdog watchdog.c && ./watchdog
```
后台守护进程:
```
echo "*/5 * * * * ./watchdog > /dev/null" > /var/spool/cron/root
```
