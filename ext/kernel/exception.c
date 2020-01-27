
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Phalcon Team (http://www.zephir-lang.com)       |
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
void zephir_throw_exception_debug(zval *object, const char *file, uint32_t line)
{
	zend_class_entry *default_exception_ce;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	int ZEPHIR_LAST_CALL_STATUS = 0;
	zval curline;
	zval object_copy;

	ZVAL_UNDEF(&curline);

	ZEPHIR_MM_GROW();

	if (Z_TYPE_P(object) != IS_OBJECT) {
		ZVAL_COPY_VALUE(&object_copy, object);
		object_init_ex(object, zend_exception_get_default());
		ZEPHIR_CALL_METHOD(NULL, object, "__construct", NULL, 0, &object_copy);
		zval_ptr_dtor(&object_copy);
	}

	Z_ADDREF_P(object);

	if (line > 0) {
		ZEPHIR_CALL_METHOD(&curline, object, "getline", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&curline, 0)) {
			default_exception_ce = zend_exception_get_default();
			zend_update_property_string(default_exception_ce, object, SL("file"), file);
			zend_update_property_long(default_exception_ce, object, SL("line"), line);
		}
	}

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(object);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Throws an exception with a single string parameter + debug info
 */
void zephir_throw_exception_string_debug(zend_class_entry *ce, const char *message, uint32_t message_len, const char *file, uint32_t line)
{
	zval object, msg;
	int ZEPHIR_LAST_CALL_STATUS = 0;
	zend_class_entry *default_exception_ce;

	object_init_ex(&object, ce);

	ZVAL_STRINGL(&msg, message, message_len);

	ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, &object, "__construct", NULL, 0, &msg);

	if (line > 0) {
		default_exception_ce = zend_exception_get_default();
		zend_update_property_string(default_exception_ce, &object, "file", sizeof("file")-1, file);
		zend_update_property_long(default_exception_ce, &object, "line", sizeof("line")-1, line);
	}

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(&object);
	}

	zval_ptr_dtor(&msg);
}

/**
 * Throws an exception with a single string parameter
 */
void zephir_throw_exception_string(zend_class_entry *ce, const char *message, uint32_t message_len)
{
	zval object, msg;
	int ZEPHIR_LAST_CALL_STATUS = 0;

	object_init_ex(&object, ce);

	ZVAL_STRINGL(&msg, message, message_len);

	ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, &object, "__construct", NULL, 0, &msg);

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(&object);
	}

	zval_ptr_dtor(&msg);
}

/**
 * Throws an exception with a string format as parameter
 */
void zephir_throw_exception_format(zend_class_entry *ce, const char *format, ...)
{
	zval object, msg;
	int ZEPHIR_LAST_CALL_STATUS = 0, len;
	char *buffer;
	va_list args;

	object_init_ex(&object, ce);

	va_start(args, format);
	len = vspprintf(&buffer, 0, format, args);
	va_end(args);

	ZVAL_STRINGL(&msg, buffer, len);
	efree(buffer);

	ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(NULL, &object, "__construct", NULL, 0, &msg);

	if (ZEPHIR_LAST_CALL_STATUS != FAILURE) {
		zend_throw_exception_object(&object);
	}

	zval_ptr_dtor(&msg);
}
