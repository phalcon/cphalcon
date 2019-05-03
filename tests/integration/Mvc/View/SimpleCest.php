<?php

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Exception;
use Phalcon\Mvc\View\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use function dataDir;

class SimpleCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiViewSimple();
    }

    /**
     * Tests the rendering with registered engine
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithRegisteredEngine(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $view->setParamToView('name', 'FooBar');

        $view->registerEngines(
            [
                '.mhtml' => Volt::class,
            ]
        );

        $I->assertEquals(
            'Hello FooBar',
            $view->render('mustache/index')
        );

        $I->amInPath(
            dataDir('fixtures/views/mustache')
        );

        $I->seeFileFound('index.mhtml.php');

        $I->safeDeleteFile('index.mhtml.php');
    }

    /**
     * Tests render with missing view
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMissingView(IntegrationTester $I)
    {
        $I->expectThrowable(
            new Exception(
                sprintf(
                    "View '%sfixtures/views/unknown/view' was not found in the views directory",
                    dataDir()
                )
            ),
            function () {
                $view = $this->container->get('viewSimple');

                $view->render('unknown/view');
            }
        );
    }

    /**
     * Tests render with filename without registered
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithFilenameWithEngineWithoutEngineRegistered(IntegrationTester $I)
    {
        $I->expectThrowable(
            new Exception(
                sprintf(
                    "View '%sfixtures/views/unknown/view' was not found in the views directory",
                    dataDir()
                )
            ),
            function () {
                $view = $this->container->get('viewSimple');

                $view->setParamToView('name', 'FooBar');

                $view->render('unknown/view');
            }
        );
    }

    /**
     * Tests render with partials
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithPartials(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check me');

        $view = $this->container->get('viewSimple');

        $expectedParams = [
            'cool_var' => 'FooBar',
        ];

        $this->renderPartialBuffered(
            $view,
            'partials/_partial1',
            $expectedParams
        );

        $I->assertEquals(
            'Hey, this is a partial, also FooBar',
            $view->getContent()
        );

        $view->setVars($expectedParams);

//        expect($view->render('test5/index'))->equals('Hey, this is a partial, also FooBar');
//        expect($view->render('test9/index'))->equals('Hey, this is a partial, also FooBar<br />Hey, this is a second partial, also FooBar');
    }

    /**
     * Tests the View setters and getters
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testSettersAndGetters(IntegrationTester $I)
    {
        $I->skipTest('TODO = Check me');

        $view = $this->container->get('viewSimple');

        $view->foo = 'bar';

        $I->assertEquals(
            'bar',
            $view->foo
        );

        $I->assertEquals(
            $view,
            $view->setVar('foo1', 'bar1')
        );

        $I->assertEquals(
            'bar1',
            $view->getVar('foo1')
        );

        $expectedVars = [
            'foo2' => 'bar2',
            'foo3' => 'bar3',
        ];

        $I->assertEquals(
            $view,
            $view->setVars($expectedVars)
        );

        $I->assertEquals(
            'bar2',
            $view->foo2
        );

        $I->assertEquals(
            'bar3',
            $view->foo3
        );

        $I->assertEquals(
            $view,
            $view->setVars($expectedVars, false)
        );

        $I->assertEquals(
            $view,
            $view->setParamToView('foo4', 'bar4')
        );

        $expectedParamsToView = [
            'foo2' => 'bar2',
            'foo3' => 'bar3',
            'foo4' => 'bar4',
        ];

        $I->assertEquals(
            $expectedParamsToView,
            $view->getParamsToView()
        );

        $I->assertEquals(
            $view,
            $view->setContent('<h1>hello</h1>')
        );

        $I->assertEquals(
            '<h1>hello</h1>',
            $view->getContent()
        );

        $view->setViewsDir(
            dataDir('views' . DIRECTORY_SEPARATOR)
        );

        $I->assertEquals(
            dataDir('views' . DIRECTORY_SEPARATOR),
            $view->getViewsDir()
        );

        $expectedCacheOptions = [
            'lifetime' => 86400,
            'key'      => 'simple-cache',
        ];

        verify_not($view->getCacheOptions());

        $I->assertEquals(
            $view,
            $view->setCacheOptions($expectedCacheOptions)
        );

        $I->assertEquals(
            $expectedCacheOptions,
            $view->getCacheOptions()
        );
    }

    public function testSetVars(IntegrationTester $I)
    {
        $I->wantToTest('Set and get View vars');

        $view = new Simple();

        $view->setViewsDir(
            dataDir('fixtures/views/')
        );

        $I->assertNull(
            $view->getVar('some_var')
        );

        $some_var = time();

        $view->setParamToView('some_var', $some_var);

        $I->assertNull(
            $view->getVar('another_var')
        );

        $another_var = uniqid();

        $view->setVar('another_var', $another_var);

        $I->assertEquals(
            $some_var,
            $view->getVar('some_var')
        );

        $I->assertEquals(
            $another_var,
            $view->getVar('another_var')
        );
    }
}
