<?php
/**
 * Collection.php
 * \PhalconTest\Assets\Collection
 *
 * Collection proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace PhalconTest\Assets;

use Phalcon\Assets\Collection as PhCollection;

class Collection implements \Countable, \Iterator
{
    private $collection = null;

    public function __construct()
    {
        $this->collection = new PhCollection();
    }

    public function __desctruct()
    {
        unset($this->collection);
    }

	public function add($resource)
	{
        $this->collection->add($resource);
		return $this;
	}

	public function addInline($code)
	{
        $this->collection->addInline($code);
		return $this;
	}

	public function addCss($path, $local = null, $filter = false, $attributes = null)
	{
        $this->collection->addCss($path, $local, $filter, $attributes);
		return $this;
	}

	public function addInlineCss($content, $filter = false, $attributes = null)
	{
        $this->collection->addInlineCss($content, $filter, $attributes);
		return $this;
	}

	public function addJs($path, $local = null, $filter = false, $attributes = null)
	{
        $this->collection->addJs($path, $local, $filter, $attributes);
		return $this;
	}

	public function addInlineJs($content, $filter = false, $attributes = null)
	{
        $this->collection->addInlineJs($content, $filter, $attributes);
		return $this;
	}

	public function count()
	{
        return $this->collection->count();
	}

	public function rewind()
	{
        $this->collection->rewind();
	}

	public function current()
	{
        return $this->collection->current();
	}

	public function key()
	{
        return $this->collection->key();
	}

	public function next()
	{
        $this->collection->next();
	}

	public function valid()
	{
        return $this->collection->valid();
	}

	public function setTargetPath($targetPath)
	{
        $this->collection->setTargetPath($targetPath);
		return $this;
	}

	public function setSourcePath($sourcePath)
	{
        $this->collection->setSourcePath($sourcePath);
		return $this;
	}

	public function setTargetUri($targetUri)
	{
        $this->collection->setTargetUri($targetUri);
		return $this;
	}

	public function setPrefix($prefix)
	{
        $this->collection->setPrefix($prefix);
		return $this;
	}

	public function setLocal($local)
	{
        $this->collection->setLocal($local);
		return $this;
	}

	public function setAttributes($attributes)
	{
        $this->collection->setAttributes($attributes);
		return $this;
	}

	public function setFilters($filters)
	{
        $this->collection->setFilter($filters);
		return $this;
	}

	public function setTargetLocal($targetLocal)
	{
        $this->collection->setTargetLocal($targetLocal);
		return $this;
	}

	public function join($join)
	{
        $this->collection->join($join);
		return $this;
	}

	public function getRealTargetPath($basePath)
	{
        return $this->collection->getRealTargetPath($basePath);
	}

	public function addFilter($filter)
	{
        $this->collection->addFilter($filter);
		return $this;
	}
}
