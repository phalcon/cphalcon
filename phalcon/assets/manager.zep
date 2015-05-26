
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Assets;

use Phalcon\Tag;
use Phalcon\Assets\Resource;
use Phalcon\Assets\Collection;
use Phalcon\Assets\Exception;
use Phalcon\Assets\Resource\Js as ResourceJs;
use Phalcon\Assets\Resource\Css as ResourceCss;
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
	protected _options;

	protected _collections;

	protected _implicitOutput = true;

	/**
	 * Phalcon\Assets\Manager
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		if typeof options == "array" {
			let this->_options = options;
		}
	}

	/**
	 * Sets the manager options
	 */
	public function setOptions(array! options) -> <Manager>
	{
		let this->_options = options;
		return this;
	}

	/**
	 * Returns the manager options
	 */
	public function getOptions() -> array
	{
		return this->_options;
	}

	/**
	 * Sets if the HTML generated must be directly printed or returned
	 */
	public function useImplicitOutput(boolean implicitOutput) -> <Manager>
	{
		let this->_implicitOutput = implicitOutput;
		return this;
	}


	/**
	* Adds a Css resource to the 'css' collection
	*
	*<code>
	*	$assets->addCss('css/bootstrap.css');
	*	$assets->addCss('http://bootstrap.my-cdn.com/style.css', false);
	*</code>
	*
	* @param string path
	* @param boolean local
	* @param boolean filter
	* @param array attributes
	* @return Phalcon\Assets\Manager
	*/
	public function addCss(string! path, local = true, filter = true, attributes = null) -> <Manager>
	{
		this->addResourceByType("css", new ResourceCss(path, local, filter, attributes));
		return this;
	}

	/**
	* Adds a inline Css to the 'css' collection
	*
	* @param string content
	* @param boolean filter
	* @param array attributes
	* @return Phalcon\Assets\Manager
	*/
	public function addInlineCss(string content, filter = true, attributes = null)
	{
		this->addInlineCodeByType("css", new InlineCss(content, filter, attributes));
	}

	/**
	* Adds a javascript resource to the 'js' collection
	*
	*<code>
	*	$assets->addJs('scripts/jquery.js');
	*	$assets->addJs('http://jquery.my-cdn.com/jquery.js', false);
	*</code>
	*
	* @param string path
	* @param boolean local
	* @param boolean filter
	* @param array attributes
	* @return Phalcon\Assets\Manager
	*/
	public function addJs(string! path, local = true, filter = true, attributes = null) -> <Manager>
	{
		this->addResourceByType("js", new ResourceJs(path, local, filter, attributes));
		return this;
	}

	/**
	* Adds a inline javascript to the 'js' collection
	*
	* @param string content
	* @param boolean filter
	* @param array attributes
	* @return Phalcon\Assets\Manager
	*/
	public function addInlineJs(string content, filter = true, attributes = null)
	{
		this->addInlineCodeByType("js", new InlineJs(content, filter, attributes));
	}

	/**
	 * Adds a resource by its type
	 *
	 *<code>
	 *	$assets->addResourceByType('css', new \Phalcon\Assets\Resource\Css('css/style.css'));
	 *</code>
	 */
	public function addResourceByType(string! type, <$Resource> $resource) -> <Manager>
	{
		var collection;

		if !fetch collection, this->_collections[type] {
			let collection = new Collection();
			let this->_collections[type] = collection;
		}

		/**
		 * Add the resource to the collection
		 */
		collection->add($resource);

		return this;
	}

	/**
	 * Adds a inline code by its type
	 */
	public function addInlineCodeByType(string! type, <$Inline> code) -> <Manager>
	{
		var collection;

		if !fetch collection, this->_collections[type] {
			let collection = new Collection();
			let this->_collections[type] = collection;
		}

		/**
		 * Add the inline code to the collection
		 */
		collection->addInline(code);

		return this;
	}

	/**
	 * Adds a raw resource to the manager
	 *
	 *<code>
	 * $assets->addResource(new Phalcon\Assets\Resource('css', 'css/style.css'));
	 *</code>
	 */
	public function addResource(<$Resource> $resource) -> <Manager>
	{
		/**
		 * Adds the resource by its type
		 */
		this->addResourceByType($resource->getType(), $resource);
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
	 * $assets->set('js', $collection);
	 *</code>
	 */
	public function set(string! id, <Collection> collection) -> <Manager>
	{
		let this->_collections[id] = collection;
		return this;
	}

	/**
	* Returns a collection by its id
	*
	*<code>
	* $scripts = $assets->get('js');
	*</code>
	*/
	public function get(string! id) -> <Collection>
	{
		var collection;

		if !fetch collection, this->_collections[id] {
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
		if !fetch collection, this->_collections["css"] {
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
		if !fetch collection, this->_collections["js"] {
			return new Collection();
		}

		return collection;
	}

	/**
	 * Creates/Returns a collection of resources
	 */
	public function collection(string name) -> <Collection>
	{
		var collection;

		if !fetch collection, this->_collections[name] {
			let collection = new Collection();
			let this->_collections[name] = collection;
		}

		return collection;
	}

	/**
	 * Traverses a collection calling the callback to generate its HTML
	 *
	 * @param Phalcon\Assets\Collection collection
	 * @param callback callback
	 * @param string type
	 */
	public function output(<Collection> collection, callback, type)
	{
		var output, resources, filters, prefix, sourceBasePath = null,
			targetBasePath = null, options, collectionSourcePath, completeSourcePath,
			collectionTargetPath, completeTargetPath, filteredJoinedContent, join,
			$resource, filterNeeded, local, sourcePath, targetPath, path, prefixedPath,
			attributes, parameters, html, useImplicitOutput, content, mustFilter,
			filter, filteredContent, typeCss, targetUri;

		let useImplicitOutput = this->_implicitOutput;

		let output = "";

		/**
		 * Get the resources as an array
		 */
		let resources = collection->getResources();

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

			let options = this->_options;

			/**
			 * Check for global options in the assets manager
			 */
			if typeof options == "array" {

				/**
				 * The source base path is a global location where all resources are located
				 */
				fetch sourceBasePath, options["sourceBasePath"];

				/**
				 * The target base path is a global location where all resources are written
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
		 * walk in resources
		 */
		for $resource in resources {

			let filterNeeded = false;
			let type = $resource->getType();

			/**
			 * Is the resource local?
			 */
			let local = $resource->getLocal();

			/**
			 * If the collection must not be joined we must print a HTML for each one
			 */
			if count(filters) {
				if local {

					/**
					 * Get the complete path
					 */
					let sourcePath = $resource->getRealSourcePath(completeSourcePath);

					/**
					 * We need a valid source path
					 */
					if !sourcePath {
						let sourcePath = $resource->getPath();
						throw new Exception("Resource '". sourcePath. "' does not have a valid source path");
					}
				} else {

					/**
					 * Get the complete source path
					 */
					let sourcePath = $resource->getPath();

					/**
					 * resources paths are always filtered
					 */
					let filterNeeded = true;
				}

				/**
				 * Get the target path, we need to write the filtered content to a file
				 */
				let targetPath = $resource->getRealTargetPath(completeTargetPath);

				/**
				 * We need a valid final target path
				 */
				if !targetPath {
					throw new Exception("Resource '". sourcePath. "' does not have a valid target path");
				}

				if local {
					/**
					 * Make sure the target path is not the same source path
					 */
					if targetPath == sourcePath {
						throw new Exception("Resource '". targetPath. "' have the same source and target paths");
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
				let path = $resource->getRealTargetUri();

				if prefix {
					let prefixedPath = prefix . path;
				} else {
					let prefixedPath = path;
				}

				/**
				 * Gets extra HTML attributes in the resource
				 */
				let attributes = $resource->getAttributes();

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
				 * Gets the resource's content
				 */
				let content = $resource->getContent(completeSourcePath);

				/**
				 * Check if the resource must be filtered
				 */
				let mustFilter = $resource->getFilter();

				/**
				 * Only filter the resource if it's marked as 'filterable'
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
				 * Generate the HTML using the original path in the resource
				 */
				let path = $resource->getRealTargetUri();

				if prefix {
					let prefixedPath = prefix . path;
				} else {
					let prefixedPath = path;
				}

				/**
				 * Gets extra HTML attributes in the resource
				 */
				let attributes = $resource->getAttributes();

				/**
				 * Filtered resources are always local
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
				 * Generate the HTML using the original path in the resource
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
	 * @param Phalcon\Assets\Collection collection
	 * @param string type
	 */
	public function outputInline(<Collection> collection, type)
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

				if count(filters) {
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
			if this->_implicitOutput == true {
				echo html;
			} else {
				let output .= html;
			}
		}

		return output;
	}

	/**
	 * Prints the HTML for CSS resources
	 *
	 * @param string collectionName
	 */
	public function outputCss(collectionName = null)
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
	 *
	 * @param string collectionName
	 */
	public function outputInlineCss(collectionName = null)
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
	 * Prints the HTML for JS resources
	 *
	 * @param string collectionName
	 */
	public function outputJs(collectionName = null)
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
	 *
	 * @param string collectionName
	 */
	public function outputInlineJs(collectionName = null)
	{
		var collection;

		if !collectionName {
			let collection = this->getJs();
		} else {
			let collection = this->get(collectionName);
		}

		return this->outputInline(collection, "script");
	}
}
