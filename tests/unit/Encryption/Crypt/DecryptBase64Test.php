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
use Phalcon\Encryption\Crypt\Exception\Mismatch;
use Phalcon\Tests\AbstractUnitTestCase;

final class DecryptBase64Test extends AbstractUnitTestCase
{
    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13379
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptDecryptBase64DecryptSignedString(): void
    {
        $crypt = new Crypt();
        $crypt
            ->useSigning(true)
            ->setKey('secret')
        ;

        $expected  = 'le text';
        $encrypted = $crypt->encryptBase64($expected);
        $actual    = $crypt->decryptBase64($encrypted);

        $this->assertSame($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13379
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptDecryptBase64SignedKeyMismatchThrowsException(): void
    {
        $this->expectException(Mismatch::class);
        $this->expectExceptionMessage('Hash does not match.');

        $crypt = new Crypt();
        $crypt->decryptBase64(
            $crypt->encryptBase64('le text', 'encrypt key'),
            'wrong key'
        );
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13379
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptDecryptBase64UnsignedKeyMismatchNoException(): void
    {
        $crypt = new Crypt();
        $crypt->useSigning(false);
        $actual = $crypt->decryptBase64(
            $crypt->encryptBase64('le text', 'encrypt key'),
            'wrong key'
        );

        $this->assertNotEmpty($actual);
    }
}
