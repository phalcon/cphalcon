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

namespace Phalcon\Test\Unit\Security;

use UnitTester;
use Phalcon\Security;

/**
 * Class GetDefaultHashCest
 */
class GetSetDefaultHashCest
{
    /**
     * Tests Phalcon\Security :: getDefaultHash() and setDefaultHash()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityGetSetDefaultHash(UnitTester $I)
    {
        $I->wantToTest('Security - getDefaultHash()');

        $security = new Security();

        $expected = null;
        $actual   = $security->getDefaultHash();
        $I->assertEquals($expected, $actual);

        $expected = 16;
        $actual   = $security->getRandomBytes();
        $I->assertEquals($expected, $actual);

        $security->setDefaultHash(1);
        $expected = 1;
        $actual   = $security->getDefaultHash();
        $I->assertEquals($expected, $actual);

        $security->setRandomBytes(22);
        $expected = 22;
        $actual   = $security->getRandomBytes();
        $I->assertEquals($expected, $actual);
    }
}
