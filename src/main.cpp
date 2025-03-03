#include <QGuiApplication>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickWindow>

int main(int argc,char* argv[])
{
    QGuiApplication app(argc,argv);
    QQmlEngine eng;
    QQmlComponent com(&eng);
    com.loadUrl(QUrl("qrc:/main.qml"));
    if(com.isError())
        qDebug()<<com.errorString();
    std::unique_ptr<QQuickWindow> ct(
        static_cast<QQuickWindow*>(com.create())
        );
    if(com.isError())
        qDebug()<<com.errorString();

    return app.exec();
}
