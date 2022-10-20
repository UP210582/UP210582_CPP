
# UP210582 Unit 2

## Excersice 1 (Rent)
<details open="open">
in this code you can calculate your tax depending of you annual rent of your home or another product depending of the pay you recive a tax respective of you annual rent and you give the sale 

in this code we can see that at the momento of starting to execute, it will ask the user for their annual income, from this, we have 5 different discounts, one of 5% this will be applied if the user pays less than 10,000, one of 15% this will be applied if the user pays less than 20,000, one of 20% if he pays less than 35,000, one of 30% if he pays less than 60,000 and another of 45% if he pays 60,000 or more, once the amount has been entered, the program will show the percentage of your taxes with respect to your annual payment, and also show the amount to be paid.

```c++
    //The user is asked for his annual income

    cout << "How much is your annual rent payment? $";
    cin >> montoRenta;

//The improvisation that will be made according to your annual payment is calculated

    if (montoRenta < 10000)
        descuento = 5;  
    else if (montoRenta < 20000)
        descuento = 15;
    else if (montoRenta < 35000)
        descuento = 20;
    else if (montoRenta < 60000)
        descuento = 30;
    else 
        descuento = 45;

    improviso=montoRenta * descuento / 100;

//the total of if improvised and the percentage that it occupies is printed

    cout << "You have to pay: $" << improviso << endl;
    cout << "Your tax is: " << descuento << "%" << endl;
```


Below you will see different tests with the code so you can observe its operation

Be the income with an entry of **$9000**
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Prueba1.png)

Be the income with an entry of **$19000**
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Prueba2.png)

Be the income with an entry of **$34000**
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Prueba3.png)

Be the income with an entry of **$59000**
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Prueba4.png)

Be the income with an entry of **$70000**
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Prueba5.png)
</details>

## Exersice 2 (Points)

Obtain if a user's score is unacceptable, acceptable and meritorious, in addition to indicating their bonus and how much it is equivalent to respectively depending on their score

```c++
    cout << "What is the user score? ";
    cin >> punto;

    //If the score is 0.0

    if(punto == 0.0){
        cout << "Your level is Unacceptable \n";
        beneficio = monto * punto;
            cout << "Your benefit is: $" << beneficio << endl;

    //If the score is 0.4

    }
    else if (punto == 0.4){
        cout << "Your level is Acceptable \n";
        beneficio = monto * punto;
            cout << "Your benefit is: $" << beneficio << endl;

    //If the score becomes greater than 1, it   cancels and asks the user to enter a valid score.

    }
    else if (punto > 1){
        cout << "Please enter a valid score" << endl;
    }

    //If the score is greater than or equal to 0.6 but not greater than 1

    else if (punto >= 0.6){
        cout << "Your level is Merit \n";
         beneficio = monto * punto;
             cout << "Your benefit is: $" << beneficio << endl;
    }

    //If none of the conditions are met, it will proceed to ask for a valid score

    else {
        cout << "Please enter a valid score" << endl;
    } 
```

### Explanation

The user will have a score which goes from 0.0 to 1, the existing scores are 0.0 being equal to 0, 0.4 being equivalent to 40%, and from 0.6 to 1, 1 being equal to 100%

Each score will be used to be multiplied by 2400 which is the bonus

Entering an intermediate value between 0.0 and 0.4 will give us a message which will tell us that this score is invalid, it also gives this message when entering an intermediate value between 0.4 and 0.6

### Test

Unacceptable

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Unacceptable.png)

Acceptable

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Acceptable4.png)

Merit

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Merit6.png)


![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Merit1.png)

Invalid

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Invalid.png)


## Exercise 3 (Price of park)

this program can give you the entrance price for a game park depending on the age of the user

```c++
    //question to know the age and capture it in a variable

    cout << "How old are you ";
    cin >> edad;

//process to calculate the price of admission to the park

    if (edad < 4)
        precio = 0;  
    else if (edad >= 4 && edad <= 18)
        precio = 5;
    else if (edad > 18)
        precio = 10;

//exit message about price and welcoming users

    cout << "You have to pay: $" << precio << endl;
    cout << "Welcome to Los Pollos Hermanos Games" << endl;

```

To make this calculation, the program takes the age from 0 to 3 for a free entrance to the park, from 4 to 18 an entrance with a cost of 5 dollars and an age older than 18 with a cost of 10 dollars.

### Test

Pay 0 bucks
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Edad5.png)

Pay 5 bucks
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Edad1.png)

Pay 5 bucks
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Edad2.png)

Pay 5 bucks
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Edad3.png)

Pay 10 bucks
![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Edad4.png)



## Exercise 4 (Create a Vegan Pizza or Regular Pizza)

In this program you will be able to choose between several ingredients for a pizza, the ingredients change depending on whether it is vegan or normal, it also comes with cheese and tomato sauce included, you can only choose one ingredient

```c++
     // asks the user about which pizza he wants

    cout << "What type of pizza do you want \n";
    cout << "Choose whit 1 and 2 \n";
    cout << "Vegetarian Pizza is 1 \n";
    cout << "Normal Pizza is 2 \n";
    cin >> typo;

    // if the user choose a Vegetarian pizza, get the all ingredients

    if (typo == 1)
    {
        cout << "You select a Vegetarian Pizza \n";
        cout << "Choose a ingredient \n";
        cout << "You can chose pepper or tofu \n";
        cout << "Choose whit 1 and 2 \n";
        cout << "Pepper is 1 \n";
        cout << "Tofu is 2 \n";
        cin >> ingredientes;

        // vegetarian pizza ingredients

        if (ingredientes == 1)
        {
            cout << "You choose pepper \n";
            cout << "And your pizza include Pepper, Soya cheese and Tomato sauce \n";
            cout << "\n";
        }
        else if (ingredientes == 2)
        {
            cout << "You choose Tofu \n";
            cout << "And your pizza include Tofu, Soya cheese and Tomato sauce \n";
            cout << "\n";
        }
    }

    // if the user choose a Regular pizza, get the all ingredients

    if (typo == 2)
    {
        cout << "You select a Normal Pizza \n";
        cout << "Choose a ingredient \n";
        cout << "You can chose pepperoni, ham or salmon \n";
        cout << "Choose whit 1, 2, 3 \n";
        cout << "Pepperoni is 1 \n";
        cout << "Ham is 2 \n";
        cout << "Salmon is 3 \n";
        cout << "\n";
        cin >> ingredientes;

        // regular pizza ingredients

        if (ingredientes == 1)
        {
            cout << "You choose pepperoni \n";
            cout << "And your pizza include Pepperoni, mozarella and Tomato sauce \n";
            cout << "\n";
        }
        else if (ingredientes == 2)
        {
            cout << "You choose ham \n";
            cout << "And your pizza include ham, mozarella and Tomato sauce \n";
            cout << "\n";
        }
        else if (ingredientes == 3)
        {
            cout << "You choose salmon \n";
            cout << "And your pizza include salmon, mozarella and Tomato sauce \n";
            cout << "\n";
        }
    }

    // message after assembling your pizza
    
    cout << "your pizza will be ready in less than an eagle sings \n";
    cout << "THANK YOU FOR visiting Pizzas Upa";
```

Once the order is taken, the console will print your chosen pizza as well as the ingredients assigned to it.

### Test

Vegan Pizza

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Pizza1.png)


Regular Pizza

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Pizza2.png)


## Exercise 5 (Temperature)
    
In this program 6 temperatures are requested, these will be used to calculate the average temperature, the highest temperature and the lowest temperature

```c++
     //Requesting the user's temperature
    cout << "Welcome to Farmacias UPA´s \n";

    do
    {
        cout << "Give me a temperature" << endl;
        cin >> temperatura;
        tempeAcum +=temperatura;

        contador ++;
        if (temperatura <= temperatura_min)
        {
            temperatura_min=temperatura;
        }
        if (temperatura >= temperatura_max)
        {
            temperatura_max=temperatura;
        }
    } while (contador <=6);
    //printing the average, maximum temperature and minimum temperature
    cout << "Today's average temperature is: " << tempeAcum/6 <<endl;
    cout << "The minimum temperature is: " << temperatura_min<< endl;
    cout << "The maximum temperature is: " << temperatura_max << endl;
```
To begin with, the user is welcomed, followed by this, the temperatures will be asked, for this, at the moment of giving the temperatures, they are being saved in a variable to be able to determine if they are higher or lower, at all times they are being compared and if it is greater than another, it is replaced and the largest is put, for the smallest it is the same way it is being saved in a variable and if the new temperature is lower than the previous one, it changes and is replaced by the new one

### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Temp.png)


## Exercise 6 (Prices)

in this program is from a store where they are asked for the number of products that it carries of the same product and then ask for its price and multiply it by the quantity of product that it carries, until giving the value of 0 in the amount of products


```c++
    //welcoming to the store
    cout << "Welcome to UxxA \n";

    do
    {
        //Asking for the quantity of products
        cout << "Give me the number of products \n";
        cin  >> producto;

        if (producto !=0 and producto >0){

            //Asking the price
            cout << "Tell me the price of the product \n";
            cin >> precio;

            //Making the calculation of the purchase by product
            total +=(precio*producto);
        }

    } while (producto != 0);

    //Printing the price of each of the products as well as the total of all products
    cout << "The total of your purchase is: \n" << total << endl;
```
For this, a do while was used, which does not help when the quantity of products is 0, each time the user enters a quantity of product, it is stored in a variable and is used later to multiply this by the price until the number of products is 0

### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Precios.png)


## Excersice 7 (Decimal to Binary)

now with this program you can convert from decimal to binary, you just have to enter the number to convert and it will give you in binary

```c++
    //Asking the user for the number in decimal
    cout << "Give me the number in decimal: \n";
    cin >> num, decimal;
    while (num != 0)
    {
        //Calculation of the number to convert it to binary
        resultado=(num%2==0)?"0"+resultado:"1"+resultado;
        num /= 2;
    }
    
    //printing the result in binary
    cout << "Result : " << resultado << endl;
```
For this, the user is asked for the decimal number to then divide it by 2 and in the division the remainder is taken and then added to the end of the binary, the number of times that the 2 fits in the number is taken again to then divide it again by 2 and then take its remainder again to add it to the binary

### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/DtB.png)

## Excersice 8 (Multiplication table)

now it is a multiplication table which is generated from the request of the number to multiply and the times that we are going to multiply it

```c++
    //A do to ask if you want another table
    do
    {
        //Asking the number to multiply
        cout << "Give me the number to multiply" << endl;
        cin >> numero;
        
        //Asking the times to multiply
        cout << "Give me the times I'm going to multiply it" << endl;
        cin >> limite;

        //printing the title of the table where the amount of times and the number are specified
        cout << "The multiplication table of: " << numero << " multiplied up: " << limite <<endl;

        //A for to be printing each row
        for (int i = 1; i <=limite; i++)
        {
            //A nested for to print the rows
            for (int j = 0; j <= 80; j++)
            {
                cout << "-";
            }
            //Information that will go inside each row and column
            cout<< "\n";
            cout << "|\t"<<i<<"\t|"<<"\tx\t"<<"|\t"<<numero<<"\t|"<<"\t=\t"<<"|\t"<<numero*i<<"\t|\n";
        }   
        //A for to be able to close the table
        for (int p = limite; p <=88; p++)
            {
                cout << "-";
            }
        //Ask to generate another table
        cout << "\n";
        cout <<  "Do you want another multiplication table? Y/N" << endl;
        cin >> follow;

    } while (follow != 'n');

```
for this, the number in question is requested to multiply this and then ask the user for the amount of times that it is going to multiply, using that everything is nested inside a do while to ask the user if he wants to generate another table, inside this puts what are 2 for in a for another one is nested for the creation of the lines and for later in the main for the multiplications are being generated as well as the vertical lines which will not help to delimit the table, they were used "\t" so that the table is justified and seen correctly, for the last horizontal line a for is used so that when it reaches the limit the horizontal line is printed and the table does not look ugly

### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Tabla.png)

# Exercise 9: Bisection method
## Input
```c++
    // Ask the user for the range
    cout << "Enter the value A: ";
    cin >> a;
    cout << "Enter the value B: ";
    cin >> b;
```
## Process
```c++
    do
    {
        // Obtain point c and Y(a), Y(b), Y(c)
        c = (a + b) / 2;
        ya = resolverEcuacion(a);
        yb = resolverEcuacion(b);
        yc = resolverEcuacion(c);
        // Print the results in a table
        cout << "| " << interador << "\t\t| " << fixed << setprecision(8) << a << "\t\t| " << b << "\t\t| " << c << "\t\t| " << ya << "\t\t| " << yb << "\t\t| " << yc << "\t\t| \n";
        imprimirlinea();

        // If you select which half to grab to return to get the point c and Y(a), Y(b), Y(c)
        if ((ya * yc) < 0)
        {
            b = c;
        }
        else {
            a=c;
        }
        if (a==b){
            solucion = 0;
            break;
        }
        /*  Metodo de clase
        else if ((yc * yb) < 0)
        {
            a = c;
        }
        else // If to prevent infinite cycling
        {
            solucion = 0;
            break;
        }
        */
        interador++;
    } while ( abs(yc)>= margen_error);
```
## Output
```c++
    // Print the root if there is
    if (solucion != 0)
    {
        cout << "The root is :" << c;
        cout << "\n";
    }
    else
    {
        cout << "There is no root in that range. \n";
    }

```
## Explanation.
1. Ask the user for the range (a and b).
2. Obtain the point c.
3. Get the y-values when its value is a, b and c.
4. If the Y(c) value is greater than or equal to 0.01 or less than or equal to -0.01 enter a while loop.  
4.1 Enter an If to select half.  
4.2 if ((ya * yc) < 0) then b=c, otherwise a=c.  
4.3 Get the y values with the new values.  
4.4 When Y(c) is between 0.01 and -0.01 exit the while.  
5. Print the root if there is
## Texts.
### When the root is within the established range.
![Refres the page to see the image](https://github.com/UP210052/UP210052_CPP/blob/main/imagenes/Img_25.png)

### When the root is not within the established range.
![Refres the page to see the image](https://github.com/UP210052/UP210052_CPP/blob/main/imagenes/Img_26.png)

