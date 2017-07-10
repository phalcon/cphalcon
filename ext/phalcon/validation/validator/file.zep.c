
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
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

	zend_bool _1, _2, _3, _5, _6, _13, _14, _16, _22, _23, _53, _60$$16, _67$$21;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *_SERVER, *_POST, *_FILES, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *types = NULL, *byteUnits = NULL, *unit = NULL, *maxSize = NULL, *matches = NULL, *bytes = NULL, *mime = NULL, *tmp = NULL, *width = NULL, *height = NULL, *minResolution = NULL, *maxResolution = NULL, *minWidth = NULL, *maxWidth = NULL, *minHeight = NULL, *maxHeight = NULL, *fieldTypes = NULL, *code = NULL, *minResolutionArray = NULL, *maxResolutionArray = NULL, *_0, *_4, *_7, *_15, *_17, *_18 = NULL, *_27 = NULL, *_28 = NULL, *_45 = NULL, *_52 = NULL, *_54 = NULL, *_8$$3 = NULL, *_9$$3 = NULL, *_10$$3 = NULL, *_19$$4 = NULL, *_20$$4 = NULL, *_21$$4 = NULL, *_24$$5 = NULL, *_25$$5 = NULL, *_26$$5 = NULL, *_29$$6 = NULL, *_31$$6, *_32$$6, *_33$$6, *_34$$6, *_35$$6 = NULL, *_37$$6, *_38$$6, _39$$6, *_40$$6, *_41$$6 = NULL, *_30$$7, *_42$$9 = NULL, *_43$$9 = NULL, *_44$$9 = NULL, *_46$$10, _47$$13, *_48$$13, *_49$$15 = NULL, *_50$$15 = NULL, *_51$$15 = NULL, *_55$$16, *_56$$16 = NULL, *_57$$16 = NULL, *_64$$16 = NULL, *_58$$17, *_59$$18, *_61$$20 = NULL, *_62$$20 = NULL, *_63$$20 = NULL, *_65$$21, *_66$$22, *_68$$23 = NULL, *_69$$23 = NULL, *_70$$23 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 109 TSRMLS_CC);
	_1 = ZEPHIR_IS_STRING(_0, "POST");
	if (_1) {
		_1 = ZEPHIR_IS_EMPTY(_POST);
	}
	_2 = _1;
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_3 = _2;
	if (_3) {
		zephir_array_fetch_string(&_4, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 109 TSRMLS_CC);
		_3 = ZEPHIR_GT_LONG(_4, 0);
	}
	_5 = _3;
	if (!(_5)) {
		_6 = zephir_array_isset_string(value, SS("error"));
		if (_6) {
			zephir_array_fetch_string(&_7, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 109 TSRMLS_CC);
			_6 = ZEPHIR_IS_LONG_IDENTICAL(_7, 1);
		}
		_5 = _6;
	}
	if (_5) {
		ZEPHIR_INIT_VAR(_8$$3);
		ZVAL_STRING(_8$$3, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _8$$3, _9$$3);
		zephir_check_temp_parameter(_8$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8$$3);
		object_init_ex(_8$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "strtr", &_11, 27, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_9$$3);
		ZVAL_STRING(_9$$3, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _8$$3, "__construct", &_12, 475, _10$$3, field, _9$$3, code);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _8$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_13 = !(zephir_array_isset_string(value, SS("error")));
	if (!(_13)) {
		_13 = !(zephir_array_isset_string(value, SS("tmp_name")));
	}
	_14 = _13;
	if (!(_14)) {
		zephir_array_fetch_string(&_15, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 124 TSRMLS_CC);
		_14 = !ZEPHIR_IS_LONG_IDENTICAL(_15, 0);
	}
	_16 = _14;
	if (!(_16)) {
		zephir_array_fetch_string(&_17, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 124 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_18, "is_uploaded_file", NULL, 253, _17);
		zephir_check_call_status();
		_16 = !zephir_is_true(_18);
	}
	if (_16) {
		ZEPHIR_INIT_VAR(_19$$4);
		ZVAL_STRING(_19$$4, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_20$$4);
		ZVAL_STRING(_20$$4, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _19$$4, _20$$4);
		zephir_check_temp_parameter(_19$$4);
		zephir_check_temp_parameter(_20$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_19$$4);
		object_init_ex(_19$$4, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_21$$4, "strtr", &_11, 27, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_20$$4);
		ZVAL_STRING(_20$$4, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _19$$4, "__construct", &_12, 475, _21$$4, field, _20$$4, code);
		zephir_check_temp_parameter(_20$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _19$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_22 = !(zephir_array_isset_string(value, SS("name")));
	if (!(_22)) {
		_22 = !(zephir_array_isset_string(value, SS("type")));
	}
	_23 = _22;
	if (!(_23)) {
		_23 = !(zephir_array_isset_string(value, SS("size")));
	}
	if (_23) {
		ZEPHIR_INIT_VAR(_24$$5);
		ZVAL_STRING(_24$$5, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_25$$5);
		ZVAL_STRING(_25$$5, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _24$$5, _25$$5);
		zephir_check_temp_parameter(_24$$5);
		zephir_check_temp_parameter(_25$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_24$$5);
		object_init_ex(_24$$5, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_26$$5, "strtr", &_11, 27, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_25$$5);
		ZVAL_STRING(_25$$5, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _24$$5, "__construct", &_12, 475, _26$$5, field, _25$$5, code);
		zephir_check_temp_parameter(_25$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _24$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_28);
	ZVAL_STRING(_28, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_27, this_ptr, "hasoption", NULL, 0, _28);
	zephir_check_temp_parameter(_28);
	zephir_check_call_status();
	if (zephir_is_true(_27)) {
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
		ZEPHIR_INIT_VAR(_29$$6);
		ZVAL_STRING(_29$$6, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, 0, _29$$6);
		zephir_check_temp_parameter(_29$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		if (Z_TYPE_P(maxSize) == IS_ARRAY) {
			zephir_array_fetch(&_30$$7, maxSize, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 162 TSRMLS_CC);
			ZEPHIR_CPY_WRT(maxSize, _30$$7);
		}
		ZEPHIR_INIT_NVAR(_29$$6);
		ZEPHIR_INIT_VAR(_31$$6);
		ZEPHIR_INIT_VAR(_32$$6);
		zephir_array_keys(_32$$6, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_31$$6, SL("|"), _32$$6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_33$$6);
		ZEPHIR_CONCAT_SVS(_33$$6, "/^([0-9]+(?:\\.[0-9]+)?)(", _31$$6, ")?$/Di");
		zephir_preg_match(_29$$6, _33$$6, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "phalcon/validation/validator/file.zep", 168 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_34$$6, matches, 1, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 171 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_35$$6, "floatval", &_36, 328, _34$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_37$$6);
		zephir_array_fetch(&_38$$6, byteUnits, unit, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 171 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_39$$6);
		ZVAL_LONG(&_39$$6, 2);
		zephir_pow_function(_37$$6, &_39$$6, _38$$6);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _35$$6, _37$$6 TSRMLS_CC);
		zephir_array_fetch_string(&_40$$6, value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 173 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_35$$6, "floatval", &_36, 328, _40$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_41$$6, "floatval", &_36, 328, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_35$$6, _41$$6)) {
			ZEPHIR_INIT_VAR(_42$$9);
			ZVAL_STRING(_42$$9, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_43$$9);
			ZVAL_STRING(_43$$9, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _42$$9, _43$$9);
			zephir_check_temp_parameter(_42$$9);
			zephir_check_temp_parameter(_43$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_42$$9);
			object_init_ex(_42$$9, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_44$$9, "strtr", &_11, 27, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_43$$9);
			ZVAL_STRING(_43$$9, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _42$$9, "__construct", &_12, 475, _44$$9, field, _43$$9, code);
			zephir_check_temp_parameter(_43$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _42$$9);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_28);
	ZVAL_STRING(_28, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_45, this_ptr, "hasoption", NULL, 0, _28);
	zephir_check_temp_parameter(_28);
	zephir_check_call_status();
	if (zephir_is_true(_45)) {
		ZEPHIR_INIT_VAR(_46$$10);
		ZVAL_STRING(_46$$10, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, 0, _46$$10);
		zephir_check_temp_parameter(_46$$10);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(fieldTypes);
		if (zephir_array_isset_fetch(&fieldTypes, types, field, 0 TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(types, fieldTypes);
		}
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/validation/validator/file.zep", 198);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_VAR(_47$$13);
			ZVAL_LONG(&_47$$13, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 250, &_47$$13);
			zephir_check_call_status();
			zephir_array_fetch_string(&_48$$13, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 203 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 251, tmp, _48$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 252, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "phalcon/validation/validator/file.zep", 207 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_49$$15);
			ZVAL_STRING(_49$$15, "FileType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_50$$15);
			ZVAL_STRING(_50$$15, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _49$$15, _50$$15);
			zephir_check_temp_parameter(_49$$15);
			zephir_check_temp_parameter(_50$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_49$$15);
			zephir_fast_join_str(_49$$15, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_49$$15, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_49$$15);
			object_init_ex(_49$$15, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_51$$15, "strtr", &_11, 27, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_50$$15);
			ZVAL_STRING(_50$$15, "FileType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _49$$15, "__construct", &_12, 475, _51$$15, field, _50$$15, code);
			zephir_check_temp_parameter(_50$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _49$$15);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_28);
	ZVAL_STRING(_28, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_52, this_ptr, "hasoption", NULL, 0, _28);
	zephir_check_temp_parameter(_28);
	zephir_check_call_status();
	_53 = zephir_is_true(_52);
	if (!(_53)) {
		ZEPHIR_INIT_NVAR(_28);
		ZVAL_STRING(_28, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_54, this_ptr, "hasoption", NULL, 0, _28);
		zephir_check_temp_parameter(_28);
		zephir_check_call_status();
		_53 = zephir_is_true(_54);
	}
	if (_53) {
		zephir_array_fetch_string(&_55$$16, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 228 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 261, _55$$16);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 229 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 230 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_57$$16);
		ZVAL_STRING(_57$$16, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_56$$16, this_ptr, "hasoption", NULL, 0, _57$$16);
		zephir_check_temp_parameter(_57$$16);
		zephir_check_call_status();
		if (zephir_is_true(_56$$16)) {
			ZEPHIR_INIT_VAR(_58$$17);
			ZVAL_STRING(_58$$17, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&minResolution, this_ptr, "getoption", NULL, 0, _58$$17);
			zephir_check_temp_parameter(_58$$17);
			zephir_check_call_status();
			if (Z_TYPE_P(minResolution) == IS_ARRAY) {
				zephir_array_fetch(&_59$$18, minResolution, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 235 TSRMLS_CC);
				ZEPHIR_CPY_WRT(minResolution, _59$$18);
			}
			ZEPHIR_INIT_VAR(minResolutionArray);
			zephir_fast_explode_str(minResolutionArray, SL("x"), minResolution, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolutionArray, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 238 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolutionArray, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 239 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_60$$16 = ZEPHIR_LT(width, minWidth);
		if (!(_60$$16)) {
			_60$$16 = ZEPHIR_LT(height, minHeight);
		}
		if (_60$$16) {
			ZEPHIR_INIT_VAR(_61$$20);
			ZVAL_STRING(_61$$20, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_62$$20);
			ZVAL_STRING(_62$$20, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _61$$20, _62$$20);
			zephir_check_temp_parameter(_61$$20);
			zephir_check_temp_parameter(_62$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":min"), &minResolution, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_61$$20);
			object_init_ex(_61$$20, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_63$$20, "strtr", &_11, 27, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_62$$20);
			ZVAL_STRING(_62$$20, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _61$$20, "__construct", &_12, 475, _63$$20, field, _62$$20, code);
			zephir_check_temp_parameter(_62$$20);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _61$$20);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_57$$16);
		ZVAL_STRING(_57$$16, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_64$$16, this_ptr, "hasoption", NULL, 0, _57$$16);
		zephir_check_temp_parameter(_57$$16);
		zephir_check_call_status();
		if (zephir_is_true(_64$$16)) {
			ZEPHIR_INIT_VAR(_65$$21);
			ZVAL_STRING(_65$$21, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&maxResolution, this_ptr, "getoption", NULL, 0, _65$$21);
			zephir_check_temp_parameter(_65$$21);
			zephir_check_call_status();
			if (Z_TYPE_P(maxResolution) == IS_ARRAY) {
				zephir_array_fetch(&_66$$22, maxResolution, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 265 TSRMLS_CC);
				ZEPHIR_CPY_WRT(maxResolution, _66$$22);
			}
			ZEPHIR_INIT_VAR(maxResolutionArray);
			zephir_fast_explode_str(maxResolutionArray, SL("x"), maxResolution, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolutionArray, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 268 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolutionArray, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 269 TSRMLS_CC);
			_67$$21 = ZEPHIR_GT(width, maxWidth);
			if (!(_67$$21)) {
				_67$$21 = ZEPHIR_GT(height, maxHeight);
			}
			if (_67$$21) {
				ZEPHIR_INIT_VAR(_68$$23);
				ZVAL_STRING(_68$$23, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_VAR(_69$$23);
				ZVAL_STRING(_69$$23, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _68$$23, _69$$23);
				zephir_check_temp_parameter(_68$$23);
				zephir_check_temp_parameter(_69$$23);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(replacePairs);
				zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&replacePairs, SL(":max"), &maxResolution, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_68$$23);
				object_init_ex(_68$$23, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_70$$23, "strtr", &_11, 27, message, replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_69$$23);
				ZVAL_STRING(_69$$23, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _68$$23, "__construct", &_12, 475, _70$$23, field, _69$$23, code);
				zephir_check_temp_parameter(_69$$23);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _68$$23);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
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
			zephir_array_fetch_string(&_2, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 301 TSRMLS_CC);
			_1 = ZEPHIR_IS_LONG_IDENTICAL(_2, 4);
		}
		_0 = _1;
	}
	RETURN_MM_BOOL(_0);

}

