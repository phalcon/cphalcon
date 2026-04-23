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

final class GetAlgHeaderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTSignerHmacGetAlgHeader(): void
    {
        $signer   = new Hmac();
        $expected = 'HS512';
        $actual   = $signer->getAlgHeader();
        $this->assertSame($expected, $actual);

        $signer   = new Hmac('sha512');
        $expected = 'HS512';
        $actual   = $signer->getAlgHeader();
        $this->assertSame($expected, $actual);

        $signer   = new Hmac('sha384');
        $expected = 'HS384';
        $actual   = $signer->getAlgHeader();
        $this->assertSame($expected, $actual);

        $signer   = new Hmac('sha256');
        $expected = 'HS256';
        $actual   = $signer->getAlgHeader();
        $this->assertSame($expected, $actual);
    }
}
