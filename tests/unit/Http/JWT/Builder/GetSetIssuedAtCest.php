<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Builder;

use Phalcon\Http\JWT\Builder;
use Phalcon\Http\JWT\Signer\Hmac;
use UnitTester;

class GetSetIssuedAtCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Builder :: getIssuedAt()/setIssuedAt()
     *
     * @since  2019-12-15
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
