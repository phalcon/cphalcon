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

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\AttributesReader;
use Phalcon\Annotations\Exceptions\InvalidSourceTable;
use Phalcon\Annotations\Models\MetaData\Source;
use Phalcon\Annotations\Reader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Models\Annotations\SourceChild;
use Phalcon\Tests\Support\Models\Annotations\SourceEmpty;
use Phalcon\Tests\Support\Models\Annotations\SourceModel;
use Phalcon\Tests\Support\Models\Annotations\SourceNamedArgument;
use Phalcon\Tests\Support\Models\Annotations\SourceUnrelated;
use Phalcon\Tests\Support\Models\Annotations\SourceWithoutAnnotations;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetTableFromAdapterTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{class-string, string|null}>
     */
    public static function getExamples(): array
    {
        return [
            'positional'     => [SourceModel::class, 'attribute_records'],
            'named'          => [SourceNamedArgument::class, 'named_attribute_records'],
            'not inherited'  => [SourceChild::class, null],
            'foreign Source' => [SourceUnrelated::class, null],
            'no attributes'  => [SourceWithoutAnnotations::class, null],
        ];
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-16
     */
    #[DataProvider('getExamples')]
    public function testAnnotationsModelsMetaDataSourceGetTableFromAdapter(string $className, ?string $expected): void
    {
        $adapter = new Memory();
        $adapter->setReader(new AttributesReader());

        $this->assertSame($expected, Source::getTableFromAdapter($adapter, $className));
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-16
     */
    public function testAnnotationsModelsMetaDataSourceGetTableFromAdapterInvalidTable(): void
    {
        $adapter = new Memory();
        $adapter->setReader(new AttributesReader());

        $this->expectException(InvalidSourceTable::class);
        $this->expectExceptionMessage("Source table name must be a non-empty string; received: ''");

        Source::getTableFromAdapter($adapter, SourceEmpty::class);
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-16
     */
    public function testAnnotationsModelsMetaDataSourceGetTableFromAdapterSkipsDocblocks(): void
    {
        $adapter = $this->createMock(AdapterInterface::class);
        $adapter->method('getReader')->willReturn(new Reader());
        $adapter->expects($this->never())->method('get');

        $this->assertNull(Source::getTableFromAdapter($adapter, SourceModel::class));
    }
}
