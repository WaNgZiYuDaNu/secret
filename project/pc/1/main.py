import requests # 引入requsets库
response = requests.get('https://www.baidu.com/') # 不带参数的get请求
response.encoding = 'utf-8' # 用utf-8解码
#print(response.status_code)
#print(response.content)
print(response.text) 
#print(response.apparent_encoding)
#print(response.encoding)