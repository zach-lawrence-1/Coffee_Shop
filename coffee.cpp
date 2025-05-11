#include "coffee.h"

Coffee::Coffee() : name("Espresso"), size("Medium"), milk("None"), price(2) {};

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
    if (this->milk != "None")
        std::cout << "Added " << this->milk << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

std::string Coffee::getSize()
{
    return this->size;
}

std::string Coffee::getMilkType()
{
    return this->milk;
}

int Coffee::getPrice()
{
    return this->price;
}

void Coffee::setSize(const std::string &newSize)
{
    this->size = newSize;
}    

void Coffee::setMilkType(const std::string &newMilkType)
{
    this->milk = newMilkType;
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
    outputStream << std::endl << "===============" << std::endl << "Drink Type: " << coffeeObject.name <<
    std::endl << "----------------" << std::endl << "Milk Type: " << coffeeObject.milk <<
    std::endl << "---------------" << std::endl << "Drink Size: " << coffeeObject.size << 
    std::endl << "---------------" << std::endl << "Drink price: " << coffeeObject.price <<
    std::endl << "===============" << std::endl;
    return outputStream;
}

Cappachino::Cappachino()
{
    this->name = "Cappachino";
    this->milk = "Milk";
    this->price = 4;
}

//TODO: add some kind of animation and timer
void Cappachino::steamMilk()
{
    if (this->milk != "None")
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
    if (this->milk != "None")
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
    this->name = "Latte";
    this->milk = "Milk";
    this->price = 3;
}

//TODO: add some kind of animation and timer
void Latte::steamMilk()
{
    if (this->milk != "None")
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

Customer::Customer() : walletMoney(9) {};

bool Customer::payForOrder(int cost)
{
    if (walletMoney >= cost)
    {
        walletMoney -= cost;
        return true;
    }
    return false;
}

void Customer::printAllOrders()
{
    if (drinksOrdered.empty())
        std::cout << "No orders made yet, press any key..." << std::endl;
    
    for (auto iter = drinksOrdered.begin(); iter != drinksOrdered.end(); iter++)
    {
        std::cout << (*(*iter));
    }
}

void Customer::printLastOrder()
{
    if (!drinksOrdered.empty())
    {
        auto drinkIterator = drinksOrdered.begin() + (drinksOrdered.size() - 1);
        std::cout << "Last Order: " << std::endl << (*(*drinkIterator));
    }
    else
        std::cout << "No orders made yet, press any key..." << std::endl;
}

void Customer::addDrinkToOrders(std::unique_ptr<Coffee> &&drink)
{
    this->drinksOrdered.push_back(std::move(drink));
}

void Customer::addFunds(int moneyAmount)
{
    this->walletMoney += moneyAmount;
}

int Customer::getWalletMoney()
{
    return this->walletMoney;
}