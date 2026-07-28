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
    private const BASE      = 'Phalcon\\Tests\\Support\\ADR\\Action';
    private const DIRECTORY = PATH_SUPPORT . 'ADR/Action';

    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * The routing convention as a vector list. One path names exactly one
     * class, so the list holds at most one entry - there is no candidate
     * ordering and nothing can be shadowed.
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
            'no fused operation form' => [
                'GET',
                '/posts/archive',
                [
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'attribute tail' => [
                'GET',
                '/posts/42',
                [
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'two level descent' => [
                'GET',
                '/reports/daily',
                [
                    self::BASE . '\\Reports\\Daily\\GetReportsDaily',
                ],
            ],
            'two level descent, multi word' => [
                'GET',
                '/user-profiles/reset-password',
                [
                    self::BASE
                    . '\\UserProfiles\\ResetPassword\\GetUserProfilesResetPassword',
                ],
            ],
            'descent stops, remainder is attributes' => [
                'GET',
                '/admin/posts/42',
                [
                    self::BASE . '\\Admin\\GetAdmin',
                ],
            ],
            'unknown first segment' => [
                'GET',
                '/nope',
                [],
            ],
            'unknown first segment, deeper path' => [
                'GET',
                '/nope/deeper',
                [],
            ],
        ];
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: candidatesFor() agrees with
     * match() - the single derived class is the one routed to
     */
    public function testAdrRouterRouterCandidatesForAgreesWithMatch(): void
    {
        $_SERVER['REQUEST_URI']    = '/admin/posts/42';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $candidates = $router->candidatesFor('GET', '/admin/posts/42');
        $existing   = array_values(array_filter($candidates, 'class_exists'));

        $this->assertNotEmpty($existing);
        $this->assertSame($existing[0], $router->match(new Request())->getAction());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: candidatesFor() derives at most
     * one Action class for any method and path
     */
    #[DataProvider('getExamples')]
    public function testAdrRouterRouterCandidatesForReturnsSingleDerivation(
        string $method,
        string $path,
        array $expected
    ): void {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $candidates = $router->candidatesFor($method, $path);

        $this->assertSame($expected, $candidates);
        $this->assertLessThanOrEqual(1, count($candidates));
    }
}
