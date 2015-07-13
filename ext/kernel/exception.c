
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
#include "kernel/operators.h"


/**
 * Throws a zval object as exception
 */
void phalcon_throw_exception(zval *object TSRMLS_DC){
	Z_ADDREF_P(object);
	zend_throw_exception_object(object TSRMLS_CC);
}

/**
 * Throws a zval object as exception
 */
void phalcon_throw_exception_debug(zval *object, const char *file, zend_uint line TSRMLS_DC){

	zend_class_entry *default_exception_ce;
	zval *curline = NULL, *object_copy = NULL;

	PHALCON_MM_GROW();

	if (Z_TYPE_P(object) != IS_OBJECT) {
		object_copy = object;
		ALLOC_INIT_ZVAL(object);
		object_init_ex(object, zend_exception_get_default(TSRMLS_C));
		PHALCON_CALL_METHOD(NULL, object, "__construct", NULL, 0, object_copy);
	}

	Z_ADDREF_P(object);

	if (line > 0) {
		curline = 0;
		PHALCON_CALL_METHOD(&curline, object, "getline", NULL);
		if (PHALCON_IS_LONG(curline, 0)) {
			default_exception_ce = zend_exception_get_default(TSRMLS_C);
			zend_update_property_string(default_exception_ce, object, "file", sizeof("file")-1, file TSRMLS_CC);
			zend_update_property_long(default_exception_ce, object, "line", sizeof("line")-1, line TSRMLS_CC);
		}
	}

	zend_throw_exception_object(object TSRMLS_CC);
	PHALCON_MM_RESTORE();
}

/**
 * Throws an exception with a single string parameter
 */
void phalcon_throw_exception_string(zend_class_entry *ce, const char *message TSRMLS_DC){

	zend_throw_exception_ex(ce, 0 TSRMLS_CC, "%s", message);
}

/**
 * Throws an exception with a single string parameter + debug info
 */
void phalcon_throw_exception_string_debug(zend_class_entry *ce, const char *message, zend_uint message_len, const char *file, zend_uint line TSRMLS_DC) {

	zval *object, *msg;
	zend_class_entry *default_exception_ce;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	ALLOC_INIT_ZVAL(msg);
	ZVAL_STRINGL(msg, message, message_len, 1);

	PHALCON_CALL_METHODW(NULL, object, "__construct", NULL, msg);

	if (line > 0) {
		default_exception_ce = zend_exception_get_default(TSRMLS_C);
		zend_update_property_string(default_exception_ce, object, "file", sizeof("file")-1, file TSRMLS_CC);
		zend_update_property_long(default_exception_ce, object, "line", sizeof("line")-1, line TSRMLS_CC);
	}

	zend_throw_exception_object(object TSRMLS_CC);

	phalcon_ptr_dtor(&msg);
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

/**
 * Throws an exception with a single zval parameter
 */
void phalcon_throw_exception_zval_debug(zend_class_entry *ce, zval *message, const char *file, zend_uint line TSRMLS_DC){

	zval *object;
	zend_class_entry *default_exception_ce;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	PHALCON_CALL_METHODW(NULL, object, "__construct", NULL, message);

	if (line > 0) {
		default_exception_ce = zend_exception_get_default(TSRMLS_C);
		zend_update_property_string(default_exception_ce, object, "file", sizeof("file")-1, file TSRMLS_CC);
		zend_update_property_long(default_exception_ce, object, "line", sizeof("line")-1, line TSRMLS_CC);
	}

	zend_throw_exception_object(object TSRMLS_CC);
}

/**
 * Throws an exception with a string format as parameter
 */
void phalcon_throw_exception_format(zend_class_entry *ce TSRMLS_DC, const char *format, ...) {

	zval *object, *msg;
	int len;
	char *buffer;
	va_list args;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	va_start(args, format);
	len = vspprintf(&buffer, 0, format, args);
	va_end(args);

	ALLOC_INIT_ZVAL(msg);
	ZVAL_STRINGL(msg, buffer, len, 0);

	PHALCON_CALL_METHODW(NULL, object, "__construct", NULL, msg);

	zend_throw_exception_object(object TSRMLS_CC);

	phalcon_ptr_dtor(&msg);
}
