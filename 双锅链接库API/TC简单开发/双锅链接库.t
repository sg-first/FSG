空间 双锅链接库

功能 获取路径(fsgid,num)
    路径=系统.获取程序路径()
    路径=字符串.连接(路径,fsgid)
    如果(num==1)
        路径=字符串.连接(路径,".ini")
        返回 路径
    如果结束
    如果(num==2)
        路径=字符串.连接(路径,".ssg")
        返回 路径
    如果结束
    如果(num==3)
        路径=字符串.连接(路径,".fsg")
        返回 路径
    如果结束
功能结束

功能 调用(fsgid,参数1,密码,要调用的函数)
    ini路径=双锅链接库.获取路径(fsgid,1)
    fsg路径=双锅链接库.获取路径(fsgid,3)
    ssg路径=双锅链接库.获取路径(fsgid,2)
    文件句柄=文件.创建(ssg路径,"读写")
    文件句柄2=文件.创建(ini路径,"读写")
    文件.关闭(文件句柄)
    文件.关闭(文件句柄2)
    辅助.写配置(fsgid,"密码",密码,ini路径)
    辅助.写配置(fsgid,"要调用的函数",要调用的函数,ini路径)
    辅助.写配置(fsgid,"参数1",参数1,ini路径)
    进程.打开(fsg路径)
    返回 真
功能结束

功能 阻滞(fsgid)
    ssg路径=双锅链接库.获取路径(fsgid,2)
    阻止循环=1
    循环(阻止循环==1)
        是否存在=文件.是否存在(ssg路径)
        如果(是否存在)
        否则
            返回 真
        如果结束
    循环结束
    返回 假
功能结束

功能 清除缓存(fsgid)
    ini路径=双锅链接库.获取路径(fsgid,1)
    文件.删除(ini路径)
    返回 真
功能结束

功能 读返回值(fsgid)
    ini路径=双锅链接库.获取路径(fsgid,1)
    返回 辅助.读配置(fsgid,"返回值",ini路径)
功能结束

功能 简单调用(fsgid,参数1,密码,要调用的函数)
    ini路径=双锅链接库.获取路径(fsgid,1)
    双锅链接库.调用(fsgid,参数1,密码,要调用的函数)
    双锅链接库.阻滞(fsgid)
    返回值=辅助.读配置(fsgid,"返回值",ini路径)
    双锅链接库.清除缓存(fsgid)
    返回 返回值
功能结束

空间结束