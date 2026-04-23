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

        $expected = serialize($data);
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

        $expected = 'O:26:"Phalcon\Support\Collection":'
                    . '3:{s:3:"one";s:3:"two";s:5:"three";s:4:"four";s:4:"five";s:3:"six";}';
        $actual = serialize($collection);
        $this->assertSame($expected, $actual);
    }
}
