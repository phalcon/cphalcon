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

namespace Phalcon\Tests\Unit\Acl\Adapter\Storage;

use Phalcon\Acl\Adapter\Storage;
use Phalcon\Acl\Exceptions\InvalidSnapshot;
use Phalcon\Storage\Adapter\Memory as StorageMemory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class VersionTest extends AbstractUnitTestCase
{

    public function testIncompatibleVersionThrows(): void
    {
        $backend = new StorageMemory(new SerializerFactory());
        $backend->set(
            'acl-ver',
            [
                'version'         => 999,
                'access'          => [],
                'accessList'      => [],
                'components'      => [],
                'componentsNames' => [],
                'roles'           => [],
                'roleInherits'    => [],
            ]
        );

        $this->expectException(InvalidSnapshot::class);

        new Storage($backend, 'acl-ver');
    }
    public function testMissingVersionLoadsAsEmpty(): void
    {
        $backend = new StorageMemory(new SerializerFactory());
        $backend->set('acl-ver', ['roles' => [], 'components' => []]);

        $adapter = new Storage($backend, 'acl-ver');

        $this->assertSame([], $adapter->getRoles());
        $this->assertSame([], $adapter->getComponents());
    }
}
