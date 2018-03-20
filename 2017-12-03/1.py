import re
import xlwt
import os

filenames = os.listdir('.')
count = 0
for name in filenames:
    print(name)
    if name == 'test.py' or name == 'result':
        continue
    f = open(name)
    #line = f.readline()
    filename = os.path.basename(f.name).split('.')
    print("Now converting %s" % filename[0])
    saveName = './result/' + filename[0][14:] + '.xls'

    sheetLine = sheetRow = 0
    workbook = xlwt.Workbook(encoding = 'ascii')
    worksheet1 = workbook.add_sheet(filename[0])
    worksheet2 = workbook.add_sheet("selected")
    number_style = xlwt.Style.easyxf(num_format_str="General")
    for line in f:
        sheetRow = 0
        current = re.split(r',+|:|\t|;| |\n',line)
        if sheetLine == 3:
            current.insert(4, '')
            current.insert(4, '')
        for value in current:
            worksheet1.write(sheetLine, sheetRow, value)
            if sheetLine >= 3:
                if sheetRow >= 0 and sheetRow <= 2:
                    worksheet2.write(sheetLine-3, sheetRow, value)
                elif sheetRow >= 7 and sheetRow <= 22:
                    worksheet2.write(sheetLine-3, sheetRow-4, value)
                elif sheetRow >= 37 and sheetRow <= 40:
                    worksheet2.write(sheetLine-3, sheetRow-18, value)
            sheetRow += 1

        sheetLine += 1

    workbook.save(saveName)
    f.close()
    count += 1
    print("%s convert finished, No.%d" % (filename[0], count))
