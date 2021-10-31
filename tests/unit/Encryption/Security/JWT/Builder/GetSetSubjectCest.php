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
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use UnitTester;

/**
 * Class GetSetSubjectCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class GetSetSubjectCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: getSubject()/setSubject()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
