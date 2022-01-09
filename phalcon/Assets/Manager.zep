
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

use Phalcon\Assets\Asset\Css as AssetCss;
use Phalcon\Assets\Asset\Js as AssetJs;
use Phalcon\Assets\Inline\Css as InlineCss;
use Phalcon\Assets\Inline\Js as InlineJs;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Html\Helper\Element;
use Phalcon\Html\Helper\Link;
use Phalcon\Html\Helper\Script;
use Phalcon\Html\TagFactory;

/**
 * Manages collections of CSS/JavaScript assets
 *
 * @property array      $collections
 * @property bool       $implicitOutput
 * @property array      $options
 * @property TagFactory $tagFactory
 */
class Manager extends AbstractInjectionAware
{
    /**
     * @var array
     */
    protected collections = [];

    /**
     * @var bool
     */
    protected implicitOutput = true;

    /**
     * @var array
     */
    protected options = [];

    /**
     * @var TagFactory
     */
    protected tagFactory;

    /**
     * Manager constructor.
     *
     * @param TagFactory $tagFactory
     * @param array      $options
     */
    public function __construct(<TagFactory> tagFactory, array options = [])
    {
        let this->tagFactory = tagFactory,
            this->options    = options;
    }

    /**
     * Adds a raw asset to the manager
     *
     * @param Asset $asset
     */
    public function addAsset(<Asset> asset) -> <Manager>
    {
        /**
         * Adds the asset by its type
         */
        this->addAssetByType(asset->getType(), asset);

        return this;
    }

    /**
     * Adds a asset by its type
     *
     * @param string $type
     * @param Asset  $asset
     */
    public function addAssetByType(string! type, <Asset> asset) -> <Manager>
    {
        var collection;

        let collection = this->checkAndCreateCollection(type);

        collection->add(asset);

        return this;
    }

    /**
     * Adds a CSS asset to the 'css' collection
     *
     * @param string      $path
     * @param bool        $local
     * @param bool        $filter
     * @param array       $attributes
     * @param string|null $version
     * @param bool        $autoVersion
     */
    public function addCss(
        string! path,
        bool local = true,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    ) -> <Manager>
    {
        this->addAssetByType(
            "css",
            new AssetCss(path, local, filter, attributes, version, autoVersion)
        );

        return this;
    }

    /**
     * Adds a raw inline code to the manager
     *
     * @param Inline $code
     */
    public function addInlineCode(<$Inline> code) -> <Manager>
    {
        /**
         * Adds the inline code by its type
         */
        this->addInlineCodeByType(code->getType(), code);

        return this;
    }

    /**
     * Adds an inline code by its type
     *
     * @param string $type
     * @param Inline $code
     */
    public function addInlineCodeByType(string! type, <$Inline> code) -> <Manager>
    {
        var collection;

        let collection = this->checkAndCreateCollection(type);

        collection->addInline(code);

        return this;
    }

    /**
     * Adds an inline CSS to the 'css' collection
     *
     * @param string $content
     * @param bool   $filter
     * @param array  $attributes
     */
    public function addInlineCss(
        string content,
        bool filter = true,
        array attributes = []
    ) -> <Manager> {
        this->addInlineCodeByType(
            "css",
            new InlineCss(content, filter, attributes)
        );

        return this;
    }

    /**
     * Adds an inline JavaScript to the 'js' collection
     *
     * @param string $content
     * @param bool   $filter
     * @param array  $attributes
     */
    public function addInlineJs(
        string content,
        bool filter = true,
        array attributes = []
    ) -> <Manager> {
        this->addInlineCodeByType(
            "js",
            new InlineJs(content, filter, attributes)
        );

        return this;
    }

    /**
     * Adds a JavaScript asset to the 'js' collection
     *
     *```php
     * $assets->addJs("scripts/jquery.js");
     * $assets->addJs("http://jquery.my-cdn.com/jquery.js", false);
     *```
     *
     * @param string      $path
     * @param bool        $local
     * @param bool        $filter
     * @param array       $attributes
     * @param string|null $version
     * @param bool        $autoVersion
     */
    public function addJs(
        string! path,
        bool local = true,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    ) -> <Manager>
    {
        this->addAssetByType(
            "js",
            new AssetJs(path, local, filter, attributes, version, autoVersion)
        );

        return this;
    }

    /**
     * Creates/Returns a collection of assets
     *
     * @param string $name
     */
    public function collection(string name) -> <Collection>
    {
        return this->checkAndCreateCollection(name);
    }

    /**
     * Creates/Returns a collection of assets by type
     *
     * @param array  $assets
     * @param string $type
     */
    public function collectionAssetsByType(array assets, string type) -> array
    {
        var asset;
        array filtered = [];

        for asset in assets {
            if (
                asset instanceof AssetInterface &&
                type === asset->getType()
            ) {
                let filtered[] = asset;
            }
        }

        return filtered;
    }

    /**
     * Returns true or false if collection exists.
     *
     * ```php
     * if ($manager->exists("jsHeader")) {
     *     // \Phalcon\Assets\Collection
     *     $collection = $manager->get("jsHeader");
     * }
     * ```
     *
     * @param string $name
     * @deprecated
     */
    public function exists(string! name) -> bool
    {
        return this->has(name);
    }

    /**
     * Returns a collection by its id.
     *
     * ```php
     * $scripts = $assets->get("js");
     * ```
     *
     * @param string $name
     *
     * @return Collection
     * @throws Exception
     */
    public function get(string! name) -> <Collection>
    {
        if unlikely true !== isset(this->collections[name]) {
            throw new Exception("The collection does not exist in the manager");
        }

        return this->collections[name];
    }

    /**
     * Returns existing collections in the manager
     *
     * @return Collection[]
     */
    public function getCollections() -> <Collection[]>
    {
        return this->collections;
    }

    /**
     * Returns the CSS collection of assets
     *
     * @return Collection
     */
    public function getCss() -> <Collection>
    {
        return this->checkAndCreateCollection("css");
    }

    /**
     * Returns the CSS collection of assets
     *
     * @return Collection
     */
    public function getJs() -> <Collection>
    {
        return this->checkAndCreateCollection("js");
    }

    /**
     * Returns the manager options
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Returns true or false if collection exists.
     *
     * ```php
     * if ($manager->has("jsHeader")) {
     *     // \Phalcon\Assets\Collection
     *     $collection = $manager->get("jsHeader");
     * }
     * ```
     *
     * @param string $name
     */
    public function has(string! name) -> bool
    {
        return isset this->collections[name];
    }

    /**
     * Traverses a collection calling the callback to generate its HTML
     *
     * @param Collection $collection
     * @param string     $type
     *
     * @return string|null
     * @throws Exception
     */
    public function output(<Collection> collection, string type) -> string | null
    {
        string output;
        bool filterNeeded;
        var asset, assets, callback, callbackMethod, collectionSourcePath,
            collectionTargetPath, completeSourcePath, completeTargetPath,
            content, filter, filters, filteredContent, filteredJoinedContent,
            html, join, mustFilter, options, prefixedPath, sourceBasePath,
            sourcePath, targetBasePath, targetPath, typeCss;

        let completeSourcePath    = "",
            completeTargetPath    = "",
            filteredContent       = "",
            filteredJoinedContent = "",
            join                  = false,
            output                = "",
            options               = this->options;

        let callbackMethod = ("css" === type) ? "cssLink" : "jsLink",
            callback       = [this, callbackMethod];

        /**
         * Get the assets as an array
         */
        let assets = this->collectionAssetsByType(
            collection->getAssets(),
            type
        );

        /**
         * Get filters in the collection
         */
        let filters = collection->getFilters(),
            typeCss = "css";

        /**
         * Prepare options if the collection must be filtered
         */
        if (true !== empty(filters)) {
            /**
             * Check for global options in the asset manager. The source and
             * target base path are global locations where all assets are read
             * and written respectively
             */
            if !fetch sourceBasePath, options["sourceBasePath"] {
                let sourceBasePath = "";
            }

            if !fetch targetBasePath, options["targetBasePath"] {
                let targetBasePath = "";
            }

            /**
             * Check if the collection have its own source base path
             */
            let collectionSourcePath = collection->getSourcePath(),
                completeSourcePath   = sourceBasePath;

            /**
             * Concatenate the global base source path with the collection one
             */
            if (true !== empty(collectionSourcePath)) {
                let completeSourcePath .= collectionSourcePath;
            }

            /**
             * Check if the collection have its own target base path
             */
            let collectionTargetPath = collection->getTargetPath(),
                completeTargetPath   = targetBasePath;

            /**
             * Concatenate the global base source path with the collection one
             */
            if (true !== empty(collectionTargetPath)) {
                let completeTargetPath .= collectionTargetPath;
            }

            /**
             * Global filtered content
             */
            let filteredJoinedContent = "";

            /**
             * Check if the collection have its own target base path
             */
            let join = collection->getJoin();

            /**
             * Check for valid target paths if the collection must be joined
             */
            if !join {
                /**
                 * We need a valid final target path
                 */
                if (true === empty(completeTargetPath)) {
                    throw new Exception(
                        "Path '" . completeTargetPath . "' is not a valid target path (1)"
                    );
                }

                if (true === is_dir(completeTargetPath)) {
                    throw new Exception(
                        "Path '" . completeTargetPath . "' is not a valid target path (2), it is a directory."
                    );
                }
            }
        }

        /** @var Asset $asset */
        for asset in assets {
            let filterNeeded = false;

            /**
             * If the collection must not be joined we must print a HTML for
             * each one
             */
            if (true !== empty(filters)) {
                let sourcePath = asset->getPath();
                if (true === asset->isLocal()) {
                    let filterNeeded = true;
                    /**
                     * Get the complete path
                     */
                    let sourcePath = asset->getRealSourcePath(completeSourcePath);

                    /**
                     * We need a valid source path
                     */
                    if (true === empty(sourcePath)) {
                        let sourcePath = asset->getPath();

                        throw new Exception(
                            "Asset '" . sourcePath . "' does not have a valid source path"
                        );
                    }
                }

                /**
                 * Get the target path, we need to write the filtered content to
                 * a file
                 */
                let targetPath = asset->getRealTargetPath(completeTargetPath);

                /**
                 * We need a valid final target path
                 */
                if (true === empty(targetPath)) {
                    throw new Exception(
                        "Asset '" . sourcePath . "' does not have a valid target path"
                    );
                }

                if (true === asset->isLocal()) {
                    /**
                     * Make sure the target path is not the same source path
                     */
                    if (targetPath === sourcePath) {
                        throw new Exception(
                            "Asset '" . targetPath . "' have the same source and target paths"
                        );
                    }

                    if (true === file_exists(targetPath)) {
                        if (filemtime(targetPath) !== filemtime(sourcePath)) {
                            let filterNeeded = true;
                        }
                    } else {
                        let filterNeeded = true;
                    }
                }
            } else {
                /**
                 * If there are no filters, just print/buffer the HTML
                 */
                let prefixedPath = this->calculatePrefixedPath(
                    collection,
                    asset->getRealTargetUri(),
                    asset->getRealSourcePath()
                );

                /**
                 * Generate the HTML
                 */
                let html = this->doCallback(
                    callback,
                    asset->getAttributes(),
                    prefixedPath,
                    asset->isLocal()
                );

                /**
                 * Implicit output prints the content directly
                 */
                if (true === this->implicitOutput) {
                    echo html;
                } else {
                    let output .= html;
                }

                continue;
            }

            if (filterNeeded) {
                /**
                 * Gets the asset's content
                 */
                let content = asset->getContent(completeSourcePath);

                /**
                 * Check if the asset must be filtered
                 */
                let mustFilter = asset->getFilter();
                /**
                 * Only filter the asset if it's marked as 'filterable'
                 */
                if (mustFilter) {
                    for filter in filters {
                        /**
                         * Filters must be valid objects
                         */
                        if (true !== is_object(filter)) {
                            throw new Exception("Filter is invalid");
                        }

                        /**
                         * Calls the method 'filter' which must return a
                         * filtered version of the content
                         */
                        let filteredContent = filter->filter(content),
                            content         = filteredContent;
                    }

                    /**
                     * Update the joined filtered content
                     */
                    if (join) {
                        let filteredJoinedContent .= filteredContent;
                        if (asset->getType() !== typeCss) {
                            let filteredJoinedContent .= ";";
                        }
                    }
                } else {
                    /**
                     * Update the joined filtered content
                     */
                    if (join) {
                        let filteredJoinedContent .= content;
                    } else {
                        let filteredContent = content;
                    }
                }

                if (!join) {
                    /**
                     * Write the file using file-put-contents. This respects the
                     * openbase-dir also writes to streams
                     */
                    file_put_contents(targetPath, filteredContent);
                }
            }

            if (!join) {
                /**
                 * Generate the HTML using the original path in the asset
                 */
                let prefixedPath = this->calculatePrefixedPath(
                    collection,
                    asset->getRealTargetUri(),
                    asset->getRealSourcePath()
                );

                /**
                 * Generate the HTML
                 */
                let html = this->doCallback(
                    callback,
                    collection->getAttributes(),
                    prefixedPath,
                    true
                );

                /**
                 * Implicit output prints the content directly
                 */
                if (true === this->implicitOutput) {
                    echo html;
                } else {
                    let output .= html;
                }
            }
        }

        if (true !== empty(filters) && join) {
            /**
             * Write the file using file_put_contents. This respects the
             * openbase-dir also writes to streams
             */
            file_put_contents(completeTargetPath, filteredJoinedContent);

            let prefixedPath = this->calculatePrefixedPath(
                collection,
                collection->getTargetUri(),
                completeTargetPath
            );

            /**
             * Generate the HTML
             */
            let html = this->doCallback(
                callback,
                collection->getAttributes(),
                prefixedPath,
                collection->getTargetIsLocal()
            );

            /**
             * Implicit output prints the content directly
             */
            if (true === this->implicitOutput) {
                echo html;
            } else {
                let output .= html;
            }
        }

        return output;
    }

    /**
     * Prints the HTML for CSS assets
     *
     * @param string|null $name
     *
     * @return string
     * @throws Exception
     */
    public function outputCss(string name = null) -> string
    {
        var collection;

        let collection = this->getCss();

        if (true !== empty(name)) {
            let collection = this->get(name);
        }

        return this->output(collection, "css");
    }

    /**
     * Traverses a collection and generate its HTML
     *
     * @param Collection $collection
     * @param string     $type
     *
     * @return string
     * @throws Exception
     */
    public function outputInline(<Collection> collection, type) -> string
    {
        string html, joinedContent, output;
        var attributes, code, codes, content, filter, filters, join;

        let output        = "",
            html          = "",
            joinedContent = "",
            codes         = collection->getCodes(),
            filters       = collection->getFilters(),
            join          = collection->getJoin();

        if (true !== empty(codes)) {
            /** @var Inline $code */
            for code in codes {
                let attributes = code->getAttributes(),
                    content    = code->getContent();

                /** @var FilterInterface $filter */
                for filter in filters {
                    /**
                     * Filters must be valid objects
                     */
                    if (typeof filter !== "object") {
                        throw new Exception("The filter is not valid");
                    }

                    /**
                     * Calls the method 'filter' which must return a filtered
                     * version of the content
                     */
                    let content = filter->filter(content);
                }

                if (true === join) {
                    let joinedContent .= content;
                } else {
                    let html .= this->tagFactory->element(
                        type,
                        content,
                        attributes,
                        true
                    ) . PHP_EOL;
                }
            }

            if (true === join) {
                let html .= this->tagFactory->element(
                    type,
                    joinedContent,
                    attributes,
                    true
                ) . PHP_EOL;
            }

            /**
             * Implicit output prints the content directly
             */
            if (true === this->implicitOutput) {
                echo html;
            } else {
                let output .= html;
            }
        }

        return output;
    }

    /**
     * Prints the HTML for inline CSS
     *
     * @param string|null $name
     *
     * @return string
     */
    public function outputInlineCss(string name = null) -> string
    {
        var collection;

        let collection = this->getCss();
        if (true !== empty(name)) {
            let collection = this->get(name);
        }

        return this->outputInline(collection, "style");
    }

    /**
     * Prints the HTML for inline JS
     *
     * @param string|null $name
     *
     * @return string
     */
    public function outputInlineJs(string name = null) -> string
    {
        var collection;

        let collection = this->getJs();
        if (true !== empty(name)) {
            let collection = this->get(name);
        }

        return this->outputInline(collection, "script");
    }

    /**
     * Prints the HTML for JS assets
     *
     * @param string|null $name
     *
     * @return string
     * @throws Exception
     */
    public function outputJs(string name = null) -> string
    {
        var collection;

        let collection = this->getJs();
        if (true !== empty(name)) {
            let collection = this->get(name);
        }

        return this->output(collection, "js");
    }

    /**
     * Sets a collection in the Assets Manager
     *
     *```php
     * $assets->set("js", $collection);
     *```
     *
     * @param string     $name
     * @param Collection $collection
     */
    public function set(string! name, <Collection> collection) -> <Manager>
    {
        let this->collections[name] = collection;

        return this;
    }

    /**
     * Sets the manager options
     *
     * @param array $options
     */
    public function setOptions(array options) -> <Manager>
    {
        let this->options = options;

        return this;
    }

    /**
     * Sets if the HTML generated must be directly printed or returned
     *
     * @param bool $implicitOutput
     */
    public function useImplicitOutput(bool implicitOutput) -> <Manager>
    {
        let this->implicitOutput = implicitOutput;

        return this;
    }

    /**
     * Calculates the prefixed path including the version
     *
     * @param Collection $collection
     * @param string     $path
     * @param string     $filePath
     *
     * @return string
     */
    private function calculatePrefixedPath(
        <Collection> collection,
        string path,
        string filePath
    ) -> string {
        var modificationTime, prefixedPath, version;

        let prefixedPath = collection->getPrefix() . path,
            version      = collection->getVersion();

        if (
            true === collection->isAutoVersion() &&
            true === collection->isLocal()
        ) {
            let modificationTime = filemtime(filePath),
                version          = version ? version . "." . modificationTime : modificationTime;
        }

        if (version) {
            let prefixedPath = prefixedPath . "?ver=" . version;
        }

        return prefixedPath;
    }

    /**
     * @param string $type
     */
    private function checkAndCreateCollection(string type) -> <Collection>
    {
        if (true !== isset(this->collections[type])) {
            let this->collections[type] = new Collection();
        }

        return this->collections[type];
    }

    /**
     * Builds a LINK[rel="stylesheet"] tag
     *
     * @param mixed $parameters
     * @param bool  $local
     *
     * @return string
     * @throws Exception
     */
    private function cssLink(parameters = [], bool local = true) -> string
    {
        return this->processParameters(
            parameters,
            local,
            "link",
            "text/css",
            "href"
        );
    }

    /**
     * @param mixed  $callback
     * @param array  $attributes
     * @param string $prefixedPath
     * @param bool   $local
     *
     * @return string
     */
    private function doCallback(
        var callback,
        array attributes,
        string prefixedPath,
        bool local
    ) -> string {
        array parameters;

        /**
         * Prepare the parameters for the callback
         */
        if (true !== empty(attributes)) {
            let attributes[0] = prefixedPath,
                parameters    = [attributes];
        } else {
            let parameters = [prefixedPath];
        }
        let parameters[] = local;

        /**
         * Call the callback to generate the HTML
         */
        return call_user_func_array(callback, parameters);
    }

    /**
     * @param mixed $parameters
     * @param bool  $local
     *
     * @return string
     * @throws Exception
     */
    private function jsLink(parameters = [], bool local = true) -> string
    {
        return this->processParameters(
            parameters,
            local,
            "script",
            "application/javascript",
            "src"
        );
    }
    /**
     * Processes common parameters for js/css link generation
     */
    private function processParameters(
        var parameters,
        bool local,
        string helperClass,
        string type,
        string name
    ) -> string {
        var helper, params, tag;

        let params = parameters;

        if (typeof params !== "array") {
            let params = [parameters, local];
        }

        if (true === isset(params[1])) {
            let local = (bool) params[1];
            unset(params[1]);
        } else {
            if (true === isset(params["local"])) {
                let local = (bool) params["local"];

                unset(params["local"]);
            }
        }

        if (true !== isset(params["type"])) {
            let params["type"] = type;
        }

        /**
         * Only for css
         */
        if ("link" === helperClass) {
            let params["rel"] = "stylesheet";
        }

        if (true !== isset(params[name])) {
            let params[name] = "";
            if (true === isset(params[0])) {
                let params[name] = params[0];
                unset(params[0]);
            }
        }

        let tag = params[name];
        unset(params[name]);

        /**
         * URLs are generated through the "url" service
         */
        if local {
            let tag = "/" . ltrim(tag, "/");
        }

        let helper = this->tagFactory->newInstance(helperClass);

        helper->__invoke(""); // no indentation
        helper->add(tag, params);

        return (string) helper;
    }
}
