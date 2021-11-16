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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Codeception\Example;
use Phalcon\Support\Helper\Exception;
use Phalcon\Support\Helper\Str\Friendly;
use UnitTester;

/**
 * Class FriendlyCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class FriendlyCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: friendly()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrFriendly(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - friendly() ' . $example['message']);

        $object   = new Friendly();
        $expected = $example['result'];
        $actual   = $object->__invoke(
            $example['text'],
            $example['separator'],
            $example['lowercase'],
            $example['replace']
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: friendly() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrFriendlyException(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('Parameter replace must be an array or a string'),
            function () {
                (new Friendly())('test', '-', true, true);
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
