
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
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
 * Class Validator
 *
 * @property int   $timeShift
 * @property Token $token
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Validator)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\JWT, Validator, phalcon, encryption_security_jwt_validator, phalcon_encryption_security_jwt_validator_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_encryption_security_jwt_validator_ce, SL("timeShift"), 0, ZEND_ACC_PRIVATE);
	/**
	 * @var Token
	 */
	zend_declare_property_null(phalcon_encryption_security_jwt_validator_ce, SL("token"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * Validator constructor.
 *
 * @param Token $token
 * @param int   $timeShift
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, __construct)
{
	zend_long timeShift;
	zval *token, token_sub, *timeShift_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(token, phalcon_encryption_security_jwt_token_token_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeShift)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 1, &token, &timeShift_param);
	if (!timeShift_param) {
		timeShift = 0;
	} else {
		timeShift = zephir_get_intval(timeShift_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("token"), token);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, timeShift);
	zephir_update_property_zval(this_ptr, ZEND_STRL("timeShift"), &_0);
}

/**
 * @param Token $token
 *
 * @return Validator
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, setToken)
{
	zval *token, token_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(token, phalcon_encryption_security_jwt_token_token_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &token);


	zephir_update_property_zval(this_ptr, ZEND_STRL("token"), token);
	RETURN_THISW();
}

/**
 * @param string $audience
 *
 * @return Validator
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateAudience)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *audience_param = NULL, _0, _1, _2, _3, _4;
	zval audience;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&audience);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(audience)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &audience_param);
	if (UNEXPECTED(Z_TYPE_P(audience_param) != IS_STRING && Z_TYPE_P(audience_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'audience' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(audience_param) == IS_STRING)) {
		zephir_get_strval(&audience, audience_param);
	} else {
		ZEPHIR_INIT_VAR(&audience);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "aud");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_4, &_3);
	zephir_check_call_status();
	if (!(zephir_fast_in_array(&audience, &_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_validatorexception_ce, "Validation: audience not allowed", "phalcon/Encryption/Security/JWT/Validator.zep", 71);
		return;
	}
	RETURN_THIS();
}

/**
 * @param int $timestamp
 *
 * @return Validator
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateExpiration)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timestamp_param = NULL, _0, _1, _2, _3, _5, _6, _7, _8;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timestamp_param);
	timestamp = zephir_get_intval(timestamp_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "exp");
	ZEPHIR_CALL_METHOD(&_2, &_1, "has", NULL, 0, &_3);
	zephir_check_call_status();
	_4 = zephir_is_true(&_2);
	if (_4) {
		ZVAL_LONG(&_6, timestamp);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "gettimestamp", NULL, 251, &_6);
		zephir_check_call_status();
		zephir_read_property(&_6, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7, &_6, "getclaims", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "exp");
		ZEPHIR_CALL_METHOD(&_8, &_7, "get", NULL, 0, &_3);
		zephir_check_call_status();
		_4 = ZEPHIR_GE_LONG(&_5, zephir_get_intval(&_8));
	}
	if (_4) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_validatorexception_ce, "Validation: the token has expired", "phalcon/Encryption/Security/JWT/Validator.zep", 91);
		return;
	}
	RETURN_THIS();
}

/**
 * @param string $id
 *
 * @return Validator
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0, _1, _2, _3;
	zval id, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);
	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "jti");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_cast_to_string(&_4, &_2);
	if (!ZEPHIR_IS_IDENTICAL(&id, &_4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_validatorexception_ce, "Validation: incorrect Id", "phalcon/Encryption/Security/JWT/Validator.zep", 108);
		return;
	}
	RETURN_THIS();
}

/**
 * @param int $timestamp
 *
 * @return Validator
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateIssuedAt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timestamp_param = NULL, _0, _1, _2, _3, _4;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timestamp_param);
	timestamp = zephir_get_intval(timestamp_param);


	ZVAL_LONG(&_1, timestamp);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettimestamp", NULL, 251, &_1);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "iat");
	ZEPHIR_CALL_METHOD(&_3, &_2, "get", NULL, 0, &_4);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(&_0, zephir_get_intval(&_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_validatorexception_ce, "Validation: the token cannot be used yet (future)", "phalcon/Encryption/Security/JWT/Validator.zep", 125);
		return;
	}
	RETURN_THIS();
}

/**
 * @param string $issuer
 *
 * @return Validator
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateIssuer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *issuer_param = NULL, _0, _1, _2, _3;
	zval issuer, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&issuer);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(issuer)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &issuer_param);
	if (UNEXPECTED(Z_TYPE_P(issuer_param) != IS_STRING && Z_TYPE_P(issuer_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'issuer' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(issuer_param) == IS_STRING)) {
		zephir_get_strval(&issuer, issuer_param);
	} else {
		ZEPHIR_INIT_VAR(&issuer);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "iss");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_cast_to_string(&_4, &_2);
	if (!ZEPHIR_IS_IDENTICAL(&issuer, &_4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_validatorexception_ce, "Validation: incorrect issuer", "phalcon/Encryption/Security/JWT/Validator.zep", 142);
		return;
	}
	RETURN_THIS();
}

/**
 * @param int $timestamp
 *
 * @return Validator
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateNotBefore)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timestamp_param = NULL, _0, _1, _2, _3, _4;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timestamp_param);
	timestamp = zephir_get_intval(timestamp_param);


	ZVAL_LONG(&_1, timestamp);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettimestamp", NULL, 251, &_1);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "nbf");
	ZEPHIR_CALL_METHOD(&_3, &_2, "get", NULL, 0, &_4);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(&_0, zephir_get_intval(&_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_validatorexception_ce, "Validation: the token cannot be used yet (not before)", "phalcon/Encryption/Security/JWT/Validator.zep", 159);
		return;
	}
	RETURN_THIS();
}

/**
 * @param SignerInterface $signer
 * @param string          $passphrase
 *
 * @return Validator
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateSignature)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval passphrase;
	zval *signer, signer_sub, *passphrase_param = NULL, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&passphrase);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(signer, phalcon_encryption_security_jwt_signer_signerinterface_ce)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &signer, &passphrase_param);
	zephir_get_strval(&passphrase, passphrase_param);


	zephir_read_property(&_1, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getsignature", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &_2, "gethash", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "getpayload", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, signer, "verify", NULL, 0, &_3, &_5, &passphrase);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_validatorexception_ce, "Validation: the signature does not match", "phalcon/Encryption/Security/JWT/Validator.zep", 183);
		return;
	}
	RETURN_THIS();
}

/**
 * @param int $timestamp
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, getTimestamp)
{
	zval *timestamp_param = NULL, _0;
	zend_long timestamp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &timestamp_param);
	timestamp = zephir_get_intval(timestamp_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("timeShift"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG((timestamp + zephir_get_numberval(&_0)));
}

