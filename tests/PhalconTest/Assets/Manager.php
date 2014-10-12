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

use Phalcon\Assets\Manager as PhManager;

class Manager
{
    private $manager = null;

    public function __construct($options = null)
    {
        $this->manager = new PhManager($options);
    }

    public function __desctruct()
    {
        unset($this->manager);
    }

	public function setOptions($options)
	{
        $this->manager->setOptions($options);
		return $this;
	}

	public function getOptions()
	{
		return $this->manager->getOptions();
	}

	public function useImplicitOutput($implicitOutput)
	{
        $this->manager->useImplicitOutput($implicitOutput);
		return $this;
	}

	public function addCss($path, $local = true, $filter = true, $attributes = null)
	{
        $this->manager->addCss($path, $local, $filter, $attributes);
		return $this;
	}

	public function addInlineCss($content, $filter = true, $attributes = null)
	{
        $this->manager->addInlineCsse($content, $filter, $attributes);
	}

	public function addJs($path, $local = true, $filter = true, $attributes = null)
	{
        $this->manager->addJs($path, $local, $filter, $attributes);
		return $this;
	}

	public function addInlineJs($content, $filter = true, $attributes = null)
	{
        $this->manager->addInlineJs($content, $filter, $attributes);
	}

	public function addResourceByType($type, $resource)
	{
        $this->manager->addResourceByType($type, $resource);
		return $this;
	}

	public function addInlineCodeByType($type, $code)
	{
        $this->manager->addInlineCodeByType($type, $code);
		return $this;
	}

	public function addResource($resource)
	{
        $this->manager->addResource($resource);
		return $this;
	}

	public function addInlineCode($code)
	{
        $this->manager->addInlineCode($code);
		return $this;
	}

	public function set($id, $collection)
	{
        $this->manager->set($id, $collection);
		return $this;
	}

	public function get($id)
	{
        return $this->manager->get($id);
	}

	public function getCss()
	{
        return $this->manager->getCss();
	}

	public function getJs()
	{
        return $this->manager->getJs();
	}

	public function collection($name)
	{
        return $this->manager->collection($name);
	}

	public function output($collection, $callback, $type)
	{
        return $this->manager->output($collection, $callback, $type);
	}

	public function outputInline($collection, $type)
	{
        return $this->manager->outputInline($collection, $type);
	}

	public function outputCss($collectionName = null)
	{
        return $this->manager->outputCss($collectionName);
	}

	public function outputInlineCss($collectionName = null)
	{
        return $this->manager->outputInlineCss($collectionName);
	}

	public function outputJs($collectionName = null)
	{
        return $this->manager->outputJs($collectionName);
	}

	public function outputInlineJs($collectionName = null)
	{
        return $this->manager->outputInlineJs($collectionName);
	}
}
