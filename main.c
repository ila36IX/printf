#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdint.h>

int main()
{
   printf("%00054.91x%-119.117s%.120s%-3.12X" ,2341589136u,"V0dP#8kjTEcV7&k(cX>QVDa","oUyFMC$9``PRmEAG|~@|`<^'Q@\n",198320040u);
   ft_printf("%00054.91x%-119.117s%.120s%-3.12X" ,2341589136u,"V0dP#8kjTEcV7&k(cX>QVDa","oUyFMC$9``PRmEAG|~@|`<^'Q@\n",198320040u);

}
