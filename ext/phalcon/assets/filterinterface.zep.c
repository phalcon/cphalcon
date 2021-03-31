
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for custom Phalcon\Assets filters
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Assets, FilterInterface, phalcon, assets_filterinterface, phalcon_assets_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Filters the content returning a string with the filtered content
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_FilterInterface, filter);
