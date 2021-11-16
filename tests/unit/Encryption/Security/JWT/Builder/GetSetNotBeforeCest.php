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
 * Class GetSetNotBeforeCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class GetSetNotBeforeCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: getNotBefore()/setNotBefore()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTBuilderGetSetNotBefore(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getNotBefore()/setNotBefore()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertNull($builder->getNotBefore());

        $return = $builder->setNotBefore(4);
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals(4, $builder->getNotBefore());
    }

    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: setNotBefore() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTBuilderSetNotBefore(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - setNotBefore() - exception');

        $I->expectThrowable(
            new ValidatorException(
                "Invalid Not Before"
            ),
            function () {
                $signer  = new Hmac();
                $builder = new Builder($signer);
                $future  = strtotime("now") + 1000;
                $return  = $builder->setNotBefore($future);
            }
        );
    }
}
