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
use Phalcon\Storage\Adapter\Memory as StorageMemory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class SaveTest extends AbstractUnitTestCase
{
    /**
     * Callable rules are not part of the persisted snapshot (closures are not
     * serializable), so after a reload the rule behaves as a plain allow.
     */
    public function testCallableRulesAreNotPersisted(): void
    {
        $backend = new StorageMemory(new SerializerFactory());

        $writer = new Storage($backend, 'acl-func');
        $writer->addRole('admin');
        $writer->addComponent('products', ['browse']);
        $writer->allow('admin', 'products', 'browse', fn () => false);

        // The closure denies before persistence.
        $this->assertFalse($writer->isAllowed('admin', 'products', 'browse'));

        $writer->save();

        // The closure is dropped on reload; the static allow remains.
        $reader = new Storage($backend, 'acl-func');
        $this->assertTrue($reader->isAllowed('admin', 'products', 'browse'));
    }
}
