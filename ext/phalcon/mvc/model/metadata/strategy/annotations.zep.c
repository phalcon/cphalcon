
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
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
	zend_string *_7;
	zend_ulong _6;
	zend_bool hasReversedColumn = 0, _12, _10$$6, _15$$10;
	zval orderedColumnMap, reversedColumnMap;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *container, container_sub, __$null, annotations, className, reflection, propertiesAnnotations, property, propAnnotations, columnAnnotation, columnName, _1, *_4, *_5, _11, _0$$3, _2$$4, _3$$5, _8$$6, _9$$6, _13$$10, _14$$10;

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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&orderedColumnMap);
	ZVAL_UNDEF(&reversedColumnMap);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &model, &container);
	if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_metadata_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 34);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "annotations");
	ZEPHIR_CALL_METHOD(&annotations, container, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0);
	ZEPHIR_CALL_METHOD(&reflection, &annotations, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&reflection) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_metadata_exceptions_noannotationsforclass_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0, &className);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 43);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, &reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&propertiesAnnotations))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_metadata_exceptions_nopropertyannotationsforclass_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0, &className);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 52);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&orderedColumnMap);
	array_init(&orderedColumnMap);
	ZEPHIR_INIT_VAR(&reversedColumnMap);
	array_init(&reversedColumnMap);
	hasReversedColumn = 0;
	if (Z_TYPE_P(&propertiesAnnotations) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_string_to_char_array(&_1, &propertiesAnnotations);
		_4 = &_1;
	} else {
		_4 = &propertiesAnnotations;
	}
	zephir_is_iterable(_4, 0, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 89);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&property);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&property, _7);
			} else {
				ZVAL_LONG(&property, _6);
			}
			ZEPHIR_INIT_NVAR(&propAnnotations);
			ZVAL_COPY(&propAnnotations, _5);
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "Column");
			ZEPHIR_CALL_METHOD(&_8$$6, &propAnnotations, "has", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_8$$6))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "Column");
			ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_9$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "column");
			ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&columnName)) {
				ZEPHIR_CPY_WRT(&columnName, &property);
			}
			zephir_array_update_zval(&orderedColumnMap, &columnName, &property, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&reversedColumnMap, &property, &columnName, PH_COPY | PH_SEPARATE);
			_10$$6 = !hasReversedColumn;
			if (_10$$6) {
				_10$$6 = !ZEPHIR_IS_EQUAL(&columnName, &property);
			}
			if (_10$$6) {
				hasReversedColumn = 1;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, _4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&propAnnotations, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_STRING(&_14$$10, "Column");
				ZEPHIR_CALL_METHOD(&_13$$10, &propAnnotations, "has", NULL, 0, &_14$$10);
				zephir_check_call_status();
				if (!(zephir_is_true(&_13$$10))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_STRING(&_14$$10, "Column");
				ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_14$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_STRING(&_14$$10, "column");
				ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_14$$10);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&columnName)) {
					ZEPHIR_CPY_WRT(&columnName, &property);
				}
				zephir_array_update_zval(&orderedColumnMap, &columnName, &property, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&reversedColumnMap, &property, &columnName, PH_COPY | PH_SEPARATE);
				_15$$10 = !hasReversedColumn;
				if (_15$$10) {
					_15$$10 = !ZEPHIR_IS_EQUAL(&columnName, &property);
				}
				if (_15$$10) {
					hasReversedColumn = 1;
				}
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
	zend_bool _73, _70$$6, _136$$44;
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *container, container_sub, __$true, annotations, className, reflection, propertiesAnnotations, property, propAnnotations, columnAnnotation, columnName, feature, fieldTypes, fieldBindTypes, numericTyped, primaryKeys, nonPrimaryKeys, identityField, notNull, attributes, defaultValues, defaultValue, emptyStringValues, skipOnInsert, skipOnUpdate, _1, *_4, *_5, _72, _0$$3, _2$$4, _3$$5, _8$$6, _9$$6, _64$$6, _65$$6, _66$$6, _67$$6, _68$$6, _69$$6, _71$$6, _10$$9, _11$$9, _12$$10, _13$$10, _14$$11, _15$$11, _16$$12, _17$$12, _18$$13, _19$$13, _20$$14, _21$$14, _22$$15, _23$$15, _24$$16, _25$$16, _26$$17, _27$$17, _28$$18, _29$$18, _30$$19, _31$$19, _32$$20, _33$$20, _34$$21, _35$$21, _36$$22, _37$$22, _38$$23, _39$$23, _40$$24, _41$$24, _42$$25, _43$$25, _44$$26, _45$$26, _46$$27, _47$$27, _48$$28, _49$$28, _50$$29, _51$$29, _52$$30, _53$$30, _54$$31, _55$$31, _56$$32, _57$$32, _58$$33, _59$$33, _60$$34, _61$$34, _62$$35, _63$$35, _74$$44, _75$$44, _130$$44, _131$$44, _132$$44, _133$$44, _134$$44, _135$$44, _137$$44, _76$$47, _77$$47, _78$$48, _79$$48, _80$$49, _81$$49, _82$$50, _83$$50, _84$$51, _85$$51, _86$$52, _87$$52, _88$$53, _89$$53, _90$$54, _91$$54, _92$$55, _93$$55, _94$$56, _95$$56, _96$$57, _97$$57, _98$$58, _99$$58, _100$$59, _101$$59, _102$$60, _103$$60, _104$$61, _105$$61, _106$$62, _107$$62, _108$$63, _109$$63, _110$$64, _111$$64, _112$$65, _113$$65, _114$$66, _115$$66, _116$$67, _117$$67, _118$$68, _119$$68, _120$$69, _121$$69, _122$$70, _123$$70, _124$$71, _125$$71, _126$$72, _127$$72, _128$$73, _129$$73;

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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_64$$6);
	ZVAL_UNDEF(&_65$$6);
	ZVAL_UNDEF(&_66$$6);
	ZVAL_UNDEF(&_67$$6);
	ZVAL_UNDEF(&_68$$6);
	ZVAL_UNDEF(&_69$$6);
	ZVAL_UNDEF(&_71$$6);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_42$$25);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_44$$26);
	ZVAL_UNDEF(&_45$$26);
	ZVAL_UNDEF(&_46$$27);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_48$$28);
	ZVAL_UNDEF(&_49$$28);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_51$$29);
	ZVAL_UNDEF(&_52$$30);
	ZVAL_UNDEF(&_53$$30);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_56$$32);
	ZVAL_UNDEF(&_57$$32);
	ZVAL_UNDEF(&_58$$33);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_60$$34);
	ZVAL_UNDEF(&_61$$34);
	ZVAL_UNDEF(&_62$$35);
	ZVAL_UNDEF(&_63$$35);
	ZVAL_UNDEF(&_74$$44);
	ZVAL_UNDEF(&_75$$44);
	ZVAL_UNDEF(&_130$$44);
	ZVAL_UNDEF(&_131$$44);
	ZVAL_UNDEF(&_132$$44);
	ZVAL_UNDEF(&_133$$44);
	ZVAL_UNDEF(&_134$$44);
	ZVAL_UNDEF(&_135$$44);
	ZVAL_UNDEF(&_137$$44);
	ZVAL_UNDEF(&_76$$47);
	ZVAL_UNDEF(&_77$$47);
	ZVAL_UNDEF(&_78$$48);
	ZVAL_UNDEF(&_79$$48);
	ZVAL_UNDEF(&_80$$49);
	ZVAL_UNDEF(&_81$$49);
	ZVAL_UNDEF(&_82$$50);
	ZVAL_UNDEF(&_83$$50);
	ZVAL_UNDEF(&_84$$51);
	ZVAL_UNDEF(&_85$$51);
	ZVAL_UNDEF(&_86$$52);
	ZVAL_UNDEF(&_87$$52);
	ZVAL_UNDEF(&_88$$53);
	ZVAL_UNDEF(&_89$$53);
	ZVAL_UNDEF(&_90$$54);
	ZVAL_UNDEF(&_91$$54);
	ZVAL_UNDEF(&_92$$55);
	ZVAL_UNDEF(&_93$$55);
	ZVAL_UNDEF(&_94$$56);
	ZVAL_UNDEF(&_95$$56);
	ZVAL_UNDEF(&_96$$57);
	ZVAL_UNDEF(&_97$$57);
	ZVAL_UNDEF(&_98$$58);
	ZVAL_UNDEF(&_99$$58);
	ZVAL_UNDEF(&_100$$59);
	ZVAL_UNDEF(&_101$$59);
	ZVAL_UNDEF(&_102$$60);
	ZVAL_UNDEF(&_103$$60);
	ZVAL_UNDEF(&_104$$61);
	ZVAL_UNDEF(&_105$$61);
	ZVAL_UNDEF(&_106$$62);
	ZVAL_UNDEF(&_107$$62);
	ZVAL_UNDEF(&_108$$63);
	ZVAL_UNDEF(&_109$$63);
	ZVAL_UNDEF(&_110$$64);
	ZVAL_UNDEF(&_111$$64);
	ZVAL_UNDEF(&_112$$65);
	ZVAL_UNDEF(&_113$$65);
	ZVAL_UNDEF(&_114$$66);
	ZVAL_UNDEF(&_115$$66);
	ZVAL_UNDEF(&_116$$67);
	ZVAL_UNDEF(&_117$$67);
	ZVAL_UNDEF(&_118$$68);
	ZVAL_UNDEF(&_119$$68);
	ZVAL_UNDEF(&_120$$69);
	ZVAL_UNDEF(&_121$$69);
	ZVAL_UNDEF(&_122$$70);
	ZVAL_UNDEF(&_123$$70);
	ZVAL_UNDEF(&_124$$71);
	ZVAL_UNDEF(&_125$$71);
	ZVAL_UNDEF(&_126$$72);
	ZVAL_UNDEF(&_127$$72);
	ZVAL_UNDEF(&_128$$73);
	ZVAL_UNDEF(&_129$$73);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &model, &container);
	if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_metadata_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 111);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "annotations");
	ZEPHIR_CALL_METHOD(&annotations, container, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0);
	ZEPHIR_CALL_METHOD(&reflection, &annotations, "get", NULL, 0, &className);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&reflection) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_metadata_exceptions_noannotationsforclass_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0, &className);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 120);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, &reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&propertiesAnnotations))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_metadata_exceptions_nopropertyannotationsforclass_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0, &className);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 129);
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
	if (Z_TYPE_P(&propertiesAnnotations) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_string_to_char_array(&_1, &propertiesAnnotations);
		_4 = &_1;
	} else {
		_4 = &propertiesAnnotations;
	}
	zephir_is_iterable(_4, 0, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 386);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&property);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&property, _7);
			} else {
				ZVAL_LONG(&property, _6);
			}
			ZEPHIR_INIT_NVAR(&propAnnotations);
			ZVAL_COPY(&propAnnotations, _5);
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "Column");
			ZEPHIR_CALL_METHOD(&_8$$6, &propAnnotations, "has", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_8$$6))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "Column");
			ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_9$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "column");
			ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&columnName)) {
				ZEPHIR_CPY_WRT(&columnName, &property);
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "type");
			ZEPHIR_CALL_METHOD(&feature, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_STRING(&feature, "biginteger")) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_STRING(&feature, "bit")) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_STRING(&feature, "blob")) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_STRING(&feature, "boolean")) { goto zephir_switch_0_clause_3; }
			if (ZEPHIR_IS_STRING(&feature, "char")) { goto zephir_switch_0_clause_4; }
			if (ZEPHIR_IS_STRING(&feature, "date")) { goto zephir_switch_0_clause_5; }
			if (ZEPHIR_IS_STRING(&feature, "datetime")) { goto zephir_switch_0_clause_6; }
			if (ZEPHIR_IS_STRING(&feature, "decimal")) { goto zephir_switch_0_clause_7; }
			if (ZEPHIR_IS_STRING(&feature, "double")) { goto zephir_switch_0_clause_8; }
			if (ZEPHIR_IS_STRING(&feature, "enum")) { goto zephir_switch_0_clause_9; }
			if (ZEPHIR_IS_STRING(&feature, "float")) { goto zephir_switch_0_clause_10; }
			if (ZEPHIR_IS_STRING(&feature, "integer")) { goto zephir_switch_0_clause_11; }
			if (ZEPHIR_IS_STRING(&feature, "json")) { goto zephir_switch_0_clause_12; }
			if (ZEPHIR_IS_STRING(&feature, "jsonb")) { goto zephir_switch_0_clause_13; }
			if (ZEPHIR_IS_STRING(&feature, "longblob")) { goto zephir_switch_0_clause_14; }
			if (ZEPHIR_IS_STRING(&feature, "longtext")) { goto zephir_switch_0_clause_15; }
			if (ZEPHIR_IS_STRING(&feature, "mediumblob")) { goto zephir_switch_0_clause_16; }
			if (ZEPHIR_IS_STRING(&feature, "mediumint")) { goto zephir_switch_0_clause_17; }
			if (ZEPHIR_IS_STRING(&feature, "mediumtext")) { goto zephir_switch_0_clause_18; }
			if (ZEPHIR_IS_STRING(&feature, "smallint")) { goto zephir_switch_0_clause_19; }
			if (ZEPHIR_IS_STRING(&feature, "text")) { goto zephir_switch_0_clause_20; }
			if (ZEPHIR_IS_STRING(&feature, "time")) { goto zephir_switch_0_clause_21; }
			if (ZEPHIR_IS_STRING(&feature, "timestamp")) { goto zephir_switch_0_clause_22; }
			if (ZEPHIR_IS_STRING(&feature, "tinyblob")) { goto zephir_switch_0_clause_23; }
			if (ZEPHIR_IS_STRING(&feature, "tinyint")) { goto zephir_switch_0_clause_24; }
			if (ZEPHIR_IS_STRING(&feature, "tinytext")) { goto zephir_switch_0_clause_25; }
			goto zephir_switch_0_clause_26;
			zephir_switch_0_clause_0: ;
				ZEPHIR_INIT_NVAR(&_10$$9);
				ZVAL_LONG(&_10$$9, 14);
				zephir_array_update_zval(&fieldTypes, &columnName, &_10$$9, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$9);
				ZVAL_LONG(&_11$$9, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_11$$9, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZVAL_LONG(&_12$$10, 19);
				zephir_array_update_zval(&fieldTypes, &columnName, &_12$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_LONG(&_13$$10, 1);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_13$$10, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_INIT_NVAR(&_14$$11);
				ZVAL_LONG(&_14$$11, 11);
				zephir_array_update_zval(&fieldTypes, &columnName, &_14$$11, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_15$$11);
				ZVAL_LONG(&_15$$11, 3);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_15$$11, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&_16$$12);
				ZVAL_LONG(&_16$$12, 8);
				zephir_array_update_zval(&fieldTypes, &columnName, &_16$$12, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZVAL_LONG(&_17$$12, 5);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_17$$12, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_INIT_NVAR(&_18$$13);
				ZVAL_LONG(&_18$$13, 5);
				zephir_array_update_zval(&fieldTypes, &columnName, &_18$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_19$$13);
				ZVAL_LONG(&_19$$13, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_19$$13, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_5: ;
				ZEPHIR_INIT_NVAR(&_20$$14);
				ZVAL_LONG(&_20$$14, 1);
				zephir_array_update_zval(&fieldTypes, &columnName, &_20$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_21$$14);
				ZVAL_LONG(&_21$$14, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_21$$14, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_6: ;
				ZEPHIR_INIT_NVAR(&_22$$15);
				ZVAL_LONG(&_22$$15, 4);
				zephir_array_update_zval(&fieldTypes, &columnName, &_22$$15, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_23$$15);
				ZVAL_LONG(&_23$$15, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_23$$15, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_INIT_NVAR(&_24$$16);
				ZVAL_LONG(&_24$$16, 3);
				zephir_array_update_zval(&fieldTypes, &columnName, &_24$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_25$$16);
				ZVAL_LONG(&_25$$16, 32);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_25$$16, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_8: ;
				ZEPHIR_INIT_NVAR(&_26$$17);
				ZVAL_LONG(&_26$$17, 9);
				zephir_array_update_zval(&fieldTypes, &columnName, &_26$$17, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_27$$17);
				ZVAL_LONG(&_27$$17, 32);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_27$$17, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_9: ;
				ZEPHIR_INIT_NVAR(&_28$$18);
				ZVAL_LONG(&_28$$18, 18);
				zephir_array_update_zval(&fieldTypes, &columnName, &_28$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_29$$18);
				ZVAL_LONG(&_29$$18, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_29$$18, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_10: ;
				ZEPHIR_INIT_NVAR(&_30$$19);
				ZVAL_LONG(&_30$$19, 7);
				zephir_array_update_zval(&fieldTypes, &columnName, &_30$$19, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_31$$19);
				ZVAL_LONG(&_31$$19, 32);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_31$$19, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_11: ;
				ZEPHIR_INIT_NVAR(&_32$$20);
				ZVAL_LONG(&_32$$20, 0);
				zephir_array_update_zval(&fieldTypes, &columnName, &_32$$20, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_33$$20);
				ZVAL_LONG(&_33$$20, 1);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_33$$20, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_12: ;
				ZEPHIR_INIT_NVAR(&_34$$21);
				ZVAL_LONG(&_34$$21, 15);
				zephir_array_update_zval(&fieldTypes, &columnName, &_34$$21, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_35$$21);
				ZVAL_LONG(&_35$$21, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_35$$21, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_13: ;
				ZEPHIR_INIT_NVAR(&_36$$22);
				ZVAL_LONG(&_36$$22, 16);
				zephir_array_update_zval(&fieldTypes, &columnName, &_36$$22, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_37$$22);
				ZVAL_LONG(&_37$$22, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_37$$22, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_14: ;
				ZEPHIR_INIT_NVAR(&_38$$23);
				ZVAL_LONG(&_38$$23, 13);
				zephir_array_update_zval(&fieldTypes, &columnName, &_38$$23, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_39$$23);
				ZVAL_LONG(&_39$$23, 3);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_39$$23, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_15: ;
				ZEPHIR_INIT_NVAR(&_40$$24);
				ZVAL_LONG(&_40$$24, 24);
				zephir_array_update_zval(&fieldTypes, &columnName, &_40$$24, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_41$$24);
				ZVAL_LONG(&_41$$24, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_41$$24, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_16: ;
				ZEPHIR_INIT_NVAR(&_42$$25);
				ZVAL_LONG(&_42$$25, 12);
				zephir_array_update_zval(&fieldTypes, &columnName, &_42$$25, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_43$$25);
				ZVAL_LONG(&_43$$25, 3);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_43$$25, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_17: ;
				ZEPHIR_INIT_NVAR(&_44$$26);
				ZVAL_LONG(&_44$$26, 21);
				zephir_array_update_zval(&fieldTypes, &columnName, &_44$$26, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_45$$26);
				ZVAL_LONG(&_45$$26, 1);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_45$$26, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_18: ;
				ZEPHIR_INIT_NVAR(&_46$$27);
				ZVAL_LONG(&_46$$27, 23);
				zephir_array_update_zval(&fieldTypes, &columnName, &_46$$27, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_47$$27);
				ZVAL_LONG(&_47$$27, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_47$$27, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_19: ;
				ZEPHIR_INIT_NVAR(&_48$$28);
				ZVAL_LONG(&_48$$28, 22);
				zephir_array_update_zval(&fieldTypes, &columnName, &_48$$28, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_49$$28);
				ZVAL_LONG(&_49$$28, 1);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_49$$28, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_20: ;
				ZEPHIR_INIT_NVAR(&_50$$29);
				ZVAL_LONG(&_50$$29, 6);
				zephir_array_update_zval(&fieldTypes, &columnName, &_50$$29, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_51$$29);
				ZVAL_LONG(&_51$$29, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_51$$29, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_21: ;
				ZEPHIR_INIT_NVAR(&_52$$30);
				ZVAL_LONG(&_52$$30, 20);
				zephir_array_update_zval(&fieldTypes, &columnName, &_52$$30, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_53$$30);
				ZVAL_LONG(&_53$$30, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_53$$30, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_22: ;
				ZEPHIR_INIT_NVAR(&_54$$31);
				ZVAL_LONG(&_54$$31, 17);
				zephir_array_update_zval(&fieldTypes, &columnName, &_54$$31, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_55$$31);
				ZVAL_LONG(&_55$$31, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_55$$31, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_23: ;
				ZEPHIR_INIT_NVAR(&_56$$32);
				ZVAL_LONG(&_56$$32, 10);
				zephir_array_update_zval(&fieldTypes, &columnName, &_56$$32, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_57$$32);
				ZVAL_LONG(&_57$$32, 3);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_57$$32, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_24: ;
				ZEPHIR_INIT_NVAR(&_58$$33);
				ZVAL_LONG(&_58$$33, 26);
				zephir_array_update_zval(&fieldTypes, &columnName, &_58$$33, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_59$$33);
				ZVAL_LONG(&_59$$33, 1);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_59$$33, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_25: ;
				ZEPHIR_INIT_NVAR(&_60$$34);
				ZVAL_LONG(&_60$$34, 25);
				zephir_array_update_zval(&fieldTypes, &columnName, &_60$$34, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_61$$34);
				ZVAL_LONG(&_61$$34, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_61$$34, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_26: ;
				ZEPHIR_INIT_NVAR(&_62$$35);
				ZVAL_LONG(&_62$$35, 2);
				zephir_array_update_zval(&fieldTypes, &columnName, &_62$$35, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_63$$35);
				ZVAL_LONG(&_63$$35, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_63$$35, PH_COPY | PH_SEPARATE);
			zephir_switch_0_end: ;

			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "Primary");
			ZEPHIR_CALL_METHOD(&_64$$6, &propAnnotations, "has", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_64$$6)) {
				zephir_array_append(&primaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 330);
			} else {
				zephir_array_append(&nonPrimaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 332);
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "Identity");
			ZEPHIR_CALL_METHOD(&_65$$6, &propAnnotations, "has", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_65$$6)) {
				ZEPHIR_CPY_WRT(&identityField, &columnName);
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "skip_on_insert");
			ZEPHIR_CALL_METHOD(&_66$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_66$$6)) {
				zephir_array_update_zval(&skipOnInsert, &columnName, &__$true, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "skip_on_update");
			ZEPHIR_CALL_METHOD(&_67$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_67$$6)) {
				zephir_array_update_zval(&skipOnUpdate, &columnName, &__$true, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "allow_empty_string");
			ZEPHIR_CALL_METHOD(&_68$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_68$$6)) {
				zephir_array_update_zval(&emptyStringValues, &columnName, &columnName, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "nullable");
			ZEPHIR_CALL_METHOD(&_69$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (!(zephir_is_true(&_69$$6))) {
				zephir_array_append(&notNull, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 368);
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "default");
			ZEPHIR_CALL_METHOD(&defaultValue, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			_70$$6 = Z_TYPE_P(&defaultValue) != IS_NULL;
			if (!(_70$$6)) {
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZVAL_STRING(&_9$$6, "nullable");
				ZEPHIR_CALL_METHOD(&_71$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
				zephir_check_call_status();
				_70$$6 = zephir_is_true(&_71$$6);
			}
			if (_70$$6) {
				zephir_array_update_zval(&defaultValues, &columnName, &defaultValue, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&attributes, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 380);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_73 = 1;
		while (1) {
			if (_73) {
				_73 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_72, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_72)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, _4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&propAnnotations, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "Column");
				ZEPHIR_CALL_METHOD(&_74$$44, &propAnnotations, "has", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (!(zephir_is_true(&_74$$44))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "Column");
				ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_75$$44);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "column");
				ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&columnName)) {
					ZEPHIR_CPY_WRT(&columnName, &property);
				}
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "type");
				ZEPHIR_CALL_METHOD(&feature, &columnAnnotation, "getnamedparameter", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&feature, "biginteger")) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_STRING(&feature, "bit")) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_STRING(&feature, "blob")) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_STRING(&feature, "boolean")) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_STRING(&feature, "char")) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_STRING(&feature, "date")) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_STRING(&feature, "datetime")) { goto zephir_switch_1_clause_6; }
				if (ZEPHIR_IS_STRING(&feature, "decimal")) { goto zephir_switch_1_clause_7; }
				if (ZEPHIR_IS_STRING(&feature, "double")) { goto zephir_switch_1_clause_8; }
				if (ZEPHIR_IS_STRING(&feature, "enum")) { goto zephir_switch_1_clause_9; }
				if (ZEPHIR_IS_STRING(&feature, "float")) { goto zephir_switch_1_clause_10; }
				if (ZEPHIR_IS_STRING(&feature, "integer")) { goto zephir_switch_1_clause_11; }
				if (ZEPHIR_IS_STRING(&feature, "json")) { goto zephir_switch_1_clause_12; }
				if (ZEPHIR_IS_STRING(&feature, "jsonb")) { goto zephir_switch_1_clause_13; }
				if (ZEPHIR_IS_STRING(&feature, "longblob")) { goto zephir_switch_1_clause_14; }
				if (ZEPHIR_IS_STRING(&feature, "longtext")) { goto zephir_switch_1_clause_15; }
				if (ZEPHIR_IS_STRING(&feature, "mediumblob")) { goto zephir_switch_1_clause_16; }
				if (ZEPHIR_IS_STRING(&feature, "mediumint")) { goto zephir_switch_1_clause_17; }
				if (ZEPHIR_IS_STRING(&feature, "mediumtext")) { goto zephir_switch_1_clause_18; }
				if (ZEPHIR_IS_STRING(&feature, "smallint")) { goto zephir_switch_1_clause_19; }
				if (ZEPHIR_IS_STRING(&feature, "text")) { goto zephir_switch_1_clause_20; }
				if (ZEPHIR_IS_STRING(&feature, "time")) { goto zephir_switch_1_clause_21; }
				if (ZEPHIR_IS_STRING(&feature, "timestamp")) { goto zephir_switch_1_clause_22; }
				if (ZEPHIR_IS_STRING(&feature, "tinyblob")) { goto zephir_switch_1_clause_23; }
				if (ZEPHIR_IS_STRING(&feature, "tinyint")) { goto zephir_switch_1_clause_24; }
				if (ZEPHIR_IS_STRING(&feature, "tinytext")) { goto zephir_switch_1_clause_25; }
				goto zephir_switch_1_clause_26;
				zephir_switch_1_clause_0: ;
					ZEPHIR_INIT_NVAR(&_76$$47);
					ZVAL_LONG(&_76$$47, 14);
					zephir_array_update_zval(&fieldTypes, &columnName, &_76$$47, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_77$$47);
					ZVAL_LONG(&_77$$47, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_77$$47, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					ZEPHIR_INIT_NVAR(&_78$$48);
					ZVAL_LONG(&_78$$48, 19);
					zephir_array_update_zval(&fieldTypes, &columnName, &_78$$48, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_79$$48);
					ZVAL_LONG(&_79$$48, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_79$$48, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_NVAR(&_80$$49);
					ZVAL_LONG(&_80$$49, 11);
					zephir_array_update_zval(&fieldTypes, &columnName, &_80$$49, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_81$$49);
					ZVAL_LONG(&_81$$49, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_81$$49, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&_82$$50);
					ZVAL_LONG(&_82$$50, 8);
					zephir_array_update_zval(&fieldTypes, &columnName, &_82$$50, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_83$$50);
					ZVAL_LONG(&_83$$50, 5);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_83$$50, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_INIT_NVAR(&_84$$51);
					ZVAL_LONG(&_84$$51, 5);
					zephir_array_update_zval(&fieldTypes, &columnName, &_84$$51, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_85$$51);
					ZVAL_LONG(&_85$$51, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_85$$51, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_5: ;
					ZEPHIR_INIT_NVAR(&_86$$52);
					ZVAL_LONG(&_86$$52, 1);
					zephir_array_update_zval(&fieldTypes, &columnName, &_86$$52, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_87$$52);
					ZVAL_LONG(&_87$$52, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_87$$52, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
					ZEPHIR_INIT_NVAR(&_88$$53);
					ZVAL_LONG(&_88$$53, 4);
					zephir_array_update_zval(&fieldTypes, &columnName, &_88$$53, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_89$$53);
					ZVAL_LONG(&_89$$53, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_89$$53, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_INIT_NVAR(&_90$$54);
					ZVAL_LONG(&_90$$54, 3);
					zephir_array_update_zval(&fieldTypes, &columnName, &_90$$54, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_91$$54);
					ZVAL_LONG(&_91$$54, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_91$$54, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_8: ;
					ZEPHIR_INIT_NVAR(&_92$$55);
					ZVAL_LONG(&_92$$55, 9);
					zephir_array_update_zval(&fieldTypes, &columnName, &_92$$55, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_93$$55);
					ZVAL_LONG(&_93$$55, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_93$$55, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_INIT_NVAR(&_94$$56);
					ZVAL_LONG(&_94$$56, 18);
					zephir_array_update_zval(&fieldTypes, &columnName, &_94$$56, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_95$$56);
					ZVAL_LONG(&_95$$56, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_95$$56, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_10: ;
					ZEPHIR_INIT_NVAR(&_96$$57);
					ZVAL_LONG(&_96$$57, 7);
					zephir_array_update_zval(&fieldTypes, &columnName, &_96$$57, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_97$$57);
					ZVAL_LONG(&_97$$57, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_97$$57, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_11: ;
					ZEPHIR_INIT_NVAR(&_98$$58);
					ZVAL_LONG(&_98$$58, 0);
					zephir_array_update_zval(&fieldTypes, &columnName, &_98$$58, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_99$$58);
					ZVAL_LONG(&_99$$58, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_99$$58, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_12: ;
					ZEPHIR_INIT_NVAR(&_100$$59);
					ZVAL_LONG(&_100$$59, 15);
					zephir_array_update_zval(&fieldTypes, &columnName, &_100$$59, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_101$$59);
					ZVAL_LONG(&_101$$59, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_101$$59, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_13: ;
					ZEPHIR_INIT_NVAR(&_102$$60);
					ZVAL_LONG(&_102$$60, 16);
					zephir_array_update_zval(&fieldTypes, &columnName, &_102$$60, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_103$$60);
					ZVAL_LONG(&_103$$60, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_103$$60, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_14: ;
					ZEPHIR_INIT_NVAR(&_104$$61);
					ZVAL_LONG(&_104$$61, 13);
					zephir_array_update_zval(&fieldTypes, &columnName, &_104$$61, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_105$$61);
					ZVAL_LONG(&_105$$61, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_105$$61, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_15: ;
					ZEPHIR_INIT_NVAR(&_106$$62);
					ZVAL_LONG(&_106$$62, 24);
					zephir_array_update_zval(&fieldTypes, &columnName, &_106$$62, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_107$$62);
					ZVAL_LONG(&_107$$62, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_107$$62, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_16: ;
					ZEPHIR_INIT_NVAR(&_108$$63);
					ZVAL_LONG(&_108$$63, 12);
					zephir_array_update_zval(&fieldTypes, &columnName, &_108$$63, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_109$$63);
					ZVAL_LONG(&_109$$63, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_109$$63, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_17: ;
					ZEPHIR_INIT_NVAR(&_110$$64);
					ZVAL_LONG(&_110$$64, 21);
					zephir_array_update_zval(&fieldTypes, &columnName, &_110$$64, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_111$$64);
					ZVAL_LONG(&_111$$64, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_111$$64, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_18: ;
					ZEPHIR_INIT_NVAR(&_112$$65);
					ZVAL_LONG(&_112$$65, 23);
					zephir_array_update_zval(&fieldTypes, &columnName, &_112$$65, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_113$$65);
					ZVAL_LONG(&_113$$65, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_113$$65, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_19: ;
					ZEPHIR_INIT_NVAR(&_114$$66);
					ZVAL_LONG(&_114$$66, 22);
					zephir_array_update_zval(&fieldTypes, &columnName, &_114$$66, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_115$$66);
					ZVAL_LONG(&_115$$66, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_115$$66, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_20: ;
					ZEPHIR_INIT_NVAR(&_116$$67);
					ZVAL_LONG(&_116$$67, 6);
					zephir_array_update_zval(&fieldTypes, &columnName, &_116$$67, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_117$$67);
					ZVAL_LONG(&_117$$67, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_117$$67, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_21: ;
					ZEPHIR_INIT_NVAR(&_118$$68);
					ZVAL_LONG(&_118$$68, 20);
					zephir_array_update_zval(&fieldTypes, &columnName, &_118$$68, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_119$$68);
					ZVAL_LONG(&_119$$68, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_119$$68, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_22: ;
					ZEPHIR_INIT_NVAR(&_120$$69);
					ZVAL_LONG(&_120$$69, 17);
					zephir_array_update_zval(&fieldTypes, &columnName, &_120$$69, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_121$$69);
					ZVAL_LONG(&_121$$69, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_121$$69, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_23: ;
					ZEPHIR_INIT_NVAR(&_122$$70);
					ZVAL_LONG(&_122$$70, 10);
					zephir_array_update_zval(&fieldTypes, &columnName, &_122$$70, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_123$$70);
					ZVAL_LONG(&_123$$70, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_123$$70, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_24: ;
					ZEPHIR_INIT_NVAR(&_124$$71);
					ZVAL_LONG(&_124$$71, 26);
					zephir_array_update_zval(&fieldTypes, &columnName, &_124$$71, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_125$$71);
					ZVAL_LONG(&_125$$71, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_125$$71, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_25: ;
					ZEPHIR_INIT_NVAR(&_126$$72);
					ZVAL_LONG(&_126$$72, 25);
					zephir_array_update_zval(&fieldTypes, &columnName, &_126$$72, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_127$$72);
					ZVAL_LONG(&_127$$72, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_127$$72, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_26: ;
					ZEPHIR_INIT_NVAR(&_128$$73);
					ZVAL_LONG(&_128$$73, 2);
					zephir_array_update_zval(&fieldTypes, &columnName, &_128$$73, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_129$$73);
					ZVAL_LONG(&_129$$73, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_129$$73, PH_COPY | PH_SEPARATE);
				zephir_switch_1_end: ;

				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "Primary");
				ZEPHIR_CALL_METHOD(&_130$$44, &propAnnotations, "has", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_130$$44)) {
					zephir_array_append(&primaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 330);
				} else {
					zephir_array_append(&nonPrimaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 332);
				}
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "Identity");
				ZEPHIR_CALL_METHOD(&_131$$44, &propAnnotations, "has", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_131$$44)) {
					ZEPHIR_CPY_WRT(&identityField, &columnName);
				}
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "skip_on_insert");
				ZEPHIR_CALL_METHOD(&_132$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_132$$44)) {
					zephir_array_update_zval(&skipOnInsert, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "skip_on_update");
				ZEPHIR_CALL_METHOD(&_133$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_133$$44)) {
					zephir_array_update_zval(&skipOnUpdate, &columnName, &__$true, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "allow_empty_string");
				ZEPHIR_CALL_METHOD(&_134$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_134$$44)) {
					zephir_array_update_zval(&emptyStringValues, &columnName, &columnName, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "nullable");
				ZEPHIR_CALL_METHOD(&_135$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_75$$44);
				zephir_check_call_status();
				if (!(zephir_is_true(&_135$$44))) {
					zephir_array_append(&notNull, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 368);
				}
				ZEPHIR_INIT_NVAR(&_75$$44);
				ZVAL_STRING(&_75$$44, "default");
				ZEPHIR_CALL_METHOD(&defaultValue, &columnAnnotation, "getnamedparameter", NULL, 0, &_75$$44);
				zephir_check_call_status();
				_136$$44 = Z_TYPE_P(&defaultValue) != IS_NULL;
				if (!(_136$$44)) {
					ZEPHIR_INIT_NVAR(&_75$$44);
					ZVAL_STRING(&_75$$44, "nullable");
					ZEPHIR_CALL_METHOD(&_137$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_75$$44);
					zephir_check_call_status();
					_136$$44 = zephir_is_true(&_137$$44);
				}
				if (_136$$44) {
					zephir_array_update_zval(&defaultValues, &columnName, &defaultValue, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&attributes, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 380);
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

