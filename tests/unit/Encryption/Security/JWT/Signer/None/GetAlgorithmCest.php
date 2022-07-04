<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\None;

use Phalcon\Encryption\Security\JWT\Signer\None;
use UnitTester;

/**
 * Class GetAlgorithmCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\None
 */
class GetAlgorithmCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Signer\None :: getAlgorithm()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function encryptionSecurityJWTSignerNoneGetAlgorithm(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security\JWT\Signer\None - getAlgorithm()');

        $signer = new None();
        $I->assertSame('None', $signer->getAlgorithm());
    }
}
