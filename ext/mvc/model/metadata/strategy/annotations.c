
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

#include "mvc/model/metadata/strategy/annotations.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/array.h"

/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Annotations
 *
 * Queries the table meta-data in order to instrospect the model's metadata
 */
zend_class_entry *phalcon_mvc_model_metadata_strategy_annotations_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_annotations_getmetadata, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_strategy_annotations_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData, arginfo_phalcon_mvc_model_metadata_strategy_annotations_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Annotations initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Annotations){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Annotations, mvc_model_metadata_strategy_annotations, phalcon_mvc_model_metadata_strategy_annotations_method_entry, 0);

	return SUCCESS;
}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\DiInterface $dependencyInjector
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData){

	zval *model, *dependency_injector, *service;
	zval *annotations = NULL, *class_name, *reflection = NULL;
	zval *exception_message = NULL, *properties_annotations = NULL;
	zval *attributes, *primary_keys, *non_primary_keys;
	zval *numeric_typed, *not_null, *field_types;
	zval *field_bind_types, *automatic_default;
	zval *identity_field = NULL, *column_annot_name;
	zval *primary_annot_name, *id_annot_name;
	zval *column_type_name, *column_nullable_name;
	zval *prop_annotations = NULL, *property = NULL, *has_annotation = NULL;
	zval *column_annotation = NULL, *feature = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &dependency_injector);
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "annotations", 1);
	
	PHALCON_CALL_METHOD(&annotations, dependency_injector, "get", service);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 0 TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&reflection, annotations, "get", class_name);
	if (Z_TYPE_P(reflection) != IS_OBJECT) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SV(exception_message, "No annotations were found in class ", class_name);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Get the properties defined in 
	 */
	PHALCON_CALL_METHOD(&properties_annotations, reflection, "getpropertiesannotations");
	if (!phalcon_fast_count_ev(properties_annotations TSRMLS_CC)) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SV(exception_message, "No properties with annotations were found in class ", class_name);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Initialize meta-data
	 */
	PHALCON_INIT_VAR(attributes);
	array_init(attributes);
	
	PHALCON_INIT_VAR(primary_keys);
	array_init(primary_keys);
	
	PHALCON_INIT_VAR(non_primary_keys);
	array_init(non_primary_keys);
	
	PHALCON_INIT_VAR(numeric_typed);
	array_init(numeric_typed);
	
	PHALCON_INIT_VAR(not_null);
	array_init(not_null);
	
	PHALCON_INIT_VAR(field_types);
	array_init(field_types);
	
	PHALCON_INIT_VAR(field_bind_types);
	array_init(field_bind_types);
	
	PHALCON_INIT_VAR(automatic_default);
	array_init(automatic_default);
	
	PHALCON_INIT_VAR(identity_field);
	ZVAL_FALSE(identity_field);
	
	PHALCON_INIT_VAR(column_annot_name);
	ZVAL_STRING(column_annot_name, "Column", 1);
	
	PHALCON_INIT_VAR(primary_annot_name);
	ZVAL_STRING(primary_annot_name, "Primary", 1);
	
	PHALCON_INIT_VAR(id_annot_name);
	ZVAL_STRING(id_annot_name, "Identity", 1);
	
	PHALCON_INIT_VAR(column_type_name);
	ZVAL_STRING(column_type_name, "type", 1);
	
	PHALCON_INIT_VAR(column_nullable_name);
	ZVAL_STRING(column_nullable_name, "nullable", 1);
	
	phalcon_is_iterable(properties_annotations, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(property, ah0, hp0);
		PHALCON_GET_HVALUE(prop_annotations);
	
		/** 
		 * All columns marked with the 'Column' annotation are considered columns
		 */
		PHALCON_CALL_METHOD(&has_annotation, prop_annotations, "has", column_annot_name);
		if (!zend_is_true(has_annotation)) {
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		/** 
		 * Fetch the 'column' annotation
		 */
		PHALCON_CALL_METHOD(&column_annotation, prop_annotations, "get", column_annot_name);
	
		/** 
		 * Check if annotation has the 'type' named parameter
		 */
		PHALCON_CALL_METHOD(&feature, column_annotation, "getargument", column_type_name);
		if (PHALCON_IS_STRING(feature, "integer")) {
			phalcon_array_update_zval_long(&field_types, property, 0, PH_SEPARATE);
			phalcon_array_update_zval_long(&field_bind_types, property, 1, PH_SEPARATE);
			phalcon_array_update_zval_bool(&numeric_typed, property, 1, PH_SEPARATE);
		} else if (PHALCON_IS_STRING(feature, "decimal")) {
			phalcon_array_update_zval_long(&field_types, property, 3, PH_SEPARATE);
			phalcon_array_update_zval_long(&field_bind_types, property, 32, PH_SEPARATE);
			phalcon_array_update_zval_bool(&numeric_typed, property, 1, PH_SEPARATE);
		} else if (PHALCON_IS_STRING(feature, "boolean")) {
			phalcon_array_update_zval_long(&field_types, property, 8, PH_SEPARATE);
			phalcon_array_update_zval_long(&field_bind_types, property, 5, PH_SEPARATE);
		} else {
			if (PHALCON_IS_STRING(feature, "date")) {
				phalcon_array_update_zval_long(&field_types, property, 1, PH_SEPARATE);
			} else {
				/**
				 * By default all columns are varchar/string
				 */
				phalcon_array_update_zval_long(&field_types, property, 2, PH_SEPARATE);
			}
			phalcon_array_update_zval_long(&field_bind_types, property, 2, PH_SEPARATE);
		}
	
		/** 
		 * All columns marked with the 'Primary' annotation are considered primary keys
		 */
		PHALCON_CALL_METHOD(&has_annotation, prop_annotations, "has", primary_annot_name);
		if (zend_is_true(has_annotation)) {
			phalcon_array_append(&primary_keys, property, PH_SEPARATE);
		} else {
			phalcon_array_append(&non_primary_keys, property, PH_SEPARATE);
		}
	
		/** 
		 * All columns marked with the 'Primary' annotation are considered primary keys
		 */
		PHALCON_CALL_METHOD(&has_annotation, prop_annotations, "has", id_annot_name);
		if (zend_is_true(has_annotation)) {
			PHALCON_CPY_WRT(identity_field, property);
		}
	
		/** 
		 * Check if the column 
		 */
		PHALCON_CALL_METHOD(&feature, column_annotation, "getargument", column_nullable_name);
		if (!zend_is_true(feature)) {
			phalcon_array_append(&not_null, property, PH_SEPARATE);
		}
	
		phalcon_array_append(&attributes, property, PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Create an array using the MODELS_* constants as indexes
	 */
	array_init_size(return_value, 10);
	phalcon_array_update_long(&return_value, 0,  attributes, PH_COPY);
	phalcon_array_update_long(&return_value, 1,  primary_keys, PH_COPY);
	phalcon_array_update_long(&return_value, 2,  non_primary_keys, PH_COPY);
	phalcon_array_update_long(&return_value, 3,  not_null, PH_COPY);
	phalcon_array_update_long(&return_value, 4,  field_types, PH_COPY);
	phalcon_array_update_long(&return_value, 5,  numeric_typed, PH_COPY);
	phalcon_array_update_long(&return_value, 8,  identity_field, PH_COPY);
	phalcon_array_update_long(&return_value, 9,  field_bind_types, PH_COPY);
	phalcon_array_update_long(&return_value, 10, automatic_default, PH_COPY);
	phalcon_array_update_long(&return_value, 11, automatic_default, PH_COPY);
	
	PHALCON_MM_RESTORE();
}

/**
 * Read the model's column map, this can't be inferred
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\DiInterface $dependencyInjector
 * @return array
 * @todo Not implemented
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps){


	
}

