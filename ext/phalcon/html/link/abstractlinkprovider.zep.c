
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
#include "kernel/string.h"
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
 * @phpstan-import-type link_collection from LinkTypes
 * @phpstan-import-type link_list from LinkTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_AbstractLinkProvider)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Link, AbstractLinkProvider, phalcon, html_link_abstractlinkprovider, phalcon_html_link_abstractlinkprovider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @phpstan-var link_collection
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_link_abstractlinkprovider_ce, SL("links"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * LinkProvider constructor.
 *
 * The guard keeps foreign objects out of the collection. It stays live in
 * the Zephir implementation, where the array is untyped.
 *
 * @phpstan-param array<array-key, object> $links
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, __construct)
{
	zend_bool _9, _4$$3, _12$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *links_param = NULL, link, *_0, _8, _1$$3, _2$$3, _5$$3, _6$$4, _10$$5, _11$$5, _13$$5, _14$$6;
	zval links;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&links);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(links, links_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &links_param);
	if (!links_param) {
		ZEPHIR_INIT_VAR(&links);
		array_init(&links);
	} else {
		zephir_get_arrval(&links, links_param);
	}
	zephir_is_iterable(&links, 0, "phalcon/Html/Link/AbstractLinkProvider.zep", 47);
	if (Z_TYPE_P(&links) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&links), _0)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _0);
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Phalcon\\Html\\Link\\Interfaces\\LinkInterface");
			ZEPHIR_CALL_FUNCTION(&_2$$3, "is_a", &_3, 203, &link, &_1$$3);
			zephir_check_call_status();
			_4$$3 = ZEPHIR_IS_TRUE_IDENTICAL(&_2$$3);
			if (!(_4$$3)) {
				ZEPHIR_INIT_NVAR(&_1$$3);
				ZVAL_STRING(&_1$$3, "Psr\\Link\\LinkInterface");
				ZEPHIR_CALL_FUNCTION(&_5$$3, "is_a", &_3, 203, &link, &_1$$3);
				zephir_check_call_status();
				_4$$3 = ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3);
			}
			if (_4$$3) {
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "getkey", &_7, 0, &link);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("links"), &_6$$4, &link);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &links, "rewind", NULL, 0);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &links, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_8, &links, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, &links, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "Phalcon\\Html\\Link\\Interfaces\\LinkInterface");
				ZEPHIR_CALL_FUNCTION(&_11$$5, "is_a", &_3, 203, &link, &_10$$5);
				zephir_check_call_status();
				_12$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_11$$5);
				if (!(_12$$5)) {
					ZEPHIR_INIT_NVAR(&_10$$5);
					ZVAL_STRING(&_10$$5, "Psr\\Link\\LinkInterface");
					ZEPHIR_CALL_FUNCTION(&_13$$5, "is_a", &_3, 203, &link, &_10$$5);
					zephir_check_call_status();
					_12$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_13$$5);
				}
				if (_12$$5) {
					ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "getkey", &_7, 0, &link);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("links"), &_14$$6, &link);
				}
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
 * @phpstan-return link_collection
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doGetLinks)
{

	RETURN_MEMBER_TYPED(getThis(), "links", IS_ARRAY);
}

/**
 * Returns an iterable of LinkInterface objects that have a specific
 * relationship.
 *
 * The iterable may be an array or any PHP \Traversable object. If no links
 * with that relationship are available, an empty array or \Traversable
 * MUST be returned.
 *
 * @phpstan-return link_list
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doGetLinksByRel)
{
	zend_bool _5;
	zval filtered;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval rel_zv, link, rels, _0, *_1, _2, *_3, _4;
	zend_string *rel = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel_zv);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&rels);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&filtered);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("links", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(rel)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&rel_zv);
	ZVAL_STR_COPY(&rel_zv, rel);
	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 225, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Html/Link/AbstractLinkProvider.zep", 85);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _3);
			ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
			zephir_check_call_status();
			if (1 == zephir_fast_in_array(&rel_zv, &rels)) {
				zephir_array_append(&filtered, &link, PH_SEPARATE, "phalcon/Html/Link/AbstractLinkProvider.zep", 81);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
				zephir_check_call_status();
				if (1 == zephir_fast_in_array(&rel_zv, &rels)) {
					zephir_array_append(&filtered, &link, PH_SEPARATE, "phalcon/Html/Link/AbstractLinkProvider.zep", 81);
				}
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
 * @phpstan-param LinkInterface $link
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(link)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
 * @phpstan-param LinkInterface $link
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("links", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(link)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &link);
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getkey", NULL, 0, link);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_unset_property_array(&newInstance, ZEND_STRL("links"), &key);
	zephir_read_property_cached(&_0, &newInstance, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &key, PH_SEPARATE);
	RETURN_CCTOR(&newInstance);
}

/**
 * Returns the object hash key
 *
 * @phpstan-param object $link
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, getKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *link, link_sub;

	ZVAL_UNDEF(&link_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(link)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &link);
	ZEPHIR_RETURN_CALL_FUNCTION("spl_object_hash", NULL, 190, link);
	zephir_check_call_status();
	RETURN_MM();
}

