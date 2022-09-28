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

**==================================================**