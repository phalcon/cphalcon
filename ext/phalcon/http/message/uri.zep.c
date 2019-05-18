
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
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Uri) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, Uri, phalcon, http_message_uri, phalcon_http_message_uri_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("authority"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the fragment component of the URI.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("fragment"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

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
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("host"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the path component of the URI.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("path"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

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
	 * @var null | int
	 */
	zend_declare_property_null(phalcon_http_message_uri_ce, SL("port"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the query string of the URI.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("query"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

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
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("scheme"), "https", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("pass"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uri_ce, SL("user"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalcon_http_message_uri_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uriinterface")));
	return SUCCESS;

}

/**
 * Retrieve the fragment component of the URI.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getFragment) {

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
PHP_METHOD(Phalcon_Http_Message_Uri, getHost) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "host");

}

/**
 * Retrieve the path component of the URI.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getPath) {

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
PHP_METHOD(Phalcon_Http_Message_Uri, getPort) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "port");

}

/**
 * Retrieve the query string of the URI.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getQuery) {

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
PHP_METHOD(Phalcon_Http_Message_Uri, getScheme) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "scheme");

}

/**
 * Constructor - parses the URI
 */
PHP_METHOD(Phalcon_Http_Message_Uri, __construct) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, fragment, host, scheme, pass, path, port, query, urlParts, user, _0, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&pass);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&urlParts);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "");
	if (!ZEPHIR_IS_IDENTICAL(&_0, &uri)) {
		ZEPHIR_CALL_FUNCTION(&urlParts, "parse_url", NULL, 312, &uri);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "scheme");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_CE_STATIC(&scheme, phalcon_helper_arr_ce, "get", &_1, 5, &urlParts, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "host");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_CE_STATIC(&host, phalcon_helper_arr_ce, "get", &_1, 5, &urlParts, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "port");
		ZVAL_NULL(&_4$$3);
		ZEPHIR_CALL_CE_STATIC(&port, phalcon_helper_arr_ce, "get", &_1, 5, &urlParts, &_2$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "user");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_CE_STATIC(&user, phalcon_helper_arr_ce, "get", &_1, 5, &urlParts, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "pass");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_CE_STATIC(&pass, phalcon_helper_arr_ce, "get", &_1, 5, &urlParts, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "path");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_CE_STATIC(&path, phalcon_helper_arr_ce, "get", &_1, 5, &urlParts, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "query");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_CE_STATIC(&query, phalcon_helper_arr_ce, "get", &_1, 5, &urlParts, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "fragment");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_CE_STATIC(&fragment, phalcon_helper_arr_ce, "get", &_1, 5, &urlParts, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "filterscheme", NULL, 313, &scheme);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("scheme"), &_5$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_fast_strtolower(&_2$$3, &host);
		zephir_update_property_zval(this_ptr, SL("host"), &_2$$3);
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "filterport", NULL, 314, &port);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("port"), &_6$$3);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "rawurlencode", NULL, 198, &user);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("user"), &_7$$3);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "rawurlencode", NULL, 198, &pass);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("pass"), &_8$$3);
		ZEPHIR_CALL_METHOD(&_9$$3, this_ptr, "filterpath", NULL, 315, &path);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("path"), &_9$$3);
		ZEPHIR_CALL_METHOD(&_10$$3, this_ptr, "filterquery", NULL, 316, &query);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("query"), &_10$$3);
		ZEPHIR_CALL_METHOD(&_11$$3, this_ptr, "filterfragment", NULL, 317, &fragment);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("fragment"), &_11$$3);
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
 */
PHP_METHOD(Phalcon_Http_Message_Uri, __toString) {

	zend_bool _11$$5, _13$$5;
	zval authority, fragment, part, path, query, scheme, uri, _0, _1, _2, _4, _6, _18, _20, _3$$3, _5$$4, _7$$5, _8$$5, _9$$5, _10$$5, _12$$5, _14$$5, _15$$6, _16$$6, _17$$7, _19$$8, _21$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&authority);
	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_21$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&authority, this_ptr, "getauthority", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("fragment"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&fragment, &_0);
	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&path, &_0);
	zephir_read_property(&_0, this_ptr, SL("query"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&query, &_0);
	zephir_read_property(&_0, this_ptr, SL("scheme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&scheme, &_0);
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&part);
	zephir_substr(&part, &path, 0 , 1 , 0);
	ZEPHIR_INIT_VAR(&uri);
	ZVAL_STRING(&uri, "");
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "");
	if (!ZEPHIR_IS_IDENTICAL(&_2, &scheme)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VS(&_3$$3, &scheme, ":");
		zephir_concat_self(&uri, &_3$$3 TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "");
	if (!ZEPHIR_IS_IDENTICAL(&_4, &authority)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, "//", &authority);
		zephir_concat_self(&uri, &_5$$4 TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "");
	if (!ZEPHIR_IS_IDENTICAL(&_6, &path)) {
		ZVAL_LONG(&_7$$5, 0);
		ZVAL_LONG(&_8$$5, 2);
		ZEPHIR_INIT_VAR(&_9$$5);
		zephir_substr(&_9$$5, &path, 0 , 2 , 0);
		ZEPHIR_SINIT_VAR(_10$$5);
		ZVAL_STRING(&_10$$5, "//");
		_11$$5 = ZEPHIR_IS_IDENTICAL(&_10$$5, &_9$$5);
		if (_11$$5) {
			ZEPHIR_SINIT_VAR(_12$$5);
			ZVAL_STRING(&_12$$5, "");
			_11$$5 = ZEPHIR_IS_IDENTICAL(&_12$$5, &authority);
		}
		_13$$5 = !(zephir_start_with_str(&path, SL("/")));
		if (_13$$5) {
			ZEPHIR_SINIT_VAR(_14$$5);
			ZVAL_STRING(&_14$$5, "");
			_13$$5 = !ZEPHIR_IS_IDENTICAL(&_14$$5, &authority);
		}
		if (_11$$5) {
			ZEPHIR_INIT_VAR(&_15$$6);
			ZEPHIR_INIT_VAR(&_16$$6);
			ZVAL_STRING(&_16$$6, "/");
			zephir_fast_trim(&_15$$6, &path, &_16$$6, ZEPHIR_TRIM_LEFT TSRMLS_CC);
			ZEPHIR_CPY_WRT(&path, &_15$$6);
		} else if (_13$$5) {
			ZEPHIR_INIT_VAR(&_17$$7);
			ZEPHIR_CONCAT_SV(&_17$$7, "/", &path);
			ZEPHIR_CPY_WRT(&path, &_17$$7);
		}
		zephir_concat_self(&uri, &path TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_STRING(&_18, "");
	if (!ZEPHIR_IS_IDENTICAL(&_18, &query)) {
		ZEPHIR_INIT_VAR(&_19$$8);
		ZEPHIR_CONCAT_SV(&_19$$8, "?", &query);
		zephir_concat_self(&uri, &_19$$8 TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_20);
	ZVAL_STRING(&_20, "");
	if (!ZEPHIR_IS_IDENTICAL(&_20, &fragment)) {
		ZEPHIR_INIT_VAR(&_21$$9);
		ZEPHIR_CONCAT_SV(&_21$$9, "#", &fragment);
		zephir_concat_self(&uri, &_21$$9 TSRMLS_CC);
	}
	RETURN_CCTOR(&uri);

}

/**
 * Retrieve the authority component of the URI.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, getAuthority) {

	zval authority, userInfo, _0, _1, _2, _4, _3$$4, _5$$5, _6$$5;
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

	zephir_read_property(&_0, this_ptr, SL("host"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "");
	if (ZEPHIR_IS_IDENTICAL(&_1, &_0)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_OBS_VAR(&authority);
	zephir_read_property(&authority, this_ptr, SL("host"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&userInfo, this_ptr, "getuserinfo", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "");
	if (!ZEPHIR_IS_IDENTICAL(&_2, &userInfo)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_VSV(&_3$$4, &userInfo, "@", &authority);
		ZEPHIR_CPY_WRT(&authority, &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, SL("port"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_4) != IS_NULL) {
		zephir_read_property(&_5$$5, this_ptr, SL("port"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_CONCAT_SV(&_6$$5, ":", &_5$$5);
		zephir_concat_self(&authority, &_6$$5 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Http_Message_Uri, getUserInfo) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("pass"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, SL("pass"), PH_NOISY_CC | PH_READONLY);
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
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withFragment) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment, fragment_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fragment);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "fragment");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processwith", NULL, 318, fragment, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return an instance with the specified host.
 *
 * This method MUST retain the state of the current instance, and return
 * an instance that contains the specified host.
 *
 * An empty host value is equivalent to removing the host.
 *
 * @throws \InvalidArgumentException for invalid hostnames.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withHost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *host, host_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "host");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processwith", NULL, 318, host, &_0);
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
 * @throws \InvalidArgumentException for invalid paths.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);

	ZEPHIR_SEPARATE_PARAM(path);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "path");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 319, path, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "?");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, path, &_0, 0 );
	if (UNEXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Path cannot contain a query string", "phalcon/Http/Message/Uri.zep", 329);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "#");
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strpos(&_3, path, &_2, 0 );
	if (UNEXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Path cannot contain a query fragment", "phalcon/Http/Message/Uri.zep", 335);
		return;
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "filterpath", NULL, 315, path);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(path, &_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "path");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 320, path, &_5);
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
 * @throws \InvalidArgumentException for invalid ports.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withPort) {

	zend_bool _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *port = NULL, port_sub, type, _5, _0$$7, _1$$7, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);

	ZEPHIR_SEPARATE_PARAM(port);


	if (Z_TYPE_P(port) != IS_NULL) {
		if (Z_TYPE_P(port) != IS_LONG) {
			if (Z_TYPE_P(port) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&type);
				zephir_get_class(&type, port, 0 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&type);
				zephir_gettype(&type, port TSRMLS_CC);
			}
			if (UNEXPECTED(Z_TYPE_P(port) != IS_STRING)) {
				ZEPHIR_INIT_VAR(&_0$$7);
				object_init_ex(&_0$$7, spl_ce_InvalidArgumentException);
				ZEPHIR_INIT_VAR(&_1$$7);
				ZEPHIR_CONCAT_SV(&_1$$7, "Method expects an integer, integer string or null argument instead of ", &type);
				ZEPHIR_CALL_METHOD(NULL, &_0$$7, "__construct", NULL, 272, &_1$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_0$$7, "phalcon/Http/Message/Uri.zep", 372 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "filterport", NULL, 314, port);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(port, &_2$$3);
	}
	_3 = Z_TYPE_P(port) != IS_NULL;
	if (_3) {
		_4 = ZEPHIR_LT_LONG(port, 1);
		if (!(_4)) {
			_4 = ZEPHIR_GT_LONG(port, 65535);
		}
		_3 = _4;
	}
	if (UNEXPECTED(_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Method expects valid port (1-65535)", "phalcon/Http/Message/Uri.zep", 382);
		return;
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "port");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 320, port, &_5);
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
 * @throws \InvalidArgumentException for invalid query strings.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, query_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);

	ZEPHIR_SEPARATE_PARAM(query);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "query");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 319, query, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "#");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, query, &_0, 0 );
	if (UNEXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Query cannot contain a query fragment", "phalcon/Http/Message/Uri.zep", 408);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "filterquery", NULL, 316, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "query");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 320, query, &_3);
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
 * @throws \InvalidArgumentException for invalid schemes.
 * @throws \InvalidArgumentException for unsupported schemes.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withScheme) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *scheme = NULL, scheme_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme);

	ZEPHIR_SEPARATE_PARAM(scheme);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "scheme");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 319, scheme, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "filterscheme", NULL, 313, scheme);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(scheme, &_1);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "scheme");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processwith", NULL, 318, scheme, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return an instance with the specified user information.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, withUserInfo) {

	zend_bool _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user = NULL, user_sub, *password = NULL, password_sub, __$null, newInstance, _0, _2, _4, _6, _1$$3, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&password_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &password);

	ZEPHIR_SEPARATE_PARAM(user);
	if (!password) {
		password = &password_sub;
		ZEPHIR_CPY_WRT(password, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(password);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "user");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 319, user, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(password) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pass");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 319, user, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "rawurlencode", NULL, 198, user);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(user, &_2);
	if (Z_TYPE_P(password) != IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&_3$$4, "rawurlencode", NULL, 198, password);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(password, &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
	_5 = ZEPHIR_IS_IDENTICAL(user, &_4);
	if (_5) {
		zephir_read_property(&_6, this_ptr, SL("pass"), PH_NOISY_CC | PH_READONLY);
		_5 = ZEPHIR_IS_IDENTICAL(password, &_6);
	}
	if (_5) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&newInstance, SL("user"), user);
	zephir_update_property_zval(&newInstance, SL("pass"), password);
	RETURN_CCTOR(&newInstance);

}

/**
 * Checks the element passed if it is a string
 */
PHP_METHOD(Phalcon_Http_Message_Uri, checkStringParameter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property;
	zval *element, element_sub, *property_param = NULL, type, _0$$5, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &property_param);

	zephir_get_strval(&property, property_param);


	if (Z_TYPE_P(element) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&type);
		zephir_get_class(&type, element, 0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&type);
		zephir_gettype(&type, element TSRMLS_CC);
	}
	if (UNEXPECTED(Z_TYPE_P(element) != IS_STRING)) {
		ZEPHIR_INIT_VAR(&_0$$5);
		object_init_ex(&_0$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_1$$5);
		ZEPHIR_CONCAT_SV(&_1$$5, "Method requires a string argument instead of ", &type);
		ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 272, &_1$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$5, "phalcon/Http/Message/Uri.zep", 489 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a new instance having set the parameter
 */
PHP_METHOD(Phalcon_Http_Message_Uri, cloneInstance) {

	zval property;
	zval *element, element_sub, *property_param = NULL, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &property_param);

	zephir_get_strval(&property, property_param);


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &property, PH_NOISY_CC);
	if (!ZEPHIR_IS_IDENTICAL(element, &_0)) {
		zephir_update_property_zval_zval(&newInstance, &property, element TSRMLS_CC);
	}
	RETURN_CCTOR(&newInstance);

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
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterFragment) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment_param = NULL, _0, _2$$3, _3$$3, _4$$3;
	zval fragment;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fragment_param);

	zephir_get_strval(&fragment, fragment_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "");
	_1 = !ZEPHIR_IS_IDENTICAL(&_0, &fragment);
	if (_1) {
		_1 = zephir_start_with_str(&fragment, SL("#"));
	}
	if (_1) {
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_substr(&_3$$3, &fragment, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, "%23", &_3$$3);
		zephir_get_strval(&fragment, &_4$$3);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 198, &fragment);
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
 * @return string The URI path.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterPath) {

	zend_string *_5;
	zend_ulong _4;
	zend_bool _1;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, element, index, parts, _0, *_2, _3, _9, _10, _6$$4, _8$$5;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "");
	_1 = ZEPHIR_IS_IDENTICAL(&_0, &path);
	if (!(_1)) {
		_1 = !(zephir_start_with_str(&path, SL("/")));
	}
	if (_1) {
		RETURN_CTOR(&path);
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("/"), &path, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(&parts, 1, "phalcon/Http/Message/Uri.zep", 570);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&index, _5);
			} else {
				ZVAL_LONG(&index, _4);
			}
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _2);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "rawurlencode", &_7, 198, &element);
			zephir_check_call_status();
			zephir_array_update_zval(&parts, &index, &_6$$4, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(&index, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&element, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8$$5, "rawurlencode", &_7, 198, &element);
				zephir_check_call_status();
				zephir_array_update_zval(&parts, &index, &_8$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&path);
	zephir_fast_join_str(&path, SL("/"), &parts TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "/");
	zephir_fast_trim(&_9, &path, &_10, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_CONCAT_SV(return_value, "/", &_9);
	RETURN_MM();

}

/**
 * Checks the port. If it is a standard one (80,443) then it returns null
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterPort) {

	zend_long _0$$3;
	zval ports;
	zval *port = NULL, port_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&ports);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);

	ZEPHIR_SEPARATE_PARAM(port);


	ZEPHIR_INIT_VAR(&ports);
	zephir_create_array(&ports, 2, 0 TSRMLS_CC);
	add_index_long(&ports, 80, 1);
	add_index_long(&ports, 443, 1);
	if (Z_TYPE_P(port) != IS_NULL) {
		_0$$3 = zephir_get_intval(port);
		ZEPHIR_INIT_NVAR(port);
		ZVAL_LONG(port, _0$$3);
		if (zephir_array_isset(&ports, port)) {
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
 * @return string The URI query string.
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterQuery) {

	zend_string *_6;
	zend_ulong _5;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, __$null, key, parts, split, value, _0, *_3, _4, _1$$4, _2$$4, _7$$5, _11$$5, _12$$5, _13$$5, _14$$5, _15$$5, _8$$7, _9$$7, _16$$8, _19$$8, _20$$8, _21$$8, _22$$8, _23$$8, _17$$10, _18$$10;
	zval query;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	zephir_get_strval(&query, query_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &query)) {
		RETURN_MM_STRING("");
	}
	if (zephir_start_with_str(&query, SL("?"))) {
		ZVAL_LONG(&_1$$4, 1);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_substr(&_2$$4, &query, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(&query, &_2$$4);
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("&"), &query, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(&parts, 1, "phalcon/Http/Message/Uri.zep", 645);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&key, _6);
			} else {
				ZVAL_LONG(&key, _5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_INIT_NVAR(&split);
			zephir_fast_explode_str(&split, SL("="), &value, LONG_MAX TSRMLS_CC);
			if (!(zephir_array_isset_long(&split, 1))) {
				zephir_array_append(&split, &__$null, PH_SEPARATE, "phalcon/Http/Message/Uri.zep", 633);
			}
			zephir_array_fetch_long(&_7$$5, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 636 TSRMLS_CC);
			if (Z_TYPE_P(&_7$$5) == IS_NULL) {
				zephir_array_fetch_long(&_8$$7, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 637 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&_9$$7, "rawurlencode", &_10, 198, &_8$$7);
				zephir_check_call_status();
				zephir_array_update_zval(&parts, &key, &_9$$7, PH_COPY | PH_SEPARATE);
				continue;
			}
			zephir_array_fetch_long(&_11$$5, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 642 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_12$$5, "rawurlencode", &_10, 198, &_11$$5);
			zephir_check_call_status();
			zephir_array_fetch_long(&_13$$5, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 642 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_14$$5, "rawurlencode", &_10, 198, &_13$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_15$$5);
			ZEPHIR_CONCAT_VSV(&_15$$5, &_12$$5, "=", &_14$$5);
			zephir_array_update_zval(&parts, &key, &_15$$5, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(&key, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&split);
				zephir_fast_explode_str(&split, SL("="), &value, LONG_MAX TSRMLS_CC);
				if (!(zephir_array_isset_long(&split, 1))) {
					zephir_array_append(&split, &__$null, PH_SEPARATE, "phalcon/Http/Message/Uri.zep", 633);
				}
				zephir_array_fetch_long(&_16$$8, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 636 TSRMLS_CC);
				if (Z_TYPE_P(&_16$$8) == IS_NULL) {
					zephir_array_fetch_long(&_17$$10, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 637 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&_18$$10, "rawurlencode", &_10, 198, &_17$$10);
					zephir_check_call_status();
					zephir_array_update_zval(&parts, &key, &_18$$10, PH_COPY | PH_SEPARATE);
					continue;
				}
				zephir_array_fetch_long(&_19$$8, &split, 0, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 642 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&_20$$8, "rawurlencode", &_10, 198, &_19$$8);
				zephir_check_call_status();
				zephir_array_fetch_long(&_21$$8, &split, 1, PH_NOISY | PH_READONLY, "phalcon/Http/Message/Uri.zep", 642 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&_22$$8, "rawurlencode", &_10, 198, &_21$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_23$$8);
				ZEPHIR_CONCAT_VSV(&_23$$8, &_20$$8, "=", &_22$$8);
				zephir_array_update_zval(&parts, &key, &_23$$8, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_join_str(return_value, SL("&"), &parts TSRMLS_CC);
	RETURN_MM();

}

/**
 * Filters the passed scheme - only allowed schemes
 */
PHP_METHOD(Phalcon_Http_Message_Uri, filterScheme) {

	zval schemes;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *scheme_param = NULL, filtered, _0, _1, _2, _3, _4$$4, _5$$4, _6$$4;
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
	ZVAL_UNDEF(&schemes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme_param);

	zephir_get_strval(&scheme, scheme_param);


	ZEPHIR_INIT_VAR(&filtered);
	zephir_fast_strtolower(&filtered, &scheme);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "#:(//)?$#");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 25, &_0, &_1, &filtered);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filtered, &_2);
	ZEPHIR_INIT_VAR(&schemes);
	zephir_create_array(&schemes, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(&schemes, SL("http"), 1);
	add_assoc_long_ex(&schemes, SL("https"), 1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "");
	if (ZEPHIR_IS_IDENTICAL(&_3, &filtered)) {
		RETURN_MM_STRING("");
	}
	if (UNEXPECTED(!(zephir_array_isset(&schemes, &filtered)))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_fast_join_str(&_5$$4, SL(", "), &schemes TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_SVSSVS(&_6$$4, "Unsupported scheme [", &filtered, "]. ", "Scheme must be one of [", &_5$$4, "]");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 272, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Http/Message/Uri.zep", 672 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&scheme);

}

/**
 * UTF-8 aware parse_url
 *
 * @link http://php.net/manual/en/function.parse-url.php#114817
 */
PHP_METHOD(Phalcon_Http_Message_Uri, parseUrl) {

	zend_string *_5;
	zend_ulong _4;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, encoded, key, urlParts, value, _0, _1, *_2, _3, _6$$4, _8$$5;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&urlParts);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_22__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "%[^:/@?&=#]+%usD");
	ZEPHIR_CALL_FUNCTION(&encoded, "preg_replace_callback", NULL, 321, &_1, &_0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&urlParts, "parse_url", NULL, 312, &encoded);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&urlParts))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The source URI string appears to be malformed", "phalcon/Http/Message/Uri.zep", 701);
		return;
	}
	zephir_is_iterable(&urlParts, 1, "phalcon/Http/Message/Uri.zep", 708);
	if (Z_TYPE_P(&urlParts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&urlParts), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "urldecode", &_7, 322, &value);
			zephir_check_call_status();
			zephir_array_update_zval(&urlParts, &key, &_6$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &urlParts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &urlParts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &urlParts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &urlParts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8$$5, "urldecode", &_7, 322, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&urlParts, &key, &_8$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &urlParts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&urlParts);

}

/**
 * Checks the element passed; assigns it to the property and returns a
 * clone of the object back
 */
PHP_METHOD(Phalcon_Http_Message_Uri, processWith) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property;
	zval *element, element_sub, *property_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &property_param);

	zephir_get_strval(&property, property_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 319, element, &property);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 320, element, &property);
	zephir_check_call_status();
	RETURN_MM();

}

