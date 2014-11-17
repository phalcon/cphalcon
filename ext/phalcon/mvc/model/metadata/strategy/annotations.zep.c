
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Annotations) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Annotations, phalcon, mvc_model_metadata_strategy_annotations, phalcon_mvc_model_metadata_strategy_annotations_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_metadata_strategy_annotations_ce TSRMLS_CC, 1, phalcon_mvc_model_metadata_strategyinterface_ce);
	return SUCCESS;

}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\DiInterface dependencyInjector
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData) {

	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *annotations = NULL, *className, *reflection = NULL, *propertiesAnnotations = NULL, *property = NULL, *propAnnotations = NULL, *columnAnnotation = NULL, *columnName = NULL, *feature = NULL, *fieldTypes, *fieldBindTypes, *numericTyped, *primaryKeys, *nonPrimaryKeys, *identityField = NULL, *notNull, *attributes, *automaticDefault, *_0 = NULL, *_1 = NULL, *_2 = NULL, **_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/mvc/model/metadata/strategy/annotations.zep", 45);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "annotations", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&annotations, dependencyInjector, "get", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, model, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&reflection, annotations, "get", NULL, className);
	zephir_check_call_status();
	if (Z_TYPE_P(reflection) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "No annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model/metadata/strategy/annotations.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, reflection, "getpropertiesannotations", NULL);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(propertiesAnnotations TSRMLS_CC))) {
		ZEPHIR_INIT_LNVAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SV(_2, "No properties with annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model/metadata/strategy/annotations.zep", 60 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(attributes);
	array_init(attributes);
	ZEPHIR_INIT_VAR(primaryKeys);
	array_init(primaryKeys);
	ZEPHIR_INIT_VAR(nonPrimaryKeys);
	array_init(nonPrimaryKeys);
	ZEPHIR_INIT_VAR(numericTyped);
	array_init(numericTyped);
	ZEPHIR_INIT_VAR(notNull);
	array_init(notNull);
	ZEPHIR_INIT_VAR(fieldTypes);
	array_init(fieldTypes);
	ZEPHIR_INIT_VAR(fieldBindTypes);
	array_init(fieldBindTypes);
	ZEPHIR_INIT_VAR(automaticDefault);
	array_init(automaticDefault);
	ZEPHIR_INIT_VAR(identityField);
	ZVAL_BOOL(identityField, 0);
	zephir_is_iterable(propertiesAnnotations, &_4, &_3, 0, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 160);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(property, _4, _3);
		ZEPHIR_GET_HVALUE(propAnnotations, _5);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6, propAnnotations, "has", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			continue;
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnAnnotation, propAnnotations, "get", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnName, columnAnnotation, "getnamedparameter", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(columnName)) {
			ZEPHIR_CPY_WRT(columnName, property);
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&feature, columnAnnotation, "getnamedparameter", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(feature, "integer")) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 0);
			zephir_array_update_zval(&fieldTypes, property, &_0, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 1);
			zephir_array_update_zval(&fieldBindTypes, columnName, &_7, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			if (ZEPHIR_IS_STRING(feature, "decimal")) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 3);
				zephir_array_update_zval(&fieldTypes, columnName, &_7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 32);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_8, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			} else {
				if (ZEPHIR_IS_STRING(feature, "boolean")) {
					ZEPHIR_INIT_NVAR(_8);
					ZVAL_LONG(_8, 8);
					zephir_array_update_zval(&fieldTypes, columnName, &_8, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(_9);
					ZVAL_LONG(_9, 5);
					zephir_array_update_zval(&fieldBindTypes, columnName, &_9, PH_COPY | PH_SEPARATE);
				} else {
					if (ZEPHIR_IS_STRING(feature, "date")) {
						ZEPHIR_INIT_NVAR(_9);
						ZVAL_LONG(_9, 1);
						zephir_array_update_zval(&fieldTypes, columnName, &_9, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(_10);
						ZVAL_LONG(_10, 2);
						zephir_array_update_zval(&fieldTypes, columnName, &_10, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_INIT_NVAR(_10);
					ZVAL_LONG(_10, 2);
					zephir_array_update_zval(&fieldBindTypes, columnName, &_10, PH_COPY | PH_SEPARATE);
				}
			}
		}
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "Primary", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, propAnnotations, "has", NULL, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		if (zephir_is_true(_11)) {
			zephir_array_append(&primaryKeys, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 135);
		} else {
			zephir_array_append(&nonPrimaryKeys, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 137);
		}
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "Identity", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, propAnnotations, "has", NULL, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		if (zephir_is_true(_12)) {
			ZEPHIR_CPY_WRT(identityField, columnName);
		}
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "nullable", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, columnAnnotation, "getnamedparameter", NULL, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		if (!(zephir_is_true(_13))) {
			zephir_array_append(&notNull, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 151);
		}
		zephir_array_append(&attributes, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 154);
	}
	array_init_size(return_value, 13);
	zephir_array_update_long(&return_value, 0, &attributes, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 1, &primaryKeys, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 2, &nonPrimaryKeys, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 3, &notNull, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 4, &fieldTypes, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 5, &numericTyped, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 8, &identityField, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 9, &fieldBindTypes, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 10, &automaticDefault, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	zephir_array_update_long(&return_value, 11, &automaticDefault, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 171);
	RETURN_MM();

}

/**
 * Read the model's column map, this can't be inferred
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\DiInterface dependencyInjector
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps) {

	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *annotations = NULL, *className, *reflection = NULL, *propertiesAnnotations = NULL, *property = NULL, *propAnnotations = NULL, *columnAnnotation = NULL, *columnName = NULL, *orderedColumnMap = NULL, *reversedColumnMap = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, **_5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/mvc/model/metadata/strategy/annotations.zep", 188);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "annotations", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&annotations, dependencyInjector, "get", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, model, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&reflection, annotations, "get", NULL, className);
	zephir_check_call_status();
	if (Z_TYPE_P(reflection) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "No annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model/metadata/strategy/annotations.zep", 195 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, reflection, "getpropertiesannotations", NULL);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(propertiesAnnotations TSRMLS_CC))) {
		ZEPHIR_INIT_LNVAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SV(_2, "No properties with annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model/metadata/strategy/annotations.zep", 203 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(orderedColumnMap);
	ZVAL_NULL(orderedColumnMap);
	ZEPHIR_INIT_VAR(reversedColumnMap);
	ZVAL_NULL(reversedColumnMap);
	zephir_is_iterable(propertiesAnnotations, &_4, &_3, 0, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 240);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(property, _4, _3);
		ZEPHIR_GET_HVALUE(propAnnotations, _5);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6, propAnnotations, "has", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			continue;
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnAnnotation, propAnnotations, "get", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnName, columnAnnotation, "getnamedparameter", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(columnName))) {
			if (Z_TYPE_P(orderedColumnMap) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(orderedColumnMap);
				array_init(orderedColumnMap);
				ZEPHIR_INIT_NVAR(reversedColumnMap);
				array_init(reversedColumnMap);
			}
			zephir_array_update_zval(&orderedColumnMap, columnName, &property, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&reversedColumnMap, property, &columnName, PH_COPY | PH_SEPARATE);
		}
	}
	array_init_size(return_value, 3);
	zephir_array_fast_append(return_value, orderedColumnMap);
	zephir_array_fast_append(return_value, reversedColumnMap);
	RETURN_MM();

}

