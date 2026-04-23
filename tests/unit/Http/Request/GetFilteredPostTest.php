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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function ucfirst;

final class GetFilteredPostTest extends AbstractHttpBase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                'post',
                'id',
                ['absint'],
                ['post'],
                '24',
                24,
            ],
            [
                'post',
                'name',
                ['striptags', 'trim'],
                ['post'],
                ' This is a <strong>test</strong>   ',
                'This is a test',
            ],
            [
                'query',
                'id',
                ['absint'],
                ['get'],
                '24',
                24,
            ],
            [
                'query',
                'name',
                ['striptags', 'trim'],
                ['get'],
                ' This is a <strong>test</strong>   ',
                'This is a test',
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-01
     */
    public function testHttpRequestGetFilteredDefault(): void
    {
        $request = $this->getRequestObject();
        $request
            ->setParameterFilters('id', ['absint'], ['post', 'get'])
        ;

        $_GET  = ['no-id' => '24'];
        $_POST = ['no-id' => '24'];

        $expected = 24;
        $actual   = $request->getFilteredQuery('id', 24);
        $this->assertSame($expected, $actual);

        $expected = 24;
        $actual   = $request->getFilteredPost('id', 24);
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-01
     */
    public function testHttpRequestGetFilteredPost(
        string $method,
        string $name,
        array $filters,
        array $scope,
        string $value,
        int | string $expected
    ): void {
        $request = $this->getRequestObject();

        $request->setParameterFilters($name, $filters, $scope);

        if ('query' === $method) {
            $_GET = [
                $name => $value,
            ];
        } elseif ('post' === $method) {
            $_POST = [
                $name => $value,
            ];
        }

        $method = 'getFiltered' . ucfirst($method);
        $actual = $request->$method($name);
        $this->assertSame($expected, $actual);
    }
}
