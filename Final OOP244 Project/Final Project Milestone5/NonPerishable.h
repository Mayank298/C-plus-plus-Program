#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__
#include "PosIO.h"
#include "Error.h"
#include "Item.h"
namespace ict {
   class NonPerishable : public Item{
   private: 
      Error m_err;
   protected:
      bool ok() const;
      void error(const char* message);
      virtual const char signature() const;
   public:
       std::fstream& save(std::fstream& file)const;
       std::fstream& load(std::fstream& file);
       std::ostream& write(std::ostream& os, bool linear)const;
       std::istream& read(std::istream& is) ;
   };
}
#endif