
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
 * $robots = $Robots::find(array("type='virtual'", "order" => "name"));
 * foreach($robots as $robot){
 *  echo $robot->name, "\n";
 * }
 *
 * //Using a while
 * $robots = $Robots::find(array("type='virtual'", "order" => "name"));
 * $robots->rewind();
 * while($robots->valid()){
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
	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("_pointer"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_count"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_activeRow"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_rows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Moves cursor to next row in the resultset
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, next){

	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_pointer"), PH_NOISY_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, SL("_pointer"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets pointer number of active row in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key){

	zval *pointer;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(pointer);
	phalcon_read_property(&pointer, this_ptr, SL("_pointer"), PH_NOISY_CC);
	
	RETURN_CCTOR(pointer);
}

/**
 * Rewinds resultset to its beginning
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind){

	zval *type, *result, *active_row, *zero, *rows;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {
		PHALCON_INIT_VAR(result);
		phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (PHALCON_IS_NOT_FALSE(result)) {
			phalcon_update_property_long(this_ptr, SL("_pointer"), 1 TSRMLS_CC);
	
			PHALCON_INIT_VAR(active_row);
			phalcon_read_property(&active_row, this_ptr, SL("_activeRow"), PH_NOISY_CC);
			if (Z_TYPE_P(active_row) != IS_NULL) {
				PHALCON_INIT_VAR(zero);
				ZVAL_LONG(zero, 0);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "dataseek", zero, PH_NO_CHECK);
			}
		}
	} else {
		PHALCON_INIT_VAR(rows);
		phalcon_read_property(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(rows) == IS_ARRAY) { 
			Z_SET_ISREF_P(rows);
			PHALCON_CALL_FUNC_PARAMS_1_NORETURN("reset", rows);
			Z_UNSET_ISREF_P(rows);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Changes internal pointer to a specific position in the resultset
 *
 * @param int $position
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek){

	zval *numeric_position, *type, *result, *rows;
	long i, position = 0;
	HashTable *ah0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &position) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {

		PHALCON_INIT_VAR(numeric_position);
		ZVAL_LONG(numeric_position, position);

		PHALCON_INIT_VAR(result);
		phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "dataseek", numeric_position, PH_NO_CHECK);

	} else {

		PHALCON_INIT_VAR(rows);
		phalcon_read_property(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);

		if (Z_TYPE_P(rows) == IS_NULL) {
			PHALCON_INIT_VAR(result);
			phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (PHALCON_IS_NOT_FALSE(result)) {
				PHALCON_INIT_NVAR(rows);
				PHALCON_CALL_METHOD(rows, result, "fetchall", PH_NO_CHECK);
				phalcon_update_property_zval(this_ptr, SL("_rows"), rows TSRMLS_CC);
			}
		}

		if(Z_TYPE_P(rows) == IS_ARRAY){

			ah0 = Z_ARRVAL_P(rows);
			zend_hash_internal_pointer_reset(ah0);

			i = 0;
			ph_cycle_start_0:

				if (i >= position) {
					goto ph_cycle_end_0;
				}

				zend_hash_move_forward(ah0);
				i++;
				goto ph_cycle_start_0;

			ph_cycle_end_0:
			if(0){}
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

	PHALCON_INIT_VAR(count);
	phalcon_read_property(&count, this_ptr, SL("_count"), PH_NOISY_CC);
	if (Z_TYPE_P(count) == IS_NULL) {
		PHALCON_INIT_NVAR(count);
		ZVAL_LONG(count, 0);
	
		PHALCON_INIT_VAR(type);
		phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
		if (zend_is_true(type)) {
			PHALCON_INIT_VAR(result);
			phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (PHALCON_IS_NOT_FALSE(result)) {
				PHALCON_INIT_VAR(number_rows);
				PHALCON_CALL_METHOD(number_rows, result, "numrows", PH_NO_CHECK);
	
				PHALCON_INIT_NVAR(count);
				PHALCON_CALL_FUNC_PARAMS_1(count, "intval", number_rows);
			}
		} else {
			PHALCON_INIT_VAR(rows);
			phalcon_read_property(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
			if (Z_TYPE_P(rows) == IS_NULL) {
				PHALCON_INIT_NVAR(result);
				phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
				if (PHALCON_IS_NOT_FALSE(result)) {
					PHALCON_INIT_NVAR(rows);
					PHALCON_CALL_METHOD(rows, result, "fetchall", PH_NO_CHECK);
					phalcon_update_property_zval(this_ptr, SL("_rows"), rows TSRMLS_CC);
				}
			}
	
			PHALCON_INIT_NVAR(count);
			phalcon_fast_count(count, rows TSRMLS_CC);
		}
	
		phalcon_update_property_zval(this_ptr, SL("_count"), count TSRMLS_CC);
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

	zval *index, *count, *exists;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(count);
	PHALCON_CALL_METHOD(count, this_ptr, "count", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exists);
	is_smaller_function(exists, index, count TSRMLS_CC);
	
	RETURN_NCTOR(exists);
}

/**
 * Gets row in a specific position of the resultset
 *
 * @param int $index
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet){

	zval *index, *count, *exists, *valid, *current;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(count);
	PHALCON_CALL_METHOD(count, this_ptr, "count", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exists);
	is_smaller_function(exists, index, count TSRMLS_CC);
	if (PHALCON_IS_TRUE(exists)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "seek", index, PH_NO_CHECK);
	
		PHALCON_INIT_VAR(valid);
		PHALCON_CALL_METHOD(valid, this_ptr, "valid", PH_NO_CHECK);
		if (PHALCON_IS_NOT_FALSE(valid)) {
			PHALCON_INIT_VAR(current);
			PHALCON_CALL_METHOD(current, this_ptr, "current", PH_NO_CHECK);
	
			RETURN_CCTOR(current);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The index does not exist in the cursor");
	return;
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $index
 * @param Phalcon\Mvc\Model $value
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet){

	zval *index, *value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object");
	return;
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $offset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset){

	zval *offset;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &offset) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cursor is an immutable ArrayAccess object");
	return;
}

/**
 * Get first row in the resultset
 *
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst){

	zval *valid, *current;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(valid);
	PHALCON_CALL_METHOD(valid, this_ptr, "valid", PH_NO_CHECK);
	if (PHALCON_IS_NOT_FALSE(valid)) {
		PHALCON_INIT_VAR(current);
		PHALCON_CALL_METHOD(current, this_ptr, "current", PH_NO_CHECK);
	
		RETURN_CCTOR(current);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Get last row in the resultset
 *
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast){

	zval *count, *pre_count, *valid, *current;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(count);
	PHALCON_CALL_METHOD(count, this_ptr, "count", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	
	PHALCON_INIT_VAR(pre_count);
	sub_function(pre_count, count, t0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "seek", pre_count, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(valid);
	PHALCON_CALL_METHOD(valid, this_ptr, "valid", PH_NO_CHECK);
	if (PHALCON_IS_NOT_FALSE(valid)) {
		PHALCON_INIT_VAR(current);
		PHALCON_CALL_METHOD(current, this_ptr, "current", PH_NO_CHECK);
	
		RETURN_CCTOR(current);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Set if the resultset is fresh or an old one cached
 *
 * @param boolean $isFresh
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh){

	zval *is_fresh;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &is_fresh) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_isFresh"), is_fresh TSRMLS_CC);
	
}

/**
 * Tell if the resultset if fresh or an old one cached
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh){

	zval *is_fresh;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(is_fresh);
	phalcon_read_property(&is_fresh, this_ptr, SL("_isFresh"), PH_NOISY_CC);
	
	RETURN_CCTOR(is_fresh);
}

/**
 * Returns the associated cache for the resultset
 *
 * @return Phalcon\Cache\Backend
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache){

	zval *cache;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(cache);
	phalcon_read_property(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	
	RETURN_CCTOR(cache);
}

/**
 * Returns current row in the resultset
 *
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset, current){

	zval *active_row;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(active_row);
	phalcon_read_property(&active_row, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	
	RETURN_CCTOR(active_row);
}

