<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Codeception\Stub;
use Phalcon\Encryption\Crypt;
use UnitTester;

use function uniqid;

class IsValidDecryptLengthCest
{
    /**
     * Tests Phalcon\Encryption\Crypt :: isValidDecryptLength()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-09
     */
    public function encryptionCryptGetSetKey(UnitTester $I)
    {
        $I->wantToTest('Encryption\Crypt - isValidDecryptLength()');

        $crypt = new Crypt();
        $crypt->setKey('1234');

        $input     = uniqid();
        $encrypted = $crypt->encrypt($input);

        $actual = $crypt->isValidDecryptLength($encrypted);
        $I->assertTrue($actual);

        $actual = $crypt->isValidDecryptLength('text');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Encryption\Crypt :: isValidDecryptLength() - false length
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-09
     */
    public function encryptionCryptGetSetKeyFalseLength(UnitTester $I)
    {
        $I->wantToTest('Encryption\Crypt - isValidDecryptLength()');

        $crypt = Stub::make(
            Crypt::class,
            [
                'phpOpensslCipherIvLength' => false,
            ]
        );
        $crypt->setKey('1234');

        $actual = $crypt->isValidDecryptLength('text');
        $I->assertFalse($actual);
    }
}
