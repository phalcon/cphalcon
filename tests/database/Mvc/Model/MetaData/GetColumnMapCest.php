<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\MetaData;

use DatabaseTester;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\InvoicesMap;

/**
 * Class GetColumnMapCest
 */
class GetColumnMapCest
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @param  DatabaseTester $I
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }

        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getColumnMap()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelMetadataGetColumnMap(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData - getColumnMap()');

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');
        $model    = new Invoices();

        $I->assertNull($metadata->getColumnMap($model));

        $model    = new InvoicesMap();
        $expected = [
            'inv_id'          => 'id',
            'inv_cst_id'      => 'cst_id',
            'inv_status_flag' => 'status_flag',
            'inv_title'       => 'title',
            'inv_total'       => 'total',
            'inv_created_at'  => 'created_at',
        ];

        $I->assertEquals($expected, $metadata->getColumnMap($model));
    }
}
