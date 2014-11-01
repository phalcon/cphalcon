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

use \Phalcon\Assets\Resource as PhResource;

class Resource extends PhResource
{
    public function getType()
    {
        return parent::getType();
    }

    public function getPath()
    {
        return parent::getPath();
    }

    public function getLocal()
    {
        return parent::getLocal();
    }

    public function getFilter()
    {
        return parent::getFilter();
    }

    public function getAttributes()
    {
        return parent::getAttributes();
    }

    public function getSourcePath()
    {
        return parent::getSourcePath();
    }

    public function getTargetPath()
    {
        return parent::getTargetPath();
    }

    public function getTargetUri()
    {
        return parent::getTargetUri();
    }

    public function setType($type)
    {
        return parent::setType($type);
    }

    public function setPath($path)
    {
        return parent::setPath($path);
    }

    public function setLocal($local)
    {
        return parent::setLocal($local);
    }

    public function setFilter($filter)
    {
        return parent::setFilter($filter);
    }

    public function setAttributes($attributes)
    {
        return parent::setAttributes($attributes);
    }

    public function setTargetUri($targetUri)
    {
        return parent::setTargetUri($targetUri);
    }

    public function setSourcePath($sourcePath)
    {
        return parent::setSourcePath($sourcePath);
    }

    public function setTargetPath($targetPath)
    {
        return parent::setTargetPath($targetPath);
    }

    public function getContent($basePath = null)
    {
        return parent::getContent($basePath);
    }

    public function getRealTargetUri()
    {
        return parent::getRealTargetUri();
    }

    public function getRealSourcePath($basePath = null)
    {
        return parent::getRealSourcePath($basePath);
    }

    public function getRealTargetPath($basePath = null)
    {
        return parent::getRealTargetPath($basePath);
    }
}
