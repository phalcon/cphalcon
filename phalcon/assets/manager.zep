
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

use Phalcon\Tag;
use Phalcon\Assets\Asset;
use Phalcon\Assets\Collection;
use Phalcon\Assets\Exception;
use Phalcon\Assets\Asset\Js as AssetJs;
use Phalcon\Assets\Asset\Css as AssetCss;
use Phalcon\Assets\Inline\Css as InlineCss;
use Phalcon\Assets\Inline\Js as InlineJs;

/**
 * Phalcon\Assets\Manager
 *
 * Manages collections of CSS/Javascript assets
 */
class Manager
{

	/**
	 * Options configure
	 * @var array
	 */
	protected options;

	protected collections;

	/**
	 * @var bool 
	 */
	protected implicitOutput = true;

	/**
	 * Phalcon\Assets\Manager
	 */
	public function __construct(array options = [])
	{
		let this->options = options;
	}

	/**
	 * Sets the manager options
	 */
	public function setOptions(array! options) -> <Manager>
	{
		let this->options = options;
		return this;
	}

	/**
	 * Returns the manager options
	 */
	public function getOptions() -> array
	{
		return this->options;
	}

	/**
	 * Sets if the HTML generated must be directly printed or returned
	 */
	public function useImplicitOutput(bool implicitOutput) -> <Manager>
	{
		let this->implicitOutput = implicitOutput;
		return this;
	}


	/**
	* Adds a Css asset to the 'css' collection
	*
	*<code>
	*	assets->addCss("css/bootstrap.css");
	*	assets->addCss("http://bootstrap.my-cdn.com/style.css", false);
	*</code>
	*/
	public function addCss(string! path, local = true, filter = true, var attributes = null) -> <Manager>
	{
		this->addAssetByType("css", new AssetCss(path, local, filter, attributes));
		return this;
	}

	/**
	 * Adds an inline Css to the 'css' collection
	 */
	public function addInlineCss(string content, filter = true, var attributes = null) -> <Manager>
	{
		this->addInlineCodeByType("css", new InlineCss(content, filter, attributes));
		return this;
	}

	/**
	 * Adds a javascript asset to the 'js' collection
	 *
	 *<code>
	 * assets->addJs("scripts/jquery.js");
	 * assets->addJs("http://jquery.my-cdn.com/jquery.js", false);
	 *</code>
	 */
	public function addJs(string! path, local = true, filter = true, attributes = null) -> <Manager>
	{
		this->addAssetByType("js", new AssetJs(path, local, filter, attributes));
		return this;
	}

	/**
	 * Adds an inline javascript to the 'js' collection
	 */
	public function addInlineJs(string content, filter = true, attributes = null) -> <Manager>
	{
		this->addInlineCodeByType("js", new InlineJs(content, filter, attributes));
		return this;
	}

	/**
	 * Adds a asset by its type
	 *
	 *<code>
	 * assets->addAssetByType("css",
	 *     new \Phalcon\Assets\Asset\Css("css/style.css")
	 * );
	 *</code>
	 */
	public function addAssetByType(string! type, <$Asset> asset) -> <Manager>
	{
		var collection;

		if !fetch collection, this->collections[type] {
			let collection = new Collection();
			let this->collections[type] = collection;
		}

		/**
		 * Add the asset to the collection
		 */
		collection->add(asset);

		return this;
	}

	/**
	 * Adds an inline code by its type
	 */
	public function addInlineCodeByType(string! type, <$Inline> code) -> <Manager>
	{
		var collection;

		if !fetch collection, this->collections[type] {
			let collection = new Collection();
			let this->collections[type] = collection;
		}

		/**
		 * Add the inline code to the collection
		 */
		collection->addInline(code);

		return this;
	}

	/**
	 * Adds a raw asset to the manager
	 *
	 *<code>
	 * assets->addAsset(
	 *     new Phalcon\Assets\Asset("css", "css/style.css")
	 * );
	 *</code>
	 */
	public function addAsset(<$Asset> asset) -> <Manager>
	{
		/**
		 * Adds the asset by its type
		 */
		this->addAssetByType(asset->getType(), asset);
		return this;
	}

	/**
	 * Adds a raw inline code to the manager
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
	 * Sets a collection in the Assets Manager
	 *
	 *<code>
	 * assets->set("js", $collection);
	 *</code>
	 */
	public function set(string! id, <Collection> collection) -> <Manager>
	{
		let this->collections[id] = collection;
		return this;
	}

	/**
	 * Returns a collection by its id.
	 *
	 * <code>
	 * $scripts = assets->get("js");
	 * </code>
	 */
	public function get(string! id) -> <Collection>
	{
		var collection;

		if !fetch collection, this->collections[id] {
			throw new Exception("The collection does not exist in the manager");
		}

		return collection;
	}

	/**
	 * Returns the CSS collection of assets
	 */
	public function getCss() -> <Collection>
	{
		var collection;

		/**
		 * Check if the collection does not exist and create an implicit collection
		 */
		if !fetch collection, this->collections["css"] {
			return new Collection();
		}

		return collection;
	}

	/**
	 * Returns the CSS collection of assets
	 */
	public function getJs() -> <Collection>
	{
		var collection;

		/**
		 * Check if the collection does not exist and create an implicit collection
		 */
		if !fetch collection, this->collections["js"] {
			return new Collection();
		}

		return collection;
	}

	/**
	 * Creates/Returns a collection of assets
	 */
	public function collection(string name) -> <Collection>
	{
		var collection;

		if !fetch collection, this->collections[name] {
			let collection = new Collection();
			let this->collections[name] = collection;
		}

		return collection;
	}

	public function collectionAssetsByType(array assets, string type) -> array
	{
		var $filtered = [], asset;
		for asset in assets {
			if asset->getType() == type {
				let $filtered[] = asset;
			}
		}

		return $filtered;
	}

	/**
	 * Traverses a collection calling the callback to generate its HTML
	 *
	 * @param callback callback
	 * @param string type
	 */
	public function output(<Collection> collection, callback, type) -> string | null
	{
		var output, assets, filters, prefix, sourceBasePath = null,
			targetBasePath = null, options, collectionSourcePath, completeSourcePath,
			collectionTargetPath, completeTargetPath, filteredJoinedContent, join,
			asset, filterNeeded, local, sourcePath, targetPath, path, prefixedPath,
			attributes, parameters, html, useImplicitOutput, content, mustFilter,
			filter, filteredContent, typeCss, targetUri;

		let useImplicitOutput = this->implicitOutput;

		let output = "";

		/**
		 * Get the assets as an array
		 */
		let assets = this->collectionAssetsByType(collection->getAssets(), type);

		/**
		 * Get filters in the collection
		 */
		let filters = collection->getFilters();

		/**
		 * Get the collection's prefix
		 */
		let prefix = collection->getPrefix();

		let typeCss = "css";

		/**
		 * Prepare options if the collection must be filtered
		 */
		if count(filters) {

			let options = this->options;

			/**
			 * Check for global options in the assets manager
			 */
			if typeof options == "array" {

				/**
				 * The source base path is a global location where all assets are located
				 */
				fetch sourceBasePath, options["sourceBasePath"];

				/**
				 * The target base path is a global location where all assets are written
				 */
				fetch targetBasePath, options["targetBasePath"];
			}

			/**
			 * Check if the collection have its own source base path
			 */
			let collectionSourcePath = collection->getSourcePath();

			/**
			 * Concatenate the global base source path with the collection one
			 */
			if collectionSourcePath {
				let completeSourcePath = sourceBasePath . collectionSourcePath;
			} else {
				let completeSourcePath = sourceBasePath;
			}

			/**
			 * Check if the collection have its own target base path
			 */
			let collectionTargetPath = collection->getTargetPath();

			/**
			 * Concatenate the global base source path with the collection one
			 */
			if collectionTargetPath {
				let completeTargetPath = targetBasePath . collectionTargetPath;
			} else {
				let completeTargetPath = targetBasePath;
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
			if join {
				/**
				* We need a valid final target path
				*/
				if !completeTargetPath {
					throw new Exception("Path '". completeTargetPath. "' is not a valid target path (1)");
				}

				if is_dir(completeTargetPath) {
					throw new Exception("Path '". completeTargetPath. "' is not a valid target path (2), is dir.");
				}
			}
		}

		/**
		 * walk in assets
		 */
		for asset in assets {

			let filterNeeded = false;
			let type = asset->getType();

			/**
			 * Is the asset local?
			 */
			let local = asset->getLocal();

			/**
			 * If the collection must not be joined we must print a HTML for each one
			 */
			if count(filters) {
				if local {

					/**
					 * Get the complete path
					 */
					let sourcePath = asset->getRealSourcePath(completeSourcePath);

					/**
					 * We need a valid source path
					 */
					if !sourcePath {
						let sourcePath = asset->getPath();
						throw new Exception("Asset '". sourcePath. "' does not have a valid source path");
					}
				} else {

					/**
					 * Get the complete source path
					 */
					let sourcePath = asset->getPath();

					/**
					 * assets paths are always filtered
					 */
					let filterNeeded = true;
				}

				/**
				 * Get the target path, we need to write the filtered content to a file
				 */
				let targetPath = asset->getRealTargetPath(completeTargetPath);

				/**
				 * We need a valid final target path
				 */
				if !targetPath {
					throw new Exception("Asset '". sourcePath. "' does not have a valid target path");
				}

				if local {

					/**
					 * Make sure the target path is not the same source path
					 */
					if targetPath == sourcePath {
						throw new Exception("Asset '". targetPath. "' have the same source and target paths");
					}

					if file_exists(targetPath) {
						if compare_mtime(targetPath, sourcePath) {
							let filterNeeded = true;
						}
					} else {
						let filterNeeded = true;
					}
				}
			} else {

				/**
				 * If there are not filters, just print/buffer the HTML
				 */
				let path = asset->getRealTargetUri();

				if prefix {
					let prefixedPath = prefix . path;
				} else {
					let prefixedPath = path;
				}

				/**
				 * Gets extra HTML attributes in the asset
				 */
				let attributes = asset->getAttributes();

				/**
				 * Prepare the parameters for the callback
				 */
				let parameters = [];
				if typeof attributes == "array" {
					let attributes[0] = prefixedPath;
					let parameters[] = attributes;
				} else {
					let parameters[] = prefixedPath;
				}
				let parameters[] = local;

				/**
				 * Call the callback to generate the HTML
				 */
				let html = call_user_func_array(callback, parameters);

				/**
				 * Implicit output prints the content directly
				 */
				if useImplicitOutput == true {
					echo html;
				} else {
					let output .= html;
				}

				continue;
			}

			if filterNeeded == true {

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
				if mustFilter == true {
					for filter in filters {

						/**
						 * Filters must be valid objects
						 */
						if typeof filter != "object" {
							throw new Exception("Filter is invalid");
						}

						/**
						 * Calls the method 'filter' which must return a filtered version of the content
						 */
						let filteredContent = filter->filter(content),
							content = filteredContent;
					}
					/**
					 * Update the joined filtered content
					 */
					if join == true {
						if type == typeCss {
							let filteredJoinedContent .= filteredContent;
						} else {
							let filteredJoinedContent .= filteredContent . ";";
						}
					}
				} else {

					/**
					 * Update the joined filtered content
					 */
					if join == true {
						let filteredJoinedContent .= content;
					} else {
						let filteredContent = content;
					}
				}

				if !join {
					/**
					 * Write the file using file-put-contents. This respects the openbase-dir also
					 * writes to streams
					 */
					file_put_contents(targetPath, filteredContent);
				}
			}

			if !join {

				/**
				 * Generate the HTML using the original path in the asset
				 */
				let path = asset->getRealTargetUri();

				if prefix {
					let prefixedPath = prefix . path;
				} else {
					let prefixedPath = path;
				}

				/**
				 * Gets extra HTML attributes in the asset
				 */
				let attributes = asset->getAttributes();

				/**
				 * Filtered assets are always local
				 */
				let local = true;

				/**
				 * Prepare the parameters for the callback
				 */
				let parameters = [];
				if typeof attributes == "array" {
					let attributes[0] = prefixedPath;
					let parameters[] = attributes;
				} else {
					let parameters[] = prefixedPath;
				}
				let parameters[] = local;

				/**
				* Call the callback to generate the HTML
				*/
				let html = call_user_func_array(callback, parameters);

				/**
				* Implicit output prints the content directly
				*/
				if useImplicitOutput == true {
					echo html;
				} else {
					let output .= html;
				}
			}
		}

		if count(filters) {

			if join == true {

				/**
				 * Write the file using file_put_contents. This respects the openbase-dir also
				 * writes to streams
				 */
				file_put_contents(completeTargetPath, filteredJoinedContent);

				/**
				 * Generate the HTML using the original path in the asset
				 */
				let targetUri = collection->getTargetUri();

				if prefix {
					let prefixedPath = prefix . targetUri;
				} else {
					let prefixedPath = targetUri;
				}

				/**
				 * Gets extra HTML attributes in the collection
				 */
				let attributes = collection->getAttributes();

				/**
				 *  Gets local
				 */
				let local = collection->getTargetLocal();

				/**
				 * Prepare the parameters for the callback
				 */
				let parameters = [];
				if typeof attributes == "array" {
					let attributes[0] = prefixedPath;
					let parameters[] = attributes;
				} else {
					let parameters[] = prefixedPath;
				}
				let parameters[] = local;

				/**
				 * Call the callback to generate the HTML
				 */
				let html = call_user_func_array(callback, parameters);

				/**
				 * Implicit output prints the content directly
				 */
				if useImplicitOutput == true {
					echo html;
				} else {
					let output .= html;
				}
			}
		}

		return output;
	}

	/**
	 * Traverses a collection and generate its HTML
	 *
	 * @param string type
	 */
	public function outputInline(<Collection> collection, type) -> string
	{
		var output, html, codes, filters, filter, code, attributes, content, join, joinedContent;

		let output = "",
			html = "",
			joinedContent = "";

		let codes = collection->getCodes(),
			filters = collection->getFilters(),
			join = collection->getJoin() ;

		if count(codes) {
			for code in codes {
				let attributes = code->getAttributes(),
					content = code->getContent();

				for filter in filters {
					/**
					 * Filters must be valid objects
					 */
					if typeof filter != "object" {
						throw new Exception("Filter is invalid");
					}

					/**
					 * Calls the method 'filter' which must return a filtered version of the content
					 */
					let content = filter->filter(content);
				}

				if join {
					let joinedContent .= content;
				} else {
					let html .= Tag::tagHtml(type, attributes, false, true) . content . Tag::tagHtmlClose(type, true);
				}
			}

			if join {
				let html .= Tag::tagHtml(type, attributes, false, true) . joinedContent . Tag::tagHtmlClose(type, true);
			}

			/**
			 * Implicit output prints the content directly
			 */
			if this->implicitOutput == true {
				echo html;
			} else {
				let output .= html;
			}
		}

		return output;
	}

	/**
	 * Prints the HTML for CSS assets
	 */
	public function outputCss(string collectionName = null) -> string
	{
		var collection;

		if !collectionName {
			let collection = this->getCss();
		} else {
			let collection = this->get(collectionName);
		}

		return this->output(collection, ["Phalcon\\Tag", "stylesheetLink"], "css");
	}

	/**
	 * Prints the HTML for inline CSS
	 */
	public function outputInlineCss(string collectionName = null) -> string
	{
		var collection;

		if !collectionName {
			let collection = this->getCss();
		} else {
			let collection = this->get(collectionName);
		}

		return this->outputInline(collection, "style");
	}

	/**
	 * Prints the HTML for JS assets
	 */
	public function outputJs(string collectionName = null) -> string
	{
		var collection;

		if !collectionName {
			let collection = this->getJs();
		} else {
			let collection = this->get(collectionName);
		}

		return this->output(collection, ["Phalcon\\Tag", "javascriptInclude"], "js");
	}

	/**
	 * Prints the HTML for inline JS
	 */
	public function outputInlineJs(string collectionName = null) -> string
	{
		var collection;

		if !collectionName {
			let collection = this->getJs();
		} else {
			let collection = this->get(collectionName);
		}

		return this->outputInline(collection, "script");
	}

	/**
	 * Returns existing collections in the manager
	 */
	public function getCollections() -> <Collection[]>
	{
		return this->collections;
	}

	/**
	 * Returns true or false if collection exists.
	 *
	 * <code>
	 * if (assets->exists("jsHeader")) {
	 *     // \Phalcon\Assets\Collection
	 *     $collection = assets->get("jsHeader");
	 * }
	 * </code>
	 */
	public function exists(string! id) -> bool
	{
		return isset this->collections[id];
	}
}
