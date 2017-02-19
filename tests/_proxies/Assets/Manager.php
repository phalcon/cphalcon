<?php

namespace Phalcon\Test\Proxy\Assets;

use Phalcon\Assets\Inline as PhInline;
use Phalcon\Assets\Manager as PhManager;
use Phalcon\Assets\Resource as PhResource;
use Phalcon\Assets\Collection as PhCollection;

/**
 * \Phalcon\Test\Proxy\Assets\Manager
 * Manager proxy class for \Phalcon\Assets\Manager
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Assets
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Manager extends PhManager
{
    public function setOptions(array $options)
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
        parent::addInlineCss($content, $filter, $attributes);
    }

    public function addJs($path, $local = true, $filter = true, $attributes = null)
    {
        return parent::addJs($path, $local, $filter, $attributes);
    }

    public function addInlineJs($content, $filter = true, $attributes = null)
    {
        parent::addInlineJs($content, $filter, $attributes);
    }

    public function addResourceByType($type, PhResource $resource)
    {
        parent::addResourceByType($type, $resource);
    }

    public function addInlineCodeByType($type, PhInline $code)
    {
        parent::addInlineCodeByType($type, $code);
    }

    public function addResource(PhResource $resource)
    {
        parent::addResource($resource);
    }

    public function addInlineCode(PhInline $code)
    {
        parent::addInlineCode($code);
    }

    public function set($id, PhCollection $collection)
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

    public function output(PhCollection $collection, $callback, $type)
    {
        return parent::output($collection, $callback, $type);
    }

    public function outputInline(PhCollection $collection, $type)
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

    public function exists($id)
    {
        return parent::exists($id);
    }
}
