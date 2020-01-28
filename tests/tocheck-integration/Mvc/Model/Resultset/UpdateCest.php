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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

/**
 * Class UpdateCest
 */
class UpdateCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $I->cleanDir(
            cacheModelsDir()
        );
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Resultset :: update()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelResultsetUpdate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset - update()');
        $robots = Robots::find(
            [
                'type' => 'mechanical',
            ]
        );
        $I->assertTrue($robots->update(['type' => 'mechanical']));
        $I->assertFalse($robots->update(['id' => 'invalid']));
    }
}
