#include "shamir.hpp"
#include <random>

InfInt Shamir::pow(int a, int b)
{
    if(b == 0)
        return 1;
    InfInt ret(a);
    for(int i = 1;i < b;i++)
        ret *= a;
    return ret;
}

InfInt Shamir::bitString(std::string &str)
{
    InfInt ret;
    for(auto value : str)
    {
        ret += (u_char)value;
        ret *= 256;
    }
    return ret;
}

std::string Shamir::toBitString(InfInt i)
{
    std::string str;
    while(i > 0)
    {
        str.push_back((char)(i%256).toInt());
        i/=256;
    }
    return str;
}

InfInt Shamir::getShare()
{
    InfInt ret;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0);
    for(int i = 0;i < 4;i++)
    {
        ret *= INT_MAX;
        ret += dist(rd);
    }
    return ret;
}

void Shamir::split(std::string &key, InfInt *piecestreams)
{
    InfInt shares[required];
    shares[0] = bitString(key);
    for(int i = 0;i < required-1;i++)
        shares[i+1] = getShare();
    InfInt points[produced];
    for(int i = 0;i < produced;i++)
    {
        for(int x = 0;x < required;x++)
            points[i]+=(shares[x]*pow((i+1),x));
    }
    for(int i = 0;i < produced;i++)
        piecestreams[i] = points[i];
}

void Shamir::glue(InfInt *shares, int *parts, std::string &key)
{
    InfInt keyInt(1); // кажется, в имплементации больших чисел существует сильная погрешность. это позволяет восстановить ключ (вроде-бы) гарантированно?
    for(int i = 0;i < required;i++)
    {
        InfInt y = shares[i];
        for(int j = 0;j < required;j++)
            if(i != j)
            {
                std::cout << y << " ";
                int denom = parts[i]-parts[j];
                std::cout << denom << " ";
                y*=(-parts[j]);
                std::cout << y << " ";
                y/=denom;
                std::cout << y << std::endl;
            }
        std::cout << std::endl;
        keyInt += y;
    }
    std::cout << keyInt << " " << keyInt%prime << std::endl;
    std::string buf = toBitString(keyInt%prime);
    std::cout << buf << std::endl;
    key = std::string(buf.rbegin(),buf.rend());
}