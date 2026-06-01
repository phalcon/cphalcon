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

namespace Phalcon\Tests\Unit\Auth\Adapter;

use Phalcon\Auth\Adapter\Memory;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;

final class MemoryFromOptionsTest extends AbstractUnitTestCase
{
    private Security $security;

    protected function setUp(): void
    {
        $this->security = new Security();
    }

    public function testFromOptionsAcceptsEmptyOptions(): void
    {
        $adapter = Memory::fromOptions($this->security, []);

        $this->assertInstanceOf(Memory::class, $adapter);
        $this->assertNull($adapter->retrieveById(1));
    }

    public function testFromOptionsBuildsMemoryWithUsers(): void
    {
        $adapter = Memory::fromOptions(
            $this->security,
            [
                'users' => [
                    [
                        'id'       => 1,
                        'email'    => 'alice@example.com',
                        'password' => $this->security->hash('secret'),
                    ],
                ],
            ]
        );

        $user = $adapter->retrieveById(1);

        $this->assertInstanceOf(AuthUser::class, $user);
    }

    public function testFromOptionsIgnoresNonArrayUsers(): void
    {
        $adapter = Memory::fromOptions($this->security, ['users' => 'not-an-array']);

        $this->assertInstanceOf(Memory::class, $adapter);
        $this->assertNull($adapter->retrieveById(1));
    }
}
