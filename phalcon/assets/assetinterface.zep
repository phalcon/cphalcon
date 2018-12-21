
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

/**
 * Phalcon\Assets\AssetInterface
 *
 * Interface for custom Phalcon\Assets reources
 */
interface AssetInterface
{
	/**
	 * Sets the asset's type.
	 */
	public function setType(string type) -> <AssetInterface>;

	/**
	 * Gets the asset's type.
	 */
	public function getType() -> string;

	/**
	 * Sets if the asset must be filtered or not.
	 */
	public function setFilter(bool filter) -> <AssetInterface>;

	/**
	 * Gets if the asset must be filtered or not.
	 */
	public function getFilter() -> bool;

	/**
	 * Sets extra HTML attributes.
	 */
	public function setAttributes(array attributes) -> <AssetInterface>;

	/**
	 * Gets extra HTML attributes.
	 */
	public function getAttributes() -> array | null;

	/**
	 * Gets the asset's key.
	 */
	public function getAssetKey() -> string;
}
