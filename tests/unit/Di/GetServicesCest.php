<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use UnitTester;

class GetServicesCest
{
    /**
     * Unit Tests Phalcon\Di :: getServices()
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diGetServices(UnitTester $I)
    {
        $I->wantToTest('Di - getServices()');

        $di = new Di();
        $I->assertEquals([], $di->getServices());

        $di->set('service', \stdClass::class);
        $I->assertCount(1, $di->getServices());

        $di->remove('service');
        $I->assertFalse($di->has('service'));
        $I->assertEquals([], $di->getServices());
    }
}
