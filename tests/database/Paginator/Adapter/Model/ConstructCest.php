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

namespace Phalcon\Test\Database\Paginator\Adapter\Model;

use DatabaseTester;
use Phalcon\Paginator\Adapter\Model;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;

use function uniqid;

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
     * Tests Phalcon\Paginator\Adapter\Model :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function paginatorAdapterModelConstruct(DatabaseTester $I)
    {
        $I->wantToTest('Paginator\Adapter\Model - __construct()');

        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

        $paginator = new Model(
            [
                'model' => Invoices::class,
                'limit' => 10,
                'page'  => 1,
            ]
        );

        $I->assertInstanceOf(Model::class, $paginator);
    }
}
