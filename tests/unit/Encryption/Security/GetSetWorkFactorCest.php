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

namespace Phalcon\Tests\Unit\Encryption\Security;

use Phalcon\Encryption\Security;
use UnitTester;

class GetSetWorkFactorCest
{
    /**
     * Tests Phalcon\Security :: setWorkFactor()/getWorkFactor()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityGetSetWorkFactor(UnitTester $I)
    {
        $I->wantToTest('Security - getWorkFactor()/setWorkFactor()');

        $security = new Security();

        $I->assertEquals(10, $security->getWorkFactor());

        $expected = 31;
        $security->setWorkFactor($expected);

        $I->assertEquals($expected, $security->getWorkFactor());
    }
}
