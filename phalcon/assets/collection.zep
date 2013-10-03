
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
 * Phalcon\Assets\Collection
 *
 * Represents a collection of resources
 */
class Collection //implements Countable, Iterator
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

    protected _sourcePath { get, set };

    /**
    * Adds a resource to the collection
    *
    * @param Phalcon\Assets\Resource $resource
    * @return Phalcon\Assets\Collection
    */
    public function add(resource) 
    {
        if typeof resource == "object" {
            throw new Phalcon\Assets\Exception("Resource must be an object");
        }

        let this->_resources[] = resource; 
    }

    /**
    * Adds a CSS resource to the collection
    *
    * @param string $path
    * @param boolean $local
    * @param boolean $filter
    * @param array $attributes
    * @return Phalcon\Assets\Collection
    */
    public function addCss(path, local, filter, attributes)
    {
        var resource, collectionLocal, collectionAttributes;

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

        let resource = new Phalcon\Assets\Resource\Css(collectionLocal, filter, collectionAttributes);

        let this->_resources[] = resource;
    }

    /**
    * Adds a javascript resource to the collection
    *
    * @param string $path
    * @param boolean $local
    * @param boolean $filter
    * @param array $attributes
    * @return Phalcon\Assets\Collection
    */
    public function addJs(path, local, filter, attributes)
    {
        var resource, collectionLocal, collectionAttributes;

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

        let resource = new Phalcon\Assets\Resource\Js(collectionLocal, filter, collectionAttributes);

        let this->_resources[] = resource;
    }

    /**
    * Returns the number of elements in the form
    *
    * @return int
    */ 
    public function count()
    {
        return count(this->_resources);
    }

    /**
    * Rewinds the internal iterator
    */
    public function rewind()
    {
        let this->_position = 0;
    }

    /**
    * Returns the current resource in the iterator
    *
    * @return Phalcon\Assets\Resource
    */
    public function current()
    {
        var position, resource, resources;

        let position = this->_position;
        let resources = this->_resources;

        let resource = null;
        if isset resources[position] {
            let resource = resources[position];
        }

        return resource;
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
    public function next()
    {
        var position;

        //let this->_position++; //COOL
        let position = this->_position;
        let this->_position = position + 1;
    }

    /**
    * Check if the current element in the iterator is valid
    *
    * @return boolean
    */
    public function valid()
    {
        var resources;

        let resources = this->_resources;

        if isset resources[this->_position] {
            return true;
        }
        return false;
    }

    /**
    * Sets if all filtered resources in the collection must be joined in a single result file
    *
    * @param boolean $join
    * @return Phalcon\Assets\Collection
    */
    public function join(join)
    {
        let this->_join = join;
    }

    /**
    * Returns the complete location where the joined/filtered collection must be written
    *
    * @param string $basePath
    * @return string
    */
    public function getRealTargetPath(basePath) 
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
}
