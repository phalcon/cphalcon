
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Token Parser class.
 *
 * It parses a token by validating if it is formed properly and splits it into
 * three parts. The headers are decoded, then the claims and finally the
 * signature. It returns a token object populated with the decoded information.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Token_Parser)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\JWT\\Token, Parser, phalcon, encryption_security_jwt_token_parser, phalcon_encryption_security_jwt_token_parser_method_entry, 0);

	/**
	 * @var Decode
	 */
	zend_declare_property_null(phalcon_encryption_security_jwt_token_parser_ce, SL("decode"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *decode = NULL, decode_sub, __$null, service;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&decode_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&service);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(decode, phalcon_support_helper_json_decode_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &decode);
	if (!decode) {
		decode = &decode_sub;
		decode = &__$null;
	}
	ZEPHIR_CPY_WRT(&service, decode);
	if (Z_TYPE_P(&service) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&service);
		object_init_ex(&service, phalcon_support_helper_json_decode_ce);
		if (zephir_has_constructor(&service)) {
			ZEPHIR_CALL_METHOD(NULL, &service, "__construct", NULL, 0);
			zephir_check_call_status();
		}

	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("decode"), &service);
	ZEPHIR_MM_RESTORE();
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
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval token_zv, claims, encodedClaims, encodedHeaders, encodedSignature, headers, results, signature, _0;
	zend_string *token = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token_zv);
	ZVAL_UNDEF(&claims);
	ZVAL_UNDEF(&encodedClaims);
	ZVAL_UNDEF(&encodedHeaders);
	ZVAL_UNDEF(&encodedSignature);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&signature);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(token)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&token_zv);
	ZVAL_STR_COPY(&token_zv, token);
	ZEPHIR_CALL_METHOD(&results, this_ptr, "parsetoken", NULL, 0, &token_zv);
	zephir_check_call_status();
	zephir_memory_observe(&encodedHeaders);
	zephir_array_fetch_long(&encodedHeaders, &results, 0, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 59);
	zephir_memory_observe(&encodedClaims);
	zephir_array_fetch_long(&encodedClaims, &results, 1, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 60);
	zephir_memory_observe(&_0);
	zephir_array_fetch_long(&_0, &results, 2, PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 61);
	zephir_cast_to_string(&_1, &_0);
	ZEPHIR_CPY_WRT(&encodedSignature, &_1);
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "decodeheaders", NULL, 0, &encodedHeaders);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&claims, this_ptr, "decodeclaims", NULL, 0, &encodedClaims);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&signature, this_ptr, "decodesignature", NULL, 0, &headers, &encodedSignature);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_token_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &headers, &claims, &signature);
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
	zval claims_zv, decoded, _0, _1, _2, _5, _3$$3, _7$$4;
	zend_string *claims = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&claims_zv);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(claims)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&claims_zv);
	ZVAL_STR_COPY(&claims_zv, claims);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("decode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "decodeurl", NULL, 0, &claims_zv);
	zephir_check_call_status();
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(&decoded, &_0, "__invoke", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&decoded) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_encryption_security_jwt_exceptions_invalidclaims_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 83);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_array_isset_value_string(&decoded, SL("aud"));
	if (_4) {
		zephir_memory_observe(&_5);
		zephir_array_fetch_string(&_5, &decoded, SL("aud"), PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 89);
		_4 = Z_TYPE_P(&_5) != IS_ARRAY;
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_create_array(&_6$$4, 1, 0);
		zephir_memory_observe(&_7$$4);
		zephir_array_fetch_string(&_7$$4, &decoded, SL("aud"), PH_NOISY, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 90);
		zephir_array_fast_append(&_6$$4, &_7$$4);
		zephir_array_update_string(&decoded, SL("aud"), &_6$$4, PH_COPY | PH_SEPARATE);
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_item_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 510, &decoded, &claims_zv);
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
	zval headers_zv, decoded, _0, _1, _2, _3$$3, _4$$4;
	zend_string *headers = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_zv);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(headers)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&headers_zv);
	ZVAL_STR_COPY(&headers_zv, headers);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("decode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "decodeurl", NULL, 0, &headers_zv);
	zephir_check_call_status();
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(&decoded, &_0, "__invoke", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&decoded) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_encryption_security_jwt_exceptions_invalidheader_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 110);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_array_isset_value_string(&decoded, SL("typ")))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_encryption_security_jwt_exceptions_missingjwttypheader_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 114);
		ZEPHIR_MM_RESTORE();
		return;
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_item_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 510, &decoded, &headers_zv);
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
	zval _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *signature = NULL;
	zval *headers, headers_sub, signature_zv, algo, decoded, encodedSignature, _0, _1, _2, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&signature_zv);
	ZVAL_UNDEF(&algo);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&encodedSignature);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(headers, phalcon_encryption_security_jwt_token_item_ce)
		Z_PARAM_STR(signature)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	headers = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&signature_zv);
	ZVAL_STR_COPY(&signature_zv, signature);
	ZEPHIR_INIT_VAR(&decoded);
	ZVAL_STRING(&decoded, "");
	ZEPHIR_INIT_VAR(&encodedSignature);
	ZVAL_STRING(&encodedSignature, "");
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "alg");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "none");
	ZEPHIR_CALL_METHOD(&algo, headers, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "none");
	if (!ZEPHIR_IS_IDENTICAL(&_2, &algo)) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "decodeurl", NULL, 0, &signature_zv);
		zephir_check_call_status();
		zephir_cast_to_string(&_4$$3, &_3$$3);
		ZEPHIR_CPY_WRT(&decoded, &_4$$3);
		ZEPHIR_CPY_WRT(&encodedSignature, &signature_zv);
	}
	object_init_ex(return_value, phalcon_encryption_security_jwt_token_signature_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 511, &decoded, &encodedSignature);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval token_zv, parts, _0$$3;
	zend_string *token = NULL;

	ZVAL_UNDEF(&token_zv);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(token)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&token_zv);
	ZVAL_STR_COPY(&token_zv, token);
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("."), &token_zv, LONG_MAX);
	if (zephir_fast_count_int(&parts) != 3) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_encryption_security_jwt_exceptions_malformedjwtstring_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Encryption/Security/JWT/Token/Parser.zep", 158);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&parts);
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

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_CALL_FUNCTION(&_5, "strtr", NULL, 6, &input, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&data, "base64_decode", NULL, 472, &_5);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		ZEPHIR_INIT_NVAR(&data);
		ZVAL_STRING(&data, "");
	}
	RETURN_CCTOR(&data);
}

