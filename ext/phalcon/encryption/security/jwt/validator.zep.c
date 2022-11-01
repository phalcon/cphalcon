
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
#include "kernel/time.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Validator)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\JWT, Validator, phalcon, encryption_security_jwt_validator, phalcon_encryption_security_jwt_validator_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_encryption_security_jwt_validator_ce, SL("claims"), ZEND_ACC_PRIVATE);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_encryption_security_jwt_validator_ce, SL("errors"), ZEND_ACC_PRIVATE);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_encryption_security_jwt_validator_ce, SL("timeShift"), 0, ZEND_ACC_PRIVATE);
	/**
	 * @var Token
	 */
	zend_declare_property_null(phalcon_encryption_security_jwt_validator_ce, SL("token"), ZEND_ACC_PRIVATE);
	phalcon_encryption_security_jwt_validator_ce->create_object = zephir_init_properties_Phalcon_Encryption_Security_JWT_Validator;

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
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long timeShift;
	zval *token, token_sub, *timeShift_param = NULL, __$null, now, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&now);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(token, phalcon_encryption_security_jwt_token_token_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeShift)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &token, &timeShift_param);
	if (!timeShift_param) {
		timeShift = 0;
	} else {
		timeShift = zephir_get_intval(timeShift_param);
	}


	ZEPHIR_INIT_VAR(&now);
	zephir_time(&now);
	zephir_update_property_zval(this_ptr, ZEND_STRL("token"), token);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, timeShift);
	zephir_update_property_zval(this_ptr, ZEND_STRL("timeShift"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 7, 0);
	zephir_array_update_string(&_1, SL("aud"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("exp"), &now, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("jti"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("iat"), &now, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("iss"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("nbf"), &now, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("sub"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("claims"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, getErrors)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "errors");
}

PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *claim_param = NULL, _0, _1$$3, _2$$3;
	zval claim;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&claim);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(claim)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &claim_param);
	zephir_get_strval(&claim, claim_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &claim)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &claim, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/JWT/Validator.zep", 75);
		RETURN_CTOR(&_2$$3);
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *claim_param = NULL, *value, value_sub;
	zval claim;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&claim);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(claim)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &claim_param, &value);
	zephir_get_strval(&claim, claim_param);


	zephir_update_property_array(this_ptr, SL("claims"), &claim, value);
	RETURN_THIS();
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
 * @param string|array $audience
 *
 * @return Validator
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateAudience)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *audience = NULL, audience_sub, item, tokenAudience, _2, _3, _4, _5, *_6, _7, _1$$4, _8$$6, _9$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&audience_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tokenAudience);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(audience)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &audience);
	ZEPHIR_SEPARATE_PARAM(audience);


	_0 = Z_TYPE_P(audience) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(audience) != IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_security_jwt_exceptions_validatorexception_ce, "Audience must be a string or an array", "phalcon/Encryption/Security/JWT/Validator.zep", 113);
		return;
	}
	if (Z_TYPE_P(audience) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0);
		zephir_array_fast_append(&_1$$4, audience);
		ZEPHIR_CPY_WRT(audience, &_1$$4);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "aud");
	ZEPHIR_CALL_METHOD(&tokenAudience, &_3, "get", NULL, 0, &_5, &_4);
	zephir_check_call_status();
	zephir_is_iterable(audience, 0, "phalcon/Encryption/Security/JWT/Validator.zep", 128);
	if (Z_TYPE_P(audience) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(audience), _6)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _6);
			if (1 != zephir_fast_in_array(&item, &tokenAudience)) {
				ZEPHIR_INIT_ZVAL_NREF(_8$$6);
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_STRING(&_8$$6, "Validation: audience not allowed");
				zephir_update_property_array_append(this_ptr, SL("errors"), &_8$$6);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, audience, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, audience, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, audience, "current", NULL, 0);
			zephir_check_call_status();
				if (1 != zephir_fast_in_array(&item, &tokenAudience)) {
					ZEPHIR_INIT_ZVAL_NREF(_9$$8);
					ZEPHIR_INIT_NVAR(&_9$$8);
					ZVAL_STRING(&_9$$8, "Validation: audience not allowed");
					zephir_update_property_array_append(this_ptr, SL("errors"), &_9$$8);
				}
			ZEPHIR_CALL_METHOD(NULL, audience, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
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
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timestamp_param = NULL, _0, _1, _2, _3, _4, _5, _6, _8, _9, _10$$3;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS, tokenExpirationTime = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$3);
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
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	tokenExpirationTime = zephir_get_intval(&_2);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "exp");
	ZEPHIR_CALL_METHOD(&_6, &_5, "has", NULL, 0, &_3);
	zephir_check_call_status();
	_7 = zephir_is_true(&_6);
	if (_7) {
		ZVAL_LONG(&_9, timestamp);
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "gettimestamp", NULL, 264, &_9);
		zephir_check_call_status();
		_7 = ZEPHIR_GT_LONG(&_8, tokenExpirationTime);
	}
	if (_7) {
		ZEPHIR_INIT_ZVAL_NREF(_10$$3);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "Validation: the token has expired");
		zephir_update_property_array_append(this_ptr, SL("errors"), &_10$$3);
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
	zval *id_param = NULL, tokenId, _0, _1, _2, _3, _5$$3;
	zval id, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&tokenId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);
	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "jti");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_cast_to_string(&_4, &_2);
	ZEPHIR_CPY_WRT(&tokenId, &_4);
	if (!ZEPHIR_IS_IDENTICAL(&id, &tokenId)) {
		ZEPHIR_INIT_ZVAL_NREF(_5$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Validation: incorrect Id");
		zephir_update_property_array_append(this_ptr, SL("errors"), &_5$$3);
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
	zval *timestamp_param = NULL, _0, _1, _2, _3, _4, _5, _6$$3;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS, tokenIssuedAt = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
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
	ZVAL_STRING(&_3, "iat");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	tokenIssuedAt = zephir_get_intval(&_2);
	ZVAL_LONG(&_5, timestamp);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettimestamp", NULL, 264, &_5);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(&_4, tokenIssuedAt)) {
		ZEPHIR_INIT_ZVAL_NREF(_6$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Validation: the token cannot be used yet (future)");
		zephir_update_property_array_append(this_ptr, SL("errors"), &_6$$3);
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
	zval *issuer_param = NULL, tokenIssuer, _0, _1, _2, _3, _5$$3;
	zval issuer, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&issuer);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&tokenIssuer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);
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
	ZEPHIR_CPY_WRT(&tokenIssuer, &_4);
	if (!ZEPHIR_IS_IDENTICAL(&issuer, &tokenIssuer)) {
		ZEPHIR_INIT_ZVAL_NREF(_5$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Validation: incorrect issuer");
		zephir_update_property_array_append(this_ptr, SL("errors"), &_5$$3);
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
	zval *timestamp_param = NULL, _0, _1, _2, _3, _4, _5, _6$$3;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS, tokenNotBefore = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
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
	ZVAL_STRING(&_3, "nbf");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	tokenNotBefore = zephir_get_intval(&_2);
	ZVAL_LONG(&_5, timestamp);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettimestamp", NULL, 264, &_5);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(&_4, tokenNotBefore)) {
		ZEPHIR_INIT_ZVAL_NREF(_6$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Validation: the token cannot be used yet (not before)");
		zephir_update_property_array_append(this_ptr, SL("errors"), &_6$$3);
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
	zval *signer, signer_sub, *passphrase_param = NULL, _0, _1, _2, _3, _4, _5, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
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
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_ZVAL_NREF(_6$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Validation: the signature does not match");
		zephir_update_property_array_append(this_ptr, SL("errors"), &_6$$3);
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

zend_object *zephir_init_properties_Phalcon_Encryption_Security_JWT_Validator(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("errors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("errors"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("claims"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

