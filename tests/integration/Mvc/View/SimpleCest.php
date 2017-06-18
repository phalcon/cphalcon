<?php

namespace Phalcon\Test\Integration\Mvc\View;

use Phalcon\Di;
use IntegrationTester;
use Phalcon\Mvc\View\Simple;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Output;

/**
 * \Phalcon\Test\Integration\Mvc\View\SimpleCest
 * Tests the Phalcon\Mvc\View\Simple component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Integration\Mvc\View
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class SimpleCest
{
    public function testSetVars(IntegrationTester $I)
    {
        $I->wantToTest('Set and get View vars');

        $view = new Simple;
        $view->setViewsDir(PATH_DATA . 'views/');

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
            throw new \PHPUnit_Framework_SkippedTestError(
                'Skipped in view of the experimental support for PHP 7.'
            );
        }

        // Create cache at first run
        $view = new Simple;
        codecept_debug(gettype($view->getParamsToView()));
        $view->setViewsDir(PATH_DATA . 'views/');

        // No cache before DI is set
        $I->assertFalse($view->getCache());

        $view->setDI($this->getDi());
        $I->assertEquals($view, $view->cache(['key' => 'view_simple_cache']));

        $cache = $view->getCache();
        $I->assertInstanceOf('Phalcon\Cache\BackendInterface', $cache);

        $timeNow = time();
        $view->setParamToView('a_cool_var', $timeNow);

        $I->assertEquals("<p>$timeNow</p>", rtrim($view->render('test3/coolVar')));

        $I->amInPath(PATH_CACHE);
        $I->seeFileFound('view_simple_cache');
        $I->seeInThisFile("<p>$timeNow</p>");

        unset($view, $cache);

        // Re-use the cached contents
        $view = new Simple;
        $view->setViewsDir(PATH_DATA . 'views/');
        $view->setDI($this->getDi());
        $view->cache(['key' => 'view_simple_cache']);

        $I->assertEmpty($view->getContent());
        $I->assertEquals("<p>$timeNow</p>", rtrim($view->render('test3/coolVar')));

        $I->assertNotEmpty($view->getContent());
        $I->assertEquals("<p></p>", rtrim($view->render('test3/coolVar')));

        $I->deleteFile('view_simple_cache');
    }

    /**
     * Setup viewCache service and DI
     * @return Di
     */
    protected function getDi()
    {
        $di = new Di;

        $di->set('viewCache', function () {
            return new File(new Output(['lifetime' => 2]), ['cacheDir' => PATH_CACHE]);
        });

        return $di;
    }
}
