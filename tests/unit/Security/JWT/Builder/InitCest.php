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
use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class InitCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Builder :: init()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTBuilderInit(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Builder - init()');

        $signer  = new Hmac();
        $builder = new Builder($signer);

        $builder->setSubject('abcdef');
        $I->assertEquals('abcdef', $builder->getSubject());

        $builder->init();

        $I->assertNull($builder->getSubject());
    }
}
