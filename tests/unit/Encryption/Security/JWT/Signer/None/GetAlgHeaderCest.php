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
 * Class GetAlgHeaderCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Signer\None
 */
class GetAlgHeaderCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Signer\None :: getAlgHeader()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTSignerNoneGetAlgHeader(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Signer\None - getAlgHeader()');

        $signer = new None();
        $I->assertEquals('none', $signer->getAlgHeader());
    }
}
