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
use PHPUnit\Framework\Attributes\DataProvider;

final class RoundTripTest extends AbstractUnitTestCase
{
    private const BASE      = 'Phalcon\\Tests\\Support\\ADR\\Action';
    private const DIRECTORY = PATH_SUPPORT . 'ADR/Action';

    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Every Action fixture on disk, as a class-string.
     *
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            'root'                => [self::BASE . '\\Get'],
            'admin'               => [self::BASE . '\\Admin\\GetAdmin'],
            'hello'               => [self::BASE . '\\Hello\\GetHello'],
            'posts'               => [self::BASE . '\\Posts\\GetPosts'],
            'posts archive'       => [self::BASE . '\\Posts\\GetPostsArchive'],
            'reports daily'       => [self::BASE . '\\Reports\\Daily\\GetDaily'],
            'user'                => [self::BASE . '\\User\\GetUser'],
            'user profiles'       => [self::BASE . '\\UserProfiles\\GetUserProfiles'],
            'user profiles reset' => [
                self::BASE . '\\UserProfiles\\GetUserProfilesResetPassword',
            ],
        ];
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: pathFor() fed back through match()
     * returns the class it came from - the reversibility guarantee
     */
    #[DataProvider('getExamples')]
    public function testAdrRouterRouterRoundTripsEveryAction(string $className): void
    {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $path = $router->pathFor($className);

        $this->assertNotNull($path, $className . ' has no canonical path');

        $_SERVER['REQUEST_URI']    = $path;
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $match = $router->match(new Request());

        $this->assertNotNull($match, $path . ' does not resolve');
        $this->assertSame($className, $match->getAction(), $path . ' is shadowed');
        $this->assertSame([], $match->getAttributes());
    }
}
