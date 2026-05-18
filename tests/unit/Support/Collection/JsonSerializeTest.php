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

use Phalcon\Tests\Unit\Support\Fake\FakeJson;
use PHPUnit\Framework\Attributes\DataProvider;

final class JsonSerializeTest extends AbstractCollectionTestCase
{
    /**
     * @dataProvider getClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionJsonSerialize(string $class): void
    {
        $data = $this->getData();
        $collection = new $class($data);

        $expected = $data;
        $actual = $collection->jsonSerialize();
        $this->assertSame($expected, $actual);

        $data = [
            'one'    => 'two',
            'three'  => 'four',
            'five'   => 'six',
            'object' => new FakeJson(),
        ];

        $expected = [
            'one'    => 'two',
            'three'  => 'four',
            'five'   => 'six',
            'object' => [
                'one' => 'two',
            ],
        ];

        $collection = new $class($data);

        $actual = $collection->jsonSerialize();
        $this->assertSame($expected, $actual);
    }
}
