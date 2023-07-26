
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Token Class.
 *
 * A container for Token related data. It stores the claims, headers, signature
 * and payload. It also calculates and returns the token string.
 *
 * @link https://tools.ietf.org/html/rfc7519
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Token_Token)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\JWT\\Token, Token, phalcon, encryption_security_jwt_token_token, phalcon_encryption_security_jwt_token_token_method_entry, 0);

	/**
	 * @var Item
	 */
	zend_declare_property_null(phalcon_encryption_security_jwt_token_token_ce, SL("claims"), ZEND_ACC_PRIVATE);
	/**
	 * @var Item
	 */
	zend_declare_property_null(phalcon_encryption_security_jwt_token_token_ce, SL("headers"), ZEND_ACC_PRIVATE);
	/**
	 * @var Signature
	 */
	zend_declare_property_null(phalcon_encryption_security_jwt_token_token_ce, SL("signature"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * Token constructor.
 *
 * @param Item      $headers
 * @param Item      $claims
 * @param Signature $signature
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, __construct)
{
	zval *headers, headers_sub, *claims, claims_sub, *signature, signature_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&claims_sub);
	ZVAL_UNDEF(&signature_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(headers, phalcon_encryption_security_jwt_token_item_ce)
		Z_PARAM_OBJECT_OF_CLASS(claims, phalcon_encryption_security_jwt_token_item_ce)
		Z_PARAM_OBJECT_OF_CLASS(signature, phalcon_encryption_security_jwt_token_signature_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(3, 0, &headers, &claims, &signature);


	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), headers);
	zephir_update_property_zval(this_ptr, ZEND_STRL("claims"), claims);
	zephir_update_property_zval(this_ptr, ZEND_STRL("signature"), signature);
}

/**
 * @return Item
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getClaims)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "claims");
}

/**
 * @return Item
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getHeaders)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "headers");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getPayload)
{
	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getencoded", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getencoded", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_1, ".", &_3);
	RETURN_MM();
}

/**
 * @return Signature
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getSignature)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "signature");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getToken)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpayload", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsignature", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "getencoded", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_0, ".", &_2);
	RETURN_MM();
}

/**
 * @param Validator $validator
 *
 * @return array
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, validate)
{
	zend_string *_5;
	zend_ulong _4;
	zval methods;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validator, validator_sub, claimId, method, _0, _1, *_2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&claimId);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&methods);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_encryption_security_jwt_validator_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);


	ZEPHIR_INIT_VAR(&methods);
	zephir_create_array(&methods, 6, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "aud");
	ZEPHIR_CALL_METHOD(&_0, validator, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&methods, SL("validateAudience"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "exp");
	ZEPHIR_CALL_METHOD(&_0, validator, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&methods, SL("validateExpiration"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "jti");
	ZEPHIR_CALL_METHOD(&_0, validator, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&methods, SL("validateId"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "iat");
	ZEPHIR_CALL_METHOD(&_0, validator, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&methods, SL("validateIssuedAt"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "iss");
	ZEPHIR_CALL_METHOD(&_0, validator, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&methods, SL("validateIssuer"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nbf");
	ZEPHIR_CALL_METHOD(&_0, validator, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&methods, SL("validateNotBefore"), &_0, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&methods, 0, "phalcon/Encryption/Security/JWT/Token/Token.zep", 121);
	if (Z_TYPE_P(&methods) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methods), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&method, _5);
			} else {
				ZVAL_LONG(&method, _4);
			}
			ZEPHIR_INIT_NVAR(&claimId);
			ZVAL_COPY(&claimId, _2);
			ZEPHIR_CALL_METHOD_ZVAL(NULL, validator, &method, NULL, 0, &claimId);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &methods, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &methods, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&claimId, &methods, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_ZVAL(NULL, validator, &method, NULL, 0, &claimId);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&claimId);
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_RETURN_CALL_METHOD(validator, "geterrors", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Verify the signature
 *
 * @param SignerInterface $signer
 * @param string          $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, verify)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key;
	zval *signer, signer_sub, *key_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(signer, phalcon_encryption_security_jwt_signer_signerinterface_ce)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &signer, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, signer, "getalgheader", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "alg");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_0, &_2)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("signature"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "gethash", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getpayload", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(signer, "verify", NULL, 0, &_5, &_6, &key);
	zephir_check_call_status();
	RETURN_MM();
}

