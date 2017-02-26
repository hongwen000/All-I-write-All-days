# -*- coding: utf-8 -*-
# python verson: 2.7.11

import json
import urllib
import urllib2
import cookielib
from bs4 import BeautifulSoup
from PIL import Image
from StringIO import StringIO
import sys
reload(sys)
sys.setdefaultencoding('utf-8')
#md5
def md5Upper(str):
    import hashlib
    m = hashlib.md5()
    m.update(str)
    return m.hexdigest().upper()


#PCL short for public course list
class PCL:
    def __init__(self, username, password):
        self.url = 'http://uems.sysu.edu.cn/elect'
        self.loginurl = 'http://uems.sysu.edu.cn/elect/login'
        self.codeurl = 'http://uems.sysu.edu.cn/elect/login/code'
        self.logininfo = {}
        self.logininfo['username'] = username
        self.logininfo['password'] = md5Upper(password)
        self.headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64)'}

    def setCookie(self):
        self.cj = cookielib.CookieJar()
        self.opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(self.cj))
        urllib2.install_opener(self.opener)

    def getCode(self):
        #request for the website
        self.req1 = urllib2.Request(self.url, headers = self.headers)
        try:
            urllib2.urlopen(self.req1)
        except:
            print 'Can\'t open http://uems.sysu.edu.cn/elect.'

        #request for the code
        self.req2 = urllib2.Request(self.codeurl, headers = self.headers)
        try:
            self.codepic = urllib2.urlopen(self.req2)
        except:
            print 'Can\'t get captcha'

        #get the code picture
        img = Image.open(StringIO(self.codepic.read()))
        img.show()

        #ask user to enter the code
        return raw_input('Plaease enter the code of the picture:')

    def login(self):
        try:
            self.setCookie()
        except:
            print 'Can\'t initialization.'

        self.logininfo['j_code'] = self.getCode()

        self.logindata = urllib.urlencode(self.logininfo)
        self.req3 = urllib2.Request(self.loginurl, self.logindata, self.headers)

        try:
            self.respose = urllib2.urlopen(self.req3)
        except:
            print 'Can\'t login in.'

    def pubclass(self):
        #get sid
        self.url = self.respose.geturl()
        self.start = self.url.find('sid=') + 4
        self.sid = self.url[self.start:]
		#'kclb': 30, 
        #set parameters
#       self.para = {'xnd':'2016-2017', 'xq': '1','sid': self.sid}
        self.para = {'sid': self.sid}
        self.courseurl = 'http://uems.sysu.edu.cn/elect/s/courseAll?sort=&ord=&' + urllib.urlencode(self.para)

        #request for the website which shows the list of public corses
        self.req4 = urllib2.Request(self.courseurl, headers = self.headers)
        try:
            self.respose2 = urllib2.urlopen(self.req4)
        except:
            print 'Can\'t get the courses list.'

    def getCourses(self):
        counter = 0
        self.pubclass()

        #use BeautifulSoup to get infomation of Courses
        self.soup = BeautifulSoup(self.respose2.read(), 'html.parser')
        #get all a tag
        self.alla = self.soup.find_all('tbody')[0].find_all('td')
        self.courses = []
	self.info = {}	
        #find valid a tag
        for a in self.alla:
            if counter == 0:
                self.info = {}
		self.info['year'] = a.string.split('-')[0]
                counter = counter + 1
            elif counter == 1:
                if a.string == u'第一学期':
                    self.info['term'] = 1
                elif a.string == u'第二学期':
                    self.info['term'] = 2
                else:
                    self.info['term'] = 3
                counter = counter + 1
            elif counter == 2:
                counter = counter + 1
            elif counter == 3:
                self.info['courseName'] = a.string
                counter = counter + 1
            elif counter == 4:
                if a.string == u'公必':
                    self.info['lessonType'] = 0
                elif a.string == u'专必':
                    self.info['lessonType'] = 1
                elif a.string == u'专选':
                    self.info['lessonType'] = 2
                else:
                    self.info['lessonType'] = 3
                counter = counter + 1
            elif counter == 5:
                self.info['credit'] = a.string
                counter = counter + 1
            elif counter == 6:
                counter = counter + 1
            elif counter == 7:
                #self.info['TimePlace'] = a.string
		if a.string is None:
		    self.info['WeekTimes'] = 1
		    self.info['StartTime'] = "|1"
		    self.info['EndTime'] = "|2"
		    self.info['Week'] = "|1"
		    self.info['Place'] = "|null"
		else:
		    WeekTimes = 0
		    StartTime = ''
		    EndTime = ''
		    Week =''
		    Place = ''
		    l0 = a.string
		    l1 = l0.split(',')
		    for x in l1:
		        WeekTimes = WeekTimes + 1
		        l2 = x.split('/')
		        x1=l2[0]
		        Week=Week+'|'
		        StartTime=StartTime+'|'
		        EndTime=EndTime+'|'
		        Place=Place+'|'
                        if x1[0:3] == u"星期一":
                            Week+='1'
                        elif x1[0:3] == u"星期二":
                            Week+='2'
                        elif x1[0:3] == u"星期三":
                            Week+='3'
                        elif x1[0:3] == u"星期四":
                            Week+='4'
                        elif x1[0:3] == u"星期五":
                            Week+='5'
                        elif x1[0:3] == u"星期六":
                            Week+='6'
                        elif x1[0:3] == u"星期日":
                            Week+='7'
                        x4=x1[4:]
			x5=x4.split(' ')
			x6=x5[0]
			x7=x6.split('-')
		        StartTime=StartTime+x7[0]
                        x8 = ((x7[1]).split(u'节'))[0]
	                EndTime=EndTime+x8
		        if len(l2) == 1:
		            Place=Place+'null' 
		        else:
		            x2 = ((l2[1]).split('（'))[0]
		            x3 = (x2.split('('))[0]
			    Place=Place+(x3)
		    self.info['WeekTimes'] = WeekTimes
		    self.info['StartTime'] = StartTime
		    self.info['EndTime'] = EndTime
		    self.info['Week'] = Week
		    self.info['Place'] = Place
                counter = counter + 1
            elif counter == 8:
                counter = counter +1
            elif counter == 9:
		if a.string is None:
                    self.info['teacherName'] = "null"
                else:
                    self.info['teacherName'] = a.string
                self.courses.append(self.info)
                del self.info
                counter = counter + 1
            elif counter == 13:
                counter = 0
            else:
                counter = counter + 1 

    def showCourses(self):

        #show courses list
        self.a = 0
        fObj=open('classes.json','w')
        line="\n"
        for classes in self.courses:
            #encode('GBK') because in cmd of windows, Chinese characters show well in this form
            print '{0:50}'.format(classes['courseName'].encode('utf-8')), classes['teacherName']
            jsObj=json.dumps(classes,encoding="UTF-8", ensure_ascii=False)
            fObj.write(jsObj)
            fObj.write(line)
            self.a = self.a + 1
#       x=json.loads(fObj)
#       f = csv.writer(open("test.csv", "wb+"))
#       for x in x:
#           f.writerow(x[]x["TimePlace"],x["term"],
        fObj.close()

username = raw_input('Please enter your username:')
password = raw_input('Please enter your password:')
pcl = PCL(username, password)
pcl.login()
pcl.getCourses()
pcl.showCourses()
