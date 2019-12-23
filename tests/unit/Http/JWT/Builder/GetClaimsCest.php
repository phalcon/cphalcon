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

class GetClaimsCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Builder :: getClaims()
     *
     * @since  2019-12-22
     */
    public function httpJWTBuilderGetClaims(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getClaims()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertEmpty($builder->getClaims());
    }
}
