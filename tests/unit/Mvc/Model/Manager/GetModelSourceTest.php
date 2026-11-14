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

namespace Phalcon\Tests\Unit\Mvc\Model\Manager;

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\AttributesReader;
use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\ReaderInterface;
use Phalcon\Annotations\Reflection;
use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exception as ModelException;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Models\Annotations\SourceChild;
use Phalcon\Tests\Support\Models\Annotations\SourceEmpty;
use Phalcon\Tests\Support\Models\Annotations\SourceEmptyNamedArgument;
use Phalcon\Tests\Support\Models\Annotations\SourceInitialized;
use Phalcon\Tests\Support\Models\Annotations\SourceInitializedChild;
use Phalcon\Tests\Support\Models\Annotations\SourceInvalidDocblocks;
use Phalcon\Tests\Support\Models\Annotations\SourceInvalidTable;
use Phalcon\Tests\Support\Models\Annotations\SourceModel;
use Phalcon\Tests\Support\Models\Annotations\SourceNamedArgument;
use Phalcon\Tests\Support\Models\Annotations\SourceUnrelated;
use Phalcon\Tests\Support\Models\Annotations\SourceWithoutAnnotations;
use Phalcon\Tests\Support\Models\Annotations\SourceWithoutTable;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

final class GetModelSourceTest extends AbstractUnitTestCase
{
    private FactoryDefault $container;

    public function setUp(): void
    {
        parent::setUp();

        Di::reset();

        $this->container = new FactoryDefault();
    }

    public function tearDown(): void
    {
        Di::reset();

        parent::tearDown();
    }

    /**
     * @return array<string, array{class-string<ReaderInterface>, class-string<Model>, string}>
     */
    public static function getAttributeSourceExamples(): array
    {
        return array_filter(
            self::getSourceExamples(),
            static fn (array $example): bool => $example[0] === AttributesReader::class
        );
    }

    /**
     * @return array<string, array{mixed}>
     */
    public static function getInvalidAnnotationsServices(): array
    {
        return [
            'object without the adapter interface' => [new stdClass()],
            'null'                                 => [null],
            'boolean'                              => [false],
            'integer'                              => [123],
            'string'                               => ['invalid'],
            'array'                                => [[]],
        ];
    }

    /**
     * @return array<string, array{class-string<Model>}>
     */
    public static function getInvalidSourceExamples(): array
    {
        return [
            'missing table'          => [SourceWithoutTable::class],
            'empty positional table' => [SourceEmpty::class],
            'empty named table'      => [SourceEmptyNamedArgument::class],
            'array table'            => [SourceInvalidTable::class],
        ];
    }

    /**
     * @return array<string, array{class-string<ReaderInterface>}>
     */
    public static function getReaders(): array
    {
        return [
            'attributes' => [AttributesReader::class],
            'docblocks'  => [Reader::class],
        ];
    }

    /**
     * @return array<string, array{class-string<ReaderInterface>, class-string<Model>, string}>
     */
    public static function getSourceExamples(): array
    {
        return [
            'attribute'              => [AttributesReader::class, SourceModel::class, 'attribute_records'],
            'named attribute'        => [
                AttributesReader::class,
                SourceNamedArgument::class,
                'named_attribute_records',
            ],
            'docblock ignored'       => [Reader::class, SourceModel::class, 'source_model'],
            'named docblock ignored' => [Reader::class, SourceNamedArgument::class, 'source_named_argument'],
            'child without Source'   => [AttributesReader::class, SourceChild::class, 'source_child'],
            'no attributes'          => [
                AttributesReader::class,
                SourceWithoutAnnotations::class,
                'source_without_annotations',
            ],
            'no annotations' => [
                Reader::class,
                SourceWithoutAnnotations::class,
                'source_without_annotations',
            ],
            'foreign Source'            => [AttributesReader::class, SourceUnrelated::class, 'source_unrelated'],
            'other annotation'          => [Reader::class, SourceUnrelated::class, 'source_unrelated'],
            'invalid attribute ignored' => [Reader::class, SourceWithoutTable::class, 'source_without_table'],
        ];
    }

    /**
     * @param class-string<ReaderInterface> $readerClass
     * @param class-string<Model>           $modelClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    #[DataProvider('getSourceExamples')]
    public function testMvcModelManagerGetModelSourceBeforeMetadata(
        string $readerClass,
        string $modelClass,
        string $expected
    ): void {
        $this->setReader($readerClass);
        $model   = new $modelClass();
        $manager = $this->container->getShared('modelsManager');

        $this->assertSame($expected, $manager->getModelSource($model));
        $this->assertSame($expected, $model->getSource());
    }

    /**
     * The manager caches the result even when the adapter itself does not.
     *
     * @param class-string<ReaderInterface> $readerClass
     * @param class-string<Model>           $modelClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    #[DataProvider('getAttributeSourceExamples')]
    public function testMvcModelManagerGetModelSourceCache(
        string $readerClass,
        string $modelClass,
        string $expected
    ): void {
        $reader     = new $readerClass();
        $reflection = new Reflection($reader->parse($modelClass));
        $adapter    = $this->createMock(Memory::class);
        $adapter->method('getReader')->willReturn($reader);
        $adapter->expects($this->once())
                ->method('get')
                ->with($modelClass)
                ->willReturn($reflection)
        ;
        $this->container->setShared('annotations', $adapter);

        $first  = new $modelClass();
        $second = new $modelClass();

        $this->assertSame($expected, $first->getSource());
        $this->assertSame($expected, $first->getSource());
        $this->assertSame($expected, $second->getSource());
    }

    /**
     * @param class-string<ReaderInterface> $readerClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    #[DataProvider('getReaders')]
    public function testMvcModelManagerGetModelSourceColumnMetadata(string $readerClass): void
    {
        $this->setReader($readerClass);
        $model = new SourceModel();
        $model->getSource();

        $strategy = new Annotations();
        $metadata = $strategy->getMetaData($model, $this->container);

        $this->assertSame(['id', 'name'], $metadata[MetaData::MODELS_ATTRIBUTES]);
        $this->assertSame(['id'], $metadata[MetaData::MODELS_PRIMARY_KEY]);
        $this->assertSame('id', $metadata[MetaData::MODELS_IDENTITY_COLUMN]);
    }

    /**
     * Any adapter implementing the interface can supply Source attributes.
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    public function testMvcModelManagerGetModelSourceCustomAnnotationsAdapter(): void
    {
        $reader  = new AttributesReader();
        $adapter = $this->createMock(AdapterInterface::class);
        $adapter->method('getReader')->willReturn($reader);
        $adapter->expects($this->once())
                ->method('get')
                ->with(SourceModel::class)
                ->willReturn(new Reflection($reader->parse(SourceModel::class)))
        ;
        $this->container->setShared('annotations', $adapter);

        $this->assertSame('attribute_records', (new SourceModel())->getSource());
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    public function testMvcModelManagerGetModelSourceExplicitSkipsInvalidAnnotationsService(): void
    {
        $this->container->setShared('annotations', new stdClass());
        $model = new SourceInitialized();

        $this->assertSame('initialized_records', $model->getSource());
    }

    /**
     * An explicit source also takes priority over a malformed Source attribute.
     *
     * @param class-string<Model> $modelClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    #[DataProvider('getInvalidSourceExamples')]
    public function testMvcModelManagerGetModelSourceExplicitSkipsInvalidAttribute(string $modelClass): void
    {
        $this->setReader(AttributesReader::class);
        $model   = new $modelClass();
        $manager = $this->container->getShared('modelsManager');
        $manager->setModelSource($model, 'explicit_records');

        $this->assertSame('explicit_records', $model->getSource());
    }

    /**
     * @param class-string<ReaderInterface> $readerClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    #[DataProvider('getReaders')]
    public function testMvcModelManagerGetModelSourceInheritedInitialize(string $readerClass): void
    {
        $this->setReader($readerClass);
        $child = new SourceInitializedChild();

        $this->assertSame('initialized_records', $child->getSource());
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    public function testMvcModelManagerGetModelSourceInitialize(): void
    {
        $adapter = $this->createMock(Memory::class);
        $adapter->expects($this->never())->method('get');
        $this->container->setShared('annotations', $adapter);

        $model = new SourceInitialized();

        $this->assertSame('initialized_records', $model->getSource());
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    #[DataProvider('getInvalidAnnotationsServices')]
    public function testMvcModelManagerGetModelSourceInvalidAnnotationsService(mixed $service): void
    {
        $this->container->setShared('annotations', fn () => $service);
        $model = new SourceModel();

        $this->expectException(ModelException::class);
        $this->expectExceptionMessage(
            "The 'annotations' service must implement Phalcon\\Annotations\\Adapter\\AdapterInterface"
        );

        $model->getSource();
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    public function testMvcModelManagerGetModelSourceInvalidDocblocks(): void
    {
        // Verify that this fixture really is rejected by the PHPDoc parser.
        try {
            (new Reader())->parse(SourceInvalidDocblocks::class);
            $this->fail('The fixture must contain a malformed annotation');
        } catch (Exception $exception) {
            $this->assertNotEmpty($exception->getMessage());
        }

        $model = new SourceInvalidDocblocks();
        $this->assertSame('source_invalid_docblocks', $model->getSource());
    }

    /**
     * @param class-string<Model> $modelClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    #[DataProvider('getInvalidSourceExamples')]
    public function testMvcModelManagerGetModelSourceInvalidTable(string $modelClass): void
    {
        $this->setReader(AttributesReader::class);
        $model = new $modelClass();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Source table name must be a non-empty string');

        $model->getSource();
    }

    /**
     * @param class-string<ReaderInterface> $readerClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    #[DataProvider('getReaders')]
    public function testMvcModelManagerGetModelSourceOverrideCached(string $readerClass): void
    {
        $this->setReader($readerClass);
        $model   = new SourceModel();
        $manager = $this->container->getShared('modelsManager');
        $model->getSource();

        $manager->setModelSource($model, 'explicit_records');

        $this->assertSame('explicit_records', $model->getSource());
    }

    /**
     * @param class-string<ReaderInterface> $readerClass
     * @param class-string<Model>           $modelClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    #[DataProvider('getSourceExamples')]
    public function testMvcModelManagerGetModelSourcePrefix(
        string $readerClass,
        string $modelClass,
        string $expected
    ): void {
        $this->setReader($readerClass);
        $model   = new $modelClass();
        $manager = $this->container->getShared('modelsManager');
        $manager->setModelPrefix('app_');

        $this->assertSame('app_' . $expected, $model->getSource());

        $manager->setModelPrefix('other_');

        $this->assertSame('other_' . $expected, $model->getSource());
    }

    /**
     * A reader derived from AttributesReader keeps the explicit opt-in.
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    public function testMvcModelManagerGetModelSourceReaderSubclass(): void
    {
        $adapter = new Memory();
        $adapter->setReader(new class () extends AttributesReader {
        });
        $this->container->setShared('annotations', $adapter);

        $model = new SourceModel();

        $this->assertSame('attribute_records', $model->getSource());
    }

    /**
     * Failed source resolution must not cache the inferred fallback.
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-13
     */
    public function testMvcModelManagerGetModelSourceRetryAfterInvalidAnnotationsService(): void
    {
        $this->container->setShared('annotations', new stdClass());
        $model = new SourceModel();

        try {
            $model->getSource();
            $this->fail('Invalid annotations service must be rejected');
        } catch (ModelException $exception) {
            $this->assertSame(
                "The 'annotations' service must implement Phalcon\\Annotations\\Adapter\\AdapterInterface",
                $exception->getMessage()
            );
        }

        // Clear the DI's resolved shared instance before registering its replacement.
        $this->container->remove('annotations');
        $this->setReader(AttributesReader::class);

        $this->assertSame('attribute_records', $model->getSource());
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    public function testMvcModelManagerGetModelSourceSkipsDocblockReader(): void
    {
        $reader = $this->createMock(Reader::class);
        $reader->expects($this->never())->method('parse');
        $adapter = new Memory();
        $adapter->setReader($reader);
        $this->container->setShared('annotations', $adapter);

        $model = new SourceModel();
        $this->assertSame('source_model', $model->getSource());
    }

    /**
     * A child's table is inferred from its own class, regardless of whether
     * the parent's attribute source was cached first.
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    public function testMvcModelManagerGetModelSourceUnannotatedChild(): void
    {
        $this->setReader(AttributesReader::class);

        $parent = new SourceModel();
        $this->assertSame('attribute_records', $parent->getSource());

        $child = new SourceChild();
        $this->assertSame('source_child', $child->getSource());
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    public function testMvcModelManagerGetModelSourceWithoutAnnotationsService(): void
    {
        $this->container->remove('annotations');
        $model = new SourceModel();

        $this->assertSame('source_model', $model->getSource());
    }

    /**
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    public function testMvcModelManagerGetModelSourceWithoutContainer(): void
    {
        $model   = new SourceModel();
        $manager = new Manager();

        $this->assertSame('source_model', $manager->getModelSource($model));
    }

    /**
     * @param class-string<ReaderInterface> $readerClass
     */
    private function setReader(string $readerClass): void
    {
        $adapter = new Memory();
        $adapter->setReader(new $readerClass());
        $this->container->setShared('annotations', $adapter);
    }
}
