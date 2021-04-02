<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Security\JWT\Builder;

use Phalcon\Security\JWT\Builder;
use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class GetHeadersCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: getHeaders()
     *
     * @since  2019-12-19
     */
    public function securityJWTBuilderGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - getHeaders()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $expected = [
            'alg' => $signer->getAlgHeader(),
            'typ' => 'JWT',
        ];
        $I->assertEquals($expected, $builder->getHeaders());
    }
}
