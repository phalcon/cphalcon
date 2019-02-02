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
        $random = new \Phalcon\Security\Random;
        $uuid   = $random->uuid();

        //test forbidden characters
        $I->assertRegExp("/^[a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{12}$/", $uuid);

        $differentUuid = $random->uuid();
        //Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($uuid, $differentUuid);
    }
}
