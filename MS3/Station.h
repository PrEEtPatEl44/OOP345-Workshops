// Name:Preet Bhagyesh Patel
// Seneca Student ID:132603226
// Seneca email:pbpatel48@myseneca.ca
// Date of completion:15 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include "Utilities.h"
namespace seneca {
   class Station{
      size_t m_id{};
      std::string m_name{};
      size_t m_serial{};
      size_t m_numInStock{};
      std::string m_desc{};
      static size_t m_widthField;
      static size_t id_generator;
   public:
      Station(const std::string& str);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
   };
}
#endif