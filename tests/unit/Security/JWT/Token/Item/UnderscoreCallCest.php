<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Security\JWT\Token\Item;

use Phalcon\Security\JWT\Token\Item;
use UnitTester;

class UnderscoreCallCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Token\Item :: __call()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTTokenItemUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Token\Item - __call()');

        $item = new Item(['sub' => 'subject'], 'encoded-string-here');

        $I->assertEquals('encoded-string-here', $item->getEncoded());
        $I->assertEquals(['sub' => 'subject'], $item->getPayload());
    }
}
