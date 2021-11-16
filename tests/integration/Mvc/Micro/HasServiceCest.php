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

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Html\Escaper;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Router;

class HasServiceCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: hasService()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcMicroHasService(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - hasService()');

        $micro = new Micro();

        $di = new Di();

        $micro->setDi($di);


        $I->assertFalse(
            $micro->hasService('fake')
        );

        $I->assertTrue(
            $micro->hasService('application')
        );

        $I->assertFalse(
            $micro->hasService('escaper')
        );

        $I->assertFalse(
            $micro->hasService('dispatcher')
        );


        $escaper = new Escaper();

        $micro->setService('escaper', $escaper);

        $I->assertTrue(
            $micro->hasService('escaper')
        );


        $dispatcher = new Dispatcher();

        $micro['dispatcher'] = $dispatcher;

        $I->assertTrue(
            $micro->hasService('dispatcher')
        );


        $router = new Router();

        $di->set('router', $router);

        $I->assertTrue(
            $micro->hasService('router')
        );
    }
}
