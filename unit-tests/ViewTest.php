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
  |          Piotr Gasiorowski <p.gasiorowski@vipserv.org>                 |
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\View as View;

class ViewAfterRenderListener
{
	private $_levels = array();

	public function afterRenderView($event, $view)
	{
		if ('afterRenderView' == $event->getType()) {
			$this->_levels[] = $view->getCurrentRenderLevel();
		}

		return true;
	}

	public function reset()
	{
		$this->_levels = array();
	}

	public function getLevels()
	{
		return join(',', $this->_levels);
	}
}

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

	public function testExists()
	{
		$view = new View();
		$view->setBasePath(__DIR__.'/../');
		$view->setViewsDir('unit-tests/views/');

		$this->assertTrue($view->exists('test2/index'));
		$this->assertTrue($view->exists('test3/other'));
		$this->assertFalse($view->exists('does_not_exist'));
	}

	public function testStandardRender()
	{

		$view = new View();
		$view->setBasePath(__DIR__.'/../');
		$view->setViewsDir('unit-tests/views/');

		//Standard Render
		$view->start();
		$view->render('test2', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>here</html>'.PHP_EOL);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolhere</html>'.PHP_EOL);

		//Variables
		$view->setParamToView('a_cool_var', 'le-this');

		$view->start();
		$view->render('test3', 'another');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>lol<p>le-this</p></html>'.PHP_EOL);

		//Templates
		$view->setTemplateAfter('test');

		$view->start();
		$view->render('test3', 'other');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>zuplolhere</html>' . PHP_EOL);

		$view->cleanTemplateAfter();

		//Render Levels
		$view->setRenderLevel(View::LEVEL_MAIN_LAYOUT);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolhere</html>' . PHP_EOL);

		$view->setRenderLevel(View::LEVEL_LAYOUT);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'lolhere');

		$view->setRenderLevel(View::LEVEL_ACTION_VIEW);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'here');

		//Pick View
		$view->setRenderLevel(View::LEVEL_MAIN_LAYOUT);
		$view->start();
		$view->pick('test3/yup');
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolyup</html>' . PHP_EOL);

		//No Render
		$view->setRenderLevel(View::LEVEL_NO_RENDER);
		$view->start();
		$view->pick('test3/yup');
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '');

	}

	public function testOverrideLayout()
	{

		$view = new View();

		$view->setViewsDir('unit-tests/views/');

		//Override controller layout
		$view->start();
		$view->setLayout('test6');
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>Well, this is the view content: here.</html>' . PHP_EOL);
	}

	/**
	 * @covers \Phalcon\Mvc\View::setMainView
	 */
	public function testOverrideMainView()
	{
		$view = new View();
		$view->setViewsDir('unit-tests/views/');
		$view->setMainView('html5');

		$view->start();
		$view->render('test2', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), '<!DOCTYPE html><html>here</html>' . PHP_EOL);
	}

	public function testPartials()
	{

		$view = new View();
		$view->setBasePath(__DIR__.'/../');
		$view->setViewsDir('unit-tests/views/');
		$view->setParamToView('cool_var', 'le-this');

		// Single partial
		$view->start();
		$view->render('test5', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>Hey, this is a partial, also le-this</html>' . PHP_EOL);

		// Multiple partials
		$view->start();
		$view->render('test9', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>Hey, this is a partial, also le-this<br />Hey, this is a second partial, also le-this</html>' . PHP_EOL);

		// A partial within other partial
		$view->start();
		$view->render('test5', 'subpartial');
		$view->finish();

		$this->assertEquals('<html>Including Hey, this is a partial, also le-this</html>' . PHP_EOL, $view->getContent());

		// Single partial in overridden main view
		$view->setMainView('html5');
		$view->start();
		$view->render('test5', 'index');
		$view->finish();

		$this->assertEquals('<!DOCTYPE html><html>Hey, this is a partial, also le-this</html>' . PHP_EOL, $view->getContent());


		// Retrieve a partial as a string
		$this->assertEquals('Hey, this is a partial, also le-this', $view->getPartial('partials/_partial1', array('cool_var' => 'le-this')));

	}

	public function testMissingPartial()
	{
		$this->setExpectedException('Phalcon\Mvc\View\Exception');

		$view = new View();
		$view->setBasePath(__DIR__.'/../');
		$view->setViewsDir('unit-tests/views/');

		$view->start();
		$view->render('test5', 'missing');
		$view->finish();
	}

	public function testGetRender()
	{
		$view = new View();

		$view->setViewsDir('unit-tests/views/');

		$content = $view->getRender('test5', 'index', array('cool_var' => 'le-this'));

		$this->assertEquals($content, '<html>Hey, this is a partial, also le-this</html>' . PHP_EOL);
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

	/**
	 * @covers \Phalcon\Mvc\View::getActiveRenderPath
	 */
	public function testGetActiveRenderPath()
	{
		$di = new \Phalcon\Di;
		$listener = new ViewAfterRenderListener;
		$eventsManager = new \Phalcon\Events\Manager;
		$eventsManager->attach('view', $listener);

		$view = new View;
		$view->setDI($di);
		$view->setEventsManager($eventsManager);
		$view->setBasePath(__DIR__.'/../');
		$view->setViewsDir('unit-tests/views/');
		$view->setRenderLevel(View::LEVEL_ACTION_VIEW);

		$view->start();
		$view->render('test15', 'index');
		$view->finish();

		$expectedPath = realpath('unit-tests/views/');
		$this->assertEquals($expectedPath . DIRECTORY_SEPARATOR . 'test15' . DIRECTORY_SEPARATOR . 'index.phtml',
			realpath($view->getContent()));
	}

	public function testIssue907()
	{
		$view = new View();
		$view->setBasePath(__DIR__.'/../');

		$view->setViewsDir('unit-tests/views/');

		$listener = new \ViewAfterRenderListener();
		$eventsManager = new \Phalcon\Events\Manager();
		$eventsManager->attach('view', $listener);

		$view->setEventsManager($eventsManager);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolhere</html>'.PHP_EOL);
		$this->assertEquals('1,3,5', $listener->getLevels());
		$listener->reset();

		//Templates
		$view->setTemplateAfter('test');

		$view->start();
		$view->render('test3', 'other');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>zuplolhere</html>' . PHP_EOL);
		$this->assertEquals('1,3,4,5', $listener->getLevels());
		$listener->reset();

		$view->cleanTemplateAfter();

		//Render Levels
		$view->setRenderLevel(View::LEVEL_MAIN_LAYOUT);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolhere</html>' . PHP_EOL);
		$this->assertEquals('1,3,5', $listener->getLevels());
		$listener->reset();

		$view->setRenderLevel(View::LEVEL_LAYOUT);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'lolhere');
		$this->assertEquals('1,3', $listener->getLevels());
		$listener->reset();

		$view->setRenderLevel(View::LEVEL_ACTION_VIEW);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'here');
		$this->assertEquals('1', $listener->getLevels());
		$listener->reset();

	}
}
