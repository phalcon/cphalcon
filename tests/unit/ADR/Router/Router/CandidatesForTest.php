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

final class CandidatesForTest extends AbstractUnitTestCase
{
    private const BASE = 'Phalcon\\Tests\\Support\\ADR\\Action';

    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * The routing convention as a vector list. Most of these classes do not
     * exist - candidatesFor() reports what the router would try, unfiltered.
     *
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            'root' => [
                'GET',
                '/',
                [
                    self::BASE . '\\Get',
                ],
            ],
            'root, empty path' => [
                'GET',
                '',
                [
                    self::BASE . '\\Get',
                ],
            ],
            'single segment' => [
                'GET',
                '/posts',
                [
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'single segment, trailing slash' => [
                'GET',
                '/posts/',
                [
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'single segment, no leading slash' => [
                'GET',
                'posts',
                [
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'lowercase method' => [
                'get',
                '/posts',
                [
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'other method' => [
                'POST',
                '/posts',
                [
                    self::BASE . '\\Posts\\PostPosts',
                ],
            ],
            'two segments' => [
                'GET',
                '/posts/42',
                [
                    self::BASE . '\\Posts\\GetPosts42',
                    self::BASE . '\\Posts\\42\\Get42',
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'camelized segments' => [
                'GET',
                '/user-profiles/reset_password',
                [
                    self::BASE . '\\UserProfiles\\GetUserProfilesResetPassword',
                    self::BASE . '\\UserProfiles\\ResetPassword\\GetResetPassword',
                    self::BASE . '\\UserProfiles\\GetUserProfiles',
                ],
            ],
            'three segments' => [
                'GET',
                '/admin/posts/42',
                [
                    self::BASE . '\\Admin\\Posts\\GetPosts42',
                    self::BASE . '\\Admin\\Posts\\42\\Get42',
                    self::BASE . '\\Admin\\GetAdminPosts',
                    self::BASE . '\\Admin\\Posts\\GetPosts',
                    self::BASE . '\\Admin\\GetAdmin',
                ],
            ],
        ];
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: candidatesFor() agrees with
     * match() - the first candidate that exists is the one routed to
     */
    public function testAdrRouterRouterCandidatesForAgreesWithMatch(): void
    {
        $_SERVER['REQUEST_URI']    = '/admin/posts/42';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())->setBaseNamespace(self::BASE);

        $candidates = $router->candidatesFor('GET', '/admin/posts/42');
        $existing   = array_values(array_filter($candidates, 'class_exists'));

        $this->assertNotEmpty($existing);
        $this->assertSame($existing[0], $router->match(new Request())->getAction());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: candidatesFor() reports every
     * Action class the router would try, in try order
     */
    #[DataProvider('getExamples')]
    public function testAdrRouterRouterCandidatesForReturnsTryOrder(
        string $method,
        string $path,
        array $expected
    ): void {
        $router = (new Router())->setBaseNamespace(self::BASE);

        $this->assertSame($expected, $router->candidatesFor($method, $path));
    }
}
