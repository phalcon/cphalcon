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
 * Class SetPaddingCest
 */
class SetPaddingCest
{
    /**
     * Tests Phalcon\Crypt :: setPadding()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-17
     */
    public function cryptSetPadding(UnitTester $I)
    {
        $I->wantToTest('Crypt - setPadding()');
        $texts   = [''];
        $key     = '0123456789ABCDEF0123456789ABCDEF';
        $ciphers = [
            'AES-256-ECB',
            'AES-256-CBC',
            'AES-256-CFB',
        ];
        $pads    = [
            Crypt::PADDING_ANSI_X_923,
            Crypt::PADDING_PKCS7,
            Crypt::PADDING_ISO_10126,
            Crypt::PADDING_ISO_IEC_7816_4,
            Crypt::PADDING_ZERO,
            Crypt::PADDING_SPACE,
        ];

        for ($i = 1; $i < 128; ++$i) {
            $texts[] = str_repeat('A', $i);
        }

        $crypt = new Crypt();
        $crypt->setKey(substr($key, 0, 32));

        foreach ($pads as $padding) {
            $crypt->setPadding($padding);

            foreach ($ciphers as $cipher) {
                $crypt->setCipher($cipher);

                foreach ($texts as $expected) {
                    $encrypted = $crypt->encrypt($expected);
                    $actual    = $crypt->decrypt($encrypted);
                    $I->assertEquals($expected, $actual);
                }
            }
        }
    }
}
