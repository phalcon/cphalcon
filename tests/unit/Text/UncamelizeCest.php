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

namespace Phalcon\Test\Unit\Text;

use Codeception\Example;
use Phalcon\Text;
use UnitTester;

class UncamelizeCest
{
    /**
     * Tests Phalcon\Text :: uncamelize()
     *
     * @dataProvider getSources
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function textUncamelize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - uncamelize()');

        $value     = $example[0];
        $expected  = $example[1];
        $delimiter = $example[2];

        $I->assertEquals(
            $expected,
            Text::uncamelize($value, $delimiter)
        );
    }

    private function getSources(): array
    {
        return [
            ['camelize', 'camelize', null],
            ['CameLiZe', 'came_li_ze', null],
            ['cAmeLize', 'c_ame_lize', null],
            ['_camelize', '_camelize', null],
            ['123camelize', '123camelize', null],
            ['c_a_m_e_l_i_z_e', 'c_a_m_e_l_i_z_e', null],
            ['Camelize', 'camelize', null],
            ['camel_ize', 'camel_ize', null],
            ['CameLize', 'came_lize', null],
            ['Camelize', 'camelize', null],
            ['=Camelize', '=_camelize', '_'],
            ['Camelize', 'camelize', '_'],
            ['CameLiZe', 'came_li_ze', '_'],
            ['CameLiZe', 'came#li#ze', '#'],
            ['CameLiZe', 'came li ze', ' '],
            ['CameLiZe', 'came.li.ze', '.'],
            ['CameLiZe', 'came-li-ze', '-'],
            ['CAMELIZE', 'c/a/m/e/l/i/z/e', '/'],
        ];
    }
}
