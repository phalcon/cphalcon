
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
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
 * @property array $links
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_AbstractLinkProvider)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Link, AbstractLinkProvider, phalcon, html_link_abstractlinkprovider, phalcon_html_link_abstractlinkprovider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_link_abstractlinkprovider_ce, SL("links"), ZEND_ACC_PROTECTED);
	phalcon_html_link_abstractlinkprovider_ce->create_object = zephir_init_properties_Phalcon_Html_Link_AbstractLinkProvider;

	return SUCCESS;
}

/**
 * LinkProvider constructor.
 *
 * @param array $links
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, __construct)
{
	zend_bool _5$$3, _11$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *links_param = NULL, link, *_0, _1, _2$$3, _3$$3, _6$$3, _7$$4, _9$$5, _10$$5, _12$$5, _13$$6;
	zval links;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&links);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(links)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &links_param);
	if (!links_param) {
		ZEPHIR_INIT_VAR(&links);
		array_init(&links);
	} else {
		zephir_get_arrval(&links, links_param);
	}


	zephir_is_iterable(&links, 0, "phalcon/Html/Link/AbstractLinkProvider.zep", 42);
	if (Z_TYPE_P(&links) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&links), _0)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _0);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Phalcon\\Html\\Link\\Interfaces\\LinkInterface");
			ZEPHIR_CALL_FUNCTION(&_3$$3, "is_a", &_4, 114, &link, &_2$$3);
			zephir_check_call_status();
			_5$$3 = ZEPHIR_IS_TRUE_IDENTICAL(&_3$$3);
			if (!(_5$$3)) {
				ZEPHIR_INIT_NVAR(&_2$$3);
				ZVAL_STRING(&_2$$3, "Psr\\Link\\LinkInterface");
				ZEPHIR_CALL_FUNCTION(&_6$$3, "is_a", &_4, 114, &link, &_2$$3);
				zephir_check_call_status();
				_5$$3 = ZEPHIR_IS_TRUE_IDENTICAL(&_6$$3);
			}
			if (_5$$3) {
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "getkey", &_8, 0, &link);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("links"), &_7$$4, &link);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &links, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &links, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, &links, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_STRING(&_9$$5, "Phalcon\\Html\\Link\\Interfaces\\LinkInterface");
				ZEPHIR_CALL_FUNCTION(&_10$$5, "is_a", &_4, 114, &link, &_9$$5);
				zephir_check_call_status();
				_11$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_10$$5);
				if (!(_11$$5)) {
					ZEPHIR_INIT_NVAR(&_9$$5);
					ZVAL_STRING(&_9$$5, "Psr\\Link\\LinkInterface");
					ZEPHIR_CALL_FUNCTION(&_12$$5, "is_a", &_4, 114, &link, &_9$$5);
					zephir_check_call_status();
					_11$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_12$$5);
				}
				if (_11$$5) {
					ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "getkey", &_8, 0, &link);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("links"), &_13$$6, &link);
				}
			ZEPHIR_CALL_METHOD(NULL, &links, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&link);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns an iterable of LinkInterface objects.
 *
 * The iterable may be an array or any PHP \Traversable object. If no links
 * are available, an empty array or \Traversable MUST be returned.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doGetLinks)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "links");
}

/**
 * Returns an iterable of LinkInterface objects that have a specific
 * relationship.
 *
 * The iterable may be an array or any PHP \Traversable object. If no links
 * with that relationship are available, an empty array or \Traversable
 * MUST be returned.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doGetLinksByRel)
{
	zval filtered;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rel_param = NULL, link, rels, _0, *_1, _2;
	zval rel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&rels);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&filtered);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(rel)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rel_param);
	zephir_get_strval(&rel, rel_param);


	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("links"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Html/Link/AbstractLinkProvider.zep", 80);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _1);
			ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
			zephir_check_call_status();
			if (1 == zephir_fast_in_array(&rel, &rels)) {
				zephir_array_append(&filtered, &link, PH_SEPARATE, "phalcon/Html/Link/AbstractLinkProvider.zep", 76);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
				zephir_check_call_status();
				if (1 == zephir_fast_in_array(&rel, &rels)) {
					zephir_array_append(&filtered, &link, PH_SEPARATE, "phalcon/Html/Link/AbstractLinkProvider.zep", 76);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&link);
	RETURN_CTOR(&filtered);
}

/**
 * Returns an instance with the specified link included.
 *
 * If the specified link is already present, this method MUST return
 * normally without errors. The link is present if $link is === identical
 * to a link object already in the collection.
 *
 * @param mixed $link A link object that should be included in this
 *                    collection.
 *
 * @return $this
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doWithLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *link, link_sub, key, newInstance;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newInstance);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(link)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &link);


	ZEPHIR_CALL_METHOD(&key, this_ptr, "getkey", NULL, 0, link);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_array(&newInstance, SL("links"), &key, link);
	RETURN_CCTOR(&newInstance);
}

/**
 * Returns an instance with the specified link removed.
 *
 * If the specified link is not present, this method MUST return normally
 * without errors. The link is present if $link is === identical to a link
 * object already in the collection.
 *
 * @param mixed $link The link to remove.
 *
 * @return $this
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doWithoutLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *link, link_sub, key, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(link)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &link);


	ZEPHIR_CALL_METHOD(&key, this_ptr, "getkey", NULL, 0, link);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_unset_property_array(&newInstance, ZEND_STRL("links"), &key);
	zephir_read_property(&_0, &newInstance, ZEND_STRL("links"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &key, PH_SEPARATE);
	RETURN_CCTOR(&newInstance);
}

/**
 * Returns the object hash key
 *
 * @param mixed link
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, getKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *link, link_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(link)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &link);


	ZEPHIR_RETURN_CALL_FUNCTION("spl_object_hash", NULL, 108, link);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Html_Link_AbstractLinkProvider(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("links"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("links"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

