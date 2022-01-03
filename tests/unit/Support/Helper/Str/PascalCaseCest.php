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
use Phalcon\Support\Helper\Str\PascalCase;
use UnitTester;

class PascalCaseCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: pascalCase()
     *
     * @dataProvider getSources
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-01-02
     */
    public function supportHelperStrPascalCase(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - pascalCase() - ' . $example[0]);

        $object    = new PascalCase();
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
            ['customer-session', 'CustomerSession', null],
            ['customer Session', 'CustomerSession', ' -_'],
            ['customer-Session', 'CustomerSession', ' -_'],
        ];
    }
}
