import requests
import json

def login_library(cardNo):

    login_url = 'http://202.116.65.85/library/CheckOverdueRecord.action'

    login_data = {

        'cardNo':cardNo

    }

    login_headers = {

        'Host': '202.116.65.85',

        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:49.0) Gecko/20100101 Firefox/49.0',

        'Referer': 'http://202.116.65.85/sysulib/',

        'Connection': 'keep-alive'

    }

    login_html = requests.post(login_url, data = login_data, headers = login_headers)

    return login_html

def update_record_status(login_html):

    login_json = json.loads(login_html.text)

    if login_json['resultNum']:

        print u'您没有过期记录，不需要做题'

    else:

        recordId = str(login_json['record']['id'])

        update_url = 'http://202.116.65.85/library/UpdateRecordStatus.action?recordId=' + recordId

        update_data = {'recordId':recordId}

        update_html = requests.get(update_url, cookies = login_html.cookies, data = update_data, headers = login_html.headers)

        update_json = json.loads(update_html.text)

        print update_json['record']['name'] + ' ' +update_json['record']['cardNo'] + ' ' + u'做题完成！'

if __name__ == '__main__':

    while True:

        cardNo = raw_input(u'请输入学号：')

        login_html = login_library(cardNo)

        update_record_status(login_html)
