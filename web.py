#!/usr/bin/python
#-*-coding:utf-8 -*-

import time
import os
from lightThread import LightThread
import threading
lightThread = LightThread()
os.environ["LANG"] = "en_US.UTF-8"
import os,base64

import requests
from flask import Flask,render_template,request
app = Flask(__name__)


@app.route('/color_light',methods=['GET'])
def color_light():
    print('color change')
    lightThread.setParm(request.args.get('v'))
    return 'true'


if __name__ == '__main__':
    lightThread.setDaemon(True)
    lightThread.start()
    app.debug = True # 设置调试模式，生产模式的时候要关掉debug
    app.run(host="0.0.0.0",port=2345)