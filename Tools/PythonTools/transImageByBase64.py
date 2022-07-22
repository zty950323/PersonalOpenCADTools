import base64

class transImageByBase64:
    imageFileName = ''
    ImageBase64 = ''
    
    def __init__(self, fileName) -> None:
        self.imageFileName = fileName
    
    def transToBase64(self) -> None:
        file = open(imageFileName, 'rb') #二进制方式打开图文件
        ls_file = base64.b64encode(file.read()) #读取文件内容，转换为base64编码
        file.close() #关闭文件
        print(ls_file) #打印转换后的字符串
        
    def transFromBase64(self) -> None:
        bs = ImageBase64.encode('utf-8')