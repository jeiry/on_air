#!/usr/bin/python
#-*-coding:utf-8 -*-
import threading
import time
from noairLight import colorLight
cl = colorLight()
class LightThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.color = '255,255,255'  # 停止标志位
        self.Parm = 0  # 用来被外部访问的
        self.oldColor = ''
        print('started light')
        # 自行添加参数

    def run(self):
        while (True):

            if self.oldColor != self.color:
                print(self.color)
                cl.sentData(self.color)
                self.oldColor = self.color
            time.sleep(0.3)

    def setParm(self, parm):  # 外部修改内部信息函数
        self.color = parm

    def getParm(self):  # 外部获得内部信息函数
        return self.color
