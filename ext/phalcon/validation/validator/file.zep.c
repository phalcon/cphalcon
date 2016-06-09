
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\File
 *
 * Checks if a value has a correct file
 *
 *<code>
 *use Phalcon\Validation\Validator\File as FileValidator;
 *
 *$validator->add('file', new FileValidator(array(
 *   'maxSize' => '2M',
 *   'messageSize' => ':field exceeds the max filesize (:max)',
 *   'allowedTypes' => array('image/jpeg', 'image/png'),
 *   'messageType' => 'Allowed file types are :types',
 *   'maxResolution' => '800x600',
 *   'messageMaxResolution' => 'Max resolution of :field is :max'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, File, phalcon, validation_validator_file, phalcon_validation_validator_ce, phalcon_validation_validator_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File, validate) {

	zend_bool _2, _3, _4, _6, _7, _16, _17, _19, _27, _28, _62, _69$$20, _78$$25;
	zephir_fcall_cache_entry *_12 = NULL, *_15 = NULL, *_41 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, _SERVER, _POST, _FILES, value, message, label, replacePairs, types, byteUnits, unit, maxSize, matches, bytes, mime, tmp, width, height, minResolution, maxResolution, minWidth, maxWidth, minHeight, maxHeight, _0, _1, _5, _8, _18, _20, _21, _34, _52, _61, _63, _9$$4, _11$$4, _13$$4, _14$$4, _10$$5, _22$$6, _24$$6, _25$$6, _26$$6, _23$$7, _29$$8, _31$$8, _32$$8, _33$$8, _30$$9, _35$$10, _36$$10, _37$$10, _38$$10, _39$$10, _40$$10, _42$$10, _43$$10, _44$$10, _45$$10, _46$$10, _47$$12, _49$$12, _50$$12, _51$$12, _48$$13, _53$$14, _54$$16, _55$$16, _56$$18, _58$$18, _59$$18, _60$$18, _57$$19, _64$$20, _65$$20, _66$$20, _75$$20, _67$$21, _68$$21, _70$$23, _71$$23, _73$$23, _74$$23, _72$$24, _76$$25, _77$$25, _79$$26, _80$$26, _82$$26, _83$$26, _81$$27;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&byteUnits);
	ZVAL_UNDEF(&unit);
	ZVAL_UNDEF(&maxSize);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&minResolution);
	ZVAL_UNDEF(&maxResolution);
	ZVAL_UNDEF(&minWidth);
	ZVAL_UNDEF(&maxWidth);
	ZVAL_UNDEF(&minHeight);
	ZVAL_UNDEF(&maxHeight);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_63);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$12);
	ZVAL_UNDEF(&_49$$12);
	ZVAL_UNDEF(&_50$$12);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_53$$14);
	ZVAL_UNDEF(&_54$$16);
	ZVAL_UNDEF(&_55$$16);
	ZVAL_UNDEF(&_56$$18);
	ZVAL_UNDEF(&_58$$18);
	ZVAL_UNDEF(&_59$$18);
	ZVAL_UNDEF(&_60$$18);
	ZVAL_UNDEF(&_57$$19);
	ZVAL_UNDEF(&_64$$20);
	ZVAL_UNDEF(&_65$$20);
	ZVAL_UNDEF(&_66$$20);
	ZVAL_UNDEF(&_75$$20);
	ZVAL_UNDEF(&_67$$21);
	ZVAL_UNDEF(&_68$$21);
	ZVAL_UNDEF(&_70$$23);
	ZVAL_UNDEF(&_71$$23);
	ZVAL_UNDEF(&_73$$23);
	ZVAL_UNDEF(&_74$$23);
	ZVAL_UNDEF(&_72$$24);
	ZVAL_UNDEF(&_76$$25);
	ZVAL_UNDEF(&_77$$25);
	ZVAL_UNDEF(&_79$$26);
	ZVAL_UNDEF(&_80$$26);
	ZVAL_UNDEF(&_82$$26);
	ZVAL_UNDEF(&_83$$26);
	ZVAL_UNDEF(&_81$$27);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "label");
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_1, &_SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
	_2 = ZEPHIR_IS_STRING(&_1, "POST");
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(&_POST);
	}
	_3 = _2;
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(&_FILES);
	}
	_4 = _3;
	if (_4) {
		zephir_array_fetch_string(&_5, &_SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
		_4 = ZEPHIR_GT_LONG(&_5, 0);
	}
	_6 = _4;
	if (!(_6)) {
		_7 = zephir_array_isset_string(&value, SL("error"));
		if (_7) {
			zephir_array_fetch_string(&_8, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
			_7 = ZEPHIR_IS_LONG_IDENTICAL(&_8, 1);
		}
		_6 = _7;
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "messageIniSize");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_9$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_10$$5);
			ZVAL_STRING(&_10$$5, "FileIniSize");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_10$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_9$$4);
		object_init_ex(&_9$$4, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_11$$4, "strtr", &_12, 55, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "code");
		ZEPHIR_CALL_METHOD(&_13$$4, this_ptr, "getoption", NULL, 0, &_14$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "FileIniSize");
		ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", &_15, 461, &_11$$4, &field, &_14$$4, &_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_9$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_16 = !(zephir_array_isset_string(&value, SL("error")));
	if (!(_16)) {
		_16 = !(zephir_array_isset_string(&value, SL("tmp_name")));
	}
	_17 = _16;
	if (!(_17)) {
		zephir_array_fetch_string(&_18, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 75 TSRMLS_CC);
		_17 = !ZEPHIR_IS_LONG_IDENTICAL(&_18, 0);
	}
	_19 = _17;
	if (!(_19)) {
		zephir_array_fetch_string(&_20, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 75 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_21, "is_uploaded_file", NULL, 242, &_20);
		zephir_check_call_status();
		_19 = !zephir_is_true(&_21);
	}
	if (_19) {
		ZEPHIR_INIT_VAR(&_22$$6);
		ZVAL_STRING(&_22$$6, "messageEmpty");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_22$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_23$$7);
			ZVAL_STRING(&_23$$7, "FileEmpty");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_23$$7);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_22$$6);
		object_init_ex(&_22$$6, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_24$$6, "strtr", &_12, 55, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_26$$6);
		ZVAL_STRING(&_26$$6, "code");
		ZEPHIR_CALL_METHOD(&_25$$6, this_ptr, "getoption", NULL, 0, &_26$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_26$$6);
		ZVAL_STRING(&_26$$6, "FileEmpty");
		ZEPHIR_CALL_METHOD(NULL, &_22$$6, "__construct", &_15, 461, &_24$$6, &field, &_26$$6, &_25$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_22$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_27 = !(zephir_array_isset_string(&value, SL("name")));
	if (!(_27)) {
		_27 = !(zephir_array_isset_string(&value, SL("type")));
	}
	_28 = _27;
	if (!(_28)) {
		_28 = !(zephir_array_isset_string(&value, SL("size")));
	}
	if (_28) {
		ZEPHIR_INIT_VAR(&_29$$8);
		ZVAL_STRING(&_29$$8, "messageValid");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_29$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_30$$9);
			ZVAL_STRING(&_30$$9, "FileValid");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_30$$9);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_29$$8);
		object_init_ex(&_29$$8, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_31$$8, "strtr", &_12, 55, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_33$$8);
		ZVAL_STRING(&_33$$8, "code");
		ZEPHIR_CALL_METHOD(&_32$$8, this_ptr, "getoption", NULL, 0, &_33$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_33$$8);
		ZVAL_STRING(&_33$$8, "FileValid");
		ZEPHIR_CALL_METHOD(NULL, &_29$$8, "__construct", &_15, 461, &_31$$8, &field, &_33$$8, &_32$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_29$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "maxSize");
	ZEPHIR_CALL_METHOD(&_34, this_ptr, "hasoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_34)) {
		ZEPHIR_INIT_VAR(&byteUnits);
		zephir_create_array(&byteUnits, 9, 0 TSRMLS_CC);
		add_assoc_long_ex(&byteUnits, SL("B"), 0);
		add_assoc_long_ex(&byteUnits, SL("K"), 10);
		add_assoc_long_ex(&byteUnits, SL("M"), 20);
		add_assoc_long_ex(&byteUnits, SL("G"), 30);
		add_assoc_long_ex(&byteUnits, SL("T"), 40);
		add_assoc_long_ex(&byteUnits, SL("KB"), 10);
		add_assoc_long_ex(&byteUnits, SL("MB"), 20);
		add_assoc_long_ex(&byteUnits, SL("GB"), 30);
		add_assoc_long_ex(&byteUnits, SL("TB"), 40);
		ZEPHIR_INIT_VAR(&_35$$10);
		ZVAL_STRING(&_35$$10, "maxSize");
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, 0, &_35$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&matches);
		ZVAL_NULL(&matches);
		ZEPHIR_INIT_VAR(&unit);
		ZVAL_STRING(&unit, "B");
		ZEPHIR_INIT_NVAR(&_35$$10);
		ZEPHIR_INIT_VAR(&_36$$10);
		ZEPHIR_INIT_VAR(&_37$$10);
		zephir_array_keys(&_37$$10, &byteUnits TSRMLS_CC);
		zephir_fast_join_str(&_36$$10, SL("|"), &_37$$10 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_38$$10);
		ZEPHIR_CONCAT_SVS(&_38$$10, "/^([0-9]+(?:\\.[0-9]+)?)(", &_36$$10, ")?$/Di");
		zephir_preg_match(&_35$$10, &_38$$10, &maxSize, &matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(&matches, 2)) {
			ZEPHIR_OBS_NVAR(&unit);
			zephir_array_fetch_long(&unit, &matches, 2, PH_NOISY, "phalcon/validation/validator/file.zep", 111 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_39$$10, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 114 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_40$$10, "floatval", &_41, 318, &_39$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_42$$10);
		zephir_array_fetch(&_43$$10, &byteUnits, &unit, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 114 TSRMLS_CC);
		ZVAL_LONG(&_44$$10, 2);
		zephir_pow_function(&_42$$10, &_44$$10, &_43$$10);
		ZEPHIR_INIT_VAR(&bytes);
		mul_function(&bytes, &_40$$10, &_42$$10 TSRMLS_CC);
		zephir_array_fetch_string(&_45$$10, &value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 116 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_40$$10, "floatval", &_41, 318, &_45$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_46$$10, "floatval", &_41, 318, &bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(&_40$$10, &_46$$10)) {
			ZEPHIR_INIT_VAR(&_47$$12);
			ZVAL_STRING(&_47$$12, "messageSize");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_47$$12);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&replacePairs);
			zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_VAR(&_48$$13);
				ZVAL_STRING(&_48$$13, "FileSize");
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_48$$13);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&_47$$12);
			object_init_ex(&_47$$12, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_49$$12, "strtr", &_12, 55, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_51$$12);
			ZVAL_STRING(&_51$$12, "code");
			ZEPHIR_CALL_METHOD(&_50$$12, this_ptr, "getoption", NULL, 0, &_51$$12);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_51$$12);
			ZVAL_STRING(&_51$$12, "FileSize");
			ZEPHIR_CALL_METHOD(NULL, &_47$$12, "__construct", &_15, 461, &_49$$12, &field, &_51$$12, &_50$$12);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_47$$12);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowedTypes");
	ZEPHIR_CALL_METHOD(&_52, this_ptr, "hasoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_52)) {
		ZEPHIR_INIT_VAR(&_53$$14);
		ZVAL_STRING(&_53$$14, "allowedTypes");
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, 0, &_53$$14);
		zephir_check_call_status();
		if (Z_TYPE_P(&types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/validation/validator/file.zep", 134);
			return;
		}
		if ((zephir_function_exists_ex(SL("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZVAL_LONG(&_54$$16, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 239, &_54$$16);
			zephir_check_call_status();
			zephir_array_fetch_string(&_55$$16, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 139 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 240, &tmp, &_55$$16);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 241, &tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&mime);
			zephir_array_fetch_string(&mime, &value, SL("type"), PH_NOISY, "phalcon/validation/validator/file.zep", 143 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(&mime, &types TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_56$$18);
			ZVAL_STRING(&_56$$18, "messageType");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_56$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&replacePairs);
			zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_56$$18);
			zephir_fast_join_str(&_56$$18, SL(", "), &types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_56$$18, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_VAR(&_57$$19);
				ZVAL_STRING(&_57$$19, "FileType");
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_57$$19);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&_56$$18);
			object_init_ex(&_56$$18, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_58$$18, "strtr", &_12, 55, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_60$$18);
			ZVAL_STRING(&_60$$18, "code");
			ZEPHIR_CALL_METHOD(&_59$$18, this_ptr, "getoption", NULL, 0, &_60$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_60$$18);
			ZVAL_STRING(&_60$$18, "FileType");
			ZEPHIR_CALL_METHOD(NULL, &_56$$18, "__construct", &_15, 461, &_58$$18, &field, &_60$$18, &_59$$18);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_56$$18);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "minResolution");
	ZEPHIR_CALL_METHOD(&_61, this_ptr, "hasoption", NULL, 0, &_0);
	zephir_check_call_status();
	_62 = zephir_is_true(&_61);
	if (!(_62)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "maxResolution");
		ZEPHIR_CALL_METHOD(&_63, this_ptr, "hasoption", NULL, 0, &_0);
		zephir_check_call_status();
		_62 = zephir_is_true(&_63);
	}
	if (_62) {
		zephir_array_fetch_string(&_64$$20, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 160 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 250, &_64$$20);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&width);
		zephir_array_fetch_long(&width, &tmp, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 161 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&height);
		zephir_array_fetch_long(&height, &tmp, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 162 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_66$$20);
		ZVAL_STRING(&_66$$20, "minResolution");
		ZEPHIR_CALL_METHOD(&_65$$20, this_ptr, "hasoption", NULL, 0, &_66$$20);
		zephir_check_call_status();
		if (zephir_is_true(&_65$$20)) {
			ZEPHIR_INIT_VAR(&_68$$21);
			ZVAL_STRING(&_68$$21, "minResolution");
			ZEPHIR_CALL_METHOD(&_67$$21, this_ptr, "getoption", NULL, 0, &_68$$21);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&minResolution);
			zephir_fast_explode_str(&minResolution, SL("x"), &_67$$21, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(&minWidth);
			zephir_array_fetch_long(&minWidth, &minResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 166 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&minHeight);
			zephir_array_fetch_long(&minHeight, &minResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 167 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&minWidth);
			ZVAL_LONG(&minWidth, 1);
			ZEPHIR_INIT_NVAR(&minHeight);
			ZVAL_LONG(&minHeight, 1);
		}
		_69$$20 = ZEPHIR_LT(&width, &minWidth);
		if (!(_69$$20)) {
			_69$$20 = ZEPHIR_LT(&height, &minHeight);
		}
		if (_69$$20) {
			ZEPHIR_INIT_VAR(&_70$$23);
			ZVAL_STRING(&_70$$23, "messageMinResolution");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_70$$23);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&replacePairs);
			zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_70$$23);
			ZVAL_STRING(&_70$$23, "minResolution");
			ZEPHIR_CALL_METHOD(&_71$$23, this_ptr, "getoption", NULL, 0, &_70$$23);
			zephir_check_call_status();
			zephir_array_update_string(&replacePairs, SL(":min"), &_71$$23, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_VAR(&_72$$24);
				ZVAL_STRING(&_72$$24, "FileMinResolution");
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_72$$24);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&_70$$23);
			object_init_ex(&_70$$23, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_71$$23, "strtr", &_12, 55, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_74$$23);
			ZVAL_STRING(&_74$$23, "code");
			ZEPHIR_CALL_METHOD(&_73$$23, this_ptr, "getoption", NULL, 0, &_74$$23);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_74$$23);
			ZVAL_STRING(&_74$$23, "FileMinResolution");
			ZEPHIR_CALL_METHOD(NULL, &_70$$23, "__construct", &_15, 461, &_71$$23, &field, &_74$$23, &_73$$23);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_70$$23);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_66$$20);
		ZVAL_STRING(&_66$$20, "maxResolution");
		ZEPHIR_CALL_METHOD(&_75$$20, this_ptr, "hasoption", NULL, 0, &_66$$20);
		zephir_check_call_status();
		if (zephir_is_true(&_75$$20)) {
			ZEPHIR_INIT_VAR(&_77$$25);
			ZVAL_STRING(&_77$$25, "maxResolution");
			ZEPHIR_CALL_METHOD(&_76$$25, this_ptr, "getoption", NULL, 0, &_77$$25);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&maxResolution);
			zephir_fast_explode_str(&maxResolution, SL("x"), &_76$$25, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(&maxWidth);
			zephir_array_fetch_long(&maxWidth, &maxResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 188 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&maxHeight);
			zephir_array_fetch_long(&maxHeight, &maxResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 189 TSRMLS_CC);
			_78$$25 = ZEPHIR_GT(&width, &maxWidth);
			if (!(_78$$25)) {
				_78$$25 = ZEPHIR_GT(&height, &maxHeight);
			}
			if (_78$$25) {
				ZEPHIR_INIT_VAR(&_79$$26);
				ZVAL_STRING(&_79$$26, "messageMaxResolution");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_79$$26);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&replacePairs);
				zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_79$$26);
				ZVAL_STRING(&_79$$26, "maxResolution");
				ZEPHIR_CALL_METHOD(&_80$$26, this_ptr, "getoption", NULL, 0, &_79$$26);
				zephir_check_call_status();
				zephir_array_update_string(&replacePairs, SL(":max"), &_80$$26, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(&message)) {
					ZEPHIR_INIT_VAR(&_81$$27);
					ZVAL_STRING(&_81$$27, "FileMaxResolution");
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_81$$27);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(&_79$$26);
				object_init_ex(&_79$$26, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_80$$26, "strtr", &_12, 55, &message, &replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_83$$26);
				ZVAL_STRING(&_83$$26, "code");
				ZEPHIR_CALL_METHOD(&_82$$26, this_ptr, "getoption", NULL, 0, &_83$$26);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_83$$26);
				ZVAL_STRING(&_83$$26, "FileMaxResolution");
				ZEPHIR_CALL_METHOD(NULL, &_79$$26, "__construct", &_15, 461, &_80$$26, &field, &_83$$26, &_82$$26);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_79$$26);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check on empty
 */
PHP_METHOD(Phalcon_Validation_Validator_File, isAllowEmpty) {

	zend_bool _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_EMPTY(&value);
	if (!(_0)) {
		_1 = zephir_array_isset_string(&value, SL("error"));
		if (_1) {
			zephir_array_fetch_string(&_2, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 216 TSRMLS_CC);
			_1 = ZEPHIR_IS_LONG_IDENTICAL(&_2, 4);
		}
		_0 = _1;
	}
	RETURN_MM_BOOL(_0);

}

