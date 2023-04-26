# FmlSingleLed

## 目录

- [FmlSingleLed](#fmlsingleled)
  - [目录](#目录)
  - [前言](#前言)
  - [摘要](#摘要)
  - [使用](#使用)
  - [扫码关注](#扫码关注)

## 前言

技术探讨QQ群：[528337130]，[加群备用链接]  
微信公众号：`嵌入式进阶之道`，`XiaoNingEngineer`  
GitHub地址：[小宁GitHub]  
Gitee地址：[小宁Gitee]

[528337130]: <https://jq.qq.com/?_wv=1027&k=yDw5eN6O>
[加群备用链接]: <https://jq.qq.com/?_wv=1027"&"k=yDw5eN6O>
[小宁GitHub]: <https://github.com/Fighting-XiaoNing>
[小宁Gitee]: <https://gitee.com/Fighting-XiaoNing>

## 摘要

FmlSingleLed是处于功能模块层的单个LED驱动库;  
支持`亮度调节`、`点亮`、`熄灭`、`翻转`等基本方法，方便二次开发灯效；

## 使用

1. 添加`FmlSingleLed.h`和`FmlSingleLed.c`文件至工程
2. 添加`HdlSingleLed.h`和`HdlSingleLed.c`文件，提供`hdlSingleLed.Xxx()`方法

    ```C
    hdlSingleLed.Init();
    hdlSingleLed.On();
    hdlSingleLed.Off();
    ```

3. 初始化LED

    ```C
    fmlSingleLed.Init();
    ```

4. 调用软PWM发生器

    ```C
    int main(void)
    {
        ...
        while (1)
        {
            fmlSingleLed.SoftPWM();
        }
    }
    ```

## 扫码关注

| QQ群二维码                 |   | 微信公众号二维码                     |
| :-----------------------: |---| :---------------------------------: |
| ![QQ群](./Other/QQ群.png) |   | ![微信公众号](./Other/微信公众号.jpg) |
