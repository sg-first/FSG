变量 线程ID
//从这里开始执行

var path

function getpar(varname)
    return 文件读配置("HTML应用框架",varname,字符串拼接(path,"HTML应用框架.ini"))
end

功能 TC5_HTML应用框架_初始化()
    path=系统获取工作路径()
    if("HTML应用框架"!=getpar("要调用的函数")||"741852"!=getpar("密码"))
        exit()
    end
    var 宽=转整型(getpar("参数1"))
    var 高=转整型(getpar("参数2"))
    
    var handl=窗口获取自我句柄()
    窗口设置大小(handl,宽,高)
    var webhandl=控件获取句柄("浏览器0")
    窗口设置大小(webhandl,宽,高)
    
    var 窗口宽,窗口高
    系统获取分辨率(窗口宽,窗口高)
    var x=(窗口宽-宽)/2
    var y=(窗口高-高)/2
    窗口设置位置(handl,x,y)
    
    窗口设置标题(handl,getpar("参数4"))
    网页跳转("浏览器0",字符串拼接(path,getpar("参数3")))
结束
