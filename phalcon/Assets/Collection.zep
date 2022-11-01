
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

/**
 * Collection of asset objects
 */
class Collection implements Countable, IteratorAggregate
{
    /**
     * @var array
     */
    protected assets = [];

    /**
     * @var array
     */
    protected attributes = [];

    /**
     * Should version be determined from file modification time
     *
     * @var bool
     */
    protected autoVersion = false;

    /**
     * @var array
     */
    protected codes = [];

    /**
     * @var array
     */
    protected filters = [];

    /**
     * @var bool
     */
    protected isLocal = true;

    /**
     * @var bool
     */
    protected join = true;

    /**
     * @var string
     */
    protected prefix = "";

    /**
     * @var string
     */
    protected sourcePath = "";

    /**
     * @var bool
     */
    protected targetIsLocal = true;

    /**
     * @var string
     */
    protected targetPath = "";

    /**
     * @var string
     */
    protected targetUri = "";

    /**
     * @var string
     */
    protected version = "";

    /**
     * Adds an asset to the collection
     *
     * @param AssetInterface $asset
     */
    public function add(<AssetInterface> asset) -> <Collection>
    {
        this->addAsset(asset);

        return this;
    }

    /**
     * Adds a CSS asset to the collection
     *
     * @param string      $path
     * @param bool|null   $isLocal
     * @param bool        $filter
     * @param array       $attributes
     * @param string|null $version
     * @param bool        $autoVersion
     */
    public function addCss(
        string path,
        var isLocal = null,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    ) -> <Collection> {
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
    public function addFilter(<FilterInterface> filter) -> <Collection>
    {
        let this->filters[] = filter;

        return this;
    }

    /**
     * Adds an inline code to the collection
     *
     * @param Inline $code
     */
    public function addInline(<$Inline> code) -> <Collection>
    {
        this->addAsset(code);

        return this;
    }

    /**
     * Adds an inline CSS to the collection
     *
     * @param string $content
     * @param bool   $filter
     * @param array  $attributes
     */
    public function addInlineCss(
        string content,
        bool filter = true,
        array attributes = []
    ) -> <Collection> {
        return this->processAddInline("Css", content, filter, attributes);
    }

    /**
     * Adds an inline JavaScript to the collection
     *
     * @param string $content
     * @param bool   $filter
     * @param array  $attributes
     */
    public function addInlineJs(
        string content,
        bool filter = true,
        array attributes = []
    ) -> <Collection> {
        return this->processAddInline("Js", content, filter, attributes);
    }

    /**
     * Adds a JavaScript asset to the collection
     *
     * @param string      $path
     * @param bool|null   $isLocal
     * @param bool        $filter
     * @param array       $attributes
     * @param string|null $version
     * @param bool        $autoVersion
     */
    public function addJs(
        string path,
        var isLocal = null,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    ) -> <Collection> {
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
     * @return array
     */
    public function getAssets() -> array
    {
        return this->assets;
    }

    /**
     * @return array
     */
    public function getAttributes() -> array
    {
        return this->attributes;
    }

    /**
     * @return array
     */
    public function getCodes() -> array
    {
        return this->codes;
    }

    /**
     * @return array
     */
    public function getFilters() -> array
    {
        return this->filters;
    }

    /**
     * Returns the generator of the class
     *
     * @link https://php.net/manual/en/iteratoraggregate.getiterator.php
     */
    public function getIterator() -> <\Traversable>
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
    public function getRealTargetPath(string! basePath) -> string
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
        if (true === file_exists(completePath)) {
            return realPath(completePath);
        }

        return completePath;
    }

    /**
     * @return string
     */
    public function getSourcePath() -> string
    {
        return this->sourcePath;
    }

    /**
     * @return bool
     */
    public function getTargetIsLocal() -> bool
    {
        return this->targetIsLocal;
    }

    /**
     * @return string
     */
    public function getTargetPath() -> string
    {
        return this->targetPath;
    }

    /**
     * @return string
     */
    public function getTargetUri() -> string
    {
        return this->targetUri;
    }

    /**
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
        var key, storedAsset;

        let key = asset->getAssetKey();
        for storedAsset in this->assets {
            if (key === storedAsset->getAssetKey()) {
                return true;
            }
        }

        return false;
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
     * @return bool
     */
    public function isLocal() -> bool
    {
        return this->isLocal;
    }

    /**
     * Sets if all filtered assets in the collection must be joined in a single
     * result file
     *
     * @param bool $flag
     *
     * @return Collection
     */
    public function join(bool flag) -> <Collection>
    {
        let this->join = flag;

        return this;
    }

    /**
     * Sets extra HTML attributes
     *
     * @param array $attributes
     */
    public function setAttributes(array attributes) -> <Collection>
    {
        let this->attributes = attributes;

        return this;
    }

    /**
     * @param bool $flag
     */
    public function setAutoVersion(bool flag) -> <Collection>
    {
        let this->autoVersion = flag;

        return this;
    }

    /**
     * Sets an array of filters in the collection
     *
     * @param array $filters
     */
    public function setFilters(array filters) -> <Collection>
    {
        let this->filters = filters;

        return this;
    }

    /**
     * Sets if the collection uses local assets by default
     *
     * @param bool $flag
     */
    public function setIsLocal(bool flag) -> <Collection>
    {
        let this->isLocal = flag;

        return this;
    }

    /**
     * Sets a common prefix for all the assets
     *
     * @param string $prefix
     */
    public function setPrefix(string prefix) -> <Collection>
    {
        let this->prefix = prefix;

        return this;
    }

    /**
     * Sets if the target local or not
     *
     * @param bool $flag
     */
    public function setTargetIsLocal(bool flag) -> <Collection>
    {
        let this->targetIsLocal = flag;

        return this;
    }

    /**
     * Sets the target path of the file for the filtered/join output
     *
     * @param string $targetPath
     */
    public function setTargetPath(string targetPath) -> <Collection>
    {
        let this->targetPath = targetPath;

        return this;
    }

    /**
     * Sets a target uri for the generated HTML
     *
     * @param string $targetUri
     */
    public function setTargetUri(string targetUri) -> <Collection>
    {
        let this->targetUri = targetUri;

        return this;
    }

    /**
     * Sets a base source path for all the assets in this collection
     *
     * @param string $sourcePath
     */
    public function setSourcePath(string sourcePath) -> <Collection>
    {
        let this->sourcePath = sourcePath;

        return this;
    }

    /**
     * Sets the version
     *
     * @param string $version
     */
    public function setVersion(string version) -> <Collection>
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
     */
    private function processAdd(
        string className,
        string path,
        var isLocal = null,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    ) -> <Collection> {
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
     */
    private function processAddInline(
        string className,
        string content,
        bool filter = true,
        array attributes = []
    ) -> <Collection> {
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
     * @param array $attributes
     *
     * @return array
     */
    private function processAttributes(array attributes) -> array
    {
        return (true !== empty(attributes)) ? attributes : this->attributes;
    }
}
