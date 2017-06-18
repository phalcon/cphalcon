
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

	zend_bool _50$$6;
	HashTable *_6;
	HashPosition _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *annotations = NULL, *className = NULL, *reflection = NULL, *propertiesAnnotations = NULL, *property = NULL, *propAnnotations = NULL, *columnAnnotation = NULL, *columnName = NULL, *feature = NULL, *fieldTypes = NULL, *fieldBindTypes = NULL, *numericTyped = NULL, *primaryKeys = NULL, *nonPrimaryKeys = NULL, *identityField = NULL, *notNull = NULL, *attributes = NULL, *defaultValues = NULL, *defaultValue = NULL, *emptyStringValues = NULL, *skipOnInsert = NULL, *skipOnUpdate = NULL, *_0, **_7, *_1$$4, *_2$$4, *_3$$5, *_4$$5, *_8$$6 = NULL, *_9$$6 = NULL, *_44$$6 = NULL, *_45$$6 = NULL, *_46$$6 = NULL, *_47$$6 = NULL, *_48$$6 = NULL, *_49$$6 = NULL, *_51$$6 = NULL, *_10$$9 = NULL, *_11$$9 = NULL, *_12$$10 = NULL, *_13$$10 = NULL, *_14$$11 = NULL, *_15$$11 = NULL, *_16$$12 = NULL, *_17$$12 = NULL, *_18$$13 = NULL, *_19$$13 = NULL, *_20$$14 = NULL, *_21$$14 = NULL, *_22$$15 = NULL, *_23$$15 = NULL, *_24$$16 = NULL, *_25$$16 = NULL, *_26$$17 = NULL, *_27$$17 = NULL, *_28$$18 = NULL, *_29$$18 = NULL, *_30$$19 = NULL, *_31$$19 = NULL, *_32$$20 = NULL, *_33$$20 = NULL, *_34$$21 = NULL, *_35$$21 = NULL, *_36$$22 = NULL, *_37$$22 = NULL, *_38$$23 = NULL, *_39$$23 = NULL, *_40$$24 = NULL, *_41$$24 = NULL, *_42$$25 = NULL, *_43$$25 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/mvc/model/metadata/strategy/annotations.zep", 43);
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
		zephir_throw_exception_debug(_1$$4, "phalcon/mvc/model/metadata/strategy/annotations.zep", 52 TSRMLS_CC);
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
		zephir_throw_exception_debug(_3$$5, "phalcon/mvc/model/metadata/strategy/annotations.zep", 61 TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(identityField);
	ZVAL_BOOL(identityField, 0);
	ZEPHIR_INIT_VAR(skipOnInsert);
	array_init(skipOnInsert);
	ZEPHIR_INIT_VAR(skipOnUpdate);
	array_init(skipOnUpdate);
	ZEPHIR_INIT_VAR(defaultValues);
	array_init(defaultValues);
	ZEPHIR_INIT_VAR(emptyStringValues);
	array_init(emptyStringValues);
	zephir_is_iterable(propertiesAnnotations, &_6, &_5, 0, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 260);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_forward_ex(_6, &_5)
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
			if (ZEPHIR_IS_STRING(feature, "biginteger")) {
				ZEPHIR_INIT_NVAR(_10$$9);
				ZVAL_LONG(_10$$9, 14);
				zephir_array_update_zval(&fieldTypes, columnName, &_10$$9, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_11$$9);
				ZVAL_LONG(_11$$9, 1);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_11$$9, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "integer")) {
				ZEPHIR_INIT_NVAR(_12$$10);
				ZVAL_LONG(_12$$10, 0);
				zephir_array_update_zval(&fieldTypes, columnName, &_12$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_13$$10);
				ZVAL_LONG(_13$$10, 1);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_13$$10, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "decimal")) {
				ZEPHIR_INIT_NVAR(_14$$11);
				ZVAL_LONG(_14$$11, 3);
				zephir_array_update_zval(&fieldTypes, columnName, &_14$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_15$$11);
				ZVAL_LONG(_15$$11, 32);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_15$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "float")) {
				ZEPHIR_INIT_NVAR(_16$$12);
				ZVAL_LONG(_16$$12, 7);
				zephir_array_update_zval(&fieldTypes, columnName, &_16$$12, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_17$$12);
				ZVAL_LONG(_17$$12, 32);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_17$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "double")) {
				ZEPHIR_INIT_NVAR(_18$$13);
				ZVAL_LONG(_18$$13, 9);
				zephir_array_update_zval(&fieldTypes, columnName, &_18$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_19$$13);
				ZVAL_LONG(_19$$13, 32);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_19$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, columnName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "boolean")) {
				ZEPHIR_INIT_NVAR(_20$$14);
				ZVAL_LONG(_20$$14, 8);
				zephir_array_update_zval(&fieldTypes, columnName, &_20$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_21$$14);
				ZVAL_LONG(_21$$14, 5);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_21$$14, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "date")) {
				ZEPHIR_INIT_NVAR(_22$$15);
				ZVAL_LONG(_22$$15, 1);
				zephir_array_update_zval(&fieldTypes, columnName, &_22$$15, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_23$$15);
				ZVAL_LONG(_23$$15, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_23$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "datetime")) {
				ZEPHIR_INIT_NVAR(_24$$16);
				ZVAL_LONG(_24$$16, 4);
				zephir_array_update_zval(&fieldTypes, columnName, &_24$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_25$$16);
				ZVAL_LONG(_25$$16, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_25$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "timestamp")) {
				ZEPHIR_INIT_NVAR(_26$$17);
				ZVAL_LONG(_26$$17, 17);
				zephir_array_update_zval(&fieldTypes, columnName, &_26$$17, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_27$$17);
				ZVAL_LONG(_27$$17, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_27$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "text")) {
				ZEPHIR_INIT_NVAR(_28$$18);
				ZVAL_LONG(_28$$18, 6);
				zephir_array_update_zval(&fieldTypes, columnName, &_28$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_29$$18);
				ZVAL_LONG(_29$$18, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_29$$18, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "char")) {
				ZEPHIR_INIT_NVAR(_30$$19);
				ZVAL_LONG(_30$$19, 5);
				zephir_array_update_zval(&fieldTypes, columnName, &_30$$19, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_31$$19);
				ZVAL_LONG(_31$$19, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_31$$19, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "json")) {
				ZEPHIR_INIT_NVAR(_32$$20);
				ZVAL_LONG(_32$$20, 15);
				zephir_array_update_zval(&fieldTypes, columnName, &_32$$20, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_33$$20);
				ZVAL_LONG(_33$$20, 2);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_33$$20, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "tinyblob")) {
				ZEPHIR_INIT_NVAR(_34$$21);
				ZVAL_LONG(_34$$21, 10);
				zephir_array_update_zval(&fieldTypes, columnName, &_34$$21, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_35$$21);
				ZVAL_LONG(_35$$21, 3);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_35$$21, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "blob")) {
				ZEPHIR_INIT_NVAR(_36$$22);
				ZVAL_LONG(_36$$22, 11);
				zephir_array_update_zval(&fieldTypes, columnName, &_36$$22, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_37$$22);
				ZVAL_LONG(_37$$22, 3);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_37$$22, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "mediumblob")) {
				ZEPHIR_INIT_NVAR(_38$$23);
				ZVAL_LONG(_38$$23, 12);
				zephir_array_update_zval(&fieldTypes, columnName, &_38$$23, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_39$$23);
				ZVAL_LONG(_39$$23, 3);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_39$$23, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(feature, "longblob")) {
				ZEPHIR_INIT_NVAR(_40$$24);
				ZVAL_LONG(_40$$24, 13);
				zephir_array_update_zval(&fieldTypes, columnName, &_40$$24, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_41$$24);
				ZVAL_LONG(_41$$24, 3);
				zephir_array_update_zval(&fieldBindTypes, columnName, &_41$$24, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_42$$25);
			ZVAL_LONG(_42$$25, 2);
			zephir_array_update_zval(&fieldTypes, columnName, &_42$$25, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_43$$25);
			ZVAL_LONG(_43$$25, 2);
			zephir_array_update_zval(&fieldBindTypes, columnName, &_43$$25, PH_COPY | PH_SEPARATE);
		} while(0);

		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "Primary", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_44$$6, propAnnotations, "has", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (zephir_is_true(_44$$6)) {
			zephir_array_append(&primaryKeys, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 206);
		} else {
			zephir_array_append(&nonPrimaryKeys, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 208);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "Identity", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_45$$6, propAnnotations, "has", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (zephir_is_true(_45$$6)) {
			ZEPHIR_CPY_WRT(identityField, columnName);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "skip_on_insert", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_46$$6, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (zephir_is_true(_46$$6)) {
			zephir_array_append(&skipOnInsert, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 222);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "skip_on_update", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_47$$6, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (zephir_is_true(_47$$6)) {
			zephir_array_append(&skipOnUpdate, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 229);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "allow_empty_string", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_48$$6, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (zephir_is_true(_48$$6)) {
			zephir_array_append(&emptyStringValues, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 236);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "nullable", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_49$$6, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(_49$$6))) {
			zephir_array_append(&notNull, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 243);
		}
		ZEPHIR_INIT_NVAR(_9$$6);
		ZVAL_STRING(_9$$6, "default", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&defaultValue, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		_50$$6 = Z_TYPE_P(defaultValue) != IS_NULL;
		if (!(_50$$6)) {
			ZEPHIR_INIT_NVAR(_9$$6);
			ZVAL_STRING(_9$$6, "nullable", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_51$$6, columnAnnotation, "getnamedparameter", NULL, 0, _9$$6);
			zephir_check_temp_parameter(_9$$6);
			zephir_check_call_status();
			_50$$6 = zephir_is_true(_51$$6);
		}
		if (_50$$6) {
			zephir_array_update_zval(&defaultValues, columnName, &defaultValue, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&attributes, columnName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/annotations.zep", 254);
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
	zephir_array_update_long(&return_value, 10, &skipOnInsert, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 11, &skipOnUpdate, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
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
	zend_bool hasReversedColumn = 0, _10$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *annotations = NULL, *className = NULL, *reflection = NULL, *propertiesAnnotations = NULL, *property = NULL, *propAnnotations = NULL, *columnAnnotation = NULL, *columnName = NULL, *orderedColumnMap = NULL, *reversedColumnMap = NULL, *_0, **_7, *_1$$4, *_2$$4, *_3$$5, *_4$$5, *_8$$6 = NULL, *_9$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/mvc/model/metadata/strategy/annotations.zep", 286);
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
		zephir_throw_exception_debug(_1$$4, "phalcon/mvc/model/metadata/strategy/annotations.zep", 293 TSRMLS_CC);
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
		zephir_throw_exception_debug(_3$$5, "phalcon/mvc/model/metadata/strategy/annotations.zep", 301 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(orderedColumnMap);
	array_init(orderedColumnMap);
	ZEPHIR_INIT_VAR(reversedColumnMap);
	array_init(reversedColumnMap);
	hasReversedColumn = 0;
	zephir_is_iterable(propertiesAnnotations, &_6, &_5, 0, 0, "phalcon/mvc/model/metadata/strategy/annotations.zep", 339);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_forward_ex(_6, &_5)
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
		zephir_array_update_zval(&orderedColumnMap, columnName, &property, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&reversedColumnMap, property, &columnName, PH_COPY | PH_SEPARATE);
		_10$$6 = !hasReversedColumn;
		if (_10$$6) {
			_10$$6 = !ZEPHIR_IS_EQUAL(columnName, property);
		}
		if (_10$$6) {
			hasReversedColumn = 1;
		}
	}
	if (!(hasReversedColumn)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, ZEPHIR_GLOBAL(global_null));
		zephir_array_fast_append(return_value, ZEPHIR_GLOBAL(global_null));
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, orderedColumnMap);
	zephir_array_fast_append(return_value, reversedColumnMap);
	RETURN_MM();

}

