//
// Generated file, do not edit! Created by nedtool 5.7 from custMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "custMsg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(custMsg)

custMsg::custMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->sourceId = 0;
    this->messageId = 0;
    this->ackMsgId = 0;
    this->senderId = 0;
    this->intendedReceiverId = 0;
    this->packetGenerateTime = 0;
    this->packetReachToSinkTime = 0;
    this->isRelayMsg = false;
    this->packetReachTime = 0;
    this->overheadDelay = 0;
}

custMsg::custMsg(const custMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

custMsg::~custMsg()
{
}

custMsg& custMsg::operator=(const custMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void custMsg::copy(const custMsg& other)
{
    this->sourceId = other.sourceId;
    this->messageId = other.messageId;
    this->ackMsgId = other.ackMsgId;
    this->senderId = other.senderId;
    this->intendedReceiverId = other.intendedReceiverId;
    this->packetGenerateTime = other.packetGenerateTime;
    this->packetReachToSinkTime = other.packetReachToSinkTime;
    this->isRelayMsg = other.isRelayMsg;
    this->packetReachTime = other.packetReachTime;
    this->overheadDelay = other.overheadDelay;
}

void custMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceId);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->ackMsgId);
    doParsimPacking(b,this->senderId);
    doParsimPacking(b,this->intendedReceiverId);
    doParsimPacking(b,this->packetGenerateTime);
    doParsimPacking(b,this->packetReachToSinkTime);
    doParsimPacking(b,this->isRelayMsg);
    doParsimPacking(b,this->packetReachTime);
    doParsimPacking(b,this->overheadDelay);
}

void custMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceId);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->ackMsgId);
    doParsimUnpacking(b,this->senderId);
    doParsimUnpacking(b,this->intendedReceiverId);
    doParsimUnpacking(b,this->packetGenerateTime);
    doParsimUnpacking(b,this->packetReachToSinkTime);
    doParsimUnpacking(b,this->isRelayMsg);
    doParsimUnpacking(b,this->packetReachTime);
    doParsimUnpacking(b,this->overheadDelay);
}

int custMsg::getSourceId() const
{
    return this->sourceId;
}

void custMsg::setSourceId(int sourceId)
{
    this->sourceId = sourceId;
}

int custMsg::getMessageId() const
{
    return this->messageId;
}

void custMsg::setMessageId(int messageId)
{
    this->messageId = messageId;
}

int custMsg::getAckMsgId() const
{
    return this->ackMsgId;
}

void custMsg::setAckMsgId(int ackMsgId)
{
    this->ackMsgId = ackMsgId;
}

int custMsg::getSenderId() const
{
    return this->senderId;
}

void custMsg::setSenderId(int senderId)
{
    this->senderId = senderId;
}

int custMsg::getIntendedReceiverId() const
{
    return this->intendedReceiverId;
}

void custMsg::setIntendedReceiverId(int intendedReceiverId)
{
    this->intendedReceiverId = intendedReceiverId;
}

double custMsg::getPacketGenerateTime() const
{
    return this->packetGenerateTime;
}

void custMsg::setPacketGenerateTime(double packetGenerateTime)
{
    this->packetGenerateTime = packetGenerateTime;
}

double custMsg::getPacketReachToSinkTime() const
{
    return this->packetReachToSinkTime;
}

void custMsg::setPacketReachToSinkTime(double packetReachToSinkTime)
{
    this->packetReachToSinkTime = packetReachToSinkTime;
}

bool custMsg::getIsRelayMsg() const
{
    return this->isRelayMsg;
}

void custMsg::setIsRelayMsg(bool isRelayMsg)
{
    this->isRelayMsg = isRelayMsg;
}

double custMsg::getPacketReachTime() const
{
    return this->packetReachTime;
}

void custMsg::setPacketReachTime(double packetReachTime)
{
    this->packetReachTime = packetReachTime;
}

double custMsg::getOverheadDelay() const
{
    return this->overheadDelay;
}

void custMsg::setOverheadDelay(double overheadDelay)
{
    this->overheadDelay = overheadDelay;
}

class custMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    custMsgDescriptor();
    virtual ~custMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(custMsgDescriptor)

custMsgDescriptor::custMsgDescriptor() : omnetpp::cClassDescriptor("custMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

custMsgDescriptor::~custMsgDescriptor()
{
    delete[] propertynames;
}

bool custMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<custMsg *>(obj)!=nullptr;
}

const char **custMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *custMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int custMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int custMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *custMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceId",
        "messageId",
        "ackMsgId",
        "senderId",
        "intendedReceiverId",
        "packetGenerateTime",
        "packetReachToSinkTime",
        "isRelayMsg",
        "packetReachTime",
        "overheadDelay",
    };
    return (field>=0 && field<10) ? fieldNames[field] : nullptr;
}

int custMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceId")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackMsgId")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderId")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "intendedReceiverId")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetGenerateTime")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetReachToSinkTime")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "isRelayMsg")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetReachTime")==0) return base+8;
    if (fieldName[0]=='o' && strcmp(fieldName, "overheadDelay")==0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *custMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "double",
        "double",
        "bool",
        "double",
        "double",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : nullptr;
}

const char **custMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *custMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int custMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    custMsg *pp = (custMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *custMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    custMsg *pp = (custMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string custMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    custMsg *pp = (custMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSourceId());
        case 1: return long2string(pp->getMessageId());
        case 2: return long2string(pp->getAckMsgId());
        case 3: return long2string(pp->getSenderId());
        case 4: return long2string(pp->getIntendedReceiverId());
        case 5: return double2string(pp->getPacketGenerateTime());
        case 6: return double2string(pp->getPacketReachToSinkTime());
        case 7: return bool2string(pp->getIsRelayMsg());
        case 8: return double2string(pp->getPacketReachTime());
        case 9: return double2string(pp->getOverheadDelay());
        default: return "";
    }
}

bool custMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    custMsg *pp = (custMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceId(string2long(value)); return true;
        case 1: pp->setMessageId(string2long(value)); return true;
        case 2: pp->setAckMsgId(string2long(value)); return true;
        case 3: pp->setSenderId(string2long(value)); return true;
        case 4: pp->setIntendedReceiverId(string2long(value)); return true;
        case 5: pp->setPacketGenerateTime(string2double(value)); return true;
        case 6: pp->setPacketReachToSinkTime(string2double(value)); return true;
        case 7: pp->setIsRelayMsg(string2bool(value)); return true;
        case 8: pp->setPacketReachTime(string2double(value)); return true;
        case 9: pp->setOverheadDelay(string2double(value)); return true;
        default: return false;
    }
}

const char *custMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *custMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    custMsg *pp = (custMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


