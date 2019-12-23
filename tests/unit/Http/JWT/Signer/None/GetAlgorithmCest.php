<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Signer\None;

use Phalcon\Http\JWT\Signer\None;
use UnitTester;

class GetAlgorithmCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Signer\None :: getAlgorithm()
     *
     * @since  2019-12-22
     */
    public function httpJWTSignerNoneGetAlgorithm(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Signer\None - getAlgorithm()');

        $signer = new None();
        $I->assertEquals('None', $signer->getAlgorithm());
    }
}
