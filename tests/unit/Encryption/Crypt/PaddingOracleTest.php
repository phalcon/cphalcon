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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class PaddingOracleTest extends AbstractUnitTestCase
{
    /**
     * A tampered CBC ciphertext must fail with a single generic error whether
     * the tamper breaks the PKCS7 padding or the HMAC, so it cannot be used as
     * a padding oracle (CWE-649).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testEncryptionCryptCbcTamperIsNotAPaddingOracle(): void
    {
        $crypt = new Crypt();
        $crypt->setCipher('aes-256-cbc');
        $crypt->setKey('0123456789abcdef0123456789abcdef');

        $encrypted = $crypt->encrypt('a secret message that spans blocks');

        // Flip the last ciphertext byte: this corrupts the final plaintext
        // block and reliably breaks the PKCS7 padding on decrypt.
        $tampered      = $encrypted;
        $tampered[-1]  = $tampered[-1] ^ "\xFF";

        // Must be the same generic error as a pure HMAC mismatch, not a
        // distinct padding-failure exception.
        $this->expectException(Mismatch::class);
        $crypt->decrypt($tampered);
    }
}
