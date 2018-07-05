import sys, os
import arrow
import os.path

from weather import Weather, Unit

date = arrow.now().format('YYYY-MM-DD')
path = '/Users/lixinrui/onedrive/Diary/source/_posts/'
filename = path + date + ".md"
if os.path.isfile(filename):
    os.system("open -a Typora " + filename)
    sys.exit(0)

os.chdir(path)
os.system("hexo n " + date)
f = open(filename, 'a')

weather = Weather(unit=Unit.CELSIUS)

lookup = weather.lookup(2161838)
condition = lookup.condition.text
high = lookup.forecast[0].high
low = lookup.forecast[0].low

print("{}, {}° - {}°".format(condition, low, high), file = f)
f.close()
os.system("open -a Typora " + filename)
