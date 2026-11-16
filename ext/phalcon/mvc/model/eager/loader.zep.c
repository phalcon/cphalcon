
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Loads model relations in bulk - a bounded number of queries per relation
 * node rather than one per record - and applies the result to records as they
 * are hydrated.
 *
 * @phpstan-import-type mvc_eager_map from MvcTypes
 * @phpstan-import-type mvc_eager_map_node from MvcTypes
 * @phpstan-import-type mvc_eager_node from MvcTypes
 * @phpstan-import-type mvc_eager_parents from MvcTypes
 * @phpstan-import-type mvc_model_parameters from MvcTypes
 * @phpstan-import-type mvc_query_columns from MvcTypes
 * @phpstan-import-type mvc_relation_fields from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Eager_Loader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Eager, Loader, phalcon, mvc_model_eager_loader, phalcon_mvc_model_eager_loader_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_eager_loader_ce, SL("manager"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Mvc\\Model\\ManagerInterface"));
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1037, manager);
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
 *
 * @phpstan-param mvc_eager_map $eagerMap
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, apply)
{
	zend_bool _14, _8$$3, _12$$6, _20$$10, _23$$13;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval eagerMap, values;
	zval *record, record_sub, *eagerMap_param = NULL, __$null, __$true, alias, field, fields, lookup, node, records, related, *_0, _13, *_3$$3, _4$$3, *_5$$3, _7$$3, _10$$3, _6$$4, _9$$5, *_15$$10, _16$$10, *_17$$10, _19$$10, _22$$10, _18$$11, _21$$12;

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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&eagerMap);
	ZVAL_UNDEF(&values);
	ZEND_TLS zephir_method_cache _zephir_call_cache[23];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(record)
		ZEPHIR_Z_PARAM_ARRAY(eagerMap, eagerMap_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &record, &eagerMap_param);
	zephir_get_arrval(&eagerMap, eagerMap_param);
	zephir_is_iterable(&eagerMap, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 99);
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
			zephir_array_fetch_string(&fields, &node, SL("fields"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 75);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&values);
			array_init(&values);
			if (Z_TYPE_P(&fields) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_4$$3);
				zephir_string_to_char_array(&_4$$3, &fields);
				_3$$3 = &_4$$3;
			} else {
				_3$$3 = &fields;
			}
			zephir_is_iterable(_3$$3, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 82);
			if (Z_TYPE_P(_3$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$3), _5$$3)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _5$$3);
					ZEPHIR_CALL_METHOD_CACHED(&_6$$4, record, "readAttribute", &_zephir_call_cache[0], &field);
					zephir_check_call_status();
					zephir_array_append(&values, &_6$$4, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 79);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$3, "rewind", &_zephir_call_cache[1]);
				zephir_check_call_status();
				_8$$3 = 1;
				while (1) {
					if (_8$$3) {
						_8$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _3$$3, "next", &_zephir_call_cache[2]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_7$$3, _3$$3, "valid", &_zephir_call_cache[3]);
					zephir_check_call_status();
					if (!zend_is_true(&_7$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&field, _3$$3, "current", &_zephir_call_cache[4]);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_9$$5, record, "readAttribute", &_zephir_call_cache[5], &field);
						zephir_check_call_status();
						zephir_array_append(&values, &_9$$5, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 79);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			ZEPHIR_OBS_NVAR(&records);
			zephir_array_fetch_string(&records, &node, SL("records"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 82);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&related);
			zephir_array_fetch_string(&related, &node, SL("empty"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 83);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&_10$$3, "in_array", &_11, 36, &__$null, &values, &__$true);
			zephir_check_call_status();
			if (!(zephir_is_true(&_10$$3))) {
				ZEPHIR_CALL_SELF_CACHED(&lookup, "buildKey", &_zephir_call_cache[6], &values);
				zephir_check_call_status();
				_12$$6 = zephir_array_isset_value(&records, &lookup);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_12$$6) {
					ZEPHIR_OBS_NVAR(&related);
					zephir_array_fetch(&related, &records, &lookup, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 89);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			if (zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce)) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, record, "setRelated", &_zephir_call_cache[7], &alias, &related);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, record, "writeAttribute", &_zephir_call_cache[8], &alias, &related);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &eagerMap, "rewind", &_zephir_call_cache[9]);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &eagerMap, "next", &_zephir_call_cache[10]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_13, &eagerMap, "valid", &_zephir_call_cache[11]);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&alias, &eagerMap, "key", &_zephir_call_cache[12]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&node, &eagerMap, "current", &_zephir_call_cache[13]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&fields);
				zephir_array_fetch_string(&fields, &node, SL("fields"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 75);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&values);
				array_init(&values);
				if (Z_TYPE_P(&fields) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_16$$10);
					zephir_string_to_char_array(&_16$$10, &fields);
					_15$$10 = &_16$$10;
				} else {
					_15$$10 = &fields;
				}
				zephir_is_iterable(_15$$10, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 82);
				if (Z_TYPE_P(_15$$10) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_15$$10), _17$$10)
					{
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _17$$10);
						ZEPHIR_CALL_METHOD_CACHED(&_18$$11, record, "readAttribute", &_zephir_call_cache[14], &field);
						zephir_check_call_status();
						zephir_array_append(&values, &_18$$11, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 79);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _15$$10, "rewind", &_zephir_call_cache[15]);
					zephir_check_call_status();
					_20$$10 = 1;
					while (1) {
						if (_20$$10) {
							_20$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _15$$10, "next", &_zephir_call_cache[16]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_19$$10, _15$$10, "valid", &_zephir_call_cache[17]);
						zephir_check_call_status();
						if (!zend_is_true(&_19$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&field, _15$$10, "current", &_zephir_call_cache[18]);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&_21$$12, record, "readAttribute", &_zephir_call_cache[19], &field);
							zephir_check_call_status();
							zephir_array_append(&values, &_21$$12, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 79);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_OBS_NVAR(&records);
				zephir_array_fetch_string(&records, &node, SL("records"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 82);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&related);
				zephir_array_fetch_string(&related, &node, SL("empty"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 83);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_FUNCTION(&_22$$10, "in_array", &_11, 36, &__$null, &values, &__$true);
				zephir_check_call_status();
				if (!(zephir_is_true(&_22$$10))) {
					ZEPHIR_CALL_SELF_CACHED(&lookup, "buildKey", &_zephir_call_cache[20], &values);
					zephir_check_call_status();
					_23$$13 = zephir_array_isset_value(&records, &lookup);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_23$$13) {
						ZEPHIR_OBS_NVAR(&related);
						zephir_array_fetch(&related, &records, &lookup, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 89);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				if (zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce)) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, record, "setRelated", &_zephir_call_cache[21], &alias, &related);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, record, "writeAttribute", &_zephir_call_cache[22], &alias, &related);
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
 *
 * @phpstan-param array<array-key, mixed> $values
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &values_param);
	zephir_get_arrval(&values, values_param);
	if (zephir_fast_count_int(&values) == 1) {
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_long(&_0$$3, &values, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 117);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_1$$3, &_0$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CTOR(&_1$$3);
	}
	ZEPHIR_INIT_VAR(&key);
	ZVAL_STRING(&key, "");
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 127);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _2)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			zephir_cast_to_string(&_3$$4, &value);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&part, &_3$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, zephir_fast_strlen_ev(&part));
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZEPHIR_CONCAT_VVSV(&_5$$4, &key, &_4$$4, ":", &part);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_get_strval(&key, &_5$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &values, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &values, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6, &values, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&value, &values, "current", &_zephir_call_cache[3]);
			zephir_check_call_status();
				zephir_cast_to_string(&_8$$5, &value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&part, &_8$$5);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_LONG(&_9$$5, zephir_fast_strlen_ev(&part));
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZEPHIR_CONCAT_VVSV(&_10$$5, &key, &_9$$5, ":", &part);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_strval(&key, &_10$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
 *
 * @phpstan-param array<string, mixed> $tree
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
		ZEPHIR_CALL_METHOD_CACHED(&_1, resultset, "count", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_0 = ZEPHIR_IS_LONG_IDENTICAL(&_1, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, resultset, "materialize", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_3, resultset, "toArray", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "buildMap", &_zephir_call_cache[3], &_3, &modelName_zv, &tree);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, resultset, "setEagerMap", &_zephir_call_cache[4], &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds one level of the map.
 *
 * @phpstan-param mvc_eager_parents    $parents
 * @phpstan-param array<string, mixed> $tree
 * @phpstan-return mvc_eager_map
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildMap)
{
	zend_bool _8;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *modelName = NULL, *_2;
	zval *parents_param = NULL, modelName_zv, *tree_param = NULL, alias, node, relation, *_0, _7, _3$$3, _5$$3, _6$$3, _4$$4, _9$$5, _11$$5, _12$$5, _10$$6;
	zval parents, tree, map;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parents);
	ZVAL_UNDEF(&tree);
	ZVAL_UNDEF(&map);
	ZVAL_UNDEF(&modelName_zv);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_10$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[11];
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
	zephir_is_iterable(&tree, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 187);
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
			zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 1037, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&relation, &_3$$3, "getRelationByAlias", &_zephir_call_cache[0], &modelName_zv, &alias);
			zephir_check_call_status();
			if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				object_init_ex(&_4$$4, phalcon_mvc_model_exceptions_unknowneagerrelation_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[1], &modelName_zv, &alias);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Model/Eager/Loader.zep", 176);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_fast_strtolower(&_5$$3, &alias);
			ZEPHIR_CALL_METHOD_CACHED(&_6$$3, this_ptr, "buildNode", &_zephir_call_cache[2], &relation, &alias, &parents, &node);
			zephir_check_call_status();
			zephir_array_update_zval(&map, &_5$$3, &_6$$3, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &tree, "rewind", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &tree, "next", &_zephir_call_cache[4]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_7, &tree, "valid", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&alias, &tree, "key", &_zephir_call_cache[6]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&node, &tree, "current", &_zephir_call_cache[7]);
			zephir_check_call_status();
				zephir_read_property_cached(&_9$$5, this_ptr, _zephir_prop_0, 1037, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&relation, &_9$$5, "getRelationByAlias", &_zephir_call_cache[8], &modelName_zv, &alias);
				zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					object_init_ex(&_10$$6, phalcon_mvc_model_exceptions_unknowneagerrelation_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$6, "__construct", &_zephir_call_cache[9], &modelName_zv, &alias);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$6, "phalcon/Mvc/Model/Eager/Loader.zep", 176);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_fast_strtolower(&_11$$5, &alias);
				ZEPHIR_CALL_METHOD_CACHED(&_12$$5, this_ptr, "buildNode", &_zephir_call_cache[10], &relation, &alias, &parents, &node);
				zephir_check_call_status();
				zephir_array_update_zval(&map, &_11$$5, &_12$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&node);
	ZEPHIR_INIT_NVAR(&alias);
	RETURN_CTOR(&map);
}

/**
 * Builds a single map node: one query, indexed by the referenced field.
 *
 * @phpstan-param mvc_eager_parents $parents
 * @phpstan-param mvc_eager_node    $node
 * @phpstan-return mvc_eager_map_node
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildNode)
{
	zend_ulong _9, _19$$9;
	zend_bool isMany = 0, _14, _15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0;
	zval parents, node, childModels, index, records;
	zend_string *alias = NULL, *_10, *_20$$9;
	zval *relation, relation_sub, alias_zv, *parents_param = NULL, *node_param = NULL, childMap, children, emptyResult, fields, keys, keyValue, positions, record, referencedFields, sub, children2, _0, _1, _2, _3, _4, _6, _7, *_8, _5$$4, _11$$6, _12$$7, _13$$7, _16$$8, _17$$8, *_18$$9, *_21$$11;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&parents);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&childModels);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&records);
	ZEND_TLS zephir_method_cache _zephir_call_cache[21];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, relation, "isThrough", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "buildThroughNode", &_zephir_call_cache[1], relation, &alias_zv, &parents, &node);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, relation, "getFields", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&fields, this_ptr, "normalizeFields", &_zephir_call_cache[3], &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_2, relation, "getReferencedFields", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&referencedFields, this_ptr, "normalizeFields", &_zephir_call_cache[5], &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&keys, this_ptr, "collectKeys", &_zephir_call_cache[6], &parents, &fields, &alias_zv);
	zephir_check_call_status();
	zephir_memory_observe(&_3);
	zephir_array_fetch_string(&_3, &node, SL("options"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 225);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&children, this_ptr, "fetchReferenced", &_zephir_call_cache[7], relation, &alias_zv, &keys, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&childModels);
	array_init(&childModels);
	ZEPHIR_INIT_VAR(&index);
	array_init(&index);
	position = 0;
	ZEPHIR_CALL_METHOD_CACHED(NULL, &children, "rewind", &_zephir_call_cache[8]);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD_CACHED(&_4, &children, "valid", &_zephir_call_cache[9]);
		zephir_check_call_status();
		if (!(zephir_is_true(&_4))) {
			break;
		}
		ZEPHIR_CALL_METHOD_CACHED(&record, &children, "current", &_zephir_call_cache[10]);
		zephir_check_call_status();
		zephir_array_append(&childModels, &record, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 236);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&keyValue, this_ptr, "recordKey", &_zephir_call_cache[11], &record, &referencedFields);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$4);
		ZVAL_LONG(&_5$$4, position);
		zephir_array_update_multi(&index, &_5$$4, SL("za"), 2, &keyValue);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		position++;
		ZEPHIR_CALL_METHOD_CACHED(NULL, &children, "next", &_zephir_call_cache[12]);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_6, relation, "getType", &_zephir_call_cache[13]);
	zephir_check_call_status();
	isMany = ZEPHIR_IS_LONG_IDENTICAL(&_6, 2);
	if (isMany) {
		ZEPHIR_INIT_VAR(&_7);
		array_init(&_7);
		ZEPHIR_CALL_METHOD_CACHED(&emptyResult, &children, "sliceRows", &_zephir_call_cache[14], &_7);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&emptyResult);
		ZVAL_NULL(&emptyResult);
	}
	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	zephir_is_iterable(&index, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 265);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&index), _9, _10, _8)
	{
		ZEPHIR_INIT_NVAR(&keyValue);
		if (_10 != NULL) { 
			ZVAL_STR_COPY(&keyValue, _10);
		} else {
			ZVAL_LONG(&keyValue, _9);
		}
		ZEPHIR_INIT_NVAR(&positions);
		ZVAL_COPY(&positions, _8);
		if (isMany) {
			ZEPHIR_CALL_METHOD_CACHED(&_11$$6, &children, "sliceRows", &_zephir_call_cache[15], &positions);
			zephir_check_call_status();
			zephir_array_update_zval(&records, &keyValue, &_11$$6, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_OBS_NVAR(&_12$$7);
			ZEPHIR_OBS_NVAR(&_13$$7);
			zephir_array_fetch_long(&_13$$7, &positions, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 256);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch(&_12$$7, &childModels, &_13$$7, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 256);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&records, &keyValue, &_12$$7, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&positions);
	ZEPHIR_INIT_NVAR(&keyValue);
	_14 = zephir_isempty_dim_string(&node, SL("children"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_15 = !(_14);
	if (_15) {
		_15 = !(ZEPHIR_IS_EMPTY(&childModels));
	}
	if (_15) {
		ZEPHIR_CALL_METHOD_CACHED(&_16$$8, relation, "getReferencedModel", &_zephir_call_cache[16]);
		zephir_check_call_status();
		zephir_memory_observe(&_17$$8);
		zephir_array_fetch_string(&_17$$8, &node, SL("children"), PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 270);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&childMap, this_ptr, "buildMap", &_zephir_call_cache[17], &childModels, &_16$$8, &_17$$8);
		zephir_check_call_status();
		if (isMany) {
			zephir_is_iterable(&records, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 284);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&records), _19$$9, _20$$9, _18$$9)
			{
				ZEPHIR_INIT_NVAR(&keyValue);
				if (_20$$9 != NULL) { 
					ZVAL_STR_COPY(&keyValue, _20$$9);
				} else {
					ZVAL_LONG(&keyValue, _19$$9);
				}
				ZEPHIR_INIT_NVAR(&sub);
				ZVAL_COPY(&sub, _18$$9);
				ZEPHIR_CPY_WRT(&children2, &sub);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &children2, "setEagerMap", &_zephir_call_cache[18], &childMap);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&sub);
			ZEPHIR_INIT_NVAR(&keyValue);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &emptyResult, "setEagerMap", &_zephir_call_cache[19], &childMap);
			zephir_check_call_status();
		} else {
			zephir_is_iterable(&childModels, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 289);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&childModels), _21$$11)
			{
				ZEPHIR_INIT_NVAR(&record);
				ZVAL_COPY(&record, _21$$11);
				ZEPHIR_CALL_SELF_CACHED(NULL, "apply", &_zephir_call_cache[20], &record, &childMap);
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
 *
 * @phpstan-param mvc_eager_parents $parents
 * @phpstan-param mvc_eager_node    $node
 * @phpstan-return mvc_eager_map_node
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildThroughNode)
{
	zend_ulong _24, _43$$15;
	zend_bool isMany = 0, _38, _39, _32$$6, _29$$7, _33$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0;
	zval parents, node, childModels, index, pairMap, records, _5$$3, _9$$3, _10$$3, _12$$3, _14$$4, _16$$4, _17$$4;
	zend_string *alias = NULL, *_25, *_44$$15;
	zval *relation, relation_sub, alias_zv, *parents_param = NULL, *node_param = NULL, childMap, emptyResult, fields, intermediateField, intermediateFields, intermediateModel, intermediateReferencedField, intermediateReferencedFields, keyValue, keys, pair, pairs, parentKey, positions, record, referenced, referencedFields, referencedKey, referencedKeys, slice, sub, tuple, _0, _1, _2, _3, _4, _18, _19, _20, _22, *_23, _6$$3, _7$$3, _8$$3, _11$$3, _13$$3, _15$$4, _21$$5, *_26$$6, _27$$6, *_28$$6, _31$$6, _30$$8, _34$$10, _35$$12, _36$$13, _37$$13, _40$$14, _41$$14, *_42$$15, *_45$$17;
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
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$14);
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
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[38];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, relation, "getFields", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&fields, this_ptr, "normalizeFields", &_zephir_call_cache[1], &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, relation, "getIntermediateFields", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&intermediateFields, this_ptr, "normalizeFields", &_zephir_call_cache[3], &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_2, relation, "getReferencedFields", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&referencedFields, this_ptr, "normalizeFields", &_zephir_call_cache[5], &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_3, relation, "getIntermediateReferencedFields", &_zephir_call_cache[6]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&intermediateReferencedFields, this_ptr, "normalizeFields", &_zephir_call_cache[7], &_3);
	zephir_check_call_status();
	zephir_memory_observe(&intermediateField);
	zephir_array_fetch_long(&intermediateField, &intermediateFields, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 338);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&intermediateReferencedField);
	zephir_array_fetch_long(&intermediateReferencedField, &intermediateReferencedFields, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 339);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&intermediateModel, relation, "getIntermediateModel", &_zephir_call_cache[8]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_4, relation, "getType", &_zephir_call_cache[9]);
	zephir_check_call_status();
	isMany = ZEPHIR_IS_LONG_IDENTICAL(&_4, 4);
	ZEPHIR_CALL_METHOD_CACHED(&keys, this_ptr, "collectKeys", &_zephir_call_cache[10], &parents, &fields, &alias_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pairMap);
	array_init(&pairMap);
	ZEPHIR_INIT_VAR(&referencedKeys);
	array_init(&referencedKeys);
	if (!(ZEPHIR_IS_EMPTY(&keys))) {
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0);
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 1037, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_7$$3, &_6$$3, "load", &_zephir_call_cache[11], &intermediateModel);
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_fast_append(&_10$$3, &_11$$3);
		ZEPHIR_INIT_NVAR(&_11$$3);
		ZEPHIR_CONCAT_VSV(&_11$$3, &intermediateField, ", ", &intermediateReferencedField);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_10$$3, SL("columns"), &_11$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_12$$3);
		zephir_create_array(&_12$$3, 1, 0);
		ZVAL_LONG(&_13$$3, 0);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "array_column", NULL, 102, &keys, &_13$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_12$$3, SL("phEagerKeys"), &_7$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_10$$3, SL("bind"), &_12$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_9$$3, &_10$$3);
		ZEPHIR_INIT_VAR(&pairs);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&pairs, &_5$$3, &_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &pairs, "rewind", &_zephir_call_cache[12]);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD_CACHED(&_7$$3, &pairs, "valid", &_zephir_call_cache[13]);
			zephir_check_call_status();
			if (!(zephir_is_true(&_7$$3))) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&pair, &pairs, "current", &_zephir_call_cache[14]);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_14$$4);
			zephir_create_array(&_14$$4, 1, 0);
			ZEPHIR_CALL_METHOD_CACHED(&_15$$4, &pair, "readAttribute", &_zephir_call_cache[15], &intermediateField);
			zephir_check_call_status();
			zephir_array_fast_append(&_14$$4, &_15$$4);
			ZEPHIR_CALL_SELF_CACHED(&parentKey, "buildKey", &_zephir_call_cache[16], &_14$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_16$$4);
			zephir_create_array(&_16$$4, 1, 0);
			ZEPHIR_CALL_METHOD_CACHED(&_15$$4, &pair, "readAttribute", &_zephir_call_cache[17], &intermediateReferencedField);
			zephir_check_call_status();
			zephir_array_fast_append(&_16$$4, &_15$$4);
			ZEPHIR_CALL_SELF_CACHED(&referencedKey, "buildKey", &_zephir_call_cache[18], &_16$$4);
			zephir_check_call_status();
			zephir_array_update_multi(&pairMap, &referencedKey, SL("za"), 2, &parentKey);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_17$$4);
			zephir_create_array(&_17$$4, 1, 0);
			ZEPHIR_CALL_METHOD_CACHED(&_15$$4, &pair, "readAttribute", &_zephir_call_cache[19], &intermediateReferencedField);
			zephir_check_call_status();
			zephir_array_fast_append(&_17$$4, &_15$$4);
			zephir_array_update_zval(&referencedKeys, &referencedKey, &_17$$4, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &pairs, "next", &_zephir_call_cache[20]);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(&_18, "array_values", NULL, 18, &referencedKeys);
	zephir_check_call_status();
	zephir_array_fetch_string(&_19, &node, SL("options"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 396);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&referenced, this_ptr, "fetchReferenced", &_zephir_call_cache[21], relation, &alias_zv, &_18, &_19);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&childModels);
	array_init(&childModels);
	ZEPHIR_INIT_VAR(&index);
	array_init(&index);
	position = 0;
	ZEPHIR_CALL_METHOD_CACHED(NULL, &referenced, "rewind", &_zephir_call_cache[22]);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD_CACHED(&_20, &referenced, "valid", &_zephir_call_cache[23]);
		zephir_check_call_status();
		if (!(zephir_is_true(&_20))) {
			break;
		}
		ZEPHIR_CALL_METHOD_CACHED(&record, &referenced, "current", &_zephir_call_cache[24]);
		zephir_check_call_status();
		zephir_array_append(&childModels, &record, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 407);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&keyValue, this_ptr, "recordKey", &_zephir_call_cache[25], &record, &referencedFields);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_21$$5);
		ZVAL_LONG(&_21$$5, position);
		zephir_array_update_multi(&index, &_21$$5, SL("za"), 2, &keyValue);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		position++;
		ZEPHIR_CALL_METHOD_CACHED(NULL, &referenced, "next", &_zephir_call_cache[26]);
		zephir_check_call_status();
	}
	if (isMany) {
		ZEPHIR_INIT_VAR(&_22);
		array_init(&_22);
		ZEPHIR_CALL_METHOD_CACHED(&emptyResult, &referenced, "sliceRows", &_zephir_call_cache[27], &_22);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&emptyResult);
		ZVAL_NULL(&emptyResult);
	}
	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	zephir_is_iterable(&pairMap, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 442);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&pairMap), _24, _25, _23)
	{
		ZEPHIR_INIT_NVAR(&parentKey);
		if (_25 != NULL) { 
			ZVAL_STR_COPY(&parentKey, _25);
		} else {
			ZVAL_LONG(&parentKey, _24);
		}
		ZEPHIR_INIT_NVAR(&positions);
		ZVAL_COPY(&positions, _23);
		ZEPHIR_INIT_NVAR(&tuple);
		array_init(&tuple);
		if (Z_TYPE_P(&positions) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_27$$6);
			zephir_string_to_char_array(&_27$$6, &positions);
			_26$$6 = &_27$$6;
		} else {
			_26$$6 = &positions;
		}
		zephir_is_iterable(_26$$6, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 431);
		if (Z_TYPE_P(_26$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_26$$6), _28$$6)
			{
				ZEPHIR_INIT_NVAR(&referencedKey);
				ZVAL_COPY(&referencedKey, _28$$6);
				ZEPHIR_OBS_NVAR(&sub);
				_29$$7 = zephir_array_isset_fetch(&sub, &index, &referencedKey, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_29$$7) {
					ZEPHIR_INIT_NVAR(&_30$$8);
					zephir_fast_array_merge(&_30$$8, &tuple, &sub);
					ZEPHIR_CPY_WRT(&tuple, &_30$$8);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _26$$6, "rewind", &_zephir_call_cache[28]);
			zephir_check_call_status();
			_32$$6 = 1;
			while (1) {
				if (_32$$6) {
					_32$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _26$$6, "next", &_zephir_call_cache[29]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_31$$6, _26$$6, "valid", &_zephir_call_cache[30]);
				zephir_check_call_status();
				if (!zend_is_true(&_31$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&referencedKey, _26$$6, "current", &_zephir_call_cache[31]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&sub);
					_33$$9 = zephir_array_isset_fetch(&sub, &index, &referencedKey, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_33$$9) {
						ZEPHIR_INIT_NVAR(&_34$$10);
						zephir_fast_array_merge(&_34$$10, &tuple, &sub);
						ZEPHIR_CPY_WRT(&tuple, &_34$$10);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&referencedKey);
		if (ZEPHIR_IS_EMPTY(&tuple)) {
			continue;
		}
		if (isMany) {
			ZEPHIR_CALL_METHOD_CACHED(&_35$$12, &referenced, "sliceRows", &_zephir_call_cache[32], &tuple);
			zephir_check_call_status();
			zephir_array_update_zval(&records, &parentKey, &_35$$12, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_OBS_NVAR(&_36$$13);
			ZEPHIR_OBS_NVAR(&_37$$13);
			zephir_array_fetch_long(&_37$$13, &tuple, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 438);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch(&_36$$13, &childModels, &_37$$13, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 438);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&records, &parentKey, &_36$$13, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&positions);
	ZEPHIR_INIT_NVAR(&parentKey);
	_38 = zephir_isempty_dim_string(&node, SL("children"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_39 = !(_38);
	if (_39) {
		_39 = !(ZEPHIR_IS_EMPTY(&childModels));
	}
	if (_39) {
		ZEPHIR_CALL_METHOD_CACHED(&_40$$14, relation, "getReferencedModel", &_zephir_call_cache[33]);
		zephir_check_call_status();
		zephir_array_fetch_string(&_41$$14, &node, SL("children"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/Loader.zep", 447);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&childMap, this_ptr, "buildMap", &_zephir_call_cache[34], &childModels, &_40$$14, &_41$$14);
		zephir_check_call_status();
		if (isMany) {
			zephir_is_iterable(&records, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 456);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&records), _43$$15, _44$$15, _42$$15)
			{
				ZEPHIR_INIT_NVAR(&keyValue);
				if (_44$$15 != NULL) { 
					ZVAL_STR_COPY(&keyValue, _44$$15);
				} else {
					ZVAL_LONG(&keyValue, _43$$15);
				}
				ZEPHIR_INIT_NVAR(&sub);
				ZVAL_COPY(&sub, _42$$15);
				ZEPHIR_CPY_WRT(&slice, &sub);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &slice, "setEagerMap", &_zephir_call_cache[35], &childMap);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&sub);
			ZEPHIR_INIT_NVAR(&keyValue);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &emptyResult, "setEagerMap", &_zephir_call_cache[36], &childMap);
			zephir_check_call_status();
		} else {
			zephir_is_iterable(&childModels, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 461);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&childModels), _45$$17)
			{
				ZEPHIR_INIT_NVAR(&record);
				ZVAL_COPY(&record, _45$$17);
				ZEPHIR_CALL_SELF_CACHED(NULL, "apply", &_zephir_call_cache[37], &record, &childMap);
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
 * @phpstan-param mvc_eager_parents         $parents
 * @phpstan-param array<array-key, string>  $fields
 * @phpstan-return list<array<array-key, mixed>>
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, collectKeys)
{
	zend_bool _12, _5$$3, _2$$6, _6$$10, _17$$13, _14$$16, _18$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *alias = NULL;
	zval *parents_param = NULL, *fields_param = NULL, alias_zv, __$null, __$true, field, parent, value, *_0, _11, *_1$$3, _4$$3, _8$$3, _10$$3, _3$$7, _7$$11, *_13$$13, _16$$13, _20$$13, _21$$13, _15$$17, _19$$21;
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
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_19$$21);
	ZEND_TLS zephir_method_cache _zephir_call_cache[22];
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
	zephir_is_iterable(&parents, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 512);
	if (Z_TYPE_P(&parents) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parents), _0)
		{
			ZEPHIR_INIT_NVAR(&parent);
			ZVAL_COPY(&parent, _0);
			ZEPHIR_INIT_NVAR(&values);
			array_init(&values);
			zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 505);
			if (Z_TYPE_P(&fields) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _1$$3)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _1$$3);
					if (Z_TYPE_P(&parent) == IS_OBJECT) {
						ZEPHIR_CALL_METHOD_CACHED(&value, &parent, "readAttribute", &_zephir_call_cache[0], &field);
						zephir_check_call_status();
					} else {
						_2$$6 = zephir_array_key_exists(&parent, &field);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_2$$6))) {
							ZEPHIR_INIT_NVAR(&_3$$7);
							object_init_ex(&_3$$7, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$7, "__construct", &_zephir_call_cache[1], &alias_zv, &field);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model/Eager/Loader.zep", 496);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &parent, &field, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 499);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 502);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &fields, "rewind", &_zephir_call_cache[2]);
				zephir_check_call_status();
				_5$$3 = 1;
				while (1) {
					if (_5$$3) {
						_5$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, &fields, "next", &_zephir_call_cache[3]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &fields, "valid", &_zephir_call_cache[4]);
					zephir_check_call_status();
					if (!zend_is_true(&_4$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&field, &fields, "current", &_zephir_call_cache[5]);
					zephir_check_call_status();
						if (Z_TYPE_P(&parent) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD_CACHED(&value, &parent, "readAttribute", &_zephir_call_cache[6], &field);
							zephir_check_call_status();
						} else {
							_6$$10 = zephir_array_key_exists(&parent, &field);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(!(_6$$10))) {
								ZEPHIR_INIT_NVAR(&_7$$11);
								object_init_ex(&_7$$11, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$11, "__construct", &_zephir_call_cache[7], &alias_zv, &field);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_7$$11, "phalcon/Mvc/Model/Eager/Loader.zep", 496);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&value);
							zephir_array_fetch(&value, &parent, &field, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 499);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 502);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			ZEPHIR_CALL_FUNCTION(&_8$$3, "in_array", &_9, 36, &__$null, &values, &__$true);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$3)) {
				continue;
			}
			ZEPHIR_CALL_SELF_CACHED(&_10$$3, "buildKey", &_zephir_call_cache[8], &values);
			zephir_check_call_status();
			zephir_array_update_zval(&seen, &_10$$3, &values, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &parents, "rewind", &_zephir_call_cache[9]);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &parents, "next", &_zephir_call_cache[10]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_11, &parents, "valid", &_zephir_call_cache[11]);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&parent, &parents, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&values);
				array_init(&values);
				zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 505);
				if (Z_TYPE_P(&fields) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _13$$13)
					{
						ZEPHIR_INIT_NVAR(&field);
						ZVAL_COPY(&field, _13$$13);
						if (Z_TYPE_P(&parent) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD_CACHED(&value, &parent, "readAttribute", &_zephir_call_cache[13], &field);
							zephir_check_call_status();
						} else {
							_14$$16 = zephir_array_key_exists(&parent, &field);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(!(_14$$16))) {
								ZEPHIR_INIT_NVAR(&_15$$17);
								object_init_ex(&_15$$17, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_15$$17, "__construct", &_zephir_call_cache[14], &alias_zv, &field);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_15$$17, "phalcon/Mvc/Model/Eager/Loader.zep", 496);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&value);
							zephir_array_fetch(&value, &parent, &field, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 499);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 502);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &fields, "rewind", &_zephir_call_cache[15]);
					zephir_check_call_status();
					_17$$13 = 1;
					while (1) {
						if (_17$$13) {
							_17$$13 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, &fields, "next", &_zephir_call_cache[16]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_16$$13, &fields, "valid", &_zephir_call_cache[17]);
						zephir_check_call_status();
						if (!zend_is_true(&_16$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&field, &fields, "current", &_zephir_call_cache[18]);
						zephir_check_call_status();
							if (Z_TYPE_P(&parent) == IS_OBJECT) {
								ZEPHIR_CALL_METHOD_CACHED(&value, &parent, "readAttribute", &_zephir_call_cache[19], &field);
								zephir_check_call_status();
							} else {
								_18$$20 = zephir_array_key_exists(&parent, &field);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(!(_18$$20))) {
									ZEPHIR_INIT_NVAR(&_19$$21);
									object_init_ex(&_19$$21, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_19$$21, "__construct", &_zephir_call_cache[20], &alias_zv, &field);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_19$$21, "phalcon/Mvc/Model/Eager/Loader.zep", 496);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&value);
								zephir_array_fetch(&value, &parent, &field, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 499);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 502);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&field);
				ZEPHIR_CALL_FUNCTION(&_20$$13, "in_array", &_9, 36, &__$null, &values, &__$true);
				zephir_check_call_status();
				if (zephir_is_true(&_20$$13)) {
					continue;
				}
				ZEPHIR_CALL_SELF_CACHED(&_21$$13, "buildKey", &_zephir_call_cache[21], &values);
				zephir_check_call_status();
				zephir_array_update_zval(&seen, &_21$$13, &values, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&parent);
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 18, &seen);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * One query per relation node. An empty key set issues none at all -
 * WHERE IN () is a syntax error and there is nothing to attribute.
 *
 * @phpstan-param array<array-key, array<array-key, mixed>> $keys
 * @phpstan-param mvc_model_parameters                      $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, fetchReferenced)
{
	zval _46$$16;
	zend_ulong _12$$6, _29$$9;
	zend_bool _45, _25$$5, _18$$6, _35$$9, _55$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, keyIndex = 0;
	zval keys, options, findParams, _58, _60, _5$$4;
	zend_string *alias = NULL, *_13$$6, *_30$$9;
	zval *relation, relation_sub, alias_zv, *keys_param = NULL, *options_param = NULL, binds, columnList, columns, extraParameters, fieldIndex, groups, modelInstance, parts, placeholder, referencedField, referencedFields, referencedModel, resultset, tuple, _0, _3, _59, _61, _1$$3, _2$$3, _4$$4, _6$$4, _7$$4, *_8$$5, _24$$5, _41$$5, _42$$5, *_9$$6, _10$$6, *_11$$6, _17$$6, _22$$6, _23$$6, _14$$7, _15$$7, _16$$7, _19$$8, _20$$8, _21$$8, *_26$$9, _27$$9, *_28$$9, _34$$9, _39$$9, _40$$9, _31$$10, _32$$10, _33$$10, _36$$11, _37$$11, _38$$11, _43$$12, _44$$13, _47$$14, _48$$14, _49$$14, *_50$$14, *_51$$14, _54$$14, _52$$17, _53$$18, _56$$19, _57$$20, _62$$21, _63$$21, _64$$21;
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
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_41$$5);
	ZVAL_UNDEF(&_42$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_37$$11);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_43$$12);
	ZVAL_UNDEF(&_44$$13);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_48$$14);
	ZVAL_UNDEF(&_49$$14);
	ZVAL_UNDEF(&_54$$14);
	ZVAL_UNDEF(&_52$$17);
	ZVAL_UNDEF(&_53$$18);
	ZVAL_UNDEF(&_56$$19);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&_62$$21);
	ZVAL_UNDEF(&_63$$21);
	ZVAL_UNDEF(&_64$$21);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&findParams);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_46$$16);
	ZEND_TLS zephir_method_cache _zephir_call_cache[32];
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
	ZEPHIR_CALL_METHOD_CACHED(&referencedModel, relation, "getReferencedModel", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1037, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&modelInstance, &_0, "load", &_zephir_call_cache[1], &referencedModel);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&keys)) {
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		ZVAL_NULL(&_1$$3);
		ZVAL_BOOL(&_2$$3, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[2], &_1$$3, &modelInstance, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_3, relation, "getReferencedFields", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&referencedFields, this_ptr, "normalizeFields", &_zephir_call_cache[4], &_3);
	zephir_check_call_status();
	if (zephir_fast_count_int(&referencedFields) == 1) {
		zephir_memory_observe(&referencedField);
		zephir_array_fetch_long(&referencedField, &referencedFields, 0, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 545);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&findParams);
		zephir_create_array(&findParams, 2, 0);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "[", &referencedField, "] IN ({phEagerKeys:array})");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_fast_append(&findParams, &_4$$4);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_create_array(&_5$$4, 1, 0);
		ZVAL_LONG(&_6$$4, 0);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "array_column", NULL, 102, &keys, &_6$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_5$$4, SL("phEagerKeys"), &_7$$4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&findParams, SL("bind"), &_5$$4, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&binds);
		array_init(&binds);
		ZEPHIR_INIT_VAR(&groups);
		array_init(&groups);
		keyIndex = 0;
		zephir_is_iterable(&keys, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 578);
		if (Z_TYPE_P(&keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _8$$5)
			{
				ZEPHIR_INIT_NVAR(&tuple);
				ZVAL_COPY(&tuple, _8$$5);
				ZEPHIR_INIT_NVAR(&parts);
				array_init(&parts);
				if (Z_TYPE_P(&referencedFields) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					zephir_string_to_char_array(&_10$$6, &referencedFields);
					_9$$6 = &_10$$6;
				} else {
					_9$$6 = &referencedFields;
				}
				zephir_is_iterable(_9$$6, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 573);
				if (Z_TYPE_P(_9$$6) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9$$6), _12$$6, _13$$6, _11$$6)
					{
						ZEPHIR_INIT_NVAR(&fieldIndex);
						if (_13$$6 != NULL) { 
							ZVAL_STR_COPY(&fieldIndex, _13$$6);
						} else {
							ZVAL_LONG(&fieldIndex, _12$$6);
						}
						ZEPHIR_INIT_NVAR(&referencedField);
						ZVAL_COPY(&referencedField, _11$$6);
						ZEPHIR_INIT_NVAR(&_14$$7);
						ZVAL_LONG(&_14$$7, keyIndex);
						ZEPHIR_INIT_NVAR(&placeholder);
						ZEPHIR_CONCAT_SVSV(&placeholder, "phEagerKey", &_14$$7, "_", &fieldIndex);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_15$$7);
						ZEPHIR_CONCAT_SVSVS(&_15$$7, "[", &referencedField, "] = :", &placeholder, ":");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&parts, &_15$$7, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 568);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_16$$7);
						zephir_array_fetch(&_16$$7, &tuple, &fieldIndex, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 570);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&binds, &placeholder, &_16$$7, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$6, "rewind", &_zephir_call_cache[5]);
					zephir_check_call_status();
					_18$$6 = 1;
					while (1) {
						if (_18$$6) {
							_18$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$6, "next", &_zephir_call_cache[6]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_17$$6, _9$$6, "valid", &_zephir_call_cache[7]);
						zephir_check_call_status();
						if (!zend_is_true(&_17$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&fieldIndex, _9$$6, "key", &_zephir_call_cache[8]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&referencedField, _9$$6, "current", &_zephir_call_cache[9]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_19$$8);
							ZVAL_LONG(&_19$$8, keyIndex);
							ZEPHIR_INIT_NVAR(&placeholder);
							ZEPHIR_CONCAT_SVSV(&placeholder, "phEagerKey", &_19$$8, "_", &fieldIndex);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_20$$8);
							ZEPHIR_CONCAT_SVSVS(&_20$$8, "[", &referencedField, "] = :", &placeholder, ":");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&parts, &_20$$8, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 568);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_21$$8);
							zephir_array_fetch(&_21$$8, &tuple, &fieldIndex, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 570);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&binds, &placeholder, &_21$$8, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&referencedField);
				ZEPHIR_INIT_NVAR(&fieldIndex);
				ZEPHIR_INIT_NVAR(&_22$$6);
				zephir_fast_join_str(&_22$$6, SL(" AND "), &parts);
				ZEPHIR_INIT_NVAR(&_23$$6);
				ZEPHIR_CONCAT_SVS(&_23$$6, "(", &_22$$6, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&groups, &_23$$6, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 573);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				keyIndex++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, &keys, "rewind", &_zephir_call_cache[10]);
			zephir_check_call_status();
			_25$$5 = 1;
			while (1) {
				if (_25$$5) {
					_25$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &keys, "next", &_zephir_call_cache[11]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_24$$5, &keys, "valid", &_zephir_call_cache[12]);
				zephir_check_call_status();
				if (!zend_is_true(&_24$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&tuple, &keys, "current", &_zephir_call_cache[13]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&parts);
					array_init(&parts);
					if (Z_TYPE_P(&referencedFields) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_27$$9);
						zephir_string_to_char_array(&_27$$9, &referencedFields);
						_26$$9 = &_27$$9;
					} else {
						_26$$9 = &referencedFields;
					}
					zephir_is_iterable(_26$$9, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 573);
					if (Z_TYPE_P(_26$$9) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_26$$9), _29$$9, _30$$9, _28$$9)
						{
							ZEPHIR_INIT_NVAR(&fieldIndex);
							if (_30$$9 != NULL) { 
								ZVAL_STR_COPY(&fieldIndex, _30$$9);
							} else {
								ZVAL_LONG(&fieldIndex, _29$$9);
							}
							ZEPHIR_INIT_NVAR(&referencedField);
							ZVAL_COPY(&referencedField, _28$$9);
							ZEPHIR_INIT_NVAR(&_31$$10);
							ZVAL_LONG(&_31$$10, keyIndex);
							ZEPHIR_INIT_NVAR(&placeholder);
							ZEPHIR_CONCAT_SVSV(&placeholder, "phEagerKey", &_31$$10, "_", &fieldIndex);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_32$$10);
							ZEPHIR_CONCAT_SVSVS(&_32$$10, "[", &referencedField, "] = :", &placeholder, ":");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&parts, &_32$$10, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 568);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_33$$10);
							zephir_array_fetch(&_33$$10, &tuple, &fieldIndex, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 570);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&binds, &placeholder, &_33$$10, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _26$$9, "rewind", &_zephir_call_cache[14]);
						zephir_check_call_status();
						_35$$9 = 1;
						while (1) {
							if (_35$$9) {
								_35$$9 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _26$$9, "next", &_zephir_call_cache[15]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_34$$9, _26$$9, "valid", &_zephir_call_cache[16]);
							zephir_check_call_status();
							if (!zend_is_true(&_34$$9)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&fieldIndex, _26$$9, "key", &_zephir_call_cache[17]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&referencedField, _26$$9, "current", &_zephir_call_cache[18]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_36$$11);
								ZVAL_LONG(&_36$$11, keyIndex);
								ZEPHIR_INIT_NVAR(&placeholder);
								ZEPHIR_CONCAT_SVSV(&placeholder, "phEagerKey", &_36$$11, "_", &fieldIndex);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_37$$11);
								ZEPHIR_CONCAT_SVSVS(&_37$$11, "[", &referencedField, "] = :", &placeholder, ":");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&parts, &_37$$11, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 568);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_38$$11);
								zephir_array_fetch(&_38$$11, &tuple, &fieldIndex, PH_NOISY, "phalcon/Mvc/Model/Eager/Loader.zep", 570);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&binds, &placeholder, &_38$$11, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&referencedField);
					ZEPHIR_INIT_NVAR(&fieldIndex);
					ZEPHIR_INIT_NVAR(&_39$$9);
					zephir_fast_join_str(&_39$$9, SL(" AND "), &parts);
					ZEPHIR_INIT_NVAR(&_40$$9);
					ZEPHIR_CONCAT_SVS(&_40$$9, "(", &_39$$9, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&groups, &_40$$9, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 573);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					keyIndex++;
			}
		}
		ZEPHIR_INIT_NVAR(&tuple);
		ZEPHIR_INIT_VAR(&_41$$5);
		zephir_create_array(&_41$$5, 2, 0);
		ZEPHIR_INIT_VAR(&_42$$5);
		zephir_fast_join_str(&_42$$5, SL(" OR "), &groups);
		zephir_array_fast_append(&_41$$5, &_42$$5);
		zephir_array_update_string(&_41$$5, SL("bind"), &binds, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&findParams, &_41$$5);
	}
	ZEPHIR_CALL_METHOD_CACHED(&extraParameters, relation, "getParams", &_zephir_call_cache[19]);
	zephir_check_call_status();
	if (Z_TYPE_P(&extraParameters) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC_CACHED(&_43$$12, phalcon_mvc_model_manager_ce, "mergeFindParameters", &_zephir_call_cache[20], &extraParameters, &findParams);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&_43$$12) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_43$$12, "findParams", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&findParams, &_43$$12);
	}
	if (!(ZEPHIR_IS_EMPTY(&options))) {
		ZEPHIR_CALL_CE_STATIC_CACHED(&_44$$13, phalcon_mvc_model_manager_ce, "mergeFindParameters", &_zephir_call_cache[21], &options, &findParams);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&_44$$13) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_44$$13, "findParams", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&findParams, &_44$$13);
	}
	zephir_memory_observe(&columns);
	_45 = zephir_array_isset_string_fetch(&columns, &findParams, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_45) {
		if (Z_TYPE_P(&columns) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&columnList);
			zephir_fast_join_str(&columnList, SL(","), &columns);
		} else {
			zephir_cast_to_string(&_46$$16, &columns);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&columnList, &_46$$16);
		}
		ZEPHIR_INIT_VAR(&_47$$14);
		ZEPHIR_INIT_VAR(&_48$$14);
		ZVAL_STRING(&_48$$14, " ");
		ZEPHIR_INIT_VAR(&_49$$14);
		ZVAL_STRING(&_49$$14, "");
		zephir_fast_str_replace(&_47$$14, &_48$$14, &_49$$14, &columnList);
		ZEPHIR_CPY_WRT(&columnList, &_47$$14);
		if (Z_TYPE_P(&referencedFields) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_47$$14);
			zephir_string_to_char_array(&_47$$14, &referencedFields);
			_50$$14 = &_47$$14;
		} else {
			_50$$14 = &referencedFields;
		}
		zephir_is_iterable(_50$$14, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 627);
		if (Z_TYPE_P(_50$$14) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_50$$14), _51$$14)
			{
				ZEPHIR_INIT_NVAR(&referencedField);
				ZVAL_COPY(&referencedField, _51$$14);
				ZEPHIR_INIT_NVAR(&_52$$17);
				zephir_fast_strpos(&_52$$17, &columnList, &referencedField, 0 );
				if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_52$$17))) {
					ZEPHIR_INIT_NVAR(&_53$$18);
					object_init_ex(&_53$$18, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_53$$18, "__construct", &_zephir_call_cache[22], &alias_zv, &referencedField);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_53$$18, "phalcon/Mvc/Model/Eager/Loader.zep", 624);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _50$$14, "rewind", &_zephir_call_cache[23]);
			zephir_check_call_status();
			_55$$14 = 1;
			while (1) {
				if (_55$$14) {
					_55$$14 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _50$$14, "next", &_zephir_call_cache[24]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_54$$14, _50$$14, "valid", &_zephir_call_cache[25]);
				zephir_check_call_status();
				if (!zend_is_true(&_54$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&referencedField, _50$$14, "current", &_zephir_call_cache[26]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_56$$19);
					zephir_fast_strpos(&_56$$19, &columnList, &referencedField, 0 );
					if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_56$$19))) {
						ZEPHIR_INIT_NVAR(&_57$$20);
						object_init_ex(&_57$$20, phalcon_mvc_model_exceptions_missingeagerkeycolumn_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_57$$20, "__construct", &_zephir_call_cache[27], &alias_zv, &referencedField);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_57$$20, "phalcon/Mvc/Model/Eager/Loader.zep", 624);
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&referencedField);
	}
	ZEPHIR_INIT_VAR(&_58);
	zephir_create_array(&_58, 2, 0);
	zephir_array_fast_append(&_58, &modelInstance);
	ZEPHIR_INIT_VAR(&_59);
	ZVAL_STRING(&_59, "find");
	zephir_array_fast_append(&_58, &_59);
	ZEPHIR_INIT_VAR(&_60);
	zephir_create_array(&_60, 1, 0);
	zephir_array_fast_append(&_60, &findParams);
	ZEPHIR_INIT_VAR(&resultset);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&resultset, &_58, &_60);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &resultset, "materialize", &_zephir_call_cache[28]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_61, &resultset, "count", &_zephir_call_cache[29]);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_GT_LONG(&_61, 100000))) {
		ZEPHIR_INIT_VAR(&_62$$21);
		object_init_ex(&_62$$21, phalcon_mvc_model_exceptions_eagerrowlimitexceeded_ce);
		ZEPHIR_CALL_METHOD_CACHED(&_63$$21, &resultset, "count", &_zephir_call_cache[30]);
		zephir_check_call_status();
		ZVAL_LONG(&_64$$21, 100000);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_62$$21, "__construct", &_zephir_call_cache[31], &referencedModel, &_63$$21, &_64$$21);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_62$$21, "phalcon/Mvc/Model/Eager/Loader.zep", 641);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&resultset);
}

/**
 * Relation fields are declared as a string for a single column and an
 * array for a composite key. Normalizing removes that fork everywhere
 * downstream.
 *
 * @phpstan-param mvc_relation_fields $fields
 * @phpstan-return array<array-key, string>
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
 *
 * @phpstan-param array<array-key, string> $fields
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, recordKey)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields, values;
	zval *record, record_sub, *fields_param = NULL, field, *_0, _2, _1$$3, _4$$4;

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&values);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
	zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Eager/Loader.zep", 680);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _0)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _0);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, record, "readAttribute", &_zephir_call_cache[0], &field);
			zephir_check_call_status();
			zephir_array_append(&values, &_1$$3, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 677);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &fields, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &fields, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_2, &fields, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&field, &fields, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_4$$4, record, "readAttribute", &_zephir_call_cache[5], &field);
				zephir_check_call_status();
				zephir_array_append(&values, &_4$$4, PH_SEPARATE, "phalcon/Mvc/Model/Eager/Loader.zep", 677);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_RETURN_CALL_SELF_CACHED("buildKey", &_zephir_call_cache[6], &values);
	zephir_check_call_status();
	RETURN_MM();
}

