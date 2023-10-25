
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "Zend/zend_closures.h"
#include "kernel/time.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Behavior\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the datetime when a
 * record is created or updated
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior_Timestampable)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, Timestampable, phalcon, mvc_model_behavior_timestampable, phalcon_mvc_model_behavior_ce, phalcon_mvc_model_behavior_timestampable_method_entry, 0);

	return SUCCESS;
}

/**
 * Listens for notifications from the models manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_Timestampable, notify)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *model, model_sub, options, timestamp, singleField, field, _0, *_1$$6, _2$$6;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&timestamp);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);
	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "musttakeaction", NULL, 0, &type);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getoptions", NULL, 0, &type);
	zephir_check_call_status();
	if (Z_TYPE_P(&options) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&field);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&field, &options, SL("field"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The option 'field' is required", "phalcon/Mvc/Model/Behavior/Timestampable.zep", 50);
		return;
	}
	ZEPHIR_CALL_METHOD(&timestamp, this_ptr, "gettimestamp", NULL, 434, &options);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&field) == IS_ARRAY)) {
		zephir_is_iterable(&field, 0, "phalcon/Mvc/Model/Behavior/Timestampable.zep", 63);
		if (Z_TYPE_P(&field) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _1$$6)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _1$$6);
				ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", &_3, 0, &singleField, &timestamp);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$6, &field, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", &_4, 0, &singleField, &timestamp);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else {
		ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", NULL, 0, &field, &timestamp);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_Timestampable, getTimestamp)
{
	zend_bool _0$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, format, generator;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&generator);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);


	ZEPHIR_OBS_VAR(&format);
	if (zephir_array_isset_string_fetch(&format, &options, SL("format"), 0)) {
		ZEPHIR_RETURN_CALL_FUNCTION("date", NULL, 435, &format);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&generator);
	if (zephir_array_isset_string_fetch(&generator, &options, SL("generator"), 0)) {
		_0$$4 = Z_TYPE_P(&generator) == IS_OBJECT;
		if (_0$$4) {
			_0$$4 = zephir_is_instance_of(&generator, SL("Closure"));
		}
		if (_0$$4) {
			ZEPHIR_CALL_USER_FUNC(return_value, &generator);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	zephir_time(return_value);
	RETURN_MM();
}

