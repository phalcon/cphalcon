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

class AddClaimCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: addClaim()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTBuilderAddClaim(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - addClaim()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertEmpty($builder->getClaims());

        $builder
            ->setId('this is an id')
            ->addClaim('username', 'Phalcon')
            ->addClaim('email', 'team@phalcon.io')
        ;

        $expected = [
            'email'    => 'team@phalcon.io',
            'jti'      => 'this is an id',
            'username' => 'Phalcon',
        ];
        $actual   = $builder->getClaims();
        $I->assertCount(3, $actual);
        $I->assertEquals($expected, $actual);
    }
}
