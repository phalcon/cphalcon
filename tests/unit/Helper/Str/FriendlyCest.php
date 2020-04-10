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

namespace Phalcon\Test\Unit\Helper\Str;

use Codeception\Example;
use Phalcon\Helper\Exception;
use Phalcon\Helper\Str;
use UnitTester;

/**
 * Class FriendlyCest
 */
class FriendlyCest
{
    /**
     * Tests Phalcon\Helper\Str :: friendly()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     *
     * @dataProvider getExamples
     * @since        2020-01-07
     *
     * @author       Phalcon Team <team@phalcon.io>
     */
    public function helperStrFriendly(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - friendly() ' . $example['message']);

        $actual = Str::friendly(
            $example['text'],
            $example['separator'],
            $example['lowercase'],
            $example['replace']
        );

        $I->assertEquals($example['result'], $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: friendly() - exception
     *
     * @param UnitTester $I
     *
     * @since  2020-01-07
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function helperStrFriendlyException(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('Parameter replace must be an array or a string'),
            function () {
                Str::friendly('test', '-', true, true);
            }
        );
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'message'   => 'no separator',
                'text'      => 'This is a Test',
                'separator' => '-',
                'lowercase' => true,
                'replace'   => null,
                'result'    => 'this-is-a-test',
            ],
            [
                'message'   => 'separator',
                'text'      => 'This is a Test',
                'separator' => '_',
                'lowercase' => true,
                'replace'   => null,
                'result'    => 'this_is_a_test',
            ],
            [
                'message'   => 'not lowercase',
                'text'      => 'This is a Test',
                'separator' => '-',
                'lowercase' => false,
                'replace'   => null,
                'result'    => 'This-is-a-Test',
            ],
            [
                'message'   => 'replace string',
                'text'      => 'This is a Test',
                'separator' => '_',
                'lowercase' => true,
                'replace'   => 'i',
                'result'    => 'th_s_s_a_test',
            ],
            [
                'message'   => 'replace array',
                'text'      => 'This is a Test',
                'separator' => '_',
                'lowercase' => true,
                'replace'   => ['i', 'h'],
                'result'    => 't_s_s_a_test',
            ],
            [
                'message'   => 'special characters and escaping',
                'text'      => "Mess'd up --text-- just (to) stress /test/ ?our! "
                    . '`little` \\clean\\ url fun.ction!?-->',
                'separator' => '-',
                'lowercase' => true,
                'replace'   => null,
                'result'    => 'messd-up-text-just-to-stress-test-our-little-clean-url-function',
            ],
            [
                'message'   => 'accented characters replace string',
                'text'      => "Perché l'erba è verde?",
                'separator' => '-',
                'lowercase' => true,
                'replace'   => "'",
                'result'    => 'perche-l-erba-e-verde',
            ],
            [
                'message'   => 'accented characters replace array',
                'text'      => "Perché l'erba è verde?",
                'separator' => '_',
                'lowercase' => false,
                'replace'   => ['e', 'a'],
                'result'    => 'P_rch_l_rb_v_rd',
            ],
        ];
    }
}
