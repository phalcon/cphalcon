
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
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

#ifndef ZEPHIR_KERNEL_OUTPUT_H
#define ZEPHIR_KERNEL_OUTPUT_H

void zephir_ob_start(TSRMLS_D);
void zephir_ob_get_contents(zval *result TSRMLS_DC);
int zephir_ob_end_flush(TSRMLS_D);
int zephir_ob_end_clean(TSRMLS_D);
int zephir_ob_flush(TSRMLS_D);
int zephir_ob_clean(TSRMLS_D);
int zephir_ob_get_level(TSRMLS_D);

#endif