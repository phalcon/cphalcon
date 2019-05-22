<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Router\Group;

use IntegrationTester;
use Phalcon\Mvc\Router\Group;

class ClearCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: clear()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcRouterGroupClear(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - clear()');

        $group = new Group();

        $group->addGet(
            '/docs/index',
            [
                'controller' => 'documentation4',
                'action'     => 'index',
            ]
        );

        $I->assertCount(
            1,
            $group->getRoutes()
        );

        $group->clear();

        $I->assertCount(
            0,
            $group->getRoutes()
        );
    }
}
