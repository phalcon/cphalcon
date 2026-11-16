<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\ADR\Router\Router;

use Exception;
use Phalcon\ADR\Router\Router;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\ADR\Hidden\GetHidden;
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;
use PHPUnit\Framework\Attributes\DataProvider;

use function get_class;

final class PathForTest extends AbstractUnitTestCase
{
    use ErrorHandlerTrait;

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
     * Unit Tests Phalcon\ADR\Router\Router :: pathFor() with a params()
     * method that cannot be called gives a warning, then the exception of
     * cphalcon for a value that it cannot iterate
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testAdrRouterRouterPathForParamsNotCallable(): void
    {
        $router = (new Router())->setBaseNamespace('Phalcon\\Tests\\Support\\ADR');

        [$actual, $messages] = $this->collectErrors(
            static function () use ($router): string {
                try {
                    $router->pathFor(GetHidden::class);
                } catch (Exception $ex) {
                    return get_class($ex) . ': ' . $ex->getMessage();
                }

                return 'no exception';
            }
        );

        $this->assertSame('Exception: The argument is not initialized or iterable()', $actual);
        $this->assertSame(
            ['cannot access private method ' . GetHidden::class . '::params()'],
            $messages
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
