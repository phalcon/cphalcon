<?php
/**
 * Resource.php
 * \PhalconTest\Assets\Resource
 *
 * Resource proxy class
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

use Phalcon\Assets\Resource as PhResource;

class Resource
{
    private $resource = null;

    public function __construct($type, $path, $local = true, $filter = true, $attributes = null)
    {
        $this->resource = new PhResource($type, $path, $local, $filter, $attributes);
    }

    public function __desctruct()
    {
        unset($this->resource);
    }

    public function getType()
    {
        return $this->resource->getType();
    }

    public function getPath()
    {
        return $this->resource->getPath();
    }

    public function getLocal()
    {
        return $this->resource->getLocal();
    }

    public function getFilter()
    {
        return $this->resource->getFilter();
    }

    public function getAttributes()
    {
        return $this->resource->getAttributes();
    }

    public function getSourcePath()
    {
        return $this->resource->getSourcePath();
    }

    public function getTargetPath()
    {
        return $this->resource->getTargetPath();
    }

    public function getTargetUri()
    {
        return $this->resource->getTargetUri();
    }

	public function setType($type)
	{
        $this->resource->setType($type);
		return $this;
	}

	public function setPath($path)
	{
        $this->resource->setPath($path);
		return $this;
	}

	public function setLocal($local)
	{
        $this->resource->setLocal($local);
		return $this;
	}

	public function setFilter($filter)
	{
        $this->resource->setFilter($filter);
		return $this;
	}

	public function setAttributes($attributes)
	{
        $this->resource->setAttributes($attributes);
		return $this;
	}

	public function setTargetUri($targetUri)
	{
        $this->resource->setTargetUri($targetUri);
		return $this;
	}

	public function setSourcePath($sourcePath)
	{
        $this->resource->setSourcePath($sourcePath);
		return $this;
	}

	public function setTargetPath($targetPath)
	{
        $this->resource->setTargetPath($targetPath);
		return $this;
	}

	public function getContent($basePath = null)
	{
        return $this->resource->getContent($basePath);
	}

	public function getRealTargetUri()
	{
        return $this->resource->getRealTargetUri();
	}

	public function getRealSourcePath($basePath = null)
	{
        return $this->resource->getRealSourcePath($basePath);
	}

	public function getRealTargetPath($basePath = null)
	{
        return $this->resource->getRealTargetPath($basePath);
	}

}
