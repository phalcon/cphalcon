
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * Phalcon\Mvc\Model\Resultset
 *
 * This component allows to Phalcon\Mvc\Model returns large resultsets with the minimum memory consumption
 * Resultsets can be traversed using a standard foreach or a while statement. If a resultset is serialized
 * it will dump all the rows into a big array. Then unserialize will retrieve the rows as they were before
 * serializing.
 *
 * <code>
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
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Resultset, phalcon, mvc_model_resultset, phalcon_mvc_model_resultset_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Phalcon\Db\ResultInterface or false for empty resultset
	 */
	zend_declare_property_bool(phalcon_mvc_model_resultset_ce, SL("_result"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_model_resultset_ce, SL("_isFresh"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("_pointer"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_count"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_activeRow"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_rows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_row"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("_hydrateMode"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("TYPE_RESULT_FULL"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("TYPE_RESULT_PARTIAL"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_RECORDS"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_OBJECTS"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_ARRAYS"), 1 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, phalcon_mvc_model_resultsetinterface_ce);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, zend_ce_iterator);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, spl_ce_SeekableIterator);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, zend_ce_serializable);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("jsonserializable") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset constructor
 *
 * @param \Phalcon\Db\ResultInterface|false result
 * @param \Phalcon\Cache\BackendInterface cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result, *cache = NULL, *rowCount = NULL, *rows = NULL, *_2, *_0$$3, *_1$$3, *_3$$5, *_4$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &result, &cache);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(result) != IS_OBJECT) {
		ZEPHIR_INIT_ZVAL_NREF(_0$$3);
		ZVAL_LONG(_0$$3, 0);
		zephir_update_property_this(getThis(), SL("_count"), _0$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		array_init(_1$$3);
		zephir_update_property_this(getThis(), SL("_rows"), _1$$3 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	zephir_update_property_this(getThis(), SL("_result"), result TSRMLS_CC);
	if (Z_TYPE_P(cache) != IS_NULL) {
		zephir_update_property_this(getThis(), SL("_cache"), cache TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 2);
	ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&rowCount, result, "numrows", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_count"), rowCount TSRMLS_CC);
	if (ZEPHIR_IS_LONG(rowCount, 0)) {
		ZEPHIR_INIT_VAR(_3$$5);
		array_init(_3$$5);
		zephir_update_property_this(getThis(), SL("_rows"), _3$$5 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (ZEPHIR_LE_LONG(rowCount, 32)) {
		ZEPHIR_CALL_METHOD(&rows, result, "fetchall", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(rows) == IS_ARRAY) {
			zephir_update_property_this(getThis(), SL("_rows"), rows TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_4$$8);
			array_init(_4$$8);
			zephir_update_property_this(getThis(), SL("_rows"), _4$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Moves cursor to next row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) + 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 79, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether internal resource has rows to fetch
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, valid) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_count"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_LT(_0, _1));

}

/**
 * Gets pointer number of active row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_count"), PH_NOISY_CC);
	if (ZEPHIR_GE(_0, _1)) {
		RETURN_NULL();
	}
	RETURN_MEMBER(getThis(), "_pointer");

}

/**
 * Rewinds resultset to its beginning
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 79, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the internal pointer to a specific position in the resultset.
 * Set the new position if required, and then set this->_row
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek) {

	zend_bool _1, _6$$3;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *position, *result = NULL, *row = NULL, *_0, *_2, *_3$$3, *_5$$3, *_7$$3, *_9$$3, *_11$$3, *_4$$4, *_8$$6 = NULL, *_10$$7 = NULL, *_12$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	_1 = !ZEPHIR_IS_EQUAL(_0, position);
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_row"), PH_NOISY_CC);
		_1 = Z_TYPE_P(_2) == IS_NULL;
	}
	if (_1) {
		ZEPHIR_OBS_VAR(_3$$3);
		zephir_read_property_this(&_3$$3, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(_3$$3) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(row);
			_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY_CC);
			if (zephir_array_isset_fetch(&row, _4$$4, position, 0 TSRMLS_CC)) {
				zephir_update_property_this(getThis(), SL("_row"), row TSRMLS_CC);
			}
			zephir_update_property_this(getThis(), SL("_pointer"), position TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_activeRow"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
			RETURN_MM_NULL();
		}
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_row"), PH_NOISY_CC);
		_6$$3 = Z_TYPE_P(_5$$3) == IS_NULL;
		if (_6$$3) {
			_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
			_6$$3 = ZEPHIR_IS_LONG_IDENTICAL(_7$$3, 0);
		}
		if (_6$$3) {
			ZEPHIR_CALL_METHOD(&_8$$6, result, "fetch", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("_row"), _8$$6 TSRMLS_CC);
		}
		_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
		if (ZEPHIR_GT(_9$$3, position)) {
			ZEPHIR_CALL_METHOD(NULL, result, "dataseek", NULL, 0, position);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10$$7, result, "fetch", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("_row"), _10$$7 TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_pointer"), position TSRMLS_CC);
		}
		while (1) {
			_11$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
			if (!(ZEPHIR_LT(_11$$3, position))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_12$$8, result, "fetch", &_13, 0);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("_row"), _12$$8 TSRMLS_CC);
			RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_pointer") TSRMLS_CC));
		}
		zephir_update_property_this(getThis(), SL("_pointer"), position TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_activeRow"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Counts how many rows are in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count) {

	

	RETURN_MEMBER(getThis(), "_count");

}

/**
 * Checks whether offset exists in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists) {

	zval *index, *_0;

	zephir_fetch_params(0, 1, 0, &index);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_count"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_LT(index, _0));

}

/**
 * Gets row in a specific position of the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_count"), PH_NOISY_CC);
	if (ZEPHIR_LT(index, _0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 79, index);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor", "phalcon/mvc/model/resultset.zep", 300);
	return;

}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int index
 * @param \Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet) {

	zval *index, *value;

	zephir_fetch_params(0, 2, 0, &index, &value);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 311);
	return;

}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset) {

	zval *offset;

	zephir_fetch_params(0, 1, 0, &offset);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 319);
	return;

}

/**
 * Returns the internal type of data retrieval that the resultset is using
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_rows"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZVAL_LONG(_0, 0);
	} else {
		ZVAL_LONG(_0, 1);
	}
	RETURN_CCTOR(_0);

}

/**
 * Get first row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_count"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 79, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get last row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast) {

	zval *count = NULL, *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(count);
	zephir_read_property_this(&count, this_ptr, SL("_count"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(count, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, (zephir_get_numberval(count) - 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 79, _0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set if the resultset is fresh or an old one cached
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh) {

	zval *isFresh_param = NULL;
	zend_bool isFresh;

	zephir_fetch_params(0, 1, 0, &isFresh_param);

	isFresh = zephir_get_boolval(isFresh_param);


	if (isFresh) {
		zephir_update_property_this(getThis(), SL("_isFresh"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_isFresh"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Tell if the resultset if fresh or an old one cached
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh) {

	

	RETURN_MEMBER(getThis(), "_isFresh");

}

/**
 * Sets the hydration mode in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode) {

	zval *hydrateMode_param = NULL, *_0;
	zend_long hydrateMode;

	zephir_fetch_params(0, 1, 0, &hydrateMode_param);

	hydrateMode = zephir_get_intval(hydrateMode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, hydrateMode);
	zephir_update_property_this(getThis(), SL("_hydrateMode"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current hydration mode
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode) {

	

	RETURN_MEMBER(getThis(), "_hydrateMode");

}

/**
 * Returns the associated cache for the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache) {

	

	RETURN_MEMBER(getThis(), "_cache");

}

/**
 * Returns the error messages produced by a batch operation
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages) {

	

	RETURN_MEMBER(getThis(), "_errorMessages");

}

/**
 * Updates every record in the resultset
 *
 * @param array data
 * @param \Closure conditionCallback
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, update) {

	zval *_4$$6 = NULL;
	zend_bool transaction = 0;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, *conditionCallback = NULL, *record = NULL, *connection = NULL, *_0 = NULL, *_3$$6 = NULL, *_6$$3 = NULL, *_7$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &conditionCallback);

	if (!conditionCallback) {
		conditionCallback = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(connection);
	ZVAL_NULL(connection);
	transaction = 0;
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 80);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		if (transaction == 0) {
			if (!((zephir_method_exists_ex(record, SS("getwriteconnection") TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 434);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, record, "getwriteconnection", NULL, 0);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(conditionCallback) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_3$$6);
			ZEPHIR_INIT_NVAR(_4$$6);
			zephir_create_array(_4$$6, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_4$$6, record);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_3$$6, conditionCallback, _4$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3$$6)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
				zephir_check_call_status();
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_6$$3, record, "save", NULL, 0, data);
		zephir_check_call_status();
		if (!(zephir_is_true(_6$$3))) {
			ZEPHIR_CALL_METHOD(&_7$$8, record, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("_errorMessages"), _7$$8 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, 0);
			zephir_check_call_status();
			transaction = 0;
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
		zephir_check_call_status();
	}
	if (transaction == 1) {
		ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Deletes every record in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete) {

	zval *_4$$6 = NULL;
	zend_bool result = 0, transaction = 0;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditionCallback = NULL, *record = NULL, *connection = NULL, *_0 = NULL, *_3$$6 = NULL, *_6$$3 = NULL, *_7$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &conditionCallback);

	if (!conditionCallback) {
		conditionCallback = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(connection);
	ZVAL_NULL(connection);
	result = 1;
	transaction = 0;
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 80);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		if (transaction == 0) {
			if (!((zephir_method_exists_ex(record, SS("getwriteconnection") TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 507);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, record, "getwriteconnection", NULL, 0);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(conditionCallback) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_3$$6);
			ZEPHIR_INIT_NVAR(_4$$6);
			zephir_create_array(_4$$6, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_4$$6, record);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_3$$6, conditionCallback, _4$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3$$6)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
				zephir_check_call_status();
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_6$$3, record, "delete", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_6$$3))) {
			ZEPHIR_CALL_METHOD(&_7$$8, record, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("_errorMessages"), _7$$8 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, 0);
			zephir_check_call_status();
			result = 0;
			transaction = 0;
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
		zephir_check_call_status();
	}
	if (transaction == 1) {
		ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(result);

}

/**
 * Filters a resultset returning only those the developer requires
 *
 *<code>
 * $filtered = $robots->filter(
 *     function ($robot) {
 *         if ($robot->id < 3) {
 *             return $robot;
 *         }
 *     }
 * );
 *</code>
 *
 * @param callback filter
 * @return \Phalcon\Mvc\Model[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter) {

	zend_bool _3$$3;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter, *records = NULL, *record = NULL, *parameters = NULL, *processedRecord = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter);



	ZEPHIR_INIT_VAR(records);
	array_init(records);
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 80);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		zephir_array_update_long(&parameters, 0, &record, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_NVAR(processedRecord);
		ZEPHIR_CALL_USER_FUNC_ARRAY(processedRecord, filter, parameters);
		zephir_check_call_status();
		_3$$3 = Z_TYPE_P(processedRecord) != IS_OBJECT;
		if (_3$$3) {
			_3$$3 = Z_TYPE_P(processedRecord) != IS_ARRAY;
		}
		if (_3$$3) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_4, 0);
			zephir_check_call_status();
			continue;
		}
		zephir_array_append(&records, processedRecord, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 598);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_4, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(records);

}

/**
 * Returns serialised model objects as array for json_encode.
 * Calls jsonSerialize on each object if present
 *
 *<code>
 * $robots = Robots::find();
 * echo json_encode($robots);
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, jsonSerialize) {

	zend_bool _3$$3;
	zval *records = NULL, *current = NULL, *_0 = NULL, *_4$$4 = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(records);
	array_init(records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 80);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		_3$$3 = Z_TYPE_P(current) == IS_OBJECT;
		if (_3$$3) {
			_3$$3 = (zephir_method_exists_ex(current, SS("jsonserialize") TSRMLS_CC) == SUCCESS);
		}
		if (_3$$3) {
			ZEPHIR_CALL_METHOD(&_4$$4, current, "jsonserialize", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&records, _4$$4, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 627);
		} else {
			zephir_array_append(&records, current, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 629);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(records);

}

