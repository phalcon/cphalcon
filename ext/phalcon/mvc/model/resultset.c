
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Resultset, phalcon, mvc_model_resultset, phalcon_mvc_model_resultset_method_entry, 0);

	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("_type"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_resultset_ce, SL("_isFresh"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("_pointer"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_count"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_activeRow"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_rows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("_hydrateMode"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("TYPE_RESULT_FULL"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("TYPE_RESULT_PARTIAL"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_RECORDS"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_OBJECTS"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_ARRAYS"), 1 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Moves cursor to next row in the resultset
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next) {



}

/**
 * Gets pointer number of active row in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key) {


	RETURN_MEMBER(this_ptr, "_pointer");

}

/**
 * Rewinds resultset to its beginning
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind) {

	zval *rows = NULL, *result = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (!ZEPHIR_IS_FALSE(result)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_activeRow"), PH_NOISY_CC);
			if ((Z_TYPE_P(_1) != IS_NULL)) {
				ZEPHIR_INIT_VAR(_2);
				ZVAL_LONG(_2, 0);
				zephir_call_method_p1_noret(result, "dataseek", _2);
			}
		}
	} else {
		ZEPHIR_OBS_VAR(rows);
		zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		if ((Z_TYPE_P(rows) == IS_NULL)) {
			ZEPHIR_OBS_NVAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if ((Z_TYPE_P(result) == IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(rows);
				zephir_call_method(rows, result, "fetchall");
				zephir_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
			}
		}
		if ((Z_TYPE_P(rows) == IS_ARRAY)) {
			Z_SET_ISREF_P(rows);
			zephir_call_func_p1_noret("reset", rows);
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 0);
	zephir_update_property_this(this_ptr, SL("_pointer"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes internal pointer to a specific position in the resultset
 *
 * @param int position
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek) {

	zend_bool _3;
	zval *position_param = NULL, *result = NULL, *rows = NULL, *_0, *_1, *_2, *_6;
	int position, i, _4, _5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position_param);

		position = zephir_get_intval(position_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, position)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (zephir_is_true(_1)) {
			ZEPHIR_OBS_VAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (!ZEPHIR_IS_FALSE(result)) {
				ZEPHIR_INIT_VAR(_2);
				ZVAL_LONG(_2, position);
				zephir_call_method_p1_noret(result, "dataseek", _2);
			}
		} else {
			ZEPHIR_OBS_VAR(rows);
			zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
			if ((Z_TYPE_P(rows) == IS_NULL)) {
				ZEPHIR_OBS_NVAR(result);
				zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
				if ((Z_TYPE_P(result) == IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(rows);
					zephir_call_method(rows, result, "fetchall");
					zephir_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
				}
			}
			if ((Z_TYPE_P(rows) == IS_ARRAY)) {
				Z_SET_ISREF_P(rows);
				zephir_call_func_p1_noret("reset", rows);
				_5 = position;
				_4 = 0;
				_3 = 0;
				if ((_4 <= _5)) {
					while (1) {
						if (_3) {
							_4++;
							if (!((_4 <= _5))) {
								break;
							}
						} else {
							_3 = 1;
						}
						i = _4;
						Z_SET_ISREF_P(rows);
						zephir_call_func_p1_noret("next", rows);
					}
				}
			}
		}
		ZEPHIR_INIT_ZVAL_NREF(_6);
		ZVAL_LONG(_6, position);
		zephir_update_property_zval(this_ptr, SL("_pointer"), _6 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count) {

	zval *count, *result = NULL, *rows = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(count);
	zephir_read_property_this(&count, this_ptr, SL("_count"), PH_NOISY_CC);
	if ((Z_TYPE_P(count) == IS_NULL)) {
		ZEPHIR_INIT_BNVAR(count);
		ZVAL_LONG(count, 0);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (zephir_is_true(_0)) {
			ZEPHIR_OBS_VAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (!ZEPHIR_IS_FALSE(result)) {
				ZEPHIR_INIT_VAR(_1);
				zephir_call_method(_1, result, "numrows");
				ZEPHIR_INIT_BNVAR(count);
				zephir_call_func_p1(count, "intval", _1);
			}
		} else {
			ZEPHIR_OBS_VAR(rows);
			zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
			if ((Z_TYPE_P(rows) == IS_NULL)) {
				ZEPHIR_OBS_NVAR(result);
				zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
				if ((Z_TYPE_P(result) == IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(rows);
					zephir_call_method(rows, result, "fetchall");
					zephir_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
				}
			}
			ZEPHIR_INIT_BNVAR(count);
			ZVAL_LONG(count, zephir_fast_count_int(rows TSRMLS_CC));
		}
		zephir_update_property_this(this_ptr, SL("_count"), count TSRMLS_CC);
	}
	RETURN_CCTOR(count);

}

/**
 * Checks whether offset exists in the resultset
 *
 * @param int index
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists) {

	zval *index_param = NULL, *_0;
	int index;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

		index = zephir_get_intval(index_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "count");
	RETURN_MM_BOOL(ZEPHIR_LT_LONG(_0, index));

}

/**
 * Gets row in a specific position of the resultset
 *
 * @param int index
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet) {

	zval *index, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "count");
	if (ZEPHIR_LS(index, _0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
		if (ZEPHIR_IS_EQUAL(_1, index)) {
			zephir_call_method(return_value, this_ptr, "current");
			RETURN_MM();
		}
		zephir_call_method_p1_noret(this_ptr, "seek", index);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_method(_2, this_ptr, "valid");
		if (!ZEPHIR_IS_FALSE(_2)) {
			zephir_call_method(return_value, this_ptr, "current");
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor");
	return;

}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int index
 * @param Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet) {

	zval *index_param = NULL, *value;
	int index;

	zephir_fetch_params(0, 2, 0, &index_param, &value);

		index = zephir_get_intval(index_param);


	ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object");
	return;

}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int offset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset) {

	zend_class_entry *_1;
	zval *offset_param = NULL, *_0;
	int offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

		offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon_Mvc_Model_Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	zephir_throw_exception(_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns the internal type of data retrieval that the resultset is using
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Get first row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 0)) {
		zephir_call_method(return_value, this_ptr, "current");
		RETURN_MM();
	}
	zephir_call_method_noret(this_ptr, "rewind");
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, this_ptr, "valid");
	if (!ZEPHIR_IS_FALSE(_1)) {
		zephir_call_method(return_value, this_ptr, "current");
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get last row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "count");
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) - 1));
	zephir_call_method_p1_noret(this_ptr, "seek", _1);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_method(_1, this_ptr, "valid");
	if (!ZEPHIR_IS_FALSE(_1)) {
		zephir_call_method(return_value, this_ptr, "current");
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Set if the resultset is fresh or an old one cached
 *
 * @param boolean isFresh
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh) {

	zval *isFresh_param = NULL, *_0;
	zend_bool isFresh;

	zephir_fetch_params(0, 1, 0, &isFresh_param);

		isFresh = zephir_get_boolval(isFresh_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, isFresh);
	zephir_update_property_this(this_ptr, SL("_isFresh"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Tell if the resultset if fresh or an old one cached
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh) {


	RETURN_MEMBER(this_ptr, "_isFresh");

}

/**
 * Sets the hydration mode in the resultset
 *
 * @param int hydrateMode
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode) {

	zval *hydrateMode_param = NULL, *_0;
	int hydrateMode;

	zephir_fetch_params(0, 1, 0, &hydrateMode_param);

		hydrateMode = zephir_get_intval(hydrateMode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, hydrateMode);
	zephir_update_property_zval(this_ptr, SL("_hydrateMode"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current hydration mode
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode) {


	RETURN_MEMBER(this_ptr, "_hydrateMode");

}

/**
 * Returns the associated cache for the resultset
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache) {


	RETURN_MEMBER(this_ptr, "_cache");

}

/**
 * Returns current row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, current) {


	RETURN_MEMBER(this_ptr, "_activeRow");

}

/**
 * Returns the error messages produced by a batch operation
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages) {


	RETURN_MEMBER(this_ptr, "_errorMessages");

}

/**
 * Deletes every record in the resultset
 *
 * @param Closure conditionCallback
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete) {

	zend_function *_4 = NULL, *_5 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;
	HashTable *_2;
	HashPosition _1;
	zend_bool transaction;
	zval *conditionCallback = NULL, *record = NULL, *connection = NULL, *_0, **_3, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &conditionCallback);

	if (!conditionCallback) {
		ZEPHIR_CPY_WRT(conditionCallback, ZEPHIR_GLOBAL(global_null));
	}


	transaction = 0;
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "iterator", this_ptr);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(record, _3);
		if ((transaction == 0)) {
			if (!((zephir_method_exists_str(record, SS("getwriteconnection") TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid");
				return;
			}
			ZEPHIR_INIT_NVAR(connection);
			zephir_call_method_cache(connection, record, "getwriteconnection", &_4);
			transaction = 1;
			zephir_call_method_cache_noret(connection, "begin", &_5);
		}
		if ((Z_TYPE_P(conditionCallback) == IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(_6);
			array_init(_6);
			zephir_array_append(&_6, record, 0);
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_func_p2(_7, "call_user_func_array", conditionCallback, _6);
			if (ZEPHIR_IS_FALSE(_7)) {
				continue;
			}
		}
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, record, "delete", &_8);
		if (!(zephir_is_true(_6))) {
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_cache(_7, record, "getmessages", &_9);
			zephir_update_property_this(this_ptr, SL("_errorMessages"), _7 TSRMLS_CC);
			zephir_call_method_cache_noret(connection, "rollback", &_10);
			transaction = 0;
			break;
		}
	}
	if ((transaction == 1)) {
		zephir_call_method_noret(connection, "commit");
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

	HashTable *_2;
	HashPosition _1;
	zval *filter, *records, *record = NULL, *parameters, *processedRecord = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter);



	ZEPHIR_INIT_VAR(records);
	array_init(records);
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "iterator", this_ptr);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(record, _3);
		zephir_array_update_long(&parameters, 0, &record, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(processedRecord);
		zephir_call_func_p2(processedRecord, "call_user_func_array", filter, parameters);
		if ((Z_TYPE_P(processedRecord) != IS_OBJECT)) {
			if ((Z_TYPE_P(processedRecord) != IS_ARRAY)) {
				continue;
			}
		}
		zephir_array_append(&records, processedRecord, PH_SEPARATE);
	}
	RETURN_CCTOR(records);

}

