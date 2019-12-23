<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Signer\Hmac;

use Phalcon\Http\JWT\Signer\Hmac;
use UnitTester;

class GetAlgHeaderCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Signer\Hmac :: getAlgHeader()
     *
     * @since  2019-12-19
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
