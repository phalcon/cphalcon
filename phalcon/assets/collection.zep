
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\Assets\Resource;
use Phalcon\Assets\FilterInterface;
use Phalcon\Assets\Inline;
use Phalcon\Assets\Resource\Css as ResourceCss;
use Phalcon\Assets\Resource\Js as ResourceJs;
use Phalcon\Assets\Inline\Js as InlineJs;
use Phalcon\Assets\Inline\Css as InlineCss;

/**
 * Phalcon\Assets\Collection
 *
 * Represents a collection of resources
 */
class Collection implements \Countable, \Iterator
{

	protected _prefix { get };

	protected _local = true { get };

	protected _resources = [] { get };

	protected _codes = [] { get };

	protected _position { get };

	protected _filters = [] { get };

	protected _attributes = [] { get };

	protected _join = true { get };

	protected _targetUri { get };

	protected _targetPath { get };

	protected _targetLocal = true { get };

	protected _sourcePath { get };

	protected _includedResources;

	/**
	 * Phalcon\Assets\Collection constructor
	 */
	public function __construct()
	{
		let this->_includedResources = [];
	}

	/**
	 * Adds a resource to the collection
	 */
	public function add(<$Resource> $resource) -> <Collection>
	{
		this->addResource($resource);

		return this;
	}

	/**
	 * Adds an inline code to the collection
	 */
	public function addInline(<$Inline> code) -> <Collection>
	{
		this->addResource(code);

		return this;
	}

	/**
	 * Checks this the resource is added to the collection.
	 *
	 * <code>
	 * use Phalcon\Assets\Resource;
	 * use Phalcon\Assets\Collection;
	 *
	 * $collection = new Collection();
	 * $resource = new Resource("js", "js/jquery.js");
	 * $collection->add($resource);
	 * $collection->has($resource); // true
	 * </code>
	 */
	public function has(<ResourceInterface> $resource) -> boolean
	{
		var key, resources;

		let key = $resource->getResourceKey(),
			resources = this->_includedResources;

		return in_array(key, resources);
	}

	/**
	 * Adds a CSS resource to the collection
	 */
	public function addCss(string! path, var local = null, boolean filter = true, attributes = null) -> <Collection>
	{
		var collectionLocal, collectionAttributes;

		if typeof local == "boolean" {
			let collectionLocal = local;
		} else {
			let collectionLocal = this->_local;
		}

		if typeof attributes == "array" {
			let collectionAttributes = attributes;
		} else {
			let collectionAttributes = this->_attributes;
		}

		this->add(new ResourceCss(path, collectionLocal, filter, collectionAttributes));

		return this;
	}

	/**
	 * Adds an inline CSS to the collection
	 */
	public function addInlineCss(string content, boolean filter = true, attributes = null) -> <Collection>
	{
		var collectionAttributes;

		if typeof attributes == "array" {
			let collectionAttributes = attributes;
		} else {
			let collectionAttributes = this->_attributes;
		}

		let this->_codes[] = new InlineCss(content, filter, collectionAttributes);
		return this;
	}

	/**
	 * Adds a javascript resource to the collection
	 *
	 * @param string path
	 * @param boolean local
	 * @param boolean filter
	 * @param array attributes
	 * @return \Phalcon\Assets\Collection
	 */
	public function addJs(string! path, var local = null, boolean filter = true, attributes = null) -> <Collection>
	{
		var collectionLocal, collectionAttributes;

		if typeof local == "boolean" {
			let collectionLocal = local;
		} else {
			let collectionLocal = this->_local;
		}

		if typeof attributes == "array" {
			let collectionAttributes = attributes;
		} else {
			let collectionAttributes = this->_attributes;
		}

		this->add(new ResourceJs(path, collectionLocal, filter, collectionAttributes));

		return this;
	}

	/**
	 * Adds an inline javascript to the collection
	 */
	public function addInlineJs(string content, boolean filter = true, attributes = null) -> <Collection>
	{
		var collectionAttributes;

		if typeof attributes == "array" {
			let collectionAttributes = attributes;
		} else {
			let collectionAttributes = this->_attributes;
		}

		let this->_codes[] = new InlineJs(content, filter, collectionAttributes);

		return this;
	}

	/**
	 * Returns the number of elements in the form
	 */
	public function count() -> int
	{
		return count(this->_resources);
	}

	/**
	 * Rewinds the internal iterator
	 */
	public function rewind() -> void
	{
		let this->_position = 0;
	}

	/**
	 * Returns the current resource in the iterator
	 */
	public function current() -> <$Resource>
	{
		return this->_resources[this->_position];
	}

	/**
	 * Returns the current position/key in the iterator
	 *
	 * @return int
	 */
	public function key()
	{
		return this->_position;
	}

	/**
	 * Moves the internal iteration pointer to the next position
	 */
	public function next() -> void
	{
		let this->_position++;
	}

	/**
	 * Check if the current element in the iterator is valid
	 */
	public function valid() -> boolean
	{
		return isset this->_resources[this->_position];
	}

	/**
	 * Sets the target path of the file for the filtered/join output
	 */
	public function setTargetPath(string! targetPath) -> <Collection>
	{
		let this->_targetPath = targetPath;
		return this;
	}

	/**
	 * Sets a base source path for all the resources in this collection
	 */
	public function setSourcePath(string! sourcePath) -> <Collection>
	{
		let this->_sourcePath = sourcePath;
		return this;
	}

	/**
	 * Sets a target uri for the generated HTML
	 */
	public function setTargetUri(string! targetUri) -> <Collection>
	{
		let this->_targetUri = targetUri;
		return this;
	}

	/**
	 * Sets a common prefix for all the resources
	 */
	public function setPrefix(string! prefix) -> <Collection>
	{
		let this->_prefix = prefix;
		return this;
	}

	/**
	 * Sets if the collection uses local resources by default
	 */
	public function setLocal(boolean! local) -> <Collection>
	{
		let this->_local = local;
		return this;
	}

	/**
	 * Sets extra HTML attributes
	 */
	public function setAttributes(array! attributes) -> <Collection>
	{
		let this->_attributes = attributes;
		return this;
	}

	/**
	 * Sets an array of filters in the collection
	 */
	public function setFilters(array! filters) -> <Collection>
	{
		let this->_filters = filters;
		return this;
	}

	/**
	 * Sets the target local
	 */
	public function setTargetLocal(boolean! targetLocal) -> <Collection>
	{
		let this->_targetLocal = targetLocal;
		return this;
	}

	/**
	 * Sets if all filtered resources in the collection must be joined in a single result file
	 */
	public function join(boolean join) -> <Collection>
	{
		let this->_join = join;
		return this;
	}

	/**
	 * Returns the complete location where the joined/filtered collection must be written
	 */
	public function getRealTargetPath(string! basePath) -> string
	{
		var targetPath, completePath;

		let targetPath = this->_targetPath;

		/**
		 * A base path for resources can be set in the assets manager
		 */
		let completePath = basePath . targetPath;

		/**
		 * Get the real template path, the target path can optionally don't exist
		 */
		if file_exists(completePath) {
			return realPath(completePath);
		}

		return completePath;
	}

	/**
	 * Adds a filter to the collection
	 */
	public function addFilter(<FilterInterface> filter) -> <Collection>
	{
		let this->_filters[] = filter;
		return this;
	}

	/**
	 * Adds a resource or inline-code to the collection
	 */
	protected final function addResource(<ResourceInterface> $resource) -> boolean
	{
		if !this->has($resource) {
			if $resource instanceof $Resource {
				let this->_resources[] = $resource;
			} else {
				let this->_codes[] = $resource;
			}

			let this->_includedResources[] = $resource->getResourceKey();

			return true;
		}

		return false;
	}
}
