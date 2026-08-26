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
use Phalcon\Acl\Enum;
use Phalcon\Acl\Exceptions\InvalidSnapshot;
use Phalcon\Storage\Adapter\Memory as StorageMemory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

final class MalformedSnapshotTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array<int, array<string, mixed>>>
     */
    public static function providerMalformed(): array
    {
        $valid = [
            'version'         => Storage::SNAPSHOT_VERSION,
            'access'          => [],
            'accessList'      => [],
            'components'      => [],
            'componentsNames' => [],
            'roles'           => [],
            'roleInherits'    => [],
        ];

        return [
            'array description'   => [['roles' => ['admin' => ['x']]] + $valid],
            'wildcard role'       => [['roles' => ['*' => null]] + $valid],
            'delimiter component' => [['components' => ['a!b' => null]] + $valid],
            'default action'      => [['defaultAccess' => 'x'] + $valid],
            'inherits not list'   => [['roleInherits' => ['a' => 'b']] + $valid],
            'inherits bad item'   => [['roleInherits' => ['a' => [['b']]]] + $valid],
        ];
    }

    public function testCyclicObjectSnapshotThrows(): void
    {
        $cyclic       = new stdClass();
        $cyclic->self = $cyclic;

        $backend = new StorageMemory(new SerializerFactory());
        $backend->set('acl-cyclic', $cyclic);

        $this->expectException(InvalidSnapshot::class);
        $this->expectExceptionMessage('too deep');

        new Storage($backend, 'acl-cyclic');
    }

    /**
     * @param array<string, mixed> $snapshot
     */
    #[DataProvider('providerMalformed')]
    public function testMalformedSnapshotThrows(array $snapshot): void
    {
        $backend = new StorageMemory(new SerializerFactory());
        $backend->set('acl-bad', $snapshot);

        $this->expectException(InvalidSnapshot::class);

        new Storage($backend, 'acl-bad');
    }

    public function testObjectSnapshotStillLoads(): void
    {
        $snapshot = (object) [
            'version'         => Storage::SNAPSHOT_VERSION,
            'access'          => (object) [],
            'accessList'      => (object) [],
            'components'      => (object) ['products' => 'Products'],
            'componentsNames' => (object) ['products' => true],
            'roles'           => (object) ['admin' => 'Administrator'],
            'roleInherits'    => (object) [],
        ];

        $backend = new StorageMemory(new SerializerFactory());
        $backend->set('acl-obj', $snapshot);

        $adapter = new Storage($backend, 'acl-obj');

        $this->assertTrue($adapter->isRole('admin'));
        $this->assertTrue($adapter->isComponent('products'));
        $this->assertSame(Enum::DENY, $adapter->getDefaultAction());
    }
}
