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

namespace Phalcon\Test\Unit\Http\Request;

use Codeception\Example;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class NumFilesCest extends HttpBase
{
    /**
     * Tests Request::numFiles
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-11-07
     *
     * @dataProvider filesProvider
     */
    public function testRequestNumFiles(UnitTester $I, Example $example)
    {
        $files          = $example[0];
        $all            = $example[1];
        $onlySuccessful = $example[2];

        $request = $this->getRequestObject();
        $_FILES  = $files;

        $I->assertEquals(
            $all,
            $request->numFiles(false)
        );

        $I->assertEquals(
            $onlySuccessful,
            $request->numFiles(true)
        );
    }

    private function filesProvider(): array
    {
        return [
            [
                [
                    'test' => [
                        'name'     => 'name',
                        'type'     => 'text/plain',
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
                        'type'     => ['text/plain', 'text/plain'],
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
}
