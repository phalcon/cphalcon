
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * Phalcon\Mvc\Model\Validator\Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Collection;
 * use Phalcon\Mvc\Model\Validator\Uniqueness;
 *
 * class Subscriptors extends Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new Uniqueness(
 *                 [
 *                     "field"   => "email",
 *                     "message" => "Value of field 'email' is already present in another record",
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() === true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 * @deprecated 3.1.0
 * @see Phalcon\Validation\Validator\Uniqueness
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Uniqueness) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Uniqueness, phalcon, mvc_model_validator_uniqueness, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_uniqueness_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Uniqueness, validate) {

	zend_class_entry *_29;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *record, record_sub, field, dependencyInjector, metaData, message, bindTypes, bindDataTypes, columnMap, conditions, bindParams, composeField, columnField, bindType, primaryField, attributeField, params, className, replacePairs, _0, _17, _28, *_1$$5, _2$$8, _3$$8, _5$$10, _6$$10, _7$$6, _8$$6, _9$$6, _11$$13, _12$$13, _13$$15, _14$$15, _15$$11, _16$$11, _18$$16, *_19$$16, _20$$20, _21$$20, _22$$22, _23$$22, _24$$19, _25$$19, _26$$19, _30$$24, _32$$24, _31$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&composeField);
	ZVAL_UNDEF(&columnField);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&primaryField);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_22$$22);
	ZVAL_UNDEF(&_23$$22);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_30$$24);
	ZVAL_UNDEF(&_32$$24);
	ZVAL_UNDEF(&_31$$25);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_CALL_METHOD(&dependencyInjector, record, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "modelsMetadata");
	ZEPHIR_CALL_METHOD(&metaData, &dependencyInjector, "getshared", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getbindtypes", NULL, 0, record);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, record);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	number = 0;
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "field");
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&field) == IS_ARRAY) {
		zephir_is_iterable(&field, 0, "phalcon/mvc/model/validator/uniqueness.zep", 130);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _1$$5)
		{
			ZEPHIR_INIT_NVAR(&composeField);
			ZVAL_COPY(&composeField, _1$$5);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&columnField);
				if (!(zephir_array_isset_fetch(&columnField, &columnMap, &composeField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_2$$8);
					object_init_ex(&_2$$8, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_3$$8);
					ZEPHIR_CONCAT_SVS(&_3$$8, "Column '", &composeField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_2$$8, "__construct", &_4, 4, &_3$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_2$$8, "phalcon/mvc/model/validator/uniqueness.zep", 107 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&columnField, &composeField);
			}
			ZEPHIR_OBS_NVAR(&bindType);
			if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &columnField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_5$$10);
				object_init_ex(&_5$$10, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_6$$10);
				ZEPHIR_CONCAT_SVS(&_6$$10, "Column '", &columnField, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, &_5$$10, "__construct", &_4, 4, &_6$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$10, "phalcon/mvc/model/validator/uniqueness.zep", 117 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_SINIT_NVAR(_7$$6);
			ZVAL_LONG(&_7$$6, number);
			ZEPHIR_INIT_LNVAR(_8$$6);
			ZEPHIR_CONCAT_SVSV(&_8$$6, "[", &composeField, "] = ?", &_7$$6);
			zephir_array_append(&conditions, &_8$$6, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 123);
			ZEPHIR_CALL_METHOD(&_9$$6, record, "readattribute", &_10, 0, &composeField);
			zephir_check_call_status();
			zephir_array_append(&bindParams, &_9$$6, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 124);
			zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 125);
			number++;
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&composeField);
	} else {
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&columnField);
			if (!(zephir_array_isset_fetch(&columnField, &columnMap, &field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_11$$13);
				object_init_ex(&_11$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_12$$13);
				ZEPHIR_CONCAT_SVS(&_12$$13, "Column '", &field, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_11$$13, "__construct", &_4, 4, &_12$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$13, "phalcon/mvc/model/validator/uniqueness.zep", 137 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&columnField, &field);
		}
		ZEPHIR_OBS_NVAR(&bindType);
		if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &columnField, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_13$$15);
			object_init_ex(&_13$$15, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_14$$15);
			ZEPHIR_CONCAT_SVS(&_14$$15, "Column '", &columnField, "' isn't part of the table columns");
			ZEPHIR_CALL_METHOD(NULL, &_13$$15, "__construct", &_4, 4, &_14$$15);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$15, "phalcon/mvc/model/validator/uniqueness.zep", 147 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_15$$11);
		ZEPHIR_CONCAT_SVS(&_15$$11, "[", &field, "] = ?0");
		zephir_array_append(&conditions, &_15$$11, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 153);
		ZEPHIR_CALL_METHOD(&_16$$11, record, "readattribute", NULL, 0, &field);
		zephir_check_call_status();
		zephir_array_append(&bindParams, &_16$$11, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 154);
		zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 155);
		number++;
	}
	ZEPHIR_CALL_METHOD(&_17, record, "getoperationmade", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_17, 2)) {
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, record);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		ZEPHIR_CALL_METHOD(&_18$$16, &metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(&_18$$16, 0, "phalcon/mvc/model/validator/uniqueness.zep", 200);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_18$$16), _19$$16)
		{
			ZEPHIR_INIT_NVAR(&primaryField);
			ZVAL_COPY(&primaryField, _19$$16);
			ZEPHIR_OBS_NVAR(&bindType);
			if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_20$$20);
				object_init_ex(&_20$$20, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_21$$20);
				ZEPHIR_CONCAT_SVS(&_21$$20, "Column '", &primaryField, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, &_20$$20, "__construct", &_4, 4, &_21$$20);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_20$$20, "phalcon/mvc/model/validator/uniqueness.zep", 177 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_22$$22);
					object_init_ex(&_22$$22, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_23$$22);
					ZEPHIR_CONCAT_SVS(&_23$$22, "Column '", &primaryField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_22$$22, "__construct", &_4, 4, &_23$$22);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_22$$22, "phalcon/mvc/model/validator/uniqueness.zep", 185 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &primaryField);
			}
			ZEPHIR_SINIT_NVAR(_24$$19);
			ZVAL_LONG(&_24$$19, number);
			ZEPHIR_INIT_LNVAR(_25$$19);
			ZEPHIR_CONCAT_SVSV(&_25$$19, "[", &attributeField, "] <> ?", &_24$$19);
			zephir_array_append(&conditions, &_25$$19, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 194);
			ZEPHIR_CALL_METHOD(&_26$$19, record, "readattribute", &_27, 0, &primaryField);
			zephir_check_call_status();
			zephir_array_append(&bindParams, &_26$$19, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 195);
			zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 196);
			number++;
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	zephir_array_update_string(&params, SL("di"), &dependencyInjector, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_join_str(&_0, SL(" AND "), &conditions TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bindTypes"), &bindTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, record, 0 TSRMLS_CC);
	_29 = zephir_fetch_class(&className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_28, _29, "count", NULL, 0, &params);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(&_28, 0)) {
		ZEPHIR_INIT_VAR(&_30$$24);
		ZVAL_STRING(&_30$$24, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_30$$24);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		if (Z_TYPE_P(&field) == IS_ARRAY) {
			zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_31$$25);
			zephir_fast_join_str(&_31$$25, SL(", "), &field TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":fields"), &_31$$25, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_STRING(&message, "Value of fields: :fields are already present in another record");
			}
		} else {
			zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_STRING(&message, "Value of field: ':field' is already present in another record");
			}
		}
		ZEPHIR_CALL_FUNCTION(&_32$$24, "strtr", NULL, 22, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_30$$24);
		ZVAL_STRING(&_30$$24, "Unique");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_32$$24, &field, &_30$$24);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

