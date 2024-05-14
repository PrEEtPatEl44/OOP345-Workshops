// Name:Preet Bhagyesh Patel
// Seneca Student ID:132603226
// Seneca email:pbpatel48@myseneca.ca
// Date of completion:15 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
using namespace std;
namespace seneca{
   char Utilities::m_delimiter = ' ';
   void Utilities::setFieldWidth(size_t newWidth)
   {
      m_widthField = newWidth;
   }
   size_t Utilities::getFieldWidth() const
   {
      return m_widthField;
   }
   string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
   {
      string token;
      size_t found = str.find(m_delimiter, next_pos);
      token = str.substr(next_pos, found - next_pos);
      trim(token);
      if (found == next_pos) {
         more = false;
         string e = "Error: A delimiter is found at " + next_pos;
         throw (e);
      }
      else if (found != string::npos) {
         next_pos = found + 1;
         more = true;
      }
      else {
         more = false;
      }
      m_widthField = (m_widthField < token.length()) ? token.length() : m_widthField;
      
      return token;
   }
   void Utilities::setDelimiter(char newDelimiter)
   {
      m_delimiter = newDelimiter;
   }
   char Utilities::getDelimiter()
   {
      return m_delimiter;
   }
   string& Utilities::trim(string& s)
   {
      s.erase(0, s.find_first_not_of(" "));  
      s.erase(s.find_last_not_of(" ") + 1);  
      return s;
   }
}
