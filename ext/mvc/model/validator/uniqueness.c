
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

#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"

/**
 * Phalcon\Mvc\Model\Validator\Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Uniqueness as UniquenessValidator;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new UniquenessValidator(array(
 *          'field' => 'email'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 *
 */


/**
 * Phalcon\Mvc\Model\Validator\Uniqueness initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Uniqueness){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Uniqueness, mvc_model_validator_uniqueness, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_uniqueness_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_uniqueness_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Uniqueness, validate){

	zval *record, *option = NULL, *field, *dependency_injector;
	zval *service, *meta_data, *bind_types, *bind_data_types;
	zval *column_map = NULL, *conditions = NULL, *bind_params;
	zval *number = NULL, *compose_field = NULL, *column_field = NULL;
	zval *exception_message = NULL, *value = NULL, *bind_type = NULL;
	zval *condition = NULL, *operation_made, *primary_fields;
	zval *primary_field = NULL, *attribute_field = NULL, *params;
	zval *class_name, *message = NULL, *type;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_INIT_VAR(field);
	PHALCON_CALL_METHOD_PARAMS_1(field, this_ptr, "getoption", option, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(dependency_injector);
	PHALCON_CALL_METHOD(dependency_injector, record, "getdi", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	/** 
	 * PostgreSQL check if the compared constant has the same type as the column, so we
	 * make cast to the data passed to match those column types
	 */
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(bind_data_types);
	PHALCON_CALL_METHOD_PARAMS_1(bind_data_types, meta_data, "getbindtypes", record, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(column_map);
	PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getreversecolumnmap", record, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	
	PHALCON_INIT_VAR(bind_params);
	array_init(bind_params);
	
	PHALCON_INIT_VAR(number);
	ZVAL_LONG(number, 0);
	if (Z_TYPE_P(field) == IS_ARRAY) { 
		/** 
		 * The field can be an array of values
		 */
	
		if (!phalcon_valid_foreach(field TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(field);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_VALUE(compose_field);
	
			/** 
			 * The reversed column map is used in the case to get real column name
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				eval_int = phalcon_array_isset(column_map, compose_field);
				if (eval_int) {
					PHALCON_INIT_NVAR(column_field);
					phalcon_array_fetch(&column_field, column_map, compose_field, PH_NOISY_CC);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", compose_field, "\" isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(column_field, compose_field);
			}
	
			/** 
			 * Some database systems require that we pass the values using bind casting
			 */
			eval_int = phalcon_array_isset(bind_data_types, column_field);
			if (!eval_int) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", column_field, "\" isn't part of the table columns");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * The attribute could be "protected" so we read using "readattribute"
			 */
			PHALCON_INIT_NVAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", compose_field, PH_NO_CHECK);
	
			PHALCON_INIT_NVAR(r0);
			PHALCON_CONCAT_VSV(r0, compose_field, " = ?", number);
			phalcon_array_append(&conditions, r0, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(bind_type);
			phalcon_array_fetch(&bind_type, bind_data_types, column_field, PH_NOISY_CC);
			phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
			PHALCON_SEPARATE(number);
			increment_function(number);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
		if(0){}
	
	} else {
		/** 
		 * The reversed column map is used in the case to get real column name
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			eval_int = phalcon_array_isset(column_map, field);
			if (eval_int) {
				PHALCON_INIT_NVAR(column_field);
				phalcon_array_fetch(&column_field, column_map, field, PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the column map");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			PHALCON_CPY_WRT(column_field, field);
		}
	
		/** 
		 * Some database systems require that we pass the values using bind casting
		 */
		eval_int = phalcon_array_isset(bind_data_types, column_field);
		if (!eval_int) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", column_field, "\" isn't part of the table columns");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * We're checking the uniqueness with only one field
		 */
		PHALCON_INIT_NVAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field, PH_NO_CHECK);
	
		PHALCON_INIT_VAR(condition);
		PHALCON_CONCAT_VS(condition, field, " = ?0");
		phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(bind_type);
		phalcon_array_fetch(&bind_type, bind_data_types, column_field, PH_NOISY_CC);
		phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
		PHALCON_SEPARATE(number);
		increment_function(number);
	}
	
	/** 
	 * If the operation is update, there must be values in the object
	 */
	PHALCON_INIT_VAR(operation_made);
	PHALCON_CALL_METHOD(operation_made, record, "getoperationmade", PH_NO_CHECK);
	if (phalcon_compare_strict_long(operation_made, 2 TSRMLS_CC)) {
		/** 
		 * We build a query with the primary key attributes
		 */
		PHALCON_INIT_NVAR(column_map);
		PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", record, PH_NO_CHECK);
	
		PHALCON_INIT_VAR(primary_fields);
		PHALCON_CALL_METHOD_PARAMS_1(primary_fields, meta_data, "getprimarykeyattributes", record, PH_NO_CHECK);
	
		if (!phalcon_valid_foreach(primary_fields TSRMLS_CC)) {
			return;
		}
	
		ah1 = Z_ARRVAL_P(primary_fields);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
		ph_cycle_start_1:
	
			if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
				goto ph_cycle_end_1;
			}
	
			PHALCON_GET_FOREACH_VALUE(primary_field);
	
			eval_int = phalcon_array_isset(bind_data_types, primary_field);
			if (!eval_int) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", primary_field, "\" isn't part of the table columns");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Rename the column if there is a column map
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				eval_int = phalcon_array_isset(column_map, primary_field);
				if (eval_int) {
					PHALCON_INIT_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, primary_field, PH_NOISY_CC);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", primary_field, "\" isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, primary_field);
			}
	
			/** 
			 * Create a condition based on the renamed primary key
			 */
			PHALCON_INIT_NVAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", primary_field, PH_NO_CHECK);
	
			PHALCON_INIT_NVAR(condition);
			PHALCON_CONCAT_VSV(condition, attribute_field, " <> ?", number);
			phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(bind_type);
			phalcon_array_fetch(&bind_type, bind_data_types, primary_field, PH_NOISY_CC);
			phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
			PHALCON_SEPARATE(number);
			increment_function(number);
	
			zend_hash_move_forward_ex(ah1, &hp1);
			goto ph_cycle_start_1;
	
		ph_cycle_end_1:
		if(0){}
	
	}
	
	PHALCON_INIT_VAR(r1);
	phalcon_fast_join_str(r1, SL(" AND "), conditions TSRMLS_CC);
	PHALCON_CPY_WRT(conditions, r1);
	
	/** 
	 * We don't trust the user, so we pass the parameters as bound parameters
	 */
	PHALCON_INIT_VAR(params);
	array_init(params);
	phalcon_array_update_string(&params, SL("di"), &dependency_injector, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&params, SL("conditions"), &conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&params, SL("bind"), &bind_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&params, SL("bindTypes"), &bind_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, record TSRMLS_CC);
	
	/** 
	 * Check using an standard count
	 */
	PHALCON_CALL_STATIC_ZVAL_PARAMS_1(number, class_name, "count", params);
	if (!phalcon_compare_strict_long(number, 0 TSRMLS_CC)) {
		/** 
		 * Check if the developer has defined a custom message
		 */
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message);
		PHALCON_CALL_METHOD_PARAMS_1(message, this_ptr, "getoption", option, PH_NO_CHECK);
		if (!zend_is_true(message)) {
			PHALCON_INIT_NVAR(message);
			PHALCON_CONCAT_SVS(message, "Value of field '", field, "' is already present in another record");
		}
	
		/** 
		 * Append the message to the validator
		 */
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Unique", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message, field, type, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

