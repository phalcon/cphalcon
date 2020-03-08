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

use Codeception\Example;
use DatabaseTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Migrations\StringPrimaryMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesExtended;
use Phalcon\Test\Models\ModelWithStringPrimary;

use function uniqid;

/**
 * Class FindFirstCest
 */
class FindFirstCest
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
     * Tests Phalcon\Mvc\Model :: findFirst()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelFindFirst(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst()');

        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

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
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelFindFirstNotFound(DatabaseTester $I)
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
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelFindFirstByNotFound(DatabaseTester $I)
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
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelFindFirstExtended(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - extended');

        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

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
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelFindFirstException(DatabaseTester $I)
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

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - exception
     *
     * @dataProvider findFirstProvider
     *
     * @param DatabaseTester $I
     * @param Example        $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-27
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelFindFirstStringPrimaryKey(DatabaseTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model - findFirst() - string primary key');

        $connection = $I->getConnection();
        $migration  = new StringPrimaryMigration($connection);
        $migration->insert(
            '5741bfd7-6870-40b7-adf6-cbacb515b9a9',
            1
        );
        $migration->insert(
            '1c53079c-249e-0c63-af8d-52413bfa2a2b',
            2
        );

        $model = ModelWithStringPrimary::findFirst($example['params']);

        $I->assertSame($example['found'], $model instanceof Model);
    }

    /**
     * @return array
     */
    protected function findFirstProvider(): array
    {
        return [
            [
                'params' => [
                    'uuid = ?0',
                    'bind' => ['5741bfd7-6870-40b7-adf6-cbacb515b9a9'],
                ],
                'found'  => true,
            ],
            [
                'params' => [
                    'uuid = ?0',
                    'bind' => ['1c53079c-249e-0c63-af8d-52413bfa2a2b'],
                ],
                'found'  => true,
            ],
            [
                'params' => [
                    'uuid = ?0',
                    'bind' => ['1c53079c-249e-0c63-af8d-52413bfa2a2c'],
                ],
                'found'  => false,
            ],
            [
                'params' => '134',
                'found'  => false,
            ],
            [
                'params' => "uuid = '134'",
                'found'  => false,
            ],
        ];
    }
}
