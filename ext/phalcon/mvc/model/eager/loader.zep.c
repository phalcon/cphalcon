
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
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
 * Loads model relations in bulk - a bounded number of queries per relation
 * node rather than one per record - and applies the result to records as they
 * are hydrated.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Eager_Loader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Eager, Loader, phalcon, mvc_model_eager_loader, phalcon_mvc_model_eager_loader_method_entry, 0);

	/**
	 * @var ManagerInterface
	 */
	zend_declare_property_null(phalcon_mvc_model_eager_loader_ce, SL("manager"), ZEND_ACC_PROTECTED);
	/**
	 * Maximum number of rows a single relation node may return before the load
	 * is refused. Guards against a to-many hop that follows a to-one hop, which
	 * can fan out to an entire table.
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_eager_loader_ce, SL("MAX_ROWS_PER_LEVEL"), 100000);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, __construct)
{
	zval *manager, manager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(manager, phalcon_mvc_model_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &manager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1010, manager);
}

/**
 * Applies a pre-built eager map to a single record.
 *
 * Shared by Resultset\Simple::current(), which stamps records as they are
 * hydrated, and by the loader itself, which stamps instances it retains.
 *
 * Both Model and Row implement readAttribute(), so key extraction is
 * uniform; only the write differs. A Row is what a column-restricted
 * select produces, and it has no relation cache.
 *
 * @param object $record ModelInterface or Row
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, apply)
{
	zend_bool _16, _7$$3, _21$$10;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_19 = NULL, *_23 = NULL, *_25 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval eagerMap, values;
	zval *record, record_sub, *eagerMap_param = NULL, __$null, __$true, alias, field, fields, lookup, node, records, related, *_0, _15, *_3$$3, _6$$3, _10$$3, _4$$4, _8$$5, *_17$$10, _20$$10, _24$$10, _18$$11, _22$$12;

	ZVAL_UNDEF(&record_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&lookup);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&eagerMap);
	ZVAL_UNDEF(&values);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(record)
		ZEPHIR_Z_PARAM_ARRAY(eagerMap, eagerMap_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &record, &eagerMap_param);
	zephir_get_arrval(&eagerMap, eagerMap_param);
	zephir_is_iterable(&eagerMap, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 91);
	if (Z_TYPE_P(&eagerMap) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&eagerMap), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&alias);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&alias, _2);
			} else {
				ZVAL_LONG(&alias, _1);
			}
			ZEPHIR_INIT_NVAR(&node);
			ZVAL_COPY(&node, _0);
			ZEPHIR_OBS_NVAR(&fields);
			zephir_array_fetch_string(&fields, &node, SL("fields"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 67);
			ZEPHIR_INIT_NVAR(&values);
			array_init(&values);
			zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 74);
			if (Z_TYPE_P(&fields) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3$$3)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _3$$3);
					ZEPHIR_CALL_METHOD(&_4$$4, record, "readattribute", &_5, 0, &field);
					zephir_check_call_status();
					zephir_array_append(&values, &_4$$4, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 71);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
				zephir_check_call_status();
				_7$$3 = 1;
				while (1) {
					if (_7$$3) {
						_7$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_6$$3, &fields, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_6$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_8$$5, record, "readattribute", &_9, 0, &field);
						zephir_check_call_status();
						zephir_array_append(&values, &_8$$5, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 71);
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			ZEPHIR_OBS_NVAR(&records);
			zephir_array_fetch_string(&records, &node, SL("records"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 74);
			ZEPHIR_OBS_NVAR(&related);
			zephir_array_fetch_string(&related, &node, SL("empty"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 75);
			ZEPHIR_CALL_FUNCTION(&_10$$3, "in_array", &_11, 87, &__$null, &values, &__$true);
			zephir_check_call_status();
			if (!(zephir_is_true(&_10$$3))) {
				ZEPHIR_CALL_SELF(&lookup, "buildkey", &_12, 0, &values);
				zephir_check_call_status();
				if (zephir_array_isset_value(&records, &lookup)) {
					ZEPHIR_OBS_NVAR(&related);
					zephir_array_fetch(&related, &records, &lookup, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 81);
				}
			}
			if (zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce)) {
				ZEPHIR_CALL_METHOD(NULL, record, "setrelated", &_13, 0, &alias, &related);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, record, "writeattribute", &_14, 0, &alias, &related);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &eagerMap, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &eagerMap, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, &eagerMap, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, &eagerMap, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&node, &eagerMap, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&fields);
				zephir_array_fetch_string(&fields, &node, SL("fields"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 67);
				ZEPHIR_INIT_NVAR(&values);
				array_init(&values);
				zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 74);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _17$$10)
					{
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _17$$10);
						ZEPHIR_CALL_METHOD(&_18$$11, record, "readattribute", &_19, 0, &field);
						zephir_check_call_status();
						zephir_array_append(&values, &_18$$11, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 71);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
					zephir_check_call_status();
					_21$$10 = 1;
					while (1) {
						if (_21$$10) {
							_21$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_20$$10, &fields, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_20$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_22$$12, record, "readattribute", &_23, 0, &field);
							zephir_check_call_status();
							zephir_array_append(&values, &_22$$12, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 71);
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_OBS_NVAR(&records);
				zephir_array_fetch_string(&records, &node, SL("records"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 74);
				ZEPHIR_OBS_NVAR(&related);
				zephir_array_fetch_string(&related, &node, SL("empty"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 75);
				ZEPHIR_CALL_FUNCTION(&_24$$10, "in_array", &_11, 87, &__$null, &values, &__$true);
				zephir_check_call_status();
				if (!(zephir_is_true(&_24$$10))) {
					ZEPHIR_CALL_SELF(&lookup, "buildkey", &_12, 0, &values);
					zephir_check_call_status();
					if (zephir_array_isset_value(&records, &lookup)) {
						ZEPHIR_OBS_NVAR(&related);
						zephir_array_fetch(&related, &records, &lookup, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 81);
					}
				}
				if (zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce)) {
					ZEPHIR_CALL_METHOD(NULL, record, "setrelated", &_25, 0, &alias, &related);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(NULL, record, "writeattribute", &_26, 0, &alias, &related);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&node);
	ZEPHIR_INIT_NVAR(&alias);
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds the lookup key for a set of key-field values.
 *
 * Always a string. A single value is cast, which also neutralizes the
 * PostgreSQL-integer / MySQL-string mismatch for the same column. Multiple
 * values are length-prefixed so ["a|b", "c"] cannot collide with
 * ["a", "b|c"].
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildKey)
{
	zend_bool _7;
	zval key, _1$$3, _3$$4, _8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, part, value, *_2, _6, _0$$3, _4$$4, _5$$4, _9$$5, _10$$5;
	zval values;

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_8$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &values_param);
	zephir_get_arrval(&values, values_param);
	if (zephir_fast_count_int(&values) == 1) {
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_long(&_0$$3, &values, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 107);
		zephir_cast_to_string(&_1$$3, &_0$$3);
		RETURN_CTOR(&_1$$3);
	}
	ZEPHIR_INIT_VAR(&key);
	ZVAL_STRING(&key, "");
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 117);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _2)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			zephir_cast_to_string(&_3$$4, &value);
			ZEPHIR_CPY_WRT(&part, &_3$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, zephir_fast_strlen_ev(&part));
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZEPHIR_CONCAT_VVSV(&_5$$4, &key, &_4$$4, ":", &part);
			zephir_get_strval(&key, &_5$$4);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				zephir_cast_to_string(&_8$$5, &value);
				ZEPHIR_CPY_WRT(&part, &_8$$5);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_LONG(&_9$$5, zephir_fast_strlen_ev(&part));
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZEPHIR_CONCAT_VVSV(&_10$$5, &key, &_9$$5, ":", &part);
				zephir_get_strval(&key, &_10$$5);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETURN_CTOR(&key);
}

/**
 * Loads a relation tree for a root resultset.
 *
 * The resultset is materialized first: at this point the statement has run
 * but no row has been consumed, so fetching every row costs nothing extra
 * and gives the key values without a second pass over the cursor.
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, loadResultset)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tree;
	zend_string *modelName = NULL;
	zval *resultset, resultset_sub, modelName_zv, *tree_param = NULL, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&modelName_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&tree);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(resultset, phalcon_mvc_model_resultset_simple_ce)
		Z_PARAM_STR(modelName)
		ZEPHIR_Z_PARAM_ARRAY(tree, tree_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	resultset = ZEND_CALL_ARG(execute_data, 1);
	tree_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&modelName_zv);
	ZVAL_STR_COPY(&modelName_zv, modelName);
	zephir_get_arrval(&tree, tree_param);
	_0 = ZEPHIR_IS_EMPTY(&tree);
	if (!(_0)) {
		ZEPHIR_CALL_METHOD(&_1, resultset, "count", NULL, 208);
		zephir_check_call_status();
		_0 = ZEPHIR_IS_LONG_IDENTICAL(&_1, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(NULL, resultset, "materialize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, resultset, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildmap", NULL, 0, &_3, &modelName_zv, &tree);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, resultset, "seteagermap", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds one level of the map.
 *
 * @param array $parents attribute-keyed row arrays at the root, or
 *                       ModelInterface / Row instances below it
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildMap)
{
	zend_bool _10;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *modelName = NULL, *_2;
	zval *parents_param = NULL, modelName_zv, *tree_param = NULL, alias, node, relation, *_0, _9, _3$$3, _6$$3, _8$$3, _4$$4, _11$$5, _13$$5, _14$$5, _12$$6;
	zval parents, tree, map;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parents);
	ZVAL_UNDEF(&tree);
	ZVAL_UNDEF(&map);
	ZVAL_UNDEF(&modelName_zv);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_12$$6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(parents, parents_param)
		Z_PARAM_STR(modelName)
		ZEPHIR_Z_PARAM_ARRAY(tree, tree_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	parents_param = ZEND_CALL_ARG(execute_data, 1);
	tree_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_get_arrval(&parents, parents_param);
	zephir_memory_observe(&modelName_zv);
	ZVAL_STR_COPY(&modelName_zv, modelName);
	zephir_get_arrval(&tree, tree_param);
	ZEPHIR_INIT_VAR(&map);
	array_init(&map);
	zephir_is_iterable(&tree, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 174);
	if (Z_TYPE_P(&tree) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&tree), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&alias);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&alias, _2);
			} else {
				ZVAL_LONG(&alias, _1);
			}
			ZEPHIR_INIT_NVAR(&node);
			ZVAL_COPY(&node, _0);
			zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 1010, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&relation, &_3$$3, "getrelationbyalias", NULL, 0, &modelName_zv, &alias);
			zephir_check_call_status();
			if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				object_init_ex(&_4$$4, phalcon_mvc_model_exceptions_unknowneagerrelation_ce);
				ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", &_5, 0, &modelName_zv, &alias);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Model/Eager/Loader.zep", 163);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "buildnode", &_7, 0, &relation, &alias, &parents, &node);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$3);
			zephir_fast_strtolower(&_8$$3, &alias);
			zephir_array_update_zval(&map, &_8$$3, &_6$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &tree, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &tree, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &tree, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, &tree, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&node, &tree, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_11$$5, this_ptr, _zephir_prop_0, 1010, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&relation, &_11$$5, "getrelationbyalias", NULL, 0, &modelName_zv, &alias);
				zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(&_12$$6);
					object_init_ex(&_12$$6, phalcon_mvc_model_exceptions_unknowneagerrelation_ce);
					ZEPHIR_CALL_METHOD(NULL, &_12$$6, "__construct", &_5, 0, &modelName_zv, &alias);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$6, "phalcon/Mvc/Model/Eager/Loader.zep", 163);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_13$$5, this_ptr, "buildnode", &_7, 0, &relation, &alias, &parents, &node);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$5);
				zephir_fast_strtolower(&_14$$5, &alias);
				zephir_array_update_zval(&map, &_14$$5, &_13$$5, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&node);
	ZEPHIR_INIT_NVAR(&alias);
	RETURN_CTOR(&map);
}

/**
 * Builds a single map node: one query, indexed by the referenced field.
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildNode)
{
	zend_ulong _13, _23$$9;
	zend_bool isMany = 0, _19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0;
	zval parents, node, childModels, index, records;
	zend_string *alias = NULL, *_14, *_24$$9;
	zval *relation, relation_sub, alias_zv, *parents_param = NULL, *node_param = NULL, childMap, children, emptyResult, fields, keys, keyValue, positions, record, referencedFields, sub, children2, _0, _1, _2, _3, _4, _10, _11, *_12, _18, _8$$4, _15$$6, _16$$7, _17$$7, _20$$8, _21$$8, *_22$$9, *_25$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&childMap);
	ZVAL_UNDEF(&children);
	ZVAL_UNDEF(&emptyResult);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&keyValue);
	ZVAL_UNDEF(&positions);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&sub);
	ZVAL_UNDEF(&children2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&parents);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&childModels);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&records);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(relation, phalcon_mvc_model_relationinterface_ce)
		Z_PARAM_STR(alias)
		ZEPHIR_Z_PARAM_ARRAY(parents, parents_param)
		ZEPHIR_Z_PARAM_ARRAY(node, node_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	relation = ZEND_CALL_ARG(execute_data, 1);
	parents_param = ZEND_CALL_ARG(execute_data, 3);
	node_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	zephir_get_arrval(&parents, parents_param);
	zephir_get_arrval(&node, node_param);
	ZEPHIR_CALL_METHOD(&_0, relation, "isthrough", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "buildthroughnode", NULL, 0, relation, &alias_zv, &parents, &node);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "normalizefields", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, this_ptr, "normalizefields", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&keys, this_ptr, "collectkeys", NULL, 0, &parents, &fields, &alias_zv);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, &node, SL("options"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 208);
	ZEPHIR_CALL_METHOD(&children, this_ptr, "fetchreferenced", NULL, 0, relation, &alias_zv, &keys, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&childModels);
	array_init(&childModels);
	ZEPHIR_INIT_VAR(&index);
	array_init(&index);
	position = 0;
	ZEPHIR_CALL_METHOD(NULL, &children, "rewind", NULL, 209);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_4, &children, "valid", &_5, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_4))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, &children, "current", &_6, 0);
		zephir_check_call_status();
		zephir_array_append(&childModels, &record, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 219);
		ZEPHIR_CALL_METHOD(&keyValue, this_ptr, "recordkey", &_7, 0, &record, &referencedFields);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$4);
		ZVAL_LONG(&_8$$4, position);
		zephir_array_update_multi(&index, &_8$$4, SL("za"), 2, &keyValue);
		position++;
		ZEPHIR_CALL_METHOD(NULL, &children, "next", &_9, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_10, relation, "gettype", NULL, 0);
	zephir_check_call_status();
	isMany = ZEPHIR_IS_LONG_IDENTICAL(&_10, 2);
	if (isMany) {
		ZEPHIR_INIT_VAR(&_11);
		array_init(&_11);
		ZEPHIR_CALL_METHOD(&emptyResult, &children, "slicerows", NULL, 0, &_11);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&emptyResult);
		ZVAL_NULL(&emptyResult);
	}
	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	zephir_is_iterable(&index, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 248);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&index), _13, _14, _12)
	{
		ZEPHIR_INIT_NVAR(&keyValue);
		if (_14 != NULL) { 
			ZVAL_STR_COPY(&keyValue, _14);
		} else {
			ZVAL_LONG(&keyValue, _13);
		}
		ZEPHIR_INIT_NVAR(&positions);
		ZVAL_COPY(&positions, _12);
		if (isMany) {
			ZEPHIR_CALL_METHOD(&_15$$6, &children, "slicerows", NULL, 0, &positions);
			zephir_check_call_status();
			zephir_array_update_zval(&records, &keyValue, &_15$$6, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_OBS_NVAR(&_17$$7);
			zephir_array_fetch_long(&_17$$7, &positions, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 239);
			zephir_array_fetch(&_16$$7, &childModels, &_17$$7, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 239);
			zephir_array_update_zval(&records, &keyValue, &_16$$7, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&positions);
	ZEPHIR_INIT_NVAR(&keyValue);
	zephir_array_fetch_string(&_18, &node, SL("children"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 248);
	_19 = !(ZEPHIR_IS_EMPTY(&_18));
	if (_19) {
		_19 = !(ZEPHIR_IS_EMPTY(&childModels));
	}
	if (_19) {
		ZEPHIR_CALL_METHOD(&_20$$8, relation, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_21$$8, &node, SL("children"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 253);
		ZEPHIR_CALL_METHOD(&childMap, this_ptr, "buildmap", NULL, 0, &childModels, &_20$$8, &_21$$8);
		zephir_check_call_status();
		if (isMany) {
			zephir_is_iterable(&records, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 267);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&records), _23$$9, _24$$9, _22$$9)
			{
				ZEPHIR_INIT_NVAR(&keyValue);
				if (_24$$9 != NULL) { 
					ZVAL_STR_COPY(&keyValue, _24$$9);
				} else {
					ZVAL_LONG(&keyValue, _23$$9);
				}
				ZEPHIR_INIT_NVAR(&sub);
				ZVAL_COPY(&sub, _22$$9);
				ZEPHIR_CPY_WRT(&children2, &sub);
				ZEPHIR_CALL_METHOD(NULL, &children2, "seteagermap", NULL, 0, &childMap);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&sub);
			ZEPHIR_INIT_NVAR(&keyValue);
			ZEPHIR_CALL_METHOD(NULL, &emptyResult, "seteagermap", NULL, 0, &childMap);
			zephir_check_call_status();
		} else {
			zephir_is_iterable(&childModels, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 272);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&childModels), _25$$11)
			{
				ZEPHIR_INIT_NVAR(&record);
				ZVAL_COPY(&record, _25$$11);
				ZEPHIR_CALL_SELF(NULL, "apply", &_26, 0, &record, &childMap);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&record);
		}
	}
	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("fields"), &fields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("records"), &records, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("empty"), &emptyResult, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Through-relations in two steps rather than a join.
 *
 * Step one fetches (parentKey, referencedKey) pairs from the intermediate
 * model; step two fetches the referenced rows for the keys those pairs
 * collected. The pairs then attribute referenced rows back to parents
 * without a synthetic column in the select list, and without the row
 * multiplication an inner join would cause.
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildThroughNode)
{
	zend_ulong _31, _46$$15;
	zend_bool isMany = 0, _42, _36$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL, *_20 = NULL, *_24 = NULL, *_25 = NULL, *_26 = NULL, *_28 = NULL, *_49 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0;
	zval parents, node, childModels, index, pairMap, records, _5$$3, _9$$3, _10$$3, _12$$3, _16$$4, _18$$4, _19$$4;
	zend_string *alias = NULL, *_32, *_47$$15;
	zval *relation, relation_sub, alias_zv, *parents_param = NULL, *node_param = NULL, childMap, emptyResult, fields, intermediateField, intermediateFields, intermediateModel, intermediateReferencedField, intermediateReferencedFields, keyValue, keys, pair, pairs, parentKey, positions, record, referenced, referencedFields, referencedKey, referencedKeys, slice, sub, tuple, _0, _1, _2, _3, _4, _21, _22, _23, _29, *_30, _41, _6$$3, _7$$3, _8$$3, _11$$3, _13$$3, _17$$4, _27$$5, *_33$$6, _35$$6, _34$$8, _37$$10, _38$$12, _39$$13, _40$$13, _43$$14, _44$$14, *_45$$15, *_48$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&childMap);
	ZVAL_UNDEF(&emptyResult);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&intermediateField);
	ZVAL_UNDEF(&intermediateFields);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&intermediateReferencedField);
	ZVAL_UNDEF(&intermediateReferencedFields);
	ZVAL_UNDEF(&keyValue);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&pair);
	ZVAL_UNDEF(&pairs);
	ZVAL_UNDEF(&parentKey);
	ZVAL_UNDEF(&positions);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&referenced);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&referencedKey);
	ZVAL_UNDEF(&referencedKeys);
	ZVAL_UNDEF(&slice);
	ZVAL_UNDEF(&sub);
	ZVAL_UNDEF(&tuple);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_35$$6);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_39$$13);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_43$$14);
	ZVAL_UNDEF(&_44$$14);
	ZVAL_UNDEF(&parents);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&childModels);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&pairMap);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(relation, phalcon_mvc_model_relationinterface_ce)
		Z_PARAM_STR(alias)
		ZEPHIR_Z_PARAM_ARRAY(parents, parents_param)
		ZEPHIR_Z_PARAM_ARRAY(node, node_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	relation = ZEND_CALL_ARG(execute_data, 1);
	parents_param = ZEND_CALL_ARG(execute_data, 3);
	node_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	zephir_get_arrval(&parents, parents_param);
	zephir_get_arrval(&node, node_param);
	ZEPHIR_CALL_METHOD(&_0, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "normalizefields", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, relation, "getintermediatefields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateFields, this_ptr, "normalizefields", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, this_ptr, "normalizefields", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, relation, "getintermediatereferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateReferencedFields, this_ptr, "normalizefields", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_memory_observe(&intermediateField);
	zephir_array_fetch_long(&intermediateField, &intermediateFields, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 317);
	zephir_memory_observe(&intermediateReferencedField);
	zephir_array_fetch_long(&intermediateReferencedField, &intermediateReferencedFields, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 318);
	ZEPHIR_CALL_METHOD(&intermediateModel, relation, "getintermediatemodel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, relation, "gettype", NULL, 0);
	zephir_check_call_status();
	isMany = ZEPHIR_IS_LONG_IDENTICAL(&_4, 4);
	ZEPHIR_CALL_METHOD(&keys, this_ptr, "collectkeys", NULL, 0, &parents, &fields, &alias_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pairMap);
	array_init(&pairMap);
	ZEPHIR_INIT_VAR(&referencedKeys);
	array_init(&referencedKeys);
	if (!(ZEPHIR_IS_EMPTY(&keys))) {
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0);
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 1010, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$3, &_6$$3, "load", NULL, 0, &intermediateModel);
		zephir_check_call_status();
		zephir_array_fast_append(&_5$$3, &_7$$3);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "find");
		zephir_array_fast_append(&_5$$3, &_8$$3);
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_create_array(&_9$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_10$$3);
		zephir_create_array(&_10$$3, 3, 0);
		ZEPHIR_INIT_VAR(&_11$$3);
		ZEPHIR_CONCAT_SVS(&_11$$3, "[", &intermediateField, "] IN ({phEagerKeys:array})");
		zephir_array_fast_append(&_10$$3, &_11$$3);
		ZEPHIR_INIT_NVAR(&_11$$3);
		ZEPHIR_CONCAT_VSV(&_11$$3, &intermediateField, ", ", &intermediateReferencedField);
		zephir_array_update_string(&_10$$3, SL("columns"), &_11$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_12$$3);
		zephir_create_array(&_12$$3, 1, 0);
		ZVAL_LONG(&_13$$3, 0);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "array_column", NULL, 333, &keys, &_13$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_12$$3, SL("phEagerKeys"), &_7$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_10$$3, SL("bind"), &_12$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_9$$3, &_10$$3);
		ZEPHIR_INIT_VAR(&pairs);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&pairs, &_5$$3, &_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &pairs, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7$$3, &pairs, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_7$$3))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&pair, &pairs, "current", &_14, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_16$$4);
			zephir_create_array(&_16$$4, 1, 0);
			ZEPHIR_CALL_METHOD(&_17$$4, &pair, "readattribute", NULL, 0, &intermediateField);
			zephir_check_call_status();
			zephir_array_fast_append(&_16$$4, &_17$$4);
			ZEPHIR_CALL_SELF(&parentKey, "buildkey", &_15, 0, &_16$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_18$$4);
			zephir_create_array(&_18$$4, 1, 0);
			ZEPHIR_CALL_METHOD(&_17$$4, &pair, "readattribute", NULL, 0, &intermediateReferencedField);
			zephir_check_call_status();
			zephir_array_fast_append(&_18$$4, &_17$$4);
			ZEPHIR_CALL_SELF(&referencedKey, "buildkey", &_15, 0, &_18$$4);
			zephir_check_call_status();
			zephir_array_update_multi(&pairMap, &referencedKey, SL("za"), 2, &parentKey);
			ZEPHIR_INIT_NVAR(&_19$$4);
			zephir_create_array(&_19$$4, 1, 0);
			ZEPHIR_CALL_METHOD(&_17$$4, &pair, "readattribute", NULL, 0, &intermediateReferencedField);
			zephir_check_call_status();
			zephir_array_fast_append(&_19$$4, &_17$$4);
			zephir_array_update_zval(&referencedKeys, &referencedKey, &_19$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &pairs, "next", &_20, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(&_21, "array_values", NULL, 27, &referencedKeys);
	zephir_check_call_status();
	zephir_array_fetch_string(&_22, &node, SL("options"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 375);
	ZEPHIR_CALL_METHOD(&referenced, this_ptr, "fetchreferenced", NULL, 0, relation, &alias_zv, &_21, &_22);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&childModels);
	array_init(&childModels);
	ZEPHIR_INIT_VAR(&index);
	array_init(&index);
	position = 0;
	ZEPHIR_CALL_METHOD(NULL, &referenced, "rewind", NULL, 209);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_23, &referenced, "valid", &_24, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_23))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, &referenced, "current", &_25, 0);
		zephir_check_call_status();
		zephir_array_append(&childModels, &record, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 386);
		ZEPHIR_CALL_METHOD(&keyValue, this_ptr, "recordkey", &_26, 0, &record, &referencedFields);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_27$$5);
		ZVAL_LONG(&_27$$5, position);
		zephir_array_update_multi(&index, &_27$$5, SL("za"), 2, &keyValue);
		position++;
		ZEPHIR_CALL_METHOD(NULL, &referenced, "next", &_28, 0);
		zephir_check_call_status();
	}
	if (isMany) {
		ZEPHIR_INIT_VAR(&_29);
		array_init(&_29);
		ZEPHIR_CALL_METHOD(&emptyResult, &referenced, "slicerows", NULL, 0, &_29);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&emptyResult);
		ZVAL_NULL(&emptyResult);
	}
	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	zephir_is_iterable(&pairMap, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 421);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&pairMap), _31, _32, _30)
	{
		ZEPHIR_INIT_NVAR(&parentKey);
		if (_32 != NULL) { 
			ZVAL_STR_COPY(&parentKey, _32);
		} else {
			ZVAL_LONG(&parentKey, _31);
		}
		ZEPHIR_INIT_NVAR(&positions);
		ZVAL_COPY(&positions, _30);
		ZEPHIR_INIT_NVAR(&tuple);
		array_init(&tuple);
		zephir_is_iterable(&positions, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 410);
		if (Z_TYPE_P(&positions) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&positions), _33$$6)
			{
				ZEPHIR_INIT_NVAR(&referencedKey);
				ZVAL_COPY(&referencedKey, _33$$6);
				ZEPHIR_OBS_NVAR(&sub);
				if (zephir_array_isset_fetch(&sub, &index, &referencedKey, 0)) {
					ZEPHIR_INIT_NVAR(&_34$$8);
					zephir_fast_array_merge(&_34$$8, &tuple, &sub);
					ZEPHIR_CPY_WRT(&tuple, &_34$$8);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &positions, "rewind", NULL, 0);
			zephir_check_call_status();
			_36$$6 = 1;
			while (1) {
				if (_36$$6) {
					_36$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &positions, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_35$$6, &positions, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_35$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&referencedKey, &positions, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&sub);
					if (zephir_array_isset_fetch(&sub, &index, &referencedKey, 0)) {
						ZEPHIR_INIT_NVAR(&_37$$10);
						zephir_fast_array_merge(&_37$$10, &tuple, &sub);
						ZEPHIR_CPY_WRT(&tuple, &_37$$10);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&referencedKey);
		if (ZEPHIR_IS_EMPTY(&tuple)) {
			continue;
		}
		if (isMany) {
			ZEPHIR_CALL_METHOD(&_38$$12, &referenced, "slicerows", NULL, 0, &tuple);
			zephir_check_call_status();
			zephir_array_update_zval(&records, &parentKey, &_38$$12, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_OBS_NVAR(&_40$$13);
			zephir_array_fetch_long(&_40$$13, &tuple, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 417);
			zephir_array_fetch(&_39$$13, &childModels, &_40$$13, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 417);
			zephir_array_update_zval(&records, &parentKey, &_39$$13, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&positions);
	ZEPHIR_INIT_NVAR(&parentKey);
	zephir_array_fetch_string(&_41, &node, SL("children"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 421);
	_42 = !(ZEPHIR_IS_EMPTY(&_41));
	if (_42) {
		_42 = !(ZEPHIR_IS_EMPTY(&childModels));
	}
	if (_42) {
		ZEPHIR_CALL_METHOD(&_43$$14, relation, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_44$$14, &node, SL("children"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 426);
		ZEPHIR_CALL_METHOD(&childMap, this_ptr, "buildmap", NULL, 0, &childModels, &_43$$14, &_44$$14);
		zephir_check_call_status();
		if (isMany) {
			zephir_is_iterable(&records, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 435);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&records), _46$$15, _47$$15, _45$$15)
			{
				ZEPHIR_INIT_NVAR(&keyValue);
				if (_47$$15 != NULL) { 
					ZVAL_STR_COPY(&keyValue, _47$$15);
				} else {
					ZVAL_LONG(&keyValue, _46$$15);
				}
				ZEPHIR_INIT_NVAR(&sub);
				ZVAL_COPY(&sub, _45$$15);
				ZEPHIR_CPY_WRT(&slice, &sub);
				ZEPHIR_CALL_METHOD(NULL, &slice, "seteagermap", NULL, 0, &childMap);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&sub);
			ZEPHIR_INIT_NVAR(&keyValue);
			ZEPHIR_CALL_METHOD(NULL, &emptyResult, "seteagermap", NULL, 0, &childMap);
			zephir_check_call_status();
		} else {
			zephir_is_iterable(&childModels, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 440);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&childModels), _48$$17)
			{
				ZEPHIR_INIT_NVAR(&record);
				ZVAL_COPY(&record, _48$$17);
				ZEPHIR_CALL_SELF(NULL, "apply", &_49, 0, &record, &childMap);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&record);
		}
	}
	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("fields"), &fields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("records"), &records, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("empty"), &emptyResult, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Distinct, non-null local key tuples across the parent set.
 *
 * @param array $parents attribute-keyed row arrays, ModelInterface or Row
 *
 * @return array list of value-tuples, deduped
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, collectKeys)
{
	zend_bool _12, _5$$3, _16$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *alias = NULL;
	zval *parents_param = NULL, *fields_param = NULL, alias_zv, __$null, __$true, field, parent, value, *_0, _11, *_1$$3, _4$$3, _7$$3, _9$$3, _2$$7, _6$$11, *_13$$13, _15$$13, _18$$13, _19$$13, _14$$17, _17$$21;
	zval parents, fields, seen, values;

	ZVAL_UNDEF(&parents);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&seen);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_17$$21);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(parents, parents_param)
		ZEPHIR_Z_PARAM_ARRAY(fields, fields_param)
		Z_PARAM_STR(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	parents_param = ZEND_CALL_ARG(execute_data, 1);
	fields_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_get_arrval(&parents, parents_param);
	zephir_get_arrval(&fields, fields_param);
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	ZEPHIR_INIT_VAR(&seen);
	array_init(&seen);
	zephir_is_iterable(&parents, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 491);
	if (Z_TYPE_P(&parents) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parents), _0)
		{
			ZEPHIR_INIT_NVAR(&parent);
			ZVAL_COPY(&parent, _0);
			ZEPHIR_INIT_NVAR(&values);
			array_init(&values);
			zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 484);
			if (Z_TYPE_P(&fields) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _1$$3)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _1$$3);
					if (Z_TYPE_P(&parent) == IS_OBJECT) {
						ZEPHIR_CALL_METHOD(&value, &parent, "readattribute", NULL, 0, &field);
						zephir_check_call_status();
					} else {
						if (UNEXPECTED(!(zephir_array_key_exists(&parent, &field)))) {
							ZEPHIR_INIT_NVAR(&_2$$7);
							object_init_ex(&_2$$7, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
							ZEPHIR_CALL_METHOD(NULL, &_2$$7, "__construct", &_3, 0, &alias_zv, &field);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_2$$7, "phalcon/Mvc/Model/Eager/Loader.zep", 475);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &parent, &field, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 478);
					}
					zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 481);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
				zephir_check_call_status();
				_5$$3 = 1;
				while (1) {
					if (_5$$3) {
						_5$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_4$$3, &fields, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_4$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&parent) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(&value, &parent, "readattribute", NULL, 0, &field);
							zephir_check_call_status();
						} else {
							if (UNEXPECTED(!(zephir_array_key_exists(&parent, &field)))) {
								ZEPHIR_INIT_NVAR(&_6$$11);
								object_init_ex(&_6$$11, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
								ZEPHIR_CALL_METHOD(NULL, &_6$$11, "__construct", &_3, 0, &alias_zv, &field);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_6$$11, "phalcon/Mvc/Model/Eager/Loader.zep", 475);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&value);
							zephir_array_fetch(&value, &parent, &field, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 478);
						}
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 481);
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			ZEPHIR_CALL_FUNCTION(&_7$$3, "in_array", &_8, 87, &__$null, &values, &__$true);
			zephir_check_call_status();
			if (zephir_is_true(&_7$$3)) {
				continue;
			}
			ZEPHIR_CALL_SELF(&_9$$3, "buildkey", &_10, 0, &values);
			zephir_check_call_status();
			zephir_array_update_zval(&seen, &_9$$3, &values, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parents, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &parents, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, &parents, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&parent, &parents, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&values);
				array_init(&values);
				zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 484);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _13$$13)
					{
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _13$$13);
						if (Z_TYPE_P(&parent) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(&value, &parent, "readattribute", NULL, 0, &field);
							zephir_check_call_status();
						} else {
							if (UNEXPECTED(!(zephir_array_key_exists(&parent, &field)))) {
								ZEPHIR_INIT_NVAR(&_14$$17);
								object_init_ex(&_14$$17, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
								ZEPHIR_CALL_METHOD(NULL, &_14$$17, "__construct", &_3, 0, &alias_zv, &field);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_14$$17, "phalcon/Mvc/Model/Eager/Loader.zep", 475);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&value);
							zephir_array_fetch(&value, &parent, &field, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 478);
						}
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 481);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
					zephir_check_call_status();
					_16$$13 = 1;
					while (1) {
						if (_16$$13) {
							_16$$13 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_15$$13, &fields, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&parent) == IS_OBJECT) {
								ZEPHIR_CALL_METHOD(&value, &parent, "readattribute", NULL, 0, &field);
								zephir_check_call_status();
							} else {
								if (UNEXPECTED(!(zephir_array_key_exists(&parent, &field)))) {
									ZEPHIR_INIT_NVAR(&_17$$21);
									object_init_ex(&_17$$21, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
									ZEPHIR_CALL_METHOD(NULL, &_17$$21, "__construct", &_3, 0, &alias_zv, &field);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_17$$21, "phalcon/Mvc/Model/Eager/Loader.zep", 475);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&value);
								zephir_array_fetch(&value, &parent, &field, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 478);
							}
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 481);
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_CALL_FUNCTION(&_18$$13, "in_array", &_8, 87, &__$null, &values, &__$true);
				zephir_check_call_status();
				if (zephir_is_true(&_18$$13)) {
					continue;
				}
				ZEPHIR_CALL_SELF(&_19$$13, "buildkey", &_10, 0, &values);
				zephir_check_call_status();
				zephir_array_update_zval(&seen, &_19$$13, &values, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&parent);
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 27, &seen);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * One query per relation node. An empty key set issues none at all -
 * WHERE IN () is a syntax error and there is nothing to attribute.
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, fetchReferenced)
{
	zval _42$$16;
	zend_ulong _10$$6, _25$$9;
	zend_bool _23$$5, _16$$6, _31$$9, _51$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_40 = NULL, *_49 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, keyIndex = 0;
	zval keys, options, findParams, _54, _56, _5$$4;
	zend_string *alias = NULL, *_11$$6, *_26$$9;
	zval *relation, relation_sub, alias_zv, *keys_param = NULL, *options_param = NULL, binds, columnList, columns, extraParameters, fieldIndex, groups, modelInstance, parts, placeholder, referencedField, referencedFields, referencedModel, resultset, tuple, _0, _3, _55, _57, _1$$3, _2$$3, _4$$4, _6$$4, _7$$4, *_8$$5, _22$$5, _37$$5, _38$$5, *_9$$6, _15$$6, _20$$6, _21$$6, _12$$7, _13$$7, _14$$7, _17$$8, _18$$8, _19$$8, *_24$$9, _30$$9, _35$$9, _36$$9, _27$$10, _28$$10, _29$$10, _32$$11, _33$$11, _34$$11, _39$$12, _41$$13, _43$$14, _44$$14, _45$$14, *_46$$14, _50$$14, _47$$17, _48$$18, _52$$19, _53$$20, _58$$21, _59$$21, _60$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&binds);
	ZVAL_UNDEF(&columnList);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&extraParameters);
	ZVAL_UNDEF(&fieldIndex);
	ZVAL_UNDEF(&groups);
	ZVAL_UNDEF(&modelInstance);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&placeholder);
	ZVAL_UNDEF(&referencedField);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&tuple);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_37$$5);
	ZVAL_UNDEF(&_38$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_41$$13);
	ZVAL_UNDEF(&_43$$14);
	ZVAL_UNDEF(&_44$$14);
	ZVAL_UNDEF(&_45$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_48$$18);
	ZVAL_UNDEF(&_52$$19);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_58$$21);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_60$$21);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&findParams);
	ZVAL_UNDEF(&_54);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_42$$16);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(relation, phalcon_mvc_model_relationinterface_ce)
		Z_PARAM_STR(alias)
		ZEPHIR_Z_PARAM_ARRAY(keys, keys_param)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	relation = ZEND_CALL_ARG(execute_data, 1);
	keys_param = ZEND_CALL_ARG(execute_data, 3);
	options_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	zephir_get_arrval(&keys, keys_param);
	zephir_get_arrval(&options, options_param);
	ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1010, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&modelInstance, &_0, "load", NULL, 0, &referencedModel);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&keys)) {
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		ZVAL_NULL(&_1$$3);
		ZVAL_BOOL(&_2$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1$$3, &modelInstance, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, this_ptr, "normalizefields", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_fast_count_int(&referencedFields) == 1) {
		zephir_memory_observe(&referencedField);
		zephir_array_fetch_long(&referencedField, &referencedFields, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 521);
		ZEPHIR_INIT_VAR(&findParams);
		zephir_create_array(&findParams, 2, 0);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "[", &referencedField, "] IN ({phEagerKeys:array})");
		zephir_array_fast_append(&findParams, &_4$$4);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_create_array(&_5$$4, 1, 0);
		ZVAL_LONG(&_6$$4, 0);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "array_column", NULL, 333, &keys, &_6$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_5$$4, SL("phEagerKeys"), &_7$$4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&findParams, SL("bind"), &_5$$4, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&binds);
		array_init(&binds);
		ZEPHIR_INIT_VAR(&groups);
		array_init(&groups);
		keyIndex = 0;
		zephir_is_iterable(&keys, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 554);
		if (Z_TYPE_P(&keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _8$$5)
			{
				ZEPHIR_INIT_NVAR(&tuple);
				ZVAL_COPY(&tuple, _8$$5);
				ZEPHIR_INIT_NVAR(&parts);
				array_init(&parts);
				zephir_is_iterable(&referencedFields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 549);
				if (Z_TYPE_P(&referencedFields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&referencedFields), _10$$6, _11$$6, _9$$6)
					{
						ZEPHIR_INIT_NVAR(&fieldIndex);
						if (_11$$6 != NULL) { 
							ZVAL_STR_COPY(&fieldIndex, _11$$6);
						} else {
							ZVAL_LONG(&fieldIndex, _10$$6);
						}
						ZEPHIR_INIT_NVAR(&referencedField);
						ZVAL_COPY(&referencedField, _9$$6);
						ZEPHIR_INIT_NVAR(&_12$$7);
						ZVAL_LONG(&_12$$7, keyIndex);
						ZEPHIR_INIT_NVAR(&placeholder);
						ZEPHIR_CONCAT_SVSV(&placeholder, "phEagerKey", &_12$$7, "_", &fieldIndex);
						ZEPHIR_INIT_NVAR(&_13$$7);
						ZEPHIR_CONCAT_SVSVS(&_13$$7, "[", &referencedField, "] = :", &placeholder, ":");
						zephir_array_append(&parts, &_13$$7, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 544);
						zephir_array_fetch(&_14$$7, &tuple, &fieldIndex, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 546);
						zephir_array_update_zval(&binds, &placeholder, &_14$$7, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &referencedFields, "rewind", NULL, 0);
					zephir_check_call_status();
					_16$$6 = 1;
					while (1) {
						if (_16$$6) {
							_16$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &referencedFields, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_15$$6, &referencedFields, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&fieldIndex, &referencedFields, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&referencedField, &referencedFields, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_17$$8);
							ZVAL_LONG(&_17$$8, keyIndex);
							ZEPHIR_INIT_NVAR(&placeholder);
							ZEPHIR_CONCAT_SVSV(&placeholder, "phEagerKey", &_17$$8, "_", &fieldIndex);
							ZEPHIR_INIT_NVAR(&_18$$8);
							ZEPHIR_CONCAT_SVSVS(&_18$$8, "[", &referencedField, "] = :", &placeholder, ":");
							zephir_array_append(&parts, &_18$$8, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 544);
							zephir_array_fetch(&_19$$8, &tuple, &fieldIndex, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 546);
							zephir_array_update_zval(&binds, &placeholder, &_19$$8, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_INIT_NVAR(&referencedField);
				ZEPHIR_INIT_NVAR(&fieldIndex);
				ZEPHIR_INIT_NVAR(&_20$$6);
				zephir_fast_join_str(&_20$$6, SL(" AND "), &parts);
				ZEPHIR_INIT_NVAR(&_21$$6);
				ZEPHIR_CONCAT_SVS(&_21$$6, "(", &_20$$6, ")");
				zephir_array_append(&groups, &_21$$6, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 549);
				keyIndex++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
			zephir_check_call_status();
			_23$$5 = 1;
			while (1) {
				if (_23$$5) {
					_23$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_22$$5, &keys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_22$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&tuple, &keys, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&parts);
					array_init(&parts);
					zephir_is_iterable(&referencedFields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 549);
					if (Z_TYPE_P(&referencedFields) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&referencedFields), _25$$9, _26$$9, _24$$9)
						{
							ZEPHIR_INIT_NVAR(&fieldIndex);
							if (_26$$9 != NULL) { 
								ZVAL_STR_COPY(&fieldIndex, _26$$9);
							} else {
								ZVAL_LONG(&fieldIndex, _25$$9);
							}
							ZEPHIR_INIT_NVAR(&referencedField);
							ZVAL_COPY(&referencedField, _24$$9);
							ZEPHIR_INIT_NVAR(&_27$$10);
							ZVAL_LONG(&_27$$10, keyIndex);
							ZEPHIR_INIT_NVAR(&placeholder);
							ZEPHIR_CONCAT_SVSV(&placeholder, "phEagerKey", &_27$$10, "_", &fieldIndex);
							ZEPHIR_INIT_NVAR(&_28$$10);
							ZEPHIR_CONCAT_SVSVS(&_28$$10, "[", &referencedField, "] = :", &placeholder, ":");
							zephir_array_append(&parts, &_28$$10, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 544);
							zephir_array_fetch(&_29$$10, &tuple, &fieldIndex, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 546);
							zephir_array_update_zval(&binds, &placeholder, &_29$$10, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &referencedFields, "rewind", NULL, 0);
						zephir_check_call_status();
						_31$$9 = 1;
						while (1) {
							if (_31$$9) {
								_31$$9 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &referencedFields, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_30$$9, &referencedFields, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_30$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&fieldIndex, &referencedFields, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&referencedField, &referencedFields, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_32$$11);
								ZVAL_LONG(&_32$$11, keyIndex);
								ZEPHIR_INIT_NVAR(&placeholder);
								ZEPHIR_CONCAT_SVSV(&placeholder, "phEagerKey", &_32$$11, "_", &fieldIndex);
								ZEPHIR_INIT_NVAR(&_33$$11);
								ZEPHIR_CONCAT_SVSVS(&_33$$11, "[", &referencedField, "] = :", &placeholder, ":");
								zephir_array_append(&parts, &_33$$11, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 544);
								zephir_array_fetch(&_34$$11, &tuple, &fieldIndex, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 546);
								zephir_array_update_zval(&binds, &placeholder, &_34$$11, PH_COPY | PH_SEPARATE);
						}
					}
					ZEPHIR_INIT_NVAR(&referencedField);
					ZEPHIR_INIT_NVAR(&fieldIndex);
					ZEPHIR_INIT_NVAR(&_35$$9);
					zephir_fast_join_str(&_35$$9, SL(" AND "), &parts);
					ZEPHIR_INIT_NVAR(&_36$$9);
					ZEPHIR_CONCAT_SVS(&_36$$9, "(", &_35$$9, ")");
					zephir_array_append(&groups, &_36$$9, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 549);
					keyIndex++;
			}
		}
		ZEPHIR_INIT_NVAR(&tuple);
		ZEPHIR_INIT_VAR(&_37$$5);
		zephir_create_array(&_37$$5, 2, 0);
		ZEPHIR_INIT_VAR(&_38$$5);
		zephir_fast_join_str(&_38$$5, SL(" OR "), &groups);
		zephir_array_fast_append(&_37$$5, &_38$$5);
		zephir_array_update_string(&_37$$5, SL("bind"), &binds, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&findParams, &_37$$5);
	}
	ZEPHIR_CALL_METHOD(&extraParameters, relation, "getparams", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&extraParameters) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&_39$$12, phalcon_mvc_model_manager_ce, "mergefindparameters", &_40, 0, &extraParameters, &findParams);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&findParams, &_39$$12);
	}
	if (!(ZEPHIR_IS_EMPTY(&options))) {
		ZEPHIR_CALL_CE_STATIC(&_41$$13, phalcon_mvc_model_manager_ce, "mergefindparameters", &_40, 0, &options, &findParams);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&findParams, &_41$$13);
	}
	zephir_memory_observe(&columns);
	if (zephir_array_isset_string_fetch(&columns, &findParams, SL("columns"), 0)) {
		if (Z_TYPE_P(&columns) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&columnList);
			zephir_fast_join_str(&columnList, SL(","), &columns);
		} else {
			zephir_cast_to_string(&_42$$16, &columns);
			ZEPHIR_CPY_WRT(&columnList, &_42$$16);
		}
		ZEPHIR_INIT_VAR(&_43$$14);
		ZEPHIR_INIT_VAR(&_44$$14);
		ZVAL_STRING(&_44$$14, " ");
		ZEPHIR_INIT_VAR(&_45$$14);
		ZVAL_STRING(&_45$$14, "");
		zephir_fast_str_replace(&_43$$14, &_44$$14, &_45$$14, &columnList);
		ZEPHIR_CPY_WRT(&columnList, &_43$$14);
		zephir_is_iterable(&referencedFields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 603);
		if (Z_TYPE_P(&referencedFields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&referencedFields), _46$$14)
			{
				ZEPHIR_INIT_NVAR(&referencedField);
				ZVAL_COPY(&referencedField, _46$$14);
				ZEPHIR_INIT_NVAR(&_47$$17);
				zephir_fast_strpos(&_47$$17, &columnList, &referencedField, 0 );
				if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_47$$17))) {
					ZEPHIR_INIT_NVAR(&_48$$18);
					object_init_ex(&_48$$18, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
					ZEPHIR_CALL_METHOD(NULL, &_48$$18, "__construct", &_49, 0, &alias_zv, &referencedField);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_48$$18, "phalcon/Mvc/Model/Eager/Loader.zep", 600);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &referencedFields, "rewind", NULL, 0);
			zephir_check_call_status();
			_51$$14 = 1;
			while (1) {
				if (_51$$14) {
					_51$$14 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &referencedFields, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_50$$14, &referencedFields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_50$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&referencedField, &referencedFields, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_52$$19);
					zephir_fast_strpos(&_52$$19, &columnList, &referencedField, 0 );
					if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_52$$19))) {
						ZEPHIR_INIT_NVAR(&_53$$20);
						object_init_ex(&_53$$20, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
						ZEPHIR_CALL_METHOD(NULL, &_53$$20, "__construct", &_49, 0, &alias_zv, &referencedField);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_53$$20, "phalcon/Mvc/Model/Eager/Loader.zep", 600);
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&referencedField);
	}
	ZEPHIR_INIT_VAR(&_54);
	zephir_create_array(&_54, 2, 0);
	zephir_array_fast_append(&_54, &modelInstance);
	ZEPHIR_INIT_VAR(&_55);
	ZVAL_STRING(&_55, "find");
	zephir_array_fast_append(&_54, &_55);
	ZEPHIR_INIT_VAR(&_56);
	zephir_create_array(&_56, 1, 0);
	zephir_array_fast_append(&_56, &findParams);
	ZEPHIR_INIT_VAR(&resultset);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&resultset, &_54, &_56);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &resultset, "materialize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_57, &resultset, "count", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_GT_LONG(&_57, 100000))) {
		ZEPHIR_INIT_VAR(&_58$$21);
		object_init_ex(&_58$$21, phalcon_mvc_model_exceptions_eagerrowlimitexceeded_ce);
		ZEPHIR_CALL_METHOD(&_59$$21, &resultset, "count", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_60$$21, 100000);
		ZEPHIR_CALL_METHOD(NULL, &_58$$21, "__construct", NULL, 0, &referencedModel, &_59$$21, &_60$$21);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_58$$21, "phalcon/Mvc/Model/Eager/Loader.zep", 617);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&resultset);
}

/**
 * Relation fields are declared as a string for a single column and an
 * array for a composite key. Normalizing removes that fork everywhere
 * downstream.
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, normalizeFields)
{
	zval *fields, fields_sub;

	ZVAL_UNDEF(&fields_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(fields)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &fields);
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		RETVAL_ZVAL(fields, 1, 0);
		return;
	}
	zephir_create_array(return_value, 1, 0);
	zephir_array_fast_append(return_value, fields);
	return;
}

/**
 * Lookup key for an already-hydrated record.
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, recordKey)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields, values;
	zval *record, record_sub, *fields_param = NULL, field, *_0, _3, _1$$3, _5$$4;

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&values);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(record)
		ZEPHIR_Z_PARAM_ARRAY(fields, fields_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &record, &fields_param);
	zephir_get_arrval(&fields, fields_param);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 651);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _0)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _0);
			ZEPHIR_CALL_METHOD(&_1$$3, record, "readattribute", &_2, 0, &field);
			zephir_check_call_status();
			zephir_array_append(&values, &_1$$3, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 648);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, record, "readattribute", &_6, 0, &field);
				zephir_check_call_status();
				zephir_array_append(&values, &_5$$4, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 648);
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_RETURN_CALL_SELF("buildkey", NULL, 0, &values);
	zephir_check_call_status();
	RETURN_MM();
}

