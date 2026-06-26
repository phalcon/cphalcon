
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
 * Canonical contract for Phalcon\Assets\Asset.
 *
 * Covers collection membership: an asset's key, type, HTML attributes, and
 * filter flag. The file-output pipeline (Phalcon\Assets\Manager::output())
 * requires the concrete Phalcon\Assets\Asset class.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Assets_Asset)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Assets, Asset, phalcon, contracts_assets_asset, phalcon_contracts_assets_asset_method_entry);

	return SUCCESS;
}

/**
 * Gets the asset's key.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Assets_Asset, getAssetKey);
/**
 * Gets extra HTML attributes.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Assets_Asset, getAttributes);
/**
 * Gets if the asset must be filtered or not.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Assets_Asset, getFilter);
/**
 * Gets the asset's type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Assets_Asset, getType);
/**
 * Sets extra HTML attributes.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Assets_Asset, setAttributes);
/**
 * Sets if the asset must be filtered or not.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Assets_Asset, setFilter);
/**
 * Sets the asset's type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Assets_Asset, setType);
