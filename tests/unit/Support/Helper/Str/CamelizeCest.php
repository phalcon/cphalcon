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
use Phalcon\Support\Helper\Str\Camelize;
use UnitTester;

/**
 * Class CamelizeCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class CamelizeCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: camelize()
     *
     * @dataProvider getSources
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrCamelize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - camelize() - ' . $example[0]);

        $object    = new Camelize();
        $value     = $example[0];
        $expected  = $example[1];
        $delimiter = $example[2];

        $actual = $object($value, $delimiter);
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
            ['c_a-m_e-l_i-z_e', 'CAMELIZE', null],
            ['came_li_ze', 'CameLiZe', null],
            ['=_camelize', '=Camelize', '_'],
            ['camelize', 'Camelize', '_'],
            ['came_li_ze', 'CameLiZe', '_'],
            ['came#li#ze', 'CameLiZe', '#'],
            ['came li ze', 'CameLiZe', ' '],
            ['came.li^ze', 'CameLiZe', '.^'],
            ['c_a-m_e-l_i-z_e', 'CAMELIZE', '-_'],
            ['came.li.ze', 'CameLiZe', '.'],
            ['came-li-ze', 'CameLiZe', '-'],
            ['c+a+m+e+l+i+z+e', 'CAMELIZE', '+'],
        ];
    }
}
