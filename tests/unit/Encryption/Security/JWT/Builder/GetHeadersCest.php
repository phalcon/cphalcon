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
use UnitTester;

use function ksort;

/**
 * Class GetHeadersCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class GetHeadersCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: getHeaders()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function encryptionSecurityJWTBuilderGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security\JWT\Builder - getHeaders()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $expected = [
            'alg' => $signer->getAlgHeader(),
            'typ' => 'JWT',
        ];
        $actual = $builder->getHeaders();
        ksort($actual);
        $I->assertSame($expected, $actual);
    }
}
