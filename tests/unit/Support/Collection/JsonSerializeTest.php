<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Collection;

use Phalcon\Support\Collection;
use Phalcon\Tests\Unit\Support\Fake\FakeJson;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

final class JsonSerializeTest extends AbstractCollectionTestCase
{
    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getClasses')]
    #[DataProvider('getClasses')]
    public function testSupportCollectionJsonSerialize(string $class): void
    {
        $data       = $this->getData();
        $collection = new $class($data);

        $expected = $data;
        $actual   = $collection->jsonSerialize();
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

    /**
     * jsonSerialize() keeps the keys and their order. It uses the result of
     * jsonSerialize() for each object that has this method. All other values
     * stay as they are.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-18
     */
    public function testSupportCollectionJsonSerializeKeysAndValues(): void
    {
        $method = new class () {
            public function jsonSerialize(): array
            {
                return ['three' => 'four'];
            }
        };
        $nested = [new FakeJson()];
        $object = new stdClass();

        $collection = new Collection(
            [
                2        => 'two',
                0        => 'zero',
                'json'   => new FakeJson(),
                'method' => $method,
                'object' => $object,
                'nested' => $nested,
                'null'   => null,
            ]
        );

        $expected = [
            2        => 'two',
            0        => 'zero',
            'json'   => ['one' => 'two'],
            'method' => ['three' => 'four'],
            'object' => $object,
            'nested' => $nested,
            'null'   => null,
        ];
        $this->assertSame($expected, $collection->jsonSerialize());

        $collection = new Collection();
        $this->assertSame([], $collection->jsonSerialize());
    }
}
