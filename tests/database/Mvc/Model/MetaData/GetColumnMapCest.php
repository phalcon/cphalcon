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

namespace Phalcon\Test\Database\Mvc\Model\MetaData;

use DatabaseTester;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesMap;

/**
 * Class GetColumnMapCest
 */
class GetColumnMapCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getColumnMap()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function mvcModelMetadataGetColumnMap(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData - getColumnMap()');

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model    = new Invoices();
        $expected = null;
        $actual   = $metadata->getColumnMap($model);
        $I->assertEquals($expected, $actual);

        $model    = new InvoicesMap();
        $expected = [
            'inv_id'          => 'id',
            'inv_cst_id'      => 'cst_id',
            'inv_status_flag' => 'status_flag',
            'inv_title'       => 'title',
            'inv_total'       => 'total',
            'inv_created_at'  => 'created_at',
        ];
        $actual   = $metadata->getColumnMap($model);
        $I->assertEquals($expected, $actual);
    }
}
