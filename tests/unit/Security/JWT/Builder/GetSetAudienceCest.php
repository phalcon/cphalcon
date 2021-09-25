<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Security\JWT\Builder;

use Phalcon\Security\JWT\Builder;
use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class GetSetAudienceCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: getAudience()/setAudience()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTBuilderGetSetAudience(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - getAudience()/setAudience()');

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
    public function securityJWTBuilderSetAudienceException(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - setAudience() - exception');

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
