import QtQuick
import myvideo
import QtQuick.Controls

Window
{
    width: 1280
    height: 720
    visible: true
    MyVideo
    {
        id:myvideo
        anchors.fill: parent
        onReadEnd:
        {
            print("onreadEnd")
            myvideo_timer.stop()
        }

        Timer
        {
            id:myvideo_timer
            interval: 40//40ms
            running: false
            repeat: true
            property int count: 0
            onTriggered:
            {
                //读取一帧视频
                var frame = myvideo.readFrame()
                if(!frame) return;
                print(frame)
                myvideo.paintFrame(frame)
                //渲染视频
                count++
                //print(count)
            }
        }
        Button
        {
            text:"text"
            onClicked:
            {
                //打开视频
                myvideo.open("video.mp4")
                //启动定时器
                myvideo_timer.start()
            }
        }
    }
}
