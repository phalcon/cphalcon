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

namespace Phalcon\Test\Unit\Security;

use Phalcon\Security;
use UnitTester;

class GetSetDefaultHashCest
{
    /**
     * Tests Phalcon\Security :: getDefaultHash() and setDefaultHash()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function securityGetSetDefaultHash(UnitTester $I)
    {
        $I->wantToTest('Security - getDefaultHash()');

        $security = new Security();


        $I->assertNull(
            $security->getDefaultHash()
        );


        $I->assertEquals(
            16,
            $security->getRandomBytes()
        );


        $security->setDefaultHash(1);

        $I->assertEquals(
            1,
            $security->getDefaultHash()
        );


        $security->setRandomBytes(22);

        $I->assertEquals(
            22,
            $security->getRandomBytes()
        );
    }
}
