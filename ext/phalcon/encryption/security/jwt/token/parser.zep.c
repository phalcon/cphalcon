
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


	ZEPHIR_CALL_METHOD(&results, this_ptr, "parsetoken", NULL, 246, &token);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&encodedHeaders);
	zephir_array_fetch_long(&encodedHeaders, &results, 0, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 36);
	ZEPHIR_OBS_VAR(&encodedClaims);
	zephir_array_fetch_long(&encodedClaims, &results, 1, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 37);
	ZEPHIR_OBS_VAR(&encodedSignature);
	zephir_array_fetch_long(&encodedSignature, &results, 2, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 38);
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "decodeheaders", NULL, 247, &encodedHeaders);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&claims, this_ptr, "decodeclaims", NULL, 248, &encodedClaims);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&signature, this_ptr, "decodesignature", NULL, 249, &headers, &encodedSignature);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_token_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 244, &headers, &claims, &signature);
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
	zval _6$$4;
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *claims_param = NULL, decoded, _1, _3, _5, _7$$4;
	zval claims;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&claims);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_6$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(claims)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &claims_param);
	zephir_get_strval(&claims, claims_param);


	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_helper_base64_ce, "decodeurl", &_2, 250, &claims);
	zephir_check_call_status();
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_CE_STATIC(&decoded, phalcon_helper_json_ce, "decode", &_0, 188, &_1, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&decoded) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid Claims (not an array)", "phalcon/Encryption/Security/JWT/Token/Parser.zep", 62);
		return;
	}
	_4 = zephir_array_isset_string(&decoded, SL("aud"));
	if (_4) {
		ZEPHIR_OBS_VAR(&_5);
		zephir_array_fetch_string(&_5, &decoded, SL("aud"), PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 68);
		_4 = Z_TYPE_P(&_5) != IS_ARRAY;
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_create_array(&_6$$4, 1, 0);
		ZEPHIR_OBS_VAR(&_7$$4);
		zephir_array_fetch_string(&_7$$4, &decoded, SL("aud"), PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 69);
		zephir_array_fast_append(&_6$$4, &_7$$4);
		zephir_array_update_string(&decoded, SL("aud"), &_6$$4, PH_COPY | PH_SEPARATE);
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_item_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 242, &decoded, &claims);
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
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *headers_param = NULL, decoded, _1, _3;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(headers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);
	zephir_get_strval(&headers, headers_param);


	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_helper_base64_ce, "decodeurl", &_2, 250, &headers);
	zephir_check_call_status();
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_CE_STATIC(&decoded, phalcon_helper_json_ce, "decode", &_0, 188, &_1, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&decoded) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid Header (not an array)", "phalcon/Encryption/Security/JWT/Token/Parser.zep", 91);
		return;
	}
	if (!(zephir_array_isset_string(&decoded, SL("typ")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid Header (missing 'typ' element)", "phalcon/Encryption/Security/JWT/Token/Parser.zep", 97);
		return;
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_item_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 242, &decoded, &headers);
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
	zephir_fcall_cache_entry *_3 = NULL;
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
		ZEPHIR_CALL_CE_STATIC(&decoded, phalcon_helper_base64_ce, "decodeurl", &_3, 250, &signature);
		zephir_check_call_status();
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_signature_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 243, &decoded, &signature);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid JWT string (dots misalignment)", "phalcon/Encryption/Security/JWT/Token/Parser.zep", 143);
		return;
	}
	RETURN_CCTOR(&parts);
}

