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
use Phalcon\Tests\Unit\Encryption\Fake\Crypt\FakeCrypt;

use function str_repeat;

final class DecryptTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptDecryptCryptUnpadZeroPaddingReturnsInput(): void
    {
        $crypt       = new FakeCrypt();
        $input       = str_repeat("A", 32);
        $mode        = "ccb";
        $blockSize   = 16;
        $paddingType = Crypt::PADDING_PKCS7;

        $expected = $input;
        $actual   = $crypt->cryptUnpadText($input, $mode, $blockSize, $paddingType);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptDecryptExceptionEmptyKey(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Decryption key cannot be empty');

        $crypt = new Crypt();
        $crypt->decrypt('sample text', '');
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13379
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptDecryptSignedKeyMismatchThrowsException(): void
    {
        $this->expectException(Mismatch::class);
        $this->expectExceptionMessage('Hash does not match.');

        $crypt = new Crypt();
        $crypt->decrypt(
            $crypt->encrypt('le text', 'encrypt key'),
            'wrong key'
        );
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13379
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptDecryptSignedString(): void
    {
        $crypt = new Crypt();

        $crypt->useSigning(true);
        $crypt->setKey('secret');

        $expected  = 'le text';
        $encrypted = $crypt->encrypt($expected);
        $actual    = $crypt->decrypt($encrypted);

        $this->assertSame($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13379
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptDecryptUnsignedKeyMismatchNoException(): void
    {
        $crypt = new Crypt();
        $crypt->useSigning(false);
        $actual = $crypt->decrypt(
            $crypt->encrypt('le text', 'encrypt key'),
            'wrong key'
        );

        $this->assertNotEmpty($actual);
    }
}
