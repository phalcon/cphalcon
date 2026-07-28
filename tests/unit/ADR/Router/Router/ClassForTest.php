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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class ClassForTest extends AbstractUnitTestCase
{
    private const BASE      = 'Phalcon\\Tests\\Support\\ADR\\Action';
    private const DIRECTORY = PATH_SUPPORT . 'ADR/Action';

    /**
     * The naming convention on its own. None of these paths need to exist on
     * disk - that is the point of classFor().
     *
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            'root' => [
                'GET',
                '/',
                self::BASE . '\\Get',
            ],
            'root, empty path' => [
                'GET',
                '',
                self::BASE . '\\Get',
            ],
            'single segment' => [
                'GET',
                '/posts',
                self::BASE . '\\Posts\\GetPosts',
            ],
            'single segment, trailing slash' => [
                'GET',
                '/posts/',
                self::BASE . '\\Posts\\GetPosts',
            ],
            'single segment, no leading slash' => [
                'GET',
                'posts',
                self::BASE . '\\Posts\\GetPosts',
            ],
            'lowercase method' => [
                'get',
                '/posts',
                self::BASE . '\\Posts\\GetPosts',
            ],
            'other method' => [
                'POST',
                '/posts',
                self::BASE . '\\Posts\\PostPosts',
            ],
            'two segments, nothing on disk' => [
                'GET',
                '/company/all',
                self::BASE . '\\Company\\All\\GetCompanyAll',
            ],
            'multi word segment, nothing on disk' => [
                'POST',
                '/session/forgot-password',
                self::BASE
                . '\\Session\\ForgotPassword\\PostSessionForgotPassword',
            ],
            'three segments, nothing on disk' => [
                'DELETE',
                '/admin/user-profiles/avatar',
                self::BASE
                . '\\Admin\\UserProfiles\\Avatar'
                . '\\DeleteAdminUserProfilesAvatar',
            ],
        ];
    }

    /**
     * Every Action fixture whose canonical path is fully static.
     *
     * @return array[]
     */
    public static function getInverseExamples(): array
    {
        return [
            'root'          => [self::BASE . '\\Get'],
            'admin'         => [self::BASE . '\\Admin\\GetAdmin'],
            'hello'         => [self::BASE . '\\Hello\\GetHello'],
            'posts'         => [self::BASE . '\\Posts\\GetPosts'],
            'reports daily' => [
                self::BASE . '\\Reports\\Daily\\GetReportsDaily',
            ],
            'user profiles' => [
                self::BASE . '\\UserProfiles\\GetUserProfiles',
            ],
            'user profiles reset' => [
                self::BASE
                . '\\UserProfiles\\ResetPassword\\GetUserProfilesResetPassword',
            ],
        ];
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: classFor() follows the configured
     * word separator
     */
    public function testAdrRouterRouterClassForFollowsWordSeparator(): void
    {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setWordSeparator('_');

        $this->assertSame(
            self::BASE
            . '\\UserProfiles\\ResetPassword\\GetUserProfilesResetPassword',
            $router->classFor('GET', '/user_profiles/reset_password')
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: classFor() does not consult the
     * filesystem - the action directory is never even set
     */
    public function testAdrRouterRouterClassForIgnoresTheFilesystem(): void
    {
        $router = (new Router())->setBaseNamespace(self::BASE);

        $this->assertSame(
            self::BASE . '\\Company\\All\\GetCompanyAll',
            $router->classFor('GET', '/company/all')
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: classFor() is the exact inverse
     * of pathFor() for every Action that declares no parameters
     */
    #[DataProvider('getInverseExamples')]
    public function testAdrRouterRouterClassForInvertsPathFor(
        string $className
    ): void {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $path = $router->pathFor($className);

        $this->assertNotNull($path, $className . ' has no canonical path');
        $this->assertSame($className, $router->classFor('GET', $path));
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: classFor() names the class the
     * convention would use for a static path
     */
    #[DataProvider('getExamples')]
    public function testAdrRouterRouterClassForNamesTheClass(
        string $method,
        string $path,
        string $expected
    ): void {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $this->assertSame($expected, $router->classFor($method, $path));
    }
}
