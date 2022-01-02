# WARP-WatchDog
Warp出口ip监控工具

安装使用:
```
wget https://github.com/HXHGTS/WARP-WatchDog/releases/download/Warp-WatchDog/watchdog -O watchdog && chmod +x watchdog && ./watchdog
```
后台守护进程:
```
echo "*/300 * * * * ./watchdog > /dev/null" > /var/spool/cron/root
```
