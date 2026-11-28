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

use ErrorException;
use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Exceptions\InvalidSourceTable;
use Phalcon\Annotations\Models\MetaData\Source;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Attributes\CyclicArgument;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetTableTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{array<int|string, mixed>, string}>
     */
    public static function getInvalidTables(): array
    {
        $recursiveArray         = [];
        $recursiveArray['self'] = &$recursiveArray;

        return [
            'missing argument'                              => [[], 'NULL'],
            'empty positional argument'                     => [[''], "''"],
            'empty named argument'                          => [['table' => ''], "''"],
            'empty named argument with positional fallback' => [[0 => 'invoices', 'table' => ''], "''"],
            'spaces argument'                               => [['   '], "'   '"],
            'whitespace named argument'                     => [['table' => "\t\r\n\v"], "'\t\r\n\v'"],
            'null argument'                                 => [[null], 'NULL'],
            'empty array argument'                          => [[[]], 'array'],
            'array argument'                                => [[['invoices']], 'array'],
            'recursive array argument'                      => [[$recursiveArray], 'array'],
            'cyclic object argument'                        => [[new CyclicArgument()], CyclicArgument::class],
            'array containing cyclic object'                => [[[new CyclicArgument()]], 'array'],
            'integer argument'                              => [[123], '123'],
            'boolean argument'                              => [[false], 'false'],
        ];
    }

    /**
     * @return array<string, array{array<int|string, mixed>, string}>
     */
    public static function getTables(): array
    {
        return [
            'positional argument'                           => [['invoices'], 'invoices'],
            'named argument'                                => [['table' => 'invoices'], 'invoices'],
            'named argument takes precedence'               => [[0 => 'other', 'table' => 'invoices'], 'invoices'],
            'null named argument uses positional fallback'  => [[0 => 'invoices', 'table' => null], 'invoices'],
            'zero string is not empty'                      => [['0'], '0'],
            'valid table is not trimmed'                    => [[' invoices '], ' invoices '],
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
    public function testAnnotationsModelsMetaDataSourceGetTableInvalid(array $arguments, string $value): void
    {
        $this->expectException(InvalidSourceTable::class);
        $this->expectExceptionMessage('Source table name must be a non-empty string; received: ' . $value);

        set_error_handler(static function (int $severity, string $message): never {
            throw new ErrorException($message, 0, $severity);
        });

        try {
            Source::getTable($this->createCollection($arguments));
        } finally {
            restore_error_handler();
        }
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
