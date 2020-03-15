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
use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class GetSetAudienceCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: getAudience()/setAudience()
     *
     * @since  2019-12-15
     */
    public function httpJWTBuilderGetSetAudience(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getAudience()/setAudience()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertNull($builder->getAudience());

        $return = $builder->setAudience('audience');
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals(['audience'], $builder->getAudience());

        $return = $builder->setAudience(['audience']);
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals(['audience'], $builder->getAudience());
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: setAudience() - exception
     *
     * @since  2019-12-15
     */
    public function httpJWTBuilderSetAudienceException(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - setAudience() - exception');

        $I->expectThrowable(
            new ValidatorException(
                "Invalid Audience"
            ),
            function () {
                $signer  = new Hmac();
                $builder = new Builder($signer);
                $return  = $builder->setAudience(1234);
            }
        );
    }
}
