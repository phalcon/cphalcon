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
use Phalcon\Contracts\ADR\Router\Router as RouterInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

use function method_exists;

final class MethodForTest extends AbstractUnitTestCase
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
                'GET',
            ],
            'root action, other verb' => [
                self::BASE . '\\Delete',
                'DELETE',
            ],
            'single segment' => [
                self::BASE . '\\Posts\\GetPosts',
                'GET',
            ],
            'two level descent' => [
                self::BASE . '\\Reports\\Daily\\GetReportsDaily',
                'GET',
            ],
            'multi word resource' => [
                self::BASE . '\\UserProfiles\\GetUserProfiles',
                'GET',
            ],
            'multi word, two level descent' => [
                self::BASE
                . '\\UserProfiles\\ResetPassword\\GetUserProfilesResetPassword',
                'GET',
            ],
            'post' => [
                self::BASE . '\\Posts\\PostPosts',
                'POST',
            ],
            'put' => [
                self::BASE . '\\Posts\\PutPosts',
                'PUT',
            ],
            'patch' => [
                self::BASE . '\\Posts\\PatchPosts',
                'PATCH',
            ],
            'delete' => [
                self::BASE . '\\Posts\\DeletePosts',
                'DELETE',
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
     * Unit Tests Phalcon\ADR\Router\Router :: methodFor() never walks the
     * action directory - it is not even set here
     */
    public function testAdrRouterRouterMethodForIgnoresActionDirectory(): void
    {
        $router = (new Router())->setBaseNamespace(self::BASE);

        $this->assertSame(
            'GET',
            $router->methodFor(self::BASE . '\\Company\\All\\GetCompanyAll')
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: methodFor() is published by the
     * Router contract
     */
    public function testAdrRouterRouterMethodForIsPublishedByContract(): void
    {
        $router = new Router();

        $this->assertInstanceOf(RouterInterface::class, $router);
        $this->assertTrue(method_exists(RouterInterface::class, 'methodFor'));
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: methodFor() and pathFor() agree
     * on which class names the convention would have produced
     */
    #[DataProvider('getExamples')]
    public function testAdrRouterRouterMethodForMirrorsPathForNullSemantics(
        string $className,
        ?string $expected
    ): void {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $this->assertSame(
            null === $router->pathFor($className),
            null === $router->methodFor($className)
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: methodFor() returns the uppercased
     * HTTP method an Action class answers
     */
    #[DataProvider('getExamples')]
    public function testAdrRouterRouterMethodForReturnsHttpMethod(
        string $className,
        ?string $expected
    ): void {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $this->assertSame($expected, $router->methodFor($className));
    }
}
