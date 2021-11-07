
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * PSR-7 Uri
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Uri)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message, Uri, phalcon, http_message_uri, phalcon_http_message_abstractcommon_ce, phalcon_http_message_uri_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * Returns the fragment of the URL
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("fragment"), "", ZEND_ACC_PROTECTED);
	/**
	 * Retrieve the host component of the URI.
	 *
	 * If no host is present, this method MUST return an empty string.
	 *
	 * The value returned MUST be normalized to lowercase, per RFC 3986
	 * Section 3.2.2.
	 *
	 * @see http://tools.ietf.org/html/rfc3986#section-3.2.2
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("host"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("pass"), "", ZEND_ACC_PROTECTED);
	/**
	 * Returns the path of the URL
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("path"), "", ZEND_ACC_PROTECTED);
	/**
	 * Retrieve the port component of the URI.
	 *
	 * If a port is present, and it is non-standard for the current scheme,
	 * this method MUST return it as an integer. If the port is the standard
	 * port used with the current scheme, this method SHOULD return null.
	 *
	 * If no port is present, and no scheme is present, this method MUST return
	 * a null value.
	 *
	 * If no port is present, but a scheme is present, this method MAY return
	 * the standard port for that scheme, but SHOULD return null.
	 *
	 * @var int|null
	 */
	zend_declare_property_null(phalcon_http_message_uri_ce, SL("port"), ZEND_ACC_PROTECTED);
	/**
	 * Returns the query of the URL
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("query"), "", ZEND_ACC_PROTECTED);
	/**
	 * Retrieve the scheme component of the URI.
	 *
	 * If no scheme is present, this method MUST return an empty string.
	 *
	 * The value returned MUST be normalized to lowercase, per RFC 3986
	 * Section 3.1.
	 *
	 * The trailing ":" character is not part of the scheme and MUST NOT be
	 * added.
	 *
	 * @see https://tools.ietf.org/html/rfc3986#section-3.1
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("scheme"), "https", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("user"), "", ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_http_message_uri_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uriinterface")));
	return SUCCESS;
}

/**
 * Returns the fragment of the URL
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getFragment)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "fragment");
}

/**
 * Retrieve the host component of the URI.
 *
 *
 * If no host is present, this method MUST return an empty string.
 * 
 * The value returned MUST be normalized to lowercase, per RFC 3986
 * Section 3.2.2.
 *
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getHost)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "host");
}

/**
 * Returns the path of the URL
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "path");
}

/**
 * Retrieve the port component of the URI.
 *
 *
 * If a port is present, and it is non-standard for the current scheme,
 * this method MUST return it as an integer. If the port is the standard
 * port used with the current scheme, this method SHOULD return null.
 * 
 * If no port is present, and no scheme is present, this method MUST return
 * a null value.
 * 
 * If no port is present, but a scheme is present, this method MAY return
 * the standard port for that scheme, but SHOULD return null.
 *
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getPort)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "port");
}

/**
 * Returns the query of the URL
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getQuery)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "query");
}

/**
 * Retrieve the scheme component of the URI.
 *
 *
 * If no scheme is present, this method MUST return an empty string.
 * 
 * The value returned MUST be normalized to lowercase, per RFC 3986
 * Section 3.1.
 * 
 * The trailing ":" character is not part of the scheme and MUST NOT be
 * added.
 *
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getScheme)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "scheme");
}

/**
 * Uri constructor.
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Http_Message_Uri, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, urlParts, _0, _1$$3, _2$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, _20$$3;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&urlParts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);
	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_0, &uri))) {
		ZEPHIR_CALL_FUNCTION(&urlParts, "parse_url", NULL, 122, &uri);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&urlParts))) {
			ZEPHIR_INIT_NVAR(&urlParts);
			array_init(&urlParts);
		}
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "fragment");
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_helper_arr_ce, "get", &_3, 81, &urlParts, &_4$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "filterfragment", NULL, 375, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("fragment"), &_1$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "host");
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "");
		ZEPHIR_CALL_CE_STATIC(&_6$$3, phalcon_helper_arr_ce, "get", &_3, 81, &urlParts, &_5$$3, &_7$$3);
		zephir_check_call_status();
		zephir_fast_strtolower(&_4$$3, &_6$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &_4$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "pass");
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "");
		ZEPHIR_CALL_CE_STATIC(&_8$$3, phalcon_helper_arr_ce, "get", &_3, 81, &urlParts, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9$$3, "rawurlencode", NULL, 323, &_8$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("pass"), &_9$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "path");
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "");
		ZEPHIR_CALL_CE_STATIC(&_11$$3, phalcon_helper_arr_ce, "get", &_3, 81, &urlParts, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10$$3, this_ptr, "filterpath", NULL, 376, &_11$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_10$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "port");
		ZVAL_NULL(&_14$$3);
		ZEPHIR_CALL_CE_STATIC(&_13$$3, phalcon_helper_arr_ce, "get", &_3, 81, &urlParts, &_5$$3, &_14$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12$$3, this_ptr, "filterport", NULL, 377, &_13$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &_12$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "query");
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "");
		ZEPHIR_CALL_CE_STATIC(&_16$$3, phalcon_helper_arr_ce, "get", &_3, 81, &urlParts, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$3, this_ptr, "filterquery", NULL, 378, &_16$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("query"), &_15$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "scheme");
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "");
		ZEPHIR_CALL_CE_STATIC(&_18$$3, phalcon_helper_arr_ce, "get", &_3, 81, &urlParts, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_17$$3, this_ptr, "filterscheme", NULL, 379, &_18$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("scheme"), &_17$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "user");
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "");
		ZEPHIR_CALL_CE_STATIC(&_19$$3, phalcon_helper_arr_ce, "get", &_3, 81, &urlParts, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_20$$3, "rawurlencode", NULL, 323, &_19$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &_20$$3);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Return the string representation as a URI reference.
 *
 * Depending on which components of the URI are present, the resulting
 * string is either a full URI or relative reference according to RFC 3986,
 * Section 4.1. The method concatenates the various components of the URI,
 * using the appropriate delimiters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Uri, __toString)
{
	zend_bool _2, _3;
	zval authority, path, uri, _0, _1, _4, _6, _7, _8, _9, _10, _11, _12, _13, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&authority);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_5$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&authority, this_ptr, "getauthority", NULL, 380);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&path, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	_2 = !ZEPHIR_IS_IDENTICAL(&_1, &path);
	if (_2) {
		_2 = 1 != zephir_start_with_str(&path, SL("/"));
	}
	_3 = _2;
	if (_3) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "");
		_3 = !ZEPHIR_IS_IDENTICAL(&_4, &authority);
	}
	if (UNEXPECTED(_3)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "/", &path);
		ZEPHIR_CPY_WRT(&path, &_5$$3);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, ":");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "checkvalue", NULL, 381, &_0, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "//");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "checkvalue", NULL, 381, &authority, &_7);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, ZEND_STRL("query"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "?");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "checkvalue", NULL, 381, &_11, &_7);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, ZEND_STRL("fragment"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "#");
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "checkvalue", NULL, 381, &_13, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&uri);
	ZEPHIR_CONCAT_VVVVV(&uri, &_6, &_9, &path, &_10, &_12);
	RETURN_CCTOR(&uri);
}

/**
 * Retrieve the authority component of the URI.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getAuthority)
{
	zval authority, userInfo, _0, _1, _2, _4, _3$$4, _5$$5, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&authority);
	ZVAL_UNDEF(&userInfo);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("host"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	if (UNEXPECTED(ZEPHIR_IS_IDENTICAL(&_1, &_0))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_OBS_VAR(&authority);
	zephir_read_property(&authority, this_ptr, ZEND_STRL("host"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&userInfo, this_ptr, "getuserinfo", NULL, 382);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_2, &userInfo))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_VSV(&_3$$4, &userInfo, "@", &authority);
		ZEPHIR_CPY_WRT(&authority, &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_4) != IS_NULL)) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_CONCAT_SV(&_6$$5, ":", &_5$$5);
		zephir_concat_self(&authority, &_6$$5);
	}
	RETURN_CCTOR(&authority);
}

/**
 * Retrieve the user information component of the URI.
 *
 * If no user information is present, this method MUST return an empty
 * string.
 *
 * If a user is present in the URI, this will return that value;
 * additionally, if the password is also present, it will be appended to the
 * user value, with a colon (":") separating the values.
 *
 * The trailing "@" character is not part of the user information and MUST
 * NOT be added.
 *
 * @return string The URI user information, in "username[:password]" format.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getUserInfo)
{
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pass"), PH_NOISY_CC);
	if (UNEXPECTED(1 != ZEPHIR_IS_EMPTY(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("pass"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSV(return_value, &_1$$3, ":", &_2$$3);
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "user");
}

/**
 * Return an instance with the specified URI fragment.
 *
 * This method MUST retain the state of the current instance, and return
 * an instance that contains the specified URI fragment.
 *
 * Users can provide both encoded and decoded fragment characters.
 * Implementations ensure the correct encoding as outlined in getFragment().
 *
 * An empty fragment value is equivalent to removing the fragment.
 *
 * @param string $fragment
 *
 * @return Uri
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withFragment)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment = NULL, fragment_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(fragment)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fragment);
	ZEPHIR_SEPARATE_PARAM(fragment);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 21, fragment);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterfragment", NULL, 375, fragment);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(fragment, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "fragment");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, fragment, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specified path.
 *
 * This method MUST retain the state of the current instance, and return
 * an instance that contains the specified path.
 *
 * The path can either be empty or absolute (starting with a slash) or
 * rootless (not starting with a slash). Implementations MUST support all
 * three syntaxes.
 *
 * If an HTTP path is intended to be host-relative rather than path-relative
 * then it must begin with a slash ("/"). HTTP paths not starting with a
 * slash are assumed to be relative to some base path known to the
 * application or consumer.
 *
 * Users can provide both encoded and decoded path characters.
 * Implementations ensure the correct encoding as outlined in getPath().
 *
 * @param string $path
 *
 * @return Uri
 * @throws InvalidArgumentException for invalid paths.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withPath)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, _0, _1, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);
	ZEPHIR_SEPARATE_PARAM(path);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 21, path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "?");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, path, &_0, 0 );
	_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "#");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, path, &_3, 0 );
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	if (UNEXPECTED(_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Path cannot contain a query string or fragment", "phalcon/Http/Message/Uri.zep", 290);
		return;
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "filterpath", NULL, 376, path);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(path, &_5);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "path");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, path, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specified port.
 *
 * This method MUST retain the state of the current instance, and return
 * an instance that contains the specified port.
 *
 * Implementations MUST raise an exception for ports outside the
 * established TCP and UDP port ranges.
 *
 * A null value provided for the port is equivalent to removing the port
 * information.
 *
 * @param int|null $port
 *
 * @return Uri
 * @throws InvalidArgumentException for invalid ports.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withPort)
{
	zend_bool _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *port = NULL, port_sub, _0$$3, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(port)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);
	ZEPHIR_SEPARATE_PARAM(port);


	if (UNEXPECTED(Z_TYPE_P(port) != IS_NULL)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "filterport", NULL, 377, port);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(port, &_0$$3);
		_1$$3 = Z_TYPE_P(port) != IS_NULL;
		if (_1$$3) {
			_2$$3 = ZEPHIR_LT_LONG(port, 1);
			if (!(_2$$3)) {
				_2$$3 = ZEPHIR_GT_LONG(port, 65535);
			}
			_1$$3 = _2$$3;
		}
		if (UNEXPECTED(_1$$3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Method expects valid port (1-65535)", "phalcon/Http/Message/Uri.zep", 323);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "port");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, port, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specified query string.
 *
 * This method MUST retain the state of the current instance, and return
 * an instance that contains the specified query string.
 *
 * Users can provide both encoded and decoded query characters.
 * Implementations ensure the correct encoding as outlined in getQuery().
 *
 * An empty query string value is equivalent to removing the query string.
 *
 * @param string $query
 *
 * @return Uri
 * @throws InvalidArgumentException for invalid query strings.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withQuery)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, query_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(query)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);
	ZEPHIR_SEPARATE_PARAM(query);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 21, query);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "#");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, query, &_0, 0 );
	if (UNEXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Query cannot contain a query fragment", "phalcon/Http/Message/Uri.zep", 353);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "filterquery", NULL, 378, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "query");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, query, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specified scheme.
 *
 * This method MUST retain the state of the current instance, and return
 * an instance that contains the specified scheme.
 *
 * Implementations MUST support the schemes "http" and "https" case
 * insensitively, and MAY accommodate other schemes if required.
 *
 * An empty scheme is equivalent to removing the scheme.
 *
 * @param string $scheme
 *
 * @return Uri
 * @throws InvalidArgumentException for invalid schemes.
 * @throws InvalidArgumentException for unsupported schemes.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withScheme)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *scheme = NULL, scheme_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(scheme)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme);
	ZEPHIR_SEPARATE_PARAM(scheme);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 21, scheme);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterscheme", NULL, 379, scheme);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(scheme, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "scheme");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processwith", NULL, 383, scheme, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specified user information.
 *
 * @param string      $user
 * @param string|null $password
 *
 * @return Uri
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withUserInfo)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user = NULL, user_sub, *password = NULL, password_sub, __$null, newInstance, _0, _2, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&password_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(user)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(password)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &password);
	ZEPHIR_SEPARATE_PARAM(user);
	if (!password) {
		password = &password_sub;
		ZEPHIR_CPY_WRT(password, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(password);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 21, user);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(password) != IS_NULL)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 21, user);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_0, "rawurlencode", NULL, 323, user);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(user, &_0);
	if (UNEXPECTED(Z_TYPE_P(password) != IS_NULL)) {
		ZEPHIR_CALL_FUNCTION(&_1$$4, "rawurlencode", NULL, 323, password);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(password, &_1$$4);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "user");
	ZEPHIR_CALL_METHOD(&newInstance, this_ptr, "cloneinstance", NULL, 22, user, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(&newInstance, ZEND_STRL("pass"), password);
	RETURN_CCTOR(&newInstance);
}

/**
 * Return an instance with the specified host.
 *
 * This method MUST retain the state of the current instance, and return
 * an instance that contains the specified host.
 *
 * An empty host value is equivalent to removing the host.
 *
 * @param string $host
 *
 * @return Uri
 * @throws InvalidArgumentException for invalid hostnames.
 *
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withHost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *host, host_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(host)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "host");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processwith", NULL, 383, host, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * If the value passed is empty it returns it prefixed and suffixed with
 * the passed parameters
 *
 * @param string $value
 * @param string $prefix
 * @param string $suffix
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Uri, checkValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value_param = NULL, *prefix_param = NULL, *suffix_param = NULL, _0;
	zval value, prefix, suffix, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
		Z_PARAM_STR(suffix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value_param, &prefix_param, &suffix_param);
	if (UNEXPECTED(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(&value, value_param);
	} else {
		ZEPHIR_INIT_VAR(&value);
	}
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
	}
	}
	if (!suffix_param) {
		ZEPHIR_INIT_VAR(&suffix);
		ZVAL_STRING(&suffix, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(suffix_param) != IS_STRING && Z_TYPE_P(suffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'suffix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(suffix_param) == IS_STRING)) {
		zephir_get_strval(&suffix, suffix_param);
	} else {
		ZEPHIR_INIT_VAR(&suffix);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_0, &value))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VVV(&_1$$3, &prefix, &value, &suffix);
		ZEPHIR_CPY_WRT(&value, &_1$$3);
	}
	RETURN_CTOR(&value);
}

/**
 * If no fragment is present, this method MUST return an empty string.
 *
 * The leading "#" character is not part of the fragment and MUST NOT be
 * added.
 *
 * The value returned MUST be percent-encoded, but MUST NOT double-encode
 * any characters. To determine what characters to encode, please refer to
 * RFC 3986, Sections 2 and 3.5.
 *
 * @see https://tools.ietf.org/html/rfc3986#section-2
 * @see https://tools.ietf.org/html/rfc3986#section-3.5
 *
 * @param string $fragment
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterFragment)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment_param = NULL;
	zval fragment;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(fragment)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fragment_param);
	if (UNEXPECTED(Z_TYPE_P(fragment_param) != IS_STRING && Z_TYPE_P(fragment_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fragment' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(fragment_param) == IS_STRING)) {
		zephir_get_strval(&fragment, fragment_param);
	} else {
		ZEPHIR_INIT_VAR(&fragment);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 323, &fragment);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 *
 * The path can either be empty or absolute (starting with a slash) or
 * rootless (not starting with a slash). Implementations MUST support all
 * three syntaxes.
 *
 * Normally, the empty path "" and absolute path "/" are considered equal as
 * defined in RFC 7230 Section 2.7.3. But this method MUST NOT automatically
 * do this normalization because in contexts with a trimmed base path, e.g.
 * the front controller, this difference becomes significant. It's the task
 * of the user to handle both "" and "/".
 *
 * The value returned MUST be percent-encoded, but MUST NOT double-encode
 * any characters. To determine what characters to encode, please refer to
 * RFC 3986, Sections 2 and 3.3.
 *
 * As an example, if the value should include a slash ("/") not intended as
 * delimiter between path segments, that value MUST be passed in encoded
 * form (e.g., "%2F") to the instance.
 *
 * @see https://tools.ietf.org/html/rfc3986#section-2
 * @see https://tools.ietf.org/html/rfc3986#section-3.3
 *
 * @param string $path
 *
 * @return string The URI path.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterPath)
{
	zend_string *_5;
	zend_ulong _4;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, element, key, parts, _0, *_2, _3, _9, _10, _6$$4, _8$$5;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	_1 = ZEPHIR_IS_IDENTICAL(&_0, &path);
	if (!(_1)) {
		_1 = 1 != zephir_start_with_str(&path, SL("/"));
	}
	if (UNEXPECTED(_1)) {
		RETURN_CTOR(&path);
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("/"), &path, LONG_MAX);
	zephir_is_iterable(&parts, 1, "phalcon/Http/Message/Uri.zep", 524);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _2);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "rawurlencode", &_7, 323, &element);
			zephir_check_call_status();
			zephir_array_update_zval(&parts, &key, &_6$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&element, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8$$5, "rawurlencode", &_7, 323, &element);
				zephir_check_call_status();
				zephir_array_update_zval(&parts, &key, &_8$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&path);
	zephir_fast_join_str(&path, SL("/"), &parts);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "/");
	zephir_fast_trim(&_9, &path, &_10, ZEPHIR_TRIM_LEFT);
	ZEPHIR_CONCAT_SV(return_value, "/", &_9);
	RETURN_MM();
}

/**
 * Checks the port. If it is a standard one (80,443) then it returns null
 *
 * @param int|null $port
 *
 * @return int|null
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterPort)
{
	zend_long _0$$3;
	zval ports;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *port = NULL, port_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&ports);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(port)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);
	ZEPHIR_SEPARATE_PARAM(port);


	ZEPHIR_INIT_VAR(&ports);
	zephir_create_array(&ports, 2, 0);
	add_index_long(&ports, 80, 1);
	add_index_long(&ports, 443, 1);
	if (UNEXPECTED(Z_TYPE_P(port) != IS_NULL)) {
		_0$$3 = zephir_get_intval(port);
		ZEPHIR_INIT_NVAR(port);
		ZVAL_LONG(port, _0$$3);
		if (UNEXPECTED(zephir_array_isset(&ports, port))) {
			ZEPHIR_INIT_NVAR(port);
			ZVAL_NULL(port);
		}
	}
	RETVAL_ZVAL(port, 1, 0);
	RETURN_MM();
}

/**
 * If no query string is present, this method MUST return an empty string.
 *
 * The leading "?" character is not part of the query and MUST NOT be
 * added.
 *
 * The value returned MUST be percent-encoded, but MUST NOT double-encode
 * any characters. To determine what characters to encode, please refer to
 * RFC 3986, Sections 2 and 3.4.
 *
 * As an example, if a value in a key/value pair of the query string should
 * include an ampersand ("&") not intended as a delimiter between values,
 * that value MUST be passed in encoded form (e.g., "%26") to the instance.
 *
 * @see https://tools.ietf.org/html/rfc3986#section-2
 * @see https://tools.ietf.org/html/rfc3986#section-3.4
 *
 * @param string $query
 *
 * @return string The URI query string.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterQuery)
{
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, index, part, parts, split, _0, _1, _2, *_3, _4, _8$$4, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4, _9$$5, _10$$5, _17$$6, _20$$6, _21$$6, _22$$6, _23$$6, _24$$6, _18$$7, _19$$7;
	zval query;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(query)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);
	zephir_get_strval(&query, query_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (UNEXPECTED(ZEPHIR_IS_IDENTICAL(&_0, &query))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "?");
	zephir_fast_trim(&_1, &query, &_2, ZEPHIR_TRIM_LEFT);
	zephir_get_strval(&query, &_1);
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("&"), &query, LONG_MAX);
	zephir_is_iterable(&parts, 1, "phalcon/Http/Message/Uri.zep", 597);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&index, _6);
			} else {
				ZVAL_LONG(&index, _5);
			}
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _3);
			ZEPHIR_CALL_METHOD(&split, this_ptr, "splitqueryvalue", &_7, 384, &part);
			zephir_check_call_status();
			zephir_array_fetch_long(&_8$$4, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 589);
			if (UNEXPECTED(Z_TYPE_P(&_8$$4) == IS_NULL)) {
				zephir_array_fetch_long(&_9$$5, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 590);
				ZEPHIR_CALL_FUNCTION(&_10$$5, "rawurlencode", &_11, 323, &_9$$5);
				zephir_check_call_status();
				zephir_array_update_zval(&parts, &index, &_10$$5, PH_COPY | PH_SEPARATE);
				continue;
			}
			zephir_array_fetch_long(&_12$$4, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 594);
			ZEPHIR_CALL_FUNCTION(&_13$$4, "rawurlencode", &_11, 323, &_12$$4);
			zephir_check_call_status();
			zephir_array_fetch_long(&_14$$4, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 594);
			ZEPHIR_CALL_FUNCTION(&_15$$4, "rawurlencode", &_11, 323, &_14$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZEPHIR_CONCAT_VSV(&_16$$4, &_13$$4, "=", &_15$$4);
			zephir_array_update_zval(&parts, &index, &_16$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&split, this_ptr, "splitqueryvalue", &_7, 384, &part);
				zephir_check_call_status();
				zephir_array_fetch_long(&_17$$6, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 589);
				if (UNEXPECTED(Z_TYPE_P(&_17$$6) == IS_NULL)) {
					zephir_array_fetch_long(&_18$$7, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 590);
					ZEPHIR_CALL_FUNCTION(&_19$$7, "rawurlencode", &_11, 323, &_18$$7);
					zephir_check_call_status();
					zephir_array_update_zval(&parts, &index, &_19$$7, PH_COPY | PH_SEPARATE);
					continue;
				}
				zephir_array_fetch_long(&_20$$6, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 594);
				ZEPHIR_CALL_FUNCTION(&_21$$6, "rawurlencode", &_11, 323, &_20$$6);
				zephir_check_call_status();
				zephir_array_fetch_long(&_22$$6, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 594);
				ZEPHIR_CALL_FUNCTION(&_23$$6, "rawurlencode", &_11, 323, &_22$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_24$$6);
				ZEPHIR_CONCAT_VSV(&_24$$6, &_21$$6, "=", &_23$$6);
				zephir_array_update_zval(&parts, &index, &_24$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_INIT_NVAR(&index);
	zephir_fast_join_str(return_value, SL("&"), &parts);
	RETURN_MM();
}

/**
 * Filters the passed scheme - only allowed schemes
 *
 * @param string $scheme
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterScheme)
{
	zval schemes;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *scheme_param = NULL, filtered, _0, _1, _2, _3, _4$$4, _5$$4, _6$$4, _7$$4;
	zval scheme;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&schemes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(scheme)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme_param);
	if (UNEXPECTED(Z_TYPE_P(scheme_param) != IS_STRING && Z_TYPE_P(scheme_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scheme' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(scheme_param) == IS_STRING)) {
		zephir_get_strval(&scheme, scheme_param);
	} else {
		ZEPHIR_INIT_VAR(&scheme);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "mb_strtolower", NULL, 10, &scheme);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "#:(//)?$#");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_FUNCTION(&filtered, "preg_replace", NULL, 50, &_1, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&schemes);
	zephir_create_array(&schemes, 2, 0);
	add_assoc_long_ex(&schemes, SL("http"), 1);
	add_assoc_long_ex(&schemes, SL("https"), 1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	if (UNEXPECTED(ZEPHIR_IS_IDENTICAL(&_3, &filtered))) {
		RETURN_MM_STRING("");
	}
	if (UNEXPECTED(!(zephir_array_isset(&schemes, &filtered)))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_array_keys(&_6$$4, &schemes);
		zephir_fast_join_str(&_5$$4, SL(", "), &_6$$4);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CONCAT_SVSSVS(&_7$$4, "Unsupported scheme [", &filtered, "]. ", "Scheme must be one of [", &_5$$4, "]");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 40, &_7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Http/Message/Uri.zep", 627);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&scheme);
}

/**
 * @param string $element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Message_Uri, splitQueryValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element_param = NULL, __$null, data;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);
	zephir_get_strval(&element, element_param);


	ZEPHIR_INIT_VAR(&data);
	zephir_fast_explode_str(&data, SL("="), &element, 2 );
	if (UNEXPECTED(!(zephir_array_isset_long(&data, 1)))) {
		zephir_array_append(&data, &__$null, PH_SEPARATE, "phalcon/Http/Message/Uri.zep", 644);
	}
	RETURN_CCTOR(&data);
}

