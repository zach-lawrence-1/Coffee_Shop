#include "coffee.h"

Coffee::Coffee() : m_name("Espresso"), m_size("Medium"), m_milk("None"), m_price(2) {};

//TODO: add some kind of animation and timer
void Coffee::brewCoffee()
{
    std::cout << "Brewing Coffee" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Brewed" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

//TODO: add some kind of animation and timer
void Coffee::addMilk()
{
    if (m_milk != "None")
        std::cout << "Added " << m_milk << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

std::string Coffee::getSize()
{
    return m_size;
}

std::string Coffee::getMilkType()
{
    return m_milk;
}

int Coffee::getPrice()
{
    return m_price;
}

void Coffee::setSize(const std::string &newSize)
{
    m_size = newSize;
}    

void Coffee::setMilkType(const std::string &newMilkType)
{
    m_milk = newMilkType;
}

void Coffee::makeCoffee()
{
    brewCoffee();
    addMilk();
    std::cout << "Coffee Ready!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

std::ostream& operator<<(std::ostream &outputStream, const Coffee &coffeeObject)
{
    outputStream << std::endl << "===============" << std::endl << "Drink Type: " << coffeeObject.m_name <<
    std::endl << "----------------" << std::endl << "Milk Type: " << coffeeObject.m_milk <<
    std::endl << "---------------" << std::endl << "Drink Size: " << coffeeObject.m_size << 
    std::endl << "---------------" << std::endl << "Drink price: " << coffeeObject.m_price <<
    std::endl << "===============" << std::endl;
    return outputStream;
}

Cappachino::Cappachino()
{
    m_name = "Cappachino";
    m_milk = "Milk";
    m_price = 4;
}

//TODO: add some kind of animation and timer
void Cappachino::steamMilk()
{
    if (m_milk != "None")
    {
        std::cout << "Steaming milk" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Steamed" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

//TODO: add some kind of animation and timer
void Cappachino::frothMilk()
{
    if (m_milk != "None")
    {
        std::cout << "frothing milk" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "frothed" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Cappachino::makeCoffee()
{
    brewCoffee();
    steamMilk();
    frothMilk();
    addMilk();
    std::cout << "Cappachino Ready!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

Latte::Latte()
{
    m_name = "Latte";
    m_milk = "Milk";
    m_price = 3;
}

//TODO: add some kind of animation and timer
void Latte::steamMilk()
{
    if (m_milk != "None")
    {
        std::cout << "Steaming milk" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Steamed" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

//TODO: add some kind of animation and timer
void Latte::makeCoffee()
{
    brewCoffee();
    steamMilk();
    addMilk();
    std::cout << "Latte Ready!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

Customer::Customer() : m_walletMoney(9) {};

bool Customer::payForOrder(int cost)
{
    if (m_walletMoney >= cost)
    {
        m_walletMoney -= cost;
        return true;
    }
    return false;
}

void Customer::printAllOrders()
{
    if (m_drinksOrdered.empty())
        std::cout << "No orders made yet, press any key..." << std::endl;
    
    for (auto iter = m_drinksOrdered.begin(); iter != m_drinksOrdered.end(); iter++)
    {
        std::cout << (*(*iter));
    }
}

void Customer::printLastOrder()
{
    if (!m_drinksOrdered.empty())
    {
        auto drinkIterator = m_drinksOrdered.begin() + (m_drinksOrdered.size() - 1);
        std::cout << "Last Order: " << std::endl << (*(*drinkIterator));
    }
    else
        std::cout << "No orders made yet, press any key..." << std::endl;
}

void Customer::addDrinkToOrders(std::unique_ptr<Coffee> &&drink)
{
    m_drinksOrdered.push_back(std::move(drink));
}

void Customer::addFunds(int moneyAmount)
{
    m_walletMoney += moneyAmount;
}

int Customer::getWalletMoney()
{
    return m_walletMoney;
}
