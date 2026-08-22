
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

use Phalcon\Assets\Traits\AttributesTrait;
use Phalcon\Contracts\Assets\AssetsTypes;
use Phalcon\Traits\Php\HashTrait;

/**
 * Represents an inline asset
 *
 *```php
 * $inline = new \Phalcon\Assets\Inline("js", "alert('hello world');");
 *```
 *
 * @phpstan-import-type assets_attributes from AssetsTypes
 */
class $Inline implements AssetInterface
{
    use AttributesTrait;
    use HashTrait;

    protected string content;
    protected bool filter;
    protected string type;

    /**
     * Inline constructor.
     *
     * @param assets_attributes $attributes
     */
    public function __construct(string type, string content, bool filter = true, array attributes = [])
    {
        let this->type       = type,
            this->content    = content,
            this->filter     = filter,
            this->attributes = attributes;
    }

    /**
     * Gets the asset's key.
     */
    public function getAssetKey() -> string
    {
        var key;

        let key = this->getType() . ":" . this->getContent();

        return this->phpHash("sha256", key);
    }

    /**
     * Gets if the asset content
     *
     * @return string
     */
    public function getContent() -> string
    {
        return this->content;
    }

    /**
     * Gets if the asset must be filtered or not.
     *
     * @return bool
     */
    public function getFilter() -> bool
    {
        return this->filter;
    }

    /**
     * Gets the asset's type.
     *
     * @return string
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Sets extra HTML attributes
     *
     * @param assets_attributes $attributes
     */
    public function setAttributes(array attributes) -> <AssetInterface>
    {
        let this->attributes = attributes;

        return this;
    }

    /**
     * Sets if the asset must be filtered or not
     */
    public function setFilter(bool filter) -> <AssetInterface>
    {
        let this->filter = filter;

        return this;
    }

    /**
     * Sets the inline's type
     */
    public function setType(string type) -> <AssetInterface>
    {
        let this->type = type;

        return this;
    }
}
