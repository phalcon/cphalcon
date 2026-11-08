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

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\AttributesReader;
use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\ReaderInterface;
use Phalcon\Annotations\Reflection;
use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Models\Annotations\SourceChild;
use Phalcon\Tests\Support\Models\Annotations\SourceInitialized;
use Phalcon\Tests\Support\Models\Annotations\SourceInitializedChild;
use Phalcon\Tests\Support\Models\Annotations\SourceInvalidDocblocks;
use Phalcon\Tests\Support\Models\Annotations\SourceModel;
use Phalcon\Tests\Support\Models\Annotations\SourceNamedArgument;
use Phalcon\Tests\Support\Models\Annotations\SourceUnrelated;
use Phalcon\Tests\Support\Models\Annotations\SourceWithoutAnnotations;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetModelSourceTest extends AbstractUnitTestCase
{
    private FactoryDefault $container;

    public function setUp(): void
    {
        parent::setUp();

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
            'no annotations'   => [Reader::class, SourceWithoutAnnotations::class, 'source_without_annotations'],
            'foreign Source'   => [AttributesReader::class, SourceUnrelated::class, 'source_unrelated'],
            'other annotation' => [Reader::class, SourceUnrelated::class, 'source_unrelated'],
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
