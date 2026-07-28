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
     * The routing convention as a vector list. Two candidates appear only when
     * exactly one segment remains after the descent: the fused operation form
     * is probed before the resource form.
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
            'operation form then resource form' => [
                'GET',
                '/posts/archive',
                [
                    self::BASE . '\\Posts\\GetPostsArchive',
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'attribute tail' => [
                'GET',
                '/posts/42',
                [
                    self::BASE . '\\Posts\\GetPosts42',
                    self::BASE . '\\Posts\\GetPosts',
                ],
            ],
            'two level descent' => [
                'GET',
                '/reports/daily',
                [
                    self::BASE . '\\Reports\\Daily\\GetDaily',
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
     * match() - the first candidate that exists is the one routed to
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
     * Unit Tests Phalcon\ADR\Router\Router :: candidatesFor() reports every
     * Action class the router would try, in try order
     */
    #[DataProvider('getExamples')]
    public function testAdrRouterRouterCandidatesForReturnsTryOrder(
        string $method,
        string $path,
        array $expected
    ): void {
        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $this->assertSame($expected, $router->candidatesFor($method, $path));
    }
}
