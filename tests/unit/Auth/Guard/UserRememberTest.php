<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Guard;

use Phalcon\Auth\Guard\UserRemember;
use Phalcon\Tests\AbstractUnitTestCase;

final class UserRememberTest extends AbstractUnitTestCase
{
    public function testJsonStringDecodingToNonArrayDegradesGracefully(): void
    {
        $remember = new UserRemember('"just a string"');

        $this->assertNull($remember->getId());
        $this->assertSame('', $remember->getToken());
    }

    public function testMalformedJsonStringDegradesToEmptyPayload(): void
    {
        $remember = new UserRemember('not json');

        $this->assertNull($remember->getId());
        $this->assertSame('', $remember->getToken());
        $this->assertSame('', $remember->getUserAgent());
    }

    public function testNonScalarIdBecomesNull(): void
    {
        $remember = new UserRemember(['id' => ['nested']]);

        $this->assertNull($remember->getId());
    }
    public function testParsesArrayPayload(): void
    {
        $remember = new UserRemember([
            'id'         => 42,
            'token'      => 'abc',
            'user_agent' => 'phpunit',
        ]);

        $this->assertSame(42, $remember->getId());
        $this->assertSame('abc', $remember->getToken());
        $this->assertSame('phpunit', $remember->getUserAgent());
    }

    public function testParsesJsonStringPayload(): void
    {
        $payload  = json_encode([
            'id'         => 'user-7',
            'token'      => 'xyz',
            'user_agent' => 'agent',
        ]);
        $remember = new UserRemember((string) $payload);

        $this->assertSame('user-7', $remember->getId());
        $this->assertSame('xyz', $remember->getToken());
        $this->assertSame('agent', $remember->getUserAgent());
    }
}
