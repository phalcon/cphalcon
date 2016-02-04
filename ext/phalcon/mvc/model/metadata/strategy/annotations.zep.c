
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

	zend_bool _27$$6;
	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *annotations = NULL, *className = NULL, *reflection = NULL, *propertiesAnnotations = NULL, *property = NULL, *propAnnotations = NULL, *columnAnnotation = NULL, *columnName = NULL, *feature = NULL, *fieldTypes = NULL, *fieldBindTypes = NULL, *numericTyped = NULL, *primaryKeys = NULL, *nonPrimaryKeys = NULL, *identityField = NULL, *notNull = NULL, *attributes = NULL, *automaticDefault = NULL, *defaultValues = NULL, *defaultValue = NULL, *emptyStringValues = NULL, *_0, **_7, *_1$$4, *_2$$4, *_3$$5, *_4$$5, *_8$$6 = NULL, *_9$$6 = NULL, *_24$$6 = NULL, *_25$$6 = NULL, *_26$$6 = NULL, *_28$$6 = NULL, *_10$$9 = NULL, *_11$$9 = NULL, *_12$$10 = NULL, *_13$$10 = NULL, *_14$$11 = NULL, *_15$$11 = NULL, *_16$$12 = NULL, *_17$$12 = NULL, *_18$$13 = NULL, *_19$$13 = NULL, *_20$$14 = NULL, *_21$$14 = NULL, *_22$$15 = NULL, *_23$$15 = NULL;

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
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SV(_2$$4, "No annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 9, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "phalcon/mvc/model/metadata/strategy/annotations.zep", 51 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(propertiesAnnotations TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_3$$5);
		object_init_ex(_3$$5, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_4$$5);
		ZEPHIR_CONCAT_SV(_4$$5, "No properties with annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _3$$5, "__construct", NULL, 9, _4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$5, "phalcon/mvc/model/metadata/strategy/annotations.zep", 60 TSRMLS_CC);
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
	zephir_is_iterable(propertiesAnnotations, &_6, &_5, 0, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 184);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(property, _6, _5);
		ZEPHIR_GET_HVALUE(propAnnotations, _7);
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8$$6, propAnnotations, "has", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(_8$$6))) {
			continue;
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnAnnotation, propAnnotations, "get", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnName, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(columnName)) {
			ZEPHIR_CPY_WRT(columnName, property);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&feature, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_STRING(feature, "integer")) {
				ZEPHIR_INIT_NVAR(_10$$9);
				ZVAL_LONG(_10$$9, 0);
				zephir_array_update_zval(&fieldTypes, property, &_10$$9, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_11$$9);
				ZVAL_LONG(_11$$9, 1);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_11$$9, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "decimal")) {
				ZEPHIR_INIT_NVAR(_12$$10);
				ZVAL_LONG(_12$$10, 3);
				zephir_array_update_zval(&fieldTypes, columnName, &_12$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_13$$10);
				ZVAL_LONG(_13$$10, 32);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_13$$10, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "boolean")) {
				ZEPHIR_INIT_NVAR(_14$$11);
				ZVAL_LONG(_14$$11, 8);
				zephir_array_update_zval(&fieldTypes, columnName, &_14$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_15$$11);
				ZVAL_LONG(_15$$11, 5);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_15$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "date")) {
				ZEPHIR_INIT_NVAR(_16$$12);
				ZVAL_LONG(_16$$12, 1);
				zephir_array_update_zval(&fieldTypes, columnName, &_16$$12, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_17$$12);
				ZVAL_LONG(_17$$12, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_17$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "datetime")) {
				ZEPHIR_INIT_NVAR(_18$$13);
				ZVAL_LONG(_18$$13, 4);
				zephir_array_update_zval(&fieldTypes, columnName, &_18$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_19$$13);
				ZVAL_LONG(_19$$13, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_19$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "text")) {
				ZEPHIR_INIT_NVAR(_20$$14);
				ZVAL_LONG(_20$$14, 6);
				zephir_array_update_zval(&fieldTypes, columnName, &_20$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_21$$14);
				ZVAL_LONG(_21$$14, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_21$$14, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_22$$15);
			ZVAL_LONG(_22$$15, 2);
			zephir_array_update_zval(&fieldTypes, columnName, &_22$$15, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_23$$15);
			ZVAL_LONG(_23$$15, 2);
			zephir_array_update_zval(&fieldBindTypes, columnName, &_23$$15, PH_COPY | PH_SEPARATE);
		} while(0);

		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "Primary", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_24$$6, propAnnotations, "has", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (zephir_is_true(_24$$6)) {
			zephir_array_append(&primaryKeys, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 151);
		} else {
			zephir_array_append(&nonPrimaryKeys, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 153);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "Identity", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_25$$6, propAnnotations, "has", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (zephir_is_true(_25$$6)) {
			ZEPHIR_CPY_WRT(identityField, columnName);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "nullable", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_26$$6, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(_26$$6))) {
			zephir_array_append(&notNull, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 167);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "default", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&defaultValue, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		_27$$6 = Z_TYPE_P(defaultValue) != IS_NULL;
		if (!(_27$$6)) {
			ZEPHIR_INIT_NVAR(_9$$6);
			ZVAL_STRING(_9$$6, "nullable", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_28$$6, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
			zephir_check_temp_parameter(_9$$6);
			zephir_check_call_status();
			_27$$6 = zephir_is_true(_28$$6);
		}
		if (_27$$6) {
			zephir_array_update_zval(&defaultValues, columnName, &defaultValue, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&attributes, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 178);
	}
	zephir_create_array(return_value, 12, 0 TSRMLS_CC);
	zephir_array_update_long(&return_value, 0, &attributes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 1, &primaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 2, &nonPrimaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 3, &notNull, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 4, &fieldTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 5, &numericTyped, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 8, &identityField, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 9, &fieldBindTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 10, &automaticDefault, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 11, &automaticDefault, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 12, &defaultValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 13, &emptyStringValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	RETURN_MM();

}

/**
 * Read the model's column map, this can't be inferred
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps) {

	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *annotations = NULL, *className = NULL, *reflection = NULL, *propertiesAnnotations = NULL, *property = NULL, *propAnnotations = NULL, *columnAnnotation = NULL, *columnName = NULL, *orderedColumnMap = NULL, *reversedColumnMap = NULL, *_0, **_7, *_1$$4, *_2$$4, *_3$$5, *_4$$5, *_8$$6 = NULL, *_9$$6 = NULL;

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
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SV(_2$$4, "No annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 9, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "phalcon/mvc/model/metadata/strategy/annotations.zep", 217 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(propertiesAnnotations TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_3$$5);
		object_init_ex(_3$$5, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_4$$5);
		ZEPHIR_CONCAT_SV(_4$$5, "No properties with annotations were found in class ", className);
		ZEPHIR_CALL_METHOD(NULL, _3$$5, "__construct", NULL, 9, _4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$5, "phalcon/mvc/model/metadata/strategy/annotations.zep", 225 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(orderedColumnMap);
	ZVAL_NULL(orderedColumnMap);
	ZEPHIR_INIT_VAR(reversedColumnMap);
	ZVAL_NULL(reversedColumnMap);
	zephir_is_iterable(propertiesAnnotations, &_6, &_5, 0, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 262);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(property, _6, _5);
		ZEPHIR_GET_HVALUE(propAnnotations, _7);
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8$$6, propAnnotations, "has", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(_8$$6))) {
			continue;
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "Column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnAnnotation, propAnnotations, "get", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "column", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&columnName, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
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

