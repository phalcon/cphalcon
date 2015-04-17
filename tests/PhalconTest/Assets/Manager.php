<?php
/**
 * Manager.php
 * \PhalconTest\Assets\Manager
 *
 * Manager proxy class
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

use \Phalcon\Assets\Manager as PhManager;

class Manager extends PhManager
{
    public function setOptions($options)
    {
        return parent::setOptions($options);
    }

    public function getOptions()
    {
        return parent::getOptions();
    }

    public function useImplicitOutput($implicitOutput)
    {
        return parent::useImplicitOutput($implicitOutput);
    }

    public function addCss($path, $local = true, $filter = true, $attributes = null)
    {
        return parent::addCss($path, $local, $filter, $attributes);
    }

    public function addInlineCss($content, $filter = true, $attributes = null)
    {
        parent::addInlineCsse($content, $filter, $attributes);
    }

    public function addJs($path, $local = true, $filter = true, $attributes = null)
    {
        return parent::addJs($path, $local, $filter, $attributes);
    }

    public function addInlineJs($content, $filter = true, $attributes = null)
    {
        parent::addInlineJs($content, $filter, $attributes);
    }

    public function addResourceByType($type, $resource)
    {
        parent::addResourceByType($type, $resource);
    }

    public function addInlineCodeByType($type, $code)
    {
        parent::addInlineCodeByType($type, $code);
    }

    public function addResource($resource)
    {
        parent::addResource($resource);
    }

    public function addInlineCode($code)
    {
        parent::addInlineCode($code);
    }

    public function set($id, $collection)
    {
        return parent::set($id, $collection);
    }

    public function get($id)
    {
        return parent::get($id);
    }

    public function getCss()
    {
        return parent::getCss();
    }

    public function getJs()
    {
        return parent::getJs();
    }

    public function collection($name)
    {
        return parent::collection($name);
    }

    public function output($collection, $callback, $type)
    {
        return parent::output($collection, $callback, $type);
    }

    public function outputInline($collection, $type)
    {
        return parent::outputInline($collection, $type);
    }

    public function outputCss($collectionName = null)
    {
        return parent::outputCss($collectionName);
    }

    public function outputInlineCss($collectionName = null)
    {
        return parent::outputInlineCss($collectionName);
    }

    public function outputJs($collectionName = null)
    {
        return parent::outputJs($collectionName);
    }

    public function outputInlineJs($collectionName = null)
    {
        return parent::outputInlineJs($collectionName);
    }
}
