<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Builder;

use Phalcon\Security\JWT\Builder;
use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class ConstructCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: __construct()
     *
     * @since  2019-12-19
     */
    public function httpJWTBuilderConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - __construct()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertInstanceOf(Builder::class, $builder);
    }
}
