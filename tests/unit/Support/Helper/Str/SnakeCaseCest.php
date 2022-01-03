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
use Phalcon\Support\Helper\Str\SnakeCase;
use UnitTester;

class SnakeCaseCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: snakeCase()
     *
     * @dataProvider getSources
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-01-02
     */
    public function supportHelperStrSnakeCase(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - snakeCase() - ' . $example[0]);

        $object    = new SnakeCase();
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
            ['c_a_m_e_l_i_z_e', 'c-a-m-e-l-i-z-e', null],
            ['Camelize', 'Camelize', null],
            ['camel_ize', 'camel-ize', null],
            ['CameLize', 'CameLize', null],
            ['c_a-m_e-l_i-z_e', 'c-a-m-e-l-i-z-e', null],
            ['came_li_ze', 'came-li-ze', null],
            ['=_camelize', '=-camelize', '_'],
            ['camelize', 'camelize', '_'],
            ['came_li_ze', 'came-li-ze', '_'],
            ['came#li#ze', 'came-li-ze', '#'],
            ['came li ze', 'came-li-ze', ' '],
            ['came.li^ze', 'came-li-ze', '.^'],
            ['c_a-m_e-l_i-z_e', 'c-a-m-e-l-i-z-e', '-_'],
            ['came.li.ze', 'came-li-ze', '.'],
            ['came-li-ze', 'came-li-ze', '-'],
            ['c+a+m+e+l+i+z+e', 'c-a-m-e-l-i-z-e', '+'],
            ['customer-session', 'customer-session', null],
            ['customer Session', 'customer-Session', ' -_'],
            ['customer-Session', 'customer-Session', ' -_'],
        ];
    }
}
