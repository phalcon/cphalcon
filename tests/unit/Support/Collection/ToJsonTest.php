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

use InvalidArgumentException;
use Phalcon\Support\Collection;
use PHPUnit\Framework\Attributes\DataProvider;

final class ToJsonTest extends AbstractCollectionTestCase
{
    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getClasses')]
    #[DataProvider('getClasses')]
    public function testSupportCollectionToJson(
        string $class,
    ): void {
        $data = $this->getData();
        $collection = new $class($data);

        $expected = json_encode($data);
        $actual = $collection->toJson();
        $this->assertSame($expected, $actual);

        $expected = json_encode($data, JSON_PRETTY_PRINT);
        $actual = $collection->toJson(JSON_PRETTY_PRINT);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionToJsonEncodeFail(): void
    {
        $collection = new Collection();
        $collection->set('handle', fopen('php://memory', 'r'));

        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('json_encode error: Type is not supported');

        $collection->toJson();
    }
}
