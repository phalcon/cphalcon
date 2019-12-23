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
use Phalcon\Http\JWT\Exceptions\ValidatorException;
use Phalcon\Http\JWT\Signer\Hmac;
use UnitTester;

class GetSetExpirationTimeCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Builder ::
     * getExpirationTime()/setExpirationTime()
     *
     * @since  2019-12-15
     */
    public function httpJWTBuilderGetSetExpirationTime(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getExpirationTime()/setExpirationTime()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertNull($builder->getExpirationTime());

        $future = strtotime("now") + 1000;
        $return = $builder->setExpirationTime($future);
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals($future, $builder->getExpirationTime());
    }

    /**
     * Unit Tests Phalcon\Http\JWT\Builder ::
     * getExpirationTime()/setExpirationTime() - exception
     *
     * @since  2019-12-15
     */
    public function httpJWTBuilderGetSetExpirationTimeException(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getExpirationTime()/setExpirationTime() - exception');

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
