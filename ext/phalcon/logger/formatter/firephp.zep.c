
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


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
 |          Ivan Zubok <chi_no@ukr.net>                                   |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Logger\Formatter\Firephp
 *
 * Formats messages so that they can be sent to FirePHP
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Firephp) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Firephp, phalcon, logger_formatter_firephp, phalcon_logger_formatter_ce, phalcon_logger_formatter_firephp_method_entry, 0);

	zend_declare_property_bool(phalcon_logger_formatter_firephp_ce, SL("_showBacktrace"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_logger_formatter_firephp_ce, SL("_enableLabels"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_formatter_firephp_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);
	return SUCCESS;

}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString) {

	zval *type_param = NULL, *typeString = NULL;
	int type;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	type = zephir_get_intval(type_param);


	do {
		if (type == 0 || type == 1 || type == 3) {
			ZEPHIR_INIT_VAR(typeString);
			ZVAL_STRING(typeString, "ERROR", 1);
			break;
		}
		if (type == 2 || type == 4) {
			ZEPHIR_INIT_NVAR(typeString);
			ZVAL_STRING(typeString, "WARN", 1);
			break;
		}
		if (type == 6 || type == 5 || type == 8) {
			ZEPHIR_INIT_NVAR(typeString);
			ZVAL_STRING(typeString, "INFO", 1);
			break;
		}
		if (type == 7 || type == 9) {
			ZEPHIR_INIT_NVAR(typeString);
			ZVAL_STRING(typeString, "LOG", 1);
			break;
		}
		ZEPHIR_INIT_NVAR(typeString);
		ZVAL_STRING(typeString, "CUSTOM", 1);
		break;
	} while(0);

	RETURN_CCTOR(typeString);

}

/**
 * Returns the string meaning of a logger constant
 *
 * @return this
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, setShowBacktrace) {

	zval *isShow_param = NULL;
	zend_bool isShow;

	zephir_fetch_params(0, 0, 1, &isShow_param);

	if (!isShow_param) {
		isShow = 0;
	} else {
		isShow = zephir_get_boolval(isShow_param);
	}


	zephir_update_property_this(this_ptr, SL("_showBacktrace"), isShow ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the string meaning of a logger constant
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getShowBacktrace) {


	RETURN_MEMBER(this_ptr, "_showBacktrace");

}

/**
 * Returns the string meaning of a logger constant
 *
 * @return this
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, enableLabels) {

	zval *isEnable_param = NULL;
	zend_bool isEnable;

	zephir_fetch_params(0, 0, 1, &isEnable_param);

	if (!isEnable_param) {
		isEnable = 0;
	} else {
		isEnable = zephir_get_boolval(isEnable_param);
	}


	zephir_update_property_this(this_ptr, SL("_enableLabels"), isEnable ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the labels enabled
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, labelsEnabled) {


	RETURN_MEMBER(this_ptr, "_enableLabels");

}

/**
 * Applies a format to a message before sending it to the log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @param array $context
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format) {

	zval *_21;
	HashTable *_10;
	HashPosition _9;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_7 = NULL;
	zend_bool param, _14, _17;
	int type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *timestamp_param = NULL, *context = NULL, *meta, *body = NULL, *backtrace = NULL, *encoded, *len, *lastTrace = NULL, *_0 = NULL, *_1 = NULL, *_2, *backtraceItem = NULL, *key = NULL, _3, _4, *_8, **_11, *_12, *_13, *_15, *_16, *_18, *_19, *_20;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type_param, &timestamp_param, &context);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(context) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "interpolate", NULL, message, context);
		zephir_check_call_status();
		zephir_get_strval(message, _0);
	}
	ZEPHIR_INIT_VAR(meta);
	array_init_size(meta, 2);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, type);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettypestring", NULL, _1);
	zephir_check_call_status();
	zephir_array_update_string(&meta, SL("Type"), &_0, PH_COPY | PH_SEPARATE);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_showBacktrace"), PH_NOISY_CC);
	if (zephir_is_true(_2)) {
		param = 0;
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "PHP_VERSION");
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "5.3.6", 0);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "<", 0);
		ZEPHIR_CALL_FUNCTION(&_0, "version_compare", &_5, _1, &_3, &_4);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			param = (2) ? 1 : 0;
		}
		ZEPHIR_CALL_FUNCTION(&backtrace, "debug_backtrace", &_6, (param ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		Z_SET_ISREF_P(backtrace);
		ZEPHIR_CALL_FUNCTION(&lastTrace, "end", &_7, backtrace);
		Z_UNSET_ISREF_P(backtrace);
		zephir_check_call_status();
		if (zephir_array_isset_string(lastTrace, SS("file"))) {
			zephir_array_fetch_string(&_8, lastTrace, SL("file"), PH_NOISY | PH_READONLY, "phalcon/logger/formatter/firephp.zep", 153 TSRMLS_CC);
			zephir_array_update_string(&meta, SL("File"), &_8, PH_COPY | PH_SEPARATE);
		}
		if (zephir_array_isset_string(lastTrace, SS("line"))) {
			zephir_array_fetch_string(&_8, lastTrace, SL("line"), PH_NOISY | PH_READONLY, "phalcon/logger/formatter/firephp.zep", 157 TSRMLS_CC);
			zephir_array_update_string(&meta, SL("Line"), &_8, PH_COPY | PH_SEPARATE);
		}
		zephir_is_iterable(backtrace, &_10, &_9, 1, 0, "phalcon/logger/formatter/firephp.zep", 166);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HMKEY(key, _10, _9);
			ZEPHIR_GET_HVALUE(backtraceItem, _11);
			zephir_array_unset_string(&backtraceItem, SS("object"), PH_SEPARATE);
			zephir_array_unset_string(&backtraceItem, SS("args"), PH_SEPARATE);
			zephir_array_update_zval(&backtrace, key, &backtraceItem, PH_COPY | PH_SEPARATE);
		}
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_enableLabels"), PH_NOISY_CC);
	if (zephir_is_true(_12)) {
		zephir_array_update_string(&meta, SL("Label"), &message, PH_COPY | PH_SEPARATE);
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("_enableLabels"), PH_NOISY_CC);
	_14 = !zephir_is_true(_13);
	if (_14) {
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_showBacktrace"), PH_NOISY_CC);
		_14 = !zephir_is_true(_15);
	}
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("_enableLabels"), PH_NOISY_CC);
	_17 = zephir_is_true(_16);
	if (_17) {
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("_showBacktrace"), PH_NOISY_CC);
		_17 = !zephir_is_true(_18);
	}
	if (_14) {
		ZEPHIR_CPY_WRT(body, message);
	} else if (_17) {
		ZEPHIR_INIT_NVAR(body);
		ZVAL_STRING(body, "", 1);
	} else {
		ZEPHIR_INIT_NVAR(body);
		array_init(body);
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_showBacktrace"), PH_NOISY_CC);
		if (zephir_is_true(_19)) {
			zephir_array_update_string(&body, SL("backtrace"), &backtrace, PH_COPY | PH_SEPARATE);
		}
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_enableLabels"), PH_NOISY_CC);
		if (!(zephir_is_true(_20))) {
			zephir_array_update_string(&body, SL("message"), &message, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(encoded);
	ZEPHIR_INIT_VAR(_21);
	array_init_size(_21, 3);
	zephir_array_fast_append(_21, meta);
	zephir_array_fast_append(_21, body);
	zephir_json_encode(encoded, &(encoded), _21, 0  TSRMLS_CC);
	ZEPHIR_INIT_VAR(len);
	ZVAL_LONG(len, zephir_fast_strlen_ev(encoded));
	ZEPHIR_CONCAT_VSVS(return_value, len, "|", encoded, "|");
	RETURN_MM();

}

