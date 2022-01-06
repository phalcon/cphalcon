
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Annotations)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Annotations, phalcon, mvc_model_metadata_strategy_annotations, phalcon_mvc_model_metadata_strategy_annotations_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_metadata_strategy_annotations_ce, 1, phalcon_mvc_model_metadata_strategy_strategyinterface_ce);
	return SUCCESS;
}

/**
 * Read the model's column map, this can't be inferred
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps)
{
	zend_string *_8;
	zend_ulong _7;
	zend_bool hasReversedColumn = 0, _11$$6, _14$$10;
	zval orderedColumnMap, reversedColumnMap;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *container, container_sub, __$null, annotations, className, reflection, propertiesAnnotations, property, propAnnotations, columnAnnotation, columnName, _0, *_5, _6, _1$$4, _2$$4, _3$$5, _4$$5, _9$$6, _10$$6, _12$$10, _13$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&propertiesAnnotations);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&propAnnotations);
	ZVAL_UNDEF(&columnAnnotation);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&orderedColumnMap);
	ZVAL_UNDEF(&reversedColumnMap);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &container);


	if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 32);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "annotations");
	ZEPHIR_CALL_METHOD(&annotations, container, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0);
	ZEPHIR_CALL_METHOD(&reflection, &annotations, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&reflection) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "No annotations were found in class ", &className);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 31, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 43);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, &reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&propertiesAnnotations)))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_SV(&_4$$5, "No properties with annotations were found in class ", &className);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 31, &_4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 54);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&orderedColumnMap);
	array_init(&orderedColumnMap);
	ZEPHIR_INIT_VAR(&reversedColumnMap);
	array_init(&reversedColumnMap);
	hasReversedColumn = 0;
	zephir_is_iterable(&propertiesAnnotations, 0, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 91);
	if (Z_TYPE_P(&propertiesAnnotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&propertiesAnnotations), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&property);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&property, _8);
			} else {
				ZVAL_LONG(&property, _7);
			}
			ZEPHIR_INIT_NVAR(&propAnnotations);
			ZVAL_COPY(&propAnnotations, _5);
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Column");
			ZEPHIR_CALL_METHOD(&_9$$6, &propAnnotations, "has", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_9$$6))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Column");
			ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_10$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "column");
			ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&columnName)) {
				ZEPHIR_CPY_WRT(&columnName, &property);
			}
			zephir_array_update_zval(&orderedColumnMap, &columnName, &property, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&reversedColumnMap, &property, &columnName, PH_COPY | PH_SEPARATE);
			_11$$6 = !hasReversedColumn;
			if (_11$$6) {
				_11$$6 = !ZEPHIR_IS_EQUAL(&columnName, &property);
			}
			if (_11$$6) {
				hasReversedColumn = 1;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &propertiesAnnotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, &propertiesAnnotations, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&propAnnotations, &propertiesAnnotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, "Column");
				ZEPHIR_CALL_METHOD(&_12$$10, &propAnnotations, "has", NULL, 0, &_13$$10);
				zephir_check_call_status();
				if (!(zephir_is_true(&_12$$10))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, "Column");
				ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_13$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, "column");
				ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_13$$10);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&columnName)) {
					ZEPHIR_CPY_WRT(&columnName, &property);
				}
				zephir_array_update_zval(&orderedColumnMap, &columnName, &property, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&reversedColumnMap, &property, &columnName, PH_COPY | PH_SEPARATE);
				_14$$10 = !hasReversedColumn;
				if (_14$$10) {
					_14$$10 = !ZEPHIR_IS_EQUAL(&columnName, &property);
				}
				if (_14$$10) {
					hasReversedColumn = 1;
				}
			ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&propAnnotations);
	ZEPHIR_INIT_NVAR(&property);
	if (!(hasReversedColumn)) {
		zephir_create_array(return_value, 2, 0);
		zephir_array_fast_append(return_value, &__$null);
		zephir_array_fast_append(return_value, &__$null);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &orderedColumnMap);
	zephir_array_fast_append(return_value, &reversedColumnMap);
	RETURN_MM();
}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData)
{
	zend_bool _71$$6, _135$$44;
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *container, container_sub, __$true, annotations, className, reflection, propertiesAnnotations, property, propAnnotations, columnAnnotation, columnName, feature, fieldTypes, fieldBindTypes, numericTyped, primaryKeys, nonPrimaryKeys, identityField, notNull, attributes, defaultValues, defaultValue, emptyStringValues, skipOnInsert, skipOnUpdate, _0, *_5, _6, _1$$4, _2$$4, _3$$5, _4$$5, _9$$6, _10$$6, _65$$6, _66$$6, _67$$6, _68$$6, _69$$6, _70$$6, _72$$6, _11$$9, _12$$9, _13$$10, _14$$10, _15$$11, _16$$11, _17$$12, _18$$12, _19$$13, _20$$13, _21$$14, _22$$14, _23$$15, _24$$15, _25$$16, _26$$16, _27$$17, _28$$17, _29$$18, _30$$18, _31$$19, _32$$19, _33$$20, _34$$20, _35$$21, _36$$21, _37$$22, _38$$22, _39$$23, _40$$23, _41$$24, _42$$24, _43$$25, _44$$25, _45$$26, _46$$26, _47$$27, _48$$27, _49$$28, _50$$28, _51$$29, _52$$29, _53$$30, _54$$30, _55$$31, _56$$31, _57$$32, _58$$32, _59$$33, _60$$33, _61$$34, _62$$34, _63$$35, _64$$35, _73$$44, _74$$44, _129$$44, _130$$44, _131$$44, _132$$44, _133$$44, _134$$44, _136$$44, _75$$47, _76$$47, _77$$48, _78$$48, _79$$49, _80$$49, _81$$50, _82$$50, _83$$51, _84$$51, _85$$52, _86$$52, _87$$53, _88$$53, _89$$54, _90$$54, _91$$55, _92$$55, _93$$56, _94$$56, _95$$57, _96$$57, _97$$58, _98$$58, _99$$59, _100$$59, _101$$60, _102$$60, _103$$61, _104$$61, _105$$62, _106$$62, _107$$63, _108$$63, _109$$64, _110$$64, _111$$65, _112$$65, _113$$66, _114$$66, _115$$67, _116$$67, _117$$68, _118$$68, _119$$69, _120$$69, _121$$70, _122$$70, _123$$71, _124$$71, _125$$72, _126$$72, _127$$73, _128$$73;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&propertiesAnnotations);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&propAnnotations);
	ZVAL_UNDEF(&columnAnnotation);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&feature);
	ZVAL_UNDEF(&fieldTypes);
	ZVAL_UNDEF(&fieldBindTypes);
	ZVAL_UNDEF(&numericTyped);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&nonPrimaryKeys);
	ZVAL_UNDEF(&identityField);
	ZVAL_UNDEF(&notNull);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&emptyStringValues);
	ZVAL_UNDEF(&skipOnInsert);
	ZVAL_UNDEF(&skipOnUpdate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_65$$6);
	ZVAL_UNDEF(&_66$$6);
	ZVAL_UNDEF(&_67$$6);
	ZVAL_UNDEF(&_68$$6);
	ZVAL_UNDEF(&_69$$6);
	ZVAL_UNDEF(&_70$$6);
	ZVAL_UNDEF(&_72$$6);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_40$$23);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_42$$24);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_44$$25);
	ZVAL_UNDEF(&_45$$26);
	ZVAL_UNDEF(&_46$$26);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_49$$28);
	ZVAL_UNDEF(&_50$$28);
	ZVAL_UNDEF(&_51$$29);
	ZVAL_UNDEF(&_52$$29);
	ZVAL_UNDEF(&_53$$30);
	ZVAL_UNDEF(&_54$$30);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_56$$31);
	ZVAL_UNDEF(&_57$$32);
	ZVAL_UNDEF(&_58$$32);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_60$$33);
	ZVAL_UNDEF(&_61$$34);
	ZVAL_UNDEF(&_62$$34);
	ZVAL_UNDEF(&_63$$35);
	ZVAL_UNDEF(&_64$$35);
	ZVAL_UNDEF(&_73$$44);
	ZVAL_UNDEF(&_74$$44);
	ZVAL_UNDEF(&_129$$44);
	ZVAL_UNDEF(&_130$$44);
	ZVAL_UNDEF(&_131$$44);
	ZVAL_UNDEF(&_132$$44);
	ZVAL_UNDEF(&_133$$44);
	ZVAL_UNDEF(&_134$$44);
	ZVAL_UNDEF(&_136$$44);
	ZVAL_UNDEF(&_75$$47);
	ZVAL_UNDEF(&_76$$47);
	ZVAL_UNDEF(&_77$$48);
	ZVAL_UNDEF(&_78$$48);
	ZVAL_UNDEF(&_79$$49);
	ZVAL_UNDEF(&_80$$49);
	ZVAL_UNDEF(&_81$$50);
	ZVAL_UNDEF(&_82$$50);
	ZVAL_UNDEF(&_83$$51);
	ZVAL_UNDEF(&_84$$51);
	ZVAL_UNDEF(&_85$$52);
	ZVAL_UNDEF(&_86$$52);
	ZVAL_UNDEF(&_87$$53);
	ZVAL_UNDEF(&_88$$53);
	ZVAL_UNDEF(&_89$$54);
	ZVAL_UNDEF(&_90$$54);
	ZVAL_UNDEF(&_91$$55);
	ZVAL_UNDEF(&_92$$55);
	ZVAL_UNDEF(&_93$$56);
	ZVAL_UNDEF(&_94$$56);
	ZVAL_UNDEF(&_95$$57);
	ZVAL_UNDEF(&_96$$57);
	ZVAL_UNDEF(&_97$$58);
	ZVAL_UNDEF(&_98$$58);
	ZVAL_UNDEF(&_99$$59);
	ZVAL_UNDEF(&_100$$59);
	ZVAL_UNDEF(&_101$$60);
	ZVAL_UNDEF(&_102$$60);
	ZVAL_UNDEF(&_103$$61);
	ZVAL_UNDEF(&_104$$61);
	ZVAL_UNDEF(&_105$$62);
	ZVAL_UNDEF(&_106$$62);
	ZVAL_UNDEF(&_107$$63);
	ZVAL_UNDEF(&_108$$63);
	ZVAL_UNDEF(&_109$$64);
	ZVAL_UNDEF(&_110$$64);
	ZVAL_UNDEF(&_111$$65);
	ZVAL_UNDEF(&_112$$65);
	ZVAL_UNDEF(&_113$$66);
	ZVAL_UNDEF(&_114$$66);
	ZVAL_UNDEF(&_115$$67);
	ZVAL_UNDEF(&_116$$67);
	ZVAL_UNDEF(&_117$$68);
	ZVAL_UNDEF(&_118$$68);
	ZVAL_UNDEF(&_119$$69);
	ZVAL_UNDEF(&_120$$69);
	ZVAL_UNDEF(&_121$$70);
	ZVAL_UNDEF(&_122$$70);
	ZVAL_UNDEF(&_123$$71);
	ZVAL_UNDEF(&_124$$71);
	ZVAL_UNDEF(&_125$$72);
	ZVAL_UNDEF(&_126$$72);
	ZVAL_UNDEF(&_127$$73);
	ZVAL_UNDEF(&_128$$73);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &container);


	if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid", "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 113);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "annotations");
	ZEPHIR_CALL_METHOD(&annotations, container, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0);
	ZEPHIR_CALL_METHOD(&reflection, &annotations, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&reflection) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "No annotations were found in class ", &className);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 31, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 124);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, &reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&propertiesAnnotations)))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_SV(&_4$$5, "No properties with annotations were found in class ", &className);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 31, &_4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 135);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&attributes);
	array_init(&attributes);
	ZEPHIR_INIT_VAR(&primaryKeys);
	array_init(&primaryKeys);
	ZEPHIR_INIT_VAR(&nonPrimaryKeys);
	array_init(&nonPrimaryKeys);
	ZEPHIR_INIT_VAR(&numericTyped);
	array_init(&numericTyped);
	ZEPHIR_INIT_VAR(&notNull);
	array_init(&notNull);
	ZEPHIR_INIT_VAR(&fieldTypes);
	array_init(&fieldTypes);
	ZEPHIR_INIT_VAR(&fieldBindTypes);
	array_init(&fieldBindTypes);
	ZEPHIR_INIT_VAR(&identityField);
	ZVAL_BOOL(&identityField, 0);
	ZEPHIR_INIT_VAR(&skipOnInsert);
	array_init(&skipOnInsert);
	ZEPHIR_INIT_VAR(&skipOnUpdate);
	array_init(&skipOnUpdate);
	ZEPHIR_INIT_VAR(&defaultValues);
	array_init(&defaultValues);
	ZEPHIR_INIT_VAR(&emptyStringValues);
	array_init(&emptyStringValues);
	zephir_is_iterable(&propertiesAnnotations, 0, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 392);
	if (Z_TYPE_P(&propertiesAnnotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&propertiesAnnotations), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&property);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&property, _8);
			} else {
				ZVAL_LONG(&property, _7);
			}
			ZEPHIR_INIT_NVAR(&propAnnotations);
			ZVAL_COPY(&propAnnotations, _5);
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Column");
			ZEPHIR_CALL_METHOD(&_9$$6, &propAnnotations, "has", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_9$$6))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Column");
			ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_10$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "column");
			ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&columnName)) {
				ZEPHIR_CPY_WRT(&columnName, &property);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "type");
			ZEPHIR_CALL_METHOD(&feature, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			do {
				if (ZEPHIR_IS_STRING(&feature, "biginteger")) {
					ZEPHIR_INIT_NVAR(&_11$$9);
					ZVAL_LONG(&_11$$9, 14);
					zephir_array_update_zval(&fieldTypes, &columnName, &_11$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_12$$9);
					ZVAL_LONG(&_12$$9, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_12$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "bit")) {
					ZEPHIR_INIT_NVAR(&_13$$10);
					ZVAL_LONG(&_13$$10, 19);
					zephir_array_update_zval(&fieldTypes, &columnName, &_13$$10, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_14$$10);
					ZVAL_LONG(&_14$$10, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_14$$10, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "blob")) {
					ZEPHIR_INIT_NVAR(&_15$$11);
					ZVAL_LONG(&_15$$11, 11);
					zephir_array_update_zval(&fieldTypes, &columnName, &_15$$11, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_16$$11);
					ZVAL_LONG(&_16$$11, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_16$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "boolean")) {
					ZEPHIR_INIT_NVAR(&_17$$12);
					ZVAL_LONG(&_17$$12, 8);
					zephir_array_update_zval(&fieldTypes, &columnName, &_17$$12, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_18$$12);
					ZVAL_LONG(&_18$$12, 5);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_18$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "char")) {
					ZEPHIR_INIT_NVAR(&_19$$13);
					ZVAL_LONG(&_19$$13, 5);
					zephir_array_update_zval(&fieldTypes, &columnName, &_19$$13, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_20$$13);
					ZVAL_LONG(&_20$$13, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_20$$13, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "date")) {
					ZEPHIR_INIT_NVAR(&_21$$14);
					ZVAL_LONG(&_21$$14, 1);
					zephir_array_update_zval(&fieldTypes, &columnName, &_21$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_22$$14);
					ZVAL_LONG(&_22$$14, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_22$$14, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "datetime")) {
					ZEPHIR_INIT_NVAR(&_23$$15);
					ZVAL_LONG(&_23$$15, 4);
					zephir_array_update_zval(&fieldTypes, &columnName, &_23$$15, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_24$$15);
					ZVAL_LONG(&_24$$15, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_24$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "decimal")) {
					ZEPHIR_INIT_NVAR(&_25$$16);
					ZVAL_LONG(&_25$$16, 3);
					zephir_array_update_zval(&fieldTypes, &columnName, &_25$$16, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_26$$16);
					ZVAL_LONG(&_26$$16, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_26$$16, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "double")) {
					ZEPHIR_INIT_NVAR(&_27$$17);
					ZVAL_LONG(&_27$$17, 9);
					zephir_array_update_zval(&fieldTypes, &columnName, &_27$$17, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_28$$17);
					ZVAL_LONG(&_28$$17, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_28$$17, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "enum")) {
					ZEPHIR_INIT_NVAR(&_29$$18);
					ZVAL_LONG(&_29$$18, 18);
					zephir_array_update_zval(&fieldTypes, &columnName, &_29$$18, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_30$$18);
					ZVAL_LONG(&_30$$18, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_30$$18, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "float")) {
					ZEPHIR_INIT_NVAR(&_31$$19);
					ZVAL_LONG(&_31$$19, 7);
					zephir_array_update_zval(&fieldTypes, &columnName, &_31$$19, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_32$$19);
					ZVAL_LONG(&_32$$19, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_32$$19, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "integer")) {
					ZEPHIR_INIT_NVAR(&_33$$20);
					ZVAL_LONG(&_33$$20, 0);
					zephir_array_update_zval(&fieldTypes, &columnName, &_33$$20, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_34$$20);
					ZVAL_LONG(&_34$$20, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_34$$20, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "json")) {
					ZEPHIR_INIT_NVAR(&_35$$21);
					ZVAL_LONG(&_35$$21, 15);
					zephir_array_update_zval(&fieldTypes, &columnName, &_35$$21, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_36$$21);
					ZVAL_LONG(&_36$$21, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_36$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "jsonb")) {
					ZEPHIR_INIT_NVAR(&_37$$22);
					ZVAL_LONG(&_37$$22, 16);
					zephir_array_update_zval(&fieldTypes, &columnName, &_37$$22, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_38$$22);
					ZVAL_LONG(&_38$$22, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_38$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "longblob")) {
					ZEPHIR_INIT_NVAR(&_39$$23);
					ZVAL_LONG(&_39$$23, 13);
					zephir_array_update_zval(&fieldTypes, &columnName, &_39$$23, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_40$$23);
					ZVAL_LONG(&_40$$23, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_40$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "longtext")) {
					ZEPHIR_INIT_NVAR(&_41$$24);
					ZVAL_LONG(&_41$$24, 24);
					zephir_array_update_zval(&fieldTypes, &columnName, &_41$$24, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_42$$24);
					ZVAL_LONG(&_42$$24, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_42$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "mediumblob")) {
					ZEPHIR_INIT_NVAR(&_43$$25);
					ZVAL_LONG(&_43$$25, 12);
					zephir_array_update_zval(&fieldTypes, &columnName, &_43$$25, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_44$$25);
					ZVAL_LONG(&_44$$25, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_44$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "mediumint")) {
					ZEPHIR_INIT_NVAR(&_45$$26);
					ZVAL_LONG(&_45$$26, 21);
					zephir_array_update_zval(&fieldTypes, &columnName, &_45$$26, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_46$$26);
					ZVAL_LONG(&_46$$26, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_46$$26, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "mediumtext")) {
					ZEPHIR_INIT_NVAR(&_47$$27);
					ZVAL_LONG(&_47$$27, 23);
					zephir_array_update_zval(&fieldTypes, &columnName, &_47$$27, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_48$$27);
					ZVAL_LONG(&_48$$27, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_48$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "smallint")) {
					ZEPHIR_INIT_NVAR(&_49$$28);
					ZVAL_LONG(&_49$$28, 22);
					zephir_array_update_zval(&fieldTypes, &columnName, &_49$$28, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_50$$28);
					ZVAL_LONG(&_50$$28, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_50$$28, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "text")) {
					ZEPHIR_INIT_NVAR(&_51$$29);
					ZVAL_LONG(&_51$$29, 6);
					zephir_array_update_zval(&fieldTypes, &columnName, &_51$$29, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_52$$29);
					ZVAL_LONG(&_52$$29, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_52$$29, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "time")) {
					ZEPHIR_INIT_NVAR(&_53$$30);
					ZVAL_LONG(&_53$$30, 20);
					zephir_array_update_zval(&fieldTypes, &columnName, &_53$$30, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_54$$30);
					ZVAL_LONG(&_54$$30, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_54$$30, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "timestamp")) {
					ZEPHIR_INIT_NVAR(&_55$$31);
					ZVAL_LONG(&_55$$31, 17);
					zephir_array_update_zval(&fieldTypes, &columnName, &_55$$31, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_56$$31);
					ZVAL_LONG(&_56$$31, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_56$$31, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "tinyblob")) {
					ZEPHIR_INIT_NVAR(&_57$$32);
					ZVAL_LONG(&_57$$32, 10);
					zephir_array_update_zval(&fieldTypes, &columnName, &_57$$32, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_58$$32);
					ZVAL_LONG(&_58$$32, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_58$$32, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "tinyint")) {
					ZEPHIR_INIT_NVAR(&_59$$33);
					ZVAL_LONG(&_59$$33, 26);
					zephir_array_update_zval(&fieldTypes, &columnName, &_59$$33, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_60$$33);
					ZVAL_LONG(&_60$$33, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_60$$33, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "tinytext")) {
					ZEPHIR_INIT_NVAR(&_61$$34);
					ZVAL_LONG(&_61$$34, 25);
					zephir_array_update_zval(&fieldTypes, &columnName, &_61$$34, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_62$$34);
					ZVAL_LONG(&_62$$34, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_62$$34, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_63$$35);
				ZVAL_LONG(&_63$$35, 2);
				zephir_array_update_zval(&fieldTypes, &columnName, &_63$$35, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_64$$35);
				ZVAL_LONG(&_64$$35, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_64$$35, PH_COPY | PH_SEPARATE);
			} while(0);

			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Primary");
			ZEPHIR_CALL_METHOD(&_65$$6, &propAnnotations, "has", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_65$$6)) {
				zephir_array_append(&primaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 336);
			} else {
				zephir_array_append(&nonPrimaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 338);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "Identity");
			ZEPHIR_CALL_METHOD(&_66$$6, &propAnnotations, "has", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_66$$6)) {
				ZEPHIR_CPY_WRT(&identityField, &columnName);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "skip_on_insert");
			ZEPHIR_CALL_METHOD(&_67$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_67$$6)) {
				zephir_array_append(&skipOnInsert, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 353);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "skip_on_update");
			ZEPHIR_CALL_METHOD(&_68$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_68$$6)) {
				zephir_array_append(&skipOnUpdate, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 360);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "allow_empty_string");
			ZEPHIR_CALL_METHOD(&_69$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_69$$6)) {
				zephir_array_append(&emptyStringValues, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 367);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "nullable");
			ZEPHIR_CALL_METHOD(&_70$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_70$$6))) {
				zephir_array_append(&notNull, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 374);
			}
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "default");
			ZEPHIR_CALL_METHOD(&defaultValue, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
			zephir_check_call_status();
			_71$$6 = Z_TYPE_P(&defaultValue) != IS_NULL;
			if (!(_71$$6)) {
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZVAL_STRING(&_10$$6, "nullable");
				ZEPHIR_CALL_METHOD(&_72$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_10$$6);
				zephir_check_call_status();
				_71$$6 = zephir_is_true(&_72$$6);
			}
			if (_71$$6) {
				zephir_array_update_zval(&defaultValues, &columnName, &defaultValue, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&attributes, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 386);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &propertiesAnnotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, &propertiesAnnotations, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&propAnnotations, &propertiesAnnotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "Column");
				ZEPHIR_CALL_METHOD(&_73$$44, &propAnnotations, "has", NULL, 0, &_74$$44);
				zephir_check_call_status();
				if (!(zephir_is_true(&_73$$44))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "Column");
				ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_74$$44);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "column");
				ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_74$$44);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&columnName)) {
					ZEPHIR_CPY_WRT(&columnName, &property);
				}
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "type");
				ZEPHIR_CALL_METHOD(&feature, &columnAnnotation, "getnamedparameter", NULL, 0, &_74$$44);
				zephir_check_call_status();
				do {
					if (ZEPHIR_IS_STRING(&feature, "biginteger")) {
						ZEPHIR_INIT_NVAR(&_75$$47);
						ZVAL_LONG(&_75$$47, 14);
						zephir_array_update_zval(&fieldTypes, &columnName, &_75$$47, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_76$$47);
						ZVAL_LONG(&_76$$47, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_76$$47, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "bit")) {
						ZEPHIR_INIT_NVAR(&_77$$48);
						ZVAL_LONG(&_77$$48, 19);
						zephir_array_update_zval(&fieldTypes, &columnName, &_77$$48, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_78$$48);
						ZVAL_LONG(&_78$$48, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_78$$48, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "blob")) {
						ZEPHIR_INIT_NVAR(&_79$$49);
						ZVAL_LONG(&_79$$49, 11);
						zephir_array_update_zval(&fieldTypes, &columnName, &_79$$49, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_80$$49);
						ZVAL_LONG(&_80$$49, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_80$$49, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "boolean")) {
						ZEPHIR_INIT_NVAR(&_81$$50);
						ZVAL_LONG(&_81$$50, 8);
						zephir_array_update_zval(&fieldTypes, &columnName, &_81$$50, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$50);
						ZVAL_LONG(&_82$$50, 5);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_82$$50, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "char")) {
						ZEPHIR_INIT_NVAR(&_83$$51);
						ZVAL_LONG(&_83$$51, 5);
						zephir_array_update_zval(&fieldTypes, &columnName, &_83$$51, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_84$$51);
						ZVAL_LONG(&_84$$51, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_84$$51, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "date")) {
						ZEPHIR_INIT_NVAR(&_85$$52);
						ZVAL_LONG(&_85$$52, 1);
						zephir_array_update_zval(&fieldTypes, &columnName, &_85$$52, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_86$$52);
						ZVAL_LONG(&_86$$52, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_86$$52, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "datetime")) {
						ZEPHIR_INIT_NVAR(&_87$$53);
						ZVAL_LONG(&_87$$53, 4);
						zephir_array_update_zval(&fieldTypes, &columnName, &_87$$53, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_88$$53);
						ZVAL_LONG(&_88$$53, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_88$$53, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "decimal")) {
						ZEPHIR_INIT_NVAR(&_89$$54);
						ZVAL_LONG(&_89$$54, 3);
						zephir_array_update_zval(&fieldTypes, &columnName, &_89$$54, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_90$$54);
						ZVAL_LONG(&_90$$54, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_90$$54, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "double")) {
						ZEPHIR_INIT_NVAR(&_91$$55);
						ZVAL_LONG(&_91$$55, 9);
						zephir_array_update_zval(&fieldTypes, &columnName, &_91$$55, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_92$$55);
						ZVAL_LONG(&_92$$55, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_92$$55, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "enum")) {
						ZEPHIR_INIT_NVAR(&_93$$56);
						ZVAL_LONG(&_93$$56, 18);
						zephir_array_update_zval(&fieldTypes, &columnName, &_93$$56, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_94$$56);
						ZVAL_LONG(&_94$$56, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_94$$56, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "float")) {
						ZEPHIR_INIT_NVAR(&_95$$57);
						ZVAL_LONG(&_95$$57, 7);
						zephir_array_update_zval(&fieldTypes, &columnName, &_95$$57, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_96$$57);
						ZVAL_LONG(&_96$$57, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_96$$57, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "integer")) {
						ZEPHIR_INIT_NVAR(&_97$$58);
						ZVAL_LONG(&_97$$58, 0);
						zephir_array_update_zval(&fieldTypes, &columnName, &_97$$58, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_98$$58);
						ZVAL_LONG(&_98$$58, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_98$$58, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "json")) {
						ZEPHIR_INIT_NVAR(&_99$$59);
						ZVAL_LONG(&_99$$59, 15);
						zephir_array_update_zval(&fieldTypes, &columnName, &_99$$59, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_100$$59);
						ZVAL_LONG(&_100$$59, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_100$$59, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "jsonb")) {
						ZEPHIR_INIT_NVAR(&_101$$60);
						ZVAL_LONG(&_101$$60, 16);
						zephir_array_update_zval(&fieldTypes, &columnName, &_101$$60, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_102$$60);
						ZVAL_LONG(&_102$$60, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_102$$60, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "longblob")) {
						ZEPHIR_INIT_NVAR(&_103$$61);
						ZVAL_LONG(&_103$$61, 13);
						zephir_array_update_zval(&fieldTypes, &columnName, &_103$$61, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_104$$61);
						ZVAL_LONG(&_104$$61, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_104$$61, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "longtext")) {
						ZEPHIR_INIT_NVAR(&_105$$62);
						ZVAL_LONG(&_105$$62, 24);
						zephir_array_update_zval(&fieldTypes, &columnName, &_105$$62, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_106$$62);
						ZVAL_LONG(&_106$$62, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_106$$62, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "mediumblob")) {
						ZEPHIR_INIT_NVAR(&_107$$63);
						ZVAL_LONG(&_107$$63, 12);
						zephir_array_update_zval(&fieldTypes, &columnName, &_107$$63, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_108$$63);
						ZVAL_LONG(&_108$$63, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_108$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "mediumint")) {
						ZEPHIR_INIT_NVAR(&_109$$64);
						ZVAL_LONG(&_109$$64, 21);
						zephir_array_update_zval(&fieldTypes, &columnName, &_109$$64, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_110$$64);
						ZVAL_LONG(&_110$$64, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_110$$64, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "mediumtext")) {
						ZEPHIR_INIT_NVAR(&_111$$65);
						ZVAL_LONG(&_111$$65, 23);
						zephir_array_update_zval(&fieldTypes, &columnName, &_111$$65, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_112$$65);
						ZVAL_LONG(&_112$$65, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_112$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "smallint")) {
						ZEPHIR_INIT_NVAR(&_113$$66);
						ZVAL_LONG(&_113$$66, 22);
						zephir_array_update_zval(&fieldTypes, &columnName, &_113$$66, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_114$$66);
						ZVAL_LONG(&_114$$66, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_114$$66, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "text")) {
						ZEPHIR_INIT_NVAR(&_115$$67);
						ZVAL_LONG(&_115$$67, 6);
						zephir_array_update_zval(&fieldTypes, &columnName, &_115$$67, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_116$$67);
						ZVAL_LONG(&_116$$67, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_116$$67, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "time")) {
						ZEPHIR_INIT_NVAR(&_117$$68);
						ZVAL_LONG(&_117$$68, 20);
						zephir_array_update_zval(&fieldTypes, &columnName, &_117$$68, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_118$$68);
						ZVAL_LONG(&_118$$68, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_118$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "timestamp")) {
						ZEPHIR_INIT_NVAR(&_119$$69);
						ZVAL_LONG(&_119$$69, 17);
						zephir_array_update_zval(&fieldTypes, &columnName, &_119$$69, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_120$$69);
						ZVAL_LONG(&_120$$69, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_120$$69, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "tinyblob")) {
						ZEPHIR_INIT_NVAR(&_121$$70);
						ZVAL_LONG(&_121$$70, 10);
						zephir_array_update_zval(&fieldTypes, &columnName, &_121$$70, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_122$$70);
						ZVAL_LONG(&_122$$70, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_122$$70, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "tinyint")) {
						ZEPHIR_INIT_NVAR(&_123$$71);
						ZVAL_LONG(&_123$$71, 26);
						zephir_array_update_zval(&fieldTypes, &columnName, &_123$$71, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_124$$71);
						ZVAL_LONG(&_124$$71, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_124$$71, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "tinytext")) {
						ZEPHIR_INIT_NVAR(&_125$$72);
						ZVAL_LONG(&_125$$72, 25);
						zephir_array_update_zval(&fieldTypes, &columnName, &_125$$72, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_126$$72);
						ZVAL_LONG(&_126$$72, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_126$$72, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_127$$73);
					ZVAL_LONG(&_127$$73, 2);
					zephir_array_update_zval(&fieldTypes, &columnName, &_127$$73, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_128$$73);
					ZVAL_LONG(&_128$$73, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_128$$73, PH_COPY | PH_SEPARATE);
				} while(0);

				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "Primary");
				ZEPHIR_CALL_METHOD(&_129$$44, &propAnnotations, "has", NULL, 0, &_74$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_129$$44)) {
					zephir_array_append(&primaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 336);
				} else {
					zephir_array_append(&nonPrimaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 338);
				}
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "Identity");
				ZEPHIR_CALL_METHOD(&_130$$44, &propAnnotations, "has", NULL, 0, &_74$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_130$$44)) {
					ZEPHIR_CPY_WRT(&identityField, &columnName);
				}
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "skip_on_insert");
				ZEPHIR_CALL_METHOD(&_131$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_74$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_131$$44)) {
					zephir_array_append(&skipOnInsert, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 353);
				}
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "skip_on_update");
				ZEPHIR_CALL_METHOD(&_132$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_74$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_132$$44)) {
					zephir_array_append(&skipOnUpdate, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 360);
				}
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "allow_empty_string");
				ZEPHIR_CALL_METHOD(&_133$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_74$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_133$$44)) {
					zephir_array_append(&emptyStringValues, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 367);
				}
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "nullable");
				ZEPHIR_CALL_METHOD(&_134$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_74$$44);
				zephir_check_call_status();
				if (!(zephir_is_true(&_134$$44))) {
					zephir_array_append(&notNull, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 374);
				}
				ZEPHIR_INIT_NVAR(&_74$$44);
				ZVAL_STRING(&_74$$44, "default");
				ZEPHIR_CALL_METHOD(&defaultValue, &columnAnnotation, "getnamedparameter", NULL, 0, &_74$$44);
				zephir_check_call_status();
				_135$$44 = Z_TYPE_P(&defaultValue) != IS_NULL;
				if (!(_135$$44)) {
					ZEPHIR_INIT_NVAR(&_74$$44);
					ZVAL_STRING(&_74$$44, "nullable");
					ZEPHIR_CALL_METHOD(&_136$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_74$$44);
					zephir_check_call_status();
					_135$$44 = zephir_is_true(&_136$$44);
				}
				if (_135$$44) {
					zephir_array_update_zval(&defaultValues, &columnName, &defaultValue, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&attributes, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 386);
			ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&propAnnotations);
	ZEPHIR_INIT_NVAR(&property);
	zephir_create_array(return_value, 12, 0);
	zephir_array_update_long(return_value, 0, &attributes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 1, &primaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 2, &nonPrimaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 3, &notNull, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 4, &fieldTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 5, &numericTyped, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 8, &identityField, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 9, &fieldBindTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 10, &skipOnInsert, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 11, &skipOnUpdate, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 12, &defaultValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 13, &emptyStringValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	RETURN_MM();
}

