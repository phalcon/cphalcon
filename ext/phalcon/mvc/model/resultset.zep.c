
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("TYPE_RESULT_FULL"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("TYPE_RESULT_PARTIAL"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_RECORDS"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_OBJECTS"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_resultset_ce, SL("HYDRATE_ARRAYS"), 1);

	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, phalcon_mvc_model_resultsetinterface_ce);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, zend_ce_iterator);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, spl_ce_SeekableIterator);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, zend_ce_serializable);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset constructor
 *
 * @param \Phalcon\Db\ResultInterface|false result
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result, result_sub, *cache = NULL, cache_sub, __$null, rowCount, rows, _2, _0$$3, _1$$3, _3$$5, _4$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&rowCount);
	ZVAL_UNDEF(&rows);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &result, &cache);

	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}


	if (Z_TYPE_P(result) != IS_OBJECT) {
		ZEPHIR_INIT_ZVAL_NREF(_0$$3);
		ZVAL_LONG(&_0$$3, 0);
		zephir_update_property_zval(this_ptr, SL("_count"), &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_zval(this_ptr, SL("_rows"), &_1$$3);
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, SL("_result"), result);
	if (Z_TYPE_P(cache) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_cache"), cache);
	}
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&rowCount, result, "numrows", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_count"), &rowCount);
	if (ZEPHIR_IS_LONG(&rowCount, 0)) {
		ZEPHIR_INIT_VAR(&_3$$5);
		array_init(&_3$$5);
		zephir_update_property_zval(this_ptr, SL("_rows"), &_3$$5);
		RETURN_MM_NULL();
	}
	if (ZEPHIR_LE_LONG(&rowCount, 32)) {
		ZEPHIR_CALL_METHOD(&rows, result, "fetchall", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&rows) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, SL("_rows"), &rows);
		} else {
			ZEPHIR_INIT_VAR(&_4$$8);
			array_init(&_4$$8);
			zephir_update_property_zval(this_ptr, SL("_rows"), &_4$$8);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Moves cursor to next row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_pointer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 65, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether internal resource has rows to fetch
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_pointer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_count"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_LT(&_0, &_1));

}

/**
 * Gets pointer number of active row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_pointer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_count"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GE(&_0, &_1)) {
		RETURN_NULL();
	}
	RETURN_MEMBER(getThis(), "_pointer");

}

/**
 * Rewinds resultset to its beginning
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 65, &_0);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position);



	zephir_read_property(&_0, this_ptr, SL("_pointer"), PH_NOISY_CC | PH_READONLY);
	_1 = !ZEPHIR_IS_EQUAL(&_0, position);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, SL("_row"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) == IS_NULL;
	}
	if (_1) {
		ZEPHIR_OBS_VAR(&_3$$3);
		zephir_read_property(&_3$$3, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(&_3$$3) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(&row);
			zephir_read_property(&_4$$4, this_ptr, SL("_rows"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_fetch(&row, &_4$$4, position, 0 TSRMLS_CC)) {
				zephir_update_property_zval(this_ptr, SL("_row"), &row);
			}
			zephir_update_property_zval(this_ptr, SL("_pointer"), position);
			zephir_update_property_zval(this_ptr, SL("_activeRow"), &__$null);
			RETURN_MM_NULL();
		}
		ZEPHIR_OBS_VAR(&result);
		zephir_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		zephir_read_property(&_5$$3, this_ptr, SL("_row"), PH_NOISY_CC | PH_READONLY);
		_6$$3 = Z_TYPE_P(&_5$$3) == IS_NULL;
		if (_6$$3) {
			zephir_read_property(&_7$$3, this_ptr, SL("_pointer"), PH_NOISY_CC | PH_READONLY);
			_6$$3 = ZEPHIR_IS_LONG_IDENTICAL(&_7$$3, 0);
		}
		if (_6$$3) {
			ZEPHIR_CALL_METHOD(&_8$$6, &result, "fetch", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_row"), &_8$$6);
		}
		zephir_read_property(&_9$$3, this_ptr, SL("_pointer"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT(&_9$$3, position)) {
			ZEPHIR_CALL_METHOD(NULL, &result, "dataseek", NULL, 0, position);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10$$7, &result, "fetch", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_row"), &_10$$7);
			zephir_update_property_zval(this_ptr, SL("_pointer"), position);
		}
		while (1) {
			zephir_read_property(&_11$$3, this_ptr, SL("_pointer"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_LT(&_11$$3, position))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_12$$8, &result, "fetch", &_13, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_row"), &_12$$8);
			RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_pointer") TSRMLS_CC));
		}
		zephir_update_property_zval(this_ptr, SL("_pointer"), position);
		zephir_update_property_zval(this_ptr, SL("_activeRow"), &__$null);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Counts how many rows are in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_count");

}

/**
 * Checks whether offset exists in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists) {

	zval *index, index_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &index);



	zephir_read_property(&_0, this_ptr, SL("_count"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_LT(index, &_0));

}

/**
 * Gets row in a specific position of the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index, index_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	zephir_read_property(&_0, this_ptr, SL("_count"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_LT(index, &_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 65, index);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor", "phalcon/mvc/model/resultset.zep", 290);
	return;

}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int index
 * @param \Phalcon\Mvc\ModelInterface value
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet) {

	zval *index, index_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &index, &value);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 301);
	return;

}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset) {

	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);

	zephir_fetch_params(0, 1, 0, &offset);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object", "phalcon/mvc/model/resultset.zep", 309);
	return;

}

/**
 * Returns the internal type of data retrieval that the resultset is using
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_rows"), PH_NOISY_CC);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZVAL_LONG(&_0, 0);
	} else {
		ZVAL_LONG(&_0, 1);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Get first row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_count"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 65, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get last row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast) {

	zval count, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&count);
	zephir_read_property(&count, this_ptr, SL("_count"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(&count, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZVAL_LONG(&_0, (zephir_get_numberval(&count) - 1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 65, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set if the resultset is fresh or an old one cached
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh) {

	zval *isFresh_param = NULL, __$true, __$false;
	zend_bool isFresh;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &isFresh_param);

	isFresh = zephir_get_boolval(isFresh_param);


	if (isFresh) {
		zephir_update_property_zval(this_ptr, SL("_isFresh"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_isFresh"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Tell if the resultset if fresh or an old one cached
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_isFresh");

}

/**
 * Sets the hydration mode in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode) {

	zval *hydrateMode_param = NULL, _0;
	zend_long hydrateMode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &hydrateMode_param);

	hydrateMode = zephir_get_intval(hydrateMode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, hydrateMode);
	zephir_update_property_zval(this_ptr, SL("_hydrateMode"), &_0);
	RETURN_THISW();

}

/**
 * Returns the current hydration mode
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_hydrateMode");

}

/**
 * Returns the associated cache for the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_cache");

}

/**
 * Returns the error messages produced by a batch operation
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_errorMessages");

}

/**
 * Updates every record in the resultset
 *
 * @param array data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, update) {

	zval _4$$6;
	zend_bool transaction = 0;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &conditionCallback);

	if (!conditionCallback) {
		conditionCallback = &conditionCallback_sub;
		conditionCallback = &__$null;
	}


	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	transaction = 0;
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 66);
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
			if (!((zephir_method_exists_ex(&record, SL("getwriteconnection") TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 422);
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
			zephir_create_array(&_4$$6, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_4$$6, &record);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_3$$6, conditionCallback, &_4$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$6)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
				zephir_check_call_status();
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_6$$3, &record, "save", NULL, 0, data);
		zephir_check_call_status();
		if (!(zephir_is_true(&_6$$3))) {
			ZEPHIR_CALL_METHOD(&_7$$8, &record, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_7$$8);
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
	RETURN_MM_BOOL(1);

}

/**
 * Deletes every record in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete) {

	zval _4$$6;
	zend_bool result = 0, transaction = 0;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &conditionCallback);

	if (!conditionCallback) {
		conditionCallback = &conditionCallback_sub;
		conditionCallback = &__$null;
	}


	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	result = 1;
	transaction = 0;
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 66);
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
			if (!((zephir_method_exists_ex(&record, SL("getwriteconnection") TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid", "phalcon/mvc/model/resultset.zep", 495);
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
			zephir_create_array(&_4$$6, 1, 0 TSRMLS_CC);
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
			zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_7$$8);
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
 * @return \Phalcon\Mvc\Model[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter) {

	zend_bool _3$$3;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter, filter_sub, records, record, parameters, processedRecord, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&processedRecord);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter);



	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_INIT_VAR(&parameters);
	array_init(&parameters);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 66);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&record, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		zephir_array_update_long(&parameters, 0, &record, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_NVAR(&processedRecord);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&processedRecord, filter, &parameters);
		zephir_check_call_status();
		_3$$3 = Z_TYPE_P(&processedRecord) != IS_OBJECT;
		if (_3$$3) {
			_3$$3 = Z_TYPE_P(&processedRecord) != IS_ARRAY;
		}
		if (_3$$3) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_4, 0);
			zephir_check_call_status();
			continue;
		}
		zephir_array_append(&records, &processedRecord, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 585);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_4, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&records);

}

/**
 * Returns serialised model objects as array for json_encode.
 * Calls jsonSerialize on each object if present
 *
 *<code>
 * $robots = Robots::find();
 * echo json_encode($robots);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, jsonSerialize) {

	zend_bool _3$$3;
	zval records, current, _0, _4$$4;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 66);
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
			_3$$3 = (zephir_method_exists_ex(&current, SL("jsonserialize") TSRMLS_CC) == SUCCESS);
		}
		if (_3$$3) {
			ZEPHIR_CALL_METHOD(&_4$$4, &current, "jsonserialize", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&records, &_4$$4, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 612);
		} else {
			zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/mvc/model/resultset.zep", 614);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_5, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&records);

}

