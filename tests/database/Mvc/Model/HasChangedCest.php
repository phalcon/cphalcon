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

use DatabaseTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\CustomersDefaults;

class HasChangedCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasChanged()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-17
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelHasChanged(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - hasChanged()');

        /**
         * CustomersDefault has default values
         */
        $customer = new CustomersDefaults();

        $I->assertFalse(
            $customer->hasSnapshotData()
        );

        $I->assertTrue(
            $customer->create()
        );

        $I->assertTrue(
            $customer->hasSnapshotData()
        );

        /**
         * cst_id         has been null previously
         * cst_name_first remains default
         * cst_name_last  changes from default
         */
        $customer->cst_id         = 987;
        $customer->cst_name_first = 'cst_default_firstName';
        $customer->cst_name_last  = 'cst_new_lastName';

        $I->assertTrue(
            $customer->hasChanged('cst_id')
        );

        $I->assertFalse(
            $customer->hasChanged('cst_name_first')
        );

        $I->assertTrue(
            $customer->hasChanged('cst_name_last')
        );

        $I->assertTrue(
            $customer->hasChanged(['cst_name_first', 'cst_name_last'])
        );

        $I->assertFalse(
            $customer->hasChanged(['cst_name_first', 'cst_name_last'], true)
        );
    }
}
