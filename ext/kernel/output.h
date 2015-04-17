
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
#ifndef ZEPHIR_KERNEL_OUTPUT_H
#define ZEPHIR_KERNEL_OUTPUT_H

#include <php.h>

void zephir_ob_start(TSRMLS_D);
void zephir_ob_get_contents(zval *result TSRMLS_DC);
int zephir_ob_end_flush(TSRMLS_D);
int zephir_ob_end_clean(TSRMLS_D);
int zephir_ob_flush(TSRMLS_D);
int zephir_ob_clean(TSRMLS_D);
int zephir_ob_get_level(TSRMLS_D);

#endif
=======
#ifndef PHALCON_KERNEL_OUTPUT_H
#define PHALCON_KERNEL_OUTPUT_H

#include "php_phalcon.h"

void phalcon_ob_start(TSRMLS_D);
void phalcon_ob_get_contents(zval *result TSRMLS_DC);
int phalcon_ob_end_flush(TSRMLS_D);
int phalcon_ob_end_clean(TSRMLS_D);
int phalcon_ob_flush(TSRMLS_D);
int phalcon_ob_clean(TSRMLS_D);
int phalcon_ob_get_level(TSRMLS_D);

#endif /* PHALCON_KERNEL_OUTPUT_H */
>>>>>>> master
