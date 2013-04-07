<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

class AssetsTest extends PHPUnit_Framework_TestCase
{

	public function testResource()
	{
		$resource = new Phalcon\Assets\Resource('js', 'js/jquery.js');
		$this->assertEquals($resource->getType(), 'js');
		$this->assertEquals($resource->getPath(), 'js/jquery.js');
		$this->assertEquals($resource->getLocal(), true);
	}

	public function testResourceCss()
	{
		$resource = new Phalcon\Assets\Resource\Css('/css/style.css', false);
		$this->assertEquals($resource->getType(), 'css');
		$this->assertEquals($resource->getPath(), '/css/style.css');
		$this->assertEquals($resource->getLocal(), false);
	}

	public function testResourceJs()
	{
		$resource = new Phalcon\Assets\Resource\Js('/js/jquery.js', false);
		$this->assertEquals($resource->getType(), 'js');
		$this->assertEquals($resource->getPath(), '/js/jquery.js');
		$this->assertEquals($resource->getLocal(), false);
	}

	public function testCollection()
	{
		$collection = new Phalcon\Assets\Collection();

		$collection->add(new Phalcon\Assets\Resource('js', 'js/jquery.js'));
		$collection->add(new Phalcon\Assets\Resource('js', 'js/jquery-ui.js'));

		$number = 0;
		foreach ($collection as $resource) {
			$this->assertEquals($resource->getType(), 'js');
			$number++;
		}

		$this->assertEquals($number, 2);
	}

	public function testAssetsManager()
	{
		$assets = new Phalcon\Assets\Manager();

		$assets->addCss('/css/style1.css');
		$assets->addCss('/css/style2.css');

		$collection = $assets->get('css');

		$number = 0;
		foreach ($collection as $resource) {
			$this->assertEquals($resource->getType(), 'css');
			$number++;
		}

		$this->assertEquals($number, 2);

		$assets->addJs('/js/scripts1.js');
		$assets->addJs('/js/scripts2.js');

		$collection = $assets->get('js');

		$number = 0;
		foreach ($collection as $resource) {
			$this->assertEquals($resource->getType(), 'js');
			$number++;
		}

		$this->assertEquals($number, 2);

		$assets->addResource(new Phalcon\Assets\Resource\Css('/css/style.css', false));
		$this->assertEquals(count($assets->get('css')), 3);

		new Phalcon\DI\FactoryDefault();

		//With implicit output

		ob_start();
		$assets->outputCss();
		$html = ob_get_clean();

		$this->assertEquals($html, '<link rel="stylesheet" href="//css/style1.css" type="text/css" />
<link rel="stylesheet" href="//css/style2.css" type="text/css" />
<link rel="stylesheet" href="/css/style.css" type="text/css" />' . PHP_EOL);

		ob_start();
		$assets->outputJs();
		$html = ob_get_clean();

		$this->assertEquals($html, '<script src="//js/scripts1.js" type="text/javascript"></script>
<script src="//js/scripts2.js" type="text/javascript"></script>' . PHP_EOL);

		//Without implicit output

		$assets->useImplicitOutput(false);

		$html = $assets->outputCss();

		$this->assertEquals($html, '<link rel="stylesheet" href="//css/style1.css" type="text/css" />
<link rel="stylesheet" href="//css/style2.css" type="text/css" />
<link rel="stylesheet" href="/css/style.css" type="text/css" />' . PHP_EOL);

		$html = $assets->outputJs();

		$this->assertEquals($html, '<script src="//js/scripts1.js" type="text/javascript"></script>
<script src="//js/scripts2.js" type="text/javascript"></script>' . PHP_EOL);
	}

}