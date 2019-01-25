<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-29
     */
    public function testResolvingService(UnitTester $I)
    {
        $di = new Di();
        $di->set('resolved', function () {
            return new Escaper();
        });
        $di->set('notResolved', function () {
            return new Escaper();
        });

        $actual = $di->getService('resolved')->isResolved();
        $I->assertFalse($actual);
        $actual = $di->getService('notResolved')->isResolved();
        $I->assertFalse($actual);

        $di->get('resolved');

        $actual = $di->getService('resolved')->isResolved();
        $I->assertTrue($actual);
        $actual = $di->getService('notResolved')->isResolved();
        $I->assertFalse($actual);
    }
}
