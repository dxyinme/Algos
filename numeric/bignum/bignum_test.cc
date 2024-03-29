#include "baselib/log.hpp"
#include "baselib/minitest.hpp"
#include "numeric/bignum/bignum.hpp"

int main()
{
     using namespace bignum;
     using namespace baselib;

     Int a(1000), b(1000);
     a.Set("50234782835793949482934304034093482482346235");
     Outf("a=%s", a.ToString().c_str());
     b.Set("7234792357325359239848394023492357365949487");
     Outf("b=%s", b.ToString().c_str());
     a.Add(b);
     Outf("%s + %s = %s",
          "50234782835793949482934304034093482482346235",
          "7234792357325359239848394023492357365949487",
          a.ToString().c_str());

     a.Set("100342309489574300000000000000000000000000000005555");
     b.Set("-13405803489547645687239409999999999999999999949384394");
     a.Add(b);
     Outf("%s + %s = %s",
          "100342309489574300000000000000000000000000000005555",
          "-13405803489547645687239409999999999999999999949384394",
          a.ToString().c_str());
}