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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesExtended;

use function uniqid;

/**
 * Class FindFirstCest
 */
class FindFirstCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration = new InvoicesMigration($connection);
        $migration->clear();
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirst(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst()');

        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration = new InvoicesMigration($connection);
        $migration->insert(4, $title);

        $invoice = Invoices::findFirst();

        $I->assertInstanceOf(
            Invoices::class,
            $invoice
        );

        $I->assertEquals(
            4,
            $invoice->inv_id
        );

        $invoice = Invoices::findFirst(null);

        $I->assertInstanceOf(
            Invoices::class,
            $invoice
        );

        $I->assertEquals(
            4,
            $invoice->inv_id
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - not found
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstNotFound(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - not found');

        $robot = Invoices::findFirst(
            [
                'conditions' => 'inv_id < 0',
            ]
        );

        $I->assertNull($robot);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirstBy() - not found
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstByNotFound(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirstBy() - not found');

        $I->assertNull(
            Invoices::findFirstByInvTitle('unknown')
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - extended
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstExtended(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - extended');

        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration = new InvoicesMigration($connection);
        $migration->insert(4, $title);

        $invoice = InvoicesExtended::findFirst(4);

        $I->assertInstanceOf(
            InvoicesExtended::class,
            $invoice
        );

        $I->assertEquals(4, $invoice->inv_id);

        $invoice = InvoicesExtended::findFirst(0);
        $I->assertNull($invoice);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindFirstException(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - exception');

        $I->expectThrowable(
            new Exception(
                'Parameters passed must be of type array, string, numeric or null'
            ),
            function () {
                Invoices::findFirst(false);
            }
        );
    }
}
