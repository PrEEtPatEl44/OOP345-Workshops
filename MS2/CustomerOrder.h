// Name:Preet Bhagyesh Patel
// Seneca Student ID:132603226
// Seneca email:pbpatel48@myseneca.ca
// Date of completion:23 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include "Utilities.h"
#include "Station.h"
namespace seneca {
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };

        Item(const std::string& src) : m_itemName(src) {};
    };
   class CustomerOrder
   {
      std::string m_name{};
      std::string m_product{};
      size_t m_cntItem{};
      Item** m_lstItem{};
      static size_t m_widthField;
   public:
      CustomerOrder() {};
      CustomerOrder(const std::string& other);
      CustomerOrder(const CustomerOrder& src);
      CustomerOrder& operator=(const CustomerOrder& src) = delete;
      CustomerOrder(CustomerOrder&& src) noexcept;
      CustomerOrder& operator=(CustomerOrder&& src) noexcept;
      ~CustomerOrder();
      void deallocate();
      bool isOrderFilled() const;
      bool isItemFilled(const std::string& itemName) const;
      void fillItem(Station& station, std::ostream& os);
      void display(std::ostream& os) const;
   };
}
#endif