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

namespace Phalcon\Tests\Unit\Mvc\Url;

use Phalcon\Mvc\Url;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                'https://phalcon.io',
                null,
            ],
            [
                'https://phalcon.io',
                '',
            ],
            [
                'https://phalcon.io/',
                '/',
            ],
            [
                'https://phalcon.io/en/team',
                '/en/team',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testMvcUrlGet(
        string $expected,
        ?string $name
    ): void {
        $url = new Url();

        $url->setBaseUri('https://phalcon.io');

        $actual = $url->get($name);
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-04
     */
    public function testGetAppendsArgsWhenUriHasNoQueryString(): void
    {
        $url = new Url();
        $url->setBaseUri('/');

        $expected = '/show/products?id=1&name=Carrots';
        $actual   = $url->get(
            'show/products',
            ['id' => 1, 'name' => 'Carrots']
        );

        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-04
     */
    public function testGetAppendsArgsWithAmpersandWhenUriHasQueryString(): void
    {
        $url = new Url();

        $expected = 'http://example.com?page=1&page=5';
        $actual   = $url->get(
            'http://example.com?page=1',
            ['page' => 5]
        );

        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-04
     */
    public function testGetReplaceArgsOverridesExistingQueryKeys(): void
    {
        $url = new Url();

        $expected = 'http://example.com?page=5';
        $actual   = $url->get(
            'http://example.com?page=1',
            ['page' => 5],
            null,
            null,
            true
        );

        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-04
     */
    public function testGetReplaceArgsMergesNewKeysWithExistingQuery(): void
    {
        $url = new Url();

        $actual = $url->get(
            'http://example.com?page=1&sort=asc',
            ['page' => 5, 'limit' => 20],
            null,
            null,
            true
        );

        parse_str(parse_url($actual, PHP_URL_QUERY), $query);

        $this->assertSame('5', $query['page']);
        $this->assertSame('asc', $query['sort']);
        $this->assertSame('20', $query['limit']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-04
     */
    public function testGetReplaceArgsWithNoExistingQueryStillAppends(): void
    {
        $url = new Url();

        $expected = 'http://example.com?page=5';
        $actual   = $url->get(
            'http://example.com',
            ['page' => 5],
            null,
            null,
            true
        );

        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-04
     */
    public function testGetUsesProvidedBaseUriOverInstanceBaseUri(): void
    {
        $url = new Url();

        $url->setBaseUri('https://phalcon.io/');

        $expected = 'https://example.com/products/edit/1';
        $actual   = $url->get(
            'products/edit/1',
            null,
            null,
            'https://example.com/'
        );

        $this->assertSame($expected, $actual);
    }
}
