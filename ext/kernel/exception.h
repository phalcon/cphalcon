
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
  +------------------------------------------------------------------------+
*/

/** Exceptions */
#define PHALCON_THROW_EXCEPTION_STR(class_entry, message) phalcon_throw_exception_string(class_entry, message, sizeof(message)-1, 1 TSRMLS_CC);
#define PHALCON_THROW_EXCEPTION_STRW(class_entry, message) phalcon_throw_exception_string(class_entry, message, sizeof(message)-1, 0 TSRMLS_CC);
#define PHALCON_THROW_EXCEPTION_ZVAL(class_entry, message) phalcon_throw_exception_zval(class_entry, message, 1 TSRMLS_CC);
#define PHALCON_THROW_EXCEPTION_ZVALW(class_entry, message) phalcon_throw_exception_zval(class_entry, message, 0 TSRMLS_CC);

/** Throw Exceptions */
extern void phalcon_throw_exception(zval *object TSRMLS_DC);
extern void phalcon_throw_exception_string(zend_class_entry *ce, const char *message, zend_uint message_len, int restore_stack TSRMLS_DC);
extern void phalcon_throw_exception_zval(zend_class_entry *ce, zval *message, int restore_stack TSRMLS_DC);
extern void phalcon_throw_exception_internal(zval *exception TSRMLS_DC);
