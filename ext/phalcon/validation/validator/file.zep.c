
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
#include "kernel/array.h"
#include "kernel/operators.h"
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
 * <code>
 * use Phalcon\Validation\Validator\File as FileValidator;
 *
 * $validator->add(
 *     "file",
 *     new FileValidator(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max filesize (:max)",
 *             "allowedTypes"         => [
 *                 "image/jpeg",
 *                 "image/png",
 *             ],
 *             "messageType"          => "Allowed file types are :types",
 *             "maxResolution"        => "800x600",
 *             "messageMaxResolution" => "Max resolution of :field is :max",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new FileValidator(
 *         [
 *             "maxSize" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "messageSize" => [
 *                 "file"        => "file exceeds the max filesize 2M",
 *                 "anotherFile" => "anotherFile exceeds the max filesize 4M",
 *             "allowedTypes" => [
 *                 "file"        => [
 *                     "image/jpeg",
 *                     "image/png",
 *                 ],
 *                 "anotherFile" => [
 *                     "image/gif",
 *                     "image/bmp",
 *                 ],
 *             ],
 *             "messageType" => [
 *                 "file"        => "Allowed file types are image/jpeg and image/png",
 *                 "anotherFile" => "Allowed file types are image/gif and image/bmp",
 *             ],
 *             "maxResolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "messageMaxResolution" => [
 *                 "file"        => "Max resolution of file is 800x600",
 *                 "anotherFile" => "Max resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, File, phalcon, validation_validator_file, phalcon_validation_validator_ce, phalcon_validation_validator_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File, validate) {

	zend_bool _4, _5, _6, _8, _9, _18, _19, _21, _29, _30, _65, _72$$29, _81$$36;
	zephir_fcall_cache_entry *_15 = NULL, *_17 = NULL, *_44 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *_SERVER, *_POST, *_FILES, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *types = NULL, *byteUnits = NULL, *unit = NULL, *maxSize = NULL, *matches = NULL, *bytes = NULL, *mime = NULL, *tmp = NULL, *width = NULL, *height = NULL, *minResolution = NULL, *maxResolution = NULL, *minWidth = NULL, *maxWidth = NULL, *minHeight = NULL, *maxHeight = NULL, *fieldTypes = NULL, *code = NULL, *minResolutionArray = NULL, *maxResolutionArray = NULL, *_0 = NULL, *_3, *_7, *_10, *_20, *_22, *_23 = NULL, *_36 = NULL, *_55 = NULL, *_64 = NULL, *_66 = NULL, *_1$$3, *_2$$5, *_11$$6 = NULL, *_14$$6 = NULL, *_16$$6, *_12$$7, *_13$$8, *_24$$9 = NULL, *_27$$9 = NULL, *_28$$9, *_25$$10, *_26$$11, *_31$$12 = NULL, *_34$$12 = NULL, *_35$$12, *_32$$13, *_33$$14, *_37$$15 = NULL, *_39$$15, *_40$$15, *_41$$15, *_42$$15, *_43$$15 = NULL, *_45$$15, *_46$$15, _47$$15, *_48$$15, *_49$$15 = NULL, *_38$$16, *_50$$18 = NULL, *_53$$18 = NULL, *_54$$18, *_51$$19, *_52$$20, *_56$$21, _57$$24, *_58$$24, *_59$$26 = NULL, *_62$$26 = NULL, *_63$$26, *_60$$27, *_61$$28, *_67$$29, *_68$$29 = NULL, *_69$$29 = NULL, *_78$$29 = NULL, *_70$$30, *_71$$31, *_73$$33 = NULL, *_76$$33 = NULL, *_77$$33, *_74$$34, *_75$$35, *_79$$36, *_80$$37, *_82$$38 = NULL, *_85$$38 = NULL, *_86$$38, *_83$$39, *_84$$40;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(label) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 108 TSRMLS_CC);
		ZEPHIR_CPY_WRT(label, _1$$3);
	}
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "code", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(code) == IS_ARRAY) {
		zephir_array_fetch(&_2$$5, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 117 TSRMLS_CC);
		ZEPHIR_CPY_WRT(code, _2$$5);
	}
	zephir_array_fetch_string(&_3, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 121 TSRMLS_CC);
	_4 = ZEPHIR_IS_STRING(_3, "POST");
	if (_4) {
		_4 = ZEPHIR_IS_EMPTY(_POST);
	}
	_5 = _4;
	if (_5) {
		_5 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_6 = _5;
	if (_6) {
		zephir_array_fetch_string(&_7, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 121 TSRMLS_CC);
		_6 = ZEPHIR_GT_LONG(_7, 0);
	}
	_8 = _6;
	if (!(_8)) {
		_9 = zephir_array_isset_string(value, SS("error"));
		if (_9) {
			zephir_array_fetch_string(&_10, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 121 TSRMLS_CC);
			_9 = ZEPHIR_IS_LONG_IDENTICAL(_10, 1);
		}
		_8 = _9;
	}
	if (_8) {
		ZEPHIR_INIT_VAR(_11$$6);
		ZVAL_STRING(_11$$6, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _11$$6);
		zephir_check_temp_parameter(_11$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (Z_TYPE_P(message) == IS_ARRAY) {
			zephir_array_fetch(&_12$$7, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 127 TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, _12$$7);
		}
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_13$$8);
			ZVAL_STRING(_13$$8, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _13$$8);
			zephir_check_temp_parameter(_13$$8);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_11$$6);
		object_init_ex(_11$$6, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_14$$6, "strtr", &_15, 26, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_16$$6);
		ZVAL_STRING(_16$$6, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _11$$6, "__construct", &_17, 465, _14$$6, field, _16$$6, code);
		zephir_check_temp_parameter(_16$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _11$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_18 = !(zephir_array_isset_string(value, SS("error")));
	if (!(_18)) {
		_18 = !(zephir_array_isset_string(value, SS("tmp_name")));
	}
	_19 = _18;
	if (!(_19)) {
		zephir_array_fetch_string(&_20, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 138 TSRMLS_CC);
		_19 = !ZEPHIR_IS_LONG_IDENTICAL(_20, 0);
	}
	_21 = _19;
	if (!(_21)) {
		zephir_array_fetch_string(&_22, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 138 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_23, "is_uploaded_file", NULL, 246, _22);
		zephir_check_call_status();
		_21 = !zephir_is_true(_23);
	}
	if (_21) {
		ZEPHIR_INIT_VAR(_24$$9);
		ZVAL_STRING(_24$$9, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _24$$9);
		zephir_check_temp_parameter(_24$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (Z_TYPE_P(message) == IS_ARRAY) {
			zephir_array_fetch(&_25$$10, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 144 TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, _25$$10);
		}
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_26$$11);
			ZVAL_STRING(_26$$11, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _26$$11);
			zephir_check_temp_parameter(_26$$11);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_24$$9);
		object_init_ex(_24$$9, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_27$$9, "strtr", &_15, 26, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_28$$9);
		ZVAL_STRING(_28$$9, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _24$$9, "__construct", &_17, 465, _27$$9, field, _28$$9, code);
		zephir_check_temp_parameter(_28$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _24$$9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_29 = !(zephir_array_isset_string(value, SS("name")));
	if (!(_29)) {
		_29 = !(zephir_array_isset_string(value, SS("type")));
	}
	_30 = _29;
	if (!(_30)) {
		_30 = !(zephir_array_isset_string(value, SS("size")));
	}
	if (_30) {
		ZEPHIR_INIT_VAR(_31$$12);
		ZVAL_STRING(_31$$12, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _31$$12);
		zephir_check_temp_parameter(_31$$12);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (Z_TYPE_P(message) == IS_ARRAY) {
			zephir_array_fetch(&_32$$13, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 161 TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, _32$$13);
		}
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_33$$14);
			ZVAL_STRING(_33$$14, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _33$$14);
			zephir_check_temp_parameter(_33$$14);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_31$$12);
		object_init_ex(_31$$12, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_34$$12, "strtr", &_15, 26, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_35$$12);
		ZVAL_STRING(_35$$12, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _31$$12, "__construct", &_17, 465, _34$$12, field, _35$$12, code);
		zephir_check_temp_parameter(_35$$12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _31$$12);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_36, this_ptr, "hasoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_36)) {
		ZEPHIR_INIT_VAR(byteUnits);
		zephir_create_array(byteUnits, 9, 0 TSRMLS_CC);
		add_assoc_long_ex(byteUnits, SS("B"), 0);
		add_assoc_long_ex(byteUnits, SS("K"), 10);
		add_assoc_long_ex(byteUnits, SS("M"), 20);
		add_assoc_long_ex(byteUnits, SS("G"), 30);
		add_assoc_long_ex(byteUnits, SS("T"), 40);
		add_assoc_long_ex(byteUnits, SS("KB"), 10);
		add_assoc_long_ex(byteUnits, SS("MB"), 20);
		add_assoc_long_ex(byteUnits, SS("GB"), 30);
		add_assoc_long_ex(byteUnits, SS("TB"), 40);
		ZEPHIR_INIT_VAR(_37$$15);
		ZVAL_STRING(_37$$15, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, 0, _37$$15);
		zephir_check_temp_parameter(_37$$15);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		if (Z_TYPE_P(maxSize) == IS_ARRAY) {
			zephir_array_fetch(&_38$$16, maxSize, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 180 TSRMLS_CC);
			ZEPHIR_CPY_WRT(maxSize, _38$$16);
		}
		ZEPHIR_INIT_NVAR(_37$$15);
		ZEPHIR_INIT_VAR(_39$$15);
		ZEPHIR_INIT_VAR(_40$$15);
		zephir_array_keys(_40$$15, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_39$$15, SL("|"), _40$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_41$$15);
		ZEPHIR_CONCAT_SVS(_41$$15, "/^([0-9]+(?:\\.[0-9]+)?)(", _39$$15, ")?$/Di");
		zephir_preg_match(_37$$15, _41$$15, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "phalcon/validation/validator/file.zep", 186 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_42$$15, matches, 1, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 189 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_43$$15, "floatval", &_44, 322, _42$$15);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_45$$15);
		zephir_array_fetch(&_46$$15, byteUnits, unit, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 189 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_47$$15);
		ZVAL_LONG(&_47$$15, 2);
		zephir_pow_function(_45$$15, &_47$$15, _46$$15);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _43$$15, _45$$15 TSRMLS_CC);
		zephir_array_fetch_string(&_48$$15, value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 191 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_43$$15, "floatval", &_44, 322, _48$$15);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_49$$15, "floatval", &_44, 322, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_43$$15, _49$$15)) {
			ZEPHIR_INIT_VAR(_50$$18);
			ZVAL_STRING(_50$$18, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _50$$18);
			zephir_check_temp_parameter(_50$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(message) == IS_ARRAY) {
				zephir_array_fetch(&_51$$19, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 196 TSRMLS_CC);
				ZEPHIR_CPY_WRT(message, _51$$19);
			}
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_VAR(_52$$20);
				ZVAL_STRING(_52$$20, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _52$$20);
				zephir_check_temp_parameter(_52$$20);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_50$$18);
			object_init_ex(_50$$18, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_53$$18, "strtr", &_15, 26, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_54$$18);
			ZVAL_STRING(_54$$18, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _50$$18, "__construct", &_17, 465, _53$$18, field, _54$$18, code);
			zephir_check_temp_parameter(_54$$18);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _50$$18);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_55, this_ptr, "hasoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_55)) {
		ZEPHIR_INIT_VAR(_56$$21);
		ZVAL_STRING(_56$$21, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, 0, _56$$21);
		zephir_check_temp_parameter(_56$$21);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(fieldTypes);
		if (zephir_array_isset_fetch(&fieldTypes, types, field, 0 TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(types, fieldTypes);
		}
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/validation/validator/file.zep", 217);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_VAR(_57$$24);
			ZVAL_LONG(&_57$$24, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 243, &_57$$24);
			zephir_check_call_status();
			zephir_array_fetch_string(&_58$$24, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 222 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 244, tmp, _58$$24);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 245, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "phalcon/validation/validator/file.zep", 226 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_59$$26);
			ZVAL_STRING(_59$$26, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _59$$26);
			zephir_check_temp_parameter(_59$$26);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_59$$26);
			zephir_fast_join_str(_59$$26, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_59$$26, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(message) == IS_ARRAY) {
				zephir_array_fetch(&_60$$27, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 234 TSRMLS_CC);
				ZEPHIR_CPY_WRT(message, _60$$27);
			}
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_VAR(_61$$28);
				ZVAL_STRING(_61$$28, "FileType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _61$$28);
				zephir_check_temp_parameter(_61$$28);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_59$$26);
			object_init_ex(_59$$26, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_62$$26, "strtr", &_15, 26, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_63$$26);
			ZVAL_STRING(_63$$26, "FileType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _59$$26, "__construct", &_17, 465, _62$$26, field, _63$$26, code);
			zephir_check_temp_parameter(_63$$26);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _59$$26);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_64, this_ptr, "hasoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_65 = zephir_is_true(_64);
	if (!(_65)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_66, this_ptr, "hasoption", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		_65 = zephir_is_true(_66);
	}
	if (_65) {
		zephir_array_fetch_string(&_67$$29, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 247 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 254, _67$$29);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 248 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 249 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_69$$29);
		ZVAL_STRING(_69$$29, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_68$$29, this_ptr, "hasoption", NULL, 0, _69$$29);
		zephir_check_temp_parameter(_69$$29);
		zephir_check_call_status();
		if (zephir_is_true(_68$$29)) {
			ZEPHIR_INIT_VAR(_70$$30);
			ZVAL_STRING(_70$$30, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&minResolution, this_ptr, "getoption", NULL, 0, _70$$30);
			zephir_check_temp_parameter(_70$$30);
			zephir_check_call_status();
			if (Z_TYPE_P(minResolution) == IS_ARRAY) {
				zephir_array_fetch(&_71$$31, minResolution, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 254 TSRMLS_CC);
				ZEPHIR_CPY_WRT(minResolution, _71$$31);
			}
			ZEPHIR_INIT_VAR(minResolutionArray);
			zephir_fast_explode_str(minResolutionArray, SL("x"), minResolution, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolutionArray, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 257 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolutionArray, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 258 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_72$$29 = ZEPHIR_LT(width, minWidth);
		if (!(_72$$29)) {
			_72$$29 = ZEPHIR_LT(height, minHeight);
		}
		if (_72$$29) {
			ZEPHIR_INIT_VAR(_73$$33);
			ZVAL_STRING(_73$$33, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _73$$33);
			zephir_check_temp_parameter(_73$$33);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":min"), &minResolution, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(message) == IS_ARRAY) {
				zephir_array_fetch(&_74$$34, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 269 TSRMLS_CC);
				ZEPHIR_CPY_WRT(message, _74$$34);
			}
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_VAR(_75$$35);
				ZVAL_STRING(_75$$35, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _75$$35);
				zephir_check_temp_parameter(_75$$35);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_73$$33);
			object_init_ex(_73$$33, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_76$$33, "strtr", &_15, 26, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_77$$33);
			ZVAL_STRING(_77$$33, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _73$$33, "__construct", &_17, 465, _76$$33, field, _77$$33, code);
			zephir_check_temp_parameter(_77$$33);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _73$$33);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_69$$29);
		ZVAL_STRING(_69$$29, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_78$$29, this_ptr, "hasoption", NULL, 0, _69$$29);
		zephir_check_temp_parameter(_69$$29);
		zephir_check_call_status();
		if (zephir_is_true(_78$$29)) {
			ZEPHIR_INIT_VAR(_79$$36);
			ZVAL_STRING(_79$$36, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&maxResolution, this_ptr, "getoption", NULL, 0, _79$$36);
			zephir_check_temp_parameter(_79$$36);
			zephir_check_call_status();
			if (Z_TYPE_P(maxResolution) == IS_ARRAY) {
				zephir_array_fetch(&_80$$37, maxResolution, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 284 TSRMLS_CC);
				ZEPHIR_CPY_WRT(maxResolution, _80$$37);
			}
			ZEPHIR_INIT_VAR(maxResolutionArray);
			zephir_fast_explode_str(maxResolutionArray, SL("x"), maxResolution, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolutionArray, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 287 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolutionArray, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 288 TSRMLS_CC);
			_81$$36 = ZEPHIR_GT(width, maxWidth);
			if (!(_81$$36)) {
				_81$$36 = ZEPHIR_GT(height, maxHeight);
			}
			if (_81$$36) {
				ZEPHIR_INIT_VAR(_82$$38);
				ZVAL_STRING(_82$$38, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _82$$38);
				zephir_check_temp_parameter(_82$$38);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(replacePairs);
				zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&replacePairs, SL(":max"), &maxResolution, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(message) == IS_ARRAY) {
					zephir_array_fetch(&_83$$39, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 295 TSRMLS_CC);
					ZEPHIR_CPY_WRT(message, _83$$39);
				}
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_VAR(_84$$40);
					ZVAL_STRING(_84$$40, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _84$$40);
					zephir_check_temp_parameter(_84$$40);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_82$$38);
				object_init_ex(_82$$38, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_85$$38, "strtr", &_15, 26, message, replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_86$$38);
				ZVAL_STRING(_86$$38, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _82$$38, "__construct", &_17, 465, _85$$38, field, _86$$38, code);
				zephir_check_temp_parameter(_86$$38);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _82$$38);
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
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_EMPTY(value);
	if (!(_0)) {
		_1 = zephir_array_isset_string(value, SS("error"));
		if (_1) {
			zephir_array_fetch_string(&_2, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 319 TSRMLS_CC);
			_1 = ZEPHIR_IS_LONG_IDENTICAL(_2, 4);
		}
		_0 = _1;
	}
	RETURN_MM_BOOL(_0);

}

