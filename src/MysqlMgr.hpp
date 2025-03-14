#pragma once
#include "data.hpp"
#include "MysqlDao.hpp"
#include "src/Singleton.hpp"

class MysqlMgr : public Singleton<MysqlMgr>{
    friend class Singleton<MysqlMgr>;
public:
    ~MysqlMgr();
    int RegUser(const std::string &name, const std::string &email, const std::string &pwd);
    bool CheckEmail(const std::string &name, const std::string &email);
    bool UpdatePwd(const std::string &name, const std::string &pwd);
    bool CheckPwd(const std::string &name, const std::string &pwd, UerInfo &info);
    std::shared_ptr<UserInfo> GetUser(int uid);
private:
    MysqlMgr();
    MysqlDao dao_;
};