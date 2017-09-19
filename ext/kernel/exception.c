
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
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "php_main.h"
#include "ext/standard/php_string.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

#include "Zend/zend_exceptions.h"

/**
 * Throws a zval object as exception
 */
void zephir_throw_exception(zval *object TSRMLS_DC){
	Z_ADDREF_P(object);
	zend_throw_exception_object(object TSRMLS_CC);
}

/**
 * Throws a zval object as exception
 */
void zephir_throw_exception_debug(zval *object, const char *file, zend_uint line TSRMLS_DC) {

	zend_class_entry *default_exception_ce;
	int ZEPHIR_LAST_CALL_STATUS = 0;
	zval *curline = NULL;

	ZEPHIR_MM_GROW();

	if (Z_TYPE_P(object) != IS_OBJECT) {
		zval *arg = object;
		ALLOC_INIT_ZVAL(object);
		object_init_ex(object, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_CALL_METHOD(NULL, object, "__construct", NULL, 0, arg);
	}
	else {
		Z_ADDREF_P(object);
	}

	if (line > 0) {
		ZEPHIR_CALL_METHOD(&curline, object, "getline", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(curline, 0)) {
			default_exception_ce = zend_exception_get_default(TSRMLS_C);
			zend_update_property_string(default_exception_ce, object, "file", sizeof("file") - 1, file TSRMLS_CC);
			zend_update_property_long(default_exception_ce, object, "line", sizeof("line") - 1, line TSRMLS_CC);
		}
	}

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(object TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Throws an exception with a single string parameter + debug info
 */
void zephir_throw_exception_string_debug(zend_class_entry *ce, const char *message, zend_uint message_len, const char *file, zend_uint line TSRMLS_DC) {

	zval *object, *msg;
	int ZEPHIR_LAST_CALL_STATUS = 0;
	zend_class_entry *default_exception_ce;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	ALLOC_INIT_ZVAL(msg);
	ZVAL_STRINGL(msg, message, message_len, 1);

	ZEPHIR_CALL_METHOD(NULL, object, "__construct", NULL, 0, msg);

	if (line > 0) {
		default_exception_ce = zend_exception_get_default(TSRMLS_C);
		zend_update_property_string(default_exception_ce, object, "file", sizeof("file")-1, file TSRMLS_CC);
		zend_update_property_long(default_exception_ce, object, "line", sizeof("line")-1, line TSRMLS_CC);
	}

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(object TSRMLS_CC);
	}

	zval_ptr_dtor(&msg);
}

/**
 * Throws an exception with a single string parameter
 */
void zephir_throw_exception_string(zend_class_entry *ce, const char *message, zend_uint message_len TSRMLS_DC){

	zval *object, *msg;
	int ZEPHIR_LAST_CALL_STATUS = 0;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	ALLOC_INIT_ZVAL(msg);
	ZVAL_STRINGL(msg, message, message_len, 1);

	ZEPHIR_CALL_METHOD(NULL, object, "__construct", NULL, 0, msg);

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(object TSRMLS_CC);
	}

	zval_ptr_dtor(&msg);
}

/**
 * Throws an exception with a string format as parameter
 */
void zephir_throw_exception_format(zend_class_entry *ce TSRMLS_DC, const char *format, ...) {

	zval *object, *msg;
	int ZEPHIR_LAST_CALL_STATUS = 0, len;
	char *buffer;
	va_list args;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	va_start(args, format);
	len = vspprintf(&buffer, 0, format, args);
	va_end(args);

	ALLOC_INIT_ZVAL(msg);
	ZVAL_STRINGL(msg, buffer, len, 0);

	ZEPHIR_CALL_METHOD(NULL, object, "__construct", NULL, 0, msg);

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(object TSRMLS_CC);
	}

	zval_ptr_dtor(&msg);
}

/**
 * Throws an exception with a single zval parameter
 */
void zephir_throw_exception_zval_debug(zend_class_entry *ce, zval *message, const char *file, zend_uint line TSRMLS_DC){

	zval *object;
	int ZEPHIR_LAST_CALL_STATUS = 0;
	zend_class_entry *default_exception_ce;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	ZEPHIR_CALL_METHOD(NULL, object, "__construct", NULL, 0, message);

	if (line > 0) {
		default_exception_ce = zend_exception_get_default(TSRMLS_C);
		zend_update_property_string(default_exception_ce, object, "file", sizeof("file")-1, file TSRMLS_CC);
		zend_update_property_long(default_exception_ce, object, "line", sizeof("line")-1, line TSRMLS_CC);
	}

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(object TSRMLS_CC);
	}
}

/**
 * Throws an exception with a single zval parameter
 */
void zephir_throw_exception_zval(zend_class_entry *ce, zval *message TSRMLS_DC){

	zval *object;
	int ZEPHIR_LAST_CALL_STATUS = 0;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	ZEPHIR_CALL_METHOD(NULL, object, "__construct", NULL, 0, message);	

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(object TSRMLS_CC);
	}
}
