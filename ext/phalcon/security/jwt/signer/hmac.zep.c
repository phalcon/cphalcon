
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Hmac
 */
ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Signer_Hmac) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Security\\JWT\\Signer, Hmac, phalcon, security_jwt_signer_hmac, phalcon_security_jwt_signer_abstractsigner_ce, phalcon_security_jwt_signer_hmac_method_entry, 0);

	return SUCCESS;

}

/**
 * Hmac constructor.
 *
 * @param string $algo
 *
 * @throws UnsupportedAlgorithmException
 */
PHP_METHOD(Phalcon_Security_JWT_Signer_Hmac, __construct) {

	zval supported;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *algo_param = NULL;
	zval algo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&algo);
	ZVAL_UNDEF(&supported);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &algo_param);

	if (!algo_param) {
		ZEPHIR_INIT_VAR(&algo);
		ZVAL_STRING(&algo, "sha512");
	} else {
	if (UNEXPECTED(Z_TYPE_P(algo_param) != IS_STRING && Z_TYPE_P(algo_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'algo' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(algo_param) == IS_STRING)) {
		zephir_get_strval(&algo, algo_param);
	} else {
		ZEPHIR_INIT_VAR(&algo);
		ZVAL_EMPTY_STRING(&algo);
	}
	}


	ZEPHIR_INIT_VAR(&supported);
	zephir_create_array(&supported, 3, 0);
	add_assoc_long_ex(&supported, SL("sha512"), 1);
	add_assoc_long_ex(&supported, SL("sha384"), 1);
	add_assoc_long_ex(&supported, SL("sha256"), 1);
	if (!(zephir_array_isset(&supported, &algo))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_jwt_exceptions_unsupportedalgorithmexception_ce, "Unsupported HMAC algorithm", "phalcon/Security/JWT/Signer/Hmac.zep", 40);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("algorithm"), &algo);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the value that is used for the "alg" header
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Signer_Hmac, getAlgHeader) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("algorithm"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sha");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	zephir_fast_str_replace(&_0, &_2, &_3, &_1);
	ZEPHIR_CONCAT_SV(return_value, "HS", &_0);
	RETURN_MM();

}

/**
 * Sign a payload using the passphrase
 *
 * @param string $payload
 * @param string $passphrase
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Signer_Hmac, sign) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *payload_param = NULL, *passphrase_param = NULL;
	zval payload, passphrase;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&passphrase);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &payload_param, &passphrase_param);

	if (UNEXPECTED(Z_TYPE_P(payload_param) != IS_STRING && Z_TYPE_P(payload_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'payload' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(payload_param) == IS_STRING)) {
		zephir_get_strval(&payload, payload_param);
	} else {
		ZEPHIR_INIT_VAR(&payload);
		ZVAL_EMPTY_STRING(&payload);
	}
	if (UNEXPECTED(Z_TYPE_P(passphrase_param) != IS_STRING && Z_TYPE_P(passphrase_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'passphrase' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(passphrase_param) == IS_STRING)) {
		zephir_get_strval(&passphrase, passphrase_param);
	} else {
		ZEPHIR_INIT_VAR(&passphrase);
		ZVAL_EMPTY_STRING(&passphrase);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethash", NULL, 509, &payload, &passphrase);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Verify a passed source with a payload and passphrase
 *
 * @param string $source
 * @param string $payload
 * @param string $passphrase
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Security_JWT_Signer_Hmac, verify) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *payload_param = NULL, *passphrase_param = NULL, _0;
	zval source, payload, passphrase;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&passphrase);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &source_param, &payload_param, &passphrase_param);

	if (UNEXPECTED(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(&source, source_param);
	} else {
		ZEPHIR_INIT_VAR(&source);
		ZVAL_EMPTY_STRING(&source);
	}
	if (UNEXPECTED(Z_TYPE_P(payload_param) != IS_STRING && Z_TYPE_P(payload_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'payload' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(payload_param) == IS_STRING)) {
		zephir_get_strval(&payload, payload_param);
	} else {
		ZEPHIR_INIT_VAR(&payload);
		ZVAL_EMPTY_STRING(&payload);
	}
	if (UNEXPECTED(Z_TYPE_P(passphrase_param) != IS_STRING && Z_TYPE_P(passphrase_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'passphrase' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(passphrase_param) == IS_STRING)) {
		zephir_get_strval(&passphrase, passphrase_param);
	} else {
		ZEPHIR_INIT_VAR(&passphrase);
		ZVAL_EMPTY_STRING(&passphrase);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gethash", NULL, 509, &payload, &passphrase);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_hash_equals(&source, &_0));

}

/**
 * Calculates a hash from the passed parameters
 *
 * @param string $payload
 * @param string $passphrase
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Signer_Hmac, getHash) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *payload_param = NULL, *passphrase_param = NULL, __$true, _0;
	zval payload, passphrase;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&passphrase);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &payload_param, &passphrase_param);

	if (UNEXPECTED(Z_TYPE_P(payload_param) != IS_STRING && Z_TYPE_P(payload_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'payload' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(payload_param) == IS_STRING)) {
		zephir_get_strval(&payload, payload_param);
	} else {
		ZEPHIR_INIT_VAR(&payload);
		ZVAL_EMPTY_STRING(&payload);
	}
	if (UNEXPECTED(Z_TYPE_P(passphrase_param) != IS_STRING && Z_TYPE_P(passphrase_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'passphrase' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(passphrase_param) == IS_STRING)) {
		zephir_get_strval(&passphrase, passphrase_param);
	} else {
		ZEPHIR_INIT_VAR(&passphrase);
		ZVAL_EMPTY_STRING(&passphrase);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getalgorithm", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 186, &_0, &payload, &passphrase, &__$true);
	zephir_check_call_status();
	RETURN_MM();

}

