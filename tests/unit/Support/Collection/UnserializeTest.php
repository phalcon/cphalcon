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

use PHPUnit\Framework\Attributes\DataProvider;

final class UnserializeTest extends AbstractCollectionTestCase
{
    /**
     * @dataProvider getClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionUnserialize(
        string $class,
    ): void {
        $data = $this->getData();
        $serialized = serialize($data);
        $collection = new $class();

        $collection->unserialize($serialized);

        $expected = $data;
        $actual = $collection->toArray();
        $this->assertSame($expected, $actual);
    }
}
