
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


	public function __construct(options) 
	{
		if  typeof options == "array" {
			let this->_options = options;
		}
	}

	/**
	* Sets the manager's options
	*
	* @param array $options
	* @return Phalcon\Assets\Manager
	*/
	public function setOptions(options)
	{
		if  !typeof options == "array" {
			throw new \Phalcon\Assets\Exception("Options must be an array");
		}
		let this->_options = options;
	}

	/**
	* Returns the manager's options
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
	* @param boolean $implicitOutput
	* @return Phalcon\Assets\Manager
	*/
	public function useImplicitOutput(implicitOutput)
	{
		let this->_implicitOutput = implicitOutput;
	}


	/**
	* Adds a Css resource to the 'css' collection
	*
	*<code>
	*	$assets->addCss('css/bootstrap.css');
	*	$assets->addCss('http://bootstrap.my-cdn.com/style.css', false);
	*</code>
	*
	* @param string $path
	* @param boolean $local
	* @param boolean $filter
	* @param array $attributes
	* @return Phalcon\Assets\Manager
	*/
	public function addCss(path, local, filter, attributes)
	{
		var resource;

		if !loca {
			local = 1
		}

		if !filter {
			filter = 1
		}

		let resource  = new \Phalcon\Assets\Resource\Js(path, local, filter, attributes);
		this->addResourceByType("js",resource);
	}

	/**
	* Adds a resource by its type
	*
	*<code>
	*	$assets->addResourceByType('css', new Phalcon\Assets\Resource\Css('css/style.css'));
	*</code>
	*
	* @param string $type
	* @param Phalcon\Assets\Resource $resource
	* @return Phalcon\Assets\Manager
	*/
	public function addResourceByType(type, resource)
	{
		var collections, collection;

		let collections = this->_collections;

		if isset collections[type] {
			let collection = collections[type]; 
		} else {
			let collection = new \Phalcon\Assets\Collection();
			let this->_collections[type] = collection;
		}
		/** 
		* Add the resource to the collection
		*/
		collection->add(resource);
	}

	/**
	* Adds a raw resource to the manager
	*
	*<code>
	* $assets->addResource(new Phalcon\Assets\Resource('css', 'css/style.css'));
	*</code>
	*
	* @param Phalcon\Assets\Resource $resource
	* @return Phalcon\Assets\Manager
	*/
	public function addResource(resource)
	{
		var type;

		if typeof resource != "object" {
			throw new \Phalcon\Assets\Exception("Resource must be an object");
		}

		let type = resource->getType();

		/** 
		* Adds the resource by its type
		*/
		this->addResourceByType(type, resource); 
	}

	/**
	* Sets a collection in the Assets Manager
	*
	*<code>
	* $assets->set('js', $collection);
	*</code>
	*
	* @param string $id
	* @param Phalcon\Assets\Collection $collection
	* @return Phalcon\Assets\Manager
	*/
	public function set(id, collection)
	{
		if typeof id != "string" {
			throw new \Phalcon\Assets\Exception("Collection-Id must be a string");
		}
		if typeof collection != "object" {
			throw new \Phalcon\Assets\Exception("Collection must be an object");
		}

		let this->_collections[id] = collection;

	}

	/**
	* Returns a collection by its id
	*
	*<code>
	* $scripts = $assets->get('js');
	*</code>
	*
	* @param string $id
	* @return Phalcon\Assets\Collection
	*/
	public function get(id)
	{
		var collections;

		if typeof id != "string" {
			throw new \Phalcon\Assets\Exception("Collection-Id must be a string");
		}

		let collections = this->_collections;
		if !isset collections[id] {
			throw new \Phalcon\Assets\Exception("The collection does not exist in the manager");
		}

		return collections[id];
	}

	/**
	* Returns the CSS collection of assets
	*
	* @return Phalcon\Assets\Collection
	*/
	public function getCss()
	{
		var collections;

		let collections = this->_collections;

		/** 
		* Check if the collection does not exist and create an implicit collection
		*/
		if !isset collections["css"] {
			return new \Phalcon\Assets\Collection();
		}

		return collections["css"];
	}

	/**
	* Returns the CSS collection of assets
	*
	* @return Phalcon\Assets\Collection
	*/
	public function getJs()
	{
		var collections;

		let collections = this->_collections;

		/** 
		* Check if the collection does not exist and create an implicit collection
		*/
		if !isset collections["js"] {
			return new \Phalcon\Assets\Collection();
		}

		return collections["js"];
	}

	**
	* Creates/Returns a collection of resources
	*
	* @param string $name
	* @return Phalcon\Assets\Collection
	*/
	public function collection(name)
	{
		var collections, collection;

		let collections = this->_collections;

		if isset collections[name] {
			let collection = colelctions[name];
		} else {
			let collection = new \Phalcon\Assets\Collection();
			let this->_collections[name] = collection;
		}

		return collection;
	}

	/**
	* Traverses a collection calling the callback to generate its HTML
	*
	* @param Phalcon\Assets\Collection $collection
	* @param callback $callback
	*/
	public function output(collection, callback, type)
	{
		var output, implicitOutput, resources, filters, prefix, sourceBasePath, targetBasePath, options,
			collectionSourcePath;

		let implicitOutput = this->_implicitOutput;

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

		let type_css = "css";

		/** 
		* Prepare options if the collection must be filtered
		*/
		if typeof filter == "array" {
			
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
		
		
	}
}