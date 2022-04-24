
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Parser
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Token_Parser)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\JWT\\Token, Parser, phalcon, encryption_security_jwt_token_parser, phalcon_encryption_security_jwt_token_parser_method_entry, 0);

	return SUCCESS;
}

/**
 * Parse a token and return it
 *
 * @param string $token
 *
 * @return Token
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, parse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *token_param = NULL, claims, encodedClaims, encodedHeaders, encodedSignature, headers, results, signature;
	zval token;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&claims);
	ZVAL_UNDEF(&encodedClaims);
	ZVAL_UNDEF(&encodedHeaders);
	ZVAL_UNDEF(&encodedSignature);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&signature);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(token)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token_param);
	if (UNEXPECTED(Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(token_param) == IS_STRING)) {
		zephir_get_strval(&token, token_param);
	} else {
		ZEPHIR_INIT_VAR(&token);
	}


	ZEPHIR_CALL_METHOD(&results, this_ptr, "parsetoken", NULL, 282, &token);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&encodedHeaders);
	zephir_array_fetch_long(&encodedHeaders, &results, 0, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 33);
	ZEPHIR_OBS_VAR(&encodedClaims);
	zephir_array_fetch_long(&encodedClaims, &results, 1, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 34);
	ZEPHIR_OBS_VAR(&encodedSignature);
	zephir_array_fetch_long(&encodedSignature, &results, 2, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 35);
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "decodeheaders", NULL, 283, &encodedHeaders);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&claims, this_ptr, "decodeclaims", NULL, 284, &encodedClaims);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&signature, this_ptr, "decodesignature", NULL, 285, &headers, &encodedSignature);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_token_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 280, &headers, &claims, &signature);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Decode the claims
 *
 * @param string $claims
 *
 * @return Item
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decodeClaims)
{
	zval _4$$4;
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *claims_param = NULL, decoded, _0, _1, _3, _5$$4;
	zval claims;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&claims);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_4$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(claims)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &claims_param);
	zephir_get_strval(&claims, claims_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "decodeurl", NULL, 286, &claims);
	zephir_check_call_status();
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(&decoded, this_ptr, "decode", NULL, 287, &_0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&decoded) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid Claims (not an array)", "phalcon/Encryption/Security/JWT/Token/Parser.zep", 59);
		return;
	}
	_2 = zephir_array_isset_string(&decoded, SL("aud"));
	if (_2) {
		ZEPHIR_OBS_VAR(&_3);
		zephir_array_fetch_string(&_3, &decoded, SL("aud"), PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 65);
		_2 = Z_TYPE_P(&_3) != IS_ARRAY;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_create_array(&_4$$4, 1, 0);
		ZEPHIR_OBS_VAR(&_5$$4);
		zephir_array_fetch_string(&_5$$4, &decoded, SL("aud"), PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 66);
		zephir_array_fast_append(&_4$$4, &_5$$4);
		zephir_array_update_string(&decoded, SL("aud"), &_4$$4, PH_COPY | PH_SEPARATE);
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_item_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 278, &decoded, &claims);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Decodes the headers
 *
 * @param string $headers
 *
 * @return Item
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decodeHeaders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, decoded, _0, _1;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(headers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);
	zephir_get_strval(&headers, headers_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "decodeurl", NULL, 286, &headers);
	zephir_check_call_status();
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(&decoded, this_ptr, "decode", NULL, 287, &_0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&decoded) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid Header (not an array)", "phalcon/Encryption/Security/JWT/Token/Parser.zep", 88);
		return;
	}
	if (!(zephir_array_isset_string(&decoded, SL("typ")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid Header (missing 'typ' element)", "phalcon/Encryption/Security/JWT/Token/Parser.zep", 94);
		return;
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_item_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 278, &decoded, &headers);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Decodes the signature
 *
 * @param Item   $headers
 * @param string $signature
 *
 * @return Signature
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decodeSignature)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval signature;
	zval *headers, headers_sub, *signature_param = NULL, algo, decoded, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&algo);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&signature);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(headers, phalcon_encryption_security_jwt_token_item_ce)
		Z_PARAM_STR(signature)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &headers, &signature_param);
	zephir_get_strval(&signature, signature_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "alg");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "none");
	ZEPHIR_CALL_METHOD(&algo, headers, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "none");
	if (ZEPHIR_IS_IDENTICAL(&_2, &algo)) {
		ZEPHIR_INIT_VAR(&decoded);
		ZVAL_STRING(&decoded, "");
		ZEPHIR_INIT_NVAR(&signature);
	} else {
		ZEPHIR_CALL_METHOD(&decoded, this_ptr, "decodeurl", NULL, 286, &signature);
		zephir_check_call_status();
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_signature_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 279, &decoded, &signature);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Splits the token to its three parts;
 *
 * @param string $token
 *
 * @return array
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, parseToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *token_param = NULL, parts;
	zval token;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&parts);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(token)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token_param);
	if (UNEXPECTED(Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(token_param) == IS_STRING)) {
		zephir_get_strval(&token, token_param);
	} else {
		ZEPHIR_INIT_VAR(&token);
	}


	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("."), &token, LONG_MAX);
	if (zephir_fast_count_int(&parts) != 3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid JWT string (dots misalignment)", "phalcon/Encryption/Security/JWT/Token/Parser.zep", 140);
		return;
	}
	RETURN_CCTOR(&parts);
}

/**
 * @todo This will be removed when traits are introduced
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long depth, options, ZEPHIR_LAST_CALL_STATUS;
	zend_bool associative;
	zval *data_param = NULL, *associative_param = NULL, *depth_param = NULL, *options_param = NULL, decoded, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(associative)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &data_param, &associative_param, &depth_param, &options_param);
	if (UNEXPECTED(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(&data, data_param);
	} else {
		ZEPHIR_INIT_VAR(&data);
	}
	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}
	if (!options_param) {
		options = 0;
	} else {
		options = zephir_get_intval(options_param);
	}


	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	ZVAL_LONG(&_1, depth);
	ZVAL_LONG(&_2, options);
	ZEPHIR_INIT_VAR(&decoded);
	zephir_json_decode(&decoded, &data, zephir_get_intval(&_0) );
	ZEPHIR_CALL_FUNCTION(&_3, "json_last_error", NULL, 215);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&_3, 0))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "json_last_error_msg", NULL, 216);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "json_decode error: ", &_5$$3);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 40, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 163);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&decoded);
}

/**
 * @todo This will be removed when traits are introduced
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decodeUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, remainder = 0;
	zval *input_param = NULL, data, _3, _4, _5, _0$$3, _1$$3, _2$$3;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	if (UNEXPECTED(Z_TYPE_P(input_param) != IS_STRING && Z_TYPE_P(input_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'input' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(input_param) == IS_STRING)) {
		zephir_get_strval(&input, input_param);
	} else {
		ZEPHIR_INIT_VAR(&input);
	}


	remainder = (long) (zephir_safe_mod_long_long(zephir_fast_strlen_ev(&input), 4));
	if (remainder) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "=");
		ZVAL_LONG(&_1$$3, (4 - remainder));
		ZEPHIR_CALL_FUNCTION(&_2$$3, "str_repeat", NULL, 1, &_0$$3, &_1$$3);
		zephir_check_call_status();
		zephir_concat_self(&input, &_2$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "-_");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "+/");
	ZEPHIR_CALL_FUNCTION(&_5, "strtr", NULL, 5, &input, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&data, "base64_decode", NULL, 250, &_5);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		ZEPHIR_INIT_NVAR(&data);
		ZVAL_STRING(&data, "");
	}
	RETURN_CCTOR(&data);
}

