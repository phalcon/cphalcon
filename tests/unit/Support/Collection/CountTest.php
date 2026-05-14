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

final class CountTest extends AbstractCollectionTestCase
{
    /**
     * @dataProvider getClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionCount(
        string $class,
    ): void {
        $data = $this->getData();
        $collection = new $class($data);

        $expected = 3;
        $actual = $collection->toArray();
        $this->assertCount($expected, $actual);

        $expected = 3;
        $actual = $collection->count();
        $this->assertSame($expected, $actual);
    }
}
