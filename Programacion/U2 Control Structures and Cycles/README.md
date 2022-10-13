*UP210582 Unit 2*

## Excersice 1 (Rent)

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
### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Temp.png)


## Exercise 6 (Prices)

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
### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Precios.png)

## Exercise 7 (Binary to Decimal)

```c++
     //Asking user for number in binary
   cout << "Introduce numero: ";
   cin >> binario;
   exp=0;
   decimal=0;

    //at the moment of giving 0 in the division it goes directly to print the result
   while(((int)(binario/10))!=0)
   {
           digito = (int)binario % 10;
           decimal = decimal + digito * pow(2.0,exp);
           exp++;
           binario=(int)(binario/10);
   }

    //This part prints the result and shows it to you in decimal
   decimal=decimal + binario * pow(2.0,exp);
   cout << endl << "Decimal: " << decimal << endl;
```
### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/BtD.png)

## Excersice 7.1 (Decimal to Binary)

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
### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/DtB.png)

## Excersice 8 (Multiplication table)
    ```c++
    do
    {
        cout << "Give me the number to multiply" << endl;
        cin >> numero;

        cout << "Give me the times I'm going to multiply it" << endl;
        cin >> limite;

        cout << "The multiplication table of: " << numero << " multiplied up: " << limite <<endl;

        for (int i = 1; i <=limite; i++)
        {
            for (int j = 0; j <= 80; j++)
            {
                cout << "-";
            }
            cout<< "\n";
            cout << "|\t"<<i<<"\t|"<<"\tx\t"<<"|\t"<<numero<<"\t|"<<"\t=\t"<<"|\t"<<numero*i<<"\t|\n";
        }   
        for (int p = limite; p <=90; p++)
            {
                cout << "-";
            }
        
        cout << "\n";
        cout <<  "Do you want another multiplication table? Y/N" << endl;
        cin >> follow;

    } while (follow != 'n');
    ```
### Test

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Tabla.png)

