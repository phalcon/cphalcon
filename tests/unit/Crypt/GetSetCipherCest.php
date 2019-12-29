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
use Phalcon\Crypt\Exception;
use UnitTester;

class GetSetCipherCest
{
    /**
     * Tests Phalcon\Crypt :: getCipher() / setCipher()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cryptGetSetCipher(UnitTester $I)
    {
        $I->wantToTest('Crypt - getCipher() / setCipher()');

        $cipher = 'aes-256-cfb';

        $crypt = new Crypt();

        $crypt->setCipher($cipher);

        $I->assertEquals(
            $cipher,
            $crypt->getCipher()
        );
    }

    /**
     * Tests the Crypt::setCipher
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-05-06
     */
    public function shouldThrowExceptionIfCipherIsUnknown(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception(
                'The cipher algorithm "xxx-yyy-zzz" is not supported on this system.'
            ),
            function () {
                $crypt = new Crypt();

                $crypt->setCipher('xxx-yyy-zzz');
            }
        );
    }
}
