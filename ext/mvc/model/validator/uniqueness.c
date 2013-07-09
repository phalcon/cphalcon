
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
 *use Phalcon\Mvc\Model\Validator\Uniqueness as Uniqueness;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new Uniqueness(array(
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
	zval *column_map = NULL, *conditions, *bind_params;
	zval *number = NULL, *compose_field = NULL, *column_field = NULL;
	zval *exception_message = NULL, *value = NULL, *compose_condition = NULL;
	zval *bind_type = NULL, *condition = NULL, *operation_made;
	zval *primary_fields, *primary_field = NULL, *attribute_field = NULL;
	zval *join_conditions, *params, *class_name;
	zval *message = NULL, *join_fields, *type;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &record);
	
	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_INIT_VAR(field);
	phalcon_call_method_p1(field, this_ptr, "getoption", option);
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_call_method(dependency_injector, record, "getdi");
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_call_method_p1(meta_data, dependency_injector, "getshared", service);
	
	/** 
	 * PostgreSQL check if the compared constant has the same type as the column, so we
	 * make cast to the data passed to match those column types
	 */
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(bind_data_types);
	phalcon_call_method_p1(bind_data_types, meta_data, "getbindtypes", record);
	if (PHALCON_GLOBAL(orm).column_renaming) {
		PHALCON_INIT_VAR(column_map);
		phalcon_call_method_p1(column_map, meta_data, "getreversecolumnmap", record);
	} else {
		PHALCON_INIT_NVAR(column_map);
	}
	
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
		phalcon_is_iterable(field, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(compose_field);
	
			/** 
			 * The reversed column map is used in the case to get real column name
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, compose_field)) {
					PHALCON_OBS_NVAR(column_field);
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
			if (!phalcon_array_isset(bind_data_types, column_field)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", column_field, "\" isn't part of the table columns");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * The attribute could be "protected" so we read using "readattribute"
			 */
			PHALCON_INIT_NVAR(value);
			phalcon_call_method_p1(value, record, "readattribute", compose_field);
	
			PHALCON_INIT_NVAR(compose_condition);
			PHALCON_CONCAT_SVSV(compose_condition, "[", compose_field, "] = ?", number);
			phalcon_array_append(&conditions, compose_condition, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_OBS_NVAR(bind_type);
			phalcon_array_fetch(&bind_type, bind_data_types, column_field, PH_NOISY_CC);
			phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
			PHALCON_SEPARATE(number);
			phalcon_increment(number);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		/** 
		 * The reversed column map is used in the case to get real column name
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (phalcon_array_isset(column_map, field)) {
				PHALCON_OBS_NVAR(column_field);
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
		if (!phalcon_array_isset(bind_data_types, column_field)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", column_field, "\" isn't part of the table columns");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * We're checking the uniqueness with only one field
		 */
		PHALCON_INIT_NVAR(value);
		phalcon_call_method_p1(value, record, "readattribute", field);
	
		PHALCON_INIT_VAR(condition);
		PHALCON_CONCAT_SVS(condition, "[", field, "] = ?0");
		phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_OBS_NVAR(bind_type);
		phalcon_array_fetch(&bind_type, bind_data_types, column_field, PH_NOISY_CC);
		phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
		PHALCON_SEPARATE(number);
		phalcon_increment(number);
	}
	
	/** 
	 * If the operation is update, there must be values in the object
	 */
	PHALCON_INIT_VAR(operation_made);
	phalcon_call_method(operation_made, record, "getoperationmade");
	if (PHALCON_IS_LONG(operation_made, 2)) {
	
		/** 
		 * We build a query with the primary key attributes
		 */
		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_INIT_NVAR(column_map);
			phalcon_call_method_p1(column_map, meta_data, "getcolumnmap", record);
		} else {
			PHALCON_INIT_NVAR(column_map);
		}
	
		PHALCON_INIT_VAR(primary_fields);
		phalcon_call_method_p1(primary_fields, meta_data, "getprimarykeyattributes", record);
	
		phalcon_is_iterable(primary_fields, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(primary_field);
	
			if (!phalcon_array_isset(bind_data_types, primary_field)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", primary_field, "\" isn't part of the table columns");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Rename the column if there is a column map
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, primary_field)) {
					PHALCON_OBS_NVAR(attribute_field);
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
			phalcon_call_method_p1(value, record, "readattribute", primary_field);
	
			PHALCON_INIT_NVAR(condition);
			PHALCON_CONCAT_SVSV(condition, "[", attribute_field, "] <> ?", number);
			phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_OBS_NVAR(bind_type);
			phalcon_array_fetch(&bind_type, bind_data_types, primary_field, PH_NOISY_CC);
			phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
			PHALCON_SEPARATE(number);
			phalcon_increment(number);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	}
	
	PHALCON_INIT_VAR(join_conditions);
	phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
	/** 
	 * We don't trust the user, so we pass the parameters as bound parameters
	 */
	PHALCON_INIT_VAR(params);
	array_init(params);
	phalcon_array_update_string(&params, SL("di"), &dependency_injector, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&params, SL("conditions"), &join_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&params, SL("bind"), &bind_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&params, SL("bindTypes"), &bind_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, record, 0 TSRMLS_CC);
	
	/** 
	 * Check using a standard count
	 */
	phalcon_call_zval_str_static_p1(number, class_name, "count", params);
	if (!PHALCON_IS_LONG(number, 0)) {
	
		/** 
		 * Check if the developer has defined a custom message
		 */
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "message", 1);
	
		PHALCON_INIT_VAR(message);
		phalcon_call_method_p1(message, this_ptr, "getoption", option);
		if (!zend_is_true(message)) {
			if (Z_TYPE_P(field) == IS_ARRAY) { 
				PHALCON_INIT_VAR(join_fields);
				phalcon_fast_join_str(join_fields, SL(", "), field TSRMLS_CC);
	
				PHALCON_INIT_NVAR(message);
				PHALCON_CONCAT_SVS(message, "Value of fields: '", join_fields, "' are already present in another record");
			} else {
				PHALCON_INIT_NVAR(message);
				PHALCON_CONCAT_SVS(message, "Value of field: '", field, "' is already present in another record");
			}
		}
	
		/** 
		 * Append the message to the validator
		 */
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "Unique", 1);
		phalcon_call_method_p3_noret(this_ptr, "appendmessage", message, field, type);
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

