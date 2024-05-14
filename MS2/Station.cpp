// Name:Preet Bhagyesh Patel
// Seneca Student ID:132603226
// Seneca email:pbpatel48@myseneca.ca
// Date of completion:15 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
using namespace std;
namespace seneca {
   size_t Station::m_widthField = 0;
   size_t Station::id_generator = 0;
   Station::Station(const string& str){
      Utilities util;
      bool more = true;
      size_t next_pos = 0u;
      m_id = ++id_generator;
      m_name = util.extractToken(str, next_pos, more);
      m_serial = stoi(util.extractToken(str, next_pos, more));
      m_numInStock = stoi(util.extractToken(str, next_pos, more));
      m_widthField = (m_widthField < util.getFieldWidth()) ? util.getFieldWidth() : m_widthField;
      m_desc = util.extractToken(str, next_pos, more);
   }
   const std::string& Station::getItemName() const{
      return m_name;
   }
   size_t Station::getNextSerialNumber(){
      return m_serial++;
   }
   size_t Station::getQuantity() const{
      return m_numInStock;
   }
   void Station::updateQuantity(){
      (m_numInStock > 0) ? m_numInStock-- : 0;
   }
   void Station::display(std::ostream& os, bool full) const{
      os << setfill('0') << setw(3) << m_id << " | ";
      os << setfill(' ');
      os.setf(ios::left);
      os << setw(m_widthField) << m_name << " | ";
      os.unsetf(ios::left);
      os << setfill('0') << setw(6) << m_serial << " | ";
      os << setfill(' ');
      if (full) {
         os.setf(ios::right);
         os << setw(4) << m_numInStock << " | ";
         os.unsetf(ios::right);
         os.setf(ios::left);
         os << m_desc;
         os.unsetf(ios::left);
      }
      os << endl;
   }
}