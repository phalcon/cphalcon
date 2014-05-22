
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Assets\Collection
 *
 * Represents a collection of resources
 */
class Collection implements \Countable, \Iterator
{

	protected _prefix { get, set };

	protected _local = true { get, set };

	protected _resources { get, set };

	protected _position { get, set };

	protected _filters { get, set };

	protected _attributes { get, set };

	protected _join = true { get, set };

	protected _targetUri { get, set };

	protected _targetPath { get, set };

	protected _targetLocal = true { get, set };

	protected _sourcePath { get, set };

	/**
	 * Adds a resource to the collection
	 *
	 * @param Phalcon\Assets\Resource resource
	 * @return Phalcon\Assets\Collection
	 */
	public function add(<\Phalcon\Assets\Resource> $resource) -> <\Phalcon\Assets\Collection>
	{
		let this->_resources[] = $resource;
		return this;
	}

	/**
	 * Adds a CSS resource to the collection
	 *
	 * @param string path
	 * @param boolean local
	 * @param boolean filter
	 * @param array attributes
	 * @return Phalcon\Assets\Collection
	 */
	public function addCss(string! path, boolean local = false, boolean filter = false, attributes = null) -> <\Phalcon\Assets\Collection>
	{
		var collectionLocal, collectionAttributes;

		if !filter {
			let filter = true;
		}

		if typeof local == "bool" {
			let collectionLocal = local;
		} else {
			let collectionLocal = this->_local;
		}

		if typeof attributes == "array" {
			let collectionAttributes = attributes;
		} else {
			let collectionAttributes = this->_attributes;
		}

		let this->_resources[] = new \Phalcon\Assets\Resource\Css(path, collectionLocal, filter, collectionAttributes);

		return this;
	}

	/**
	 * Adds a javascript resource to the collection
	 *
	 * @param string path
	 * @param boolean local
	 * @param boolean filter
	 * @param array attributes
	 * @return Phalcon\Assets\Collection
	 */
	public function addJs(string! path, boolean local = false, boolean filter = false, attributes = null) -> <\Phalcon\Assets\Collection>
	{
		var collectionLocal, collectionAttributes;

		if !filter {
			let filter = true;
		}

		if typeof local == "bool" {
			let collectionLocal = local;
		} else {
			let collectionLocal = this->_local;
		}

		if typeof attributes == "array" {
			let collectionAttributes = attributes;
		} else {
			let collectionAttributes = this->_attributes;
		}

		let this->_resources[] = new \Phalcon\Assets\Resource\Js(path, collectionLocal, filter, collectionAttributes);

		return this;
	}

	/**
	 * Returns the number of elements in the form
	 *
	 * @return int
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
	 *
	 * @return Phalcon\Assets\Resource
	 */
	public function current() -> <\Phalcon\Assets\Resource>
	{
		var $resource;
		fetch $resource, this->_resources[this->_position];
		return $resource;
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
	 *
	 */
	public function next() -> void
	{
		let this->_position++;
	}

	/**
	 * Check if the current element in the iterator is valid
	 *
	 * @return boolean
	 */
	public function valid() -> boolean
	{
		return isset this->_resources[this->_position];
	}

	/**
	 * Sets if all filtered resources in the collection must be joined in a single result file
	 *
	 * @param boolean join
	 * @return Phalcon\Assets\Collection
	 */
	public function join(boolean join) -> <\Phalcon\Assets\Collection>
	{
		let this->_join = join;
		return this;
	}

	/**
	 * Returns the complete location where the joined/filtered collection must be written
	 *
	 * @param string basePath
	 * @return string
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
	 *
	 * @param Phalcon\Assets\FilterInterface $filter
	 * @return Phalcon\Assets\Collection
	 */
	public function addFilter(<\Phalcon\Assets\FilterInterface> $filter) -> <\Phalcon\Assets\Collection>
	{
		let this->_filters[] = $filter;
		return this;
	}
}
