
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

use Countable;
use Iterator;
use Phalcon\Assets\Asset\Css as AssetCss;
use Phalcon\Assets\Asset\Js as AssetJs;
use Phalcon\Assets\Inline\Js as InlineJs;
use Phalcon\Assets\Inline\Css as InlineCss;

/**
 * Represents a collection of assets
 */
class Collection implements Countable, Iterator
{
    /**
     * @var array
     */
    protected assets = [] { get };

    /**
     * @var array
     */
    protected attributes = [] { get };

	/**
	 * Should version be determined from file modification time
	 * @var bool
	 */
	protected autoVersion = false { set };

    /**
     * @var array
     */
    protected codes = [] { get };

    /**
     * @var array
     */
    protected filters = [] { get };

    /**
     * @var array
     */
    protected includedAssets;

    /**
     * @var bool
     */
    protected join = true { get };

    /**
     * @var bool
     */
    protected local = true { get };

    /**
     * @var string
     */
    protected prefix { get };

    /**
     * @var int
     */
    protected position = 0 { get };

    /**
     * @var string
     */
    protected sourcePath { get };

    /**
     * @var bool
     */
    protected targetLocal = true { get };

    /**
     * @var string
     */
    protected targetPath { get };

    /**
     * @var string
     */
    protected targetUri { get };

	/**
	 * Version of resource
	 * @var string
	 */
	protected version { get, set };

    /**
     * Phalcon\Assets\Collection constructor
     */
    public function __construct()
    {
        let this->includedAssets = [];
    }

    /**
     * Adds a asset to the collection
     */
    public function add(<AssetInterface> asset) -> <Collection>
    {
        this->addAsset(asset);

        return this;
    }

    /**
     * Adds a CSS asset to the collection
     */
    public function addCss(
        string! path,
        var local = null,
        bool filter = true,
        var attributes = null,
        string version = null,
        bool autoVersion = false
	) -> <Collection>
	{
        var collectionLocal, collectionAttributes;

        if typeof local == "boolean" {
            let collectionLocal = local;
        } else {
            let collectionLocal = this->local;
        }

        if typeof attributes == "array" {
            let collectionAttributes = attributes;
        } else {
            let collectionAttributes = this->attributes;
        }

        this->add(
            new AssetCss(path, collectionLocal, filter, collectionAttributes, version, autoVersion)
        );

        return this;
    }

    /**
     * Adds a filter to the collection
     */
    public function addFilter(<FilterInterface> filter) -> <Collection>
    {
        let this->filters[] = filter;

        return this;
    }

    /**
     * Adds an inline code to the collection
     */
    public function addInline(<$Inline> code) -> <Collection>
    {
        this->addAsset(code);

        return this;
    }

    /**
     * Adds an inline CSS to the collection
     */
    public function addInlineCss(string content, bool filter = true, attributes = null) -> <Collection>
    {
        var collectionAttributes;

        if typeof attributes == "array" {
            let collectionAttributes = attributes;
        } else {
            let collectionAttributes = this->attributes;
        }

        let this->codes[] = new InlineCss(
            content,
            filter,
            collectionAttributes
        );

        return this;
    }

    /**
     * Adds an inline JavaScript to the collection
     */
    public function addInlineJs(string content, bool filter = true, attributes = null) -> <Collection>
    {
        var collectionAttributes;

        if typeof attributes == "array" {
            let collectionAttributes = attributes;
        } else {
            let collectionAttributes = this->attributes;
        }

        let this->codes[] = new InlineJs(content, filter, collectionAttributes);

        return this;
    }

    /**
     * Adds a JavaScript asset to the collection
     *
     * @param array attributes
     */
    public function addJs(
        string! path,
        var local = null,
        bool filter = true,
        var attributes = null,
        string version = null,
        bool autoVersion = false
    ) -> <Collection>
    {
        var collectionLocal, collectionAttributes;

        if typeof local == "boolean" {
            let collectionLocal = local;
        } else {
            let collectionLocal = this->local;
        }

        if typeof attributes == "array" {
            let collectionAttributes = attributes;
        } else {
            let collectionAttributes = this->attributes;
        }

        this->add(
            new AssetJs(path, collectionLocal, filter, collectionAttributes, version, autoVersion)
        );

        return this;
    }

    /**
     * Returns the number of elements in the form
     */
    public function count() -> int
    {
        return count(this->assets);
    }

    /**
     * Returns the current asset in the iterator
     */
    public function current() -> <Asset>
    {
        return this->assets[this->position];
    }

    /**
     * Returns the complete location where the joined/filtered collection must
     * be written
     */
    public function getRealTargetPath(string! basePath) -> string
    {
        var targetPath, completePath;

        let targetPath = this->targetPath;

        /**
         * A base path for assets can be set in the assets manager
         */
        let completePath = basePath . targetPath;

        /**
         * Get the real template path, the target path can optionally don't
         * exist
         */
        if file_exists(completePath) {
            return realPath(completePath);
        }

        return completePath;
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
     */
    public function has(<AssetInterface> asset) -> bool
    {
        var key, assets;

        let key = asset->getAssetKey(),
            assets = this->includedAssets;

        return in_array(key, assets);
    }

    /**
     * Checks if collection is using auto version
     */
	public function isAutoVersion() -> bool
	{
	    return this->autoVersion;
	}

    /**
     * Sets if all filtered assets in the collection must be joined in a single
     * result file
     */
    public function join(bool join) -> <Collection>
    {
        let this->join = join;

        return this;
    }

    /**
     * Returns the current position/key in the iterator
     */
    public function key() -> int
    {
        return this->position;
    }

    /**
     * Moves the internal iteration pointer to the next position
     */
    public function next() -> void
    {
        let this->position++;
    }

    /**
     * Rewinds the internal iterator
     */
    public function rewind() -> void
    {
        let this->position = 0;
    }

    /**
     * Sets extra HTML attributes
     */
    public function setAttributes(array! attributes) -> <Collection>
    {
        let this->attributes = attributes;

        return this;
    }

    /**
     * Sets an array of filters in the collection
     */
    public function setFilters(array! filters) -> <Collection>
    {
        let this->filters = filters;

        return this;
    }

    /**
     * Sets if the collection uses local assets by default
     */
    public function setLocal(bool! local) -> <Collection>
    {
        let this->local = local;

        return this;
    }

    /**
     * Sets a common prefix for all the assets
     */
    public function setPrefix(string! prefix) -> <Collection>
    {
        let this->prefix = prefix;

        return this;
    }

    /**
     * Sets the target local
     */
    public function setTargetLocal(bool! targetLocal) -> <Collection>
    {
        let this->targetLocal = targetLocal;

        return this;
    }

    /**
     * Sets the target path of the file for the filtered/join output
     */
    public function setTargetPath(string! targetPath) -> <Collection>
    {
        let this->targetPath = targetPath;

        return this;
    }

    /**
     * Sets a target uri for the generated HTML
     */
    public function setTargetUri(string! targetUri) -> <Collection>
    {
        let this->targetUri = targetUri;

        return this;
    }

    /**
     * Sets a base source path for all the assets in this collection
     */
    public function setSourcePath(string! sourcePath) -> <Collection>
    {
        let this->sourcePath = sourcePath;

        return this;
    }

    /**
     * Check if the current element in the iterator is valid
     */
    public function valid() -> bool
    {
        return isset this->assets[this->position];
    }

    /**
     * Adds a asset or inline-code to the collection
     */
    final protected function addAsset(<AssetInterface> asset) -> bool
    {
        if this->has(asset) {
            return false;
        }

        if asset instanceof Asset {
            let this->assets[] = asset;
        } else {
            let this->codes[] = asset;
        }

        let this->includedAssets[] = asset->getAssetKey();

        return true;
    }
}
