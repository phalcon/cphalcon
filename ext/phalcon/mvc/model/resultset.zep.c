
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/iterator.h"


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
 * //Using a standard foreach
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * foreach ($robots as robot) {
 *  echo robot->name, "\n";
 * }
 *
 * //Using a while
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * $robots->rewind();
 * while ($robots->valid()) {
 *  $robot = $robots->current();
 *  echo $robot->name, "\n";
 *  $robots->next();
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
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset constructor
 *
 * @param array columnTypes
 * @param Phalcon\Db\ResultInterface|false result
 * @param Phalcon\Cache\BackendInterface cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *result, *cache = NULL, *rowCount = NULL, *rows = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &result, &cache);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(result) != IS_OBJECT) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, 0);
		zephir_update_property_this(this_ptr, SL("_count"), _0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("_rows"), _1 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	zephir_update_property_this(this_ptr, SL("_result"), result TSRMLS_CC);
	if (Z_TYPE_P(cache) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&rowCount, result, "numrows", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_count"), rowCount TSRMLS_CC);
	if (ZEPHIR_IS_LONG(rowCount, 0)) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("_rows"), _1 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (ZEPHIR_LE_LONG(rowCount, 32)) {
		ZEPHIR_CALL_METHOD(&rows, result, "fetchall", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(rows) == IS_ARRAY) {
			zephir_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_rows"), _1 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Moves cursor to next row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, _1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(_0) + 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 343, &_1);
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
	RETURN_MEMBER(this_ptr, "_pointer");

}

/**
 * Rewinds resultset to its beginning
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _0;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 343, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes internal pointer to a specific position in the resultset
 * Set new position if required and set this->_row
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek) {

	zend_bool _1, _6;
	zval *position_param = NULL, *result, *row, *_0, *_2, *_3, *_4, *_5, *_7 = NULL, *_8;
	int position, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position_param);

	position = zephir_get_intval(position_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	_1 = !ZEPHIR_IS_LONG(_0, position);
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_row"), PH_NOISY_CC);
		_1 = Z_TYPE_P(_2) == IS_NULL;
	}
	if (_1) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property_this(&_3, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(row);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY_CC);
			if (zephir_array_isset_long_fetch(&row, _4, position, 0 TSRMLS_CC)) {
				zephir_update_property_this(this_ptr, SL("_row"), row TSRMLS_CC);
			}
			ZEPHIR_INIT_ZVAL_NREF(_5);
			ZVAL_LONG(_5, position);
			zephir_update_property_this(this_ptr, SL("_pointer"), _5 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_activeRow"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
			RETURN_MM_NULL();
		}
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_row"), PH_NOISY_CC);
		_6 = Z_TYPE_P(_4) == IS_NULL;
		if (_6) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
			_6 = ZEPHIR_IS_LONG_IDENTICAL(_5, 0);
		}
		if (_6) {
			ZEPHIR_CALL_METHOD(&_7, result, "fetch", NULL, 0, result);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_row"), _7 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
		if (ZEPHIR_GT_LONG(_4, position)) {
			ZEPHIR_INIT_VAR(_8);
			ZVAL_LONG(_8, position);
			ZEPHIR_CALL_METHOD(NULL, result, "dataseek", NULL, 0, _8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7, result, "fetch", NULL, 0, result);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_row"), _7 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_5);
			ZVAL_LONG(_5, position);
			zephir_update_property_this(this_ptr, SL("_pointer"), _5 TSRMLS_CC);
		}
		while (1) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
			if (!(ZEPHIR_LT_LONG(_4, position))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_7, result, "fetch", NULL, 0, result);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_row"), _7 TSRMLS_CC);
			RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_pointer") TSRMLS_CC));
		}
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, position);
		zephir_update_property_this(this_ptr, SL("_pointer"), _4 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_activeRow"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Counts how many rows are in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count) {


	RETURN_MEMBER(this_ptr, "_count");

}

/**
 * Checks whether offset exists in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists) {

	zval *index_param = NULL, *_0;
	int index;

	zephir_fetch_params(0, 1, 0, &index_param);

	index = zephir_get_intval(index_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_count"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_GT_LONG(_0, index));

}

/**
 * Gets row in a specific position of the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet) {

	zval *index_param = NULL, *_0, _1;
	int index, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	index = Z_LVAL_P(index_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_count"), PH_NOISY_CC);
	if (ZEPHIR_GT_LONG(_0, index)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, index);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 343, &_1);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor", "phalcon/mvc/model/resultset.zep", 285);
	return;

}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int index
 * @param Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet) {

	zval *index, *value;

	zephir_fetch_params(0, 2, 0, &index, &value);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 296);
	return;

}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset) {

	zval *offset_param = NULL;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 304);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, _1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_count"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 343, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get last row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *count, _0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(count);
	zephir_read_property_this(&count, this_ptr, SL("_count"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(count, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(count) - 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 343, &_0);
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


	zephir_update_property_this(this_ptr, SL("_isFresh"), isFresh ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Tell if the resultset if fresh or an old one cached
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh) {


	RETURN_MEMBER(this_ptr, "_isFresh");

}

/**
 * Sets the hydration mode in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode) {

	zval *hydrateMode_param = NULL, *_0;
	int hydrateMode;

	zephir_fetch_params(0, 1, 0, &hydrateMode_param);

	hydrateMode = zephir_get_intval(hydrateMode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, hydrateMode);
	zephir_update_property_this(this_ptr, SL("_hydrateMode"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current hydration mode
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode) {


	RETURN_MEMBER(this_ptr, "_hydrateMode");

}

/**
 * Returns the associated cache for the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache) {


	RETURN_MEMBER(this_ptr, "_cache");

}

/**
 * Returns the error messages produced by a batch operation
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages) {


	RETURN_MEMBER(this_ptr, "_errorMessages");

}

/**
 * Updates every record in the resultset
 *
 * @param array data
 * @param Closure conditionCallback
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, update) {

	zval *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_object_iterator *_0;
	zend_bool transaction;
	zval *data, *conditionCallback = NULL, *record = NULL, *connection = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &conditionCallback);

	if (!conditionCallback) {
		conditionCallback = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(connection);
	ZVAL_NULL(connection);


	transaction = 0;
	_0 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_0->funcs->get_current_data(_0, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(record, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		if (transaction == 0) {
			if (!((zephir_method_exists_ex(record, SS("getwriteconnection") TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 414);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, record, "getwriteconnection", NULL, 0);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(conditionCallback) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_NVAR(_2);
			zephir_create_array(_2, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_2, record);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_1, conditionCallback, _2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_3, record, "save", NULL, 0, data);
		zephir_check_call_status();
		if (!(zephir_is_true(_3))) {
			ZEPHIR_CALL_METHOD(&_4, record, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_errorMessages"), _4 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, 0);
			zephir_check_call_status();
			transaction = 0;
			break;
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
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

	zval *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_object_iterator *_0;
	zend_bool transaction;
	zval *conditionCallback = NULL, *record = NULL, *connection = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &conditionCallback);

	if (!conditionCallback) {
		conditionCallback = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(connection);
	ZVAL_NULL(connection);


	transaction = 0;
	_0 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_0->funcs->get_current_data(_0, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(record, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		if (transaction == 0) {
			if (!((zephir_method_exists_ex(record, SS("getwriteconnection") TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 477);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, record, "getwriteconnection", NULL, 0);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(conditionCallback) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_NVAR(_2);
			zephir_create_array(_2, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_2, record);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_1, conditionCallback, _2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_3, record, "delete", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_3))) {
			ZEPHIR_CALL_METHOD(&_4, record, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_errorMessages"), _4 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL, 0);
			zephir_check_call_status();
			transaction = 0;
			break;
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	if (transaction == 1) {
		ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Filters a resultset returning only those the developer requires
 *
 *<code>
 * $filtered = $robots->filter(function($robot){
 *		if ($robot->id < 3) {
 *			return $robot;
 *		}
 *	});
 *</code>
 *
 * @param callback filter
 * @return Phalcon\Mvc\Model[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_object_iterator *_0;
	zval *filter, *records, *record = NULL, *parameters, *processedRecord = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter);



	ZEPHIR_INIT_VAR(records);
	array_init(records);
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	_0 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_0->funcs->get_current_data(_0, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(record, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		zephir_array_update_long(&parameters, 0, &record, PH_COPY | PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 546);
		ZEPHIR_INIT_NVAR(processedRecord);
		ZEPHIR_CALL_USER_FUNC_ARRAY(processedRecord, filter, parameters);
		zephir_check_call_status();
		if (Z_TYPE_P(processedRecord) != IS_OBJECT) {
			if (Z_TYPE_P(processedRecord) != IS_ARRAY) {
				continue;
			}
		}
		zephir_array_append(&records, processedRecord, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 558);
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_CCTOR(records);

}

