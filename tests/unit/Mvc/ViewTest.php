<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Helper\ViewTrait;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Exception;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Cache\Frontend\Output as FrontendCache;
use Phalcon\Cache\Backend\File as BackendCache;

/**
 * \Phalcon\Test\Unit\Mvc\ViewTest
 * Tests the Phalcon\Mvc\View component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ViewTest extends UnitTest
{
    use ViewTrait;

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
            },
            [
                'throws' => [
                    Exception::class,
                    "View 'partials/missing' was not found in any of the views directory"
                ]
            ]
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
     * Tests View::render with params
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-09-24
     * @issue  https://github.com/phalcon/cphalcon/issues/13046
     */
    public function shouldRenderWithParams()
    {
        $this->specify(
            "The View component doesn't render view with params",
            function () {
                $view = new View();
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                $view->start();
                $view->render('test2', 'params', ['name' => 'Sam', 'age' => 20]);
                $view->finish();

                expect($view->getContent())->equals("<html>My name is Sam and I am 20 years old</html>\n");
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

    public function testSettersAndGetters()
    {
        $this->specify(
            "View getters and setters don't work",
            function () {
                $view = new View();

                expect($view)->equals($view->setBasePath(PATH_DATA));

                $view->foo = "bar";
                expect("bar")->equals($view->foo);

                expect($view)->equals($view->setVar("foo1", "bar1"));
                expect("bar1")->equals($view->getVar("foo1"));

                $expectedVars = ["foo2" => "bar2", "foo3" => "bar3"];
                expect($view)->equals($view->setVars($expectedVars));
                expect("bar2")->equals($view->foo2);
                expect("bar3")->equals($view->foo3);
                expect($view)->equals($view->setVars($expectedVars, false));

                expect($view)->equals($view->setParamToView("foo4", "bar4"));

                $expectedParamsToView = ["foo2" => "bar2", "foo3" => "bar3", "foo4" => "bar4"];
                expect($expectedParamsToView)->equals($view->getParamsToView());

                expect($view)->equals($view->setContent("<h1>hello</h1>"));
                expect("<h1>hello</h1>")->equals($view->getContent());

                expect($view)->equals($view->setViewsDir("views/"));
                expect("views/")->equals($view->getViewsDir());

                expect($view)->equals($view->setLayoutsDir("views/layouts/"));
                expect("views/layouts/")->equals($view->getLayoutsDir());

                expect($view)->equals($view->setPartialsDir("views/partials/"));
                expect("views/partials/")->equals($view->getPartialsDir());

                expect($view)->equals($view->disableLevel(View::LEVEL_MAIN_LAYOUT));
                expect($view)->equals($view->setRenderLevel(View::LEVEL_ACTION_VIEW));
                expect(View::LEVEL_ACTION_VIEW)->equals($view->getRenderLevel());

                expect($view)->equals($view->setMainView("html5"));
                expect("html5")->equals($view->getMainView());

                expect($view)->equals($view->setLayout("test2"));
                expect("test2")->equals($view->getLayout());

                expect($view)->equals($view->setTemplateBefore("before"));
                expect($view)->equals($view->setTemplateAfter("after"));
                expect($view)->equals($view->cleanTemplateBefore());
                expect($view)->equals($view->cleanTemplateAfter());

                $view->start();
                $view->render("test2", "index");
                $view->finish();

                expect("test2")->equals($view->getControllerName());
                expect("index")->equals($view->getActionName());
            }
        );
    }

    /**
     * @covers \Phalcon\Mvc\View::__isset
     */
    public function testViewParamIsset()
    {
        $this->specify(
            "Setting View parameters doesn't work",
            function () {
                $view = new View();

                $view->setViewsDir(PATH_DATA . "views" . DIRECTORY_SEPARATOR);

                $view->set_param = "something";

                $content = $view->getRender("test16", "index");

                expect($content)->equals("<html>1</html>" . PHP_EOL);
            }
        );
    }

    public function testDisableLevels()
    {
        $this->specify(
            "Disabling view levels doesn't work as expected",
            function () {
                $view = $this->_getViewDisabled();

                expect($view->getContent())->equals('<html><div class="after-layout"><div class="controller-layout"><div class="before-layout"><div class="action">Action</div></div></div></div></html>' . PHP_EOL);

                $view = $this->_getViewDisabled(View::LEVEL_ACTION_VIEW);

                expect($view->getContent())->equals('<html><div class="after-layout"><div class="controller-layout"><div class="before-layout"></div></div></div></html>' . PHP_EOL);

                $view = $this->_getViewDisabled(View::LEVEL_BEFORE_TEMPLATE);

                expect($view->getContent())->equals('<html><div class="after-layout"><div class="controller-layout"><div class="action">Action</div></div></div></html>' . PHP_EOL);

                $view = $this->_getViewDisabled(View::LEVEL_LAYOUT);

                expect($view->getContent())->equals('<html><div class="after-layout"><div class="before-layout"><div class="action">Action</div></div></div></html>' . PHP_EOL);

                $view = $this->_getViewDisabled(View::LEVEL_AFTER_TEMPLATE);

                expect($view->getContent())->equals('<html><div class="controller-layout"><div class="before-layout"><div class="action">Action</div></div></div></html>' . PHP_EOL);

                $view = $this->_getViewDisabled(View::LEVEL_MAIN_LAYOUT);

                expect($view->getContent())->equals('<div class="after-layout"><div class="controller-layout"><div class="before-layout"><div class="action">Action</div></div></div></div>');

                $view = $this->_getViewDisabled(
                    [
                        View::LEVEL_BEFORE_TEMPLATE => true,
                        View::LEVEL_LAYOUT          => true,
                        View::LEVEL_AFTER_TEMPLATE  => true,
                        View::LEVEL_MAIN_LAYOUT     => true,
                    ]
                );

                expect($view->getContent())->equals('<div class="action">Action</div>');
            }
        );
    }

    protected function _getViewDisabled($level = null)
    {
        $view = new View();

        $view->setViewsDir(PATH_DATA . "views" . DIRECTORY_SEPARATOR);

        $view->setTemplateAfter("after");
        $view->setTemplateBefore("before");

        if ($level !== null) {
            $view->disableLevel($level);
        }

        $view->start();
        $view->render("test13", "index");
        $view->finish();

        return $view;
    }

    public function testCacheDI()
    {
        $this->specify(
            "Views are not cached properly",
            function () {
                $this->clearCache();

                $date = date("r");
                $content = '<html>' . $date . '</html>' . PHP_EOL;

                $di = $this->_getDi();
                $view = new View();
                $view->setDI($di);
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $view->setVar("date", $date);

                //First hit
                $view->start();
                $view->cache(true);
                $view->render('test8', 'index');
                $view->finish();
                expect($view->getContent())->equals($content);

                $view->reset();

                //Second hit
                $view->start();
                $view->cache(true);
                $view->render('test8', 'index');
                $view->finish();
                expect($view->getContent())->equals($content);

                $view->reset();

                sleep(1);

                $view->setVar("date", date("r"));

                //Third hit after 1 second
                $view->start();
                $view->cache(true);
                $view->render('test8', 'index');
                $view->finish();
                expect($view->getContent())->equals($content);

                $view->reset();

                //Four hit
                $view->start();
                $view->cache(true);
                $view->render('test8', 'index');
                $view->finish();
                expect($view->getContent())->equals($content);
            }
        );
    }

    public function testViewCacheIndependency()
    {
        $this->specify(
            "Views are not cached properly (2)",
            function () {
                $this->clearCache();

                $date = date("r");
                $content = '<html>'.$date.'</html>'.PHP_EOL;

                $di = $this->_getDi();
                $view = new View();
                $view->setDI($di);
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $view->setVar("date", $date);

                //First hit
                $view->start();
                $view->cache(true);
                $view->render('test8', 'index');
                $view->finish();
                expect($view->getContent())->equals($content);

                $di2 = $this->_getDi();
                $view2 = new View();
                $view2->setDI($di2);
                $view2->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                //Second hit
                $view2->start();
                $view2->cache(true);
                $view2->render('test8', 'index');
                $view2->finish();
                expect($view2->getContent())->equals($content);
            }
        );
    }

    public function testViewOptions()
    {
        $this->specify(
            "Views are not cached properly when passing options to the constructor",
            function () {
                $this->clearCache();

                $config = array(
                    'cache' => array(
                        'service' => 'otherCache',
                    )
                );
                $date = date("r");
                $content = '<html>'.$date.'</html>'.PHP_EOL;

                $di = $this->_getDi('otherCache');
                $view = new View($config);
                $view->setDI($di);
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $view->setVar("date", $date);

                $view->start();
                $view->cache(true);
                $view->render('test8', 'other');
                $view->finish();
                expect($view->getContent())->equals($content);

                $view->reset();

                sleep(1);

                $view->setVar("date", date("r"));

                $view->start();
                $view->cache(true);
                $view->render('test8', 'other');
                $view->finish();
                expect($view->getContent())->equals($content);
            }
        );
    }

    public function testCacheMethods()
    {
        $this->specify(
            "View methods don't return the View instance",
            function () {
                $di = $this->_getDi();
                $view = new View();
                $view->setDI($di);
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);

                expect($view->start())->equals($view);
                expect($view->cache(true))->equals($view);
                expect($view->render('test2', 'index'))->equals($view);
                expect($view->finish())->equals($view);
            }
        );
    }

    /**
     * Tests params view scope
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12648
     * @issue  https://github.com/phalcon/cphalcon/pull/13288
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-17
     */
    public function testIssue12648()
    {
        $this->specify(
            "View params are available in local scope",
            function () {
                $this->clearCache();
                $di = $this->_getDi();
                $view = new View();
                $view->setDI($di);
                $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
                $view->setParamToView('a_cool_var', 'test');

                $content = $view->setRenderLevel(View::LEVEL_ACTION_VIEW)->getRender('test3', 'another');
                expect($content)->equals("<html>lol<p>test</p></html>\n");
                try {
                    echo $a_cool_var;
                    $this->fail('Variable a_cool_var is defined and is set to "' . $a_cool_var . '"');
                } catch (\PHPUnit_Framework_Exception $e) {
                    expect($e->getMessage())->contains("Undefined variable: a_cool_var");
                }
            }
        );
    }

    private function _getDi($service = 'viewCache', $lifetime = 60)
    {
        $di = new Di();

        $frontendCache = new FrontendCache(
            array(
                'lifetime' => $lifetime
            )
        );

        $backendCache = new BackendCache(
            $frontendCache,
            array(
                'cacheDir' => PATH_CACHE
            )
        );

        $di->set($service, $backendCache);

        return $di;
    }
}
