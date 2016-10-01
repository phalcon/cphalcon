<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Phalcon\Mvc\View;
use Phalcon\Events\Manager;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\View\Engine\Volt as VoltEngine;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;
use Phalcon\Test\Module\View\AfterRenderListener;
use Phalcon\Test\Module\View\Engine\Twig as TwigEngine;
use Phalcon\Test\Module\View\Engine\Mustache as MustacheEngine;

/**
 * \Phalcon\Test\Unit\Mvc\ViewTest
 * Tests the Phalcon\Mvc\View component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ViewTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        $di = $this->tester->getApplication()->getDI();

        Di::setDefault($di);
    }

    /**
     * Tests the View::getActiveRenderPath
     *
     * @issue  12139
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2014-08-14
     */
    public function testGetActiveRenderPath()
    {
        $this->specify(
            'The View::getActiveRenderPath returns unexpected result',
            function () {
                $view = new View;

                $eventsManager = new Manager;
                $eventsManager->attach('view', new AfterRenderListener);

                $view->setViewsDir(PATH_DATA . 'views');
                $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
                $view->setEventsManager($eventsManager);

                expect($view->getActiveRenderPath())->equals('');

                $view->start();
                $view->render('test15', 'index');
                $view->finish();

                $view->getContent();

                expect($view->getActiveRenderPath())->equals(
                    PATH_DATA . 'views' . DIRECTORY_SEPARATOR . 'test15' . DIRECTORY_SEPARATOR . 'index.phtml'
                );

                $view->setViewsDir([
                    PATH_DATA . 'views',
                    PATH_DATA . 'views2',
                ]);

                expect($view->getActiveRenderPath())->equals(
                    [PATH_DATA . 'views' . DIRECTORY_SEPARATOR . 'test15' . DIRECTORY_SEPARATOR . 'index.phtml']
                );
            }
        );
    }

    /**
     * Tests the View::getRegisteredEngines
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

                $view = new View;
                $view->setViewsDir(PATH_DATA . 'views');

                $view->registerEngines($expected);
                expect($expected)->equals($view->getRegisteredEngines());
            }
        );
    }

    /**
     * Tests the Mustache Engine
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function testMustacheEngine()
    {
        $this->specify(
            'The Mustache Engine does not work as expected',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views');

                $view->registerEngines(['.mhtml' => MustacheEngine::class]);

                $view->setParamToView('name', 'Sonny');

                $view->start();
                $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
                $view->render('test4', 'index');
                $view->finish();

                expect($view->getContent())->equals('Hello Sonny');

                $view->setParamToView('some_eval', true);

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test4', 'index');
                $view->finish();

                expect($view->getContent())->equals("Well, this is the view content: Hello Sonny.\n");
            }
        );
    }

    /**
     * Tests the Twig Engine
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function testTwigEngine()
    {
        $this->specify(
            'The Twig Engine does not work as expected',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views');

                $view->registerEngines(['.twig' => TwigEngine::class]);

                $view->setParamToView('song', 'Rock n roll');

                $view->start();
                $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
                $view->render('test7', 'index');
                $view->finish();

                expect($view->getContent())->equals('Hello Rock n roll!');

                $view->setParamToView('some_eval', true);

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test7', 'index');
                $view->finish();

                expect($view->getContent())->equals("Clearly, the song is: Hello Rock n roll!.\n");
            }
        );
    }

    /**
     * Tests the mix Mustache with PHP Engines
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function testMustacheMixedEngine()
    {
        $this->specify(
            'The Mustache Engine does not work as expected',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views');

                $view->registerEngines([
                    '.mhtml' => MustacheEngine::class,
                    '.phtml' => PhpEngine::class,
                ]);

                $view->setParamToView('name', 'Sonny');

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test6', 'index');
                $view->finish();

                expect($view->getContent())->equals('Well, this is the view content: Hello Sonny.');
            }
        );
    }

    /**
     * Tests the mix Twig with PHP Engines
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function testTwigMixedEngine()
    {
        $this->specify(
            'The Twig Engine does not work as expected',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views');

                $view->registerEngines([
                    '.twig' => TwigEngine::class,
                    '.phtml' => PhpEngine::class,
                ]);

                $view->setParamToView('name', 'Sonny');

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test12', 'index');
                $view->finish();

                expect($view->getContent())->equals('Well, this is the view content: Hello Sonny.');
            }
        );
    }

    /**
     * Tests using partials with the mix Mustache with PHP Engines
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function testMustacheMixedEnginePartials()
    {
        $this->specify(
            'The Mustache Engine does not work as expected',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views');

                $view->registerEngines([
                    '.mhtml' => MustacheEngine::class,
                    '.phtml' => PhpEngine::class,
                ]);

                $view->setParamToView('name', 'Sonny');

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test6', 'info');
                $view->finish();

                expect($view->getContent())->equals('Well, this is the view content: Hello Sonny.');
            }
        );
    }

    /**
     * Tests using partials with the mix Twig with PHP Engines
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-17
     */
    public function testTwigMixedEnginePartials()
    {
        $this->specify(
            'The Twig Engine does not work as expected',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views');

                $view->registerEngines([
                    '.twig' => TwigEngine::class,
                    '.phtml' => PhpEngine::class,
                ]);

                $view->setParamToView('name', 'Sonny');

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test12', 'info');
                $view->finish();

                expect($view->getContent())->equals('Well, this is the view content: Hello Sonny.');
            }
        );
    }
}
