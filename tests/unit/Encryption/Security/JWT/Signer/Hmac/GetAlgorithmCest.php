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
 * Class GetAlgorithmCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\Hmac
 */
class GetAlgorithmCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Signer\Hmac :: getAlgorithm()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTSignerHmacGetAlgorithm(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Signer\Hmac - getAlgorithm()');

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
