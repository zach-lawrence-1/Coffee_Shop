#include "coffee.h"

bool cinError(int &choice)
{
    if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
        choice = 0;
        return true;
    }

    return false;
}

int main () {
    Customer customer;
    int choice = 0;

    while (choice != 5)
    {
        //ansi escape codes for clearing screen and setting console position respectively
        std::cout << "\033[2J";
        std::cout << "\033[0;0H";

        std::cout << "You are in a coffeeshop, what would you like to do?:" << std::endl;
        std::cout << "1) Order a coffee" << std::endl;
        std::cout << "2) Add money to wallet with nearby ATM" << std::endl;
        std::cout << "3) See all previous orders you have made" << std::endl;
        std::cout << "4) See last order you have made" << std::endl;
        std::cout << "5) Leave" << std::endl;

        std::cin >> choice;

        if (cinError(choice))
            continue;

        if (choice == 1)
        {
            std::cout << "\033[2J";
            std::cout << "\033[0;0H";

            std::cout << "Pick a coffee to order:" << std::endl;
            std::cout << "1) Espresso" << std::endl;
            std::cout << "2) Cappachino" << std::endl;
            std::cout << "3) Latte" << std::endl;

            std::cin >> choice;

            if (cinError(choice))
                continue;

            std::unique_ptr<Coffee> drink = nullptr;

            switch (choice)
            {
                case 1:
                {
                    if (drink == nullptr)
                        drink = std::make_unique<Coffee>();
                    break;
                }
                case 2:
                {
                    if (drink == nullptr)
                        drink = std::make_unique<Cappachino>();
                    break;
                }
                case 3:
                {
                    if (drink == nullptr)
                        drink = std::make_unique<Latte>();
                    break;
                }
                default:
                    std::cout << "Not an option" << std::endl;
                    return 0;
            }

            choice = 0;

            while (choice == 0)
            {
                std::cout << "\033[2J";
                std::cout << "\033[0;0H";

                std::cout << "Pick a size:" << std::endl;
                std::cout << "1) Small" << std::endl;
                std::cout << "2) Medium" << std::endl;
                std::cout << "3) Large" << std::endl;

                std::cin >> choice;

                if (cinError(choice))
                    continue;

                switch (choice)
                {
                    case 1:
                        drink->setSize("Small");
                        break;
                    case 2:
                        drink->setSize("Medium");
                        break;
                    case 3:
                        drink->setSize("Large");
                        break;
                    default:
                        std::cout << "Not an option" << std::endl;
                        choice = 0;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        break;
                }
            }

            choice = 0;

            while (choice == 0)
            {
                std::cout << "\033[2J";
                std::cout << "\033[0;0H";

                std::cout << "Pick milk type:" << std::endl;
                std::cout << "1) None" << std::endl;
                std::cout << "2) Milk" << std::endl;
                std::cout << "3) Oat Milk" << std::endl;
                std::cout << "4) Almond Milk" << std::endl;

                std::cin >> choice;

                if (cinError(choice))
                    continue;

                switch (choice)
                {
                    case 1:
                        drink->setMilkType("None");
                        break;
                    case 2:
                        drink->setMilkType("Milk");
                        break;
                    case 3:
                        drink->setMilkType("Oat Milk");
                        break;
                    case 4:
                        drink->setMilkType("Almond Milk");
                        break;
                    default:
                        std::cout << "Not an option" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        choice = 0;
                        break;
                }
            }

            if (customer.payForOrder(drink->getPrice()))
            {
                drink->makeCoffee();
                customer.addDrinkToOrders(std::move(drink));
            }
            else
            {
                std::cout << "not enough money for the order" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        }
        else if (choice == 2)
        {
            int cashToAdd = 0;

            while (cashToAdd == 0)
            {
                std::cout << "\033[2J";
                std::cout << "\033[0;0H";

                std::cout << "How much money do you want to add to your wallet?" << std::endl;
                std::cout << "Money in wallet: $" << customer.getWalletMoney() << std::endl;
                
                std::cin >> cashToAdd;

                if (cinError(cashToAdd))
                    continue;

                if (cashToAdd <= 100 && cashToAdd > 0)
                {
                    customer.addFunds(cashToAdd);
                    std::cout << "Added $" << cashToAdd << " successfully" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }
                else
                {
                    std::cout << "Cannot add that amount" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    cashToAdd = 0;
                }
            }
        }
        else if (choice == 3)
        {
            std::cout << "All previous orders" << std::endl;
            customer.printAllOrders();
            std::string pause;
            std::cin >> pause;
        }
        else if (choice == 4)
        {
            customer.printLastOrder();
            std::string pause;
            std::cin >> pause;
        }
        else
        {
            return 0;
        }
    }
}