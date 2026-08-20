
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
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
 * @phpstan-import-type link_attribute_value from LinkTypes
 * @phpstan-import-type link_attributes from LinkTypes
 * @phpstan-import-type link_rels from LinkTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_AbstractLink)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Link, AbstractLink, phalcon, html_link_abstractlink, phalcon_html_link_abstractlink_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @phpstan-var Collection<link_attribute_value>
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_html_link_abstractlink_ce, SL("attributes"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Support\\Collection"));
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_html_link_abstractlink_ce, SL("href"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @phpstan-var Collection<bool>
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_html_link_abstractlink_ce, SL("rels"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Support\\Collection"));
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_html_link_abstractlink_ce, SL("templated"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Link constructor.
 *
 * @phpstan-param link_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval rel_zv, href_zv, *attributes_param = NULL, _0, _1, _2, _3$$3, _4$$3;
	zend_string *rel = NULL, *href = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel_zv);
	ZVAL_UNDEF(&href_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("rels", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("href", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("templated", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(rel)
		Z_PARAM_STR(href)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!rel) {
		rel = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&rel_zv);
		ZVAL_STR(&rel_zv, rel);
	} else {
		zephir_memory_observe(&rel_zv);
	ZVAL_STR_COPY(&rel_zv, rel);
	}
	if (!href) {
		href = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&href_zv);
		ZVAL_STR(&href_zv, href);
	} else {
		zephir_memory_observe(&href_zv);
	ZVAL_STR_COPY(&href_zv, href);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 41, &attributes);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 220, &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 41);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 221, &_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 222, &href_zv);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "hrefistemplated", NULL, 0, &href_zv);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 223, &_2);
	if (1 != ZEPHIR_IS_EMPTY(&rel_zv)) {
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_1, 221, PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "set", NULL, 0, &rel_zv, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a list of attributes that describe the target URI.
 *
 * A key-value list of attributes, where the key is a string and the value
 * is either a PHP primitive or an array of PHP strings. If no values are
 * found an empty array MUST be returned.
 *
 * @phpstan-return link_attributes
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetAttributes)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 220, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the target of the link.
 *
 * The target link must be one of:
 * - An absolute URI, as defined by RFC 5988.
 * - A relative URI, as defined by RFC 5988. The base of the relative link
 *     is assumed to be known based on context by the client.
 * - A URI template as defined by RFC 6570.
 *
 * If a URI template is returned, isTemplated() MUST return True.
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetHref)
{

	RETURN_MEMBER_TYPED(getThis(), "href", IS_STRING);
}

/**
 * Returns the relationship type(s) of the link.
 *
 * This method returns 0 or more relationship types for a link, expressed
 * as an array of strings.
 *
 * @phpstan-return link_rels
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetRels)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rels", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 221, PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "keys", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns whether this is a templated link. True if this link object is
 * templated, False otherwise.
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doIsTemplated)
{

	RETURN_MEMBER(getThis(), "templated");
}

/**
 * @phpstan-param link_attribute_value $value
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub, newInstance, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property_cached(&_0, &newInstance, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &key_zv, value);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithHref)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval href_zv, newInstance, _0;
	zend_string *href = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href_zv);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("href", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("templated", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(href)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&href_zv);
	ZVAL_STR_COPY(&href_zv, href);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_cached(&newInstance, _zephir_prop_0, 0, &href_zv);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hrefistemplated", NULL, 0, &href_zv);
	zephir_check_call_status();
	zephir_update_property_zval_cached(&newInstance, _zephir_prop_1, 0, &_0);
	RETURN_CCTOR(&newInstance);
}

PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithoutAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, newInstance, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property_cached(&_0, &newInstance, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, &key_zv);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithoutRel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, newInstance, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rels", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property_cached(&_0, &newInstance, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, &key_zv);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithRel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, newInstance, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rels", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property_cached(&_0, &newInstance, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &key_zv, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

/**
 * Determines if a href is a templated link or not.
 *
 * @see https://tools.ietf.org/html/rfc6570
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, hrefIsTemplated)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval href_zv, _0, _1, _3;
	zend_string *href = NULL;

	ZVAL_UNDEF(&href_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(href)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&href_zv);
	ZVAL_STR_COPY(&href_zv, href);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "{");
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strpos", NULL, 198, &href_zv, &_0);
	zephir_check_call_status();
	_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (_2) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "}");
		ZEPHIR_CALL_FUNCTION(&_3, "mb_strpos", NULL, 198, &href_zv, &_0);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_3);
	}
	RETURN_MM_BOOL(_2);
}

