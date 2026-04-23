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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Encryption\Fake\Crypt\FakeCrypt;
use Phalcon\Tests\Unit\Encryption\Fake\Crypt\FakeCryptOpensslRandomPseudoBytes;

use function str_repeat;
use function substr;

final class EncryptTest extends AbstractUnitTestCase
{
    public static function getExceptionCiphers(): array
    {
        return [
            ['aes-128-gcm'],
            ['aes-128-ccm'],
            ['aes-256-gcm'],
            ['aes-256-ccm'],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncrypt(): void
    {
        $tests = [
            md5(uniqid())            => str_repeat('x', mt_rand(1, 255)),
            time() . time()          => str_shuffle('abcdefeghijklmnopqrst'),
            'le$ki12432543543543543' => '',
        ];

        $ciphers = [
            'AES-128-CBC',
            'AES-128-CFB',
            'AES-128-OFB',
            'AES128',
        ];

        $crypt = new Crypt();

        foreach ($ciphers as $cipher) {
            $crypt->setCipher($cipher);

            foreach ($tests as $key => $test) {
                $crypt->setKey(
                    substr($key, 0, 16)
                );

                $encryption = $crypt->encrypt($test);

                $actual = rtrim(
                    $crypt->decrypt($encryption),
                    "\0"
                );

                $this->assertSame($test, $actual);
            }

            foreach ($tests as $key => $test) {
                $encryption = $crypt->encrypt(
                    $test,
                    substr($key, 0, 16)
                );

                $actual = rtrim(
                    $crypt->decrypt(
                        $encryption,
                        substr($key, 0, 16)
                    ),
                    "\0"
                );

                $this->assertSame($test, $actual);
            }
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptCannotCalculateRandomPseudoBytes(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Cannot calculate Random Pseudo Bytes");

        $crypt = new FakeCryptOpensslRandomPseudoBytes();

        $crypt->encrypt('test', '1234');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptCryptPadExceptionInvalidPaddingSizeMax(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Padding size cannot be less than 0 or greater than 256"
        );

        $crypt       = new FakeCrypt();
        $input       = str_repeat("A", 4096);
        $mode        = "cbc";
        $blockSize   = 1024;
        $paddingType = Crypt::PADDING_PKCS7;

        $crypt->cryptPadText($input, $mode, $blockSize, $paddingType);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptCryptPadExceptionInvalidPaddingSizeMin(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Padding size cannot be less than 0 or greater than 256"
        );

        $crypt       = new FakeCrypt();
        $input       = str_repeat("A", 4096);
        $mode        = "cbc";
        $blockSize   = -1024;
        $paddingType = Crypt::PADDING_PKCS7;

        $crypt->cryptPadText($input, $mode, $blockSize, $paddingType);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptCryptPadZeroPaddingReturnsInput(): void
    {
        $crypt       = new FakeCrypt();
        $input       = str_repeat("A", 32);
        $mode        = "ccb";
        $blockSize   = 16;
        $paddingType = Crypt::PADDING_PKCS7;

        $expected = $input;
        $actual   = $crypt->cryptPadText($input, $mode, $blockSize, $paddingType);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptExceptionEmptyKey(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Encryption key cannot be empty');

        $crypt = new Crypt();
        $crypt->encrypt('sample text', '');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptExceptionUnsupportedAlgo(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "The cipher algorithm 'AES-128' is not supported on this system."
        );

        $crypt = new Crypt();
        $crypt->setCipher('AES-128');
    }

    /**
     * @dataProvider getExceptionCiphers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptGcmCcmExceptionWithoutData(
        string $cipher
    ): void {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Auth data must be provided when using AEAD mode"
        );

        $crypt = new Crypt();
        $crypt
            ->setCipher($cipher)
            ->setKey('123456')
        ;

        $crypt->encrypt('phalcon');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptGcmCcmWithData(): void
    {
        $ciphers = [
            'aes-128-gcm',
            'aes-128-ccm',
            'aes-256-gcm',
            'aes-256-ccm',
        ];


        foreach ($ciphers as $cipher) {
            $crypt = new Crypt();
            $crypt
                ->setCipher($cipher)
                ->setKey('123456')
                ->setAuthTag('1234')
                ->setAuthData('abcd')
            ;

            $encryption = $crypt->encrypt('phalcon');

            $crypt = new Crypt();
            $crypt
                ->setCipher($cipher)
                ->setKey('123456')
                ->setAuthData('abcd')
            ;

            $expected = 'phalcon';
            $actual   = $crypt->decrypt($encryption);
            $this->assertSame($expected, $actual);
        }
    }
}
