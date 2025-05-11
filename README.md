# Coffee Shop
## About the project
I decided to do some practice with object oriented programming concepts and make a simple coffee shop.
The concepts implemented include encapsulation where name, size, milk, and price are stored in the base class Coffee, abstraction where Customer class cannot see inside of Coffee class but it can still interact with it through Coffee methods, inheritance where the derived classes Latte and Cappachino inherit from Coffee class, and polymorphism since the derived classes can override the makeCoffee method in the coffee class.

## How To Run
### Downloading The Code
Download the code and make file as follows
Git:
1. ```git clone https://github.com/zach-lawrence-1/Coffee_Shop.git c```
   - c can be any local directory you want.
2. ```cd c```

OR

Just download zip from github and unzip where you want
### Windows
On windows, as long as you have MSYS2 setup with g++ and you can run make files then you should be able to run the main program as follows:
1. Download code and make file.
2. Open a terminal in the same directory as the code and make file.
3. Type in ```make``` or ```make coffee```
4. run ```./coffee.exe``` or ```./coffee```
