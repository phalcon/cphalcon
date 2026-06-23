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
use Phalcon\Storage\Adapter\Memory as StorageMemory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class RoundTripTest extends AbstractUnitTestCase
{
    public function testStaticPolicySurvivesSaveAndLoad(): void
    {
        $backend = new StorageMemory(new SerializerFactory());

        $writer = new Storage($backend, 'acl-test');
        $writer->addRole('admin');
        $writer->addComponent('products', ['browse', 'edit']);
        $writer->allow('admin', 'products', 'browse');
        $writer->save();

        // A fresh adapter over the same backend hydrates on construct.
        $reader = new Storage($backend, 'acl-test');

        $this->assertTrue($reader->isAllowed('admin', 'products', 'browse'));
        $this->assertTrue($reader->isRole('admin'));
        $this->assertTrue($reader->isComponent('products'));
        $this->assertSame(Enum::DENY, $reader->getDefaultAction());
    }
}
