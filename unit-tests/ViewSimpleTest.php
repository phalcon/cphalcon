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

use Phalcon\Mvc\View\Simple as View;

class ViewSimpleTest extends PHPUnit_Framework_TestCase
{
	private $level;

	public function setUp()
	{
		$this->level = ob_get_level();
		if (is_dir('unit-tests/cache')) {
			foreach (new DirectoryIterator('unit-tests/cache/') as $item) {
				if ($item->isDir() || $item->isDot()) {
					continue;
				}

				unlink($item->getPathname());
			}
		} else {
			mkdir('unit-tests/cache');
		}
	}

    public function tearDown()
    {
        if (is_dir('unit-tests/cache')) {
            foreach (new DirectoryIterator('unit-tests/cache/') as $item) {
                if ($item->isDir() || $item->isDot()) {
                    continue;
                }

                unlink($item->getPathname());
            }
        } else {
            mkdir('unit-tests/cache');
        }

        while (ob_get_level() > $this->level) {
            ob_end_flush();
        }
    }

	public function testSettersAndGetters()
	{
		$view = new View();

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

		$view->setViewsDir('unit-tests/views/');
		$this->assertEquals('unit-tests/views/', $view->getViewsDir());

		$expectedCacheOptions = array("lifetime" => 86400, "key" => "simple-cache");
		$this->assertEmpty($view->getCacheOptions());
		$this->assertEquals($view, $view->setCacheOptions($expectedCacheOptions));
		$this->assertEquals($expectedCacheOptions, $view->getCacheOptions());
	}
}
