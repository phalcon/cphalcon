<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Security\JWT\Signer\None;

use Phalcon\Security\JWT\Signer\None;
use UnitTester;

class GetAlgHeaderCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Signer\None :: getAlgHeader()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTSignerNoneGetAlgHeader(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Signer\None - getAlgHeader()');

        $signer = new None();
        $I->assertEquals('none', $signer->getAlgHeader());
    }
}
