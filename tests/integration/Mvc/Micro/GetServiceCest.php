<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Mvc\Micro;

use ErrorException;
use IntegrationTester;
use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Html\Escaper;
use Phalcon\Http\Request;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Router;

use function restore_error_handler;
use function set_error_handler;

class GetServiceCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: getService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-22
     */
    public function mvcMicroGetService(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - getService()');

        $micro     = new Micro();
        $container = new Di();
        $escaper   = new Escaper();
        $micro->setDi($container);
        $micro->setService('escaper', $escaper);

        $expected = $escaper;
        $actual   = $micro->getService('escaper');
        $I->assertSame($expected, $actual);

        $dispatcher = new Dispatcher();
        $micro['dispatcher'] = $dispatcher;

        $expected = $dispatcher;
        $actual   = $micro->getService('dispatcher');
        $I->assertSame($expected, $actual);

        $router = new Router();
        $container->set('router', $router);

        $expected = $router;
        $actual   = $micro->getService('router');
        $I->assertSame($expected, $actual);
    }
    /**
     * Tests after binding event
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-07-03
     */
    public function mvcMicroGetServiceWithProperty(IntegrationTester $I)
    {
        $container = new FactoryDefault();
        $micro     = new Micro($container);
        $error     = '';

        set_error_handler(
            function ($number, $message, $file, $line) {
                throw new ErrorException($message, 0, $number, $file, $line);
            }
        );

        try {
            $class   = Request::class;
            $request = $micro->request;
            $I->assertInstanceOf($class, $request);
        } catch (ErrorException $ex) {
            $error = $ex->getMessage();
        }

        restore_error_handler();

        $I->assertEmpty($error);
    }
}
