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
 * Class GetSetExpirationTimeCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class GetSetExpirationTimeCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder ::
     * getExpirationTime()/setExpirationTime()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder ::
     * getExpirationTime()/setExpirationTime() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
