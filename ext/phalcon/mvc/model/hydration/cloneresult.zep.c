
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_CloneResult)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Hydration, CloneResult, phalcon, mvc_model_hydration_cloneresult, phalcon_mvc_model_hydration_cloneresult_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_Hydration_CloneResult, cloneResult)
{
	zend_bool _8;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, value, _0, *_1, _7, _11, _4$$4, _5$$4, _9$$6, _10$$6;

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
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
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model/Hydration/CloneResult.zep", 44);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				object_init_ex(&_4$$4, phalcon_mvc_model_exceptions_invaliddumpresultkey_ce);
				ZEPHIR_INIT_NVAR(&_5$$4);
				zephir_get_class(&_5$$4, base, 0);
				ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", &_6, 0, &_5$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Model/Hydration/CloneResult.zep", 34);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval_zval(&instance, &key, &value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&key) != IS_STRING)) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					object_init_ex(&_9$$6, phalcon_mvc_model_exceptions_invaliddumpresultkey_ce);
					ZEPHIR_INIT_NVAR(&_10$$6);
					zephir_get_class(&_10$$6, base, 0);
					ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_6, 0, &_10$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$6, "phalcon/Mvc/Model/Hydration/CloneResult.zep", 34);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_update_property_zval_zval(&instance, &key, &value);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_11);
	zephir_check_call_status();
	RETURN_CCTOR(&instance);
}

