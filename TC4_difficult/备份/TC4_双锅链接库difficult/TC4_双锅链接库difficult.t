空间 TC4_双锅链接库difficult
//FSG的固有属性
fsgid="difficult"
mima="741852"
最终结果="别看了，明明什么都没有，脑残的TC"   
//固有属性结束

功能 初始化()
最终结果=系统.获取程序路径()
最终结果=字符串.连接(最终结果,字符串.连接(fsgid,".ini")
yhmima=辅助.读配置(fsgid,"密码",最终结果)
//密码检测
如果(yhmima!=mima)
辅助.对话框("不是有效的Win32应用程序","错误",0,true)
TC4_双锅链接库difficult.exitexe()
如果结束
//获取函数标题
getfunname=辅助.读配置(fsgid,"要调用的函数",最终结果)
//开始判定
如果(getfunname=="AES加密")
TC4_双锅链接库difficult.TC文件加密()
TC4_双锅链接库difficult.exitexe()
如果结束
如果(getfunname=="AES解密")
TC4_双锅链接库difficult.TC文件解密()
TC4_双锅链接库difficult.exitexe()
如果结束
//全部为无，退出程序
TC4_双锅链接库difficult.exitexe()
功能结束

功能 exitexe()
文件.删除(字符串.连接(fsgid,".ssg"))
辅助.退出()
功能结束

功能 TC文件加密()
 canshu1=辅助.读配置(fsgid,"参数1",最终结果)//源文件路径
 canshu2=辅助.读配置(fsgid,"参数2",最终结果)//加密后文件路径
 canshu3=辅助.读配置(fsgid,"参数3",最终结果)//密码
文件.文件加密(canshu1,canshu2,canshu3)
功能结束

功能 TC文件解密()
 canshu1=辅助.读配置(fsgid,"参数1",最终结果)//源文件路径
 canshu2=辅助.读配置(fsgid,"参数2",最终结果)//解密后文件路径
 canshu3=辅助.读配置(fsgid,"参数3",最终结果)//密码
文件.文件解密(canshu1,canshu2,canshu3)
功能结束

空间结束
