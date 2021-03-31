<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Security\JWT\Signer\Hmac;

use Phalcon\Security\JWT\Signer\Hmac;
use UnitTester;

class GetAlgorithmCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Signer\Hmac :: getAlgorithm()
     *
     * @since  2019-12-15
     */
    public function securityJWTSignerHmacGetAlgorithm(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Signer\Hmac - getAlgorithm()');

        $signer = new Hmac();
        $I->assertEquals('sha512', $signer->getAlgorithm());

        $signer = new Hmac('sha512');
        $I->assertEquals('sha512', $signer->getAlgorithm());

        $signer = new Hmac('sha384');
        $I->assertEquals('sha384', $signer->getAlgorithm());

        $signer = new Hmac('sha256');
        $I->assertEquals('sha256', $signer->getAlgorithm());
    }
}
