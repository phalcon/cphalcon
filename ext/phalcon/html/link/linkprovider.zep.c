
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * @property LinkInterface[] links
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_LinkProvider)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Link, LinkProvider, phalcon, html_link_linkprovider, phalcon_html_link_abstractlinkprovider_ce, phalcon_html_link_linkprovider_method_entry, 0);

	zend_class_implements(phalcon_html_link_linkprovider_ce, 1, phalcon_html_link_interfaces_linkproviderinterface_ce);
	return SUCCESS;
}

/**
 * Returns an iterable of LinkInterface objects.
 *
 * The iterable may be an array or any PHP \Traversable object. If no links
 * are available, an empty array or \Traversable MUST be returned.
 */
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getLinks)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dogetlinks", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns an iterable of LinkInterface objects that have a specific
 * relationship.
 *
 * The iterable may be an array or any PHP \Traversable object. If no links
 * with that relationship are available, an empty array or \Traversable
 * MUST be returned.
 */
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getLinksByRel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rel, rel_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(rel)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rel);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dogetlinksbyrel", NULL, 0, rel);
	zephir_check_call_status();
	RETURN_MM();
}

