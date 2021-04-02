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

namespace Phalcon\Test\Database\Mvc\Model;

use DatabaseTester;
use PDO;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;

use function uniqid;

class RefreshCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model :: refresh()
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelRefresh(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - refresh()');

        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

        $invoice = Invoices::findFirst();
        $data    = $invoice->toArray();

        $invoice->assign(
            [
                'inv_id'          => 4,
                'inv_cst_id'      => 5,
                'inv_status_flag' => 6,
                'inv_total'       => 200.12,
            ]
        );

        $invoice->refresh();

        $I->assertEquals(
            $data,
            $invoice->toArray()
        );
    }
}
