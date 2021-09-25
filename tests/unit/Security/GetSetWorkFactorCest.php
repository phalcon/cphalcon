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

namespace Phalcon\Tests\Unit\Security;

use Phalcon\Security;
use UnitTester;

class GetSetWorkFactorCest
{
    /**
     * Tests Phalcon\Security :: setWorkFactor()/getWorkFactor()
     *
     * @author Ruud Boon
     * @since  2018-11-13
     */
    public function securityGetSetWorkFactor(UnitTester $I)
    {
        $I->wantToTest('Security - getWorkFactor()/setWorkFactor()');

        $security = new Security();


        $I->assertEquals(
            10,
            $security->getWorkFactor()
        );


        $expected = 31;

        $security->setWorkFactor($expected);

        $I->assertEquals(
            $expected,
            $security->getWorkFactor()
        );
    }
}
