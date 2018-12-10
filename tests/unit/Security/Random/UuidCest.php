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
 * Class UuidCest
 *
 * @package Phalcon\Test\Unit\Security\Random
 */
class UuidCest
{
    /**
     * Tests Phalcon\Security\Random :: uuid()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomUuid(UnitTester $I)
    {
        $I->wantToTest("Security\Random - uuid()");
        $I->skipTest("Need implementation");
    }
}
