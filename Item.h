#ifndef ITEM_H
#define ITEM_H
#define M 21

class Item
{
   protected:
      int itemNo;  //kwdikos proiontos
      char itemDesc[M];  //perigrafh proiontos
      float itemPrice;  //timh monados proiontos
   public:
      Item();  
      Item(int itemNo1, char itemDesc1[], float itemPrice1);
      void readData();
      void setData(int itemNo1, char itemDesc1[], float itemPrice1);
      void printData();
      int getItemNo();
      char* getItemDesc();
      float getItemPrice();

};

#endif
