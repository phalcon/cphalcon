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
use Phalcon\Acl\Component;
use Phalcon\Acl\Enum;
use Phalcon\Acl\Role;
use Phalcon\Storage\Adapter\Memory as StorageMemory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class SerializerMatrixTest extends AbstractUnitTestCase
{
    public static function serializerProvider(): array
    {
        return [['Php'], ['Json'], ['Igbinary'], ['Msgpack']];
    }

    #[DataProvider('serializerProvider')]
    public function testPolicyRoundTripsAcrossSerializers(string $serializer): void
    {
        if ('Igbinary' === $serializer && !extension_loaded('igbinary')) {
            $this->markTestSkipped('igbinary extension not available');
        }
        if ('Msgpack' === $serializer && !extension_loaded('msgpack')) {
            $this->markTestSkipped('msgpack extension not available');
        }

        $backend = new StorageMemory(
            new SerializerFactory(),
            ['defaultSerializer' => $serializer]
        );

        $writer = new Storage($backend, 'acl-matrix');
        $writer->addRole('admin');
        $writer->addRole('editor');
        $writer->addInherit('admin', 'editor');
        $writer->addComponent('posts', ['browse', 'edit', 'delete']);
        $writer->allow('editor', 'posts', 'browse');
        $writer->allow('editor', 'posts', 'edit');
        $writer->deny('admin', 'posts', 'delete');
        $writer->setNoArgumentsDefaultAction(Enum::ALLOW);
        $writer->save();

        $reader = new Storage($backend, 'acl-matrix');

        // Inheritance survives the round-trip.
        $this->assertTrue($reader->isAllowed('admin', 'posts', 'browse'));
        $this->assertTrue($reader->isAllowed('editor', 'posts', 'edit'));
        // Explicit deny survives and is not masked by inheritance.
        $this->assertFalse($reader->isAllowed('admin', 'posts', 'delete'));
        // Roles/components rehydrate as objects, not arrays.
        $this->assertInstanceOf(Role::class, $reader->getRoles()['admin']);
        $this->assertInstanceOf(Component::class, $reader->getComponents()['posts']);
        $this->assertSame(Enum::ALLOW, $reader->getNoArgumentsDefaultAction());
    }
}
