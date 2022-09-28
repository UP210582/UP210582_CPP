*UP210582 Unit 2*

**excersice 1**

***Using if***

in this code you can calculate your tax depending of you annual rent of your home or another product depending of the pay you recive a tax respective of you annual rent and you give the sale 

in this code we can see that at the momento of starting to execute, it will ask the user for their annual income, from this, we have 5 different discounts, one of 5% this will be applied if the user pays less than 10,000, one of 15% this will be applied if the user pays less than 20,000, one of 20% if he pays less than 35,000, one of 30% if he pays less than 60,000 and another of 45% if he pays 60,000 or more, once the amount has been entered, the program will show the percentage of your taxes with respect to your annual payment, and also show the amount to be paid.

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

**=======================================================================================**

Exersice 2

Obtain if a user's score is unacceptable, acceptable and meritorious, in addition to indicating their bonus and how much it is equivalent to respectively depending on their score

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

### Explanation

The user will have a score which goes from 0.0 to 1, the existing scores are 0.0 being equal to 0, 0.4 being equivalent to 40%, and from 0.6 to 1, 1 being equal to 100%

Each score will be used to be multiplied by 2400 which is the bonus

Entering an intermediate value between 0.0 and 0.4 will give us a message which will tell us that this score is invalid, it also gives this message when entering an intermediate value between 0.4 and 0.6

### Test

Unacceptable

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Unacceptable.png)

Acceptable

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Acceptable.png)

Merit

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Merit6.png)


![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Merit1.png)

Invalid

![Refres the page to see the image](https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/Invalid.png)

