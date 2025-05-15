#define COFFEE
#ifdef COFFEE

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>

class Coffee
{
    protected:
        std::string m_name;
        std::string m_size;
        std::string m_milk;
        int m_price;

    public:
        Coffee();

        void brewCoffee();
        void addMilk();

        std::string getName();
        std::string getSize();
        std::string getMilkType();
        int getPrice();

        void setSize(const std::string &newSize);
        void setMilkType(const std::string &newMilkType);
        
        virtual void makeCoffee();

        friend std::ostream& operator<<(std::ostream &outputStream, const Coffee &coffeeObject);
};

class Cappachino : public Coffee 
{
    public:
        Cappachino();
        void steamMilk();
        void frothMilk();
        void makeCoffee() override;
};

class Latte : public Coffee
{
    public:
        Latte();
        void steamMilk();
        void makeCoffee() override;
};

class Customer
{
    private:
        int m_walletMoney;
        std::vector<std::unique_ptr<Coffee>> m_drinksOrdered;

    public:
        Customer();

        bool payForOrder(int cost);
        void printAllOrders();
        void printLastOrder();
        void addDrinkToOrders(std::unique_ptr<Coffee> &&drink);
        void addFunds(int moneyAmount);
        int getWalletMoney();
};

#endif
