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

namespace Phalcon\Test\Database\Paginator\Adapter\QueryBuilder;

use DatabaseTester;
use Phalcon\Paginator\Adapter\AdapterInterface;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\Exception;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;
use stdClass;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function paginatorAdapterQuerybuilderConstruct(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - __construct()');

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

        $I->assertInstanceOf(QueryBuilder::class, $paginator);
        $I->assertInstanceOf(AdapterInterface::class, $paginator);
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: __construct() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function paginatorAdapterQuerybuilderConstructException(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - __construct() - exception');

        $I->expectThrowable(
            new Exception(
                "Parameter 'builder' must be an instance " .
                "of Phalcon\Mvc\Model\Query\Builder"
            ),
            function () {
                $paginator = new QueryBuilder(
                    [
                        'builder' => new stdClass(),
                        'limit'   => 10,
                        'page'    => 1,
                    ]
                );
            }
        );
    }
}
