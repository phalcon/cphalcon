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

namespace Phalcon\Test\Unit\Crypt;

use Phalcon\Crypt;
use Phalcon\Crypt\Exception;
use UnitTester;

/**
 * Class DecryptCest
 */
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
        $I->wantToTest('Crypt - decrypt() not throwing Exception on key mismatch');
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
     * @author                   <k@yejune.com>
     * @since                    2018-05-16
     *
     * @expectedException        \Phalcon\Crypt\Mismatch
     * @expectedExceptionMessage Hash does not match.
     */
    public function shouldThrowExceptionIfHashMismatch(UnitTester $I)
    {
        $I->expectThrowable(
            Exception::class,
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

        $key = 'secret';
        $crypt->setKey($key);

        $expected  = 'le text';
        $encrypted = $crypt->encrypt($expected);
        $actual    = $crypt->decrypt($encrypted);

        $I->assertEquals($expected, $actual);
    }
}
