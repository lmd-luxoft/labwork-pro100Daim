#include <QDebug>
#include "ipaddresswrapper.h"

int main()
{
    QHash<IpAddressWrapper, QString> my_hash;
    my_hash.insert({"127.0.0.1", 2020}, "localhost/vs");
    my_hash.insert({"127.0.0.1", 3030}, "localhost/vbox");
    my_hash.insert({"8.8.8.8", 8080}, "google.com");

    for(auto i : my_hash)
    {
        qDebug() << i;
    }
}
