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

class Collection extends PhCollection
{
    public function add($resource)
    {
        return parent::add($resource);
    }

    public function addInline($code)
    {
        return parent::addInline($code);
    }

    public function addCss($path, $local = null, $filter = false, $attributes = null)
    {
        return parent::addCss($path, $local, $filter, $attributes);
    }

    public function addInlineCss($content, $filter = false, $attributes = null)
    {
        return parent::addInlineCss($content, $filter, $attributes);
    }

    public function addJs($path, $local = null, $filter = false, $attributes = null)
    {
        return parent::addJs($path, $local, $filter, $attributes);
    }

    public function addInlineJs($content, $filter = false, $attributes = null)
    {
        return parent::addInlineJs($content, $filter, $attributes);
    }

    public function count()
    {
        return parent::count();
    }

    public function rewind()
    {
        parent::rewind();
    }

    public function current()
    {
        return parent::current();
    }

    public function key()
    {
        return parent::key();
    }

    public function next()
    {
        parent::next();
    }

    public function valid()
    {
        return parent::valid();
    }

    public function setTargetPath($targetPath)
    {
        return parent::setTargetPath($targetPath);
    }

    public function setSourcePath($sourcePath)
    {
        return parent::setSourcePath($sourcePath);
    }

    public function setTargetUri($targetUri)
    {
        return parent::setTargetUri($targetUri);
    }

    public function setPrefix($prefix)
    {
        return parent::setPrefix($prefix);
    }

    public function setLocal($local)
    {
        return parent::setLocal($local);
    }

    public function setAttributes($attributes)
    {
        return parent::setAttributes($attributes);
    }

    public function setFilters($filters)
    {
        return parent::setFilter($filters);
    }

    public function setTargetLocal($targetLocal)
    {
        return parent::setTargetLocal($targetLocal);
    }

    public function join($join)
    {
        return parent::join($join);
    }

    public function getRealTargetPath($basePath)
    {
        return parent::getRealTargetPath($basePath);
    }

    public function addFilter($filter)
    {
        return parent::addFilter($filter);
    }
}
