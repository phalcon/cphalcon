<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\InvoicesSchemaSwitchable;
use Phalcon\Tests\Support\Traits\DiTrait;

use function env;
use function sprintf;

/**
 * @group phql
 */
final class ParseDynamicSchemaTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        Query::clean();
    }

    /**
     * The PHQL intermediate cache is keyed by the PHQL string only. When a
     * model changes its schema at runtime the second query for the same
     * PHQL must still target the new schema instead of returning the SQL
     * that was baked in at first parse.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17020
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     *
     * @group  mysql
     */
    public function testMvcModelQueryParseRefreshesSchemaAfterCacheHit(): void
    {
        $manager      = $this->container->get('modelsManager');
        $defaultName  = (string) env('DATA_MYSQL_NAME');
        $secondSchema = $defaultName . '_alt';

        /**
         * Loading the model triggers initialize() once, which calls
         * setSchema(DATA_MYSQL_NAME) on this class.
         */
        $manager->load(InvoicesSchemaSwitchable::class);

        $phql = sprintf(
            'SELECT [%s].* FROM [%s]',
            InvoicesSchemaSwitchable::class,
            InvoicesSchemaSwitchable::class
        );

        $firstQuery = new Query($phql, $this->container);
        $firstSql   = $firstQuery->getSql()['sql'];

        $this->assertStringContainsString(
            sprintf('`%s`.`co_invoices`', $defaultName),
            $firstSql
        );

        /**
         * Switch the schema. The cached intermediate representation
         * still has the original schema baked in. With the fix in place,
         * parse() refreshes the source/schema before returning.
         */
        $model = $manager->load(InvoicesSchemaSwitchable::class);
        $model->switchSchema($secondSchema);

        $secondQuery = new Query($phql, $this->container);
        $secondSql   = $secondQuery->getSql()['sql'];

        $this->assertStringContainsString(
            sprintf('`%s`.`co_invoices`', $secondSchema),
            $secondSql
        );
        $this->assertStringNotContainsString(
            sprintf('`%s`.`co_invoices`', $defaultName),
            $secondSql
        );
    }
}
