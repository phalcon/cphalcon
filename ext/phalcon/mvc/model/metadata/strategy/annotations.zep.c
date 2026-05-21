
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
	zend_bool hasReversedColumn = 0, _10$$6, _13$$10;
	zval orderedColumnMap, reversedColumnMap;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *container, container_sub, __$null, annotations, className, reflection, propertiesAnnotations, property, propAnnotations, columnAnnotation, columnName, _1, *_4, _5, _0$$3, _2$$4, _3$$5, _8$$6, _9$$6, _11$$10, _12$$10;

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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 35);
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
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 44);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, &reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&propertiesAnnotations)))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_metadata_exceptions_nopropertyannotationsforclass_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0, &className);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 53);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&orderedColumnMap);
	array_init(&orderedColumnMap);
	ZEPHIR_INIT_VAR(&reversedColumnMap);
	array_init(&reversedColumnMap);
	hasReversedColumn = 0;
	zephir_is_iterable(&propertiesAnnotations, 0, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 90);
	if (Z_TYPE_P(&propertiesAnnotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&propertiesAnnotations), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&property);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&property, _7);
			} else {
				ZVAL_LONG(&property, _6);
			}
			ZEPHIR_INIT_NVAR(&propAnnotations);
			ZVAL_COPY(&propAnnotations, _4);
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
		ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &propertiesAnnotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, &propertiesAnnotations, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&propAnnotations, &propertiesAnnotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZVAL_STRING(&_12$$10, "Column");
				ZEPHIR_CALL_METHOD(&_11$$10, &propAnnotations, "has", NULL, 0, &_12$$10);
				zephir_check_call_status();
				if (!(zephir_is_true(&_11$$10))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZVAL_STRING(&_12$$10, "Column");
				ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_12$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZVAL_STRING(&_12$$10, "column");
				ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_12$$10);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&columnName)) {
					ZEPHIR_CPY_WRT(&columnName, &property);
				}
				zephir_array_update_zval(&orderedColumnMap, &columnName, &property, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&reversedColumnMap, &property, &columnName, PH_COPY | PH_SEPARATE);
				_13$$10 = !hasReversedColumn;
				if (_13$$10) {
					_13$$10 = !ZEPHIR_IS_EQUAL(&columnName, &property);
				}
				if (_13$$10) {
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
	zend_bool _70$$6, _134$$44;
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *container, container_sub, __$true, annotations, className, reflection, propertiesAnnotations, property, propAnnotations, columnAnnotation, columnName, feature, fieldTypes, fieldBindTypes, numericTyped, primaryKeys, nonPrimaryKeys, identityField, notNull, attributes, defaultValues, defaultValue, emptyStringValues, skipOnInsert, skipOnUpdate, _1, *_4, _5, _0$$3, _2$$4, _3$$5, _8$$6, _9$$6, _64$$6, _65$$6, _66$$6, _67$$6, _68$$6, _69$$6, _71$$6, _10$$9, _11$$9, _12$$10, _13$$10, _14$$11, _15$$11, _16$$12, _17$$12, _18$$13, _19$$13, _20$$14, _21$$14, _22$$15, _23$$15, _24$$16, _25$$16, _26$$17, _27$$17, _28$$18, _29$$18, _30$$19, _31$$19, _32$$20, _33$$20, _34$$21, _35$$21, _36$$22, _37$$22, _38$$23, _39$$23, _40$$24, _41$$24, _42$$25, _43$$25, _44$$26, _45$$26, _46$$27, _47$$27, _48$$28, _49$$28, _50$$29, _51$$29, _52$$30, _53$$30, _54$$31, _55$$31, _56$$32, _57$$32, _58$$33, _59$$33, _60$$34, _61$$34, _62$$35, _63$$35, _72$$44, _73$$44, _128$$44, _129$$44, _130$$44, _131$$44, _132$$44, _133$$44, _135$$44, _74$$47, _75$$47, _76$$48, _77$$48, _78$$49, _79$$49, _80$$50, _81$$50, _82$$51, _83$$51, _84$$52, _85$$52, _86$$53, _87$$53, _88$$54, _89$$54, _90$$55, _91$$55, _92$$56, _93$$56, _94$$57, _95$$57, _96$$58, _97$$58, _98$$59, _99$$59, _100$$60, _101$$60, _102$$61, _103$$61, _104$$62, _105$$62, _106$$63, _107$$63, _108$$64, _109$$64, _110$$65, _111$$65, _112$$66, _113$$66, _114$$67, _115$$67, _116$$68, _117$$68, _118$$69, _119$$69, _120$$70, _121$$70, _122$$71, _123$$71, _124$$72, _125$$72, _126$$73, _127$$73;

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
	ZVAL_UNDEF(&_5);
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
	ZVAL_UNDEF(&_72$$44);
	ZVAL_UNDEF(&_73$$44);
	ZVAL_UNDEF(&_128$$44);
	ZVAL_UNDEF(&_129$$44);
	ZVAL_UNDEF(&_130$$44);
	ZVAL_UNDEF(&_131$$44);
	ZVAL_UNDEF(&_132$$44);
	ZVAL_UNDEF(&_133$$44);
	ZVAL_UNDEF(&_135$$44);
	ZVAL_UNDEF(&_74$$47);
	ZVAL_UNDEF(&_75$$47);
	ZVAL_UNDEF(&_76$$48);
	ZVAL_UNDEF(&_77$$48);
	ZVAL_UNDEF(&_78$$49);
	ZVAL_UNDEF(&_79$$49);
	ZVAL_UNDEF(&_80$$50);
	ZVAL_UNDEF(&_81$$50);
	ZVAL_UNDEF(&_82$$51);
	ZVAL_UNDEF(&_83$$51);
	ZVAL_UNDEF(&_84$$52);
	ZVAL_UNDEF(&_85$$52);
	ZVAL_UNDEF(&_86$$53);
	ZVAL_UNDEF(&_87$$53);
	ZVAL_UNDEF(&_88$$54);
	ZVAL_UNDEF(&_89$$54);
	ZVAL_UNDEF(&_90$$55);
	ZVAL_UNDEF(&_91$$55);
	ZVAL_UNDEF(&_92$$56);
	ZVAL_UNDEF(&_93$$56);
	ZVAL_UNDEF(&_94$$57);
	ZVAL_UNDEF(&_95$$57);
	ZVAL_UNDEF(&_96$$58);
	ZVAL_UNDEF(&_97$$58);
	ZVAL_UNDEF(&_98$$59);
	ZVAL_UNDEF(&_99$$59);
	ZVAL_UNDEF(&_100$$60);
	ZVAL_UNDEF(&_101$$60);
	ZVAL_UNDEF(&_102$$61);
	ZVAL_UNDEF(&_103$$61);
	ZVAL_UNDEF(&_104$$62);
	ZVAL_UNDEF(&_105$$62);
	ZVAL_UNDEF(&_106$$63);
	ZVAL_UNDEF(&_107$$63);
	ZVAL_UNDEF(&_108$$64);
	ZVAL_UNDEF(&_109$$64);
	ZVAL_UNDEF(&_110$$65);
	ZVAL_UNDEF(&_111$$65);
	ZVAL_UNDEF(&_112$$66);
	ZVAL_UNDEF(&_113$$66);
	ZVAL_UNDEF(&_114$$67);
	ZVAL_UNDEF(&_115$$67);
	ZVAL_UNDEF(&_116$$68);
	ZVAL_UNDEF(&_117$$68);
	ZVAL_UNDEF(&_118$$69);
	ZVAL_UNDEF(&_119$$69);
	ZVAL_UNDEF(&_120$$70);
	ZVAL_UNDEF(&_121$$70);
	ZVAL_UNDEF(&_122$$71);
	ZVAL_UNDEF(&_123$$71);
	ZVAL_UNDEF(&_124$$72);
	ZVAL_UNDEF(&_125$$72);
	ZVAL_UNDEF(&_126$$73);
	ZVAL_UNDEF(&_127$$73);
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 112);
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
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 121);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&propertiesAnnotations, &reflection, "getpropertiesannotations", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&propertiesAnnotations)))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_metadata_exceptions_nopropertyannotationsforclass_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0, &className);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 130);
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
	zephir_is_iterable(&propertiesAnnotations, 0, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 387);
	if (Z_TYPE_P(&propertiesAnnotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&propertiesAnnotations), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&property);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&property, _7);
			} else {
				ZVAL_LONG(&property, _6);
			}
			ZEPHIR_INIT_NVAR(&propAnnotations);
			ZVAL_COPY(&propAnnotations, _4);
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
			do {
				if (ZEPHIR_IS_STRING(&feature, "biginteger")) {
					ZEPHIR_INIT_NVAR(&_10$$9);
					ZVAL_LONG(&_10$$9, 14);
					zephir_array_update_zval(&fieldTypes, &columnName, &_10$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_11$$9);
					ZVAL_LONG(&_11$$9, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_11$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "bit")) {
					ZEPHIR_INIT_NVAR(&_12$$10);
					ZVAL_LONG(&_12$$10, 19);
					zephir_array_update_zval(&fieldTypes, &columnName, &_12$$10, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_13$$10);
					ZVAL_LONG(&_13$$10, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_13$$10, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "blob")) {
					ZEPHIR_INIT_NVAR(&_14$$11);
					ZVAL_LONG(&_14$$11, 11);
					zephir_array_update_zval(&fieldTypes, &columnName, &_14$$11, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_15$$11);
					ZVAL_LONG(&_15$$11, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_15$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "boolean")) {
					ZEPHIR_INIT_NVAR(&_16$$12);
					ZVAL_LONG(&_16$$12, 8);
					zephir_array_update_zval(&fieldTypes, &columnName, &_16$$12, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_17$$12);
					ZVAL_LONG(&_17$$12, 5);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_17$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "char")) {
					ZEPHIR_INIT_NVAR(&_18$$13);
					ZVAL_LONG(&_18$$13, 5);
					zephir_array_update_zval(&fieldTypes, &columnName, &_18$$13, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_19$$13);
					ZVAL_LONG(&_19$$13, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_19$$13, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "date")) {
					ZEPHIR_INIT_NVAR(&_20$$14);
					ZVAL_LONG(&_20$$14, 1);
					zephir_array_update_zval(&fieldTypes, &columnName, &_20$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_21$$14);
					ZVAL_LONG(&_21$$14, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_21$$14, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "datetime")) {
					ZEPHIR_INIT_NVAR(&_22$$15);
					ZVAL_LONG(&_22$$15, 4);
					zephir_array_update_zval(&fieldTypes, &columnName, &_22$$15, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_23$$15);
					ZVAL_LONG(&_23$$15, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_23$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "decimal")) {
					ZEPHIR_INIT_NVAR(&_24$$16);
					ZVAL_LONG(&_24$$16, 3);
					zephir_array_update_zval(&fieldTypes, &columnName, &_24$$16, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_25$$16);
					ZVAL_LONG(&_25$$16, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_25$$16, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "double")) {
					ZEPHIR_INIT_NVAR(&_26$$17);
					ZVAL_LONG(&_26$$17, 9);
					zephir_array_update_zval(&fieldTypes, &columnName, &_26$$17, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_27$$17);
					ZVAL_LONG(&_27$$17, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_27$$17, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "enum")) {
					ZEPHIR_INIT_NVAR(&_28$$18);
					ZVAL_LONG(&_28$$18, 18);
					zephir_array_update_zval(&fieldTypes, &columnName, &_28$$18, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_29$$18);
					ZVAL_LONG(&_29$$18, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_29$$18, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "float")) {
					ZEPHIR_INIT_NVAR(&_30$$19);
					ZVAL_LONG(&_30$$19, 7);
					zephir_array_update_zval(&fieldTypes, &columnName, &_30$$19, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_31$$19);
					ZVAL_LONG(&_31$$19, 32);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_31$$19, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "integer")) {
					ZEPHIR_INIT_NVAR(&_32$$20);
					ZVAL_LONG(&_32$$20, 0);
					zephir_array_update_zval(&fieldTypes, &columnName, &_32$$20, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_33$$20);
					ZVAL_LONG(&_33$$20, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_33$$20, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "json")) {
					ZEPHIR_INIT_NVAR(&_34$$21);
					ZVAL_LONG(&_34$$21, 15);
					zephir_array_update_zval(&fieldTypes, &columnName, &_34$$21, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_35$$21);
					ZVAL_LONG(&_35$$21, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_35$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "jsonb")) {
					ZEPHIR_INIT_NVAR(&_36$$22);
					ZVAL_LONG(&_36$$22, 16);
					zephir_array_update_zval(&fieldTypes, &columnName, &_36$$22, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_37$$22);
					ZVAL_LONG(&_37$$22, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_37$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "longblob")) {
					ZEPHIR_INIT_NVAR(&_38$$23);
					ZVAL_LONG(&_38$$23, 13);
					zephir_array_update_zval(&fieldTypes, &columnName, &_38$$23, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_39$$23);
					ZVAL_LONG(&_39$$23, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_39$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "longtext")) {
					ZEPHIR_INIT_NVAR(&_40$$24);
					ZVAL_LONG(&_40$$24, 24);
					zephir_array_update_zval(&fieldTypes, &columnName, &_40$$24, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_41$$24);
					ZVAL_LONG(&_41$$24, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_41$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "mediumblob")) {
					ZEPHIR_INIT_NVAR(&_42$$25);
					ZVAL_LONG(&_42$$25, 12);
					zephir_array_update_zval(&fieldTypes, &columnName, &_42$$25, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_43$$25);
					ZVAL_LONG(&_43$$25, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_43$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "mediumint")) {
					ZEPHIR_INIT_NVAR(&_44$$26);
					ZVAL_LONG(&_44$$26, 21);
					zephir_array_update_zval(&fieldTypes, &columnName, &_44$$26, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_45$$26);
					ZVAL_LONG(&_45$$26, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_45$$26, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "mediumtext")) {
					ZEPHIR_INIT_NVAR(&_46$$27);
					ZVAL_LONG(&_46$$27, 23);
					zephir_array_update_zval(&fieldTypes, &columnName, &_46$$27, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_47$$27);
					ZVAL_LONG(&_47$$27, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_47$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "smallint")) {
					ZEPHIR_INIT_NVAR(&_48$$28);
					ZVAL_LONG(&_48$$28, 22);
					zephir_array_update_zval(&fieldTypes, &columnName, &_48$$28, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_49$$28);
					ZVAL_LONG(&_49$$28, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_49$$28, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "text")) {
					ZEPHIR_INIT_NVAR(&_50$$29);
					ZVAL_LONG(&_50$$29, 6);
					zephir_array_update_zval(&fieldTypes, &columnName, &_50$$29, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_51$$29);
					ZVAL_LONG(&_51$$29, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_51$$29, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "time")) {
					ZEPHIR_INIT_NVAR(&_52$$30);
					ZVAL_LONG(&_52$$30, 20);
					zephir_array_update_zval(&fieldTypes, &columnName, &_52$$30, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_53$$30);
					ZVAL_LONG(&_53$$30, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_53$$30, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "timestamp")) {
					ZEPHIR_INIT_NVAR(&_54$$31);
					ZVAL_LONG(&_54$$31, 17);
					zephir_array_update_zval(&fieldTypes, &columnName, &_54$$31, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_55$$31);
					ZVAL_LONG(&_55$$31, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_55$$31, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "tinyblob")) {
					ZEPHIR_INIT_NVAR(&_56$$32);
					ZVAL_LONG(&_56$$32, 10);
					zephir_array_update_zval(&fieldTypes, &columnName, &_56$$32, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_57$$32);
					ZVAL_LONG(&_57$$32, 3);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_57$$32, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "tinyint")) {
					ZEPHIR_INIT_NVAR(&_58$$33);
					ZVAL_LONG(&_58$$33, 26);
					zephir_array_update_zval(&fieldTypes, &columnName, &_58$$33, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_59$$33);
					ZVAL_LONG(&_59$$33, 1);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_59$$33, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_STRING(&feature, "tinytext")) {
					ZEPHIR_INIT_NVAR(&_60$$34);
					ZVAL_LONG(&_60$$34, 25);
					zephir_array_update_zval(&fieldTypes, &columnName, &_60$$34, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_61$$34);
					ZVAL_LONG(&_61$$34, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_61$$34, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_62$$35);
				ZVAL_LONG(&_62$$35, 2);
				zephir_array_update_zval(&fieldTypes, &columnName, &_62$$35, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_63$$35);
				ZVAL_LONG(&_63$$35, 2);
				zephir_array_update_zval(&fieldBindTypes, &columnName, &_63$$35, PH_COPY | PH_SEPARATE);
			} while(0);

			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "Primary");
			ZEPHIR_CALL_METHOD(&_64$$6, &propAnnotations, "has", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_64$$6)) {
				zephir_array_append(&primaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 331);
			} else {
				zephir_array_append(&nonPrimaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 333);
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
				zephir_array_append(&skipOnInsert, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 348);
			}
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "skip_on_update");
			ZEPHIR_CALL_METHOD(&_67$$6, &columnAnnotation, "getnamedparameter", NULL, 0, &_9$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_67$$6)) {
				zephir_array_append(&skipOnUpdate, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 355);
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
				zephir_array_append(&notNull, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 369);
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
			zephir_array_append(&attributes, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 381);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &propertiesAnnotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &propertiesAnnotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&property, &propertiesAnnotations, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&propAnnotations, &propertiesAnnotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "Column");
				ZEPHIR_CALL_METHOD(&_72$$44, &propAnnotations, "has", NULL, 0, &_73$$44);
				zephir_check_call_status();
				if (!(zephir_is_true(&_72$$44))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "Column");
				ZEPHIR_CALL_METHOD(&columnAnnotation, &propAnnotations, "get", NULL, 0, &_73$$44);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "column");
				ZEPHIR_CALL_METHOD(&columnName, &columnAnnotation, "getnamedparameter", NULL, 0, &_73$$44);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(&columnName)) {
					ZEPHIR_CPY_WRT(&columnName, &property);
				}
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "type");
				ZEPHIR_CALL_METHOD(&feature, &columnAnnotation, "getnamedparameter", NULL, 0, &_73$$44);
				zephir_check_call_status();
				do {
					if (ZEPHIR_IS_STRING(&feature, "biginteger")) {
						ZEPHIR_INIT_NVAR(&_74$$47);
						ZVAL_LONG(&_74$$47, 14);
						zephir_array_update_zval(&fieldTypes, &columnName, &_74$$47, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_75$$47);
						ZVAL_LONG(&_75$$47, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_75$$47, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "bit")) {
						ZEPHIR_INIT_NVAR(&_76$$48);
						ZVAL_LONG(&_76$$48, 19);
						zephir_array_update_zval(&fieldTypes, &columnName, &_76$$48, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_77$$48);
						ZVAL_LONG(&_77$$48, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_77$$48, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "blob")) {
						ZEPHIR_INIT_NVAR(&_78$$49);
						ZVAL_LONG(&_78$$49, 11);
						zephir_array_update_zval(&fieldTypes, &columnName, &_78$$49, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_79$$49);
						ZVAL_LONG(&_79$$49, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_79$$49, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "boolean")) {
						ZEPHIR_INIT_NVAR(&_80$$50);
						ZVAL_LONG(&_80$$50, 8);
						zephir_array_update_zval(&fieldTypes, &columnName, &_80$$50, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_81$$50);
						ZVAL_LONG(&_81$$50, 5);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_81$$50, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "char")) {
						ZEPHIR_INIT_NVAR(&_82$$51);
						ZVAL_LONG(&_82$$51, 5);
						zephir_array_update_zval(&fieldTypes, &columnName, &_82$$51, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_83$$51);
						ZVAL_LONG(&_83$$51, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_83$$51, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "date")) {
						ZEPHIR_INIT_NVAR(&_84$$52);
						ZVAL_LONG(&_84$$52, 1);
						zephir_array_update_zval(&fieldTypes, &columnName, &_84$$52, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_85$$52);
						ZVAL_LONG(&_85$$52, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_85$$52, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "datetime")) {
						ZEPHIR_INIT_NVAR(&_86$$53);
						ZVAL_LONG(&_86$$53, 4);
						zephir_array_update_zval(&fieldTypes, &columnName, &_86$$53, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_87$$53);
						ZVAL_LONG(&_87$$53, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_87$$53, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "decimal")) {
						ZEPHIR_INIT_NVAR(&_88$$54);
						ZVAL_LONG(&_88$$54, 3);
						zephir_array_update_zval(&fieldTypes, &columnName, &_88$$54, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_89$$54);
						ZVAL_LONG(&_89$$54, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_89$$54, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "double")) {
						ZEPHIR_INIT_NVAR(&_90$$55);
						ZVAL_LONG(&_90$$55, 9);
						zephir_array_update_zval(&fieldTypes, &columnName, &_90$$55, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_91$$55);
						ZVAL_LONG(&_91$$55, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_91$$55, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "enum")) {
						ZEPHIR_INIT_NVAR(&_92$$56);
						ZVAL_LONG(&_92$$56, 18);
						zephir_array_update_zval(&fieldTypes, &columnName, &_92$$56, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_93$$56);
						ZVAL_LONG(&_93$$56, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_93$$56, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "float")) {
						ZEPHIR_INIT_NVAR(&_94$$57);
						ZVAL_LONG(&_94$$57, 7);
						zephir_array_update_zval(&fieldTypes, &columnName, &_94$$57, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_95$$57);
						ZVAL_LONG(&_95$$57, 32);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_95$$57, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "integer")) {
						ZEPHIR_INIT_NVAR(&_96$$58);
						ZVAL_LONG(&_96$$58, 0);
						zephir_array_update_zval(&fieldTypes, &columnName, &_96$$58, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_97$$58);
						ZVAL_LONG(&_97$$58, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_97$$58, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "json")) {
						ZEPHIR_INIT_NVAR(&_98$$59);
						ZVAL_LONG(&_98$$59, 15);
						zephir_array_update_zval(&fieldTypes, &columnName, &_98$$59, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_99$$59);
						ZVAL_LONG(&_99$$59, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_99$$59, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "jsonb")) {
						ZEPHIR_INIT_NVAR(&_100$$60);
						ZVAL_LONG(&_100$$60, 16);
						zephir_array_update_zval(&fieldTypes, &columnName, &_100$$60, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_101$$60);
						ZVAL_LONG(&_101$$60, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_101$$60, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "longblob")) {
						ZEPHIR_INIT_NVAR(&_102$$61);
						ZVAL_LONG(&_102$$61, 13);
						zephir_array_update_zval(&fieldTypes, &columnName, &_102$$61, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_103$$61);
						ZVAL_LONG(&_103$$61, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_103$$61, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "longtext")) {
						ZEPHIR_INIT_NVAR(&_104$$62);
						ZVAL_LONG(&_104$$62, 24);
						zephir_array_update_zval(&fieldTypes, &columnName, &_104$$62, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_105$$62);
						ZVAL_LONG(&_105$$62, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_105$$62, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "mediumblob")) {
						ZEPHIR_INIT_NVAR(&_106$$63);
						ZVAL_LONG(&_106$$63, 12);
						zephir_array_update_zval(&fieldTypes, &columnName, &_106$$63, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_107$$63);
						ZVAL_LONG(&_107$$63, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_107$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "mediumint")) {
						ZEPHIR_INIT_NVAR(&_108$$64);
						ZVAL_LONG(&_108$$64, 21);
						zephir_array_update_zval(&fieldTypes, &columnName, &_108$$64, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_109$$64);
						ZVAL_LONG(&_109$$64, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_109$$64, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "mediumtext")) {
						ZEPHIR_INIT_NVAR(&_110$$65);
						ZVAL_LONG(&_110$$65, 23);
						zephir_array_update_zval(&fieldTypes, &columnName, &_110$$65, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_111$$65);
						ZVAL_LONG(&_111$$65, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_111$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "smallint")) {
						ZEPHIR_INIT_NVAR(&_112$$66);
						ZVAL_LONG(&_112$$66, 22);
						zephir_array_update_zval(&fieldTypes, &columnName, &_112$$66, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_113$$66);
						ZVAL_LONG(&_113$$66, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_113$$66, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "text")) {
						ZEPHIR_INIT_NVAR(&_114$$67);
						ZVAL_LONG(&_114$$67, 6);
						zephir_array_update_zval(&fieldTypes, &columnName, &_114$$67, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_115$$67);
						ZVAL_LONG(&_115$$67, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_115$$67, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "time")) {
						ZEPHIR_INIT_NVAR(&_116$$68);
						ZVAL_LONG(&_116$$68, 20);
						zephir_array_update_zval(&fieldTypes, &columnName, &_116$$68, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_117$$68);
						ZVAL_LONG(&_117$$68, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_117$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "timestamp")) {
						ZEPHIR_INIT_NVAR(&_118$$69);
						ZVAL_LONG(&_118$$69, 17);
						zephir_array_update_zval(&fieldTypes, &columnName, &_118$$69, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_119$$69);
						ZVAL_LONG(&_119$$69, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_119$$69, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "tinyblob")) {
						ZEPHIR_INIT_NVAR(&_120$$70);
						ZVAL_LONG(&_120$$70, 10);
						zephir_array_update_zval(&fieldTypes, &columnName, &_120$$70, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_121$$70);
						ZVAL_LONG(&_121$$70, 3);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_121$$70, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "tinyint")) {
						ZEPHIR_INIT_NVAR(&_122$$71);
						ZVAL_LONG(&_122$$71, 26);
						zephir_array_update_zval(&fieldTypes, &columnName, &_122$$71, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_123$$71);
						ZVAL_LONG(&_123$$71, 1);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_123$$71, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&numericTyped, &columnName, &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_STRING(&feature, "tinytext")) {
						ZEPHIR_INIT_NVAR(&_124$$72);
						ZVAL_LONG(&_124$$72, 25);
						zephir_array_update_zval(&fieldTypes, &columnName, &_124$$72, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_125$$72);
						ZVAL_LONG(&_125$$72, 2);
						zephir_array_update_zval(&fieldBindTypes, &columnName, &_125$$72, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_126$$73);
					ZVAL_LONG(&_126$$73, 2);
					zephir_array_update_zval(&fieldTypes, &columnName, &_126$$73, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_127$$73);
					ZVAL_LONG(&_127$$73, 2);
					zephir_array_update_zval(&fieldBindTypes, &columnName, &_127$$73, PH_COPY | PH_SEPARATE);
				} while(0);

				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "Primary");
				ZEPHIR_CALL_METHOD(&_128$$44, &propAnnotations, "has", NULL, 0, &_73$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_128$$44)) {
					zephir_array_append(&primaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 331);
				} else {
					zephir_array_append(&nonPrimaryKeys, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 333);
				}
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "Identity");
				ZEPHIR_CALL_METHOD(&_129$$44, &propAnnotations, "has", NULL, 0, &_73$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_129$$44)) {
					ZEPHIR_CPY_WRT(&identityField, &columnName);
				}
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "skip_on_insert");
				ZEPHIR_CALL_METHOD(&_130$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_73$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_130$$44)) {
					zephir_array_append(&skipOnInsert, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 348);
				}
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "skip_on_update");
				ZEPHIR_CALL_METHOD(&_131$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_73$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_131$$44)) {
					zephir_array_append(&skipOnUpdate, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 355);
				}
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "allow_empty_string");
				ZEPHIR_CALL_METHOD(&_132$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_73$$44);
				zephir_check_call_status();
				if (zephir_is_true(&_132$$44)) {
					zephir_array_update_zval(&emptyStringValues, &columnName, &columnName, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "nullable");
				ZEPHIR_CALL_METHOD(&_133$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_73$$44);
				zephir_check_call_status();
				if (!(zephir_is_true(&_133$$44))) {
					zephir_array_append(&notNull, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 369);
				}
				ZEPHIR_INIT_NVAR(&_73$$44);
				ZVAL_STRING(&_73$$44, "default");
				ZEPHIR_CALL_METHOD(&defaultValue, &columnAnnotation, "getnamedparameter", NULL, 0, &_73$$44);
				zephir_check_call_status();
				_134$$44 = Z_TYPE_P(&defaultValue) != IS_NULL;
				if (!(_134$$44)) {
					ZEPHIR_INIT_NVAR(&_73$$44);
					ZVAL_STRING(&_73$$44, "nullable");
					ZEPHIR_CALL_METHOD(&_135$$44, &columnAnnotation, "getnamedparameter", NULL, 0, &_73$$44);
					zephir_check_call_status();
					_134$$44 = zephir_is_true(&_135$$44);
				}
				if (_134$$44) {
					zephir_array_update_zval(&defaultValues, &columnName, &defaultValue, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&attributes, &columnName, PH_SEPARATE, "phalcon/Mvc/Model/MetaData/Strategy/Annotations.zep", 381);
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

