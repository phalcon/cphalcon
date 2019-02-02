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
use UnitTester;

/**
 * Class EncryptCest
 */
class EncryptCest
{
    /**
     * Tests Phalcon\Crypt :: encrypt()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cryptEncrypt(UnitTester $I)
    {
        $I->wantToTest('Crypt - encrypt()');
        $tests   = [
            md5(uniqid())            => str_repeat('x', mt_rand(1, 255)),
            time() . time()          => str_shuffle('abcdefeghijklmnopqrst'),
            'le$ki12432543543543543' => "",
        ];
        $ciphers = [
            'AES-128-ECB',
            'AES-128-CBC',
            'AES-128-CFB',
            'AES-128-OFB',
            'AES128',
        ];

        $crypt = new Crypt();
        foreach ($ciphers as $cipher) {
            $crypt->setCipher($cipher);

            foreach ($tests as $key => $test) {
                $crypt->setKey(substr($key, 0, 16));
                $encryption = $crypt->encrypt($test);
                $actual     = rtrim($crypt->decrypt($encryption), "\0");
                $I->assertEquals($test, $actual);
            }

            foreach ($tests as $key => $test) {
                $encryption = $crypt->encrypt($test, substr($key, 0, 16));
                $actual     = rtrim($crypt->decrypt($encryption, substr($key, 0, 16)), "\0");
                $I->assertEquals($test, $actual);
            }
        }
    }
}
