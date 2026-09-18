
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * @phpstan-import-type mvc_model_data from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_CloneResult)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Hydration, CloneResult, phalcon, mvc_model_hydration_cloneresult, phalcon_mvc_model_hydration_cloneresult_method_entry, 0);

	return SUCCESS;
}

/**
 * Assigns values to a model from an array returning a new model
 *
 *```php
 * $invoice = Phalcon\Mvc\Model::cloneResult(
 *     new Invoices(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Test Invoice",
 *         "year" => 1952,
 *     ]
 * );
 *```
 *
 * @phpstan-param mvc_model_data $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Hydration_CloneResult, cloneResult)
{
	zend_bool _9;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, privateProperties, reflectionProperty, value, _0, _1, *_2, _8, _12, _5$$4, _6$$4, _10$$8, _11$$8;

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&privateProperties);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(base, phalcon_mvc_modelinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(dirtyState)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &base, &data_param, &dirtyState_param);
	zephir_get_arrval(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, &instance, 0);
	ZEPHIR_CALL_CE_STATIC(&privateProperties, phalcon_mvc_model_hydration_getprivateproperties_ce, "getprivateproperties", NULL, 0, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model/Hydration/CloneResult.zep", 75);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				object_init_ex(&_5$$4, phalcon_mvc_model_exceptions_invaliddumpresultkey_ce);
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_get_class(&_6$$4, base, 0);
				ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_7, 0, &_6$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model/Hydration/CloneResult.zep", 60);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &key))) {
				ZEPHIR_OBS_NVAR(&reflectionProperty);
				zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model/Hydration/CloneResult.zep", 64);
				ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
				zephir_check_call_status();
			} else {
				zephir_update_property_zval_zval(&instance, &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_8, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
					ZEPHIR_INIT_NVAR(&_10$$8);
					object_init_ex(&_10$$8, phalcon_mvc_model_exceptions_invaliddumpresultkey_ce);
					ZEPHIR_INIT_NVAR(&_11$$8);
					zephir_get_class(&_11$$8, base, 0);
					ZEPHIR_CALL_METHOD(NULL, &_10$$8, "__construct", &_7, 0, &_11$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$8, "phalcon/Mvc/Model/Hydration/CloneResult.zep", 60);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(zephir_array_isset_value(&privateProperties, &key))) {
					ZEPHIR_OBS_NVAR(&reflectionProperty);
					zephir_array_fetch(&reflectionProperty, &privateProperties, &key, PH_NOISY, "phalcon/Mvc/Model/Hydration/CloneResult.zep", 64);
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperty, "setvalue", NULL, 0, &instance, &value);
					zephir_check_call_status();
				} else {
					zephir_update_property_zval_zval(&instance, &key, &value);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_12);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);
}

