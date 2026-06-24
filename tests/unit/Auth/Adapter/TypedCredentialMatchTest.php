<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Adapter;

use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;

final class TypedCredentialMatchTest extends AbstractUnitTestCase
{
    /**
     * HTTP input is always string; configured rows are author-typed. The array
     * adapters must match string credentials against typed row values (int id,
     * bool active) instead of rejecting them on a strict type mismatch.
     */
    public function testMatchesTypedRowAgainstStringCredentials(): void
    {
        $security = new Security();

        $adapter = new Memory(
            $security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'bob@example.com',
                    'active'   => true,
                    'password' => $security->hash('secret'),
                ],
            ])
        );

        $user = $adapter->retrieveByCredentials([
            'id'     => '1',
            'active' => '1',
        ]);

        $this->assertInstanceOf(AuthUser::class, $user);
        $this->assertSame(1, $user->getAuthIdentifier());
    }
}
