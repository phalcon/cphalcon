
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
#include "kernel/object.h"
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
 * Class Phalcon\Http\Link\LinkProvider
 *
 * @property LinkInterface[] links
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_LinkProvider) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Link, LinkProvider, phalcon, html_link_linkprovider, phalcon_html_link_linkprovider_method_entry, 0);

	/**
	 * @var LinkInterface[]
	 */
	zend_declare_property_null(phalcon_html_link_linkprovider_ce, SL("links"), ZEND_ACC_PROTECTED);

	phalcon_html_link_linkprovider_ce->create_object = zephir_init_properties_Phalcon_Html_Link_LinkProvider;

	zend_class_implements(phalcon_html_link_linkprovider_ce, 1, zephir_get_internal_ce(SL("psr\\link\\linkproviderinterface")));
	return SUCCESS;

}

/**
 * LinkProvider constructor.
 *
 * @param array links
 */
PHP_METHOD(Phalcon_Html_Link_LinkProvider, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *links_param = NULL, link, *_0, _1, _2$$4, _4$$6;
	zval links;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&links);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &links_param);

	if (!links_param) {
		ZEPHIR_INIT_VAR(&links);
		array_init(&links);
	} else {
		zephir_get_arrval(&links, links_param);
	}


	zephir_is_iterable(&links, 0, "phalcon/Html/Link/LinkProvider.zep", 42);
	if (Z_TYPE_P(&links) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&links), _0)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _0);
			if (zephir_is_instance_of(&link, SL("Psr\\Link\\LinkInterface"))) {
				ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getkey", &_3, 0, &link);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("links"), &_2$$4, &link);
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
				if (zephir_is_instance_of(&link, SL("Psr\\Link\\LinkInterface"))) {
					ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "getkey", &_3, 0, &link);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("links"), &_4$$6, &link);
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
 * @return LinkInterface[]|\Traversable
 */
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getLinks) {

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
 * @return LinkInterface[]|Traversable
 */
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getLinksByRel) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rel, rel_sub, link, links, rels, _0, *_1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel_sub);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&links);
	ZVAL_UNDEF(&rels);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rel);



	ZEPHIR_INIT_VAR(&links);
	array_init(&links);
	zephir_read_property(&_0, this_ptr, SL("links"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Html/Link/LinkProvider.zep", 79);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _1);
			ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
			zephir_check_call_status();
			if (1 == zephir_fast_in_array(rel, &rels)) {
				zephir_array_append(&links, &link, PH_SEPARATE, "phalcon/Html/Link/LinkProvider.zep", 75);
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
				if (1 == zephir_fast_in_array(rel, &rels)) {
					zephir_array_append(&links, &link, PH_SEPARATE, "phalcon/Html/Link/LinkProvider.zep", 75);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&link);
	RETURN_CCTOR(&links);

}

/**
 * Returns the object hash key
 *
 * @param LinkInterface link
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *link, link_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &link);



	ZEPHIR_RETURN_CALL_FUNCTION("spl_object_hash", NULL, 95, link);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Html_Link_LinkProvider(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("links"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("links"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

