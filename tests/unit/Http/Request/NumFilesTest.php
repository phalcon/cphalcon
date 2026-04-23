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

use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class NumFilesTest extends AbstractHttpBase
{
    /**
     * @return array[]
     */
    public static function filesProvider(): array
    {
        return [
            [
                [
                    'test' => [
                        'name'     => 'name',
                        'type'     => Http::CONTENT_TYPE_PLAIN,
                        'size'     => 1,
                        'tmp_name' => 'tmp_name',
                        'error'    => 0,
                    ],
                ],
                1,
                1,
            ],
            [
                [
                    'test' => [
                        'name'     => ['name1', 'name2'],
                        'type'     => [
                            Http::CONTENT_TYPE_PLAIN,
                            Http::CONTENT_TYPE_PLAIN,
                        ],
                        'size'     => [1, 1],
                        'tmp_name' => ['tmp_name1', 'tmp_name2'],
                        'error'    => [0, 0],
                    ],
                ],
                2,
                2,
            ],
            [
                [
                    'photo' => [
                        'name'     => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                        'type'     => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                        'tmp_name' => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                        'error'    => [
                            0 => 4,
                            1 => 4,
                            2 => [0 => 4, 1 => 4, 2 => 4],
                            3 => [0 => 4],
                            4 => [0 => [0 => 4]],
                            5 => [0 => [0 => [0 => [0 => 4]]]],
                        ],
                        'size'     => [
                            0 => '',
                            1 => '',
                            2 => [0 => '', 1 => '', 2 => ''],
                            3 => [0 => ''],
                            4 => [0 => [0 => '']],
                            5 => [0 => [0 => [0 => [0 => '']]]],
                        ],
                    ],
                    'test'  => [
                        'name'     => '',
                        'type'     => '',
                        'tmp_name' => '',
                        'error'    => 4,
                        'size'     => 0,
                    ],
                ],
                9,
                0,
            ],
        ];
    }

    /**
     * @dataProvider filesProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-11-07
     */
    public function testRequestNumFiles(
        array $files,
        int $all,
        int $onlySuccessful
    ): void {
        $request = $this->getRequestObject();
        $_FILES  = json_decode(json_encode($files), true);

        $expected = $all;
        $actual   = $request->numFiles();
        $this->assertSame($expected, $actual);

        $expected = $onlySuccessful;
        $actual   = $request->numFiles(true);
        $this->assertSame($expected, $actual);
    }
}
