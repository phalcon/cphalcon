
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/iterator.h"
#include "kernel/array.h"


/**
 * Phalcon\Mvc\Model\Resultset
 *
 * This component allows to Phalcon\Mvc\Model returns large resulsets with the minimum memory consumption
 * Resulsets can be traversed using a standard foreach or a while statement. If a resultset is serialized
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

	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("_type"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
 * Moves cursor to next row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, _1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(_0) + 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether internal resource has rows to fetch
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, valid) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "count", &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_LT(_0, _1));

}

/**
 * Gets pointer number of active row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "count", &_2);
	zephir_check_call_status();
	if (ZEPHIR_GE(_0, _1)) {
		RETURN_MM_NULL();
	}
	RETURN_MM_MEMBER(this_ptr, "_pointer");

}

/**
 * Rewinds resultset to its beginning
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval _0;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes internal pointer to a specific position in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek) {

	zend_bool _2, _5;
	zval *position_param = NULL, *result, *_0, *_1, *_3, *_4, *_6, *_7, *_8 = NULL, *_9;
	int position, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position_param);

	position = zephir_get_intval(position_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_row"), PH_NOISY_CC);
		_2 = Z_TYPE_P(_1) == IS_NULL;
		if (!(_2)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
			_2 = !ZEPHIR_IS_LONG(_3, position);
		}
		if (_2) {
			ZEPHIR_OBS_VAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (!ZEPHIR_IS_FALSE_IDENTICAL(result)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_row"), PH_NOISY_CC);
				_5 = Z_TYPE_P(_4) == IS_NULL;
				if (!(_5)) {
					_6 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
					_5 = ZEPHIR_GT_LONG(_6, position);
				}
				if (_5) {
					ZEPHIR_INIT_VAR(_7);
					ZVAL_LONG(_7, position);
					ZEPHIR_CALL_METHOD(NULL, result, "dataseek", NULL, _7);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8, result, "fetch", NULL, result);
					zephir_check_call_status();
					zephir_update_property_this(this_ptr, SL("_row"), _8 TSRMLS_CC);
				} else {
					while (1) {
						_9 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
						if (!(ZEPHIR_LT_LONG(_9, position))) {
							break;
						}
						ZEPHIR_CALL_METHOD(&_8, result, "fetch", NULL, result);
						zephir_check_call_status();
						zephir_update_property_this(this_ptr, SL("_row"), _8 TSRMLS_CC);
						RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_pointer") TSRMLS_CC));
					}
				}
			}
			ZEPHIR_INIT_ZVAL_NREF(_4);
			ZVAL_LONG(_4, position);
			zephir_update_property_this(this_ptr, SL("_pointer"), _4 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_activeRow"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		}
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
		if (!ZEPHIR_IS_LONG(_1, position)) {
			ZEPHIR_INIT_ZVAL_NREF(_3);
			ZVAL_LONG(_3, position);
			zephir_update_property_this(this_ptr, SL("_pointer"), _3 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_activeRow"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Counts how many rows are in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *count = NULL, *result = NULL, *rows = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(count);
	zephir_read_property_this(&count, this_ptr, SL("_count"), PH_NOISY_CC);
	if (Z_TYPE_P(count) == IS_NULL) {
		ZEPHIR_INIT_NVAR(count);
		ZVAL_LONG(count, 0);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (zephir_is_true(_0)) {
			ZEPHIR_OBS_VAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (!ZEPHIR_IS_FALSE_IDENTICAL(result)) {
				ZEPHIR_CALL_METHOD(&_1, result, "numrows", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(count);
				ZVAL_LONG(count, zephir_get_intval(_1));
			}
		} else {
			ZEPHIR_OBS_VAR(rows);
			zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
			if (Z_TYPE_P(rows) == IS_NULL) {
				ZEPHIR_OBS_NVAR(result);
				zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
				if (Z_TYPE_P(result) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&rows, result, "fetchall", NULL);
					zephir_check_call_status();
					zephir_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
				}
			}
			ZEPHIR_INIT_NVAR(count);
			ZVAL_LONG(count, zephir_fast_count_int(rows TSRMLS_CC));
		}
		zephir_update_property_this(this_ptr, SL("_count"), count TSRMLS_CC);
	}
	RETURN_CCTOR(count);

}

/**
 * Checks whether offset exists in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *index_param = NULL, *_0 = NULL;
	int index, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	index = zephir_get_intval(index_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(_0, index));

}

/**
 * Gets row in a specific position of the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	zval *index_param = NULL, *_0 = NULL, _2;
	int index, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	index = Z_LVAL_P(index_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", &_1);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(_0, index)) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, index);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", &_3, &_2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor", "phalcon/mvc/model/resultset.zep", 243);
	return;

}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int index
 * @param Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet) {

	zval *index, *value;

	zephir_fetch_params(0, 2, 0, &index, &value);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 254);
	return;

}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset) {

	zval *offset_param = NULL;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 262);
	return;

}

/**
 * Returns the internal type of data retrieval that the resultset is using
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Get first row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, _2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_0, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get last row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *count = NULL, _1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&count, this_ptr, "count", &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(count, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(count) - 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL);
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 372);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, record, "getwriteconnection", NULL);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL);
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
		ZEPHIR_CALL_METHOD(&_3, record, "save", NULL, data);
		zephir_check_call_status();
		if (!(zephir_is_true(_3))) {
			ZEPHIR_CALL_METHOD(&_4, record, "getmessages", NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_errorMessages"), _4 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL);
			zephir_check_call_status();
			transaction = 0;
			break;
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	if (transaction == 1) {
		ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL);
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 435);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, record, "getwriteconnection", NULL);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL);
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
		ZEPHIR_CALL_METHOD(&_3, record, "delete", NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_3))) {
			ZEPHIR_CALL_METHOD(&_4, record, "getmessages", NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_errorMessages"), _4 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL);
			zephir_check_call_status();
			transaction = 0;
			break;
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	if (transaction == 1) {
		ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL);
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
		zephir_array_update_long(&parameters, 0, &record, PH_COPY | PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 504);
		ZEPHIR_INIT_NVAR(processedRecord);
		ZEPHIR_CALL_USER_FUNC_ARRAY(processedRecord, filter, parameters);
		zephir_check_call_status();
		if (Z_TYPE_P(processedRecord) != IS_OBJECT) {
			if (Z_TYPE_P(processedRecord) != IS_ARRAY) {
				continue;
			}
		}
		zephir_array_append(&records, processedRecord, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 516);
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_CCTOR(records);

}

