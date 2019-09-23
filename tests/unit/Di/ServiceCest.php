<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Escaper;
use UnitTester;

class ServiceCest
{
    /**
     * Tests resolving service
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-29
     */
    public function testResolvingService(UnitTester $I)
    {
        $di = new Di();

        $di->set(
            'resolved',
            function () {
                return new Escaper();
            }
        );

        $di->set(
            'notResolved',
            function () {
                return new Escaper();
            }
        );


        $I->assertFalse(
            $di->getService('resolved')->isResolved()
        );

        $I->assertFalse(
            $di->getService('notResolved')->isResolved()
        );


        $di->get('resolved');

        $I->assertTrue(
            $di->getService('resolved')->isResolved()
        );

        $I->assertFalse(
            $di->getService('notResolved')->isResolved()
        );
    }

    public function testAlias(UnitTester $I)
    {
        $escaper = new Escaper();

        $di = new Di();

        $di->set(
            'resolved',
            Escaper::class
        );

        $di->set(Escaper::class, $escaper);

        $I->assertSame(
            $escaper,
            $di->get('resolved')
        );
    }
}
