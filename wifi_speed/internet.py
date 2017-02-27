import datetime
import urllib2
import os
import sys
import time
import subprocess
from gi.repository import NetworkManager, NMClient

def getInternetSpeed():
    path = sys.argv[0]
    print path
    path = list(path)
    print path
    while True:
        if path[len(path)-1] == chr(92) or path[len(path)-1] == '/':
            path = ('').join(path)
            break
        else:
            path.pop(len(path)-1)
    print path
    start = str(datetime.datetime.now())
    x = urllib2.urlopen('https://google.com')
    end = str(datetime.datetime.now())
    x = x.read()
    print x
    start = list(start)
    end = list(end)
    for i in range(17):
        start.pop(0)
        end.pop(0)
    start = ('').join(start)
    end = ('').join(end)
    start = float(start)
    end = float(end)
    diff = end - start
    f = open(path+'TEMP.txt','w')
    f.write(x)
    f.close()
    size = os.path.getsize(path+'TEMP.txt')
    os.remove(path+'TEMP.txt')
    print 'It took ' + str(diff) + ' second(s)'
    print 'to get a file that was ' + str(size / 1000) + ' kilobytes large!'
    scale = 1 / diff
    size = size * scale
    size = size / 1000

    print 'Download speed of ' + str(int(size)) + ' kilobytes a second'
    return size
t=0
i=0
for j in xrange(1):
    i=i+1
    k= getInternetSpeed()
    t=t+k
print "time--------"
print t/i


nmc = NMClient.Client.new()
devs = nmc.get_devices()


for dev in devs:
    if dev.get_device_type() == NetworkManager.DeviceType.WIFI:
        for ap in dev.get_access_points():
            print ap.get_ssid(),ap.ge
