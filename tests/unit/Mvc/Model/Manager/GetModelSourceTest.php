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
use Phalcon\Tests\Support\Models\Annotations\SourceInitialized;
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
            'attribute'        => [AttributesReader::class, SourceModel::class, 'attribute_records'],
            'named attribute'  => [AttributesReader::class, SourceNamedArgument::class, 'named_attribute_records'],
            'docblock'         => [Reader::class, SourceModel::class, 'docblock_records'],
            'named docblock'   => [Reader::class, SourceNamedArgument::class, 'named_docblock_records'],
            'no attributes'    => [
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
     */
    #[DataProvider('getSourceExamples')]
    public function testAppliesTheCurrentPrefix(
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
     * @param class-string<ReaderInterface> $readerClass
     */
    #[DataProvider('getReaders')]
    public function testExplicitSourceCanReplaceTheCachedSource(string $readerClass): void
    {
        $this->setReader($readerClass);
        $model   = new SourceModel();
        $manager = $this->container->getShared('modelsManager');
        $model->getSource();

        $manager->setModelSource($model, 'explicit_records');

        $this->assertSame('explicit_records', $model->getSource());
    }

    public function testFallsBackWithoutAContainer(): void
    {
        $model   = new SourceModel();
        $manager = new Manager();

        $this->assertSame('source_model', $manager->getModelSource($model));
    }

    public function testFallsBackWithoutAnAnnotationsService(): void
    {
        $this->container->remove('annotations');
        $model = new SourceModel();

        $this->assertSame('source_model', $model->getSource());
    }

    /**
     * @param class-string<ReaderInterface> $readerClass
     * @param class-string<Model>           $modelClass
     */
    #[DataProvider('getSourceExamples')]
    public function testGetsSourceBeforeReadingMetadata(
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

    public function testInitializeSourceTakesPrecedenceWithoutReadingAnnotations(): void
    {
        $adapter = $this->createMock(Memory::class);
        $adapter->expects($this->never())->method('get');
        $this->container->setShared('annotations', $adapter);

        $model = new SourceInitialized();

        $this->assertSame('initialized_records', $model->getSource());
    }

    /**
     * The manager caches the result even when the adapter itself does not.
     *
     * @param class-string<ReaderInterface> $readerClass
     * @param class-string<Model>           $modelClass
     */
    #[DataProvider('getSourceExamples')]
    public function testReadsAnnotationsOncePerModelClass(
        string $readerClass,
        string $modelClass,
        string $expected
    ): void {
        $reader     = new $readerClass();
        $reflection = new Reflection($reader->parse($modelClass));
        $adapter    = $this->createMock(Memory::class);
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
     */
    #[DataProvider('getReaders')]
    public function testSourceDoesNotChangeColumnMetadata(string $readerClass): void
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
     */
    private function setReader(string $readerClass): void
    {
        $adapter = new Memory();
        $adapter->setReader(new $readerClass());
        $this->container->setShared('annotations', $adapter);
    }
}
