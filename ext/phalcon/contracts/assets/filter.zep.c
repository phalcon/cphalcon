
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Canonical contract for Phalcon\Assets filters (Cssmin, Jsmin, None, and
 * custom user filters).
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Assets_Filter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Assets, Filter, phalcon, contracts_assets_filter, phalcon_contracts_assets_filter_method_entry);

	return SUCCESS;
}

/**
 * Filters the content returning a string with the filtered content
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Assets_Filter, filter);
