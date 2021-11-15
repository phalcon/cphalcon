<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Script;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Script;
use Phalcon\Html\TagFactory;
use UnitTester;

use const PHP_EOL;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Script
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Script :: __invoke()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function htmlHelperScriptUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Script - __invoke() ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Script($escaper);

        $result = $helper($example['indent'], $example['delimiter']);
        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1]);
        }

        $expected = $example['result'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('script');

        $result = $locator($example['indent'], $example['delimiter']);
        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1]);
        }

        $actual = (string) $result;
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'message'   => 'base',
                'indent'    => '    ',
                'delimiter' => PHP_EOL,
                'add'       => [
                    [
                        "/js/custom.js",
                        [],
                    ],
                    [
                        "/js/print.js",
                        ["ie" => "active"],
                    ],
                ],
                'result'    => "    <script type=\"application/javascript\" "
                    . "src=\"/js/custom.js\"></script>" . PHP_EOL
                    . "    <script type=\"application/javascript\" "
                    . "src=\"/js/print.js\" ie=\"active\"></script>" . PHP_EOL,
            ],
            [
                'message'   => 'with indent and delimiter',
                'indent'    => '--',
                'delimiter' => '+',
                'add'       => [
                    [
                        "/js/custom.js",
                        [],
                    ],
                    [
                        "/js/print.js",
                        ["ie" => "active"],
                    ],
                ],
                'result'    => "--<script type=\"application/javascript\" "
                    . "src=\"/js/custom.js\"></script>+"
                    . "--<script type=\"application/javascript\" "
                    . "src=\"/js/print.js\" ie=\"active\"></script>+",
            ],
        ];
    }
}
