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

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\Exception\Exception;
use Phalcon\Encryption\Crypt\Exception\Mismatch;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetPaddingTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        $ciphers  = [
            'AES-256-CBC',
            'AES-256-CFB',
        ];
        $paddings = [
            Crypt::PADDING_ANSI_X_923,
            Crypt::PADDING_PKCS7,
            Crypt::PADDING_ISO_10126,
            Crypt::PADDING_ISO_IEC_7816_4,
            Crypt::PADDING_ZERO,
            Crypt::PADDING_SPACE,
        ];
        $signed   = [
            false,
            true,
        ];

        $result = [];
        foreach ($ciphers as $cipher) {
            foreach ($signed as $signedValue) {
                foreach ($paddings as $padding) {
                    $result[] = [
                        'cipher'  => $cipher,
                        'padding' => $padding,
                        'sign'    => $signedValue,
                    ];
                }
            }
        }

        return $result;
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptSetPadding(
        string $cipher,
        int $padding,
        bool $sign
    ): void {
        $texts = [
            '',
        ];

        $key = '0123456789ABCDEF0123456789ABCDEF';

        for ($i = 1; $i < 128; ++$i) {
            $texts[] = str_repeat('A', $i);
        }

        $crypt = new Crypt();
        $crypt
            ->setKey($key)
            ->useSigning($sign)
            ->setPadding($padding)
            ->setCipher($cipher)
        ;

        foreach ($texts as $source) {
            $encrypted = $crypt->encrypt($source);
            $expected  = $source;
            $actual    = $crypt->decrypt($encrypted);
            $this->assertSame($expected, $actual);
        }
    }
}
