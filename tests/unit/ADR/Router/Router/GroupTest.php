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

namespace Phalcon\Tests\Unit\ADR\Router\Router;

use Phalcon\ADR\Router\Group;
use Phalcon\ADR\Router\Router;
use Phalcon\Http\Request;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GroupTest extends AbstractUnitTestCase
{
    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: group() prefixes routes and flattens middleware
     */
    public function testAdrRouterRouterGroupPrefixesAndFlattensMiddleware(): void
    {
        $_SERVER['REQUEST_URI']    = '/admin/users';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = new Router();
        $router->group('/admin', function (Group $group) {
            $group->withMiddleware('AuthMiddleware');
            $group->get('/users', 'ListUsersAction');
        });

        $match = $router->match(new Request());

        $this->assertSame('ListUsersAction', $match->getAction());
        $this->assertSame(['AuthMiddleware'], $match->getMiddleware());
    }
}
