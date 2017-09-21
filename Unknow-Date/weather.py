import requests
from bs4 import BeautifulSoup
import datetime

now = datetime.datetime.now()
timeFormat = '%Y-%m-%d'
timeNow = now.strftime(timeFormat)
f = open(timeNow + '.md', 'w+')
c = requests.get('http://www.weather.com.cn/weather/101280101.shtml')
c.encoding = 'UTF-8'
soup = BeautifulSoup(c.text, 'html.parser')
wea = soup.find('ul', class_='t clearfix').find('li').find('p', class_='wea').string
today = BeautifulSoup(str(soup.find('ul', class_='t clearfix').find('li')),'html.parser')
tmpl = today.find('p', class_='tem').span.string
tmph = today.find('p', class_='tem').i.string
print('#' + timeNow, file = f)
print("天气：%s\t气温：%s - %s" %(wea, tmpl, tmph), file = f)
print("##最影响情绪的事情\n**起因，发生过程（记录本我，自我，超我），结果（处理的如何），现在想法，标签（情绪标签）**\n###正面\n###负面\n##今天做了什么\n###日常行为\n###下意识行为\n##今天思考了什么\n###价值观\n###人生观\n###世界观\n", file = f)
