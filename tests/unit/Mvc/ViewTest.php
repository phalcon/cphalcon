<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Helper\ViewTrait;
use Phalcon\Mvc\View;
use Phalcon\Events\Manager;
use Phalcon\Mvc\View\Exception;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;
use Phalcon\Mvc\View\Engine\Volt as VoltEngine;
use Phalcon\Test\Module\View\AfterRenderListener;
use Phalcon\Test\Module\View\Engine\Twig as TwigEngine;
use Phalcon\Test\Module\View\Engine\Mustache as MustacheEngine;

/**
 * \Phalcon\Test\Unit\Mvc\ViewTest
 * Tests the Phalcon\Mvc\View component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      https://www.phalconphp.com
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
    use ViewTrait;

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

                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
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
                    PATH_DATA . 'views' . DIRECTORY_SEPARATOR,
                    PATH_DATA . 'views2' . DIRECTORY_SEPARATOR,
                ]);

                expect($view->getActiveRenderPath())->equals(
                    [PATH_DATA . 'views' . DIRECTORY_SEPARATOR . 'test15' . DIRECTORY_SEPARATOR . 'index.phtml']
                );
            }
        );
    }

    /**
     * Tests the View::getCurrentRenderLevel
     *
     * @issue  907
     * @author Volodymyr Kolesnykov <volodymyr@wildwolf.name>
     * @since  2013-10-03
     */
    public function testGetCurrentRenderLevel()
    {
        $this->specify(
            'The View listener does not fetch current render level correctly',
            function () {
                $view = new View;

                $listener = new AfterRenderListener;
                $eventsManager = new Manager;
                $eventsManager->attach('view', $listener);

                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $view->setEventsManager($eventsManager);

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals("<html>lolhere</html>\n");
                expect($listener->getLevels())->equals('1,3,5');

                $listener->reset();
                $view->setTemplateAfter('test');

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals("<html>zuplolhere</html>\n");
                expect($listener->getLevels())->equals('1,3,4,5');

                $listener->reset();
                $view->cleanTemplateAfter();
                $view->setRenderLevel(View::LEVEL_MAIN_LAYOUT);

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals("<html>lolhere</html>\n");
                expect($listener->getLevels())->equals('1,3,5');

                $listener->reset();
                $view->setRenderLevel(View::LEVEL_LAYOUT);

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals('lolhere');
                expect($listener->getLevels())->equals('1,3');

                $listener->reset();
                $view->setRenderLevel(View::LEVEL_ACTION_VIEW);

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals('here');
                expect($listener->getLevels())->equals('1');

                $listener->reset();
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
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->registerEngines($expected);
                expect($view->getRegisteredEngines())->equals($expected);
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
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

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
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

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
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

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
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

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
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

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
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

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

    /**
     * Tests using partials with the mix Twig with PHP Engines
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-01-07
     */
    public function testOverrideLayout()
    {
        $this->specify(
            'Overriding the layout does not work as expected',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->start();
                $view->setLayout('test6');
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals("<html>Well, this is the view content: here.</html>\n");
            }
        );
    }

    /**
     * Test using different layout and pick
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2013-01-07
     */
    public function testLayoutAndPick()
    {
        $this->specify(
            'Using different layout and pick does not work as expected',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->start();
                $view->setLayout('test6');
                $view->pick('test3/other');
                $view->render('test3', 'another');
                $view->finish();

                expect($view->getContent())->equals("<html>Well, this is the view content: here.</html>\n");


                $view->start();
                $view->setLayout('test6');
                $view->pick(['test3/other']);
                $view->render('test3', 'another');
                $view->finish();

                expect($view->getContent())->equals("<html>Well, this is the view content: here.</html>\n");
            }
        );
    }

    /**
     * Tests render with missing partial
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMissingPartial()
    {
        $this->specify(
            'Using missing partial does not throw exception',
            function () {
                $view = new View;
                $view->setDI(Di::getDefault());
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->start();
                $view->render('test5', 'missing');
                $view->finish();
            }, ['throws' => [
                Exception::class,
                "View 'partials/missing' was not found in any of the views directory"
            ]]
        );
    }

    /**
     * Tests View::exists
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testExists()
    {
        $this->specify(
            'The View component does don detect views correctly',
            function () {
                $view = new View;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                expect($view->exists('test2/index'))->true();
                expect($view->exists('test3/other'))->true();
                expect($view->exists('does_not_exist'))->false();
            }
        );
    }

    /**
     * Tests View::render
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-03-05
     */
    public function testStandardRender()
    {
        $this->specify(
            'The View component does not work as expected',
            function () {
                $view = new View;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->start();
                $view->render('test2', 'index');
                $view->finish();

                expect($view->getContent())->equals("<html>We are here</html>\n");

                $view->start();
                $view->render('test3', 'other');
                $view->finish();
                expect($view->getContent())->equals("<html>lolhere</html>\n");

                $view->setParamToView('a_cool_var', 'le-this');

                $view->start();
                $view->render('test3', 'another');
                $view->finish();

                expect($view->getContent())->equals("<html>lol<p>le-this</p></html>\n");

                $view->setTemplateAfter('test');

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals("<html>zuplolhere</html>\n");

                $view->cleanTemplateAfter();

                $view->setRenderLevel(View::LEVEL_MAIN_LAYOUT);

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals("<html>lolhere</html>\n");

                $view->setRenderLevel(View::LEVEL_LAYOUT);

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals('lolhere');

                $view->setRenderLevel(View::LEVEL_ACTION_VIEW);

                $view->start();
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals('here');

                $view->setRenderLevel(View::LEVEL_MAIN_LAYOUT);
                $view->start();
                $view->pick('test3/yup');
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals("<html>lolyup</html>\n");

                $view->setRenderLevel(View::LEVEL_NO_RENDER);
                $view->start();
                $view->pick('test3/yup');
                $view->render('test3', 'other');
                $view->finish();

                expect($view->getContent())->equals('');
            }
        );
    }


    /**
     * Tests View::setMainView
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testOverrideMainView()
    {
        $this->specify(
            'The setting main view does not work as expected',
            function () {
                $view = new View;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->setMainView('html5');

                $view->start();
                $view->render('test2', 'index');
                $view->finish();

                expect($view->getContent())->equals("<!DOCTYPE html><html>We are here</html>\n");
            }
        );
    }

    /**
     * Tests rendering with partials
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-05-28
     */
    public function testRenderingWithPartials()
    {
        $this->specify(
            'The rendering with partials does not work as expected',
            function () {
                $view = new View;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $view->setParamToView('cool_var', 'le-this');

                $view->start();
                $view->render('test5', 'index');
                $view->finish();

                expect($view->getContent())->equals("<html>Hey, this is a partial, also le-this</html>\n");

                $view->start();
                $view->render('test9', 'index');
                $view->finish();

                expect($view->getContent())
                    ->equals("<html>Hey, this is a partial, also le-this<br />Hey, this is a second partial, also le-this</html>\n");

                $view->start();
                $view->render('test5', 'subpartial');
                $view->finish();

                expect($view->getContent())->equals("<html>Including Hey, this is a partial, also le-this</html>\n");

                $view->setMainView('html5');

                $view->start();
                $view->render('test5', 'index');
                $view->finish();

                expect($view->getContent())
                    ->equals("<!DOCTYPE html><html>Hey, this is a partial, also le-this</html>\n");
                expect($view->getPartial('partials/_partial1', ['cool_var' => 'le-this']))
                    ->equals('Hey, this is a partial, also le-this');
            }
        );
    }

    /**
     * Tests View::getRender
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-26-12
     */
    public function testGetRender()
    {
        $this->specify(
            'The rendering does not work as expected',
            function () {
                $view = new View;
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                expect($view->getRender('test5', 'index', ['cool_var' => 'le-this']))
                    ->equals("<html>Hey, this is a partial, also le-this</html>\n");
            }
        );
    }
}
