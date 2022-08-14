/*
 银行账户
 
    彭寒冰
    2019-4-30 18:51
*/
#include <iostream>
#include <string>

using namespace std;

class SavingAccount
{
private:
    static double m_AnnualInterestRate; //年利率
    
    string m_Name; //储户姓名
    unsigned long long int m_Balance; //当前余额，单位：分

public:
    static bool ModifyInterestRate(double rate); //重设利率
    
    SavingAccount(string name, unsigned long long int balance);
    
    unsigned long long int CalculateMonthlyInterest(); //计算月利率
    void Show();
    bool Save(unsigned long long int amount); //存款
    bool Withdraw(unsigned long long int amount); //取款
    
    friend ostream & operator<<(ostream & os, SavingAccount account);
    SavingAccount operator+(double amount);
    SavingAccount operator-(double amount);
};

double SavingAccount::m_AnnualInterestRate = 0.03;

SavingAccount::SavingAccount(string name, unsigned long long int balance)
{
    m_Name = name;
    m_Balance = balance;
}

bool SavingAccount::ModifyInterestRate(double rate)
{
    m_AnnualInterestRate = rate;
    return true;
}

unsigned long long int SavingAccount::CalculateMonthlyInterest()
{
    return (unsigned long long) (m_Balance * m_AnnualInterestRate / 12);
}

void SavingAccount::Show()
{
    cout << "姓名：" << m_Name << "\n"
         << "余额：" << m_Balance/100. << "元\n"
         << "年利率：" << m_AnnualInterestRate * 100. << "%\n"
         << "月利息：" << CalculateMonthlyInterest()/100. << "元" << endl;
    return;
}

bool SavingAccount::Save(unsigned long long amount)
{
    m_Balance += amount;
    return true;
}

bool SavingAccount::Withdraw(unsigned long long amount)
{
    if (m_Balance < amount)
        return false;
    m_Balance -= amount;
    return true;
}

ostream & operator<<(ostream & os, SavingAccount account)
{
    os << "姓名：" << account.m_Name << "\n"
         << "余额：" << account.m_Balance/100. << "元\n"
         << "年利率：" << account.m_AnnualInterestRate * 100. << "%\n"
         << "月利息：" << account.CalculateMonthlyInterest()/100. << "元" << endl;
    return os;
}

SavingAccount SavingAccount::operator+(double amount)
{
    return SavingAccount(m_Name, m_Balance + (unsigned long long)(amount * 100));
}

SavingAccount SavingAccount::operator-(double amount)
{
    return SavingAccount(m_Name, m_Balance - (unsigned long long)(amount * 100));
}

int main()
{
    SavingAccount account1("Mavis", 300000);
    SavingAccount account2("Bradley", 500000);
    
    SavingAccount::ModifyInterestRate(0.03);
    
    cout << account1 << account2;
    
    account1.Save(200000);
    account2.Withdraw(150000);
    
    cout << account1 << account2;
    
    SavingAccount::ModifyInterestRate(0.025);
    
    cout << account1 << account2;
    
    return 0;
}