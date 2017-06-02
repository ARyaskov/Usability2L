#include "../../includes/U2L/usabilitycheck.h"

UsabilityCheck::UsabilityCheck(QObject *parent) :
    QObject(parent), m_name("EmptyName"),
    m_description("EmptyDesc"), m_parentGroup("EmptyParentGroup"),
    m_code([&]{qDebug() << "Empty lambda";})
{
}

UsabilityCheck::UsabilityCheck(QString name, QString description, QString parentGroup)
{
    setName(name);
    setDescription(description);
    setParentGroup(parentGroup);
}


UsabilityCheck& UsabilityCheck::operator=(const UsabilityCheck& other)
{
    UsabilityCheck uc;
    uc.setName(const_cast<UsabilityCheck&>(other).getName());
    uc.setDescription(const_cast<UsabilityCheck&>(other).getDescription());
    uc.setParentGroup(const_cast<UsabilityCheck&>(other).getParentGroup());
    uc.setCode(const_cast<UsabilityCheck&>(other).getCode());
    UsabilityCheck& check(uc);
    return check;
}
