
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"

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
 * foreach ($robots as $robot) {
 *  echo $robot->name, "\n";
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


/**
 * Phalcon\Mvc\Model\Resultset initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Resultset, mvc_model_resultset, phalcon_mvc_model_resultset_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

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

	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 6, phalcon_mvc_model_resultsetinterface_ce, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable, zend_ce_arrayaccess, zend_ce_serializable);

	return SUCCESS;
}

/**
 * Moves cursor to next row in the resultset
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next){


	phalcon_property_incr(this_ptr, SL("_pointer") TSRMLS_CC);
	
}

/**
 * Gets pointer number of active row in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key){


	RETURN_MEMBER(this_ptr, "_pointer");
}

/**
 * Rewinds resultset to its beginning
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind){

	zval *type, *z_zero;

	z_zero = PHALCON_GLOBAL(z_zero);

	type = phalcon_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {
	
		/** 
		 * Here, the resultset act as a result that is fetched one by one
		 */
		zval *result = phalcon_fetch_nproperty_this(this_ptr, SL("_result"), PH_NOISY_CC);
		if (PHALCON_IS_NOT_FALSE(result)) {
	
			zval *active_row = phalcon_fetch_nproperty_this(this_ptr, SL("_activeRow"), PH_NOISY_CC);
			if (Z_TYPE_P(active_row) != IS_NULL) {
				PHALCON_MM_GROW();
				phalcon_call_method_p1_noret(result, "dataseek", z_zero);
				PHALCON_MM_RESTORE();
			}
		}
	} else {
		/** 
		 * Here, the resultset act as an array
		 */
		zval *rows = phalcon_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(rows) == IS_NULL) {
	
			zval *result = phalcon_fetch_nproperty_this(this_ptr, SL("_result"), PH_NOISY_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
				zval *r;
				PHALCON_MM_GROW();
				PHALCON_INIT_VAR(r);
				phalcon_call_method(r, result, "fetchall");
				phalcon_update_property_this(this_ptr, SL("_rows"), r TSRMLS_CC);

				if (likely(Z_TYPE_P(r) == IS_ARRAY)) {
					zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(r), NULL);
				}

				PHALCON_MM_RESTORE();
			}
		}
		else if (Z_TYPE_P(rows) == IS_ARRAY) {
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(rows), NULL);
		}
	}
	
	phalcon_update_property_this(this_ptr, SL("_pointer"), z_zero TSRMLS_CC);
}

/**
 * Changes internal pointer to a specific position in the resultset
 *
 * @param int $position
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek){

	long i;
	zval *type, *result, *rows, *position;
	zval *pointer, *is_different;
	HashTable *ah0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &position) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(pointer);
	phalcon_read_property(&pointer, this_ptr, SL("_pointer"), PH_NOISY_CC);

	/**
	 * We only seek the records if the current position is diferent than the passed one
	 */
	PHALCON_INIT_VAR(is_different);
	is_not_equal_function(is_different, pointer, position TSRMLS_CC);
	if (PHALCON_IS_TRUE(is_different)) {

		PHALCON_OBS_VAR(type);
		phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
		if (zend_is_true(type)) {

			/**
			 * Here, the resultset is fetched one by one because is large
			 */
			PHALCON_OBS_VAR(result);
			phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			phalcon_call_method_p1_noret(result, "dataseek", position);

		} else {

			/**
			 * Here, the resultset is a small array
			 */
			PHALCON_OBS_VAR(rows);
			phalcon_read_property(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);

			/**
			 * We need to fetch the records because rows is null
			 */
			if (Z_TYPE_P(rows) == IS_NULL) {
				PHALCON_OBS_VAR(result);
				phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
				if (PHALCON_IS_NOT_FALSE(result)) {
					PHALCON_INIT_NVAR(rows);
					phalcon_call_method(rows, result, "fetchall");
					phalcon_update_property_zval(this_ptr, SL("_rows"), rows TSRMLS_CC);
				}
			}

			convert_to_long(position);

			if(Z_TYPE_P(rows) == IS_ARRAY){

				ah0 = Z_ARRVAL_P(rows);
				zend_hash_internal_pointer_reset(ah0);

				i = 0;
				while (1) {

					if (i >= Z_LVAL_P(position)) {
						break;
					}

					zend_hash_move_forward(ah0);
					i++;
				}
			}

			phalcon_update_property_zval(this_ptr, SL("_pointer"), position TSRMLS_CC);
		}
	}

	PHALCON_MM_RESTORE();}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count){

	zval *count = NULL, *type, *result = NULL, *number_rows, *rows = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(count);
	phalcon_read_property_this(&count, this_ptr, SL("_count"), PH_NOISY_CC);
	
	/** 
	 * We only calculate the row number is it wasn't calculated before
	 */
	if (Z_TYPE_P(count) == IS_NULL) {
	
		PHALCON_INIT_NVAR(count);
		ZVAL_LONG(count, 0);
	
		PHALCON_OBS_VAR(type);
		phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
		if (zend_is_true(type)) {
	
			/** 
			 * Here, the resultset act as a result that is fetched one by one
			 */
			PHALCON_OBS_VAR(result);
			phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (PHALCON_IS_NOT_FALSE(result)) {
				PHALCON_INIT_VAR(number_rows);
				phalcon_call_method(number_rows, result, "numrows");
	
				PHALCON_INIT_NVAR(count);
				ZVAL_LONG(count, phalcon_get_intval(number_rows));
			}
		} else {
			/** 
			 * Here, the resultset act as an array
			 */
			PHALCON_OBS_VAR(rows);
			phalcon_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
			if (Z_TYPE_P(rows) == IS_NULL) {
	
				PHALCON_OBS_NVAR(result);
				phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
				if (Z_TYPE_P(result) == IS_OBJECT) {
					PHALCON_INIT_NVAR(rows);
					phalcon_call_method(rows, result, "fetchall");
					phalcon_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
				}
			}
	
			PHALCON_INIT_NVAR(count);
			phalcon_fast_count(count, rows TSRMLS_CC);
		}
	
		phalcon_update_property_this(this_ptr, SL("_count"), count TSRMLS_CC);
	}
	
	RETURN_CCTOR(count);
}

/**
 * Checks whether offset exists in the resultset
 *
 * @param int $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists){

	zval *index, *count;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	PHALCON_INIT_VAR(count);
	phalcon_call_method(count, this_ptr, "count");
	is_smaller_function(return_value, index, count TSRMLS_CC);
	RETURN_MM();
}

/**
 * Gets row in a specific position of the resultset
 *
 * @param int $index
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet){

	zval *index, *count, *pointer, *valid;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	PHALCON_INIT_VAR(count);
	phalcon_call_method(count, this_ptr, "count");
	if (PHALCON_LT(index, count)) {
	
		/** 
		 * Check if the last record returned is the current requested
		 */
		PHALCON_OBS_VAR(pointer);
		phalcon_read_property_this(&pointer, this_ptr, SL("_pointer"), PH_NOISY_CC);
		if (PHALCON_IS_EQUAL(pointer, index)) {
			phalcon_call_method(return_value, this_ptr, "current");
			RETURN_MM();
		}
	
		/** 
		 * Move the cursor to the specific position
		 */
		phalcon_call_method_p1_noret(this_ptr, "seek", index);
	
		/** 
		 * Check if the last record returned is the requested
		 */
		PHALCON_INIT_VAR(valid);
		phalcon_call_method(valid, this_ptr, "valid");
		if (PHALCON_IS_NOT_FALSE(valid)) {
			phalcon_call_method(return_value, this_ptr, "current");
			RETURN_MM();
		}
	
		RETURN_MM_FALSE;
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor");
	return;
}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $index
 * @param Phalcon\Mvc\ModelInterface $value
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet){

	zval *index, *value;

	phalcon_fetch_params(0, 2, 0, &index, &value);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object");
	return;
}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $offset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset){

	zval *offset;

	phalcon_fetch_params(0, 1, 0, &offset);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object");
	return;
}

/**
 * Returns the internal type of data retrieval that the resultset is using
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Get first row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst){

	zval *pointer, *valid;

	PHALCON_MM_GROW();

	/** 
	 * Check if the last record returned is the current requested
	 */
	PHALCON_OBS_VAR(pointer);
	phalcon_read_property_this(&pointer, this_ptr, SL("_pointer"), PH_NOISY_CC);
	if (PHALCON_IS_LONG(pointer, 0)) {
		phalcon_call_method(return_value, this_ptr, "current");
		RETURN_MM();
	}
	
	/** 
	 * Otherwise re-execute the statement
	 */
	phalcon_call_method_noret(this_ptr, "rewind");
	
	PHALCON_INIT_VAR(valid);
	phalcon_call_method(valid, this_ptr, "valid");
	if (PHALCON_IS_NOT_FALSE(valid)) {
		phalcon_call_method(return_value, this_ptr, "current");
		RETURN_MM();
	}
	
	RETURN_MM_FALSE;
}

/**
 * Get last row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast){

	zval *z_one, *count, *pre_count, *valid;

	PHALCON_MM_GROW();

	z_one = PHALCON_GLOBAL(z_one);
	
	PHALCON_INIT_VAR(count);
	phalcon_call_method(count, this_ptr, "count");
	
	PHALCON_INIT_VAR(pre_count);
	sub_function(pre_count, count, z_one TSRMLS_CC);
	phalcon_call_method_p1_noret(this_ptr, "seek", pre_count);
	
	PHALCON_INIT_VAR(valid);
	phalcon_call_method(valid, this_ptr, "valid");
	if (PHALCON_IS_NOT_FALSE(valid)) {
		phalcon_call_method(return_value, this_ptr, "current");
		RETURN_MM();
	}
	
	RETURN_MM_FALSE;
}

/**
 * Set if the resultset is fresh or an old one cached
 *
 * @param boolean $isFresh
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh){

	zval *is_fresh;

	phalcon_fetch_params(0, 1, 0, &is_fresh);
	
	phalcon_update_property_this(this_ptr, SL("_isFresh"), is_fresh TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Tell if the resultset if fresh or an old one cached
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh){


	RETURN_MEMBER(this_ptr, "_isFresh");
}

/**
 * Sets the hydration mode in the resultset
 *
 * @param int $hydrateMode
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode){

	zval *hydrate_mode;

	phalcon_fetch_params(0, 1, 0, &hydrate_mode);
	
	phalcon_update_property_this(this_ptr, SL("_hydrateMode"), hydrate_mode TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the current hydration mode
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode){


	RETURN_MEMBER(this_ptr, "_hydrateMode");
}

/**
 * Returns the associated cache for the resultset
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache){


	RETURN_MEMBER(this_ptr, "_cache");
}

/**
 * Returns current row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, current){


	RETURN_MEMBER(this_ptr, "_activeRow");
}

/**
 * Returns the error messages produced by a batch operation
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages){


	RETURN_MEMBER(this_ptr, "_errorMessages");
}

/**
 * Deletes every record in the resultset
 *
 * @param Closure $conditionCallback
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete){

	zval *condition_callback = NULL, *transaction = NULL, *record = NULL;
	zval *connection = NULL, *parameters = NULL, *status = NULL, *messages = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &condition_callback);
	
	if (!condition_callback) {
		condition_callback = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(transaction);
	ZVAL_FALSE(transaction);
	phalcon_call_method_noret(this_ptr, "rewind");
	
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		phalcon_call_method(r0, this_ptr, "valid");
		if (zend_is_true(r0)) {
		} else {
			break;
		}
	
		PHALCON_INIT_NVAR(record);
		phalcon_call_method(record, this_ptr, "current");
		if (PHALCON_IS_FALSE(transaction)) {
	
			/** 
			 * We only can delete resultsets whose every element is a complete object
			 */
			if (phalcon_method_exists_ex(record, SS("getwriteconnection") TSRMLS_CC) == FAILURE) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The returned record is not valid");
				return;
			}
	
			PHALCON_INIT_NVAR(connection);
			phalcon_call_method(connection, record, "getwriteconnection");
			phalcon_call_method_noret(connection, "begin");
	
			PHALCON_INIT_NVAR(transaction);
			ZVAL_TRUE(transaction);
		}
	
		/** 
		 * Perform additional validations
		 */
		if (Z_TYPE_P(condition_callback) == IS_OBJECT) {
	
			PHALCON_INIT_NVAR(parameters);
			array_init_size(parameters, 1);
			phalcon_array_append(&parameters, record, PH_SEPARATE);
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_USER_FUNC_ARRAY(status, condition_callback, parameters);
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}
		}
	
		/** 
		 * Try to delete the record
		 */
		PHALCON_INIT_NVAR(status);
		phalcon_call_method(status, record, "delete");
		if (!zend_is_true(status)) {
			/** 
			 * Get the messages from the record that produce the error
			 */
			PHALCON_INIT_NVAR(messages);
			phalcon_call_method(messages, record, "getmessages");
			phalcon_update_property_this(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
	
			/** 
			 * Rollback the transaction
			 */
			phalcon_call_method_noret(connection, "rollback");
	
			PHALCON_INIT_NVAR(transaction);
			ZVAL_BOOL(transaction, 0);
			break;
		}
	
		phalcon_call_method_noret(this_ptr, "next");
	}
	
	/** 
	 * Commit the transaction
	 */
	if (PHALCON_IS_TRUE(transaction)) {
		phalcon_call_method_noret(connection, "commit");
	}
	
	RETURN_MM_TRUE;
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
 * @param callback $filter
 * @return Phalcon\Mvc\Model[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter){

	zval *filter, *records, *parameters, *record = NULL, *processed_record = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &filter);
	
	PHALCON_INIT_VAR(records);
	array_init(records);
	phalcon_call_method_noret(this_ptr, "rewind");
	
	PHALCON_INIT_VAR(parameters);
	array_init(parameters);
	
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		phalcon_call_method(r0, this_ptr, "valid");
		if (zend_is_true(r0)) {
		} else {
			break;
		}
	
		PHALCON_INIT_NVAR(record);
		phalcon_call_method(record, this_ptr, "current");
		phalcon_array_update_long(&parameters, 0, &record, PH_COPY | PH_SEPARATE);
	
		PHALCON_INIT_NVAR(processed_record);
		PHALCON_CALL_USER_FUNC_ARRAY(processed_record, filter, parameters);
	
		/** 
		 * Only add processed records to 'records' if the returned value is an array/object
		 */
		if (Z_TYPE_P(processed_record) != IS_OBJECT) {
			if (Z_TYPE_P(processed_record) != IS_ARRAY) { 
				continue;
			}
		}
	
		phalcon_array_append(&records, processed_record, PH_SEPARATE);
		phalcon_call_method_noret(this_ptr, "next");
	}
	
	RETURN_CTOR(records);
}

