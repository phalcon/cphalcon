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

namespace Phalcon\Tests\Database\Paginator\Adapter\QueryBuilderCursor;

use PDO;
use Phalcon\Paginator\Adapter\AdapterInterface;
use Phalcon\Paginator\Adapter\QueryBuilderCursor;
use Phalcon\Paginator\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorConstruct(): void
    {
        $manager = $this->getService('modelsManager');

        $builder = $manager
            ->createBuilder()
            ->from(Invoices::class)
            ->orderBy('inv_id')
        ;

        $paginator = new QueryBuilderCursor(
            [
                'builder'      => $builder,
                'limit'        => 5,
                'cursorColumn' => 'inv_id',
            ]
        );

        $this->assertInstanceOf(QueryBuilderCursor::class, $paginator);
        $this->assertInstanceOf(AdapterInterface::class, $paginator);
        $this->assertNull($paginator->getCursor());
        $this->assertSame('inv_id', $paginator->getCursorColumn());
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: __construct() -
     * exception empty cursorColumn
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorConstructExceptionEmptyCursorColumn(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Parameter 'cursorColumn' must be a non-empty string"
        );

        $manager = $this->getService('modelsManager');

        new QueryBuilderCursor(
            [
                'builder'      => $manager->createBuilder()->from(Invoices::class),
                'limit'        => 10,
                'cursorColumn' => '',
            ]
        );
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: __construct() -
     * exception invalid builder type
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorConstructExceptionInvalidBuilder(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Parameter 'builder' must be an instance of Phalcon\Mvc\Model\Query\Builder"
        );

        new QueryBuilderCursor(
            [
                'builder'      => new stdClass(),
                'limit'        => 10,
                'cursorColumn' => 'inv_id',
            ]
        );
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: __construct() -
     * exception missing cursorColumn
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorConstructExceptionMissingCursorColumn(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Parameter 'cursorColumn' is required");

        $manager = $this->getService('modelsManager');

        new QueryBuilderCursor(
            [
                'builder' => $manager->createBuilder()->from(Invoices::class),
                'limit'   => 10,
            ]
        );
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilderCursor :: __construct() -
     * exception missing limit
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testPaginatorAdapterQuerybuilderCursorConstructExceptionMissingLimit(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Parameter 'limit' is required");

        $manager = $this->getService('modelsManager');

        new QueryBuilderCursor(
            [
                'builder'      => $manager->createBuilder()->from(Invoices::class),
                'cursorColumn' => 'inv_id',
            ]
        );
    }
}
