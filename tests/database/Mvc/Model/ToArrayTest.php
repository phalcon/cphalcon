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

use PDO;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesGetters;
use Phalcon\Tests\Support\Models\InvoicesMap;
use Phalcon\Tests\Support\Traits\DiTrait;

use function date;
use function getOptionsMysql;
use function uniqid;

/**
 *
 * @group phql
 */
final class ToArrayTest extends AbstractDatabaseTestCase
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @group mysql
     */
    public function testMvcModelToArray(): void
    {
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
        $this->assertEquals($expected, $actual);

        $expected = [];
        $actual   = $invoice->toArray(['unknown']);
        $this->assertEquals($expected, $actual);

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
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @group mysql
     */
    public function testMvcModelToArrayColumnMap(): void
    {
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
        $this->assertEquals($expected, $actual);

        $expected = $data;
        $actual   = $invoice->toArray();
        $this->assertEquals($expected, $actual);

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
        $this->assertEquals($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/16467
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-21
     *
     * @group mysql
     */
    public function testMvcModelToArrayExecuteColumnNotInColumnMap(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $title      = uniqid('inv-');
        $date       = date('Y-m-d H:i:s');

        $migration = new InvoicesMigration($connection);
        $migration->insert(4, 1, 0, $title, 111.26, $date);
        $migration->insert(5, 2, 1, $title, 222.19, $date);

        $manager = $this->getService('modelsManager');
        $class   = Manager::class;
        $this->assertInstanceOf($class, $manager);


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
        $actual   = $result->toArray();
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/15361
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @group mysql
     */
    public function testMvcModelToArrayFindCastOnHydrateForceCasting(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $title      = uniqid('inv-');
        $date       = date('Y-m-d H:i:s');

        $migration = new InvoicesMigration($connection);
        $migration->insert(4, 1, 0, $title, 111.26, $date);
        $migration->insert(5, 2, 1, $title, 222.19, $date);

        $options            = getOptionsMysql();
        $options['options'] = [
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
        $this->assertEquals($expected, $actual);

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
        $this->assertSame($expected, $actual);

        $db->close();

        Invoices::setup(
            [
                'forceCasting'  => false,
                'castOnHydrate' => false,
            ]
        );
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1701
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelToArrayFindFirstColumns(): void
    {
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
        $this->assertNotFalse($result);

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
        $this->assertEquals($expected, $actual);
    }

    /**
     * @issue  #11922
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelToArrayModelWithGetters(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $title      = uniqid('inv-');
        $date       = date('Y-m-d H:i:s');

        $migration = new InvoicesMigration($connection);
        $migration->insert(4, 1, 0, $title, 111.26, $date);

        $model = InvoicesGetters::findFirst(4);

        $class = InvoicesGetters::class;
        $this->assertInstanceOf($class, $model);

        $expected = 4;
        $actual   = $model->inv_id;
        $this->assertEquals($expected, $actual);

        $expected = [
            'inv_id'          => '4',
            'inv_cst_id'      => '1',
            'inv_status_flag' => '0',
            'inv_title'       => $title . '!4',
            'inv_total'       => '111.26',
            'inv_created_at'  => $date,
        ];

        $actual = $model->toArray();
        /**
         * assertEquals here because sqlite returns strings in different
         * PHP versions
         */
        $this->assertEquals($expected, $actual);

        $expected = [
            'inv_id'          => '4',
            'inv_cst_id'      => '1',
            'inv_status_flag' => '0',
            'inv_title'       => $title,
            'inv_total'       => '111.26',
            'inv_created_at'  => $date,
        ];
        $actual   = $model->toArray(null, false);
        $this->assertEquals($expected, $actual);
    }

    /**
     * @issue  #11922
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelToArrayModelWithGettersSerialize(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $title      = uniqid('inv-');
        $date       = date('Y-m-d H:i:s');

        $migration = new InvoicesMigration($connection);
        $migration->insert(4, 1, 0, $title, 111.26, $date);

        $model = InvoicesGetters::findFirst(4);

        $class = InvoicesGetters::class;
        $this->assertInstanceOf($class, $model);

        $expected = 4;
        $actual   = $model->inv_id;
        $this->assertEquals($expected, $actual);

        /**
         * assertEquals here because sqlite returns strings in different
         * PHP versions
         */

        $serialize   = $model->serialize();
        $unserialize = new InvoicesGetters();
        $unserialize->unserialize($serialize);
        $this->assertEquals($title, $unserialize->inv_title);
    }
}
