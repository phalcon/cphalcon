
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

	zephir_nts_static zephir_fcall_cache_entry *_23 = NULL;
	zend_class_entry *_21;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_18 = NULL, *_19 = NULL;
	HashTable *_2, *_14;
	HashPosition _1, _13;
	int number, ZEPHIR_LAST_CALL_STATUS;
	zval *record, *field = NULL, *dependencyInjector = NULL, *metaData = NULL, *message = NULL, *bindTypes, *bindDataTypes = NULL, *columnMap = NULL, *conditions, *bindParams, *composeField = NULL, *columnField = NULL, *bindType = NULL, *primaryField = NULL, *attributeField = NULL, *params, *className, *replacePairs = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL, _8 = zval_used_for_init, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, **_15, *_16 = NULL, *_17 = NULL, *_20 = NULL, *_22 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	if (!(zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'record' must be an instance of 'Phalcon\\Mvc\\ModelInterface'");
		return;
	}
	ZEPHIR_CALL_METHOD(&dependencyInjector, record, "getdi",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "modelsMetadata", 0);
	ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, record);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(columnMap);
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, record);
		zephir_check_call_status();
	} else {
		ZVAL_NULL(columnMap);
	}
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	number = 0;
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "field", 0);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(composeField, _3);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(columnField);
				if (!(zephir_array_isset_fetch(&columnField, columnMap, composeField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", composeField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
					zephir_check_call_status();
					zephir_throw_exception(_4 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(columnField, composeField);
			}
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, columnField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "Column '", columnField, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_7, _5);
				zephir_check_call_status();
				zephir_throw_exception(_4 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, number);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSV(_4, "[", composeField, "] = ?", &_8);
			zephir_array_append(&conditions, _4, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_9, record, "readattribute", NULL, composeField);
			zephir_check_call_status();
			zephir_array_append(&bindParams, _9, PH_SEPARATE);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
			number++;
		}
	} else {
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(columnField);
			if (!(zephir_array_isset_fetch(&columnField, columnMap, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_10);
				object_init_ex(_10, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_11);
				ZEPHIR_CONCAT_SVS(_11, "Column '", field, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, _11);
				zephir_check_call_status();
				zephir_throw_exception(_10 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(columnField, field);
		}
		if (!(zephir_array_isset(bindDataTypes, columnField))) {
			ZEPHIR_INIT_LNVAR(_10);
			object_init_ex(_10, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SVS(_11, "Column '", columnField, "' isn't part of the table columns");
			ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, _11);
			zephir_check_call_status();
			zephir_throw_exception(_10 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_SVS(_10, "[", field, "] = ?0");
		zephir_array_append(&conditions, _10, PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_9, record, "readattribute", NULL, field);
		zephir_check_call_status();
		zephir_array_append(&bindParams, _9, PH_SEPARATE);
		ZEPHIR_OBS_NVAR(bindType);
		zephir_array_fetch(&bindType, bindDataTypes, columnField, PH_NOISY TSRMLS_CC);
		zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
		number++;
	}
	ZEPHIR_CALL_METHOD(&_12, record, "getoperationmade",  NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_12, 2)) {
		ZEPHIR_INIT_BNVAR(columnMap);
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, record);
			zephir_check_call_status();
		} else {
			ZVAL_NULL(columnMap);
		}
		ZEPHIR_CALL_METHOD(&_9, metaData, "getprimarykeyattributes", NULL, record);
		zephir_check_call_status();
		zephir_is_iterable(_9, &_14, &_13, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
		  ; zephir_hash_move_forward_ex(_14, &_13)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _15);
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, primaryField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_16);
				object_init_ex(_16, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_17);
				ZEPHIR_CONCAT_SVS(_17, "Column '", primaryField, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _16, "__construct", &_18, _17);
				zephir_check_call_status();
				zephir_throw_exception(_16 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, primaryField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_10);
					object_init_ex(_10, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_11);
					ZEPHIR_CONCAT_SVS(_11, "Column '", primaryField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _10, "__construct", &_19, _11);
					zephir_check_call_status();
					zephir_throw_exception(_10 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, primaryField);
			}
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, number);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSV(_4, "[", attributeField, "] <> ?", &_8);
			zephir_array_append(&conditions, _4, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_20, record, "readattribute", NULL, primaryField);
			zephir_check_call_status();
			zephir_array_append(&bindParams, _20, PH_SEPARATE);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
			number++;
		}
	}
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	zephir_array_update_string(&params, SL("di"), &dependencyInjector, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_0);
	zephir_fast_join_str(_0, SL(" AND "), conditions TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bindTypes"), &bindTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	_21 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_9, _21, "count", NULL, params);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(_9, 0)) {
		ZEPHIR_INIT_VAR(_22);
		ZVAL_STRING(_22, "message", 0);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _22);
		zephir_check_temp_parameter(_22);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(message);
			if (Z_TYPE_P(field) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(replacePairs);
				array_init_size(replacePairs, 2);
				ZEPHIR_INIT_NVAR(_22);
				zephir_fast_join_str(_22, SL(", "), field TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":fields"), &_22, PH_COPY | PH_SEPARATE);
				ZVAL_STRING(message, "Value of fields :fields are already present in another record", 1);
			} else {
				ZVAL_STRING(message, "Value of field :field is already present in another record", 1);
			}
		}
		ZEPHIR_CALL_FUNCTION(&_9, "strtr", &_23, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_STRING(_22, "Unique", 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, _9, field, _22);
		zephir_check_temp_parameter(_22);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

