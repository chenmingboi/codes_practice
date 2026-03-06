import time
import sys

def loading_multiple(m):
    bar = 30
    for p in range(m):
        for i in range(1, bar + 1):
            time.sleep(0.1)  # 控制速度
            percent = i * 100 // bar
            L = "+" * i + "0" * (bar - i)
            sys.stdout.write(f'\rTask {p+1}/{m} [{L}] {percent:3d}%')
            sys.stdout.flush()
        # 清除当前行
        sys.stdout.write('\r' + ' ' * (50 + bar) + '\r')
        sys.stdout.flush()
    print("ALL DONE")

loading_multiple(3)
