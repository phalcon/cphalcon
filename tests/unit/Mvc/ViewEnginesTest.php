<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Helper\ViewTrait;
use Phalcon\Mvc\View;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;

/**
 * Phalcon\Test\Unit\Mvc\ViewEnginesTest
 *
 * Test View engines
 *
 * @package Phalcon\Test\Unit\Mvc
 */
class ViewEnginesTest extends UnitTest
{
    use ViewTrait;

    /**
     * Tests View::render test template engines in function
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-29
     */
    public function shouldRenderVoltEngineBuiltInFunctions()
    {
        $this->specify(
            'Function setVar does not work as expected',
            function ($params, $expected) {
                $this->view->setDI(Di::getDefault());
                $this->view->setViewsDir(PATH_DATA . 'views/');
                $this->view->registerEngines($params['engines']);
                foreach ($params['setVar'] as $var) {
                    $this->view->setVar($var[0], $var[1]);
                }
                $this->view->start();
                $this->view->render($params['render'][0], $params['render'][1]);
                $this->view->finish();

                $this->assertEquals($this->view->getContent(), $expected);

                $this->silentRemoveFiles([
                        PATH_DATA . 'views/test11/index.volt.php',
                ]);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_built_in_function.php'
            ]
        );
    }

    /**
     * Tests the View::registerEngines
     *
     * @test
     * @issue  -
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function shouldRegisterEngines()
    {
        $this->specify(
            'Unable to get all registered engines',
            function ($engineSet) {
                $this->view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $this->view->registerEngines($engineSet);

                expect($this->view->getRegisteredEngines())->equals($engineSet);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_register_engines.php'
            ]
        );
    }

    /**
     * Tests the Different engines
     *
     * @test
     * @issue  -
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function shouldWorkEngine()
    {
        $this->specify(
            'The engine does not work as expected',
            function ($errorMessage, $engines, $params) {
                $this->view->setDI(Di::getDefault());
                $this->view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $this->view->registerEngines($engines);

                $this->setParamAndCheckData($errorMessage, $params, $this->view);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_set_single_engines.php'
            ]
        );
    }

    /**
     * Tests the mix Twig with PHP Engines
     *
     * @test
     * @issue  -
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function shouldWorkMixPhpTwigEngines()
    {
        $this->specify(
            'The engine does not work as expected',
            function ($errorMessage, $engines, $params) {
                $this->view->setDI(Di::getDefault());
                $this->view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $this->view->registerEngines($engines);

                $this->setParamAndCheckData($errorMessage, $params, $this->view);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_set_php_twig.php'
            ]
        );
    }

    /**
     * Tests the mix Mustache with PHP Engines
     *
     * @test
     * @issue  -
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function shouldWorkMixPhpMustacheEngines()
    {
        $this->specify(
            'The engine does not work as expected',
            function ($errorMessage, $engines, $params) {
                $this->view->setDI(Di::getDefault());
                $this->view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $this->view->registerEngines($engines);

                $this->setParamAndCheckData($errorMessage, $params, $this->view);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_set_php_mustache.php'
            ]
        );
    }

    /**
     * Tests the mix Mustache with PHP Engines
     *
     * @test
     * @issue  -
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function shouldWorkMixPhpMustacheEnginesPartial()
    {
        $this->specify(
            'The engine does not work as expected',
            function ($errorMessage, $engines, $params) {
                $this->view->setDI(Di::getDefault());
                $this->view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $this->view->registerEngines($engines);

                $this->setParamAndCheckData($errorMessage, $params, $this->view);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_set_php_mustache_partial.php'
            ]
        );
    }

    /**
     * Tests the mix Mustache with PHP Engines
     *
     * @test
     * @issue  -
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function shouldWorkMixPhpTwigEnginesPartial()
    {
        $this->specify(
            'The engine does not work as expected',
            function ($errorMessage, $engines, $params) {
                $this->view->setDI(Di::getDefault());
                $this->view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $this->view->registerEngines($engines);

                $this->setParamAndCheckData($errorMessage, $params, $this->view);
            },
            [
                'examples' => include PATH_FIXTURES . 'mvc/view_engines_test/view_set_php_twig_partial.php'
            ]
        );
    }
}
