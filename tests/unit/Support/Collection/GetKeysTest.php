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

final class GetKeysTest extends AbstractCollectionTestCase
{
    /**
     * @dataProvider getClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionGetKeys(string $class): void
    {
        $data = $this->getData();
        $collection = new $class($data);

        $expected = $this->getDataKeys();
        $actual = $collection->getKeys();
        $this->assertSame($expected, $actual);

        $data = $this->getDataNoCase();
        $collection = new $class($data);
        $expected = $this->getDataKeys();
        $actual = $collection->getKeys();
        $this->assertSame($expected, $actual);

        $expected = array_keys($data);
        $actual = $collection->getKeys(false);
        $this->assertSame($expected, $actual);
    }
}
