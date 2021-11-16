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
use Phalcon\Encryption\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use UnitTester;

/**
 * Class GetSetAudienceCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class GetSetAudienceCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: getAudience()/setAudience()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: setAudience() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
