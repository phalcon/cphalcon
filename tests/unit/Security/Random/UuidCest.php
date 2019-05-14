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

class UuidCest
{
    /**
     * Tests Phalcon\Security\Random :: uuid()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomUuid(UnitTester $I)
    {
        $I->wantToTest("Security\Random - uuid()");

        $random = new \Phalcon\Security\Random();



        $uuid = $random->uuid();

        // Test forbidden characters
        $I->assertRegExp(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{12}$/',
            $uuid
        );
    }

    /**
     * Tests Phalcon\Security\Random :: uuid() produces different results
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityRandomUuidDifferentResults(UnitTester $I)
    {
        $I->wantToTest("Security\Random - uuid() produces different results");

        $random = new \Phalcon\Security\Random();

        $uuid1 = $random->uuid();
        $uuid2 = $random->uuid();

        // Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($uuid1, $uuid2);
    }
}
