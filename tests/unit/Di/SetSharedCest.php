<?php
declare(strict_types=1);

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
use UnitTester;

class SetSharedCest
{
    /**
     * Unit Tests Phalcon\Di :: setShared()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-13
     */
    public function diSetShared(UnitTester $I)
    {
        $I->wantToTest('Di - setShared()');

        $di = new Di();

        $di->setShared('escaper', Escaper::class);

        // check shared service
        $actual = $di->getService('escaper');
        $I->assertTrue($actual->isShared());

        $actual = $di->getShared('escaper');
        $I->assertInstanceOf(Escaper::class, $actual);
    }
}
