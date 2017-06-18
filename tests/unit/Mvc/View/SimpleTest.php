<?php

namespace Phalcon\Test\Unit\Mvc\View;

use Phalcon\Di;
use Helper\ViewTrait;
use Phalcon\Mvc\View\Simple;
use Phalcon\Mvc\View\Exception;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;
use Phalcon\Mvc\View\Engine\Volt as VoltEngine;
use Phalcon\Test\Module\View\Engine\Twig as TwigEngine;
use Phalcon\Test\Module\View\Engine\Mustache as MustacheEngine;

/**
 * \Phalcon\Test\Unit\Mvc\View\SimpleTest
 * Tests the Phalcon\Mvc\View\Simple component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\View
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class SimpleTest extends UnitTest
{
    use ViewTrait;

    /**
     * Tests render
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderStandard()
    {
        $this->specify(
            'The view rendering does not work as expected',
            function () {
                $view = new Simple;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                expect($view->render('test2/index'))->equals('We are here');
                expect($view->getContent())->equals('We are here');
            }
        );
    }

    /**
     * Tests the rendering with registered engine
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithRegisteredEngine()
    {
        $this->specify(
            'The rendering with registered engine does not work as expected',
            function () {
                $view = new Simple;

                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->setParamToView('name', 'FooBar');
                $view->registerEngines(['.mhtml' => VoltEngine::class]);

                expect($view->render('test4/index'))->equals('Hello FooBar');

                $this->tester->amInPath(PATH_DATA . 'views/test4');
                $this->tester->seeFileFound('index.mhtml.php');
                $this->tester->deleteFile('index.mhtml.php');
            }
        );
    }

    /**
     * Tests the rendering with registered engine
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithFilenameWithEngineExtension()
    {
        $this->specify(
            'The rendering with registered engine does not work as expected',
            function () {
                $view = new Simple;

                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->setParamToView('name', 'FooBar');
                $view->registerEngines(['.mhtml' => VoltEngine::class]);

                expect($view->render('test4/index.mhtml'))->equals('Hello FooBar');

                $this->tester->amInPath(PATH_DATA . 'views/test4');
                $this->tester->seeFileFound('index.mhtml.php');
                $this->tester->deleteFile('index.mhtml.php');
            }
        );
    }

    /**
     * Tests the Simple::getRegisteredEngines
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testGetRegisteredEngines()
    {
        $this->specify(
            'Unable to get all registered engines',
            function () {
                $expected = [
                    '.mhtml' => MustacheEngine::class,
                    '.phtml' => PhpEngine::class,
                    '.twig'  => TwigEngine::class,
                    '.volt'  => VoltEngine::class,
                ];

                $view = new Simple;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->registerEngines($expected);
                expect($view->getRegisteredEngines())->equals($expected);
            }
        );
    }

    /**
     * Tests render with missing view
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMissingView()
    {
        $this->specify(
            'The View component does not throw Exception in case of missing view',
            function () {
                $view = new Simple;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $view->render('test1/index');
            },
            [
                'throws' => [
                    Exception::class,
                    "View '" . PATH_DATA . 'views' . DIRECTORY_SEPARATOR . 'test1' . DIRECTORY_SEPARATOR . "index' was not found in the views directory"
                ]
            ]
        );
    }

    /**
     * Tests render with filename without registered
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithFilenameWithEngineWithoutEngineRegistered()
    {
        $this->specify(
            'Render with filename without registered engine does not throw Exception',
            function () {
                $view = new Simple;

                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->setParamToView('name', 'FooBar');

                $view->render('test4/index.mhtml');
            },
            [
                'throws' => [
                    Exception::class,
                    "View '" . PATH_DATA . 'views' . DIRECTORY_SEPARATOR . 'test4' . DIRECTORY_SEPARATOR . "index.mhtml' was not found in the views directory"
                ]
            ]
        );
    }

    /**
     * Tests render with variables
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithVariables()
    {
        $this->specify(
            'Render with variables does not work as expected',
            function () {
                $view = new Simple;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                expect($view->render('test3/other'))->equals('here');

                $view->setParamToView('a_cool_var', 'le-this');
                expect($view->render('test3/another'))->equals('<p>le-this</p>');
            }
        );
    }

    /**
     * Tests render with partials
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithPartials()
    {
        $this->specify(
            'Render with partials does not work as expected',
            function () {
                $view = new Simple;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $expectedParams= ['cool_var' => 'FooBar'];

                $this->renderPartialBuffered($view, 'partials/_partial1', $expectedParams);
                expect($view->getContent())->equals('Hey, this is a partial, also FooBar');

                $view->setVars($expectedParams);

                expect($view->render('test5/index'))->equals('Hey, this is a partial, also FooBar');
                expect($view->render('test9/index'))->equals('Hey, this is a partial, also FooBar<br />Hey, this is a second partial, also FooBar');
            }
        );
    }

    /**
     * Tests the View setters and getters
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testSettersAndGetters()
    {
        $this->specify(
            'The View setters and getters does not work as expected',
            function () {
                $view = new Simple;

                $view->foo = 'bar';
                expect('bar')->equals($view->foo);

                expect($view)->equals($view->setVar('foo1', 'bar1'));
                expect('bar1')->equals($view->getVar('foo1'));

                $expectedVars = array('foo2' => 'bar2', 'foo3' => 'bar3');
                expect($view)->equals($view->setVars($expectedVars));
                expect('bar2')->equals($view->foo2);
                expect('bar3')->equals($view->foo3);
                expect($view)->equals($view->setVars($expectedVars, false));

                expect($view)->equals($view->setParamToView('foo4', 'bar4'));

                $expectedParamsToView = ['foo2' => 'bar2', 'foo3' => 'bar3', 'foo4' => 'bar4'];
                expect($expectedParamsToView)->equals($view->getParamsToView());

                expect($view)->equals($view->setContent('<h1>hello</h1>'));
                expect('<h1>hello</h1>')->equals($view->getContent());

                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                expect(PATH_DATA . 'views' . DIRECTORY_SEPARATOR)->equals($view->getViewsDir());

                $expectedCacheOptions = ['lifetime' => 86400, 'key' => 'simple-cache'];

                verify_not($view->getCacheOptions());
                expect($view)->equals($view->setCacheOptions($expectedCacheOptions));
                expect($expectedCacheOptions)->equals($view->getCacheOptions());
            }
        );
    }
}
