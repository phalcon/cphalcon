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
 * Class GetSetIssuedAtCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class GetSetIssuedAtCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: getIssuedAt()/setIssuedAt()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTBuilderGetSetIssuedAt(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getIssuedAt()/setIssuedAt()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertNull($builder->getIssuedAt());

        $return = $builder->setIssuedAt(4);
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals(4, $builder->getIssuedAt());
    }
}
