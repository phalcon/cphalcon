
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

/**
 * Contract for collection membership in Phalcon\Assets. It covers an asset's
 * key, type, HTML attributes, and filter flag - the data the manager uses to
 * group assets into collections.
 *
 * It does NOT cover the file-output pipeline. Building, filtering, and
 * rendering assets (`Phalcon\Assets\Manager::output()`) require the concrete
 * `Phalcon\Assets\Asset` class, which `Manager::addAsset()` already
 * type-hints. Implementing this interface alone is not enough to render an
 * asset.
 */
interface AssetInterface
{
    /**
     * Gets the asset's key.
     */
    public function getAssetKey() -> string;

    /**
     * Gets extra HTML attributes.
     */
    public function getAttributes() -> array | null;

    /**
     * Gets if the asset must be filtered or not.
     */
    public function getFilter() -> bool;

    /**
     * Gets the asset's type.
     */
    public function getType() -> string;

    /**
     * Sets extra HTML attributes.
     */
    public function setAttributes(array attributes) -> <AssetInterface>;

    /**
     * Sets if the asset must be filtered or not.
     */
    public function setFilter(bool filter) -> <AssetInterface>;

    /**
     * Sets the asset's type.
     */
    public function setType(string type) -> <AssetInterface>;
}
