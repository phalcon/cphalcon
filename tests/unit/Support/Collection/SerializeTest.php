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

namespace Phalcon\Tests\Unit\Support\Collection;

use Phalcon\Support\Collection;
use PHPUnit\Framework\Attributes\DataProvider;

final class SerializeTest extends AbstractCollectionTestCase
{
    /**
     * @dataProvider getClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionSerialize(
        string $class,
    ): void {
        $data = $this->getData();
        $collection = new $class($data);

        $expected = serialize([
            'data'        => $data,
            'insensitive' => true,
            'strictNull'  => false,
        ]);
        $actual = $collection->serialize();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionSerializeUnderscore(): void
    {
        $data = $this->getData();
        $collection = new Collection($data);

        // __serialize() now emits a structured array with data + flags.
        // __unserialize() supports both this format and the legacy flat-array
        // format for BC with previously serialized instances.
        $expected = 'O:26:"Phalcon\Support\Collection":'
                    . '3:{s:4:"data";a:3:{s:3:"one";s:3:"two";s:5:"three";s:4:"four";s:4:"five";'
                    . 's:3:"six";}s:11:"insensitive";b:1;s:10:"strictNull";b:0;}';
        $actual = serialize($collection);
        $this->assertSame($expected, $actual);
    }
}
