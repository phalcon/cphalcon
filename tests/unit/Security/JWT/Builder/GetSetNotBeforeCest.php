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

class GetSetNotBeforeCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: getNotBefore()/setNotBefore()
     *
     * @since  2019-12-15
     */
    public function securityJWTBuilderGetSetNotBefore(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - getNotBefore()/setNotBefore()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertNull($builder->getNotBefore());

        $return = $builder->setNotBefore(4);
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals(4, $builder->getNotBefore());
    }

    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: setNotBefore() - exception
     *
     * @since  2019-12-15
     */
    public function securityJWTBuilderSetNotBefore(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - setNotBefore() - exception');

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
