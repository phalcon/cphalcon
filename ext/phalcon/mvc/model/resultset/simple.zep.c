
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 *
 * @template TKey of int
 * @template TValue of \Phalcon\Mvc\ModelInterface
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Simple, phalcon, mvc_model_resultset_simple, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_simple_method_entry, 0);

	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("columnMap"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("eagerMap"), ZEND_ACC_PROTECTED);
	/**
	 * @var ModelInterface|Row
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("model"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_resultset_simple_ce, SL("keepSnapshots"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Resultset\Simple constructor
 *
 * @param array                             columnMap
 * @param ModelInterface|Row                model
 * @param \Phalcon\Db\ResultInterface|false result
 * @param mixed|null                        cache
 * @param bool keepSnapshots                false
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool keepSnapshots;
	zval *columnMap, columnMap_sub, *model, model_sub, *result, result_sub, *cache = NULL, cache_sub, *keepSnapshots_param = NULL, __$true, __$false, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("columnMap", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("keepSnapshots", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_ZVAL(model)
		Z_PARAM_ZVAL(result)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(cache)
		Z_PARAM_BOOL(keepSnapshots)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 2, &columnMap, &model, &result, &cache, &keepSnapshots_param);
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1109, model);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1110, columnMap);
	if (keepSnapshots) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1111, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1111, &__$false);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_simple_ce, getThis(), "__construct", NULL, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __serialize)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("columnMap", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("hydrateMode", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("keepSnapshots", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 6, 0);
	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1109, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("model"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1112, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("cache"), &_0, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "toarray", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("rows"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1110, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("columnMap"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1113, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hydrateMode"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1111, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("keepSnapshots"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, keepSnapshots, _0, _1, _2, _3, _4, _5, _6;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("rows", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("count", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("columnMap", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("hydrateMode", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("keepSnapshots", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	zephir_array_fetch_string(&_0, &data, SL("model"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 101);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1109, &_0);
	zephir_array_fetch_string(&_1, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 102);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1114, &_1);
	zephir_array_fetch_string(&_2, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 103);
	ZVAL_UNDEF(&_3);
	ZVAL_LONG(&_3, zephir_fast_count_int(&_2));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1115, &_3);
	zephir_array_fetch_string(&_4, &data, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 104);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1112, &_4);
	zephir_array_fetch_string(&_5, &data, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 105);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1110, &_5);
	zephir_array_fetch_string(&_6, &data, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 106);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1113, &_6);
	if (zephir_array_isset_string_fetch(&keepSnapshots, &data, SL("keepSnapshots"), 1)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1111, &keepSnapshots);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns current row in the resultset
 * @return TValue
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current)
{
	zend_class_entry *_8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, row, hydrateMode, columnMap, activeRow, modelName, _0, _1$$5, _2$$5, _12$$5, _3$$6, _5$$6, _6$$6, _7$$6, _4$$7, _9$$9, _10$$9, _11$$9, _13$$10;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("activeRow", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("row", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("hydrateMode", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("columnMap", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("keepSnapshots", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("eagerMap", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1116, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeRow, &_0);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1117, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&row, &_0);
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1116, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1116, &__$false);
		}
		RETURN_MM_NULL();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1113, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&hydrateMode, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1110, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columnMap, &_0);
	do {
		if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "orm.late_state_binding");
			ZEPHIR_CALL_CE_STATIC(&_1$$5, phalcon_support_settings_ce, "get", NULL, 0, &_2$$5);
			zephir_check_call_status();
			if (zephir_is_true(&_1$$5)) {
				zephir_memory_observe(&_3$$6);
				zephir_read_property_cached(&_3$$6, this_ptr, _zephir_prop_4, 1109, PH_NOISY_CC);
				if (zephir_instance_of_ev(&_3$$6, phalcon_mvc_model_ce)) {
					zephir_read_property_cached(&_4$$7, this_ptr, _zephir_prop_4, 1109, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&modelName);
					zephir_get_class(&modelName, &_4$$7, 0);
				} else {
					ZEPHIR_INIT_NVAR(&modelName);
					ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
				}
				zephir_read_property_cached(&_5$$6, this_ptr, _zephir_prop_4, 1109, PH_NOISY_CC | PH_READONLY);
				zephir_read_property_cached(&_6$$6, this_ptr, _zephir_prop_5, 1111, PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_7$$6, 0);
				_8$$6 = zephir_fetch_class(&modelName);
				ZEPHIR_CALL_CE_STATIC(&activeRow, _8$$6, "cloneresultmap", NULL, 0, &_5$$6, &row, &columnMap, &_7$$6, &_6$$6);
				zephir_check_call_status();
			} else {
				zephir_read_property_cached(&_9$$9, this_ptr, _zephir_prop_4, 1109, PH_NOISY_CC | PH_READONLY);
				zephir_read_property_cached(&_10$$9, this_ptr, _zephir_prop_5, 1111, PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_11$$9, 0);
				ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmap", NULL, 0, &_9$$9, &row, &columnMap, &_11$$9, &_10$$9);
				zephir_check_call_status();
			}
			zephir_read_property_cached(&_12$$5, this_ptr, _zephir_prop_6, 1118, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_12$$5) != IS_NULL) {
				zephir_read_property_cached(&_13$$10, this_ptr, _zephir_prop_6, 1118, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_CE_STATIC(NULL, phalcon_mvc_model_eager_loader_ce, "apply", NULL, 0, &activeRow, &_13$$10);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmaphydrate", NULL, 0, &row, &columnMap, &hydrateMode);
		zephir_check_call_status();
		break;
	} while(0);

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1116, &activeRow);
	RETURN_CCTOR(&activeRow);
}

/**
 * Serializing a resultset will dump all related rows into a big array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize)
{
	zval data;
	zval container, serializer, _1, _2, _3, _4, _0$$3, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&data);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("columnMap", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("hydrateMode", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("keepSnapshots", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Simple.zep", 220);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 6, 0);
	zephir_memory_observe(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1109, PH_NOISY_CC);
	zephir_array_update_string(&data, SL("model"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1112, PH_NOISY_CC);
	zephir_array_update_string(&data, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_2, 1110, PH_NOISY_CC);
	zephir_array_update_string(&data, SL("columnMap"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_3, 1113, PH_NOISY_CC);
	zephir_array_update_string(&data, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_4, 1111, PH_NOISY_CC);
	zephir_array_update_string(&data, SL("keepSnapshots"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "serializer");
	ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "serializer");
		ZEPHIR_CALL_METHOD(&_5$$4, &container, "getshared", NULL, 0, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_5$$4);
		ZEPHIR_CALL_METHOD(NULL, &serializer, "setdata", NULL, 0, &data);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&serializer, "serialize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 21, &data);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Attaches a pre-loaded relation map, applied to every record as it is
 * hydrated.
 *
 * Records in a resultset are transient - seek() clears activeRow on every
 * move and current() re-hydrates from the raw row - so hydration is the
 * only durable point at which relations can be stamped.
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, setEagerMap)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *eagerMap_param = NULL;
	zval eagerMap;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eagerMap);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eagerMap", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(eagerMap, eagerMap_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eagerMap_param);
	zephir_get_arrval(&eagerMap, eagerMap_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1118, &eagerMap);
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a new resultset of the same concrete class over the rows at the
 * given positions, preserving the column map, record prototype and
 * snapshot behavior of this resultset.
 *
 * @param array $indexes zero-based row positions, in the desired order
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, sliceRows)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *indexes_param = NULL, __$false, __$null, index, resultset, row, *_0, _2, _5, _6, _8, _9, _1$$3, _4$$5;
	zval indexes, sliced, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&sliced);
	ZVAL_UNDEF(&_7);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rows", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("columnMap", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("keepSnapshots", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("count", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(indexes, indexes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &indexes_param);
	zephir_get_arrval(&indexes, indexes_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "materialize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sliced);
	array_init(&sliced);
	zephir_is_iterable(&indexes, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 280);
	if (Z_TYPE_P(&indexes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _0)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _0);
			ZEPHIR_OBS_NVAR(&row);
			zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1114, PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_fetch(&row, &_1$$3, &index, 0)) {
				zephir_array_append(&sliced, &row, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Simple.zep", 276);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_2, &indexes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&row);
				zephir_read_property_cached(&_4$$5, this_ptr, _zephir_prop_0, 1114, PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_fetch(&row, &_4$$5, &index, 0)) {
					zephir_array_append(&sliced, &row, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Simple.zep", 276);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_get_class(&_6, this_ptr, 0);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 5, 0);
	zephir_memory_observe(&_8);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_1, 1110, PH_NOISY_CC);
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_OBS_NVAR(&_8);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_2, 1109, PH_NOISY_CC);
	zephir_array_fast_append(&_7, &_8);
	zephir_array_fast_append(&_7, &__$false);
	zephir_array_fast_append(&_7, &__$null);
	ZEPHIR_OBS_NVAR(&_8);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_3, 1111, PH_NOISY_CC);
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_5, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&resultset, &_5);
	zephir_update_property_zval_cached(&resultset, _zephir_prop_0, 0, &sliced);
	ZVAL_UNDEF(&_9);
	ZVAL_LONG(&_9, zephir_fast_count_int(&sliced));
	zephir_update_property_zval_cached(&resultset, _zephir_prop_4, 0, &_9);
	RETURN_CCTOR(&resultset);
}

/**
 * Returns a complete resultset as an array, if the resultset has a big
 * number of rows it could consume more memory than currently it does.
 * Export the resultset to an array couldn't be faster with a large number
 * of records
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray)
{
	zend_string *_6$$6, *_18$$17;
	zend_ulong _5$$6, _17$$17;
	zval renamedRecords, renamed;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *renameColumns_param = NULL, records, record, renamedKey, key, value, columnMap, _1, _2$$3, *_3$$5, _14$$5, *_4$$6, _10$$6, _7$$9, _9$$11, _12$$14, _13$$16, *_16$$17, _21$$17, _19$$20, _20$$22, _23$$25, _24$$27;
	zend_bool renameColumns, _0, _15$$5, _11$$6, _22$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&renamedKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_24$$27);
	ZVAL_UNDEF(&renamedRecords);
	ZVAL_UNDEF(&renamed);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rows", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("columnMap", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(renameColumns)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &renameColumns_param);
	if (!renameColumns_param) {
		renameColumns = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "materialize", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&records);
	zephir_read_property_cached(&records, this_ptr, _zephir_prop_0, 1114, PH_NOISY_CC);
	_0 = renameColumns;
	if (_0) {
		zephir_memory_observe(&_1);
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1109, PH_NOISY_CC);
		_0 = !(zephir_instance_of_ev(&_1, phalcon_mvc_model_row_ce));
	}
	if (_0) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_2, 1110, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&columnMap, &_2$$3);
		if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
			RETURN_CCTOR(&records);
		}
		ZEPHIR_INIT_VAR(&renamedRecords);
		array_init(&renamedRecords);
		if (Z_TYPE_P(&records) == IS_ARRAY) {
			zephir_is_iterable(&records, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 361);
			if (Z_TYPE_P(&records) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&records), _3$$5)
				{
					ZEPHIR_INIT_NVAR(&record);
					ZVAL_COPY(&record, _3$$5);
					ZEPHIR_INIT_NVAR(&renamed);
					array_init(&renamed);
					zephir_is_iterable(&record, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 359);
					if (Z_TYPE_P(&record) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _5$$6, _6$$6, _4$$6)
						{
							ZEPHIR_INIT_NVAR(&key);
							if (_6$$6 != NULL) { 
								ZVAL_STR_COPY(&key, _6$$6);
							} else {
								ZVAL_LONG(&key, _5$$6);
							}
							ZEPHIR_INIT_NVAR(&value);
							ZVAL_COPY(&value, _4$$6);
							if (Z_TYPE_P(&key) == IS_STRING) {
								ZEPHIR_OBS_NVAR(&renamedKey);
								if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
									ZEPHIR_INIT_NVAR(&_7$$9);
									object_init_ex(&_7$$9, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
									ZEPHIR_CALL_METHOD(NULL, &_7$$9, "__construct", &_8, 0, &key);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_7$$9, "phalcon/Mvc/Model/Resultset/Simple.zep", 343);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
										ZEPHIR_INIT_NVAR(&_9$$11);
										object_init_ex(&_9$$11, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
										ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", &_8, 0, &key);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_9$$11, "phalcon/Mvc/Model/Resultset/Simple.zep", 348);
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &record, "rewind", NULL, 0);
						zephir_check_call_status();
						_11$$6 = 1;
						while (1) {
							if (_11$$6) {
								_11$$6 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &record, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_10$$6, &record, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_10$$6)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&key, &record, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&value, &record, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&key) == IS_STRING) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
										ZEPHIR_INIT_NVAR(&_12$$14);
										object_init_ex(&_12$$14, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
										ZEPHIR_CALL_METHOD(NULL, &_12$$14, "__construct", &_8, 0, &key);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_12$$14, "phalcon/Mvc/Model/Resultset/Simple.zep", 343);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&renamedKey);
										if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
											ZEPHIR_INIT_NVAR(&_13$$16);
											object_init_ex(&_13$$16, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
											ZEPHIR_CALL_METHOD(NULL, &_13$$16, "__construct", &_8, 0, &key);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_13$$16, "phalcon/Mvc/Model/Resultset/Simple.zep", 348);
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
									zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
								}
						}
					}
					ZEPHIR_INIT_NVAR(&value);
					ZEPHIR_INIT_NVAR(&key);
					zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Simple.zep", 359);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
				zephir_check_call_status();
				_15$$5 = 1;
				while (1) {
					if (_15$$5) {
						_15$$5 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &records, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_14$$5, &records, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&record, &records, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&renamed);
						array_init(&renamed);
						zephir_is_iterable(&record, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 359);
						if (Z_TYPE_P(&record) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _17$$17, _18$$17, _16$$17)
							{
								ZEPHIR_INIT_NVAR(&key);
								if (_18$$17 != NULL) { 
									ZVAL_STR_COPY(&key, _18$$17);
								} else {
									ZVAL_LONG(&key, _17$$17);
								}
								ZEPHIR_INIT_NVAR(&value);
								ZVAL_COPY(&value, _16$$17);
								if (Z_TYPE_P(&key) == IS_STRING) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
										ZEPHIR_INIT_NVAR(&_19$$20);
										object_init_ex(&_19$$20, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
										ZEPHIR_CALL_METHOD(NULL, &_19$$20, "__construct", &_8, 0, &key);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_19$$20, "phalcon/Mvc/Model/Resultset/Simple.zep", 343);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&renamedKey);
										if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
											ZEPHIR_INIT_NVAR(&_20$$22);
											object_init_ex(&_20$$22, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
											ZEPHIR_CALL_METHOD(NULL, &_20$$22, "__construct", &_8, 0, &key);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_20$$22, "phalcon/Mvc/Model/Resultset/Simple.zep", 348);
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
									zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &record, "rewind", NULL, 0);
							zephir_check_call_status();
							_22$$17 = 1;
							while (1) {
								if (_22$$17) {
									_22$$17 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &record, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_21$$17, &record, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_21$$17)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&key, &record, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&value, &record, "current", NULL, 0);
								zephir_check_call_status();
									if (Z_TYPE_P(&key) == IS_STRING) {
										ZEPHIR_OBS_NVAR(&renamedKey);
										if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
											ZEPHIR_INIT_NVAR(&_23$$25);
											object_init_ex(&_23$$25, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
											ZEPHIR_CALL_METHOD(NULL, &_23$$25, "__construct", &_8, 0, &key);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_23$$25, "phalcon/Mvc/Model/Resultset/Simple.zep", 343);
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&renamedKey);
											if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
												ZEPHIR_INIT_NVAR(&_24$$27);
												object_init_ex(&_24$$27, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
												ZEPHIR_CALL_METHOD(NULL, &_24$$27, "__construct", &_8, 0, &key);
												zephir_check_call_status();
												zephir_throw_exception_debug(&_24$$27, "phalcon/Mvc/Model/Resultset/Simple.zep", 348);
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
										zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
									}
							}
						}
						ZEPHIR_INIT_NVAR(&value);
						ZEPHIR_INIT_NVAR(&key);
						zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Simple.zep", 359);
				}
			}
			ZEPHIR_INIT_NVAR(&record);
		}
		RETURN_CTOR(&renamedRecords);
	}
	RETURN_CCTOR(&records);
}

/**
 * Unserializing a resultset will allow to only works on the rows present in
 * the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, resultset, keepSnapshots, container, serializer, _1, _2, _6, _7, _8, _9, _10, _11, _12, _0$$3, _3$$4, _4$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("rows", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("count", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("columnMap", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("hydrateMode", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("keepSnapshots", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Simple.zep", 379);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "serializer");
	ZEPHIR_CALL_METHOD(&_1, &container, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "serializer");
		ZEPHIR_CALL_METHOD(&_3$$4, &container, "getshared", NULL, 0, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_3$$4);
		ZEPHIR_CALL_METHOD(NULL, &serializer, "unserialize", NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&resultset, &serializer, "getdata", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 26, data);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&resultset) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_5$$6);
		object_init_ex(&_5$$6, phalcon_mvc_model_exceptions_invalidserializationdata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model/Resultset/Simple.zep", 392);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_6, &resultset, SL("model"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 395);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1109, &_6);
	zephir_array_fetch_string(&_7, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 396);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1114, &_7);
	zephir_array_fetch_string(&_8, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 397);
	ZVAL_UNDEF(&_9);
	ZVAL_LONG(&_9, zephir_fast_count_int(&_8));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1115, &_9);
	zephir_array_fetch_string(&_10, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 398);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1112, &_10);
	zephir_array_fetch_string(&_11, &resultset, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 399);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1110, &_11);
	zephir_array_fetch_string(&_12, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 400);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1113, &_12);
	if (zephir_array_isset_string_fetch(&keepSnapshots, &resultset, SL("keepSnapshots"), 1)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1111, &keepSnapshots);
	}
	ZEPHIR_MM_RESTORE();
}

