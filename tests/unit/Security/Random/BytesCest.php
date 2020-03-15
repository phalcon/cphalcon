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

namespace Phalcon\Test\Unit\Security\Random;

use Phalcon\Security\Random;
use UnitTester;

use function strlen;

class BytesCest
{
    /**
     * Tests Phalcon\Security\Random :: bytes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function securityRandomBytes(UnitTester $I)
    {
        $I->wantToTest("Security\Random - bytes()");

        $random = new Random();

        $bytes = $random->bytes();
        $I->assertEquals(16, strlen($bytes));

        $bytes = $random->bytes(32);
        $I->assertEquals(32, strlen($bytes));
    }
}
