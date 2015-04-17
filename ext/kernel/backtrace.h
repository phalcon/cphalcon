
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
<<<<<<< HEAD
  | Copyright (c) 2011-2015 Zephir Team (http://www.zephir-lang.com)       |
=======
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
>>>>>>> master
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

<<<<<<< HEAD
#ifndef ZEPHIR_KERNEL_BACKTRACE_H
#define ZEPHIR_KERNEL_BACKTRACE_H

#ifndef ZEPHIR_RELEASE

extern void zephir_print_backtrace(void);
=======
#ifndef PHALCON_KERNEL_BACKTRACE_H
#define PHALCON_KERNEL_BACKTRACE_H

#include "php_phalcon.h"
>>>>>>> master

void phalcon_print_backtrace(void);

<<<<<<< HEAD
#ifndef zephir_print_backtrace
#define zephir_print_backtrace()
#endif

#endif
#endif /* ZEPHIR_KERNEL_BACKTRACE_H */
=======
#endif /* PHALCON_KERNEL_BACKTRACE_H */
>>>>>>> master
