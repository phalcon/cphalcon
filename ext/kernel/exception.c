
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/exception.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * Throws a zval object as exception
 */
void phalcon_throw_exception(zval *object TSRMLS_DC){
	Z_ADDREF_P(object);
	zend_throw_exception_object(object TSRMLS_CC);
}

/**
 * Throws an exception with a single string parameter
 */
void phalcon_throw_exception_string(zend_class_entry *ce, const char *message TSRMLS_DC){

	zend_throw_exception_ex(ce, 0 TSRMLS_CC, "%s", message);
}

/**
 * Throws an exception with a single zval parameter
 */
void phalcon_throw_exception_zval(zend_class_entry *ce, zval *message TSRMLS_DC){

	zval *object;

	MAKE_STD_ZVAL(object);
	object_init_ex(object, ce);

	PHALCON_CALL_METHODW(NULL, object, "__construct", message);
	zend_throw_exception_object(object TSRMLS_CC);
}
