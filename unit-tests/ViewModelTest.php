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
  |          Piotr Gasiorowski <p.gasiorowski@vipserv.org>                 |
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\View as View,
	Phalcon\Mvc\View\Model as ViewModel;

class ViewModelTest extends PHPUnit_Framework_TestCase
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

	public function testBasic()
	{
		$di = new Phalcon\DI\FactoryDefault();
		$di['view'] = function() {
			$view = new View();
			$view->setBasePath(__DIR__.'/../')
				->setViewsDir('unit-tests/views/');
			return $view;
		};

		$viewmodel = new ViewModel();
		$viewmodel->label = 'phalcon';
		$viewmodel->setTemplate('model/model1');

		$this->assertEquals('phalcon', $viewmodel->label);

		$viewmodel1 = new ViewModel(array(
            'label'   => 'First child',
        ), 'model/model2');

		$viewmodel2 = new Phalcon\Mvc\View\Model([
            'label' => 'Second child',
        ], 'model/model2', 'child2');

		$viewmodel->addChild($viewmodel1, 'child1');
		$viewmodel->addChild($viewmodel2);

		$content = $viewmodel->render();
		$this->assertEquals($content, '<ul>phalcon<li>First child</li><li>Second child</li></ul>');

		$viewmodel3 = new Phalcon\Mvc\View\Model([
            'label' => 'append',
        ], 'model/model2', 'child1');

		$viewmodel->appendChild($viewmodel3);

		$content = $viewmodel->render();

		var_dump($viewmodel->child1);
		$this->assertEquals($content, '<ul>phalcon<li>First child</li><li>append</li><li>Second child</li></ul>');
	}
}
