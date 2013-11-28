
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
	public function __construct(options)
	{
		if  typeof options == "array" {
			let this->_options = options;
		}
	}

	/**
	 * Sets the manager options
	 *
	 * @param array options
	 * @return Phalcon\Assets\Manager
	 */
	public function setOptions(options) -> <Phalcon\Assets\Manager>
	{
		if  typeof options != "array" {
			throw new Phalcon\Assets\Exception("Options must be an array");
		}
		let this->_options = options;
		return this;
	}

	/**
	 * Returns the manager options
	 *
	 * @return array
	 */
	public function getOptions()
	{
		return this->_options;
	}

	/**
	 * Sets if the HTML generated must be directly printed or returned
	 *
	 * @param boolean implicitOutput
	 * @return Phalcon\Assets\Manager
	 */
	public function useImplicitOutput(boolean implicitOutput) -> <Phalcon\Assets\Manager>
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
	public function addCss(string! path, local=true, filter=true, attributes)
	{
		this->addResourceByType("css", new Phalcon\Assets\Resource\Js(path, local, filter, attributes));
	}

	/**
	 * Adds a resource by its type
	 *
	 *<code>
	 *	$assets->addResourceByType('css', new Phalcon\Assets\Resource\Css('css/style.css'));
	 *</code>
	 *
	 * @param string type
	 * @param Phalcon\Assets\Resource resource
	 * @return Phalcon\Assets\Manager
	 */
	public function addResourceByType(string! type, <Phalcon\Assets\Resource> resource) -> <Phalcon\Assets\Manager>
	{
		var collections, collection;

		let collections = this->_collections;
		if !fetch collection, collections[type] {
			let this->_collections[type] = new Phalcon\Assets\Collection();
		}

		/**
		 * Add the resource to the collection
		 */
		collection->add(resource);

		return this;
	}

	/**
	 * Adds a raw resource to the manager
	 *
	 *<code>
	 * $assets->addResource(new Phalcon\Assets\Resource('css', 'css/style.css'));
	 *</code>
	 *
	 * @param Phalcon\Assets\Resource resource
	 * @return Phalcon\Assets\Manager
	 */
	public function addResource(<Phalcon\Assets\Resource> resource) -> <Phalcon\Assets\Manager>
	{
		var type;

		if typeof resource != "object" {
			throw new Phalcon\Assets\Exception("Resource must be an object");
		}

		let type = resource->getType();

		/**
		 * Adds the resource by its type
		 */
		this->addResourceByType(type, resource);
		return this;
	}

	/**
	 * Sets a collection in the Assets Manager
	 *
	 *<code>
	 * $assets->set('js', $collection);
	 *</code>
	 *
	 * @param string id
	 * @param Phalcon\Assets\Collection collection
	 * @return Phalcon\Assets\Manager
	 */
	public function set(string! id, <Phalcon\Assets\Collection> collection) -> <Phalcon\Assets\Manager>
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
	*
	* @param string id
	* @return Phalcon\Assets\Collection
	*/
	public function get(string! id) -> <Phalcon\Assets\Collection>
	{
		var collections, collection;

		let collections = this->_collections;
		if !fetch collection, collections[id] {
			throw new Phalcon\Assets\Exception("The collection does not exist in the manager");
		}

		return collection;
	}

	/**
	 * Returns the CSS collection of assets
	 *
	 * @return Phalcon\Assets\Collection
	 */
	public function getCss() -> <Phalcon\Assets\Collection>
	{
		var collection, collections;

		/**
		 * Check if the collection does not exist and create an implicit collection
		 */
		let collections = this->_collections;
		if !fetch collection, collections["css"] {
			return new Phalcon\Assets\Collection();
		}
		return collection;
	}

	/**
	 * Returns the CSS collection of assets
	 *
	 * @return Phalcon\Assets\Collection
	 */
	public function getJs() -> <Phalcon\Assets\Collection>
	{
		var collections, collection;

		/**
		 * Check if the collection does not exist and create an implicit collection
		 */
		let collections = this->_collections;
		if !fetch collection, collections["js"] {
			return new Phalcon\Assets\Collection();
		}

		return collection;
	}

	/**
	 * Creates/Returns a collection of resources
	 *
	 * @param string name
	 * @return Phalcon\Assets\Collection
	 */
	public function collection(string name) -> <Phalcon\Assets\Collection>
	{
		var collections, collection;

		let collections = this->_collections;

		if !fetch collection, collections[name] {
			let collection = new Phalcon\Assets\Collection();
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
	public function output(<Phalcon\Assets\Collection> collection, callback, type)
	{
		var output, resources, filters, prefix, sourceBasePath,
			targetBasePath, options, collectionSourcePath, completeSourcePath,
			collectionTargetPath, completeTargetPath, filteredJoinedContent, join,
			resource, filterNeeded, local, sourcePath, targetPath, path, prefixedPath,
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
		if typeof filters == "array" {

			let options = this->_options;

			/**
			 * Check for global options in the assets manager
			 */
			if typeof options == "array" {

				/**
				 * The source base path is a global location where all resources are located
				 */
				if isset options["sourceBasePath"] {
					let sourceBasePath = options["sourceBasePath"];
				}

				/**
				 * The target base path is a global location where all resources are written
				 */
				if isset options["targetBasePath"] {
					let targetBasePath = options["targetBasePath"];
				}
			}
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
		let filteredJoinedContent = null;

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
				throw new Phalcon\Assets\Exception("Path '". completeTargetPath. "' is not a valid target path (1)");
			}

			if is_dir(completeTargetPath) {
				throw new Phalcon\Assets\Exception("Path '". completeTargetPath. "' is not a valid target path (2), is dir.");
			}
		}

		/**
		 * walk in resources
		 */
		for resource in resources {
			let filterNeeded = false;
			let type = resource->getType();

			/**
			 * Is the resource local?
			 */
			let local = resource->getLocal();

			/**
			 * If the collection must not be joined we must print a HTML for each one
			 */
			if typeof filters == "array" {
				if join {
					if local {

						/**
						 * Get the complete path
						 */
						let sourcePath = resource->getRealSourcePath();

						/**
						 * We need a valid source path
						 */
						if !sourcePath {
							let sourcePath = resource->getPath();
							throw new Phalcon\Assets\Exception("Resource '". sourcePath. "' does not have a valid source path");
						}
					} else {

						/**
						 * Get the complete source path
						 */
						let sourcePath = resource->getPath();

						/**
						 * resources paths are always filtered
						 */
						let filterNeeded = true;
					}

					/**
					* Get the target path, we need to write the filtered content to a file
					*/
					let targetPath = resource->getRealTargetPath(completeTargetPath);

					/**
					* We need a valid final target path
					*/
					if !targetPath {
						throw new Phalcon\Assets\Exception("Resource '". sourcePath. "' does not have a valid target path");
					}

					if local {
						/**
						 * Make sure the target path is not the same source path
						 */
						if targetPath == sourcePath {
							throw new Phalcon\Assets\Exception("Resource '". targetPath. "' have the same source and target paths");
						}

						if file_exists(targetPath) {
							if compare_mtime(targetPath, sourcePath) {
								let filterNeeded = true;
							}
						} else {
							let filterNeeded = true;
						}
					}
				}
			} else {

				/**
				 * If there are not filters, just print/buffer the HTML
				 */
				let path = resource->getRealTargetUri();

				if prefix {
					let prefixedPath = prefix . path;
				} else {
					let prefixedPath = path;
				}

				/**
				 * Gets extra HTML attributes in the resource
				 */
				let attributes = resource->getAttributes();

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
				let content = resource->getContent(completeSourcePath);

				/**
				 * Check if the resource must be filtered
				 */
				let mustFilter = resource->getFilter();

				/**
				 * Only filter the resource if it's marked as 'filterable'
				 */
				if mustFilter == true {
					for filter in filters {

						/**
						 * Filters must be valid objects
						 */
						if typeof filter != "object" {
							throw new Phalcon\Assets\Exception("Filter is invalid");
						}

						/**
						 * Calls the method 'filter' which must return a filtered version of the content
						 */
						let filteredContent = filter->filter(content);

						/**
						 * Update the joined filtered content
						 */
						if join == true {
							if type == typeCss {
								if filteredJoinedContent==null {
									let filteredJoinedContent = filteredContent;
								} else {
									let filteredJoinedContent .= filteredContent;
								}
							} else {
								if filteredJoinedContent==null {
									let filteredJoinedContent = filteredContent . ";";
								} else {
									let filteredJoinedContent .= filteredContent. ";";
								}
							}
						}
					}
				} else {

					/**
					 * Update the joined filtered content
					 */
					if join == true {

					} else {
						if filteredJoinedContent == null {
							let filteredJoinedContent = content;
						} else {
							let filteredContent = content;
						}
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
				let path = resource->getRealTargetUri();

				if prefix {
					let prefixedPath = prefix . path;
				} else {
					let prefixedPath = path;
				}

				/**
				 * Gets extra HTML attributes in the resource
				 */
				let attributes = resource->getAttributes();

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

		if typeof filters == "array" {

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
				 * Gets extra HTML attributes in the resource
				 */
				let attributes = resource->getAttributes();

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
	 * Prints the HTML for CSS resources
	 *
	 * @param string collectionName
	 */
	public function outputCss(collectionName)
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
	 * Prints the HTML for JS resources
	 *
	 * @param string collectionName
	 */
	public function outputJs(collectionName)
	{
		var collection;

		if !collectionName {
			let collection = this->getJs();
		} else {
			let collection = this->get(collectionName);
		}

		return this->output(collection, ["Phalcon\\Tag", "javascriptInclude"], "js");
	}
}
