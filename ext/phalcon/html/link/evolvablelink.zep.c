
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
 * Class Phalcon\Http\Link\EvolvableLink
 *
 * @property array  attributes
 * @property string href
 * @property array  rels
 * @property bool   templated
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_EvolvableLink) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Link, EvolvableLink, phalcon, html_link_evolvablelink, phalcon_html_link_link_ce, phalcon_html_link_evolvablelink_method_entry, 0);

	zend_class_implements(phalcon_html_link_evolvablelink_ce, 1, zephir_get_internal_ce(SL("psr\\link\\evolvablelinkinterface")));
	return SUCCESS;

}

/**
 * Returns an instance with the specified attribute added.
 *
 * If the specified attribute is already present, it will be overwritten
 * with the new value.
 *
 * @param string attribute The attribute to include.
 * @param string value     The value of the attribute to set.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attribute, attribute_sub, *value, value_sub, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute, &value);



	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, attribute, value);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);

}

/**
 * Returns an instance with the specified href.
 *
 * @param string href
 *       The href value to include.  It must be one of:
 *       - An absolute URI, as defined by RFC 5988.
 *       - A relative URI, as defined by RFC 5988. The base of the relative
 *       link is assumed to be known based on context by the client.
 *       - A URI template as defined by RFC 6570.
 *       - An object implementing __toString() that produces one of the
 *       above values.
 *
 * An implementing library SHOULD evaluate a passed object to a string
 * immediately rather than waiting for it to be returned later.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withHref) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *href, href_sub, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(href)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &href);



	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&newInstance, ZEND_STRL("href"), href);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hrefistemplated", NULL, 0, href);
	zephir_check_call_status();
	zephir_update_property_zval(&newInstance, ZEND_STRL("templated"), &_0);
	RETURN_CCTOR(&newInstance);

}

/**
 * Returns an instance with the specified relationship included.
 *
 * If the specified rel is already present, this method MUST return
 * normally without errors, but without adding the rel a second time.
 *
 * @param string rel
 *   The relationship value to add.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withRel) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rel, rel_sub, newInstance, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(rel)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rel);



	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("rels"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, rel, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);

}

/**
 * Returns an instance with the specified attribute excluded.
 *
 * If the specified attribute is not present, this method MUST return
 * normally without errors.
 *
 * @param string attribute
 *   The attribute to remove.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withoutAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attribute, attribute_sub, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(attribute)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute);



	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, attribute);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);

}

/**
 * Returns an instance with the specified relationship excluded.
 *
 * If the specified rel is already not present, this method MUST return
 * normally without errors.
 *
 * @param string rel
 *   The relationship value to exclude.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withoutRel) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rel, rel_sub, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(rel)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rel);



	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("rels"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, rel);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);

}

