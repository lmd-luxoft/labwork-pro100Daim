#include "ipaddresswrapper.h"

IpAddressWrapper::IpAddressWrapper(QString addr, uint port)
    : addr_(addr)
    , port_(port)
{

}

QString IpAddressWrapper::addr() const
{
    return addr_;
}

uint IpAddressWrapper::port() const
{
    return port_;
}

bool IpAddressWrapper::operator==(const IpAddressWrapper& obj) const
{
    return (addr_ == obj.addr_) && (port_ == obj.port_);
}
