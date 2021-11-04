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

namespace Phalcon\Tests\Database\Mvc\Model;

use Codeception\Example;
use DatabaseTester;
use PDO;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Migrations\StringPrimaryMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\InvoicesExtended;
use Phalcon\Tests\Models\InvoicesMap;
use Phalcon\Tests\Models\ModelWithStringPrimary;

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
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
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

        $class = Invoices::class;
        $actual = $invoice;
        $I->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $I->assertEquals($expected, $actual);

        $invoice = Invoices::findFirst(null);

        $class = Invoices::class;
        $actual = $invoice;
        $I->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelFindFirstColumnMap(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - with column map');

        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

        $invoice = InvoicesMap::findFirst();

        $class  = InvoicesMap::class;
        $actual = $invoice;
        $I->assertInstanceOf($class, $invoice);

        $expected = 4;
        $actual   = $invoice->id;
        $I->assertEquals($expected, $actual);

        $expected = $title;
        $actual   = $invoice->title;
        $I->assertEquals($expected, $actual);

        $invoice = InvoicesMap::findFirst(null);

        $class  = InvoicesMap::class;
        $actual = $invoice;
        $I->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->id;
        $I->assertEquals($expected, $actual);

        $expected = $title;
        $actual   = $invoice->title;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - not found
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelFindFirstNotFound(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirst() - not found');

        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_id < 0',
            ]
        );

        $I->assertNull($invoice);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirstBy() - not found
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelFindFirstByNotFound(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - findFirstBy() - not found');

        $actual = Invoices::findFirstByInvTitle('unknown');
        $I->assertNull($actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - extended
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
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

        $class = InvoicesExtended::class;
        $actual = $invoice;
        $I->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $I->assertEquals($expected, $actual);

        $invoice = InvoicesExtended::findFirst(0);
        $I->assertNull($invoice);
    }

    /**
     * Tests Phalcon\Mvc\Model :: findFirst() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
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
     * Tests Phalcon\Mvc\Model :: findFirst() - option 'column'
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-11-22
     * @issue  https://github.com/phalcon/cphalcon/issues/15356
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     *
     * @param DatabaseTester $I
     */
    public function mvcModelFindFirstColumn(DatabaseTester $I): void
    {
        $I->wantToTest('Mvc\Model - findFirst() - column option');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4);

        $invoice = Invoices::findFirst(
            [
                'columns' => 'inv_id',
            ]
        );

        $class = Row::class;
        $actual = $invoice;
        $I->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $I->assertEquals($expected, $actual);

        $expected = ['inv_id' => 4];
        $actual   = $invoice->toArray();
        $I->assertEquals($expected, $actual);
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
     * @group        mysql
     * @group        pgsql
     * @group        sqlite
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
