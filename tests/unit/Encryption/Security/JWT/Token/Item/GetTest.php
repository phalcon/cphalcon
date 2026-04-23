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
use Phalcon\Tests\AbstractUnitTestCase;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityJWTTokenItemGet(): void
    {
        $item = new Item(['sub' => 'subject'], 'encoded-string-here');

        $expected = 'subject';
        $actual   = $item->get('sub');
        $this->assertSame($expected, $actual);

        $expected = 'default';
        $actual   = $item->get('jti', 'default');
        $this->assertSame($expected, $actual);
    }
}
