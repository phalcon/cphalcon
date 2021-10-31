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

namespace Phalcon\Tests\Unit\Encryption\Security\Random;

use Phalcon\Encryption\Security\Random;
use UnitTester;

/**
 * Class UuidCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\Random
 */
class UuidCest
{
    /**
     * Tests Phalcon\Encryption\Security\Random :: uuid()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityRandomUuid(UnitTester $I)
    {
        $I->wantToTest("Security\Random - uuid()");

        $random = new Random();


        $uuid = $random->uuid();

        // Test forbidden characters
        $I->assertRegExp(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{12}$/',
            $uuid
        );
    }

    /**
     * Tests Phalcon\Encryption\Security\Random :: uuid() produces different results
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityRandomUuidDifferentResults(UnitTester $I)
    {
        $I->wantToTest("Security\Random - uuid() produces different results");

        $random = new Random();

        $uuid1 = $random->uuid();
        $uuid2 = $random->uuid();

        // Buy lottery ticket if this fails (or fix the bug)
        $I->assertNotEquals($uuid1, $uuid2);
    }
}
