<?php

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\View\Engine\Php;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Exception;
use Phalcon\Mvc\View\Simple;
use Phalcon\Test\Fixtures\Mvc\View\Engine\Mustache;
use Phalcon\Test\Fixtures\Mvc\View\Engine\Twig;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use function dataFolder;

class SimpleCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiViewSimple();
    }

    /**
     * Tests render
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderStandard(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $expected = 'We are here';
        $actual   = $view->render('simple/index');
        $I->assertEquals($expected, $actual);

        $expected = 'We are here';
        $actual   = $view->getContent();
        $I->assertEquals($expected, $actual);
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
        $view->registerEngines(['.mhtml' => Volt::class]);

        $expected = 'Hello FooBar';
        $actual   = $view->render('mustache/index');
        $I->assertEquals($expected, $actual);

        $I->amInPath(dataFolder('fixtures/views/mustache'));
        $I->seeFileFound('index.mhtml.php');
        $I->safeDeleteFile('index.mhtml.php');
    }

    /**
     * Tests the Simple::getRegisteredEngines
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testGetRegisteredEngines(IntegrationTester $I)
    {
        $view     = $this->container->get('viewSimple');
        $expected = [
            '.mhtml' => Mustache::class,
            '.phtml' => Php::class,
            '.twig'  => Twig::class,
            '.volt'  => Volt::class,
        ];

        $view->registerEngines($expected);

        $actual = $view->getRegisteredEngines();
        $I->assertEquals($expected, $actual);
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
                    dataFolder()
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
                    dataFolder()
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
     * Tests render with variables
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderWithVariables(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $expected = 'here';
        $actual   = $view->render('currentrender/other');
        $I->assertEquals($expected, $actual);

        $view->setParamToView('a_cool_var', 'le-this');

        $expected = '<p>le-this</p>';
        $actual   = $view->render('currentrender/another');
        $I->assertEquals($expected, $actual);
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

        $expectedParams = ['cool_var' => 'FooBar'];

        $this->renderPartialBuffered($view, 'partials/_partial1', $expectedParams);
        expect($view->getContent())->equals('Hey, this is a partial, also FooBar');

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
        expect('bar')->equals($view->foo);

        expect($view)->equals($view->setVar('foo1', 'bar1'));
        expect('bar1')->equals($view->getVar('foo1'));

        $expectedVars = ['foo2' => 'bar2', 'foo3' => 'bar3'];
        expect($view)->equals($view->setVars($expectedVars));
        expect('bar2')->equals($view->foo2);
        expect('bar3')->equals($view->foo3);
        expect($view)->equals($view->setVars($expectedVars, false));

        expect($view)->equals($view->setParamToView('foo4', 'bar4'));

        $expectedParamsToView = ['foo2' => 'bar2', 'foo3' => 'bar3', 'foo4' => 'bar4'];
        expect($expectedParamsToView)->equals($view->getParamsToView());

        expect($view)->equals($view->setContent('<h1>hello</h1>'));
        expect('<h1>hello</h1>')->equals($view->getContent());

        $view->setViewsDir(dataFolder('views' . DIRECTORY_SEPARATOR));
        expect(dataFolder('views' . DIRECTORY_SEPARATOR))->equals($view->getViewsDir());

        $expectedCacheOptions = ['lifetime' => 86400, 'key' => 'simple-cache'];

        verify_not($view->getCacheOptions());
        expect($view)->equals($view->setCacheOptions($expectedCacheOptions));
        expect($expectedCacheOptions)->equals($view->getCacheOptions());
    }

    public function testSetVars(IntegrationTester $I)
    {
        $I->wantToTest('Set and get View vars');

        $view = new Simple();
        $view->setViewsDir(dataFolder('fixtures/views/'));

        $I->assertNull($view->getVar('some_var'));
        $some_var = time();
        $view->setParamToView('some_var', $some_var);


        $I->assertNull($view->getVar('another_var'));
        $another_var = uniqid();
        $view->setVar('another_var', $another_var);

        $I->assertEquals($some_var, $view->getVar('some_var'));
        $I->assertEquals($another_var, $view->getVar('another_var'));
    }

    public function testRenderWithCache(IntegrationTester $I)
    {
        $I->wantToTest('Render by using simple view with cache');

        if (PHP_MAJOR_VERSION == 7) {
            $I->skipTest(
                'Skipped in view of the experimental support for PHP 7.'
            );
        }

        // Create cache at first run
        $view = new Simple();
        codecept_debug(gettype($view->getParamsToView()));
        $view->setViewsDir(dataFolder('fixtures/views/'));

        // No cache before DI is set
        $I->assertFalse($view->getCache());

        $view->setDI($this->getDi());
        $I->assertEquals($view, $view->cache(['key' => 'view_simple_cache']));

        $cache = $view->getCache();
        $I->assertInstanceOf('Phalcon\Cache\BackendInterface', $cache);

        $timeNow = time();
        $view->setParamToView('a_cool_var', $timeNow);

        $I->assertEquals("<p>$timeNow</p>", rtrim($view->render('test3/coolVar')));

        $I->amInPath(cacheFolder());
        $I->seeFileFound('view_simple_cache');
        $I->seeInThisFile("<p>$timeNow</p>");

        unset($view, $cache);

        // Re-use the cached contents
        $view = new Simple;
        $view->setViewsDir(dataFolder('fixtures/views/'));
        $view->setDI($this->getDi());
        $view->cache(['key' => 'view_simple_cache']);

        $I->assertEmpty($view->getContent());
        $I->assertEquals("<p>$timeNow</p>", rtrim($view->render('test3/coolVar')));

        $I->assertNotEmpty($view->getContent());
        $I->assertEquals("<p></p>", rtrim($view->render('test3/coolVar')));

        $I->safeDeleteFile('view_simple_cache');
    }

    /**
     * Setup viewCache service and DI
     *
     * @return Di
     */
    protected function getDi()
    {
        $di = new Di;

        $di->set('viewCache', function () {
            return new File(new Output(['lifetime' => 2]), ['cacheDir' => cacheFolder()]);
        });

        return $di;
    }
}
