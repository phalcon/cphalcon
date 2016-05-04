
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

	zend_bool _2, _3, _4, _6, _7, _16, _17, _18, _20, _21, _23, _30, _31, _62, _69$$21, _77$$26;
	zephir_fcall_cache_entry *_12 = NULL, *_14 = NULL, *_43 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *_SERVER, *_POST, *_FILES, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *types = NULL, *byteUnits = NULL, *unit = NULL, *maxSize = NULL, *matches = NULL, *bytes = NULL, *mime = NULL, *tmp = NULL, *width = NULL, *height = NULL, *minResolution = NULL, *maxResolution = NULL, *minWidth = NULL, *maxWidth = NULL, *minHeight = NULL, *maxHeight = NULL, *_0 = NULL, *_1, *_5, *_8, *_15 = NULL, *_19, *_22, *_24, *_25 = NULL, *_36 = NULL, *_53 = NULL, *_61 = NULL, *_63 = NULL, *_9$$4 = NULL, *_11$$4 = NULL, *_13$$4, *_10$$5, *_26$$7 = NULL, *_28$$7 = NULL, *_29$$7, *_27$$8, *_32$$9 = NULL, *_34$$9 = NULL, *_35$$9, *_33$$10, *_37$$11 = NULL, *_38$$11, *_39$$11, *_40$$11, *_41$$11, *_42$$11 = NULL, *_44$$11, *_45$$11, _46$$11, *_47$$11, *_48$$11 = NULL, *_49$$13 = NULL, *_51$$13 = NULL, *_52$$13, *_50$$14, *_54$$15, _55$$17, *_56$$17, *_57$$19 = NULL, *_59$$19 = NULL, *_60$$19, *_58$$20, *_64$$21, *_65$$21 = NULL, *_66$$21 = NULL, *_74$$21 = NULL, *_67$$22 = NULL, *_68$$22, *_70$$24 = NULL, *_71$$24 = NULL, *_73$$24, *_72$$25, *_75$$26 = NULL, *_76$$26, *_78$$27 = NULL, *_79$$27 = NULL, *_81$$27, *_80$$28;

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
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
	_2 = ZEPHIR_IS_STRING(_1, "POST");
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(_POST);
	}
	_3 = _2;
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_4 = _3;
	if (_4) {
		zephir_array_fetch_string(&_5, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
		_4 = ZEPHIR_GT_LONG(_5, 0);
	}
	_6 = _4;
	if (!(_6)) {
		_7 = zephir_array_isset_string(value, SS("error"));
		if (_7) {
			zephir_array_fetch_string(&_8, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
			_7 = ZEPHIR_IS_LONG_IDENTICAL(_8, 1);
		}
		_6 = _7;
	}
	if (_6) {
		ZEPHIR_INIT_VAR(_9$$4);
		ZVAL_STRING(_9$$4, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _9$$4);
		zephir_check_temp_parameter(_9$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_10$$5);
			ZVAL_STRING(_10$$5, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _10$$5);
			zephir_check_temp_parameter(_10$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_9$$4);
		object_init_ex(_9$$4, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_11$$4, "strtr", &_12, 55, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_13$$4);
		ZVAL_STRING(_13$$4, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _9$$4, "__construct", &_14, 434, _11$$4, field, _13$$4);
		zephir_check_temp_parameter(_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _9$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_16 = zephir_is_true(_15);
	if (_16) {
		_17 = ZEPHIR_IS_EMPTY(value);
		if (!(_17)) {
			_18 = zephir_array_isset_string(value, SS("error"));
			if (_18) {
				zephir_array_fetch_string(&_19, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 75 TSRMLS_CC);
				_18 = ZEPHIR_IS_LONG_IDENTICAL(_19, 4);
			}
			_17 = _18;
		}
		_16 = _17;
	}
	if (_16) {
		RETURN_MM_BOOL(1);
	}
	_20 = !(zephir_array_isset_string(value, SS("error")));
	if (!(_20)) {
		_20 = !(zephir_array_isset_string(value, SS("tmp_name")));
	}
	_21 = _20;
	if (!(_21)) {
		zephir_array_fetch_string(&_22, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 79 TSRMLS_CC);
		_21 = !ZEPHIR_IS_LONG_IDENTICAL(_22, 0);
	}
	_23 = _21;
	if (!(_23)) {
		zephir_array_fetch_string(&_24, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 79 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_25, "is_uploaded_file", NULL, 229, _24);
		zephir_check_call_status();
		_23 = !zephir_is_true(_25);
	}
	if (_23) {
		ZEPHIR_INIT_VAR(_26$$7);
		ZVAL_STRING(_26$$7, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _26$$7);
		zephir_check_temp_parameter(_26$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_27$$8);
			ZVAL_STRING(_27$$8, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _27$$8);
			zephir_check_temp_parameter(_27$$8);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_26$$7);
		object_init_ex(_26$$7, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_28$$7, "strtr", &_12, 55, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_29$$7);
		ZVAL_STRING(_29$$7, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _26$$7, "__construct", &_14, 434, _28$$7, field, _29$$7);
		zephir_check_temp_parameter(_29$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _26$$7);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_30 = !(zephir_array_isset_string(value, SS("name")));
	if (!(_30)) {
		_30 = !(zephir_array_isset_string(value, SS("type")));
	}
	_31 = _30;
	if (!(_31)) {
		_31 = !(zephir_array_isset_string(value, SS("size")));
	}
	if (_31) {
		ZEPHIR_INIT_VAR(_32$$9);
		ZVAL_STRING(_32$$9, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _32$$9);
		zephir_check_temp_parameter(_32$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_33$$10);
			ZVAL_STRING(_33$$10, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _33$$10);
			zephir_check_temp_parameter(_33$$10);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_32$$9);
		object_init_ex(_32$$9, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_34$$9, "strtr", &_12, 55, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_35$$9);
		ZVAL_STRING(_35$$9, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _32$$9, "__construct", &_14, 434, _34$$9, field, _35$$9);
		zephir_check_temp_parameter(_35$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _32$$9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_36, this_ptr, "issetoption", NULL, 0, _0);
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
		ZEPHIR_INIT_VAR(_37$$11);
		ZVAL_STRING(_37$$11, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, 0, _37$$11);
		zephir_check_temp_parameter(_37$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_NVAR(_37$$11);
		ZEPHIR_INIT_VAR(_38$$11);
		ZEPHIR_INIT_VAR(_39$$11);
		zephir_array_keys(_39$$11, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_38$$11, SL("|"), _39$$11 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_40$$11);
		ZEPHIR_CONCAT_SVS(_40$$11, "/^([0-9]+(?:\\.[0-9]+)?)(", _38$$11, ")?$/Di");
		zephir_preg_match(_37$$11, _40$$11, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "phalcon/validation/validator/file.zep", 115 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_41$$11, matches, 1, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 118 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_42$$11, "floatval", &_43, 301, _41$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_44$$11);
		zephir_array_fetch(&_45$$11, byteUnits, unit, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 118 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_46$$11);
		ZVAL_LONG(&_46$$11, 2);
		zephir_pow_function(_44$$11, &_46$$11, _45$$11);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _42$$11, _44$$11 TSRMLS_CC);
		zephir_array_fetch_string(&_47$$11, value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 120 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_42$$11, "floatval", &_43, 301, _47$$11);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_48$$11, "floatval", &_43, 301, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_42$$11, _48$$11)) {
			ZEPHIR_INIT_VAR(_49$$13);
			ZVAL_STRING(_49$$13, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _49$$13);
			zephir_check_temp_parameter(_49$$13);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_VAR(_50$$14);
				ZVAL_STRING(_50$$14, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _50$$14);
				zephir_check_temp_parameter(_50$$14);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_49$$13);
			object_init_ex(_49$$13, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_51$$13, "strtr", &_12, 55, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_52$$13);
			ZVAL_STRING(_52$$13, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _49$$13, "__construct", &_14, 434, _51$$13, field, _52$$13);
			zephir_check_temp_parameter(_52$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _49$$13);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_53, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_53)) {
		ZEPHIR_INIT_VAR(_54$$15);
		ZVAL_STRING(_54$$15, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, 0, _54$$15);
		zephir_check_temp_parameter(_54$$15);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/validation/validator/file.zep", 138);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_VAR(_55$$17);
			ZVAL_LONG(&_55$$17, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 226, &_55$$17);
			zephir_check_call_status();
			zephir_array_fetch_string(&_56$$17, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 143 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 227, tmp, _56$$17);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 228, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "phalcon/validation/validator/file.zep", 147 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_57$$19);
			ZVAL_STRING(_57$$19, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _57$$19);
			zephir_check_temp_parameter(_57$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_57$$19);
			zephir_fast_join_str(_57$$19, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_57$$19, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_VAR(_58$$20);
				ZVAL_STRING(_58$$20, "FileType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _58$$20);
				zephir_check_temp_parameter(_58$$20);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_57$$19);
			object_init_ex(_57$$19, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_59$$19, "strtr", &_12, 55, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_60$$19);
			ZVAL_STRING(_60$$19, "FileType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _57$$19, "__construct", &_14, 434, _59$$19, field, _60$$19);
			zephir_check_temp_parameter(_60$$19);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _57$$19);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_61, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_62 = zephir_is_true(_61);
	if (!(_62)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_63, this_ptr, "issetoption", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		_62 = zephir_is_true(_63);
	}
	if (_62) {
		zephir_array_fetch_string(&_64$$21, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 164 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 237, _64$$21);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 165 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 166 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_66$$21);
		ZVAL_STRING(_66$$21, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_65$$21, this_ptr, "issetoption", NULL, 0, _66$$21);
		zephir_check_temp_parameter(_66$$21);
		zephir_check_call_status();
		if (zephir_is_true(_65$$21)) {
			ZEPHIR_INIT_VAR(_68$$22);
			ZVAL_STRING(_68$$22, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_67$$22, this_ptr, "getoption", NULL, 0, _68$$22);
			zephir_check_temp_parameter(_68$$22);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(minResolution);
			zephir_fast_explode_str(minResolution, SL("x"), _67$$22, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 170 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 171 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_69$$21 = ZEPHIR_LT(width, minWidth);
		if (!(_69$$21)) {
			_69$$21 = ZEPHIR_LT(height, minHeight);
		}
		if (_69$$21) {
			ZEPHIR_INIT_VAR(_70$$24);
			ZVAL_STRING(_70$$24, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _70$$24);
			zephir_check_temp_parameter(_70$$24);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_70$$24);
			ZVAL_STRING(_70$$24, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_71$$24, this_ptr, "getoption", NULL, 0, _70$$24);
			zephir_check_temp_parameter(_70$$24);
			zephir_check_call_status();
			zephir_array_update_string(&replacePairs, SL(":min"), &_71$$24, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_VAR(_72$$25);
				ZVAL_STRING(_72$$25, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _72$$25);
				zephir_check_temp_parameter(_72$$25);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_70$$24);
			object_init_ex(_70$$24, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_71$$24, "strtr", &_12, 55, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_73$$24);
			ZVAL_STRING(_73$$24, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _70$$24, "__construct", &_14, 434, _71$$24, field, _73$$24);
			zephir_check_temp_parameter(_73$$24);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _70$$24);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_66$$21);
		ZVAL_STRING(_66$$21, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_74$$21, this_ptr, "issetoption", NULL, 0, _66$$21);
		zephir_check_temp_parameter(_66$$21);
		zephir_check_call_status();
		if (zephir_is_true(_74$$21)) {
			ZEPHIR_INIT_VAR(_76$$26);
			ZVAL_STRING(_76$$26, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_75$$26, this_ptr, "getoption", NULL, 0, _76$$26);
			zephir_check_temp_parameter(_76$$26);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(maxResolution);
			zephir_fast_explode_str(maxResolution, SL("x"), _75$$26, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 192 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 193 TSRMLS_CC);
			_77$$26 = ZEPHIR_GT(width, maxWidth);
			if (!(_77$$26)) {
				_77$$26 = ZEPHIR_GT(height, maxHeight);
			}
			if (_77$$26) {
				ZEPHIR_INIT_VAR(_78$$27);
				ZVAL_STRING(_78$$27, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _78$$27);
				zephir_check_temp_parameter(_78$$27);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(replacePairs);
				zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_78$$27);
				ZVAL_STRING(_78$$27, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_79$$27, this_ptr, "getoption", NULL, 0, _78$$27);
				zephir_check_temp_parameter(_78$$27);
				zephir_check_call_status();
				zephir_array_update_string(&replacePairs, SL(":max"), &_79$$27, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_VAR(_80$$28);
					ZVAL_STRING(_80$$28, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _80$$28);
					zephir_check_temp_parameter(_80$$28);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_78$$27);
				object_init_ex(_78$$27, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_79$$27, "strtr", &_12, 55, message, replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_81$$27);
				ZVAL_STRING(_81$$27, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _78$$27, "__construct", &_14, 434, _79$$27, field, _81$$27);
				zephir_check_temp_parameter(_81$$27);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _78$$27);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

