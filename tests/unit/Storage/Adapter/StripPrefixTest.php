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

use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class StripPrefixTest extends AbstractUnitTestCase
{
    /**
     * By default a leading prefix is stripped from incoming keys, so a key
     * carrying the prefix addresses the same record as the bare key
     *
     * @issue  17127
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testStorageAdapterStripPrefixDefault(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer, ['prefix' => 'sess']);

        $adapter->set('sessabc', 'one');

        $expected = 'one';
        $this->assertSame($expected, $adapter->get('abc'));
        $this->assertSame($expected, $adapter->get('sessabc'));
    }

    /**
     * With `stripPrefix` disabled, a key that happens to start with the
     * prefix text is a distinct record from the bare key
     *
     * @issue  17127
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-11
     */
    public function testStorageAdapterStripPrefixDisabled(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Memory(
            $serializer,
            [
                'prefix'      => 'sess',
                'stripPrefix' => false,
            ]
        );

        $adapter->set('sessabc', 'one');
        $adapter->set('abc', 'two');

        $expected = 'one';
        $actual   = $adapter->get('sessabc');
        $this->assertSame($expected, $actual);

        $expected = 'two';
        $actual   = $adapter->get('abc');
        $this->assertSame($expected, $actual);
    }
}
