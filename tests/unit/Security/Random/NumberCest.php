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

namespace Phalcon\Test\Unit\Security\Random;

use UnitTester;

/**
 * Class NumberCest
 */
class NumberCest
{
    /**
     * Tests Phalcon\Security\Random :: number()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomNumber(UnitTester $I)
    {
        $I->wantToTest("Security\Random - number()");
        $random = new \Phalcon\Security\Random;
        $I->expectException(\Exception::class, function () {
            $randNumber = $random->number();
        });

        $I->expectException(\Exception::class, function () {
            $randNumber = $random->number(-1);
        });

        $maxRand    = 1;
        $randNumber = $random->number($maxRand);

        $I->assertGreaterOrEquals(0, $randNumber);
        $I->assertLessOrEquals($maxRand, $randNumber);

        $maxRand    = 1000000000000000000;
        $randNumber = $random->number($maxRand);

        $I->assertGreaterOrEquals(0, $randNumber);
        $I->assertLessOrEquals($maxRand, $randNumber);

        $differentNumber = $random->number($maxRand);

        //Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($randNumber, $differentNumber);
    }
}
