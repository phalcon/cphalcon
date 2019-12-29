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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Snapshot\Robots;

class HasChangedCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasChanged()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-17
     */
    public function mvcModelHasChanged(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - hasChanged()');

        /**
         * Robot has default values set:
         *  'year' => 1900,
         *  'type' => "mechanical"
         */
        $robot = new Robots();

        $robot->type     = 'mechanical';
        $robot->name     = 'Astro Boy';
        $robot->datetime = (new \DateTime())->format('Y-m-d');
        $robot->text     = 'Test text';

        $I->assertTrue(
            $robot->create()
        );

        $I->assertFalse(
            $robot->hasChanged('name')
        );

        $robot->type = 'hydraulic';

        $I->assertTrue(
            $robot->hasChanged('type')
        );

        /**
         * Testing that default value is unchanged
         */
        $I->assertFalse(
            $robot->hasChanged('year')
        );

        /**
         * Any of multiple fields
         */
        $I->assertTrue(
            $robot->hasChanged(['type', 'name'])
        );

        /**
         * All of multiple fields
         */
        $I->assertFalse(
            $robot->hasChanged(['type', 'name'], true)
        );

        $robot->name = 'My Astro Boy';

        $I->assertTrue(
            $robot->hasChanged(['type', 'name'], true)
        );

        /**
         * Clean up
         */
        $I->assertTrue(
            $robot->delete()
        );
    }
}
