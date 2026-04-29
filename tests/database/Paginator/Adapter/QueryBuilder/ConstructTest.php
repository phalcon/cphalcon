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

namespace Phalcon\Tests\Database\Paginator\Adapter\QueryBuilder;

use PDO;
use Phalcon\Paginator\Adapter\AdapterInterface;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use stdClass;

final class ConstructTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testPaginatorAdapterQuerybuilderConstruct(): void
    {
        $manager = $this->getService('modelsManager');

        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 5,
                'page'    => 1,
            ]
        );

        $this->assertInstanceOf(QueryBuilder::class, $paginator);
        $this->assertInstanceOf(AdapterInterface::class, $paginator);
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: __construct() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testPaginatorAdapterQuerybuilderConstructException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Parameter 'builder' must be an instance of Phalcon\Mvc\Model\Query\Builder"
        );

        $paginator = new QueryBuilder(
            [
                'builder' => new stdClass(),
                'limit'   => 10,
                'page'    => 1,
            ]
        );
    }
}
