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

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Router;

class GetServiceCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: getService()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcMicroGetService(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - getService()');

        $micro = new Micro();

        $di = new Di();

        $micro->setDi($di);


        $escaper = new Escaper();

        $micro->setService('escaper', $escaper);

        $I->assertSame(
            $escaper,
            $micro->getService('escaper')
        );


        $dispatcher = new Dispatcher();

        $micro['dispatcher'] = $dispatcher;

        $I->assertSame(
            $dispatcher,
            $micro->getService('dispatcher')
        );


        $router = new Router();

        $di->set('router', $router);

        $I->assertSame(
            $router,
            $micro->getService('router')
        );
    }
}
