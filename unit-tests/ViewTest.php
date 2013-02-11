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

use Phalcon\Mvc\View as View;

class ViewTest extends PHPUnit_Framework_TestCase
{

	/*public function testStandardRender()
	{

		$view = new View();
		$view->setBasePath(__DIR__.'/../');

		$view->setViewsDir('unit-tests/views/');
		$this->assertEquals($view->getViewsDir(), 'unit-tests/views/');

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

		$view = new Phalcon\Mvc\View();

		$view->setViewsDir('unit-tests/views/');

		//Override controller layout
		$view->start();
		$view->setLayout('test6');
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>Well, this is the view content: here.</html>' . PHP_EOL);
	}

	public function testPartials()
	{

		$view = new Phalcon\Mvc\View();
		$view->setBasePath(__DIR__.'/../');

		$view->setViewsDir('unit-tests/views/');
		$this->assertEquals($view->getViewsDir(), 'unit-tests/views/');

		$view->setParamToView('cool_var', 'le-this');

		$view->start();
		$view->render('test5', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>Hey, this is a partial, also le-this</html>' . PHP_EOL);

		$view->start();
		$view->render('test9', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>Hey, this is a partial, also le-this<br />Hey, this is a second partial, also le-this</html>' . PHP_EOL);
	}

	public function testGetRender()
	{
		$view = new Phalcon\Mvc\View();

		$view->setViewsDir('unit-tests/views/');

		$content = $view->getRender('test5', 'index', array('cool_var' => 'le-this'));

		$this->assertEquals($content, '<html>Hey, this is a partial, also le-this</html>' . PHP_EOL);
	}*/

	protected function _getViewDisabled($level=null)
	{
		$view = new Phalcon\Mvc\View();

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
