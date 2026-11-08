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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Annotations\AttributesReader;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Di\Di;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Annotations\SourceChild;
use Phalcon\Tests\Support\Models\Annotations\SourceInitializedChild;
use Phalcon\Tests\Support\Models\Annotations\SourceInvalidDocblocks;
use Phalcon\Tests\Support\Models\Annotations\SourceModel;
use Phalcon\Tests\Support\Models\Annotations\SourceNamedArgument;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('sqlite')]
final class SourceAnnotationsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        // Each case has its own database and model manager.
        Query::clean();
        $this->setNewFactoryDefault();
    }

    public function tearDown(): void
    {
        Query::clean();
        Di::reset();

        parent::tearDown();
    }

    /**
     * @return array<string, array{class-string<Model>, string, string}>
     */
    public static function getExamples(): array
    {
        return [
            'attribute'       => [SourceModel::class, 'attribute_records', ''],
            'named attribute' => [
                SourceNamedArgument::class,
                'named_attribute_records',
                'app_',
            ],
            'child without Source' => [SourceChild::class, 'source_child', 'app_'],
            'inherited initialize' => [SourceInitializedChild::class, 'initialized_records', 'app_'],
        ];
    }

    /**
     * The default Introspection strategy must not parse unrelated PHPDoc
     * annotations when saving or querying a model.
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    public function testMvcModelManagerGetModelSourceIntrospectionWithInvalidDocblocks(): void
    {
        $connection = new Sqlite(['dbname' => ':memory:']);
        $this->container->setShared('db', $connection);
        $connection->execute(
            'CREATE TABLE source_invalid_docblocks (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(70) NOT NULL)'
        );

        $model       = new SourceInvalidDocblocks();
        $model->name = 'Introspection test';

        $this->assertTrue($model->save());
        $this->assertGreaterThan(0, $model->id);

        $found = SourceInvalidDocblocks::findFirst();
        $this->assertInstanceOf(SourceInvalidDocblocks::class, $found);
        $this->assertSame('Introspection test', $found->name);
    }

    /**
     * Source must be resolved before the first insert or PHQL query. The
     * property annotations still supply the columns, primary key and identity.
     *
     * @param class-string<Model> $modelClass
     *
     * @author QUAD69 <quad69@yandex.ru>
     * @since  2026-11-08
     */
    #[DataProvider('getExamples')]
    public function testMvcModelManagerGetModelSourcePersistence(
        string $modelClass,
        string $table,
        string $prefix
    ): void {
        $annotations = new AnnotationsMemory();
        $annotations->setReader(new AttributesReader());
        $this->container->setShared('annotations', $annotations);

        $metadata = new Memory();
        $metadata->setStrategy(new Annotations());
        $this->container->setShared('modelsMetadata', $metadata);

        $connection = new Sqlite(['dbname' => ':memory:']);
        $this->container->setShared('db', $connection);
        $this->container->getShared('modelsManager')->setModelPrefix($prefix);

        $source = $prefix . $table;
        $connection->execute(
            'CREATE TABLE ' . $source . ' (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(70) NOT NULL)'
        );

        $model       = new $modelClass();
        $model->name = 'Source test';

        $this->assertTrue($model->save());
        $this->assertGreaterThan(0, $model->id);
        $this->assertSame($source, $model->getSource());
        $this->assertSame(1, (int) $connection->fetchOne('SELECT COUNT(*) AS total FROM ' . $source)['total']);

        $found = $modelClass::findFirst([
            'conditions' => 'id = :id:',
            'bind'       => ['id' => $model->id],
        ]);

        $this->assertInstanceOf($modelClass, $found);
        $this->assertSame('Source test', $found->name);
    }
}
