1.
	post的时候会出现
 	Access to XMLHttpRequest at '...' from origin 'null' has been blocked by CORS policy: Cross origin 
	requests are only supported for protocol schemes: http, data, chrome, chrome-extension, https.
	的错误信息。
	解决方法：
	右击chrome快捷方式，选择“属性”，在“快捷方式”下的“目标”中添加" --allow-file-access-from-files"(最前面有个空格)，重启chrome即可如下:
	"C:\Program Files (x86)\Google\Chrome\Application\chrome.exe" --allow-file-access-from-files   　　//注意有空格，关闭浏览器然后重启浏览器即可支持

2.
	windows系统在post之后会报错：this program cannot be run at dom mode  会返回乱码， mac系统不存在此问题。
 
