#ifndef IPADDRESSWRAPPER_H
#define IPADDRESSWRAPPER_H

#include <QString>
#include <QHash>

class IpAddressWrapper
{
public:
    IpAddressWrapper(QString addr, uint port);

    bool operator==(const IpAddressWrapper& obj) const;

    QString addr() const;
    uint port() const;
private:
    QString addr_;
    uint port_;
};

inline uint qHash(const IpAddressWrapper& key, uint seed)
{
    return qHash(key.addr(), seed) ^ key.port();
}

#endif // IPADDRESSWRAPPER_H
