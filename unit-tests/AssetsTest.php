<?php

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

class TrimFilter implements \Phalcon\Assets\FilterInterface
{
	public function filter($s)
	{
		return str_replace(array("\n", "\r", " ", "\t"), '', $s);
	}
}

class UppercaseFilter implements \Phalcon\Assets\FilterInterface
{
	public function filter($s)
	{
		return strtoupper($s);
	}
}

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

		Phalcon\DI::reset();

		//Create a default DI
		$di = new Phalcon\DI();

		$di->set('url', function(){
			$url = new Phalcon\Mvc\Url();
			$url->setBaseUri('/');
			return $url;
		});

		$di->set('escaper', function() { return new \Phalcon\Escaper(); });

		//With implicit output

		ob_start();
		$assets->outputCss();
		$html = ob_get_clean();

		$this->assertEquals($html, '<link rel="stylesheet" type="text/css" href="//css/style1.css" />
<link rel="stylesheet" type="text/css" href="//css/style2.css" />
<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL);

		ob_start();
		$assets->outputJs();
		$html = ob_get_clean();

		$this->assertEquals($html, '<script type="text/javascript" src="//js/scripts1.js"></script>
<script type="text/javascript" src="//js/scripts2.js"></script>' . PHP_EOL);

		//Without implicit output

		$assets->useImplicitOutput(false);

		$html = $assets->outputCss();

		$this->assertEquals($html, '<link rel="stylesheet" type="text/css" href="//css/style1.css" />
<link rel="stylesheet" type="text/css" href="//css/style2.css" />
<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL);

		$html = $assets->outputJs();

		$this->assertEquals($html, '<script type="text/javascript" src="//js/scripts1.js"></script>
<script type="text/javascript" src="//js/scripts2.js"></script>' . PHP_EOL);

		//Test collections
		$assets->collection('footer')
			->addCss('css/style-1.css');

		$footer = $assets->collection('footer');
		$footer->addCss('css/style-2.css');

		$html = $assets->outputCss('footer');

		$this->assertEquals($html, '<link rel="stylesheet" type="text/css" href="/css/style-1.css" />
<link rel="stylesheet" type="text/css" href="/css/style-2.css" />' . PHP_EOL);

		$scripts = $assets
			->collection('header')
    		->setPrefix('http:://cdn.example.com/')
    		->setLocal(false)
			->addJs('js/jquery.js')
        	->addJs('js/bootstrap.min.js');

		$html = $assets->outputJs('header');

		$this->assertEquals($html, '<script type="text/javascript" src="http:://cdn.example.com/js/jquery.js"></script>
<script type="text/javascript" src="http:://cdn.example.com/js/bootstrap.min.js"></script>' . PHP_EOL);
	}

	public function testJsminFilter()
	{
		$jsmin = new Phalcon\Assets\Filters\Jsmin();

		try {
			$filtered = $jsmin->filter(null);
		} catch(Exception $e) {
			$this->assertEquals($e->getMessage(), 'Script must be a string');
		}

		try {
			$filtered = $jsmin->filter('/*');
		} catch(Exception $e) {
			$this->assertEquals($e->getMessage(), 'Unterminated comment.');
		}

		try {
			$filtered = $jsmin->filter('a = "');
		} catch(Exception $e) {
			$this->assertEquals($e->getMessage(), 'Unterminated string literal.');
		}

		try {
			$filtered = $jsmin->filter('b = /[a-z]+');
		} catch(Exception $e) {
			$this->assertEquals($e->getMessage(), 'Unterminated Regular Expression literal.');
		}

		$filtered = $jsmin->filter('');
		$this->assertEquals($filtered, '');

		$filtered = $jsmin->filter('{}}');
		$this->assertEquals($filtered, "\n" . '{}}');

		$filtered = $jsmin->filter('if ( a == b ) {    document . writeln("hello") ; }');
		$this->assertEquals($filtered, "\n" . 'if(a==b){document.writeln("hello");}');

		$filtered = $jsmin->filter("if ( a == b ) {    document . writeln('\t') ; }");
		$this->assertEquals($filtered, "\n" . "if(a==b){document.writeln('\t');}");

		$filtered = $jsmin->filter("/** this is a comment */ if ( a == b ) {    document . writeln('\t') ; /** this is a comment */ }");
		$this->assertEquals($filtered, "\n" . "if(a==b){document.writeln('\t');}");

		$filtered = $jsmin->filter("\t\ta\t\r\n= \n \r\n100;\t");
		$this->assertEquals($filtered, "\n" . 'a=100;');
	}

	public function testCssminFilter()
	{
		$cssmin = new Phalcon\Assets\Filters\Cssmin();

		try {
			$filtered = $cssmin->filter(null);
		} catch(Exception $e) {
			$this->assertEquals($e->getMessage(), 'Style must be a string');
		}

		$filtered = $cssmin->filter('');
		$this->assertEquals($filtered, '');

		$filtered = $cssmin->filter(' ');
		$this->assertEquals($filtered, ' ');

		$filtered = $cssmin->filter('{}}');
		$this->assertEquals($filtered, '{}}');

		$filtered = $cssmin->filter(".s { d 	:		b; }");
		$this->assertEquals($filtered, ".s{d : b;}");

		$filtered = $cssmin->filter(".social-link {display: inline-block; width: 44px; height: 44px; text-align: left; text-indent: -9999px; overflow: hidden; background: url('../images/social-links.png'); }");
		$this->assertEquals($filtered, ".social-link{display: inline-block;width: 44px;height: 44px;text-align: left;text-indent: -9999px;overflow: hidden;background: url('../images/social-links.png');}");

		$filtered = $cssmin->filter("h2:after 	    { border-width:   	  1px; }");
		$this->assertEquals($filtered, 'h2:after{border-width: 1px;}');

		$filtered = $cssmin->filter("h1 > p { font-family: 'Helvetica Neue'; }");
		$this->assertEquals($filtered, "h1> p{font-family: 'Helvetica Neue';}");

		$filtered = $cssmin->filter("h2:after,
		.h2:after {
		content: ''; display 	:
		block; height: 1px; width: 100%; border-color:         #c0c0c0; border-style:
		solid
		none;
		border-width: 1px;
		position: absolute;
		bottom: 	0; left: 	0;
}	");
		$this->assertEquals($filtered, "h2:after, .h2:after{content: '';display : block;height: 1px;width: 100%;border-color: #c0c0c0;border-style: solid none;border-width: 1px;position: absolute;bottom: 0;left: 0;} ");

		$filtered = $cssmin->filter(".navbar .nav>li>a { color: #111; text-decoration: underline; }");
		$this->assertEquals($filtered, ".navbar .nav>li>a{color: #111;text-decoration: underline;}");
	}

	public function testNoneFilter()
	{
		$cssmin = new Phalcon\Assets\Filters\None();

		$filtered = $cssmin->filter(' ');
		$this->assertEquals($filtered, ' ');
	}

	public function testFilterSimpleNoJoin()
	{
		@unlink('unit-tests/assets/production/combined.js');

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di['url'] = function() {
			$url = new Phalcon\Mvc\Url();
			$url->setStaticBaseUri('/');
			return $url;
		};

		$di->set('escaper', function() { return new \Phalcon\Escaper(); });

		$assets = new Phalcon\Assets\Manager();

		$assets->useImplicitOutput(false);

		$js = $assets->collection('js');

		$js->setTargetPath('unit-tests/assets/production/combined.js');

		$js->setTargetUri('production/combined.js');

		$js->addJs('unit-tests/assets/jquery.js', false, false);

		//Basic output
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' . PHP_EOL);

		//Enabling join
		$js->join(true);
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' . PHP_EOL);

		//Disabling join
		$js->join(false);
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' . PHP_EOL);

		//Filter - Join
		$js->join(false);
		$js->addFilter(new Phalcon\Assets\Filters\None());
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="/unit-tests/assets/jquery.js"></script>' . PHP_EOL);

	}

	public function testFilterSimpleJoin()
	{
		@unlink('unit-tests/assets/production/combined.js');

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di['url'] = function() {
			$url = new Phalcon\Mvc\Url();
			$url->setStaticBaseUri('/');
			return $url;
		};

		$di->set('escaper', function() { return new \Phalcon\Escaper(); });

		$assets = new Phalcon\Assets\Manager();

		$assets->useImplicitOutput(false);

		$js = $assets->collection('js');

		$js->setTargetPath('unit-tests/assets/production/combined.js');

		$js->setTargetUri('production/combined.js');

		$js->addJs('unit-tests/assets/jquery.js', false, false);

		//Basic output
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' . PHP_EOL);

		//Enabling join
		$js->join(true);
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' . PHP_EOL);

		//Disabling join
		$js->join(false);
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' . PHP_EOL);

		//Filter + Join
		$js->join(true);
		$js->addFilter(new Phalcon\Assets\Filters\None());
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="/production/combined.js"></script>' . PHP_EOL);
	}

	public function testFilterMultiplesSourcesNoFilter()
	{
		@unlink('unit-tests/assets/production/combined-1.js');

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di['url'] = function() {
			$url = new Phalcon\Mvc\Url();
			$url->setStaticBaseUri('/');
			return $url;
		};

		$di->set('escaper', function() { return new \Phalcon\Escaper(); });

		$assets = new Phalcon\Assets\Manager();

		$assets->useImplicitOutput(false);

		$js = $assets->collection('js');

		$js->setTargetPath('unit-tests/assets/production/combined-1.js');

		$js->setTargetUri('production/combined.js');

		$js->addJs('jquery.js', false, false);
		$js->addJs('gs.js');

		//Basic output
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="jquery.js"></script>' . PHP_EOL . '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL);

		//Enabling join
		$js->join(true);
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="jquery.js"></script>' . PHP_EOL . '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL);

		//Disabling join
		$js->join(false);
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="jquery.js"></script>' . PHP_EOL . '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL);
	}

	public function testFilterMultiplesSourcesFilterNoJoin()
	{
		@unlink('unit-tests/assets/production/combined-2.js');

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di['url'] = function() {
			$url = new Phalcon\Mvc\Url();
			$url->setStaticBaseUri('/');
			return $url;
		};

		$di->set('escaper', function() { return new \Phalcon\Escaper(); });

		$assets = new Phalcon\Assets\Manager();

		$assets->useImplicitOutput(false);

		$js = $assets->collection('js');

		$js->setTargetPath('unit-tests/assets/production/');

		$jquery = new Phalcon\Assets\Resource\Js('unit-tests/assets/jquery.js', false, false);

		$jquery->setTargetUri('jquery.js');

		$js->add($jquery);

		$gs = new Phalcon\Assets\Resource\Js('unit-tests/assets/gs.js');

		$gs->setTargetUri('gs.js');
		$gs->setTargetPath('gs.js');

		$js->add($gs);

		//Basic output
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="jquery.js"></script>' . PHP_EOL . '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL);

		//Enabling join
		$js->join(true);
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="jquery.js"></script>' . PHP_EOL . '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL);

		//Disabling join
		$js->join(false);
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="jquery.js"></script>' . PHP_EOL . '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL);

		$js->addFilter(new Phalcon\Assets\Filters\None());
		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="/jquery.js"></script>' . PHP_EOL . '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL);
	}

	public function testFilterMultiplesSourcesFilterJoin()
	{
		@unlink('unit-tests/assets/production/combined-3.js');

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di['url'] = function() {
			$url = new Phalcon\Mvc\Url();
			$url->setStaticBaseUri('/');
			return $url;
		};

		$di->set('escaper', function() { return new \Phalcon\Escaper(); });

		$assets = new Phalcon\Assets\Manager();

		$assets->useImplicitOutput(false);

		$js = $assets->collection('js');

		$js->setTargetUri('production/combined-3.js');
		$js->setTargetPath('unit-tests/assets/production/combined-3.js');

		$jquery = new Phalcon\Assets\Resource\Js('unit-tests/assets/jquery.js', false, false);

		$jquery->setTargetUri('jquery.js');

		$js->add($jquery);

		$gs = new Phalcon\Assets\Resource\Js('unit-tests/assets/gs.js');

		$gs->setTargetUri('gs.js');
		$gs->setTargetPath('gs.js');

		$js->add($gs);
		$js->join(true);

		//Use two filters
		$js->addFilter(new Phalcon\Assets\Filters\None());
		$js->addFilter(new Phalcon\Assets\Filters\None());

		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="/production/combined-3.js"></script>' . PHP_EOL);
	}

	public function testIssue1198()
	{
		@unlink(__DIR__ . '/assets/production/1198.css');
		$di = new \Phalcon\DI\FactoryDefault();
		$assets = new \Phalcon\Assets\Manager();
		$assets->useImplicitOutput(false);
		$css = $assets->collection('css');
		$css->setTargetPath(__DIR__ . '/assets/production/1198.css');
		$css->addCss(__DIR__ . '/assets/1198.css');
		$css->addFilter(new UppercaseFilter());
		$css->addFilter(new TrimFilter());
		$css->join(true);
		$assets->outputCss('css');

		$this->assertEquals(file_get_contents(__DIR__ . '/assets/production/1198.css'), 'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}');
		@unlink(__DIR__ . '/assets/production/1198.css');
	}

	public function testIssue1532()
	{
		@unlink(__DIR__ . '/assets/production/1532.js');
		$di = new \Phalcon\DI\FactoryDefault();
		$assets = new \Phalcon\Assets\Manager();
		$assets->useImplicitOutput(false);
		$assets->collection('js')
			->addJs('unit-tests/assets/jquery.js')
			->join(true)
			->addFilter(new Phalcon\Assets\Filters\Jsmin())
			->setTargetPath(__DIR__ .'/assets/production/1532.js')
			->setTargetLocal(FALSE)
			->setPrefix('//phalconphp.com/')
			->setTargetUri('js/jquery.js');

		$this->assertEquals($assets->outputJs('js'), '<script type="text/javascript" src="//phalconphp.com/js/jquery.js"></script>' . PHP_EOL);
	}

}
