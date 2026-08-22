
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

use Phalcon\Assets\Exceptions\CannotReadAsset;
use Phalcon\Assets\Traits\AttributesTrait;
use Phalcon\Assets\Traits\SourceTargetTrait;
use Phalcon\Contracts\Assets\AssetsTypes;
use Phalcon\Traits\Php\FileTrait;
use Phalcon\Traits\Php\HashTrait;

/**
 * Object representation of an asset
 *
 *```php
 * $asset = new \Phalcon\Assets\Asset("js", "js/jquery.js");
 *```
 *
 * @phpstan-import-type assets_attributes from AssetsTypes
 */
class Asset implements AssetInterface
{
    use AttributesTrait;
    use FileTrait;
    use HashTrait;
    use SourceTargetTrait;

    protected bool isAutoVersion = false;
    protected bool filter;
    protected string path;
    protected string type;
    protected ?string version;

    /**
     * Asset constructor.
     *
     * @param string      $type
     * @param string      $path
     * @param bool        $isLocal
     * @param bool        $filter
     * @param assets_attributes $attributes
     * @param string|null $version
     * @param bool        $isAutoVersion
     */
    public function __construct(
        string type,
        string path,
        bool isLocal = true,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool isAutoVersion = false
    ) {
        let this->type          = type,
            this->path          = path,
            this->isLocal       = isLocal,
            this->filter        = filter,
            this->attributes    = attributes,
            this->version       = version,
            this->isAutoVersion = isAutoVersion;
    }

    /**
     * Gets the asset's key.
     */
    public function getAssetKey() -> string
    {
        var key;

        let key = this->getType() . ":" . this->getPath();

        return this->phpHash("sha256", key);
    }

    /**
     * Returns the content of the asset as an string
     * Optionally a base path where the asset is located can be set
     */
    public function getContent(string basePath = null) -> string
    {
        var completePath, content;

        /**
         * A base path for assets can be set in the assets manager
         */
        let completePath = basePath . this->checkPath("sourcePath");

        /**
         * Local assets are loaded from the local disk
         */
        if (
            true === this->isLocal &&
            true !== this->phpFileExists(completePath)
        ) {
            this->throwException(completePath);
        }

        /**
         * Use file_get_contents to respect the openbase_dir. Access URLs must
         * be enabled
         */
        let content = this->phpFileGetContents(completePath);

        if (false === content) {
            this->throwException(completePath);
        }

        return content;
    }

    /**
     * Gets if the asset must be filtered or not.
     */
    public function getFilter() -> bool
    {
        return this->filter;
    }

    /**
     * Returns the path for this asset
     */
    public function getPath() -> string
    {
        return this->path;
    }

    /**
     * Returns the complete location where the asset is located
     */
    public function getRealSourcePath(string basePath = null) -> string
    {
        var source;

        let source = this->checkPath("sourcePath");
        if (this->isLocal) {
            /**
             * Get the real template path. If `realpath` fails it will return
             * `false`. Casting it to a string will return an empty string
             */
            let source = (string) realpath(basePath . source);
        }

        return source;
    }

    /**
     * Returns the complete location where the asset must be written
     */
    public function getRealTargetPath(string basePath = null) -> string
    {
        var completePath, target;

        let target = this->checkPath("targetPath");
        if (this->isLocal) {
            /**
             * A base path for assets can be set in the assets manager
             */
            let completePath = basePath . target;

            /**
             * Get the real template path, the target path can optionally don't
             * exist
             */
            if (true === this->phpFileExists(completePath)) {
                let completePath = realpath(completePath);

                if (false === completePath) {
                    let completePath = "";
                }
            }

            return completePath;
        }

        return target;
    }

    /**
     * Returns the real target uri for the generated HTML
     */
    public function getRealTargetUri() -> string
    {
        var modTime, target, ver;

        let target = this->checkPath("targetUri"),
            ver    = this->version;
        if (this->isAutoVersion && this->isLocal) {
            let modTime = filemtime(this->getRealSourcePath()),
                ver     = ver ? ver . "." . modTime : modTime;
        }

        if (true !== empty(ver)) {
            let target = target . "?ver=" . ver;
        }

        return target;
    }

    /**
     * Gets the asset's type.
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Gets the asset's version.
     */
    public function getVersion() -> string | null
    {
        return this->version;
    }

    /**
     * Checks if the asset is using auto version
     */
    public function isAutoVersion() -> bool
    {
        return this->isAutoVersion;
    }

    /**
     * Sets extra HTML attributes
     */
    public function setAttributes(array attributes) -> <AssetInterface>
    {
        let this->attributes = attributes;

        return this;
    }

    public function setAutoVersion(bool flag) -> <AssetInterface>
    {
        let this->isAutoVersion = flag;

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
     * Sets the asset's path
     */
    public function setPath(string path) -> <AssetInterface>
    {
        let this->path = path;

        return this;
    }

    /**
     * Sets the asset's type
     */
    public function setType(string type) -> <AssetInterface>
    {
        let this->type = type;

        return this;
    }

    /**
     * Sets the asset's version
     */
    public function setVersion(string version) -> <AssetInterface>
    {
        let this->version = version;

        return this;
    }

    private function checkPath(string property) -> string
    {
        var value;

        if (true === empty(this->{property})) {
            return this->path;
        }

        /** @var string $value */
        let value = this->{property};

        return value;
    }

    private function throwException(string completePath) -> void
    {
        throw new CannotReadAsset(completePath);
    }
}
