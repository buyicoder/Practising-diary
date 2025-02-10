// dma.cpp --dma class methods

#include "dma.h"
#include <cstring>

//dmaABC methods
dmaABC::dmaABC(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}
dmaABC::dmaABC(const dmaABC & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

dmaABC::~dmaABC()
{
    delete [] label;
}

dmaABC & dmaABC::operator=(const dmaABC & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const dmaABC & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}
void dmaABC::View(){
	std::cout<< "Label: " << label << std::endl;
    std::cout<< "Rating: " << rating << std::endl;
};

// baseDMA methods
baseDMA::baseDMA(const char * l, int r):dmaABC(l,r)
{};
    

baseDMA::baseDMA(const baseDMA & rs):dmaABC(rs)
{};

baseDMA::~baseDMA()
{};

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    dmaABC::operator=(rs);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os<<(const dmaABC &)rs;
    return os;
}
void baseDMA::View(){
	dmaABC::View();
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : dmaABC(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
    : dmaABC(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const dmaABC &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}
void lacksDMA::View(){
	dmaABC::View();
	std::cout<<"Color: "<<color<<std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
         : dmaABC(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
         : dmaABC(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : dmaABC(hs)  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    dmaABC::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const baseDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}
void hasDMA::View(){
	dmaABC::View();
	std::cout << "Style: " << style << std::endl;
}

