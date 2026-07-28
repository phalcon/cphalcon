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
            'fused operation form' => [
                self::BASE . '\\Posts\\GetPostsArchive',
                '/posts/archive',
            ],
            'two level descent' => [
                self::BASE . '\\Reports\\Daily\\GetDaily',
                '/reports/daily',
            ],
            'multi word resource' => [
                self::BASE . '\\UserProfiles\\GetUserProfiles',
                '/user-profiles',
            ],
            'multi word resource and operation' => [
                self::BASE . '\\UserProfiles\\GetUserProfilesResetPassword',
                '/user-profiles/reset-password',
            ],
            'other verb' => [
                self::BASE . '\\Posts\\PostPosts',
                '/posts',
            ],
            'outside the base namespace' => [
                'Some\\Other\\Namespace1\\GetThing',
                null,
            ],
            'root class that is not a verb' => [
                self::BASE . '\\Nonsense',
                null,
            ],
            'class name that does not carry its resource' => [
                self::BASE . '\\Posts\\GetSomethingElse',
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
            $router->pathFor(self::BASE . '\\UserProfiles\\GetUserProfilesResetPassword')
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: pathFor() returns the canonical
     * static path for an Action class
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
