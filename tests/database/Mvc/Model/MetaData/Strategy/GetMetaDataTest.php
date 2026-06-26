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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Strategy;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Mvc\Model\MetaData\Strategy\Introspection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Boutique\Robots;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class GetMetaDataTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        // The Introspection strategy reads the live table schema.
        new InvoicesMigration(self::getConnection());
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * Both strategies expose the same metadata contract: the Introspection
     * strategy reads it from the live table schema, the Annotations strategy
     * from the model's column annotations. Only the driver-independent
     * structural indices are asserted (the type/bind-type indices vary per
     * driver).
     *
     * @return array<string, array{0: class-string, 1: class-string, 2: array, 3: array, 4: string}>
     */
    public static function getExamples(): array
    {
        return [
            'introspection' => [
                Introspection::class,
                Invoices::class,
                ['inv_id', 'inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total', 'inv_created_at'],
                ['inv_id'],
                'inv_id',
            ],
            'annotations'   => [
                Annotations::class,
                Robots::class,
                ['id', 'name', 'type', 'year', 'datetime', 'deleted', 'text'],
                ['id'],
                'id',
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelMetadataStrategyGetMetaData(
        string $strategyClass,
        string $modelClass,
        array $expectedAttributes,
        array $expectedPrimaryKey,
        string $expectedIdentity
    ): void {
        $strategy = new $strategyClass();
        $model    = new $modelClass();

        $metaData = $strategy->getMetaData($model, $this->container);

        $this->assertSame($expectedAttributes, $metaData[MetaData::MODELS_ATTRIBUTES]);
        $this->assertSame($expectedPrimaryKey, $metaData[MetaData::MODELS_PRIMARY_KEY]);
        $this->assertSame($expectedIdentity, $metaData[MetaData::MODELS_IDENTITY_COLUMN]);
    }
}
