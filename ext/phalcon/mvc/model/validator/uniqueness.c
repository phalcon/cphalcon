
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"


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
/**
 * Phalcon\Mvc\Model\Validator\Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Uniqueness as Uniqueness;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new Uniqueness(array(
 *          "field" => 'email'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Uniqueness) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Uniqueness, phalcon, mvc_model_validator_uniqueness, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_uniqueness_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_uniqueness_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Uniqueness, validate) {

	zend_function *_6 = NULL, *_7 = NULL, *_8 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL;
	HashTable *_2, *_12;
	HashPosition _1, _11;
	int ZEPHIR_LAST_CALL_STATUS, _9;
	zval *record, *field, *dependencyInjector, *metaData, *message = NULL, *bindTypes, *bindDataTypes, *columnMap, *conditions, *bindParams, *number = NULL, *composeField = NULL, *value = NULL, *columnField = NULL, *composeCondition = NULL, *bindType = NULL, *condition, *operationMade, *primaryFields, *primaryField = NULL, *attributeField = NULL, *joinConditions, *params, *className, *replacePairs = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL, *_10 = NULL, **_13, *_14 = NULL, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	if (!(zephir_is_instance_of(record, SL("Phalcon\\Mvc\\ModelInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'record' must be an instance of 'Phalcon\\Mvc\\ModelInterface'");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", 1);
	ZEPHIR_INIT_VAR(field);
	zephir_call_method_p1(field, this_ptr, "getoption", _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(dependencyInjector);
	zephir_call_method(dependencyInjector, record, "getdi");
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "modelsMetadata", 1);
	ZEPHIR_INIT_VAR(metaData);
	zephir_call_method_p1(metaData, dependencyInjector, "getshared", _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_INIT_VAR(bindDataTypes);
	zephir_call_method_p1(bindDataTypes, metaData, "getbindtypes", record);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(columnMap);
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		zephir_call_method_p1(columnMap, metaData, "getreversecolumnmap", record);
		zephir_check_call_status();
	} else {
		ZVAL_NULL(columnMap);
	}
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(number);
	ZVAL_LONG(number, 0);
	if ((Z_TYPE_P(field) == IS_ARRAY)) {
		zephir_is_iterable(field, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(composeField, _3);
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				if (zephir_array_isset(columnMap, composeField)) {
					ZEPHIR_OBS_NVAR(columnField);
					zephir_array_fetch(&columnField, columnMap, composeField, PH_NOISY TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", composeField, "' isn't part of the column map");
					zephir_call_method_p1_cache_noret(_4, "__construct", &_6, _5);
					zephir_check_call_status();
					zephir_throw_exception(_4 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(columnField, composeField);
			}
			if (!(zephir_array_isset(bindDataTypes, columnField))) {
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "Column '", columnField, "' isn't part of the table columns");
				zephir_call_method_p1_cache_noret(_4, "__construct", &_7, _5);
				zephir_check_call_status();
				zephir_throw_exception(_4 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(value);
			zephir_call_method_p1_cache(value, record, "readattribute", &_8, composeField);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(composeCondition);
			ZEPHIR_CONCAT_SVSV(composeCondition, "[", composeField, "] = ?", number);
			zephir_array_append(&conditions, composeCondition, PH_SEPARATE);
			zephir_array_append(&bindParams, value, PH_SEPARATE);
			ZEPHIR_OBS_NVAR(bindType);
			zephir_array_fetch(&bindType, bindDataTypes, columnField, PH_NOISY TSRMLS_CC);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
			_9 = (zephir_get_numberval(number) + 1);
			ZEPHIR_INIT_NVAR(number);
			ZVAL_LONG(number, _9);
		}
	} else {
		if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
			if (zephir_array_isset(columnMap, field)) {
				ZEPHIR_OBS_NVAR(columnField);
				zephir_array_fetch(&columnField, columnMap, field, PH_NOISY TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_10);
				ZEPHIR_CONCAT_SVS(_10, "Column '", field, "' isn't part of the column map");
				zephir_call_method_p1_noret(_4, "__construct", _10);
				zephir_check_call_status();
				zephir_throw_exception(_4 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(columnField, field);
		}
		if (!(zephir_array_isset(bindDataTypes, columnField))) {
			ZEPHIR_INIT_LNVAR(_4);
			object_init_ex(_4, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVS(_10, "Column '", columnField, "' isn't part of the table columns");
			zephir_call_method_p1_noret(_4, "__construct", _10);
			zephir_check_call_status();
			zephir_throw_exception(_4 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(value);
		zephir_call_method_p1(value, record, "readattribute", field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(condition);
		ZEPHIR_CONCAT_SVS(condition, "[", field, "] = ?0");
		zephir_array_append(&conditions, condition, PH_SEPARATE);
		zephir_array_append(&bindParams, value, PH_SEPARATE);
		ZEPHIR_OBS_NVAR(bindType);
		zephir_array_fetch(&bindType, bindDataTypes, columnField, PH_NOISY TSRMLS_CC);
		zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
		_9 = (zephir_get_numberval(number) + 1);
		ZEPHIR_INIT_BNVAR(number);
		ZVAL_LONG(number, _9);
	}
	ZEPHIR_INIT_VAR(operationMade);
	zephir_call_method(operationMade, record, "getoperationmade");
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(operationMade, 2)) {
		ZEPHIR_INIT_BNVAR(columnMap);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			zephir_call_method_p1(columnMap, metaData, "getcolumnmap", record);
			zephir_check_call_status();
		} else {
			ZVAL_NULL(columnMap);
		}
		ZEPHIR_INIT_VAR(primaryFields);
		zephir_call_method_p1(primaryFields, metaData, "getprimarykeyattributes", record);
		zephir_check_call_status();
		zephir_is_iterable(primaryFields, &_12, &_11, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _13);
			if (!(zephir_array_isset(bindDataTypes, primaryField))) {
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_14);
				ZEPHIR_CONCAT_SVS(_14, "Column '", primaryField, "' isn't part of the table columns");
				zephir_call_method_p1_cache_noret(_4, "__construct", &_15, _14);
				zephir_check_call_status();
				zephir_throw_exception(_4 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				if (zephir_array_isset(columnMap, primaryField)) {
					ZEPHIR_OBS_NVAR(attributeField);
					zephir_array_fetch(&attributeField, columnMap, primaryField, PH_NOISY TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", primaryField, "' isn't part of the column map");
					zephir_call_method_p1_cache_noret(_4, "__construct", &_16, _5);
					zephir_check_call_status();
					zephir_throw_exception(_4 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, primaryField);
			}
			ZEPHIR_INIT_NVAR(value);
			zephir_call_method_p1_cache(value, record, "readattribute", &_17, primaryField);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSV(_4, "[", attributeField, "] <> ?", number);
			zephir_array_append(&conditions, _4, PH_SEPARATE);
			zephir_array_append(&bindParams, value, PH_SEPARATE);
			ZEPHIR_OBS_NVAR(bindType);
			zephir_array_fetch(&bindType, bindDataTypes, primaryField, PH_NOISY TSRMLS_CC);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
			_9 = (zephir_get_numberval(number) + 1);
			ZEPHIR_INIT_NVAR(number);
			ZVAL_LONG(number, _9);
		}
	}
	ZEPHIR_INIT_VAR(joinConditions);
	zephir_fast_join_str(joinConditions, SL(" AND "), conditions TSRMLS_CC);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	zephir_array_update_string(&params, SL("di"), &dependencyInjector, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("conditions"), &joinConditions, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bindTypes"), &bindTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(number);
	ZVAL_NULL(number);
	if (!ZEPHIR_IS_LONG(number, 0)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(message);
			if ((Z_TYPE_P(field) == IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(replacePairs);
				array_init_size(replacePairs, 2);
				ZEPHIR_INIT_BNVAR(_0);
				zephir_fast_join_str(_0, SL(", "), field TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":fields"), &_0, PH_COPY | PH_SEPARATE);
				ZVAL_STRING(message, "Value of fields :fields are already present in another record", 1);
			} else {
				ZVAL_STRING(message, "Value of field :field is already present in another record", 1);
			}
		}
		ZEPHIR_INIT_BNVAR(_0);
		zephir_call_func_p2(_0, "strtr", message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_18);
		ZVAL_STRING(_18, "Unique", 1);
		zephir_call_method_p3_noret(this_ptr, "appendmessage", _0, field, _18);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

