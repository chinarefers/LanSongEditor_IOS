# LanSongEditor_IOS
lansong  video  editor   ios version. crop cut overlay  filter beautiful compress merge and so on...
 蓝松科技的视频编辑SDK IOS版本Demo演示.
 
 ### 当前版本是2.3.8
*  增加分段录制,为每段设置录制的速度。
*  增加美颜举例, 美颜可以调节冷暖色;
*  应客户需求， 增加其他各种代码。

[更多版本日志](https://github.com/LanSoSdk/LanSongEditor_IOS/blob/master/%E7%89%88%E6%9C%AC%E6%9B%B4%E6%96%B0%E8%AE%B0%E5%BD%95.md)


	
### 注意:因为视频编辑用到GPU, 真机和模拟器的GPU差异太大, 当前我们的SDK 暂时只能在真机上运行, 请您知悉.

### 此SDK采用为收费授权,公司性质的合作,为了您项目更好的进行,欢迎和我们联系.谢谢!

### 容器和图层架构
*   一个工程是由多个线程组成, 又由各种类对象组成. 
*   我们把对视频处理的OpenGL技术处理后封装成 线程，命名为DrawPad(容器)
*   对视频处理用到的各种素材，封装成类，命名为Pen(图层的单词是Layer, 但'Layer'单词被IOS的UI使用了, 为了您开发不至于混淆,我们使用Pen作为图层的表示,仅仅单词不同,一样是图层的意思.)
*   这样视频处理的OpenGL线程中增加的各种类对象，就被抽象成 容器和图层的关系。和日常画画流程一致，方便您的使用。
*   容器：用来处理各种素材的线程，分为 [容器前台线程] 和 [容器后台线程], 您自由选择使用。
*   图层：编辑会用到的素材。包括：视频，图片，文字，音乐，麦克风，摄像头，裸数据，MV等。这些经过我们的核心技术处理，变成：视频图层， 		图片图层，UI图层，音乐图层，麦克风图层，数据图层，摄像头图层，MV图层等。
*   抽象类Pen：继承它的有：视频图层， 图片图层，UI图层，数据图层，摄像头图层，MV图层；均有：平移/缩放/旋转/隐藏/显示/RGBA调节的功能。
		另外他们各自也有独立的方法。
*   滤镜功能：具有滤镜属性的图层有：视频图层，图片图层，摄像头图层


比如您的操作是：
1.	把给视频增加滤镜： 则你增加视频图层到容器上， 然后调节VideoPen中的滤镜属性即可。

2.	再比如： 你要在视频中增加文字： 则你增加[视频图层]+[UI图层]到容器中，在处理过程中，实时的调节他们即可。

3.	再比如：你要拍照的同时增加滤镜，或增加图片或视频在四周环绕， 则您可以增加[摄像头图层]+[图片图层]或[视频图层]到容器上，图片设置到四周，视频用滤镜处理成中间透明，就实现您要的效果。

4.	再比如：你想生成一段文字或把炫酷的动画转换为视频，则可以直接增加[UI图层]到容器上。

5.	再比如：你想给视频实时增加说话声，则可以直接增加[Mic图层]，当然如果仅仅是剪切替换声音，则直接用VideoEditor类中的替换方法就可以。

											


### 更仅一步说:
*	1，你用 【视频图层 VideoPen】在 容器 DrawPad上作画， 就得到 调整后的视频

* 2，你用  【图片图层 BitmapPen】在容器上作画， 就得到 动态的照片影集。

*	3，你用 【UI图层  ViewPen】在容器上作画， 就是把精美的UI界面转换为视频， 当然我们的设计，也可以后台处理。

* 4， 你用 【视频图层】+ 【图片图层】 在容器上作画， 就得到动态的视频图片效果。

* 5， 你用  【视频图层】 + 【MV图层】 在容器上作画， 就是在视频中叠加MV的效果。

* 6， 当然： 容器 可以在前台工作， 也可以在后台处理。



### 下载地址: 
*  https://github.com/LanSoSdk/LanSongEditor_IOS

### 我们有android版本的SDK，欢迎你的评估使用：
*	android系统SDK--基本版本：https://github.com/LanSoSdk/LanSoEditor_common
*	android系统SDK--高级版本：https://github.com/LanSoSdk/LanSoEditor_advance

### 联系方式:
*   QQ 1852600324 
*   Email:support@lansongtech.com
*   网站: www.lansongtech.com
