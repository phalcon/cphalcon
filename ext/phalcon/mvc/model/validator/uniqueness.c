
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


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 *class Subscriptors extends Phalcon\Mvc\Model
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

	int _8;
	zend_function *_5 = NULL, *_6 = NULL, *_7 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL;
	HashTable *_2, *_11;
	HashPosition _1, _10;
	zval *record, *field, *dependencyInjector, *metaData, *message = NULL, *bindTypes, *bindDataTypes, *columnMap, *conditions, *bindParams, *number = NULL, *composeField = NULL, *value = NULL, *columnField = NULL, *composeCondition = NULL, *bindType = NULL, *condition = NULL, *operationMade, *primaryFields, *primaryField = NULL, *attributeField = NULL, *joinConditions, *params, *className, *joinFields, *_0 = NULL, **_3, *_4 = NULL, *_9 = NULL, **_12, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", 1);
	ZEPHIR_INIT_VAR(field);
	zephir_call_method_p1(field, this_ptr, "getoption", _0);
	ZEPHIR_INIT_VAR(dependencyInjector);
	zephir_call_method(dependencyInjector, record, "getdi");
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "modelsMetadata", 1);
	ZEPHIR_INIT_VAR(metaData);
	zephir_call_method_p1(metaData, dependencyInjector, "getshared", _0);
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_INIT_VAR(bindDataTypes);
	zephir_call_method_p1(bindDataTypes, metaData, "getbindtypes", record);
	ZEPHIR_INIT_VAR(columnMap);
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		zephir_call_method_p1(columnMap, metaData, "getreversecolumnmap", record);
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
			; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			; zend_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(composeField, _3);
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				if (zephir_array_isset(columnMap, composeField)) {
					ZEPHIR_OBS_NVAR(columnField);
					zephir_array_fetch(&columnField, columnMap, composeField, PH_NOISY TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", composeField, "' isn't part of the column map");
					zephir_call_method_p1_cache_noret(_0, "__construct", &_5, _4);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(columnField, composeField);
			}
			if (!(zephir_array_isset(bindDataTypes, columnField))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Column '", columnField, "' isn't part of the table columns");
				zephir_call_method_p1_cache_noret(_0, "__construct", &_6, _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(value);
			zephir_call_method_p1_cache(value, record, "readattribute", &_7, composeField);
			ZEPHIR_INIT_NVAR(composeCondition);
			ZEPHIR_CONCAT_SVSV(composeCondition, "[", composeField, "] = ?", number);
			zephir_array_append(&conditions, composeCondition, PH_SEPARATE);
			zephir_array_append(&bindParams, value, PH_SEPARATE);
			ZEPHIR_OBS_NVAR(bindType);
			zephir_array_fetch(&bindType, bindDataTypes, columnField, PH_NOISY TSRMLS_CC);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
			_8 = (zephir_get_numberval(number) + 1);
			ZEPHIR_INIT_NVAR(number);
			ZVAL_LONG(number, _8);
		}
	} else {
		if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
			if (zephir_array_isset(columnMap, field)) {
				ZEPHIR_OBS_NVAR(columnField);
				zephir_array_fetch(&columnField, columnMap, field, PH_NOISY TSRMLS_CC);
			} else {
				ZEPHIR_INIT_BNVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_9);
				ZEPHIR_CONCAT_SVS(_9, "Column '", field, "' isn't part of the column map");
				zephir_call_method_p1_noret(_0, "__construct", _9);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(columnField, field);
		}
		if (!(zephir_array_isset(bindDataTypes, columnField))) {
			ZEPHIR_INIT_BNVAR(_0);
			object_init_ex(_0, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SVS(_9, "Column '", columnField, "' isn't part of the table columns");
			zephir_call_method_p1_noret(_0, "__construct", _9);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(value);
		zephir_call_method_p1(value, record, "readattribute", field);
		ZEPHIR_INIT_VAR(condition);
		ZEPHIR_CONCAT_SVS(condition, "[", field, "] = ?0");
		zephir_array_append(&conditions, condition, PH_SEPARATE);
		zephir_array_append(&bindParams, value, PH_SEPARATE);
		ZEPHIR_OBS_NVAR(bindType);
		zephir_array_fetch(&bindType, bindDataTypes, columnField, PH_NOISY TSRMLS_CC);
		zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
		_8 = (zephir_get_numberval(number) + 1);
		ZEPHIR_INIT_BNVAR(number);
		ZVAL_LONG(number, _8);
	}
	ZEPHIR_INIT_VAR(operationMade);
	zephir_call_method(operationMade, record, "getoperationmade");
	if (ZEPHIR_IS_LONG(operationMade, 2)) {
		ZEPHIR_INIT_BNVAR(columnMap);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			zephir_call_method_p1(columnMap, metaData, "getcolumnmap", record);
		} else {
			ZVAL_NULL(columnMap);
		}
		ZEPHIR_INIT_VAR(primaryFields);
		zephir_call_method_p1(primaryFields, metaData, "getprimarykeyattributes", record);
		zephir_is_iterable(primaryFields, &_11, &_10, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
			; zend_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _12);
			if (!(zephir_array_isset(bindDataTypes, primaryField))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_SVS(_13, "Column '", primaryField, "' isn't part of the table columns");
				zephir_call_method_p1_cache_noret(_0, "__construct", &_14, _13);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				if (zephir_array_isset(columnMap, primaryField)) {
					ZEPHIR_OBS_NVAR(attributeField);
					zephir_array_fetch(&attributeField, columnMap, primaryField, PH_NOISY TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", primaryField, "' isn't part of the column map");
					zephir_call_method_p1_cache_noret(_0, "__construct", &_15, _4);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, primaryField);
			}
			ZEPHIR_INIT_NVAR(value);
			zephir_call_method_p1_cache(value, record, "readattribute", &_16, primaryField);
			ZEPHIR_INIT_NVAR(condition);
			ZEPHIR_CONCAT_VSV(condition, attributeField, "] <> ?", number);
			zephir_array_append(&conditions, condition, PH_SEPARATE);
			zephir_array_append(&bindParams, value, PH_SEPARATE);
			ZEPHIR_OBS_NVAR(bindType);
			zephir_array_fetch(&bindType, bindDataTypes, primaryField, PH_NOISY TSRMLS_CC);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
			_8 = (zephir_get_numberval(number) + 1);
			ZEPHIR_INIT_NVAR(number);
			ZVAL_LONG(number, _8);
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
	zephir_call_func_p1(className, "get_class", record);
	ZEPHIR_INIT_BNVAR(number);
	ZVAL_NULL(number);
	if (!ZEPHIR_IS_LONG(number, 0)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _0);
		if (!(zephir_is_true(message))) {
			ZEPHIR_INIT_NVAR(message);
			if ((Z_TYPE_P(field) == IS_ARRAY)) {
				ZEPHIR_INIT_VAR(joinFields);
				zephir_fast_join_str(joinFields, SL(", "), field TSRMLS_CC);
				ZEPHIR_CONCAT_SVS(message, "Value of fields: '", joinFields, "' are already present in another record");
			} else {
				ZEPHIR_CONCAT_SVS(message, "Value of field: '", field, "' is already present in another record");
			}
		}
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "Unique", 1);
		zephir_call_method_p3_noret(this_ptr, "appendmessage", message, field, _0);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

