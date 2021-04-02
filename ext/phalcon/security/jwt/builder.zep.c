
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "ext/spl/spl_exceptions.h"
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
 * Class Builder
 *
 * @property CollectionInterface  $claims
 * @property CollectionInterface  $jose
 * @property string               $passphrase
 * @property SignerInterface      $signer
 *
 * @link https://tools.ietf.org/html/rfc7519
 */
ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Builder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Security\\JWT, Builder, phalcon, security_jwt_builder, phalcon_security_jwt_builder_method_entry, 0);

	/**
	 * @var CollectionInterface
	 */
	zend_declare_property_null(phalcon_security_jwt_builder_ce, SL("claims"), ZEND_ACC_PRIVATE);

	/**
	 * @var CollectionInterface
	 */
	zend_declare_property_null(phalcon_security_jwt_builder_ce, SL("jose"), ZEND_ACC_PRIVATE);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_security_jwt_builder_ce, SL("passphrase"), ZEND_ACC_PRIVATE);

	/**
	 * @var SignerInterface
	 */
	zend_declare_property_null(phalcon_security_jwt_builder_ce, SL("signer"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * Builder constructor.
 *
 * @param SignerInterface $signer
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *signer, signer_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(signer, phalcon_security_jwt_signer_signerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &signer);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("signer"), signer);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("jose"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("signer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getalgheader", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "alg");
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return Builder
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, init) {

	zval _2;
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, ZEND_STRL("passphrase"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, phalcon_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 22);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("claims"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_collection_ce);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	add_assoc_stringl_ex(&_2, SL("typ"), SL("JWT"));
	add_assoc_stringl_ex(&_2, SL("alg"), SL("none"));
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 22, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("jose"), &_1);
	RETURN_THIS();

}

/**
 * @return array|string
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getAudience) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "aud");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getClaims) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getContentType) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("jose"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cty");
	ZVAL_NULL(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "string");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return int|null
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getExpirationTime) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "exp");
	ZVAL_NULL(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "int");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getHeaders) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("jose"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getId) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "jti");
	ZVAL_NULL(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "string");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return int|null
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getIssuedAt) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "iat");
	ZVAL_NULL(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "int");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getIssuer) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "iss");
	ZVAL_NULL(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "string");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return int|null
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getNotBefore) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "nbf");
	ZVAL_NULL(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "int");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return string|null
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getSubject) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sub");
	ZVAL_NULL(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "string");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return Token
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getToken) {

	zval claims, encodedClaims, encodedHeaders, encodedSignature, headers, signature, signatureHash, _0, _2, _4, _5, _6, _7, _8, _9, _10, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&claims);
	ZVAL_UNDEF(&encodedClaims);
	ZVAL_UNDEF(&encodedHeaders);
	ZVAL_UNDEF(&encodedSignature);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&signature);
	ZVAL_UNDEF(&signatureHash);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("passphrase"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_jwt_exceptions_validatorexception_ce, "Invalid passphrase (empty)", "phalcon/Security/JWT/Builder.zep", 183);
		return;
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_helper_json_ce, "encode", &_3, 14, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&encodedClaims, phalcon_helper_base64_ce, "encodeurl", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&claims);
	object_init_ex(&claims, phalcon_security_jwt_token_item_ce);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getclaims", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &claims, "__construct", NULL, 0, &_5, &encodedClaims);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_helper_json_ce, "encode", &_3, 14, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&encodedHeaders, phalcon_helper_base64_ce, "encodeurl", &_1, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&headers);
	object_init_ex(&headers, phalcon_security_jwt_token_item_ce);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &headers, "__construct", NULL, 0, &_8, &encodedHeaders);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, ZEND_STRL("signer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_VSV(&_10, &encodedHeaders, ".", &encodedClaims);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("passphrase"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&signatureHash, &_9, "sign", NULL, 0, &_10, &_11);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&encodedSignature, phalcon_helper_base64_ce, "encodeurl", &_1, 0, &signatureHash);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&signature);
	object_init_ex(&signature, phalcon_security_jwt_token_signature_ce);
	ZEPHIR_CALL_METHOD(NULL, &signature, "__construct", NULL, 0, &signatureHash, &encodedSignature);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_security_jwt_token_token_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &headers, &claims, &signature);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, getPassphrase) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "passphrase");

}

/**
 * The "aud" (audience) claim identifies the recipients that the JWT is
 * intended for.  Each principal intended to process the JWT MUST
 * identify itself with a value in the audience claim.  If the principal
 * processing the claim does not identify itself with a value in the
 * "aud" claim when this claim is present, then the JWT MUST be
 * rejected.  In the general case, the "aud" value is an array of case-
 * sensitive strings, each containing a StringOrURI value.  In the
 * special case when the JWT has one audience, the "aud" value MAY be a
 * single case-sensitive string containing a StringOrURI value.  The
 * interpretation of audience values is generally application specific.
 * Use of this claim is OPTIONAL.
 *
 * @param mixed $audience
 *
 * @return Builder
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setAudience) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *audience, audience_sub, aud, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&audience_sub);
	ZVAL_UNDEF(&aud);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(audience)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &audience);



	_0 = Z_TYPE_P(audience) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(audience) != IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_jwt_exceptions_validatorexception_ce, "Invalid Audience", "phalcon/Security/JWT/Builder.zep", 233);
		return;
	}
	if (Z_TYPE_P(audience) == IS_STRING) {
		ZEPHIR_INIT_VAR(&aud);
		zephir_create_array(&aud, 1, 0);
		zephir_array_fast_append(&aud, audience);
	} else {
		ZEPHIR_CPY_WRT(&aud, audience);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "aud");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setclaim", NULL, 0, &_1, &aud);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the content type header 'cty'
 *
 * @param string $contentType
 *
 * @return Builder
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setContentType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *contentType_param = NULL, _0, _1;
	zval contentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(contentType)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contentType_param);

	zephir_get_strval(&contentType, contentType_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("jose"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cty");
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, &contentType);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * The "exp" (expiration time) claim identifies the expiration time on
 * or after which the JWT MUST NOT be accepted for processing.  The
 * processing of the "exp" claim requires that the current date/time
 * MUST be before the expiration date/time listed in the "exp" claim.
 * Implementers MAY provide for some small leeway, usually no more than
 * a few minutes, to account for clock skew.  Its value MUST be a number
 * containing a NumericDate value.  Use of this claim is OPTIONAL.
 *
 * @param int $timestamp
 *
 * @return Builder
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setExpirationTime) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timestamp_param = NULL, _0, _1, _2;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timestamp_param);

	timestamp = zephir_get_intval(timestamp_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	if (ZEPHIR_GT_LONG(&_0, timestamp)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_jwt_exceptions_validatorexception_ce, "Invalid Expiration Time", "phalcon/Security/JWT/Builder.zep", 278);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "exp");
	ZVAL_LONG(&_2, timestamp);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setclaim", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * The "jti" (JWT ID) claim provides a unique identifier for the JWT.
 * The identifier value MUST be assigned in a manner that ensures that
 * there is a negligible probability that the same value will be
 * accidentally assigned to a different data object; if the application
 * uses multiple issuers, collisions MUST be prevented among values
 * produced by different issuers as well.  The "jti" claim can be used
 * to prevent the JWT from being replayed.  The "jti" value is a case-
 * sensitive string.  Use of this claim is OPTIONAL.
 *
 * @param string $id
 *
 * @return Builder
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
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
		ZVAL_EMPTY_STRING(&id);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "jti");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setclaim", NULL, 0, &_0, &id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * The "iat" (issued at) claim identifies the time at which the JWT was
 * issued.  This claim can be used to determine the age of the JWT.  Its
 * value MUST be a number containing a NumericDate value.  Use of this
 * claim is OPTIONAL.
 *
 * @param int $timestamp
 *
 * @return Builder
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setIssuedAt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timestamp_param = NULL, _0, _1;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timestamp_param);

	if (UNEXPECTED(Z_TYPE_P(timestamp_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'timestamp' must be of the type int"));
		RETURN_MM_NULL();
	}
	timestamp = Z_LVAL_P(timestamp_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "iat");
	ZVAL_LONG(&_1, timestamp);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setclaim", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * The "iss" (issuer) claim identifies the principal that issued the
 * JWT.  The processing of this claim is generally application specific.
 * The "iss" value is a case-sensitive string containing a StringOrURI
 * value.  Use of this claim is OPTIONAL.
 *
 * @param string $issuer
 *
 * @return Builder
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setIssuer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *issuer_param = NULL, _0;
	zval issuer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&issuer);
	ZVAL_UNDEF(&_0);
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
		ZVAL_EMPTY_STRING(&issuer);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "iss");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setclaim", NULL, 0, &_0, &issuer);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * The "nbf" (not before) claim identifies the time before which the JWT
 * MUST NOT be accepted for processing.  The processing of the "nbf"
 * claim requires that the current date/time MUST be after or equal to
 * the not-before date/time listed in the "nbf" claim.  Implementers MAY
 * provide for some small leeway, usually no more than a few minutes, to
 * account for clock skew.  Its value MUST be a number containing a
 * NumericDate value.  Use of this claim is OPTIONAL.
 *
 * @param int $timestamp
 *
 * @return Builder
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setNotBefore) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timestamp_param = NULL, _0, _1, _2;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timestamp_param);

	if (UNEXPECTED(Z_TYPE_P(timestamp_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'timestamp' must be of the type int"));
		RETURN_MM_NULL();
	}
	timestamp = Z_LVAL_P(timestamp_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	if (ZEPHIR_LT_LONG(&_0, timestamp)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_jwt_exceptions_validatorexception_ce, "Invalid Not Before", "phalcon/Security/JWT/Builder.zep", 352);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "nbf");
	ZVAL_LONG(&_2, timestamp);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setclaim", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * The "sub" (subject) claim identifies the principal that is the
 * subject of the JWT.  The claims in a JWT are normally statements
 * about the subject.  The subject value MUST either be scoped to be
 * locally unique in the context of the issuer or be globally unique.
 * The processing of this claim is generally application specific.  The
 * "sub" value is a case-sensitive string containing a StringOrURI
 * value.  Use of this claim is OPTIONAL.
 *
 * @param string $subject
 *
 * @return Builder
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setSubject) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subject_param = NULL, _0;
	zval subject;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subject);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(subject)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &subject_param);

	if (UNEXPECTED(Z_TYPE_P(subject_param) != IS_STRING && Z_TYPE_P(subject_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'subject' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(subject_param) == IS_STRING)) {
		zephir_get_strval(&subject, subject_param);
	} else {
		ZEPHIR_INIT_VAR(&subject);
		ZVAL_EMPTY_STRING(&subject);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sub");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setclaim", NULL, 0, &_0, &subject);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $passphrase
 *
 * @return Builder
 * @throws ValidatorException
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setPassphrase) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *passphrase_param = NULL, _0, _1, _2, _3;
	zval passphrase;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&passphrase);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(passphrase)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &passphrase_param);

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
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/(?=^.{16,}$)((?=.*\\d)|(?=.*\\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$/");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/(?=^.{16,}$)((?=.*\\d)|(?=.*\\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$/");
	zephir_preg_match(&_2, &_3, &passphrase, &_0, 0, 0 , 0 );
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_jwt_exceptions_validatorexception_ce, "Invalid passphrase (too weak)", "phalcon/Security/JWT/Builder.zep", 390);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("passphrase"), &passphrase);
	RETURN_THIS();

}

/**
 * Sets a registered claim
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return Builder
 */
PHP_METHOD(Phalcon_Security_JWT_Builder, setClaim) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("claims"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

