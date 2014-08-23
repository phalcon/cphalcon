
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
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"
#include "kernel/iterator.h"
#include "kernel/array.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Resultset, phalcon, mvc_model_resultset, phalcon_mvc_model_resultset_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

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
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next) {


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_pointer") TSRMLS_CC));

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

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rows = NULL, *result = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (!ZEPHIR_IS_FALSE_IDENTICAL(result)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_activeRow"), PH_NOISY_CC);
			if (Z_TYPE_P(_1) != IS_NULL) {
				ZEPHIR_INIT_VAR(_2);
				ZVAL_LONG(_2, 0);
				ZEPHIR_CALL_METHOD(NULL, result, "dataseek", NULL, _2);
				zephir_check_call_status();
			}
		}
	} else {
		ZEPHIR_OBS_VAR(rows);
		zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(rows) == IS_NULL) {
			ZEPHIR_OBS_NVAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&rows, result, "fetchall",  NULL);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
			}
		}
		if (Z_TYPE_P(rows) == IS_ARRAY) {
			Z_SET_ISREF_P(rows);
			ZEPHIR_CALL_FUNCTION(NULL, "reset", &_3, rows);
			Z_UNSET_ISREF_P(rows);
			zephir_check_call_status();
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

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zval *position_param = NULL, *result = NULL, *rows = NULL, *_0, *_1, *_2, *_5;
	int position, i, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position_param);

	position = zephir_get_intval(position_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, position)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (zephir_is_true(_1)) {
			ZEPHIR_OBS_VAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (!ZEPHIR_IS_FALSE_IDENTICAL(result)) {
				ZEPHIR_INIT_VAR(_2);
				ZVAL_LONG(_2, position);
				ZEPHIR_CALL_METHOD(NULL, result, "dataseek", NULL, _2);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_OBS_VAR(rows);
			zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
			if (Z_TYPE_P(rows) == IS_NULL) {
				ZEPHIR_OBS_NVAR(result);
				zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
				if (Z_TYPE_P(result) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&rows, result, "fetchall",  NULL);
					zephir_check_call_status();
					zephir_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
				}
			}
			if (Z_TYPE_P(rows) == IS_ARRAY) {
				i = 0;
				Z_SET_ISREF_P(rows);
				ZEPHIR_CALL_FUNCTION(NULL, "reset", &_3, rows);
				Z_UNSET_ISREF_P(rows);
				zephir_check_call_status();
				while (1) {
					if (!(i < position)) {
						break;
					}
					Z_SET_ISREF_P(rows);
					ZEPHIR_CALL_FUNCTION(NULL, "next", &_4, rows);
					Z_UNSET_ISREF_P(rows);
					zephir_check_call_status();
					i++;
				}
			}
		}
		ZEPHIR_INIT_ZVAL_NREF(_5);
		ZVAL_LONG(_5, position);
		zephir_update_property_this(this_ptr, SL("_pointer"), _5 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *count, *result = NULL, *rows = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(count);
	zephir_read_property_this(&count, this_ptr, SL("_count"), PH_NOISY_CC);
	if (Z_TYPE_P(count) == IS_NULL) {
		ZEPHIR_INIT_BNVAR(count);
		ZVAL_LONG(count, 0);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (zephir_is_true(_0)) {
			ZEPHIR_OBS_VAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (!ZEPHIR_IS_FALSE_IDENTICAL(result)) {
				ZEPHIR_CALL_METHOD(&_1, result, "numrows",  NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_BNVAR(count);
				ZVAL_LONG(count, zephir_get_intval(_1));
			}
		} else {
			ZEPHIR_OBS_VAR(rows);
			zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
			if (Z_TYPE_P(rows) == IS_NULL) {
				ZEPHIR_OBS_NVAR(result);
				zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
				if (Z_TYPE_P(result) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&rows, result, "fetchall",  NULL);
					zephir_check_call_status();
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *index_param = NULL, *_0 = NULL;
	int index, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	index = zephir_get_intval(index_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count",  &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(_0, index));

}

/**
 * Gets row in a specific position of the resultset
 *
 * @param int index
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_5 = NULL;
	zval *index_param = NULL, *_0 = NULL, *_2, _4, *_6 = NULL;
	int index, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	index = Z_LVAL_P(index_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count",  &_1);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(_0, index)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_2, index)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", &_3);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, index);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", &_5, &_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "valid",  NULL);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", &_3);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor", "phalcon/mvc/model/resultset.zep", 283);
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



	if (!(zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'value' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 294);
	return;

}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int offset
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
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Get first row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface|boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", &_1);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "valid",  NULL);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", &_1);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get last row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface| boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, _2, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count",  &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, (zephir_get_numberval(_0) - 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "valid",  NULL);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", &_5);
		zephir_check_call_status();
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

	zval *isFresh_param = NULL;
	zend_bool isFresh;

	zephir_fetch_params(0, 1, 0, &isFresh_param);

	isFresh = zephir_get_boolval(isFresh_param);


	zephir_update_property_this(this_ptr, SL("_isFresh"), isFresh ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
	zephir_update_property_this(this_ptr, SL("_hydrateMode"), _0 TSRMLS_CC);
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

	zval *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_object_iterator *_1;
	zend_bool _0, transaction;
	zval *conditionCallback = NULL, *record = NULL, *connection = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &conditionCallback);

	if (!conditionCallback) {
		conditionCallback = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(connection);
	ZVAL_NULL(connection);


	_0 = Z_TYPE_P(conditionCallback) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(conditionCallback, zend_ce_closure TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'conditionCallback' must be an instance of 'Closure'", "", 0);
		return;
	}
	transaction = 0;
	_1 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{ zval **tmp; 
		_1->funcs->get_current_data(_1, &tmp TSRMLS_CC);
		record = *tmp;
		}
		if (transaction == 0) {
			if (!((zephir_method_exists_ex(record, SS("getwriteconnection") TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 450);
				return;
			}
			ZEPHIR_CALL_METHOD(&connection, record, "getwriteconnection",  NULL);
			zephir_check_call_status();
			transaction = 1;
			ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(conditionCallback) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_INIT_NVAR(_3);
			array_init_size(_3, 2);
			zephir_array_fast_append(_3, record);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_2, conditionCallback, _3);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_4, record, "delete",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_4))) {
			ZEPHIR_CALL_METHOD(&_5, record, "getmessages",  NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_errorMessages"), _5 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, connection, "rollback", NULL);
			zephir_check_call_status();
			transaction = 0;
			break;
		}
	}
	_1->funcs->dtor(_1 TSRMLS_CC);
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
		{ zval **tmp; 
		_0->funcs->get_current_data(_0, &tmp TSRMLS_CC);
		record = *tmp;
		}
		zephir_array_update_long(&parameters, 0, &record, PH_COPY | PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 519);
		ZEPHIR_INIT_NVAR(processedRecord);
		ZEPHIR_CALL_USER_FUNC_ARRAY(processedRecord, filter, parameters);
		zephir_check_call_status();
		if (Z_TYPE_P(processedRecord) != IS_OBJECT) {
			if (Z_TYPE_P(processedRecord) != IS_ARRAY) {
				continue;
			}
		}
		zephir_array_append(&records, processedRecord, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 531);
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_CCTOR(records);

}

