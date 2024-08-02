#ifndef ORDER_H
#define ORDER_H

class Order : public Customer, public Item  //pollaplh klhronomikothta
{
   private:
     int orderNo;  //kwdikos paraggelias
     char orderDate[11];  //hmeromhnia paraggelias dd/mm/yyyy
     float totalAmount;  //synoliko poso agorwn
   public:
     Order();
     Order(int orderNo1, char orderDate1[], float totalAmount1, int custNo1, char custName1[], char custEmail1[], int itemNo1, char itemDesc1[], float itemPrice1);
     void readData(); //kalei prwta th readData() ths Customer kai meta zhta na plhktrologhthei to orderNo kai to orderDate
     void setData(int orderNo1, char orderDate1[], float totalAmount1, int custNo1, char custName1[], char custEmail1[], int itemNo1, char itemDesc1[], float itemPrice1);
     void printData();
     int getOrderNo();
     char* getOrderDate();
     float getTotalAmount();
     void buyItem(float price, int qty);  //pollaplasiazei thn posothta me th timh monados toy proiontos poy agorasthke kai athroizei thn aksia sto synoliko poso agorwn
     int shippingCost();  //an to synoliko poso agorwn>200 eyrw tote epistrefei 0 alliws +20 eyrw metaforika
};

#endif
