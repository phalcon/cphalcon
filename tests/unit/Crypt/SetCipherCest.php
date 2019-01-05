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
 * Class SetCipherCest
 */
class SetCipherCest
{
    /**
     * Tests Phalcon\Crypt :: setCipher()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cryptSetCipher(UnitTester $I)
    {
        $I->wantToTest('Crypt - setCipher()');

        $cipher = "aes-256-cfb";
        $crypt  = new Crypt();
        $crypt->setCipher($cipher);
        $I->assertEquals($cipher, $crypt->getCipher());
    }

    /**
     * Tests the Crypt::setCipher
     *
     * @author                   Phalcon Team <team@phalconphp.com>
     * @since                    2018-05-06
     *
     * @expectedException        \Phalcon\Crypt\Exception
     * @expectedExceptionMessage The cipher algorithm "xxx-yyy-zzz" is not
     *                           supported on this system.
     */
    public function shouldThrowExceptionIfCipherIsUnknown(UnitTester $I)
    {
        $I->expectThrowable(
            Exception::class,
            function () {
                $crypt = new Crypt();
                $crypt->setCipher('xxx-yyy-zzz');
            }
        );
    }
}
