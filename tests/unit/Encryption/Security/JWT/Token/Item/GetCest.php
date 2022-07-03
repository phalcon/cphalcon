<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Item;

use Phalcon\Encryption\Security\JWT\Token\Item;
use UnitTester;

/**
 * Class GetCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Item
 */
class GetCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Item :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function encryptionSecurityJWTTokenItemGet(UnitTester $I)
    {
        $I->wantToTest('Encryption\Security\JWT\Token\Item - get()');

        $item = new Item(['sub' => 'subject'], 'encoded-string-here');

        $I->assertSame('subject', $item->get('sub'));
        $I->assertSame('default', $item->get('jti', 'default'));
    }
}
