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
     * Closures are not serializable, so on reload a closure-backed rule fails
     * closed (DENY) until the closure is re-registered.
     */
    public function testCallableRulesPersistAsDeny(): void
    {
        $backend = new StorageMemory(new SerializerFactory());

        $writer = new Storage($backend, 'acl-func');
        $writer->addRole('admin');
        $writer->addComponent('products', ['browse']);
        $writer->allow('admin', 'products', 'browse', fn () => false);

        $this->assertFalse($writer->isAllowed('admin', 'products', 'browse'));

        $writer->save();

        // Closure dropped on reload => rule denies (fail closed), not allows.
        $reader = new Storage($backend, 'acl-func');
        $this->assertFalse($reader->isAllowed('admin', 'products', 'browse'));

        // Re-registering the closure restores conditional behavior.
        $reader->allow('admin', 'products', 'browse', fn () => true);
        $this->assertTrue($reader->isAllowed('admin', 'products', 'browse'));
    }
}
