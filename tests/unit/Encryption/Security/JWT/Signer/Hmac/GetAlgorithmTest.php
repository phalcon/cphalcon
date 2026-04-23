<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\Hmac;

use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetAlgorithmTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTSignerHmacGetAlgorithm(): void
    {
        $signer   = new Hmac();
        $expected = 'sha512';
        $actual   = $signer->getAlgorithm();
        $this->assertSame($expected, $actual);

        $signer   = new Hmac('sha512');
        $expected = 'sha512';
        $actual   = $signer->getAlgorithm();
        $this->assertSame($expected, $actual);

        $signer   = new Hmac('sha384');
        $expected = 'sha384';
        $actual   = $signer->getAlgorithm();
        $this->assertSame($expected, $actual);

        $signer   = new Hmac('sha256');
        $expected = 'sha256';
        $actual   = $signer->getAlgorithm();
        $this->assertSame($expected, $actual);
    }
}
