
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

	HashTable *_2$$5, *_22$$16;
	HashPosition _1$$5, _21$$16;
	zend_class_entry *_33;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *record, *field = NULL, *dependencyInjector = NULL, *metaData = NULL, *message = NULL, *bindTypes = NULL, *bindDataTypes = NULL, *columnMap = NULL, *conditions = NULL, *bindParams = NULL, *composeField = NULL, *columnField = NULL, *bindType = NULL, *primaryField = NULL, *attributeField = NULL, *params = NULL, *className = NULL, *replacePairs = NULL, *_0 = NULL, *_19 = NULL, *_32 = NULL, **_3$$5, *_4$$8 = NULL, *_5$$8 = NULL, *_7$$10 = NULL, *_8$$10 = NULL, _9$$6 = zval_used_for_init, *_10$$6 = NULL, *_11$$6 = NULL, *_13$$13, *_14$$13, *_15$$15, *_16$$15, *_17$$11, *_18$$11 = NULL, *_20$$16 = NULL, **_23$$16, *_24$$20 = NULL, *_25$$20 = NULL, *_26$$22 = NULL, *_27$$22 = NULL, _28$$19 = zval_used_for_init, *_29$$19 = NULL, *_30$$19 = NULL, *_34$$24 = NULL, *_36$$24 = NULL, *_35$$25;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_CALL_METHOD(&dependencyInjector, record, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, record);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, 0, record);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	number = 0;
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "field", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, &_2$$5, &_1$$5, 0, 0, "phalcon/mvc/model/validator/uniqueness.zep", 130);
		for (
		  ; zend_hash_get_current_data_ex(_2$$5, (void**) &_3$$5, &_1$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$5, &_1$$5)
		) {
			ZEPHIR_GET_HVALUE(composeField, _3$$5);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(columnField);
				if (!(zephir_array_isset_fetch(&columnField, columnMap, composeField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_4$$8);
					object_init_ex(_4$$8, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5$$8);
					ZEPHIR_CONCAT_SVS(_5$$8, "Column '", composeField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4$$8, "__construct", &_6, 9, _5$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4$$8, "phalcon/mvc/model/validator/uniqueness.zep", 107 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(columnField, composeField);
			}
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, columnField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_7$$10);
				object_init_ex(_7$$10, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_8$$10);
				ZEPHIR_CONCAT_SVS(_8$$10, "Column '", columnField, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _7$$10, "__construct", &_6, 9, _8$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7$$10, "phalcon/mvc/model/validator/uniqueness.zep", 117 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_SINIT_NVAR(_9$$6);
			ZVAL_LONG(&_9$$6, number);
			ZEPHIR_INIT_LNVAR(_10$$6);
			ZEPHIR_CONCAT_SVSV(_10$$6, "[", composeField, "] = ?", &_9$$6);
			zephir_array_append(&conditions, _10$$6, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 123);
			ZEPHIR_CALL_METHOD(&_11$$6, record, "readattribute", &_12, 0, composeField);
			zephir_check_call_status();
			zephir_array_append(&bindParams, _11$$6, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 124);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 125);
			number++;
		}
	} else {
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(columnField);
			if (!(zephir_array_isset_fetch(&columnField, columnMap, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_13$$13);
				object_init_ex(_13$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_14$$13);
				ZEPHIR_CONCAT_SVS(_14$$13, "Column '", field, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _13$$13, "__construct", &_6, 9, _14$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_13$$13, "phalcon/mvc/model/validator/uniqueness.zep", 137 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(columnField, field);
		}
		ZEPHIR_OBS_NVAR(bindType);
		if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, columnField, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_15$$15);
			object_init_ex(_15$$15, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(_16$$15);
			ZEPHIR_CONCAT_SVS(_16$$15, "Column '", columnField, "' isn't part of the table columns");
			ZEPHIR_CALL_METHOD(NULL, _15$$15, "__construct", &_6, 9, _16$$15);
			zephir_check_call_status();
			zephir_throw_exception_debug(_15$$15, "phalcon/mvc/model/validator/uniqueness.zep", 147 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(_17$$11);
		ZEPHIR_CONCAT_SVS(_17$$11, "[", field, "] = ?0");
		zephir_array_append(&conditions, _17$$11, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 153);
		ZEPHIR_CALL_METHOD(&_18$$11, record, "readattribute", NULL, 0, field);
		zephir_check_call_status();
		zephir_array_append(&bindParams, _18$$11, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 154);
		zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 155);
		number++;
	}
	ZEPHIR_CALL_METHOD(&_19, record, "getoperationmade", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_19, 2)) {
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, record);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		ZEPHIR_CALL_METHOD(&_20$$16, metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(_20$$16, &_22$$16, &_21$$16, 0, 0, "phalcon/mvc/model/validator/uniqueness.zep", 200);
		for (
		  ; zend_hash_get_current_data_ex(_22$$16, (void**) &_23$$16, &_21$$16) == SUCCESS
		  ; zend_hash_move_forward_ex(_22$$16, &_21$$16)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _23$$16);
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, primaryField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_24$$20);
				object_init_ex(_24$$20, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_25$$20);
				ZEPHIR_CONCAT_SVS(_25$$20, "Column '", primaryField, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _24$$20, "__construct", &_6, 9, _25$$20);
				zephir_check_call_status();
				zephir_throw_exception_debug(_24$$20, "phalcon/mvc/model/validator/uniqueness.zep", 177 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, primaryField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_26$$22);
					object_init_ex(_26$$22, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_27$$22);
					ZEPHIR_CONCAT_SVS(_27$$22, "Column '", primaryField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _26$$22, "__construct", &_6, 9, _27$$22);
					zephir_check_call_status();
					zephir_throw_exception_debug(_26$$22, "phalcon/mvc/model/validator/uniqueness.zep", 185 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, primaryField);
			}
			ZEPHIR_SINIT_NVAR(_28$$19);
			ZVAL_LONG(&_28$$19, number);
			ZEPHIR_INIT_LNVAR(_29$$19);
			ZEPHIR_CONCAT_SVSV(_29$$19, "[", attributeField, "] <> ?", &_28$$19);
			zephir_array_append(&conditions, _29$$19, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 194);
			ZEPHIR_CALL_METHOD(&_30$$19, record, "readattribute", &_31, 0, primaryField);
			zephir_check_call_status();
			zephir_array_append(&bindParams, _30$$19, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 195);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 196);
			number++;
		}
	}
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	zephir_array_update_string(&params, SL("di"), &dependencyInjector, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_join_str(_0, SL(" AND "), conditions TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bindTypes"), &bindTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	_33 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_32, _33, "count", NULL, 0, params);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(_32, 0)) {
		ZEPHIR_INIT_VAR(_34$$24);
		ZVAL_STRING(_34$$24, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _34$$24);
		zephir_check_temp_parameter(_34$$24);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		if (Z_TYPE_P(field) == IS_ARRAY) {
			zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_35$$25);
			zephir_fast_join_str(_35$$25, SL(", "), field TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":fields"), &_35$$25, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of fields: :fields are already present in another record", 1);
			}
		} else {
			zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field: ':field' is already present in another record", 1);
			}
		}
		ZEPHIR_CALL_FUNCTION(&_36$$24, "strtr", NULL, 27, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_34$$24);
		ZVAL_STRING(_34$$24, "Unique", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, _36$$24, field, _34$$24);
		zephir_check_temp_parameter(_34$$24);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

