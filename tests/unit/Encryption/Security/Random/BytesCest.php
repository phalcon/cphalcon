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

use function strlen;

/**
 * Class BytesCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\Random
 */
class BytesCest
{
    /**
     * Tests Phalcon\Encryption\Security\Random :: bytes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function encryptionSecurityRandomBytes(UnitTester $I)
    {
        $I->wantToTest("Encryption\Security\Random - bytes()");

        $random = new Random();

        $bytes = $random->bytes();
        $I->assertSame(16, strlen($bytes));

        $bytes = $random->bytes(32);
        $I->assertSame(32, strlen($bytes));
    }
}
