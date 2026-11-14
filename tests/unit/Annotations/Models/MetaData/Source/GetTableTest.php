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

namespace Phalcon\Tests\Unit\Annotations\Models\MetaData\Source;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Models\MetaData\Source;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetTableTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{array<int|string, mixed>}>
     */
    public static function getInvalidTables(): array
    {
        return [
            'missing argument'                              => [[]],
            'empty positional argument'                     => [['']],
            'empty named argument'                          => [['table' => '']],
            'empty named argument with positional fallback' => [[0 => 'invoices', 'table' => '']],
            'null argument'                                 => [[null]],
            'empty array argument'                          => [[[]]],
            'array argument'                                => [[['invoices']]],
            'integer argument'                              => [[123]],
            'boolean argument'                              => [[false]],
        ];
    }

    /**
     * @return array<string, array{array<int|string, mixed>, string}>
     */
    public static function getTables(): array
    {
        return [
            'positional argument'                          => [['invoices'], 'invoices'],
            'named argument'                               => [['table' => 'invoices'], 'invoices'],
            'named argument takes precedence'              => [[0 => 'other', 'table' => 'invoices'], 'invoices'],
            'null named argument uses positional fallback' => [[0 => 'invoices', 'table' => null], 'invoices'],
            'zero string is not empty'                     => [['0'], '0'],
        ];
    }

    /**
     * @param array<int|string, mixed> $arguments
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    #[DataProvider('getTables')]
    public function testAnnotationsModelsMetaDataSourceGetTable(array $arguments, string $expected): void
    {
        $this->assertSame($expected, Source::getTable($this->createCollection($arguments)));
    }

    /**
     * @param array<int|string, mixed> $arguments
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    #[DataProvider('getInvalidTables')]
    public function testAnnotationsModelsMetaDataSourceGetTableInvalid(array $arguments): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Source table name must be a non-empty string');

        Source::getTable($this->createCollection($arguments));
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    public function testAnnotationsModelsMetaDataSourceGetTableWithoutSource(): void
    {
        $this->assertNull(Source::getTable(new Collection()));
        $this->assertNull(Source::getTable(new Collection([['name' => 'OtherSource']])));
    }

    /**
     * @param array<int|string, mixed> $arguments
     */
    private function createCollection(array $arguments): Collection
    {
        $nodes = [];

        foreach ($arguments as $key => $value) {
            $node = [
                'expr' => [
                    'type'  => Annotation::T_RESOLVED,
                    'value' => $value,
                ],
            ];

            if (is_string($key)) {
                $node['name'] = $key;
            }

            $nodes[] = $node;
        }

        return new Collection([['name' => 'Source', 'arguments' => $nodes]]);
    }
}
