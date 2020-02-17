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

namespace Phalcon\Test\Unit\Crypt;

use Phalcon\Crypt;
use Phalcon\Crypt\MismatchException;
use UnitTester;

class DecryptCest
{
    /**
     * Tests decrypt without using HMAC
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     * @author <k@yejune.com>
     * @since  2018-05-16
     */
    public function shouldNotThrowExceptionIfKeyMismatch(UnitTester $I)
    {
        $I->wantToTest(
            'Crypt - decrypt() not throwing Exception on key mismatch'
        );

        $crypt = new Crypt();

        $actual = $crypt->decrypt(
            $crypt->encrypt('le text', 'encrypt key'),
            'wrong key'
        );

        $I->assertNotEmpty($actual);
    }

    /**
     * Tests decrypt using HMAC
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     * @author <k@yejune.com>
     * @since  2018-05-16
     */
    public function shouldThrowExceptionIfHashMismatch(UnitTester $I)
    {
        $I->expectThrowable(
            new MismatchException('Hash does not match.'),
            function () {
                $crypt = new Crypt();

                $crypt->useSigning(true);

                $crypt->decrypt(
                    $crypt->encrypt('le text', 'encrypt key'),
                    'wrong key'
                );
            }
        );
    }

    /**
     * Tests decrypt using HMAC
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13379
     * @author <k@yejune.com>
     * @since  2018-05-16
     */
    public function shouldDecryptSignedString(UnitTester $I)
    {
        $crypt = new Crypt();

        $crypt->useSigning(true);

        $crypt->setKey('secret');

        $expected  = 'le text';
        $encrypted = $crypt->encrypt($expected);
        $actual    = $crypt->decrypt($encrypted);

        $I->assertEquals($expected, $actual);
    }
}
