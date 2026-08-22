
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Traits;

use Phalcon\Contracts\Assets\AssetsTypes;

/**
 * Shared HTML-attributes state for asset objects (`Asset`, `Inline`,
 * `Collection`).
 *
 * @phpstan-import-type assets_attributes from AssetsTypes
 *
 * @todo set attributes to have a default array when introduced in zephir
 * @todo v7 - share setAttributes here too (blocked: Collection is not an AssetInterface, so the return type diverges)
 */
trait AttributesTrait
{
    /**
     * @var assets_attributes|null
     */
    protected attributes = null;

    /**
     * Gets extra HTML attributes.
     *
     * @return assets_attributes
     */
    public function getAttributes() -> array
    {
        return (array) this->attributes;
    }
}
