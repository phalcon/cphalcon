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

/**
 * Class GetSetIssuerCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class GetSetIssuerCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: getIssuer()/setIssuer()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTBuilderGetSetIssuer(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getIssuer()/setIssuer()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertNull($builder->getIssuer());

        $return = $builder->setIssuer('issuer');
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals('issuer', $builder->getIssuer());
    }
}
