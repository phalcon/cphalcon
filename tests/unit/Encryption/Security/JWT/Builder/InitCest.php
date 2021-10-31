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
 * Class InitCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Builder
 */
class InitCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Builder :: init()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTBuilderInit(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Builder - init()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $builder->setSubject('abcdef');
        $I->assertEquals('abcdef', $builder->getSubject());

        $builder->init();

        $I->assertNull($builder->getSubject());
    }
}
