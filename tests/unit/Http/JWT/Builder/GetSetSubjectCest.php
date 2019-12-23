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

class GetSetSubjectCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Builder :: getSubject()/setSubject()
     *
     * @since  2019-12-15
     */
    public function httpJWTBuilderGetSetSubject(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - getSubject()/setSubject()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $I->assertNull($builder->getSubject());

        $return = $builder->setSubject('subject');
        $I->assertInstanceOf(Builder::class, $return);

        $I->assertEquals('subject', $builder->getSubject());
    }
}
