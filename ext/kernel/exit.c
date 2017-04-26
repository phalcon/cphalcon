/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Song Yeung <netyum@163.com>                                   |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "php_main.h"

#include "kernel/main.h"
#include "kernel/exit.h"

void zephir_exit_empty()
{
	zend_bailout();
}

void zephir_exit(zval *ptr)  {
	TSRMLS_FETCH();
	if (Z_TYPE_P(ptr) == IS_LONG) {
		EG(exit_status) = Z_LVAL_P(ptr);
	} else {
		zend_print_variable(ptr);
	}
	zephir_exit_empty();
}
