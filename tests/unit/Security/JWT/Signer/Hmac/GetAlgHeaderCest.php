<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Security\JWT\Signer\Hmac;

use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class GetAlgHeaderCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Signer\Hmac :: getAlgHeader()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTSignerHmacGetAlgHeader(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Signer\Hmac - getAlgHeader()');

        $signer = new Hmac();
        $I->assertEquals('HS512', $signer->getAlgHeader());

        $signer = new Hmac('sha512');
        $I->assertEquals('HS512', $signer->getAlgHeader());

        $signer = new Hmac('sha384');
        $I->assertEquals('HS384', $signer->getAlgHeader());

        $signer = new Hmac('sha256');
        $I->assertEquals('HS256', $signer->getAlgHeader());
    }
}
