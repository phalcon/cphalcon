
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
 * No signing class
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Signer_None)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\JWT\\Signer, None, phalcon, encryption_security_jwt_signer_none, phalcon_encryption_security_jwt_signer_none_method_entry, 0);

	zend_class_implements(phalcon_encryption_security_jwt_signer_none_ce, 1, phalcon_encryption_security_jwt_signer_signerinterface_ce);
	return SUCCESS;
}

/**
 * Return the value that is used for the "alg" header
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_None, getAlgHeader)
{

	RETURN_STRING("none");
}

/**
 * Return the algorithm used
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_None, getAlgorithm)
{

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
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_None, sign)
{
	zval payload_zv, passphrase_zv;
	zend_string *payload = NULL, *passphrase = NULL;

	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&passphrase_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(payload)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&payload_zv, payload);
	ZVAL_STR(&passphrase_zv, passphrase);
	RETURN_STRING("");
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
PHP_METHOD(Phalcon_Encryption_Security_JWT_Signer_None, verify)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval source_zv, payload_zv, passphrase_zv, _0;
	zend_string *source = NULL, *payload = NULL, *passphrase = NULL;

	ZVAL_UNDEF(&source_zv);
	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&passphrase_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(source)
		Z_PARAM_STR(payload)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&source_zv);
	ZVAL_STR_COPY(&source_zv, source);
	zephir_memory_observe(&payload_zv);
	ZVAL_STR_COPY(&payload_zv, payload);
	zephir_memory_observe(&passphrase_zv);
	ZVAL_STR_COPY(&passphrase_zv, passphrase);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_0, &source_zv));
}

