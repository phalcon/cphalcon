<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Text;

use Codeception\Example;
use Phalcon\Text;
use UnitTester;

/**
 * Class CamelizeCest
 */
class CamelizeCest
{
    /**
     * Tests Phalcon\Text :: camelize()
     *
     * @dataProvider getSources
     *
     * @param UnitTester $I
     * @param Example    $item
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2018-11-13
     */
    public function textCamelize(UnitTester $I, Example $item)
    {
        $I->wantToTest('Text - camelize()');
        $value     = $item[0];
        $expected  = $item[1];
        $delimiter = $item[2];
        $actual    = Text::camelize($value, $delimiter);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getSources(): array
    {
        return [
            ['camelize', 'Camelize', null],
            ['CameLiZe', 'Camelize', null],
            ['cAmeLize', 'Camelize', null],
            ['123camelize', '123camelize', null],
            ['c_a_m_e_l_i_z_e', 'CAMELIZE', null],
            ['Camelize', 'Camelize', null],
            ['camel_ize', 'CamelIze', null],
            ['CameLize', 'Camelize', null],
            ["c_a-m_e-l_i-z_e", 'CAMELIZE', null],
            ["came_li_ze", 'CameLiZe', null],
            ["=_camelize", '=Camelize', "_"],
            ["camelize", 'Camelize', "_"],
            ["came_li_ze", 'CameLiZe', "_"],
            ["came#li#ze", 'CameLiZe', "#"],
            ["came li ze", 'CameLiZe', " "],
            ["came.li^ze", 'CameLiZe', ".^"],
            ["c_a-m_e-l_i-z_e", 'CAMELIZE', "-_"],
            ["came.li.ze", 'CameLiZe', "."],
            ["came-li-ze", 'CameLiZe', "-"],
            ["c+a+m+e+l+i+z+e", 'CAMELIZE', "+"],
        ];
    }
}
