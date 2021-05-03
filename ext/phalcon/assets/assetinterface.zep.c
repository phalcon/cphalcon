
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
 * Interface for custom Phalcon\Assets resources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_AssetInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Assets, AssetInterface, phalcon, assets_assetinterface, phalcon_assets_assetinterface_method_entry);

	return SUCCESS;
}

/**
 * Gets the asset's key.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, getAssetKey);
/**
 * Gets extra HTML attributes.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, getAttributes);
/**
 * Gets if the asset must be filtered or not.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, getFilter);
/**
 * Gets the asset's type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, getType);
/**
 * Sets extra HTML attributes.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, setAttributes);
/**
 * Sets if the asset must be filtered or not.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, setFilter);
/**
 * Sets the asset's type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, setType);
