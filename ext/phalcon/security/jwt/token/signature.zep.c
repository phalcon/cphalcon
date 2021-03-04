
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Item
 */
ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Token_Signature) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Security\\JWT\\Token, Signature, phalcon, security_jwt_token_signature, phalcon_security_jwt_token_abstractitem_ce, phalcon_security_jwt_token_signature_method_entry, 0);

	return SUCCESS;

}

/**
 * Signature constructor.
 *
 * @param string $hash
 * @param string $encoded
 */
PHP_METHOD(Phalcon_Security_JWT_Token_Signature, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *hash_param = NULL, *encoded_param = NULL, _0, _1;
	zval hash, encoded;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(hash)
		Z_PARAM_STR(encoded)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &hash_param, &encoded_param);

	if (!hash_param) {
		ZEPHIR_INIT_VAR(&hash);
		ZVAL_STRING(&hash, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(hash_param) != IS_STRING && Z_TYPE_P(hash_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hash' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(hash_param) == IS_STRING)) {
		zephir_get_strval(&hash, hash_param);
	} else {
		ZEPHIR_INIT_VAR(&hash);
		ZVAL_EMPTY_STRING(&hash);
	}
	}
	if (!encoded_param) {
		ZEPHIR_INIT_VAR(&encoded);
		ZVAL_STRING(&encoded, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(encoded_param) != IS_STRING && Z_TYPE_P(encoded_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoded' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoded_param) == IS_STRING)) {
		zephir_get_strval(&encoded, encoded_param);
	} else {
		ZEPHIR_INIT_VAR(&encoded);
		ZVAL_EMPTY_STRING(&encoded);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "encoded");
	zephir_update_property_array(this_ptr, SL("data"), &_0, &encoded);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "hash");
	zephir_update_property_array(this_ptr, SL("data"), &_1, &hash);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Token_Signature, getHash) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("hash"), PH_NOISY | PH_READONLY, "phalcon/Security/JWT/Token/Signature.zep", 35);
	RETURN_CTORW(&_1);

}

