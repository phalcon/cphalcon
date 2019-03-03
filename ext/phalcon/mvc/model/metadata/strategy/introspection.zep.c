
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Introspection
 *
 * Queries the table meta-data in order to introspect the model's metadata
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Introspection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Introspection, phalcon, mvc_model_metadata_strategy_introspection, phalcon_mvc_model_metadata_strategy_introspection_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_metadata_strategy_introspection_ce TSRMLS_CC, 1, phalcon_mvc_model_metadata_strategyinterface_ce);
	return SUCCESS;

}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData) {

	zend_bool _15$$9, _24$$17;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *dependencyInjector, dependencyInjector_sub, __$true, schema, table, readConnection, columns, attributes, primaryKeys, nonPrimaryKeys, completeTable, numericTyped, notNull, fieldTypes, automaticDefault, identityField, fieldBindTypes, defaultValues, column, fieldName, defaultValue, emptyStringValues, _0, *_7, _8, _1$$3, _2$$3, _3$$3, _4$$6, _5$$6, _6$$6, _9$$9, _10$$9, _11$$9, _12$$9, _13$$9, _14$$9, _16$$9, _17$$15, _18$$17, _19$$17, _20$$17, _21$$17, _22$$17, _23$$17, _25$$17, _26$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&nonPrimaryKeys);
	ZVAL_UNDEF(&completeTable);
	ZVAL_UNDEF(&numericTyped);
	ZVAL_UNDEF(&notNull);
	ZVAL_UNDEF(&fieldTypes);
	ZVAL_UNDEF(&automaticDefault);
	ZVAL_UNDEF(&identityField);
	ZVAL_UNDEF(&fieldBindTypes);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&emptyStringValues);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$23);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&table, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, model, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &readConnection, "tableexists", NULL, 0, &table, &schema);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		if (zephir_is_true(&schema)) {
			ZEPHIR_INIT_VAR(&completeTable);
			ZEPHIR_CONCAT_VSV(&completeTable, &schema, "'.'", &table);
		} else {
			ZEPHIR_CPY_WRT(&completeTable, &table);
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, model, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVSV(&_3$$3, "Table '", &completeTable, "' doesn't exist in database when dumping meta-data for ", &_2$$3);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/mvc/model/metadata/strategy/introspection.zep", 60 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&columns, &readConnection, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&columns TSRMLS_CC))) {
		if (zephir_is_true(&schema)) {
			ZEPHIR_INIT_NVAR(&completeTable);
			ZEPHIR_CONCAT_VSV(&completeTable, &schema, "'.'", &table);
		} else {
			ZEPHIR_CPY_WRT(&completeTable, &table);
		}
		ZEPHIR_INIT_VAR(&_4$$6);
		object_init_ex(&_4$$6, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$6);
		zephir_get_class(&_5$$6, model, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$6);
		ZEPHIR_CONCAT_SVSV(&_6$$6, "Cannot obtain table columns for the mapped source '", &completeTable, "' used in model ", &_5$$6);
		ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 4, &_6$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$6, "phalcon/mvc/model/metadata/strategy/introspection.zep", 80 TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(&automaticDefault);
	array_init(&automaticDefault);
	ZEPHIR_INIT_VAR(&identityField);
	ZVAL_BOOL(&identityField, 0);
	ZEPHIR_INIT_VAR(&defaultValues);
	array_init(&defaultValues);
	ZEPHIR_INIT_VAR(&emptyStringValues);
	array_init(&emptyStringValues);
	zephir_is_iterable(&columns, 0, "phalcon/mvc/model/metadata/strategy/introspection.zep", 157);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _7)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _7);
			ZEPHIR_CALL_METHOD(&fieldName, &column, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&attributes, &fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 101);
			ZEPHIR_CALL_METHOD(&_9$$9, &column, "isprimary", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_9$$9)) {
				zephir_array_append(&primaryKeys, &fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 107);
			} else {
				zephir_array_append(&nonPrimaryKeys, &fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 109);
			}
			ZEPHIR_CALL_METHOD(&_10$$9, &column, "isnumeric", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_10$$9)) {
				zephir_array_update_zval(&numericTyped, &fieldName, &__$true, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_CALL_METHOD(&_11$$9, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_11$$9)) {
				zephir_array_append(&notNull, &fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 123);
			}
			ZEPHIR_CALL_METHOD(&_12$$9, &column, "isautoincrement", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_12$$9)) {
				ZEPHIR_CPY_WRT(&identityField, &fieldName);
			}
			ZEPHIR_CALL_METHOD(&_13$$9, &column, "gettype", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&fieldTypes, &fieldName, &_13$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_14$$9, &column, "getbindtype", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&fieldBindTypes, &fieldName, &_14$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
			zephir_check_call_status();
			_15$$9 = Z_TYPE_P(&defaultValue) != IS_NULL;
			if (!(_15$$9)) {
				ZEPHIR_CALL_METHOD(&_16$$9, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				_15$$9 = ZEPHIR_IS_FALSE_IDENTICAL(&_16$$9);
			}
			if (_15$$9) {
				ZEPHIR_CALL_METHOD(&_17$$15, &column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_17$$15))) {
					zephir_array_update_zval(&defaultValues, &fieldName, &defaultValue, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&fieldName, &column, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_append(&attributes, &fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 101);
				ZEPHIR_CALL_METHOD(&_18$$17, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_18$$17)) {
					zephir_array_append(&primaryKeys, &fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 107);
				} else {
					zephir_array_append(&nonPrimaryKeys, &fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 109);
				}
				ZEPHIR_CALL_METHOD(&_19$$17, &column, "isnumeric", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_19$$17)) {
					zephir_array_update_zval(&numericTyped, &fieldName, &__$true, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_CALL_METHOD(&_20$$17, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_20$$17)) {
					zephir_array_append(&notNull, &fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 123);
				}
				ZEPHIR_CALL_METHOD(&_21$$17, &column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_21$$17)) {
					ZEPHIR_CPY_WRT(&identityField, &fieldName);
				}
				ZEPHIR_CALL_METHOD(&_22$$17, &column, "gettype", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&fieldTypes, &fieldName, &_22$$17, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_23$$17, &column, "getbindtype", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&fieldBindTypes, &fieldName, &_23$$17, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
				zephir_check_call_status();
				_24$$17 = Z_TYPE_P(&defaultValue) != IS_NULL;
				if (!(_24$$17)) {
					ZEPHIR_CALL_METHOD(&_25$$17, &column, "isnotnull", NULL, 0);
					zephir_check_call_status();
					_24$$17 = ZEPHIR_IS_FALSE_IDENTICAL(&_25$$17);
				}
				if (_24$$17) {
					ZEPHIR_CALL_METHOD(&_26$$23, &column, "isautoincrement", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_26$$23))) {
						zephir_array_update_zval(&defaultValues, &fieldName, &defaultValue, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_create_array(return_value, 12, 0 TSRMLS_CC);
	zephir_array_update_long(return_value, 0, &attributes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 1, &primaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 2, &nonPrimaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 3, &notNull, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 4, &fieldTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 5, &numericTyped, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 8, &identityField, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 9, &fieldBindTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 10, &automaticDefault, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 11, &automaticDefault, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 12, &defaultValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(return_value, 13, &emptyStringValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	RETURN_MM();

}

/**
 * Read the model's column map, this can't be inferred
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *dependencyInjector, dependencyInjector_sub, orderedColumnMap, userColumnMap, reversedColumnMap, name, userName, *_0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&orderedColumnMap);
	ZVAL_UNDEF(&userColumnMap);
	ZVAL_UNDEF(&reversedColumnMap);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&userName);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	ZEPHIR_INIT_VAR(&orderedColumnMap);
	ZVAL_NULL(&orderedColumnMap);
	ZEPHIR_INIT_VAR(&reversedColumnMap);
	ZVAL_NULL(&reversedColumnMap);
	if ((zephir_method_exists_ex(model, SL("columnmap") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&userColumnMap, model, "columnmap", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&userColumnMap) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "columnMap() not returned an array", "phalcon/mvc/model/metadata/strategy/introspection.zep", 190);
			return;
		}
		ZEPHIR_INIT_NVAR(&reversedColumnMap);
		array_init(&reversedColumnMap);
		ZEPHIR_CPY_WRT(&orderedColumnMap, &userColumnMap);
		zephir_is_iterable(&userColumnMap, 0, "phalcon/mvc/model/metadata/strategy/introspection.zep", 197);
		if (Z_TYPE_P(&userColumnMap) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&userColumnMap), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&name, _3$$3);
				} else {
					ZVAL_LONG(&name, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&userName);
				ZVAL_COPY(&userName, _0$$3);
				zephir_array_update_zval(&reversedColumnMap, &userName, &name, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &userColumnMap, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &userColumnMap, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&name, &userColumnMap, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&userName, &userColumnMap, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_update_zval(&reversedColumnMap, &userName, &name, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &userColumnMap, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&userName);
		ZEPHIR_INIT_NVAR(&name);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &orderedColumnMap);
	zephir_array_fast_append(return_value, &reversedColumnMap);
	RETURN_MM();

}

