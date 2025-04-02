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
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\InvoicesMap;
use Phalcon\Tests\Models\Manufacturer;

/**
 * Class CloneResultMapCest
 */
class CloneResultMapCest
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
     * Tests Phalcon\Mvc\Model :: cloneResultMap()
     *
     * @dataProvider modelDataProvider
     *
     * @param DatabaseTester $I
     * @param Example        $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-10-05
     *
     * @group        mysql
     * @group        pgsql
     * @group        sqlite
     */
    public function cloneResultMap(DatabaseTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model - cloneResultMap()');

        $base = new InvoicesMap();

        /**
         * @var Model\MetaData $metaData
         */
        $metaData = $base->getModelsMetaData();

        $columnMap = $metaData->getColumnMap($base);

        $data = [
            'inv_id'          => $example['inv_id'],
            'inv_cst_id'      => $example['inv_cst_id'],
            'inv_status_flag' => $example['inv_status_flag'],
            'inv_title'       => $example['inv_title'],
            'inv_total'       => $example['inv_total'],
            'inv_created_at'  => $example['inv_created_at']
        ];

        /**
         * @var InvoicesMap $invoice
         */
        $invoice = Model::cloneResultMap(
            $base,
            $data,
            $columnMap
        );

        $expected = array_combine(
            $columnMap,
            $data
        );

        $I->assertEquals(
            $expected,
            $invoice->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: cloneResultMap() with casting
     *
     * @dataProvider modelDataProvider
     *
     * @param DatabaseTester $I
     * @param Example        $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-10-05
     *
     * @group        mysql
     * @group        pgsql
     */
    public function cloneResultMapWithCasting(DatabaseTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model - cloneResultMap() - with casting');

        $base = new InvoicesMap();

        /**
         * @var Model\MetaData $metaData
         */
        $metaData = $base->getModelsMetaData();

        $columnMap = $metaData->getColumnMap($base);

        /**
         * $dataTypes = [
         *   'inv_id'          => Column::TYPE_INTEGER,
         *   'inv_cst_id'      => Column::TYPE_INTEGER,
         *   'inv_status_flag' => Column::TYPE_TINYINTEGER,
         *   'inv_title'       => Column::TYPE_VARCHAR,
         *   'inv_total'       => Column::TYPE_FLOAT,
         *   'inv_created_at'  => Column::TYPE_DATETIME
         * ];
         */
        $dataTypes = $metaData->getDataTypes($base);

        /**
         * Assemble typed column map
         */
        foreach ($columnMap as $mappedField => $field) {
            $typedColumnMap[$mappedField] = [
                $field,
                $dataTypes[$mappedField]
            ];
        }

        /**
         * @var InvoicesMap $invoice
         */
        $invoice = Model::cloneResultMap(
            $base,
            [
                'inv_id'          => $example['inv_id'],
                'inv_cst_id'      => $example['inv_cst_id'],
                'inv_status_flag' => $example['inv_status_flag'],
                'inv_title'       => $example['inv_title'],
                'inv_total'       => $example['inv_total'],
                'inv_created_at'  => $example['inv_created_at']
            ],
            $typedColumnMap
        );

        $I->assertIsInt(
            $invoice->id
        );

        $I->assertEquals(
            (int)$example['inv_id'],
            $invoice->id
        );

        $I->assertIsInt(
            $invoice->cst_id
        );

        $I->assertEquals(
            (int)$example['inv_cst_id'],
            $invoice->cst_id
        );

        $I->assertIsInt(
            $invoice->status_flag
        );

        $I->assertEquals(
            (int)$example['inv_status_flag'],
            $invoice->status_flag
        );

        $I->assertIsString(
            $invoice->title
        );

        $I->assertEquals(
            $example['inv_title'],
            $invoice->title
        );

        $I->assertIsFloat(
            $invoice->total
        );

        $I->assertIsString(
            $invoice->created_at
        );

        $I->assertEquals(
            $example['inv_created_at'],
            $invoice->created_at
        );
    }    
    
    /**
    * Tests Phalcon\Mvc\Model :: cloneResultMapModelTyped()
    *
    * @dataProvider modelManufactureDataProvider
    *
    * @param DatabaseTester $I
    * @param Example        $example
    *
    * @author       Phalcon Team <team@phalcon.io>
    * @since        2020-10-05
    *
    * @group        mysql
    * @group        pgsql
    * @group        sqlite
    */
   public function cloneResultMapModelTyped(DatabaseTester $I, Example $example)
   {
       $I->wantToTest('Mvc\Model - cloneResultMapModelTyped() - with model arguments typed');

       $base = new Manufacturer();

       /**
        * @var Model\MetaData $metaData
        */
       $metaData = $base->getModelsMetaData();
       $columnMap = $metaData->getColumnMap($base);

       $data = [
           'id'             => $example['id'],
           'name'           => $example['name'],
           'country'        => $example['country'],
           'founded_year'   => $example['founded_year'],
       ];

       $data = array_filter($data);

       /**
        * @var Manufacturer $manufacturer
        */
       $manufacturer = Model::cloneResultMap(
           $base,
           $data,
           $columnMap
       );

       
       if ($example['founded_year'] === null) {
            $I->expectThrowable(
                \Error::class,
                function () use ($manufacturer) {
                    $manufacturer->founded_year;
                }
            );
       } else {
           $I->assertEquals(
               $example['founded_year'],
               $manufacturer->founded_year
           );
       }
       
       if ($example['country'] === null) {
            $I->assertEquals(
                [
                    'id' => $example['id'],
                    'name' => $example['name'],
                    'country' => 'UK',
                    'founded_year' => $example['founded_year'],
                ],
                $manufacturer->toArray()
            );
       } else {
            $I->assertEquals(
                [
                    'id' => $example['id'],
                    'name' => $example['name'],
                    'country' => $example['country'],
                    'founded_year' => $example['founded_year'],
                ],
                $manufacturer->toArray()
            );
       }
   }

    /**
     * @return array
     */
    protected function modelDataProvider(): array
    {
        return [
            [
                'inv_id'          => '1',
                'inv_cst_id'      => '42',
                'inv_status_flag' => '1',
                'inv_title'       => 'Test title',
                'inv_total'       => '3.14',
                'inv_created_at'  => '2020-10-05 20:43',
            ],
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 42,
                'inv_status_flag' => 1,
                'inv_title'       => 'Test title',
                'inv_total'       => 3.14,
                'inv_created_at'  => '2020-10-05 20:43',
            ]
        ];
    }

    /**
     * @return array
     */
    protected function modelManufactureDataProvider(): array
    {
        return [
            [
                'id'           => 1,
                'name'         => 'Test Manufacturer',
                'founded_year' => 1990,
                'country'      => 'UK'
            ],
            [
                'id'           => 2,
                'name'         => 'Another Manufacturer',
                'founded_year' => 2000,
                'country'      => null
            ],
            [
                'id'           => 3,
                'name'         => 'Third Manufacturer',
                'founded_year' => null,
                'country'      => 'CA'
            ]

        ];
    }
}
