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
use Phalcon\Support\Helper\Str\KebabCase;
use Phalcon\Support\Helper\Str\SnakeCase;
use UnitTester;

class KebabCaseCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: kebabCase()
     *
     * @dataProvider getSources
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-01-02
     */
    public function supportHelperStrKebabCase(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - kebabCase() - ' . $example[0]);

        $object    = new KebabCase();
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
            ['Camelize', 'Camelize', null],
            ['CameLiZe', 'CameLiZe', null],
            ['Camelize', 'Camelize', null],
            ['123camelize', '123camelize', null],
            ['c_a_m_e_l_i_z_e', 'c_a_m_e_l_i_z_e', null],
            ['Camelize', 'Camelize', null],
            ['camel_ize', 'camel_ize', null],
            ['CameLize', 'CameLize', null],
            ['c_a-m_e-l_i-z_e', 'c_a_m_e_l_i_z_e', null],
            ['came_li_ze', 'came_li_ze', null],
            ['=_camelize', '=_camelize', '_'],
            ['camelize', 'camelize', '_'],
            ['came_li_ze', 'came_li_ze', '_'],
            ['came#li#ze', 'came_li_ze', '#'],
            ['came li ze', 'came_li_ze', ' '],
            ['came.li^ze', 'came_li_ze', '.^'],
            ['c_a-m_e-l_i-z_e', 'c_a_m_e_l_i_z_e', '-_'],
            ['came.li.ze', 'came_li_ze', '.'],
            ['came-li-ze', 'came_li_ze', '-'],
            ['c+a+m+e+l+i+z+e', 'c_a_m_e_l_i_z_e', '+'],
            ['customer-session', 'customer_session', null],
            ['customer Session', 'customer_Session', ' -_'],
            ['customer-Session', 'customer_Session', ' -_'],
        ];
    }
}
