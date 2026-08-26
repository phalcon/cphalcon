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

namespace Phalcon\Tests\Unit\Storage\Adapter;

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

final class StreamKeyCollisionTest extends AbstractUnitTestCase
{
    /**
     * "acl/rules" and "acl_rules" both normalize to "acl_rules"; the key with
     * the separator gets a hash suffix so the two never share a file.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testStorageAdapterStreamKeysDoNotCollide(): void
    {
        $adapter = new Stream(
            new SerializerFactory(),
            ['storageDir' => Talon::settings()->outputPath() . '/']
        );

        $adapter->set('acl/rules', 'slash');
        $adapter->set('acl_rules', 'underscore');

        $slash      = $adapter->get('acl/rules');
        $underscore = $adapter->get('acl_rules');

        $adapter->delete('acl/rules');
        $adapter->delete('acl_rules');
        $this->safeDeleteDirectory(Talon::settings()->outputPath('ph-strm'));

        $this->assertSame('slash', $slash);
        $this->assertSame('underscore', $underscore);
    }
}
