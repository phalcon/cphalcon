<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Builder;

use Phalcon\Encryption\Security\JWT\Builder;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Tests\AbstractUnitTestCase;

use function ksort;

final class GetHeadersTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTBuilderGetHeaders(): void
    {
        $signer  = new Hmac();
        $builder = new Builder($signer);

        $expected = [
            'alg' => $signer->getAlgHeader(),
            'typ' => 'JWT',
        ];
        $actual   = $builder->getHeaders();
        ksort($actual);
        $this->assertSame($expected, $actual);


        $builder = new Builder($signer);

        $builder
            ->addHeader('abc', 'custom header')
        ;

        $expected = [
            'abc' => 'custom header',
            'alg' => $signer->getAlgHeader(),
            'typ' => 'JWT',
        ];
        $actual   = $builder->getHeaders();
        ksort($actual);
        $this->assertSame($expected, $actual);
    }
}
