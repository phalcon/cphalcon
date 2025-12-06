
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
#include "ext/spl/spl_iterators.h"
#include "ext/json/php_json.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Resultset
 *
 * This component allows to Phalcon\Mvc\Model returns large resultsets with the minimum memory consumption
 * Resultsets can be traversed using a standard foreach or a while statement. If a resultset is serialized
 * it will dump all the rows into a big array. Then unserialize will retrieve the rows as they were before
 * serializing.
 *
 * ```php
 *
 * // Using a standard foreach
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * foreach ($robots as robot) {
 *     echo robot->name, "\n";
 * }
 *
 * // Using a while
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * $robots->rewind();
 *
 * while ($robots->valid()) {
 *     $robot = $robots->current();
 *
 *     echo $robot->name, "\n";
 *
 *     $robots->next();
 * }
 * ```
 * @template TKey
 * @template TValue
 * @implements Iterator<TKey, TValue>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Resultset, phalcon, mvc_model_resultset, phalcon_mvc_model_resultset_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("activeRow"), ZEND_ACC_PROTECTED);
	/**
	 * @var CacheInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("cache"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("count"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("errorMessages"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("hydrateMode"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_resultset_ce, SL("isFresh"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("pointer"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("row"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("rows"), ZEND_ACC_PROTECTED);
	/**
	 * Phalcon\Db\ResultInterface or false for empty resultset
	 *
	 * @var ResultInterface|bool
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("result"), ZEND_ACC_PROTECTED);
	phalcon_mvc_model_resultset_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Resultset;
	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_ARRAYS"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_OBJECTS"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_RECORDS"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("TYPE_RESULT_FULL"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("TYPE_RESULT_PARTIAL"), 1);

	zend_class_implements(phalcon_mvc_model_resultset_ce, 1, phalcon_mvc_model_resultsetinterface_ce);
	zend_class_implements(phalcon_mvc_model_resultset_ce, 1, zend_ce_iterator);
	zend_class_implements(phalcon_mvc_model_resultset_ce, 1, spl_ce_SeekableIterator);
	zend_class_implements(phalcon_mvc_model_resultset_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_mvc_model_resultset_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_mvc_model_resultset_ce, 1, zend_ce_serializable);
	zend_class_implements(phalcon_mvc_model_resultset_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Resultset constructor
 *
 * @param ResultInterface|false $result
 * @param mixed|null            $cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, __construct)
{
	zend_bool _11, _4$$4;
	zval _10, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, prefetchRecords = 0;
	zval *result, result_sub, *cache = NULL, cache_sub, __$null, rowCount, rows, _8, _0$$3, _1$$3, _2$$4, _3$$4, _5$$4, _6$$5, _9$$6, _12$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&rowCount);
	ZVAL_UNDEF(&rows);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_7$$5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(result)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(cache)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &result, &cache);
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}
	if (Z_TYPE_P(result) != IS_OBJECT) {
		ZVAL_UNDEF(&_0$$3);
		ZVAL_LONG(&_0$$3, 0);
		zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_1$$3);
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("result"), result);
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Phalcon\\Cache\\CacheInterface");
		ZEPHIR_CALL_FUNCTION(&_3$$4, "is_a", NULL, 87, cache, &_2$$4);
		zephir_check_call_status();
		_4$$4 = !ZEPHIR_IS_TRUE_IDENTICAL(&_3$$4);
		if (_4$$4) {
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "Psr\\SimpleCache\\CacheInterface");
			ZEPHIR_CALL_FUNCTION(&_5$$4, "is_a", NULL, 87, cache, &_2$$4);
			zephir_check_call_status();
			_4$$4 = !ZEPHIR_IS_TRUE_IDENTICAL(&_5$$4);
		}
		if (UNEXPECTED(_4$$4)) {
			ZEPHIR_INIT_VAR(&_6$$5);
			object_init_ex(&_6$$5, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_7$$5);
			ZEPHIR_CONCAT_SS(&_7$$5, "Cache service must be an object implementing ", "Phalcon\\Cache\\CacheInterface or Psr\\SimpleCache\\CacheInterface");
			ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 33, &_7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$5, "phalcon/Mvc/Model/Resultset.zep", 168);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), cache);
	}
	ZVAL_LONG(&_8, 2);
	ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&rowCount, result, "numrows", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &rowCount);
	if (ZEPHIR_IS_LONG(&rowCount, 0)) {
		ZEPHIR_INIT_VAR(&_9$$6);
		array_init(&_9$$6);
		zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_9$$6);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_INIT_NVAR(&_10);
	ZVAL_STRING(&_10, "ZEPHIR_GLOBAL(orm).resultset_prefetch_records");
	prefetchRecords = zephir_get_intval_ex(&_10);
	_11 = prefetchRecords > 0;
	if (_11) {
		_11 = ZEPHIR_LE_LONG(&rowCount, prefetchRecords);
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(&rows, result, "fetchall", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&rows) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &rows);
		} else {
			ZEPHIR_INIT_VAR(&_12$$9);
			array_init(&_12$$9);
			zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_12$$9);
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Counts how many rows are in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count)
{

	RETURN_MEMBER(getThis(), "count");
}

/**
 * Deletes every record in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete)
{
	zval _4$$6;
	zend_bool result = 0, transaction = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditionCallback = NULL, conditionCallback_sub, __$null, record, connection, _0, _3$$6, _6$$3, _7$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditionCallback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_4$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(conditionCallback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &conditionCallback);
	if (!conditionCallback) {
		conditionCallback = &conditionCallback_sub;
		conditionCallback = &__$null;
	}
	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	result = 1;
	transaction = 0;
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 92);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		if (transaction == 0) {
			if (UNEXPECTED(!((zephir_method_exists_ex(&record, ZEND_STRL("getwriteconnection")) == SUCCESS)))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/Mvc/Model/Resultset.zep", 242);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, &record, "getwriteconnection", NULL, 0);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(conditionCallback) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_3$$6);
			ZEPHIR_INIT_NVAR(&_4$$6);
			zephir_create_array(&_4$$6, 1, 0);
			zephir_array_fast_append(&_4$$6, &record);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_3$$6, conditionCallback, &_4$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$6)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
				zephir_check_call_status();
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_6$$3, &record, "delete", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_6$$3))) {
			ZEPHIR_CALL_METHOD(&_7$$8, &record, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_7$$8);
			ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", NULL, 0);
			zephir_check_call_status();
			result = 0;
			transaction = 0;
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
		zephir_check_call_status();
	}
	if (transaction == 1) {
		ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(result);
}

/**
 * Filters a resultset returning only those the developer requires
 *
 *```php
 * $filtered = $robots->filter(
 *     function ($robot) {
 *         if ($robot->id < 3) {
 *             return $robot;
 *         }
 *     }
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter)
{
	zend_bool _4$$3;
	zval records, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter, filter_sub, record, processedRecord, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&processedRecord);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(filter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &filter);
	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 92);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_create_array(&_3$$3, 1, 0);
		zephir_array_fast_append(&_3$$3, &record);
		ZEPHIR_INIT_NVAR(&processedRecord);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&processedRecord, filter, &_3$$3);
		zephir_check_call_status();
		_4$$3 = Z_TYPE_P(&processedRecord) != IS_OBJECT;
		if (_4$$3) {
			_4$$3 = Z_TYPE_P(&processedRecord) != IS_ARRAY;
		}
		if (_4$$3) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
			zephir_check_call_status();
			continue;
		}
		zephir_array_append(&records, &processedRecord, PH_SEPARATE, "phalcon/Mvc/Model/Resultset.zep", 336);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
		zephir_check_call_status();
	}
	RETURN_CTOR(&records);
}

/**
 * Returns the associated cache for the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache)
{

	RETURN_MEMBER(getThis(), "cache");
}

/**
 * Get first row in the resultset
 *
 * ```php
 * $model = new Robots();
 * $manager = $model->getModelsManager();
 *
 * // \Robots
 * $manager->createQuery('SELECT * FROM Robots')
 *         ->execute()
 *         ->getFirst();
 *
 * // \Phalcon\Mvc\Model\Row
 * $manager->createQuery('SELECT r.id FROM Robots AS r')
 *         ->execute()
 *         ->getFirst();
 *
 * // NULL
 * $manager->createQuery('SELECT r.id FROM Robots AS r WHERE r.name = "NON-EXISTENT"')
 *         ->execute()
 *         ->getFirst();
 * ```
 *
 * @return ModelInterface|Row|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("count"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 0)) {
		RETURN_MM_NULL();
	}
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 93, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the current hydration mode
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode)
{

	RETURN_MEMBER(getThis(), "hydrateMode");
}

/**
 * Get last row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast)
{
	zval count, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("count"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&count, &_0);
	if (ZEPHIR_IS_LONG(&count, 0)) {
		RETURN_MM_NULL();
	}
	ZVAL_LONG(&_0, (zephir_get_numberval(&count) - 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 93, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the error messages produced by a batch operation
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages)
{

	RETURN_MEMBER(getThis(), "errorMessages");
}

/**
 * Returns the internal type of data retrieval that the resultset is using
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("rows"), PH_NOISY_CC);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 0);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 1);
	}
	RETURN_CCTOR(&_0);
}

/**
 * Tell if the resultset if fresh or an old one cached
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh)
{

	RETURN_MEMBER(getThis(), "isFresh");
}

/**
 * Returns serialised model objects as array for json_encode.
 * Calls jsonSerialize on each object if present
 *
 *```php
 * $robots = Robots::find();
 *
 * echo json_encode($robots);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, jsonSerialize)
{
	zend_bool _3$$3;
	zval records;
	zval current, _0, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&records);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 92);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		_3$$3 = Z_TYPE_P(&current) == IS_OBJECT;
		if (_3$$3) {
			_3$$3 = (zephir_method_exists_ex(&current, ZEND_STRL("jsonserialize")) == SUCCESS);
		}
		if (_3$$3) {
			ZEPHIR_CALL_METHOD(&_4$$4, &current, "jsonserialize", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&records, &_4$$4, PH_SEPARATE, "phalcon/Mvc/Model/Resultset.zep", 461);
		} else {
			zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/Mvc/Model/Resultset.zep", 463);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
		zephir_check_call_status();
	}
	RETURN_CTOR(&records);
}

/**
 * Gets pointer number of active row in the resultset
 *
 * @return TKey|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	RETURN_MM_MEMBER(getThis(), "pointer");
}

/**
 * Moves cursor to next row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("pointer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 93, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Gets row in a specific position of the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval index_sub, _0;
	zval *index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("count"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_GE(index, &_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor", "phalcon/Mvc/Model/Resultset.zep", 503);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 93, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks whether offset exists in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists)
{
	zval *index, index_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &index);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("count"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_LT(index, &_0));
}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int offset
 * @param \Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet)
{
	zval *offset, offset_sub, *value, value_sub;

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &offset, &value);
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/Mvc/Model/Resultset.zep", 530);
	return;
}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset)
{
	zval *offset, offset_sub;

	ZVAL_UNDEF(&offset_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &offset);
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/Mvc/Model/Resultset.zep", 538);
	return;
}

/**
 * Rewinds resultset to its beginning
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 93, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Changes the internal pointer to a specific position in the resultset.
 * Set the new position if required, and then set this->row
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek)
{
	zend_bool _1, _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *position, position_sub, __$null, result, row, _0, _2, _3$$3, _5$$3, _7$$3, _9$$3, _11$$3, _4$$4, _8$$6, _10$$7, _12$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &position);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pointer"), PH_NOISY_CC | PH_READONLY);
	_1 = !ZEPHIR_IS_EQUAL(&_0, position);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("row"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) == IS_NULL;
	}
	if (_1) {
		zephir_memory_observe(&_3$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("rows"), PH_NOISY_CC);
		if (Z_TYPE_P(&_3$$3) == IS_ARRAY) {
			zephir_memory_observe(&row);
			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("rows"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_fetch(&row, &_4$$4, position, 0)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("row"), &row);
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("pointer"), position);
			zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &__$null);
			RETURN_MM_NULL();
		}
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("result"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&result, &_5$$3);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("row"), PH_NOISY_CC | PH_READONLY);
		_6$$3 = Z_TYPE_P(&_5$$3) == IS_NULL;
		if (_6$$3) {
			zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("pointer"), PH_NOISY_CC | PH_READONLY);
			_6$$3 = ZEPHIR_IS_LONG_IDENTICAL(&_7$$3, 0);
		}
		if (_6$$3) {
			ZEPHIR_CALL_METHOD(&_8$$6, &result, "fetch", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("row"), &_8$$6);
		}
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("pointer"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT(&_9$$3, position)) {
			ZEPHIR_CALL_METHOD(NULL, &result, "dataseek", NULL, 0, position);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10$$7, &result, "fetch", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("row"), &_10$$7);
			zephir_update_property_zval(this_ptr, ZEND_STRL("pointer"), position);
		}
		while (1) {
			zephir_read_property(&_11$$3, this_ptr, ZEND_STRL("pointer"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_LT(&_11$$3, position))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_12$$8, &result, "fetch", &_13, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("row"), &_12$$8);
			RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("pointer")));
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("pointer"), position);
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &__$null);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the hydration mode in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode)
{
	zval *hydrateMode_param = NULL, _0;
	zend_long hydrateMode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(hydrateMode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &hydrateMode_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, hydrateMode);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hydrateMode"), &_0);
	RETURN_THISW();
}

/**
 * Set if the resultset is fresh or an old one cached
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh)
{
	zval *isFresh_param = NULL, __$true, __$false;
	zend_bool isFresh;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(isFresh)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &isFresh_param);
	if (isFresh) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isFresh"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isFresh"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Updates every record in the resultset
 *
 * @param array data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, update)
{
	zval _4$$6;
	zend_bool transaction = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *conditionCallback = NULL, conditionCallback_sub, __$null, record, connection, _0, _3$$6, _6$$3, _7$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&conditionCallback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_4$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(conditionCallback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &data, &conditionCallback);
	if (!conditionCallback) {
		conditionCallback = &conditionCallback_sub;
		conditionCallback = &__$null;
	}
	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	transaction = 0;
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 92);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		if (transaction == 0) {
			if (UNEXPECTED(!((zephir_method_exists_ex(&record, ZEND_STRL("getwriteconnection")) == SUCCESS)))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/Mvc/Model/Resultset.zep", 655);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, &record, "getwriteconnection", NULL, 0);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(conditionCallback) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_3$$6);
			ZEPHIR_INIT_NVAR(&_4$$6);
			zephir_create_array(&_4$$6, 1, 0);
			zephir_array_fast_append(&_4$$6, &record);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_3$$6, conditionCallback, &_4$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$6)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
				zephir_check_call_status();
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, &record, "assign", NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$3, &record, "save", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_6$$3))) {
			ZEPHIR_CALL_METHOD(&_7$$8, &record, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("errorMessages"), &_7$$8);
			ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", NULL, 0);
			zephir_check_call_status();
			transaction = 0;
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
		zephir_check_call_status();
	}
	if (transaction == 1) {
		ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(transaction);
}

/**
 * Check whether internal resource has rows to fetch
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, valid)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pointer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("count"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_LT(&_0, &_1));
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Resultset(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("errorMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("errorMessages"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

