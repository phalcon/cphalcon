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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query\Exceptions\AmbiguousJoinRelation;
use Phalcon\Mvc\Model\Query\Exceptions\RelationshipNotFound;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\ObjectsMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use Phalcon\Tests\Support\Models\Objects;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * WITH names a model instead of a relation alias.
 *
 * The alias lookup misses, so the query falls back to the lookup by model
 * pair. That lookup gives back an array of relations, never one object.
 *
 * @see https://github.com/phalcon/cphalcon/issues/17554
 */
#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class EagerRelationFallbackTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        new CustomersMigration(self::getPdoConnection());
        new InvoicesMigration(self::getPdoConnection());
        new ObjectsMigration(self::getPdoConnection());
    }

    /**
     * Two or more relations between the same pair of models cannot be
     * resolved without an alias.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelQueryEagerRelationAmbiguousThrows(): void
    {
        $manager = $this->container->get('modelsManager');

        $query = $manager->createQuery(
            'SELECT * FROM ' . Customers::class . ' WITH ' . Invoices::class
        );

        $this->expectException(AmbiguousJoinRelation::class);
        $this->expectExceptionMessage('There is more than one relation between models');

        $query->parse();
    }

    /**
     * A model with no relation at all still reports that it was not found.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelQueryEagerRelationNotFoundThrows(): void
    {
        $manager = $this->container->get('modelsManager');

        $query = $manager->createQuery(
            'SELECT * FROM ' . Invoices::class . ' WITH ' . Objects::class
        );

        $this->expectException(RelationshipNotFound::class);
        $this->expectExceptionMessage('Cannot find a relationship between');

        $query->parse();
    }

    /**
     * A model named in WITH resolves through the by-model-pair lookup when
     * the relation carries an alias.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelQueryEagerRelationResolvesByModelName(): void
    {
        $manager = $this->container->get('modelsManager');

        $query = $manager->createQuery(
            'SELECT * FROM ' . InvoicesBelongsToCustomers::class
            . ' WITH ' . Customers::class
        );

        $intermediate = $query->parse();

        $this->assertIsArray($intermediate);
        $this->assertArrayHasKey('joins', $intermediate);
        $this->assertCount(1, $intermediate['joins']);

        $expected = Customers::class;
        $actual   = $intermediate['joins'][0]['source'][0];
        $this->assertSame('co_customers', $actual);

        $columns = $intermediate['columns'];
        $eager   = array_filter(
            $columns,
            function ($column) {
                return isset($column['eager']);
            }
        );
        $this->assertNotEmpty($eager);
    }
}
