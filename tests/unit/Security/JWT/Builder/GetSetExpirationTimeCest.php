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
use Phalcon\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class GetSetExpirationTimeCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder ::
     * getExpirationTime()/setExpirationTime()
     *
     * @since  2019-12-15
     */
    public function securityJWTBuilderGetSetExpirationTime(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - getExpirationTime()/setExpirationTime()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertNull($builder->getExpirationTime());

        $future = strtotime("now") + 1000;
        $return = $builder->setExpirationTime($future);
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals($future, $builder->getExpirationTime());
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Builder ::
     * getExpirationTime()/setExpirationTime() - exception
     *
     * @since  2019-12-15
     */
    public function securityJWTBuilderGetSetExpirationTimeException(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - getExpirationTime()/setExpirationTime() - exception');

        $I->expectThrowable(
            new ValidatorException(
                "Invalid Expiration Time"
            ),
            function () {
                $signer  = new Hmac();
                $builder = new Builder($signer);
                $return  = $builder->setExpirationTime(4);
            }
        );
    }
}
