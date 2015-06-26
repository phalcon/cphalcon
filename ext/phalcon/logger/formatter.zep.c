
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Logger\Formatter
 *
 * This is a base class for logger formatters
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Formatter, phalcon, logger_formatter, phalcon_logger_formatter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter, getTypeString) {

	zval *type_param = NULL;
	int type;

	zephir_fetch_params(0, 1, 0, &type_param);

	type = zephir_get_intval(type_param);


	do {
		if (type == 7) {
			RETURN_STRING("DEBUG", 1);
		}
		if (type == 3) {
			RETURN_STRING("ERROR", 1);
		}
		if (type == 4) {
			RETURN_STRING("WARNING", 1);
		}
		if (type == 1) {
			RETURN_STRING("CRITICAL", 1);
		}
		if (type == 8) {
			RETURN_STRING("CUSTOM", 1);
		}
		if (type == 2) {
			RETURN_STRING("ALERT", 1);
		}
		if (type == 5) {
			RETURN_STRING("NOTICE", 1);
		}
		if (type == 6) {
			RETURN_STRING("INFO", 1);
		}
		if (type == 0) {
			RETURN_STRING("EMERGENCY", 1);
		}
		if (type == 9) {
			RETURN_STRING("SPECIAL", 1);
		}
	} while(0);

	RETURN_STRING("CUSTOM", 1);

}

/**
 * Interpolates context values into the message placeholders
 *
 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Formatter, interpolate) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zval *message_param = NULL, *context = NULL, *replace, *key = NULL, *value = NULL, **_3, *_4 = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context);

	zephir_get_strval(message, message_param);
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(context) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(context TSRMLS_CC) > 0;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(replace);
		array_init(replace);
		zephir_is_iterable(context, &_2, &_1, 0, 0, "phalcon/logger/formatter.zep", 89);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(key, _2, _1);
			ZEPHIR_GET_HVALUE(value, _3);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVS(_4, "{", key, "}");
			zephir_array_update_zval(&replace, _4, &value, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, message, replace);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(message);

}

