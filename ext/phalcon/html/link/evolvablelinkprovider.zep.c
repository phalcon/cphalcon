
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
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_EvolvableLinkProvider) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Link, EvolvableLinkProvider, phalcon, html_link_evolvablelinkprovider, phalcon_html_link_linkprovider_ce, phalcon_html_link_evolvablelinkprovider_method_entry, 0);

	zend_class_implements(phalcon_html_link_evolvablelinkprovider_ce, 1, zephir_get_internal_ce(SL("psr\\link\\evolvablelinkproviderinterface")));
	return SUCCESS;

}

/**
 * Returns an instance with the specified link included.
 *
 * If the specified link is already present, this method MUST return
 * normally without errors. The link is present if link is === identical
 * to a link object already in the collection.
 *
 * @param LinkInterface link
 *   A link object that should be included in this collection.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Link_EvolvableLinkProvider, withLink) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *link, link_sub, key, newInstance;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newInstance);

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
 * without errors. The link is present if link is === identical to a link
 * object already in the collection.
 *
 * @param LinkInterface link
 *   The link to remove.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Link_EvolvableLinkProvider, withoutLink) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *link, link_sub, key, links, newInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&links);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &link);



	ZEPHIR_CALL_METHOD(&key, this_ptr, "getkey", NULL, 0, link);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, SL("links"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&links, &_0);
	zephir_array_unset(&links, &key, PH_SEPARATE);
	zephir_update_property_zval(&newInstance, SL("links"), &links);
	RETURN_CCTOR(&newInstance);

}

