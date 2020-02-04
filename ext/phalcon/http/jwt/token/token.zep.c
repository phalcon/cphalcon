
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
#include "kernel/concat.h"
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
 * Class Token
 *
 * @property Item      $claims
 * @property Item      $headers
 * @property Signature $signature
 *
 * @link https://tools.ietf.org/html/rfc7519
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_JWT_Token_Token) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\JWT\\Token, Token, phalcon, http_jwt_token_token, phalcon_http_jwt_token_token_method_entry, 0);

	/**
	 * @var Item
	 */
	zend_declare_property_null(phalcon_http_jwt_token_token_ce, SL("claims"), ZEND_ACC_PRIVATE);

	/**
	 * @var Item
	 */
	zend_declare_property_null(phalcon_http_jwt_token_token_ce, SL("headers"), ZEND_ACC_PRIVATE);

	/**
	 * @var Signature
	 */
	zend_declare_property_null(phalcon_http_jwt_token_token_ce, SL("signature"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Http_JWT_Token_Token, getClaims) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "claims");

}

/**
 */
PHP_METHOD(Phalcon_Http_JWT_Token_Token, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

/**
 */
PHP_METHOD(Phalcon_Http_JWT_Token_Token, getSignature) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "signature");

}

/**
 * Token constructor.
 *
 * @param Item      $headers
 * @param Item      $claims
 * @param Signature $signature
 */
PHP_METHOD(Phalcon_Http_JWT_Token_Token, __construct) {

	zval *headers, headers_sub, *claims, claims_sub, *signature, signature_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&claims_sub);
	ZVAL_UNDEF(&signature_sub);

	zephir_fetch_params_without_memory_grow(3, 0, &headers, &claims, &signature);



	zephir_update_property_zval(this_ptr, SL("headers"), headers);
	zephir_update_property_zval(this_ptr, SL("claims"), claims);
	zephir_update_property_zval(this_ptr, SL("signature"), signature);

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Http_JWT_Token_Token, getPayload) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getencoded", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getencoded", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_1, ".", &_3);
	RETURN_MM();

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Http_JWT_Token_Token, getToken) {

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

