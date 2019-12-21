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

class OffsetExistsCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: offsetExists()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcMicroOffsetExists(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - offsetExists()');

        $micro = new Micro();

        $di = new Di();

        $micro->setDi($di);


        $I->assertFalse(
            isset($micro['fake'])
        );

        $I->assertTrue(
            isset($micro['application'])
        );

        $I->assertFalse(
            isset($micro['escaper'])
        );

        $I->assertFalse(
            isset($micro['dispatcher'])
        );


        $escaper = new Escaper();

        $micro->setService('escaper', $escaper);

        $I->assertTrue(
            isset($micro['escaper'])
        );


        $dispatcher = new Dispatcher();

        $micro['dispatcher'] = $dispatcher;

        $I->assertTrue(
            isset($micro['dispatcher'])
        );


        $router = new Router();

        $di->set('router', $router);

        $I->assertTrue(
            isset($micro['router'])
        );
    }
}
