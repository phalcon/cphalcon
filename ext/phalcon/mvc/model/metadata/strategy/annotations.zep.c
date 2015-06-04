
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Annotations) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Annotations, phalcon, mvc_model_metadata_strategy_annotations, phalcon_mvc_model_metadata_strategy_annotations_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_metadata_strategy_annotations_ce TSRMLS_CC, 1, phalcon_mvc_model_metadata_strategyinterface_ce);
	return SUCCESS;

}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData) {

	zend_bool _11;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *annotations = NULL, *className, *reflection = NULL, *propertiesAnnotations = NULL, *property = NULL, *propAnnotations = NULL, *columnAnnotation = NULL, *columnName = NULL, *feature = NULL, *fieldTypes, *fieldBindTypes, *numericTyped, *primaryKeys, *nonPrimaryKeys, *identityField = NULL, *notNull, *attributes, *automaticDefault, *defaultValues, *defaultValue = NULL, *emptyStringValues, *_0 = NULL, *_1 = NULL, **_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/mvc/model/metadata/strategy/annotations.zep", 42);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "annotations", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&annotations, dependencyInjector, "get", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, model, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&reflection, annotations, "get", NULL, 0, className);
	zephir_check_call_status();
	if (Z_TYPE_P(reflection) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "No annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 51 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(propertiesAnnotations TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SV(_1, "No properties with annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 60 TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(defaultValues);
	array_init(defaultValues);
	ZEPHIR_INIT_VAR(emptyStringValues);
	array_init(emptyStringValues);
	zephir_is_iterable(propertiesAnnotations, &_3, &_2, 0, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 184);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(property, _3, _2);
		ZEPHIR_GET_HVALUE(propAnnotations, _4);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, propAnnotations, "has", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (!(zephir_is_true(_5))) {
			continue;
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnAnnotation, propAnnotations, "get", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnName, columnAnnotation, "getnamedparameter", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(columnName)) {
			ZEPHIR_CPY_WRT(columnName, property);
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&feature, columnAnnotation, "getnamedparameter", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_STRING(feature, "integer")) {
				ZEPHIR_INIT_NVAR(_0);
				ZVAL_LONG(_0, 0);
				zephir_array_update_zval(&fieldTypes, property, &_0, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 1);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_6, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "decimal")) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 3);
				zephir_array_update_zval(&fieldTypes, columnName, &_6, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 32);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "boolean")) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 8);
				zephir_array_update_zval(&fieldTypes, columnName, &_6, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "date")) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 1);
				zephir_array_update_zval(&fieldTypes, columnName, &_6, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "datetime")) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 4);
				zephir_array_update_zval(&fieldTypes, columnName, &_6, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "text")) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 6);
				zephir_array_update_zval(&fieldTypes, columnName, &_6, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 2);
			zephir_array_update_zval(&fieldTypes, columnName, &_6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 2);
			zephir_array_update_zval(&fieldBindTypes, columnName, &_7, PH_COPY | PH_SEPARATE);
		} while(0);

		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "Primary", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, propAnnotations, "has", NULL, 0, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		if (zephir_is_true(_8)) {
			zephir_array_append(&primaryKeys, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 151);
		} else {
			zephir_array_append(&nonPrimaryKeys, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 153);
		}
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "Identity", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_9, propAnnotations, "has", NULL, 0, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		if (zephir_is_true(_9)) {
			ZEPHIR_CPY_WRT(identityField, columnName);
		}
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "nullable", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, columnAnnotation, "getnamedparameter", NULL, 0, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		if (!(zephir_is_true(_10))) {
			zephir_array_append(&notNull, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 167);
		}
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "default", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&defaultValue, columnAnnotation, "getnamedparameter", NULL, 0, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		_11 = Z_TYPE_P(defaultValue) != IS_NULL;
		if (!(_11)) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "nullable", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12, columnAnnotation, "getnamedparameter", NULL, 0, _6);
			zephir_check_temp_parameter(_6);
			zephir_check_call_status();
			_11 = zephir_is_true(_12);
		}
		if (_11) {
			zephir_array_update_zval(&defaultValues, columnName, &defaultValue, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&attributes, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 178);
	}
	zephir_create_array(return_value, 12, 0 TSRMLS_CC);
	zephir_array_update_long(&return_value, 0, &attributes, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 1, &primaryKeys, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 2, &nonPrimaryKeys, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 3, &notNull, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 4, &fieldTypes, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 5, &numericTyped, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 8, &identityField, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 9, &fieldBindTypes, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 10, &automaticDefault, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 11, &automaticDefault, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 12, &defaultValues, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	zephir_array_update_long(&return_value, 13, &emptyStringValues, PH_COPY, "phalcon/mvc/model/metadata/strategy/annotations.zep", 197);
	RETURN_MM();

}

/**
 * Read the model's column map, this can't be inferred
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *annotations = NULL, *className, *reflection = NULL, *propertiesAnnotations = NULL, *property = NULL, *propAnnotations = NULL, *columnAnnotation = NULL, *columnName = NULL, *orderedColumnMap = NULL, *reversedColumnMap = NULL, *_0 = NULL, *_1 = NULL, **_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/mvc/model/metadata/strategy/annotations.zep", 210);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "annotations", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&annotations, dependencyInjector, "get", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, model, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&reflection, annotations, "get", NULL, 0, className);
	zephir_check_call_status();
	if (Z_TYPE_P(reflection) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "No annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 217 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(propertiesAnnotations TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SV(_1, "No properties with annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 225 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(orderedColumnMap);
	ZVAL_NULL(orderedColumnMap);
	ZEPHIR_INIT_VAR(reversedColumnMap);
	ZVAL_NULL(reversedColumnMap);
	zephir_is_iterable(propertiesAnnotations, &_3, &_2, 0, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 262);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(property, _3, _2);
		ZEPHIR_GET_HVALUE(propAnnotations, _4);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, propAnnotations, "has", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (!(zephir_is_true(_5))) {
			continue;
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnAnnotation, propAnnotations, "get", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnName, columnAnnotation, "getnamedparameter", NULL, 0, _0);
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
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, orderedColumnMap);
	zephir_array_fast_append(return_value, reversedColumnMap);
	RETURN_MM();

}

