
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
 * Interface for custom Phalcon\Assets resources
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
