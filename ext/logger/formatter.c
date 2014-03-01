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

#include "logger/formatter.h"
#include "logger/formatterinterface.h"

#include <main/spprintf.h>

#include "kernel/main.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Logger\Formatter
 *
 * This is a base class for logger formatters
 */
zend_class_entry *phalcon_logger_formatter_ce;

PHP_METHOD(Phalcon_Logger_Formatter, getTypeString);
PHP_METHOD(Phalcon_Logger_Formatter, interpolate);

static const zend_function_entry phalcon_logger_formatter_method_entry[] = {
	PHP_ME(Phalcon_Logger_Formatter, getTypeString, arginfo_phalcon_logger_formatter_gettypestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter, interpolate, arginfo_phalcon_logger_formatter_interpolate, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

/**
 * Phalcon\Logger\Formatter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Formatter){

	PHALCON_REGISTER_CLASS(Phalcon\\Logger, Formatter, logger_formatter, phalcon_logger_formatter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_logger_formatter_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);

	return SUCCESS;
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter, getTypeString){

	static const char *lut[10] = {
		"EMERGENCY", "CRITICAL", "ALERT", "ERROR",  "WARNING",
		"NOTICE",    "INFO",     "DEBUG", "CUSTOM", "SPECIAL"
	};

	zval **type;
	int itype;

	phalcon_fetch_params_ex(1, 0, &type);
	PHALCON_ENSURE_IS_LONG(type);
	
	itype = Z_LVAL_PP(type);
	if (itype >= 0 && itype < 10) {
		RETURN_STRING(lut[itype], 1);
	}
	
	RETURN_STRING("CUSTOM", 1);
}

/**
 * Interpolates context values into the message placeholders
 *
 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Formatter, interpolate)
{
	zval **message, **context;

	phalcon_fetch_params_ex(2, 0, &message, &context);

	if (Z_TYPE_PP(context) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_PP(context)) > 0) {
		HashTable *ht = Z_ARRVAL_PP(context);
		HashPosition hp;
		zval *replace, **val;

		PHALCON_ALLOC_GHOST_ZVAL(replace);
		array_init_size(replace, zend_hash_num_elements(ht));

		for (
			zend_hash_internal_pointer_reset_ex(ht, &hp);
			zend_hash_get_current_data_ex(ht, (void**)&val, &hp) == SUCCESS;
			zend_hash_move_forward_ex(ht, &hp)
		) {
			char *str_index, *idx;
			uint str_length;
			ulong num_index;
			int type = zend_hash_get_current_key_ex(ht, &str_index, &str_length, &num_index, 0, &hp);

			if (HASH_KEY_IS_STRING == type) {
				str_length       += 2;
				idx               = emalloc(str_length);
				idx[0]            = '{';
				idx[str_length-2] = '}';
				idx[str_length-1] = '\0';
				memcpy(idx + 1, str_index, str_length - 3);
			}
			else if (HASH_KEY_IS_LONG == type) {
				str_length = spprintf(&idx, 0, "{%ld}", num_index);
			}
			else { /* Better safe than sorry */
				continue;
			}

			Z_ADDREF_PP(val);
			zend_hash_add(Z_ARRVAL_P(replace), idx, str_length, (void*)val, sizeof(zval*), NULL);
			efree(idx);
		}

		PHALCON_RETURN_CALL_FUNCTIONW("strtr", *message, replace);
		return;
	}

	RETURN_ZVAL(*message, 1, 0);
}
