<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\Hmac;

use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use UnitTester;

/**
 * Class GetAlgHeaderCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\Hmac
 */
class GetAlgHeaderCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Signer\Hmac :: getAlgHeader()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTSignerHmacGetAlgHeader(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Signer\Hmac - getAlgHeader()');

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
