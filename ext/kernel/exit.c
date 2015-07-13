/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "php_phalcon.h"

#include "kernel/exit.h"

void phalcon_exit_empty() {
	//TSRMLS_FETCH();
	zend_bailout();
}

void phalcon_exit(zval *ptr)  {
	TSRMLS_FETCH();
	if (Z_TYPE_P(ptr) == IS_LONG) {
		EG(exit_status) = Z_LVAL_P(ptr);
	} else {
		zend_print_variable(ptr);
	}
	zend_bailout();
}
