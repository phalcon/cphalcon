<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Phalcon\Mvc\Router;
use Phalcon\Http\Request;
use Phalcon\Mvc\Router\Route;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\RouterTest
 * Tests the Phalcon\Mvc\Router component
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
class RouterTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        Route::reset();
    }

    /**
     * Tests setting host name by using regexp
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-23
     */
    public function testHostnameRegexRouter()
    {
        $this->specify(
            'The Router::getControllerName does not return correct controller by using regexp in host name',
            function ($hostname, $expected) {
                $router = $this->getRouter();

                $router->add('/edit', [
                    'controller' => 'posts3',
                    'action' => 'edit3'
                ]);

                $router->add('/edit', [
                    'controller' => 'posts',
                    'action' => 'edit'
                ])->setHostname('([a-z]+).phalconphp.com');

                $router->add('/edit', [
                    'controller' => 'posts2',
                    'action' => 'edit2'
                ])->setHostname('mail.([a-z]+).com');

                $router->add('/edit', [
                    'controller' => 'posts4',
                    'action' => 'edit2'
                ])->setHostname('([a-z]+).([a-z]+).net');

                $_SERVER['HTTP_HOST'] = $hostname;
                $router->handle('/edit');
                expect($router->getControllerName())->equals($expected);
            }, ['examples' => [
                ['localhost',         'posts3'],
                ['my.phalconphp.com', 'posts' ],
                [null,                'posts3'],
                ['mail.example.com',  'posts2'],
                ['some-domain.com',   'posts3'],
                ['some.domain.net',   'posts4'],
            ]]
        );
    }

    /**
     * Tests setting host name by using regexp
     *
     * @issue  2573
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-26
     */
    public function testHostnameRegexRouterWithHostPort()
    {
        $this->specify(
            'The Router::getControllerName does not return correct controller by using regexp in host name',
            function ($hostname, $expected, $port) {
                $router = $this->getRouter();

                $router->add('/edit', [
                    'controller' => 'posts3',
                    'action' => 'edit3'
                ]);

                $router->add('/edit', [
                    'controller' => 'posts',
                    'action' => 'edit'
                ])->setHostname('([a-z]+).phalconphp.com');

                $router->add('/edit', [
                    'controller' => 'posts2',
                    'action' => 'edit2'
                ])->setHostname('mail.([a-z]+).com');

                $router->add('/edit', [
                    'controller' => 'posts4',
                    'action' => 'edit2'
                ])->setHostname('([a-z]+).([a-z]+).net');

                $_SERVER['HTTP_HOST'] = $hostname . ($port ? ':' . $port : '');
                $router->handle('/edit');
                expect($router->getControllerName())->equals($expected);
            }, ['examples' => [
                ['localhost',         'posts3', null],
                ['my.phalconphp.com', 'posts',  80 ],
                ['my.phalconphp.com', 'posts',  8080],
                [null,                'posts3', 8080],
                ['mail.example.com',  'posts2', 9090],
                ['some-domain.com',   'posts3', 9000],
                ['some.domain.net',   'posts4', 0],
            ]]
        );
    }

    protected function getRouter()
    {
        $router = new Router(false);

        $di = new Di;
        $di->set('request', function() {
            return new Request;
        });

        $router->setDI($di);

        return $router;
    }
}
