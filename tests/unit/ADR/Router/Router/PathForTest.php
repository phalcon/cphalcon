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

final class PathForTest extends AbstractUnitTestCase
{
    private const BASE      = 'Phalcon\\Tests\\Support\\ADR\\Action';
    private const DIRECTORY = PATH_SUPPORT . 'ADR/Action';

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            'root action' => [
                self::BASE . '\\Get',
                '/',
            ],
            'single segment' => [
                self::BASE . '\\Posts\\GetPosts',
                '/posts',
            ],
            'two level descent' => [
                self::BASE . '\\Reports\\Daily\\GetReportsDaily',
                '/reports/daily',
            ],
            'multi word resource' => [
                self::BASE . '\\UserProfiles\\GetUserProfiles',
                '/user-profiles',
            ],
            'multi word, two level descent' => [
                self::BASE
                . '\\UserProfiles\\ResetPassword\\GetUserProfilesResetPassword',
                '/user-profiles/reset-password',
            ],
            'other verb' => [
                self::BASE . '\\Posts\\PostPosts',
                '/posts',
            ],
            'declared parameter becomes a placeholder' => [
                self::BASE . '\\User\\GetUser',
                '/user/{id}',
            ],
            'outside the base namespace' => [
                'Some\\Other\\Namespace1\\GetThing',
                null,
            ],
            'root class that is not a verb' => [
                self::BASE . '\\Nonsense',
                null,
            ],
            'fused operation form is not a convention name' => [
                self::BASE . '\\Posts\\GetPostsArchive',
                null,
            ],
            'class name that does not carry its namespace' => [
                self::BASE . '\\Posts\\GetSomethingElse',
                null,
            ],
            'class name carrying only the last segment' => [
                self::BASE . '\\Reports\\Daily\\GetDaily',
                null,
            ],
        ];
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: pathFor() follows the configured
     * word separator
     */
    public function testAdrRouterRouterPathForFollowsWordSeparator(): void
    {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY)
            ->setWordSeparator('_');

        $this->assertSame(
            '/user_profiles/reset_password',
            $router->pathFor(
                self::BASE
                . '\\UserProfiles\\ResetPassword\\GetUserProfilesResetPassword'
            )
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: pathFor() never walks the action
     * directory - it is not even set here
     */
    public function testAdrRouterRouterPathForIgnoresActionDirectory(): void
    {
        $router = (new Router())->setBaseNamespace(self::BASE);

        $this->assertSame(
            '/company/all',
            $router->pathFor(self::BASE . '\\Company\\All\\GetCompanyAll')
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: pathFor() returns the canonical
     * path for an Action class
     */
    #[DataProvider('getExamples')]
    public function testAdrRouterRouterPathForReturnsCanonicalPath(
        string $className,
        ?string $expected
    ): void {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $this->assertSame($expected, $router->pathFor($className));
    }
}
