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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Db\Exceptions\InvalidSqlExpression;
use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;
use PHPUnit\Framework\Attributes\Group;

use function sprintf;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ParseTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use ErrorHandlerTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        new InvoicesMigration(self::getPdoConnection());
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: parse()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryParse(): void
    {
        $manager = $this->container->get('modelsManager');

        $query        = $manager->createQuery('SELECT * FROM ' . Invoices::class);
        $intermediate = $query->parse();

        $this->assertIsArray($intermediate);
        $this->assertArrayHasKey('models', $intermediate);
    }

    /**
     * A second query with the same PHQL gets the intermediate representation
     * from the cache. getIntermediate() must return it.
     *
     * Tests Phalcon\Mvc\Model\Query :: parse() - cache hit
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testMvcModelQueryParseCacheHitSetsIntermediate(): void
    {
        $phql = sprintf('SELECT inv_id FROM [%s] WHERE inv_id = 1', Invoices::class);

        Query::clean();

        $first = new Query($phql, $this->container);
        $first->parse();

        $second = new Query($phql, $this->container);
        $second->parse();

        $this->assertSame($first->getIntermediate(), $second->getIntermediate());
    }

    /**
     * The enable_implicit_joins option changes the intermediate
     * representation. A query must not get a cached representation that was
     * built with the other value of the option.
     *
     * With implicit joins disabled, a join with no ON condition is not valid
     * and the query fails. The next query, with implicit joins enabled, must
     * get the condition from the relation.
     *
     * Tests Phalcon\Mvc\Model\Query :: parse() - cache and implicit joins
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testMvcModelQueryParseCacheKeepsImplicitJoins(): void
    {
        $phql = sprintf(
            'SELECT i.inv_id, c.cst_id FROM [%s] AS i JOIN [%s] AS c',
            InvoicesBelongsToCustomers::class,
            Customers::class
        );

        Query::clean();

        try {
            (new Query($phql, $this->container, ['enable_implicit_joins' => false]))->getSql();
            $this->fail('The query with implicit joins disabled must fail');
        } catch (InvalidSqlExpression) {
            // The join has no condition.
        }

        $actual = (new Query($phql, $this->container))->getSql();

        $this->assertStringContainsString(' ON ', $actual['sql']);
    }

    /**
     * With implicit joins disabled, a join with no ON condition throws
     * InvalidSqlExpression. There is no "Undefined array key" warning.
     *
     * Tests Phalcon\Mvc\Model\Query :: parse() - join with no condition
     *
     * @issue  https://github.com/phalcon/phalcon/issues/816
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testMvcModelQueryParseJoinNoCondition(): void
    {
        $phql      = sprintf(
            'SELECT i.inv_id, c.cst_id FROM [%s] AS i JOIN [%s] AS c',
            Invoices::class,
            Customers::class
        );
        $container = $this->container;

        Query::clean();

        [$actual, $messages] = $this->collectErrors(
            static function () use ($phql, $container): string {
                try {
                    (new Query($phql, $container, ['enable_implicit_joins' => false]))->getSql();
                } catch (InvalidSqlExpression $ex) {
                    return $ex::class;
                }

                return 'no exception';
            }
        );

        $this->assertSame(InvalidSqlExpression::class, $actual);
        $this->assertSame([], $messages);
    }
}
