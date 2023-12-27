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

use DatabaseTester;
use PDO;
use Phalcon\Db\Adapter\AbstractAdapter;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\models\InvoicesGetters;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\InvoicesMap;

use function date;
use function getOptionsMysql;
use function phpversion;
use function uniqid;
use function version_compare;

use const PHP_VERSION;

class ToArrayCest
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
     * Tests Phalcon\Mvc\Model :: toArray()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelToArray(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray()');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');

        $data = [
            'inv_id'          => 1,
            'inv_cst_id'      => 5,
            'inv_status_flag' => 2,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);

        $expected = $data;
        $actual   = $invoice->toArray();
        $I->assertEquals($expected, $actual);

        $expected = [];
        $actual   = $invoice->toArray(['unknown']);
        $I->assertEquals($expected, $actual);

        $expected = $data;
        unset($expected['inv_created_at']);
        unset($expected['inv_total']);
        $actual = $invoice->toArray(
            [
                'inv_id',
                'inv_cst_id',
                'inv_status_flag',
                'inv_title',
            ]
        );
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: toArray() - column map
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelToArrayColumnMap(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray() - column map');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');

        $data = [
            'id'          => 4,
            'cst_id'      => 5,
            'status_flag' => 2,
            'title'       => $title,
            'total'       => 100.12,
            'created_at'  => $date,
        ];

        $invoice = new InvoicesMap();
        $invoice->assign($data);

        $expected = [];
        $actual   = $invoice->toArray(['unknown']);
        $I->assertEquals($expected, $actual);

        $expected = $data;
        $actual   = $invoice->toArray();
        $I->assertEquals($expected, $actual);

        $expected = $data;
        unset($expected['created_at']);
        unset($expected['total']);
        $actual = $invoice->toArray(
            [
                'id',
                'cst_id',
                'status_flag',
                'title',
            ]
        );
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: toArray() - find first columns
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @issue https://github.com/phalcon/cphalcon/issues/1701
     *
     * @group  mysql
     * @group  sqlite
     */
    public function mvcModelToArrayFindFirstColumns(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray() - find first columns');

        $title = uniqid('inv-');
        $date  = date('Y-m-d H:i:s');

        $data = [
            'inv_id'          => 4,
            'inv_cst_id'      => 5,
            'inv_status_flag' => 2,
            'inv_title'       => $title,
            'inv_total'       => 100.12,
            'inv_created_at'  => $date,
        ];

        $invoice = new Invoices();
        $invoice->assign($data);
        $result = $invoice->save();
        $I->assertNotFalse($result);

        $invoice = Invoices::findFirst(
            [
                'columns' => 'inv_id, inv_cst_id, inv_title',
                'inv_title = "' . $title . '"',
            ]
        );

        $expected = [
            'inv_id'     => 4,
            'inv_cst_id' => 5,
            'inv_title'  => $title,
        ];
        $actual   = $invoice->toArray();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: toArray() - find - castOnHydrate/forceCasting
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @issue https://github.com/phalcon/cphalcon/issues/15361
     *
     * @group  mysql
     */
    public function mvcModelToArrayFindCastOnHydrateForceCasting(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray() - find - castOnHydrate/forceCasting');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $title      = uniqid('inv-');
        $date       = date('Y-m-d H:i:s');

        $migration = new InvoicesMigration($connection);
        $migration->insert(4, 1, 0, $title, 111.26, $date);
        $migration->insert(5, 2, 1, $title, 222.19, $date);

        $options = getOptionsMysql();
        $options['persistent'] = true;
        $options['options']    = [
            PDO::ATTR_EMULATE_PREPARES  => false,
            PDO::ATTR_STRINGIFY_FETCHES => false,
        ];

        $db = (new PdoFactory())->newInstance('mysql', $options);
        $this->container->set('db', $db);

        $invoices = Invoices::findFirst();

        $expected = [
            'inv_id'          => 4,
            'inv_cst_id'      => 1,
            'inv_status_flag' => 0,
            'inv_title'       => $title,
            'inv_total'       => 111.26,
            'inv_created_at'  => $date,
        ];
        $actual   = $invoices->toArray();
        $I->assertEquals($expected, $actual);

        $invoices = Invoices::find();

        $expected = [
            [
                'inv_id'          => 4,
                'inv_cst_id'      => 1,
                'inv_status_flag' => 0,
                'inv_title'       => $title,
                'inv_total'       => 111.26,
                'inv_created_at'  => $date,
            ],
            [
                'inv_id'          => 5,
                'inv_cst_id'      => 2,
                'inv_status_flag' => 1,
                'inv_title'       => $title,
                'inv_total'       => 222.19,
                'inv_created_at'  => $date,
            ],
        ];
        $actual   = $invoices->toArray();
        $I->assertSame($expected, $actual);

        Invoices::setup(
            [
                'forceCasting'  => false,
                'castOnHydrate' => false,
            ]
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: toArray() - execute column not in columnMap
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-21
     *
     * @issue https://github.com/phalcon/cphalcon/issues/16467
     *
     * @group  mysql
     */
    public function mvcModelToArrayExecuteColumnNotInColumnMap(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray() - execute - column not in columnMap');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $title      = uniqid('inv-');
        $date       = date('Y-m-d H:i:s');

        $migration = new InvoicesMigration($connection);
        $migration->insert(4, 1, 0, $title, 111.26, $date);
        $migration->insert(5, 2, 1, $title, 222.19, $date);

        $manager = $this->getService('modelsManager');
        $class   = Manager::class;
        $I->assertInstanceOf($class, $manager);


        $result = $manager
            ->createBuilder()
            ->addFrom(InvoicesMap::class, 'i')
            ->limit(10)
            ->getQuery()
            ->execute()
        ;

        $result->rewind();
        $result->next();
        $result->rewind();

        /**
         * This needs to be here because of how PDO works in PHP 8.0 vs 8.1+
         */
        if (version_compare(PHP_VERSION, '8.1.0', '<')) {
            // PHP 8.0.x
            $expected = [
                [
                    'id'          => '4',
                    'cst_id'      => '1',
                    'status_flag' => '0',
                    'title'       => $title,
                    'total'       => '111.26',
                    'created_at'  => $date,
                ],
                [
                    'id'          => '5',
                    'cst_id'      => '2',
                    'status_flag' => '1',
                    'title'       => $title,
                    'total'       => '222.19',
                    'created_at'  => $date,
                ],
            ];
        } else {
            // PHP 8.1.x+
            $expected = [
                [
                    'id'          => 4,
                    'cst_id'      => 1,
                    'status_flag' => 0,
                    'title'       => $title,
                    'total'       => 111.26,
                    'created_at'  => $date,
                ],
                [
                    'id'          => 5,
                    'cst_id'      => 2,
                    'status_flag' => 1,
                    'title'       => $title,
                    'total'       => 222.19,
                    'created_at'  => $date,
                ],
            ];
        }
        $actual   = $result->toArray();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\ :: save() with property source
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     * @issue  #11922
     *
     * @group  mysql
     * @group  sqlite
     */
    public function mvcModelToArrayModelWithGetters(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray - model with getters');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $title      = uniqid('inv-');
        $date       = date('Y-m-d H:i:s');

        $migration = new InvoicesMigration($connection);
        $migration->insert(4, 1, 0, $title, 111.26, $date);

        $model = InvoicesGetters::findFirst(4);

        $class = InvoicesGetters::class;
        $I->assertInstanceOf($class, $model);

        $expected = 4;
        $actual   = $model->inv_id;
        $I->assertEquals($expected, $actual);

        $expected = [
            'inv_id'          => '4',
            'inv_cst_id'      => '1',
            'inv_status_flag' => '0',
            'inv_title'       => $title . '!4',
            'inv_total'       => '111.26',
            'inv_created_at'  => $date,
        ];

        $actual   = $model->toArray();
        /**
         * assertEquals here because sqlite returns strings in different
         * PHP versions
         */
        $I->assertEquals($expected, $actual);
    }
}
