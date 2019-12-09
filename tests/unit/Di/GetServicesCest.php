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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Escaper;
use UnitTester;

class GetServicesCest
{
    /**
     * Unit Tests Phalcon\Di :: getServices()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diGetServices(UnitTester $I)
    {
        $I->wantToTest('Di - getServices()');

        $di = new Di();

        $I->assertNull($di->getServices());

        $di->set('escaper', Escaper::class);

        $I->assertCount(1, $di->getServices());

        $di->remove('escaper');
        $I->assertFalse($di->has('escaper'));
        $I->assertEquals([], $di->getServices());
        $I->assertEmpty($di->getServices());
        $I->assertTrue(is_array($di->getServices()));
        $I->assertCount(0, $di->getServices());
    }
}
