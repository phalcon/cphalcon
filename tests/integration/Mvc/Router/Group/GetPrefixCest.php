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

class GetPrefixCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: getPrefix()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcRouterGroupGetPrefixEmpty(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - empty getPrefix()');

        $group = new Group();

        $I->assertEquals(
            '',
            $group->getPrefix()
        );
    }

    /**
     * Tests Phalcon\Mvc\Router\Group :: getPrefix() when nothing is set
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcRouterGroupGetPrefix(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - getPrefix()');

        $group = new Group();

        $group->setPrefix('/blog');

        $I->assertEquals(
            '/blog',
            $group->getPrefix()
        );
    }
}
