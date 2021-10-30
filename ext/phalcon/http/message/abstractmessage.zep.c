
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * Message methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_AbstractMessage)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message, AbstractMessage, phalcon, http_message_abstractmessage, phalcon_http_message_abstractcommon_ce, phalcon_http_message_abstractmessage_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Gets the body of the message.
	 *
	 * @var StreamInterface
	 */
	zend_declare_property_null(phalcon_http_message_abstractmessage_ce, SL("body"), ZEND_ACC_PROTECTED);
	/**
	 * @var Collection|CollectionInterface
	 */
	zend_declare_property_null(phalcon_http_message_abstractmessage_ce, SL("headers"), ZEND_ACC_PROTECTED);
	/**
	 * Retrieves the HTTP protocol version as a string.
	 *
	 * The string MUST contain only the HTTP version number (e.g., '1.1',
	 * '1.0').
	 *
	 * @return string HTTP protocol version.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_abstractmessage_ce, SL("protocolVersion"), "1.1", ZEND_ACC_PROTECTED);
	/**
	 * Retrieves the URI instance.
	 *
	 * This method MUST return a UriInterface instance.
	 *
	 * @see http://tools.ietf.org/html/rfc3986#section-4.3
	 *
	 * @var UriInterface
	 */
	zend_declare_property_null(phalcon_http_message_abstractmessage_ce, SL("uri"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Gets the body of the message.
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getBody)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "body");
}

/**
 * Retrieves the HTTP protocol version as a string.
 *
 *
 * The string MUST contain only the HTTP version number (e.g., '1.1',
 * '1.0').
 *
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getProtocolVersion)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "protocolVersion");
}

/**
 * Retrieves the URI instance.
 *
 *
 * This method MUST return a UriInterface instance.
 *
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getUri)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "uri");
}

/**
 * Retrieves a message header value by the given case-insensitive name.
 *
 * This method returns an array of all the header values of the given
 * case-insensitive header name.
 *
 * If the header does not appear in the message, this method MUST return an
 * empty array.
 *
 * @param string $name
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getHeader)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);
	ZEPHIR_SEPARATE_PARAM(name);


	zephir_cast_to_string(&_0, name);
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "get", NULL, 0, name, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Retrieves a comma-separated string of the values for a single header.
 *
 * This method returns all of the header values of the given
 * case-insensitive header name as a string concatenated together using
 * a comma.
 *
 * NOTE: Not all header values may be appropriately represented using
 * comma concatenation. For such headers, use getHeader() instead
 * and supply your own delimiter when concatenating.
 *
 * If the header does not appear in the message, this method MUST return
 * an empty string.
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getHeaderLine)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, header, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_CALL_METHOD(&header, this_ptr, "getheader", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ",");
	zephir_fast_join(return_value, &_0, &header);
	RETURN_MM();
}

/**
 * Retrieves all message header values.
 *
 * The keys represent the header name as it will be sent over the wire, and
 * each value is an array of strings associated with the header.
 *
 *     // Represent the headers as a string
 *     foreach ($message->getHeaders() as $name => $values) {
 *         echo $name . ': ' . implode(', ', $values);
 *     }
 *
 *     // Emit headers iteratively:
 *     foreach ($message->getHeaders() as $name => $values) {
 *         foreach ($values as $value) {
 *             header(sprintf('%s: %s', $name, $value), false);
 *         }
 *     }
 *
 * While header names are not case-sensitive, getHeaders() will preserve the
 * exact case in which headers were originally specified.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getHeaders)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks if a header exists by the given case-insensitive name.
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, hasHeader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specified header appended with the given
 * value.
 *
 * Existing values for the specified header will be maintained. The new
 * value(s) will be appended to the existing list. If the header did not
 * exist previously, it will be added.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new header and/or value.
 *
 * @param string          $name
 * @param string|string[] $value
 *
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withAddedHeader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value = NULL, value_sub, existing, headers, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);
	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", NULL, 35, name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&existing, &headers, "get", NULL, 0, name, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getheadervalue", NULL, 36, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_array_merge(&_4, &existing, value);
	ZEPHIR_CPY_WRT(value, &_4);
	ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, &headers, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specified message body.
 *
 * The body MUST be a StreamInterface object.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return a new instance that has the
 * new body stream.
 *
 * @param StreamInterface $body
 *
 * @return static
 * @throws InvalidArgumentException When the body is not valid.
 *
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withBody)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *body, body_sub, newBody, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&newBody);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(body, zephir_get_internal_ce(SL("psr\\http\\message\\streaminterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "w+b");
	ZEPHIR_CALL_METHOD(&newBody, this_ptr, "processbody", NULL, 37, body, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "body");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, &newBody, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the provided value replacing the specified
 * header.
 *
 * While header names are case-insensitive, the casing of the header will
 * be preserved by this function, and returned from getHeaders().
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new and/or updated header and value.
 *
 * @param string          $name
 * @param string|string[] $value
 *
 * @return static
 * @throws InvalidArgumentException for invalid header names or values.
 *
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withHeader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value = NULL, value_sub, headers, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);
	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", NULL, 35, name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getheadervalue", NULL, 36, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_2);
	ZEPHIR_CALL_METHOD(NULL, &headers, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, &headers, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance with the specified HTTP protocol version.
 *
 * The version string MUST contain only the HTTP version number (e.g.,
 * '1.1', '1.0').
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that has the
 * new protocol version.
 *
 * @param string $version
 *
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withProtocolVersion)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version, version_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(version)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processprotocol", NULL, 38, version);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "protocolVersion");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, version, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an instance without the specified header.
 *
 * Header resolution MUST be done without case-sensitivity.
 *
 * This method MUST be implemented in such a way as to retain the
 * immutability of the message, and MUST return an instance that removes
 * the named header.
 *
 * @param string $name
 *
 * @return static
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, withoutHeader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, headers, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&headers, &_1);
	ZEPHIR_CALL_METHOD(NULL, &headers, "remove", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 22, &headers, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Ensure Host is the first header.
 *
 * @see: http://tools.ietf.org/html/rfc7230#section-5.4
 *
 * @param CollectionInterface $collection
 *
 * @return CollectionInterface
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, checkHeaderHost)
{
	zend_bool _2, _4;
	zval header, _11$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, data, host, hostArray, _0, _1, _3, _5, _6, _7, _8$$3, _10$$3, _12$$3, _9$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&hostArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_11$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_support_collection_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "host");
	ZEPHIR_CALL_METHOD(&_0, collection, "has", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		ZEPHIR_OBS_VAR(&_3);
		zephir_read_property(&_3, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC);
		_2 = !(ZEPHIR_IS_EMPTY(&_3));
	}
	_4 = _2;
	if (_4) {
		zephir_read_property(&_5, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6, &_5, "gethost", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_STRING(&_7, "");
		_4 = !ZEPHIR_IS_IDENTICAL(&_7, &_6);
	}
	if (UNEXPECTED(_4)) {
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&host, this_ptr, "geturihost", NULL, 39, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&hostArray, &host);
		if (UNEXPECTED(Z_TYPE_P(&host) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_9$$4);
			zephir_create_array(&_9$$4, 1, 0);
			zephir_array_fast_append(&_9$$4, &host);
			ZEPHIR_CPY_WRT(&hostArray, &_9$$4);
		}
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "host");
		ZEPHIR_CALL_METHOD(NULL, collection, "remove", NULL, 0, &_10$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&data, collection, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&header);
		array_init(&header);
		zephir_array_update_string(&header, SL("Host"), &hostArray, PH_COPY | PH_SEPARATE);
		zephir_get_arrval(&_11$$3, &data);
		ZEPHIR_INIT_VAR(&_12$$3);
		zephir_add_function(&_12$$3, &header, &_11$$3);
		ZEPHIR_CPY_WRT(&header, &_12$$3);
		ZEPHIR_CALL_METHOD(NULL, collection, "clear", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, collection, "init", NULL, 0, &header);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(collection, 1, 0);
	RETURN_MM();
}

/**
 * Check the name of the header. Throw exception if not valid
 *
 * @see http://tools.ietf.org/html/rfc7230#section-3.2
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, checkHeaderName)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _1, _2, _3, _4, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	_0 = Z_TYPE_P(name) != IS_STRING;
	if (!(_0)) {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "/^[a-zA-Z0-9'`#$%&*+.^_|~!-]+$/");
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "/^[a-zA-Z0-9'`#$%&*+.^_|~!-]+$/");
		zephir_preg_match(&_3, &_4, name, &_1, 0, 0 , 0 );
		_0 = !zephir_is_true(&_3);
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "Invalid header name ", name);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 40, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Http/Message/AbstractMessage.zep", 333);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Validates a header value
 *
 * Most HTTP header field values are defined using common syntax
 * components (token, quoted-string, and comment) separated by
 * whitespace or specific delimiting characters.  Delimiters are chosen
 * from the set of US-ASCII visual characters not allowed in a token
 * (DQUOTE and '(),/:;<=>?@[\]{}').
 *
 *     token          = 1*tchar
 *
 *     tchar          = '!' / '#' / '$' / '%' / '&' / ''' / '*'
 *                    / '+' / '-' / '.' / '^' / '_' / '`' / '|' / '~'
 *                    / DIGIT / ALPHA
 *                    ; any VCHAR, except delimiters
 *
 * A string of text is parsed as a single value if it is quoted using
 * double-quote marks.
 *
 *     quoted-string  = DQUOTE *( qdtext / quoted-pair ) DQUOTE
 *     qdtext         = HTAB / SP /%x21 / %x23-5B / %x5D-7E / obs-text
 *     obs-text       = %x80-FF
 *
 * Comments can be included in some HTTP header fields by surrounding
 * the comment text with parentheses.  Comments are only allowed in
 * fields containing 'comment' as part of their field value definition.
 *
 *     comment        = '(' *( ctext / quoted-pair / comment ) ')'
 *     ctext          = HTAB / SP / %x21-27 / %x2A-5B / %x5D-7E / obs-text
 *
 * The backslash octet ('\') can be used as a single-octet quoting
 * mechanism within quoted-string and comment constructs.  Recipients
 * that process the value of a quoted-string MUST handle a quoted-pair
 * as if it were replaced by the octet following the backslash.
 *
 *     quoted-pair    = '\' ( HTAB / SP / VCHAR / obs-text )
 *
 * A sender SHOULD NOT generate a quoted-pair in a quoted-string except
 * where necessary to quote DQUOTE and backslash octets occurring within
 * that string.  A sender SHOULD NOT generate a quoted-pair in a comment
 * except where necessary to quote parentheses ['(' and ')'] and
 * backslash octets occurring within that comment.
 *
 * @see https://tools.ietf.org/html/rfc7230#section-3.2.6
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, checkHeaderValue)
{
	zval _1;
	zend_bool _0, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value = NULL, value_sub, _2, _3, _4, _5, _7, _8, _9, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);
	ZEPHIR_SEPARATE_PARAM(value);


	_0 = Z_TYPE_P(value) != IS_STRING;
	if (_0) {
		_0 = 1 != zephir_is_numeric(value);
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid header value", "phalcon/Http/Message/AbstractMessage.zep", 385);
		return;
	}
	zephir_cast_to_string(&_1, value);
	ZEPHIR_CPY_WRT(value, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "#(?:(?:(?<!\r)\n)|(?:\r(?!\n))|(?:\r\n(?![ \t])))#");
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "#(?:(?:(?<!\r)\n)|(?:\r(?!\n))|(?:\r\n(?![ \t])))#");
	zephir_preg_match(&_4, &_5, value, &_2, 0, 0 , 0 );
	_6 = zephir_is_true(&_4);
	if (!(_6)) {
		ZEPHIR_INIT_VAR(&_7);
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_STRING(&_8, "/[^\x09\x0a\x0d\x20-\x7E\x80-\xFE]/");
		ZEPHIR_INIT_VAR(&_9);
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_STRING(&_10, "/[^\x09\x0a\x0d\x20-\x7E\x80-\xFE]/");
		zephir_preg_match(&_9, &_10, value, &_7, 0, 0 , 0 );
		_6 = zephir_is_true(&_9);
	}
	if (UNEXPECTED(_6)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid header value", "phalcon/Http/Message/AbstractMessage.zep", 392);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the header values checked for validity
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getHeaderValue)
{
	zval _2$$4, _6$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values, values_sub, value, valueArray, valueData, *_3, _4, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valueArray);
	ZVAL_UNDEF(&valueData);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values);


	ZEPHIR_CPY_WRT(&valueArray, values);
	if (UNEXPECTED(Z_TYPE_P(values) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, values);
		ZEPHIR_CPY_WRT(&valueArray, &_0$$3);
	}
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&valueArray))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SS(&_2$$4, "Invalid header value: must be a string or ", "array of strings; cannot be an empty array");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 40, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Http/Message/AbstractMessage.zep", 412);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&valueData);
	array_init(&valueData);
	zephir_is_iterable(&valueArray, 0, "phalcon/Http/Message/AbstractMessage.zep", 422);
	if (Z_TYPE_P(&valueArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&valueArray), _3)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadervalue", &_5, 41, &value);
			zephir_check_call_status();
			zephir_cast_to_string(&_6$$5, &value);
			zephir_array_append(&valueData, &_6$$5, PH_SEPARATE, "phalcon/Http/Message/AbstractMessage.zep", 419);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &valueArray, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &valueArray, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &valueArray, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadervalue", &_5, 41, &value);
				zephir_check_call_status();
				zephir_cast_to_string(&_7$$6, &value);
				zephir_array_append(&valueData, &_7$$6, PH_SEPARATE, "phalcon/Http/Message/AbstractMessage.zep", 419);
			ZEPHIR_CALL_METHOD(NULL, &valueArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETURN_CCTOR(&valueData);
}

/**
 * Return the host and if applicable the port
 *
 * @param UriInterface $uri
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, getUriHost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub, host, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(uri, zephir_get_internal_ce(SL("psr\\http\\message\\uriinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);


	ZEPHIR_CALL_METHOD(&host, uri, "gethost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, uri, "getport", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&_0) != IS_NULL)) {
		ZEPHIR_CALL_METHOD(&_1$$3, uri, "getport", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, ":", &_1$$3);
		zephir_concat_self(&host, &_2$$3);
	}
	RETURN_CCTOR(&host);
}

/**
 * Populates the header collection
 *
 * @param array $headers
 *
 * @return CollectionInterface
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, populateHeaderCollection)
{
	zval _5$$3, _9$$4;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, collection, name, value, *_0, _1, _6$$3, _10$$4;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(headers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);
	zephir_get_arrval(&headers, headers_param);


	ZEPHIR_INIT_VAR(&collection);
	object_init_ex(&collection, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 25);
	zephir_check_call_status();
	zephir_is_iterable(&headers, 0, "phalcon/Http/Message/AbstractMessage.zep", 466);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", &_4, 35, &name);
			zephir_check_call_status();
			zephir_cast_to_string(&_5$$3, &name);
			ZEPHIR_CPY_WRT(&name, &_5$$3);
			ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "getheadervalue", &_7, 36, &value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_6$$3);
			ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_8, 42, &name, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkheadername", &_4, 35, &name);
				zephir_check_call_status();
				zephir_cast_to_string(&_9$$4, &name);
				ZEPHIR_CPY_WRT(&name, &_9$$4);
				ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "getheadervalue", &_7, 36, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_10$$4);
				ZEPHIR_CALL_METHOD(NULL, &collection, "set", &_8, 42, &name, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&collection);
}

/**
 * Set a valid stream
 *
 * @param StreamInterface|resource|string $body
 * @param string                          $mode
 *
 * @return StreamInterface
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, processBody)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *body = NULL, body_sub, *mode_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&mode);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(body)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &body, &mode_param);
	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://memory");
	}
	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "r+b");
	} else {
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
	}
	}


	_0 = Z_TYPE_P(body) == IS_OBJECT;
	if (_0) {
		_0 = zephir_is_instance_of(body, SL("Psr\\Http\\Message\\StreamInterface"));
	}
	if (UNEXPECTED(_0)) {
		RETVAL_ZVAL(body, 1, 0);
		RETURN_MM();
	}
	_1 = Z_TYPE_P(body) != IS_STRING;
	if (_1) {
		_1 = Z_TYPE_P(body) != IS_RESOURCE;
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid stream passed as a parameter", "phalcon/Http/Message/AbstractMessage.zep", 486);
		return;
	}
	object_init_ex(return_value, phalcon_http_message_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 43, body, &mode);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the headers
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, processHeaders)
{
	zend_bool _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers, headers_sub, collection, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(headers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers);


	if (EXPECTED(Z_TYPE_P(headers) == IS_ARRAY)) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "populateheadercollection", NULL, 44, headers);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "checkheaderhost", NULL, 45, &collection);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&collection, &_0$$3);
	} else {
		_1$$4 = Z_TYPE_P(headers) == IS_OBJECT;
		if (_1$$4) {
			_1$$4 = zephir_instance_of_ev(headers, phalcon_support_collection_collectioninterface_ce);
		}
		if (UNEXPECTED(!(_1$$4))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Headers needs to be either an array or instance of Phalcon\\Support\\Collection", "phalcon/Http/Message/AbstractMessage.zep", 506);
			return;
		}
		ZEPHIR_CPY_WRT(&collection, headers);
	}
	RETURN_CCTOR(&collection);
}

/**
 * Checks the protocol
 *
 * @param string $protocol
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_AbstractMessage, processProtocol)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *protocol = NULL, protocol_sub, protocols, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&protocol_sub);
	ZVAL_UNDEF(&protocols);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(protocol)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &protocol);
	if (!protocol) {
		protocol = &protocol_sub;
		ZEPHIR_INIT_VAR(protocol);
		ZVAL_STRING(protocol, "");
	}


	ZEPHIR_INIT_VAR(&protocols);
	zephir_create_array(&protocols, 4, 0);
	add_assoc_long_ex(&protocols, SL("1.0"), 1);
	add_assoc_long_ex(&protocols, SL("1.1"), 1);
	add_assoc_long_ex(&protocols, SL("2.0"), 1);
	add_assoc_long_ex(&protocols, SL("3.0"), 1);
	_0 = ZEPHIR_IS_EMPTY(protocol);
	if (!(_0)) {
		_0 = Z_TYPE_P(protocol) != IS_STRING;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid protocol value", "phalcon/Http/Message/AbstractMessage.zep", 534);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset(&protocols, protocol)))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "Unsupported protocol ", protocol);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 40, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Http/Message/AbstractMessage.zep", 540);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(protocol, 1, 0);
	RETURN_MM();
}

