
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * @phpstan-import-type mvc_hydration_column_map from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_CloneResultMapHydrate)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Hydration, CloneResultMapHydrate, phalcon, mvc_model_hydration_cloneresultmaphydrate, phalcon_mvc_model_hydration_cloneresultmaphydrate_method_entry, 0);

	return SUCCESS;
}

/**
 * Returns an hydrated result based on the data and the column map
 *
 * @phpstan-param array<array-key, mixed> $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Hydration_CloneResultMapHydrate, cloneResultMapHydrate)
{
	zend_bool _13, _3$$7, _4$$7, _8$$7, _14$$16, _15$$16, _19$$16;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *calledClass = NULL, *_2;
	zend_long hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, columnMap_sub, *hydrationMode_param = NULL, calledClass_zv, key, value, attribute, attributeName, *_0, _12, _5$$7, _6$$7, _7$$8, _9$$9, _10$$9, _11$$10, _16$$16, _17$$16, _18$$17, _20$$18, _21$$18, _22$$19, _23$$23;
	zval data, hydrateArray;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&hydrateArray);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&calledClass_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_23$$23);
	ZEND_TLS zephir_method_cache _zephir_call_cache[13];
	ZEND_PARSE_PARAMETERS_START(3, 4)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_LONG(hydrationMode)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(calledClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data_param = ZEND_CALL_ARG(execute_data, 1);
	columnMap = ZEND_CALL_ARG(execute_data, 2);
	hydrationMode_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_get_arrval(&data, data_param);
	if (!calledClass) {
		calledClass = zend_string_init(ZEND_STRL("Phalcon\\Mvc\\Model"), 0);
		zephir_memory_observe(&calledClass_zv);
		ZVAL_STR(&calledClass_zv, calledClass);
	} else {
		zephir_memory_observe(&calledClass_zv);
	ZVAL_STR_COPY(&calledClass_zv, calledClass);
	}
	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		if (hydrationMode == 1) {
			RETURN_CTOR(&data);
		}
	}
	ZEPHIR_INIT_VAR(&hydrateArray);
	array_init(&hydrateArray);
	zephir_is_iterable(&data, 0, "phalcon/Mvc/Model/Hydration/CloneResultMapHydrate.zep", 90);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				_3$$7 = zephir_array_isset_value(columnMap, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_4$$7 = !(_3$$7);
				if (_4$$7) {
					ZEPHIR_INIT_NVAR(&_6$$7);
					ZVAL_STRING(&_6$$7, "orm.case_insensitive_column_map");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_5$$7, phalcon_support_settings_ce, "get", &_zephir_call_cache[0], &_6$$7);
					zephir_check_call_status();
					_4$$7 = zephir_is_true(&_5$$7);
				}
				if (_4$$7) {
					ZEPHIR_CALL_CE_STATIC_CACHED(&_7$$8, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_zephir_call_cache[1], columnMap, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_7$$8);
				}
				ZEPHIR_OBS_NVAR(&attribute);
				_8$$7 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_8$$7)) {
					ZEPHIR_INIT_NVAR(&_10$$9);
					ZVAL_STRING(&_10$$9, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_9$$9, phalcon_support_settings_ce, "get", &_zephir_call_cache[2], &_10$$9);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_9$$9))) {
						ZEPHIR_INIT_NVAR(&_11$$10);
						object_init_ex(&_11$$10, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$10, "__construct", &_zephir_call_cache[3], &key, &calledClass_zv);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$10, "phalcon/Mvc/Model/Hydration/CloneResultMapHydrate.zep", 69);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				if (Z_TYPE_P(&attribute) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeName);
					zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model/Hydration/CloneResultMapHydrate.zep", 79);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeName, &attribute);
				}
				zephir_array_update_zval(&hydrateArray, &attributeName, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_array_update_zval(&hydrateArray, &key, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "rewind", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "next", &_zephir_call_cache[5]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_12, &data, "valid", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &data, "key", &_zephir_call_cache[7]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &data, "current", &_zephir_call_cache[8]);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				if (Z_TYPE_P(columnMap) == IS_ARRAY) {
					_14$$16 = zephir_array_isset_value(columnMap, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_15$$16 = !(_14$$16);
					if (_15$$16) {
						ZEPHIR_INIT_NVAR(&_17$$16);
						ZVAL_STRING(&_17$$16, "orm.case_insensitive_column_map");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_16$$16, phalcon_support_settings_ce, "get", &_zephir_call_cache[9], &_17$$16);
						zephir_check_call_status();
						_15$$16 = zephir_is_true(&_16$$16);
					}
					if (_15$$16) {
						ZEPHIR_CALL_CE_STATIC_CACHED(&_18$$17, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_ce, "caseInsensitiveColumnMap", &_zephir_call_cache[10], columnMap, &key);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&key, &_18$$17);
					}
					ZEPHIR_OBS_NVAR(&attribute);
					_19$$16 = zephir_array_isset_fetch(&attribute, columnMap, &key, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_19$$16)) {
						ZEPHIR_INIT_NVAR(&_21$$18);
						ZVAL_STRING(&_21$$18, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_20$$18, phalcon_support_settings_ce, "get", &_zephir_call_cache[11], &_21$$18);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_20$$18))) {
							ZEPHIR_INIT_NVAR(&_22$$19);
							object_init_ex(&_22$$19, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_22$$19, "__construct", &_zephir_call_cache[12], &key, &calledClass_zv);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_22$$19, "phalcon/Mvc/Model/Hydration/CloneResultMapHydrate.zep", 69);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					if (Z_TYPE_P(&attribute) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeName);
						zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model/Hydration/CloneResultMapHydrate.zep", 79);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeName, &attribute);
					}
					zephir_array_update_zval(&hydrateArray, &attributeName, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_zval(&hydrateArray, &key, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (hydrationMode != 1) {
		ZEPHIR_CPY_WRT(&_23$$23, &hydrateArray);
		zephir_convert_to_object(&_23$$23);
		RETURN_CCTOR(&_23$$23);
	}
	RETURN_CTOR(&hydrateArray);
}

