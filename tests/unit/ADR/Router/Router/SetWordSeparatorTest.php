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

use Phalcon\ADR\Router\Router;
use Phalcon\Http\Request;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class SetWordSeparatorTest extends AbstractUnitTestCase
{
    private const BASE      = 'Phalcon\\Tests\\Support\\ADR\\Action';
    private const DIRECTORY = PATH_SUPPORT . 'ADR/Action';

    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: setWordSeparator() - the default
     * separator resolves a dashed path
     */
    public function testAdrRouterRouterSetWordSeparatorDashedPathResolves(): void
    {
        $_SERVER['REQUEST_URI']    = '/user-profiles/reset-password';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $match = $router->match(new Request());

        $this->assertSame(
            self::BASE . '\\UserProfiles\\GetUserProfilesResetPassword',
            $match->getAction()
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: setWordSeparator() - setting the
     * separator to an underscore inverts both cases
     */
    public function testAdrRouterRouterSetWordSeparatorInvertsWhenSetToUnderscore(): void
    {
        $_SERVER['REQUEST_URI']    = '/user_profiles/reset_password';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY)
            ->setWordSeparator('_');

        $match = $router->match(new Request());

        $this->assertSame(
            self::BASE . '\\UserProfiles\\GetUserProfilesResetPassword',
            $match->getAction()
        );

        $_SERVER['REQUEST_URI'] = '/user-profiles/reset-password';

        $this->assertNull($router->match(new Request()));
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: setWordSeparator() - an underscore
     * path no longer collapses onto the dashed Action
     */
    public function testAdrRouterRouterSetWordSeparatorUnderscorePathDoesNotCollapse(): void
    {
        $_SERVER['REQUEST_URI']    = '/user_profiles/reset_password';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $this->assertNull($router->match(new Request()));
    }
}
