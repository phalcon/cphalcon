
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

use ArrayIterator;
use Countable;
use IteratorAggregate;
use Phalcon\Assets\Traits\AttributesTrait;
use Phalcon\Assets\Traits\SourceTargetTrait;
use Phalcon\Traits\Php\FileTrait;
use Traversable;

/**
 * Collection of asset objects
 *
 * @template TKey of array-key
 * @template TValue of AssetInterface
 * @implements IteratorAggregate<TKey, TValue>
 */
class Collection implements Countable, IteratorAggregate
{
    use AttributesTrait;
    use FileTrait;
    use SourceTargetTrait;

    /**
     * @var array<string, AssetInterface>
     */
    protected array assets = [];

    /**
     * Should version be determined from file modification time
     */
    protected bool autoVersion = false;
    /**
     * @var AssetInterface[]
     */
    protected array codes = [];

    /**
     * @var FilterInterface[]
     */
    protected array filters = [];
    protected bool join = true;
    protected string prefix = "";
    protected bool targetIsLocal = true;
    protected string version = "";

    /**
     * Adds an asset to the collection
     */
    public function add(<AssetInterface> asset) -> <static>
    {
        this->addAsset(asset);

        return this;
    }

    /**
     * Adds a CSS asset to the collection
     *
     * @param array<string, string> $attributes
     */
    public function addCss(
        string path,
        var isLocal = null,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    ) -> <static> {
        return this->processAdd(
            "Css",
            path,
            isLocal,
            filter,
            attributes,
            version,
            autoVersion
        );
    }

    /**
     * Adds a filter to the collection
     *
     * @param FilterInterface $filter
     */
    public function addFilter(<FilterInterface> filter) -> <static>
    {
        let this->filters[] = filter;

        return this;
    }

    /**
     * Adds an inline code to the collection
     *
     * @param Inline $code
     */
    public function addInline(<$Inline> code) -> <static>
    {
        this->addAsset(code);

        return this;
    }

    /**
     * Adds an inline CSS to the collection
     *
     * @param array<string, string> $attributes
     */
    public function addInlineCss(
        string content,
        bool filter = true,
        array attributes = []
    ) -> <static> {
        return this->processAddInline("Css", content, filter, attributes);
    }

    /**
     * Adds an inline JavaScript to the collection
     *
     * @param array<string, string> $attributes
     */
    public function addInlineJs(
        string content,
        bool filter = true,
        array attributes = []
    ) -> <static> {
        return this->processAddInline("Js", content, filter, attributes);
    }

    /**
     * Adds a JavaScript asset to the collection
     *
     * @param array<string, string> $attributes
     */
    public function addJs(
        string path,
        var isLocal = null,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    ) -> <static> {
        return this->processAdd(
            "Js",
            path,
            isLocal,
            filter,
            attributes,
            version,
            autoVersion
        );
    }

    /**
     * Return the count of the assets
     *
     * @return int
     *
     * @link https://php.net/manual/en/countable.count.php
     */
    public function count() -> int
    {
        return count(this->assets);
    }

    /**
     * Return the stored assets
     *
     * @return array<string, AssetInterface>
     */
    public function getAssets() -> array
    {
        return this->assets;
    }

    /**
     * Return the stored codes
     *
     * @return AssetInterface[]
     */
    public function getCodes() -> array
    {
        return this->codes;
    }

    /**
     * Return the stored filters
     *
     * @return FilterInterface[]
     */
    public function getFilters() -> array
    {
        return this->filters;
    }

    /**
     * Returns the iterator of the class
     */
    public function getIterator() -> <Traversable>
    {
        return new ArrayIterator(this->assets);
    }

    /**
     * @return bool
     */
    public function getJoin() -> bool
    {
        return this->join;
    }

    /**
     * Returns the prefix
     *
     * @return string
     */
    public function getPrefix() -> string
    {
        return this->prefix;
    }

    /**
     * Returns the complete location where the joined/filtered collection must
     * be written
     *
     * @param string $basePath
     *
     * @return string
     */
    public function getRealTargetPath( string basePath) -> string
    {
        var completePath;

        /**
         * A base path for assets can be set in the assets manager
         */
        let completePath = basePath . this->targetPath;

        /**
         * Get the real template path, the target path can optionally don't
         * exist
         */
        if (true === this->phpFileExists(completePath)) {
            return realPath(completePath);
        }

        return completePath;
    }

    /**
     * Returns whether the target is local or not
     *
     * @return bool
     */
    public function getTargetIsLocal() -> bool
    {
        return this->targetIsLocal;
    }

    /**
     * Returns the version
     *
     * @return string
     */
    public function getVersion() -> string
    {
        return this->version;
    }

    /**
     * Checks this the asset is added to the collection.
     *
     * ```php
     * use Phalcon\Assets\Asset;
     * use Phalcon\Assets\Collection;
     *
     * $collection = new Collection();
     *
     * $asset = new Asset("js", "js/jquery.js");
     *
     * $collection->add($asset);
     * $collection->has($asset); // true
     * ```
     *
     * @param AssetInterface $asset
     *
     * @return bool
     */
    public function has(<AssetInterface> asset) -> bool
    {
        var key;

        let key = asset->getAssetKey();

        return isset this->assets[key];
    }

    /**
     * Checks if collection is using auto version
     *
     * @return bool
     */
    public function isAutoVersion() -> bool
    {
        return this->autoVersion;
    }

    /**
     * Sets if all filtered assets in the collection must be joined in a single
     * result file
     *
     * @param bool $flag
     *
     * @return static
     */
    public function join(bool flag) -> <static>
    {
        let this->join = flag;

        return this;
    }

    /**
     * Sets extra HTML attributes
     *
     * @param array<string, string> $attributes
     */
    public function setAttributes(array attributes) -> <static>
    {
        let this->attributes = attributes;

        return this;
    }

    /**
     * @param bool $flag
     */
    public function setAutoVersion(bool flag) -> <static>
    {
        let this->autoVersion = flag;

        return this;
    }

    /**
     * Sets an array of filters in the collection
     *
     * @param FilterInterface[] $filters
     */
    public function setFilters(array filters) -> <static>
    {
        let this->filters = filters;

        return this;
    }

    /**
     * Sets a common prefix for all the assets
     *
     * @param string $prefix
     */
    public function setPrefix(string prefix) -> <static>
    {
        let this->prefix = prefix;

        return this;
    }

    /**
     * Sets if the target local or not
     *
     * @param bool $flag
     */
    public function setTargetIsLocal(bool flag) -> <static>
    {
        let this->targetIsLocal = flag;

        return this;
    }

    /**
     * Sets the version
     *
     * @param string $version
     */
    public function setVersion(string version) -> <static>
    {
        let this->version = version;

        return this;
    }

    /**
     * Adds an asset or inline-code to the collection
     *
     * @param AssetInterface $asset
     *
     * @return bool
     */
    final protected function addAsset(<AssetInterface> asset) -> bool
    {
        if (true === this->has(asset)) {
            return false;
        }

        if (asset instanceof Asset) {
            let this->assets[asset->getAssetKey()] = asset;

            return true;
        }

        let this->codes[] = asset;

        return true;
    }

    /**
     * Adds an inline asset
     *
     * @param array<string, string> $attributes
     */
    private function processAdd(
        string className,
        string path,
        var isLocal = null,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    ) -> <static> {
        var attrs, flag, name;

        let name  = "Phalcon\\Assets\\Asset\\" . className,
            flag  = this->isLocal,
            attrs = this->processAttributes(attributes);

        /**
         * Check if the isLocal is null. If not assign it to flag
         */
        if isLocal !== null {
            let flag = (bool) isLocal;
        }

        this->add(new {name}(path, flag, filter, attrs, version, autoVersion));

        return this;
    }

    /**
     * Adds an inline asset
     *
     * @param array<string, string> $attributes
     */
    private function processAddInline(
        string className,
        string content,
        bool filter = true,
        array attributes = []
    ) -> <static> {
        var asset, attrs, name;

        let name  = "Phalcon\\Assets\\Inline\\" . className,
            attrs = this->processAttributes(attributes),
            asset = new {name}(
                content,
                filter,
                attrs
            );

        let this->codes[asset->getAssetKey()] = asset;

        return this;
    }

    /**
     * @param array<string, string> $attributes
     *
     * @return array<string, string>
     */
    private function processAttributes(array attributes) -> array
    {
        return (true !== empty(attributes)) ? attributes : (array) this->attributes;
    }
}
