#ifndef USABILITYCHECK_H
#define USABILITYCHECK_H

#include "../../includes/pch.h"


class UsabilityCheck : public QObject
{
    Q_OBJECT


    QString m_name;
    QString m_description;
    QString m_parentGroup;

    // check in lambda function
    std::function<void()> m_code;
public:

    explicit UsabilityCheck(QObject *parent = 0);

    UsabilityCheck& operator=(const UsabilityCheck& other);


    UsabilityCheck(const UsabilityCheck & other)
    {
        m_name = const_cast<UsabilityCheck&>(other).getName();
           m_description = const_cast<UsabilityCheck&>(other).getDescription();
              m_parentGroup = const_cast<UsabilityCheck&>(other).getParentGroup();
                 m_code = const_cast<UsabilityCheck&>(other).getCode();}

    explicit UsabilityCheck(QString name, QString description, QString parentGroup);

    void setName(const QString& i_name){m_name=i_name;}
    void setDescription(const QString& i_description){m_description = i_description;}
    void setParentGroup(const QString& i_parentName){m_parentGroup = i_parentName;}
    void setCode(const std::function<void()>& in_code){m_code = in_code;}

    const QString& getName(){return m_name;}
    const QString& getDescription(){return m_description;}
    const QString& getParentGroup(){return m_parentGroup;}
    std::function<void()>& getCode(){return m_code;}


};

#endif // USABILITYCHECK_H
