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
use Phalcon\Helper\Str;
use UnitTester;

class UncamelizeCest
{
    /**
     * Tests Phalcon\Helper\Str :: uncamelize()
     *
     * @dataProvider getSources
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     */
    public function helperStrUncamelize(UnitTester $I, Example $item)
    {
        $I->wantToTest('Helper\Str - uncamelize()');
        $value     = $item[0];
        $expected  = $item[1];
        $delimiter = $item[2];
        $actual    = Str::uncamelize($value, $delimiter);
        $I->assertEquals($expected, $actual);
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
