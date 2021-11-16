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

namespace Phalcon\Tests\Integration\Mvc\Router\Group;

use IntegrationTester;
use Phalcon\Mvc\Router\Group;

class GetSetPrefixCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: getPrefix() when nothing is set
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcRouterGroupGetPrefixEmpty(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - getPrefix() when nothing is set');

        $group = new Group();

        $I->assertEquals(
            '',
            $group->getPrefix()
        );
    }

    /**
     * Tests Phalcon\Mvc\Router\Group :: getPrefix()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcRouterGroupGetSetPrefix(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - getPrefix() / setPrefix()');

        $group = new Group();

        $group->setPrefix('/blog');

        $I->assertEquals(
            '/blog',
            $group->getPrefix()
        );
    }
}
