
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class None
 */
ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Signer_None) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Security\\JWT\\Signer, None, phalcon, security_jwt_signer_none, phalcon_security_jwt_signer_none_method_entry, 0);

	zend_class_implements(phalcon_security_jwt_signer_none_ce, 1, phalcon_security_jwt_signer_signerinterface_ce);
	return SUCCESS;

}

/**
 * Return the value that is used for the "alg" header
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Signer_None, getAlgHeader) {

	zval *this_ptr = getThis();



	RETURN_STRING("none");

}

/**
 * Return the algorithm used
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Signer_None, getAlgorithm) {

	zval *this_ptr = getThis();



	RETURN_STRING("None");

}

/**
 * Sign a payload using the passphrase
 *
 * @param string $payload
 * @param string $passphrase
 *
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Signer_None, sign) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *payload_param = NULL, *passphrase_param = NULL;
	zval payload, passphrase;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&passphrase);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(payload)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();

#endif


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
	zephir_get_strval(&passphrase, passphrase_param);


	RETURN_MM_STRING("");

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
PHP_METHOD(Phalcon_Security_JWT_Signer_None, verify) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *source_param = NULL, *payload_param = NULL, *passphrase_param = NULL, _0;
	zval source, payload, passphrase;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&passphrase);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(source)
		Z_PARAM_STR(payload)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();

#endif


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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_0, &source));

}

