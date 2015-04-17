
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
<<<<<<< HEAD
  | Copyright (c) 2011-2015 Zephir Team  (http://www.zephir-lang.com)      |
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

#ifndef ZEPHIR_KERNEL_SESSION_H
#define ZEPHIR_KERNEL_SESSION_H

#include <php.h>
#include <Zend/zend.h>

<<<<<<< HEAD
void zephir_session_start(TSRMLS_D);
void zephir_session_destroy(TSRMLS_D);
void zephir_get_session_id(zval *return_value, zval **return_value_ptr TSRMLS_DC);
void zephir_set_session_id(zval *sid TSRMLS_DC);
=======
#include "php_phalcon.h"

int phalcon_session_start(TSRMLS_D) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_session_destroy(TSRMLS_D) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_get_session_id(zval *return_value, zval **return_value_ptr TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_set_session_id(zval *sid TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_session_write_close(TSRMLS_D) PHALCON_ATTR_WARN_UNUSED_RESULT;
>>>>>>> master

#endif /* ZEPHIR_KERNEL_SESSION_H */
