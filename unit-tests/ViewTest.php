<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Phalcon Team (https://www.phalconphp.com)      |
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
  |          Piotr Gasiorowski <p.gasiorowski@vipserv.org>                 |
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\View as View;

class ViewTest extends PHPUnit_Framework_TestCase
{
	private $level;

	public function setUp()
	{
		$this->level = ob_get_level();
	}

	public function tearDown()
	{
		while (ob_get_level() > $this->level) {
			ob_end_flush();
		}
	}

	public function testSettersAndGetters()
	{
		$view = new View();

		$this->assertEquals($view, $view->setBasePath(__DIR__.'/../'));

		$view->foo = 'bar';
		$this->assertEquals('bar', $view->foo);

		$this->assertEquals($view, $view->setVar('foo1', 'bar1'));
		$this->assertEquals('bar1', $view->getVar('foo1'));

		$expectedVars = array('foo2' => 'bar2', 'foo3' => 'bar3');
		$this->assertEquals($view, $view->setVars($expectedVars));
		$this->assertEquals('bar2', $view->foo2);
		$this->assertEquals('bar3', $view->foo3);
		$this->assertEquals($view, $view->setVars($expectedVars, false));

		$this->assertEquals($view, $view->setParamToView('foo4', 'bar4'));

		$expectedParamsToView = array('foo2' => 'bar2', 'foo3' => 'bar3', 'foo4' => 'bar4');
		$this->assertEquals($expectedParamsToView, $view->getParamsToView());

		$this->assertEquals($view, $view->setContent('<h1>hello</h1>'));
		$this->assertEquals('<h1>hello</h1>', $view->getContent());

		$this->assertEquals($view, $view->setViewsDir('unit-tests/views/'));
		$this->assertEquals('unit-tests/views/', $view->getViewsDir());

		$this->assertEquals($view, $view->setLayoutsDir('unit-tests/views/layouts/'));
		$this->assertEquals('unit-tests/views/layouts/', $view->getLayoutsDir());

		$this->assertEquals($view, $view->setPartialsDir('unit-tests/views/partials/'));
		$this->assertEquals('unit-tests/views/partials/', $view->getPartialsDir());

		$this->assertEquals($view, $view->disableLevel(View::LEVEL_MAIN_LAYOUT));
		$this->assertEquals($view, $view->setRenderLevel(View::LEVEL_ACTION_VIEW));
		$this->assertEquals(View::LEVEL_ACTION_VIEW, $view->getRenderLevel());

		$this->assertEquals($view, $view->setMainView('html5'));
		$this->assertEquals('html5', $view->getMainView());

		$this->assertEquals($view, $view->setLayout('test2'));
		$this->assertEquals('test2', $view->getLayout());

		$this->assertEquals($view, $view->setTemplateBefore('before'));
		$this->assertEquals($view, $view->setTemplateAfter('after'));
		$this->assertEquals($view, $view->cleanTemplateBefore());
		$this->assertEquals($view, $view->cleanTemplateAfter());

		$view->start();
		$view->render('test2', 'index');
		$view->finish();

		$this->assertEquals('test2', $view->getControllerName());
		$this->assertEquals('index', $view->getActionName());
	}

	/**
	 * @covers \Phalcon\Mvc\View::__isset
	 */
	public function testViewParamIsset()
	{
		$view = new View();

		$view->setViewsDir('unit-tests/views/');
		$view->set_param = 'something';

		$content = $view->getRender('test16', 'index');

		$this->assertEquals($content, '<html>1</html>' . PHP_EOL);
	}

	protected function _getViewDisabled($level=null)
	{
		$view = new View();

		$view->setViewsDir('unit-tests/views/');

		$view->setTemplateAfter('after');
		$view->setTemplateBefore('before');

		if ($level!==null) {
			$view->disableLevel($level);
		}

		$view->start();
		$view->render('test13', 'index');
		$view->finish();

		return $view;
	}

	public function testDisableLevels()
	{
		$view = $this->_getViewDisabled();

		$this->assertEquals($view->getContent(), '<html><div class="after-layout"><div class="controller-layout"><div class="before-layout"><div class="action">Action</div></div></div></div></html>' . PHP_EOL);

		$view = $this->_getViewDisabled(View::LEVEL_ACTION_VIEW);

		$this->assertEquals($view->getContent(), '<html><div class="after-layout"><div class="controller-layout"><div class="before-layout"></div></div></div></html>' . PHP_EOL);

		$view = $this->_getViewDisabled(View::LEVEL_BEFORE_TEMPLATE);

		$this->assertEquals($view->getContent(), '<html><div class="after-layout"><div class="controller-layout"><div class="action">Action</div></div></div></html>' . PHP_EOL);

		$view = $this->_getViewDisabled(View::LEVEL_LAYOUT);

		$this->assertEquals($view->getContent(), '<html><div class="after-layout"><div class="before-layout"><div class="action">Action</div></div></div></html>' . PHP_EOL);

		$view = $this->_getViewDisabled(View::LEVEL_AFTER_TEMPLATE);

		$this->assertEquals($view->getContent(), '<html><div class="controller-layout"><div class="before-layout"><div class="action">Action</div></div></div></html>' . PHP_EOL);

		$view = $this->_getViewDisabled(View::LEVEL_MAIN_LAYOUT);

		$this->assertEquals($view->getContent(), '<div class="after-layout"><div class="controller-layout"><div class="before-layout"><div class="action">Action</div></div></div></div>');

		$view = $this->_getViewDisabled(array(
			View::LEVEL_BEFORE_TEMPLATE => true,
			View::LEVEL_LAYOUT => true,
			View::LEVEL_AFTER_TEMPLATE => true,
			View::LEVEL_MAIN_LAYOUT => true
		));

		$this->assertEquals($view->getContent(), '<div class="action">Action</div>');
	}
}
