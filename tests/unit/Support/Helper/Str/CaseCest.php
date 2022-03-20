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
use Phalcon\Support\Helper\Str\PascalCase;
use Phalcon\Support\Helper\Str\SnakeCase;
use UnitTester;

class CaseCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: *Case()
     *
     * @dataProvider getSources
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-01-02
     */
    public function supportHelperStrCase(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - ' . $example[1] . '  - ' . $example[2]);

        $class     = $example[0];
        $value     = $example[2];
        $expected  = $example[3];
        $delimiter = $example[4];
        $object    = new $class();

        $actual = $object($value, $delimiter);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getSources(): array
    {
        return [
            [SnakeCase::class, 'snake', 'Camelize', 'Camelize', null],
            [SnakeCase::class, 'snake', 'CameLiZe', 'CameLiZe', null],
            [SnakeCase::class, 'snake', 'Camelize', 'Camelize', null],
            [SnakeCase::class, 'snake', '123camelize', '123camelize', null],
            [SnakeCase::class, 'snake', 'c_a_m_e_l_i_z_e', 'c_a_m_e_l_i_z_e', null],
            [SnakeCase::class, 'snake', 'Camelize', 'Camelize', null],
            [SnakeCase::class, 'snake', 'camel_ize', 'camel_ize', null],
            [SnakeCase::class, 'snake', 'CameLize', 'CameLize', null],
            [SnakeCase::class, 'snake', 'c_a-m_e-l_i-z_e', 'c_a_m_e_l_i_z_e', null],
            [SnakeCase::class, 'snake', 'came_li_ze', 'came_li_ze', null],
            [SnakeCase::class, 'snake', '=_camelize', '=_camelize', '_'],
            [SnakeCase::class, 'snake', 'camelize', 'camelize', '_'],
            [SnakeCase::class, 'snake', 'came_li_ze', 'came_li_ze', '_'],
            [SnakeCase::class, 'snake', 'came#li#ze', 'came_li_ze', '#'],
            [SnakeCase::class, 'snake', 'came li ze', 'came_li_ze', ' '],
            [SnakeCase::class, 'snake', 'came.li^ze', 'came_li_ze', '.^'],
            [SnakeCase::class, 'snake', 'c_a-m_e-l_i-z_e', 'c_a_m_e_l_i_z_e', '-_'],
            [SnakeCase::class, 'snake', 'came.li.ze', 'came_li_ze', '.'],
            [SnakeCase::class, 'snake', 'came-li-ze', 'came_li_ze', '-'],
            [SnakeCase::class, 'snake', 'c+a+m+e+l+i+z+e', 'c_a_m_e_l_i_z_e', '+'],
            [SnakeCase::class, 'snake', 'customer-session', 'customer_session', null],
            [SnakeCase::class, 'snake', 'customer Session', 'customer_Session', ' -_'],
            [SnakeCase::class, 'snake', 'customer-Session', 'customer_Session', ' -_'],
            [PascalCase::class, 'pascal', 'camelize', 'Camelize', null],
            [PascalCase::class, 'pascal', 'CameLiZe', 'Camelize', null],
            [PascalCase::class, 'pascal', 'cAmeLize', 'Camelize', null],
            [PascalCase::class, 'pascal', '123camelize', '123camelize', null],
            [PascalCase::class, 'pascal', 'c_a_m_e_l_i_z_e', 'CAMELIZE', null],
            [PascalCase::class, 'pascal', 'Camelize', 'Camelize', null],
            [PascalCase::class, 'pascal', 'camel_ize', 'CamelIze', null],
            [PascalCase::class, 'pascal', 'CameLize', 'Camelize', null],
            [PascalCase::class, 'pascal', 'c_a-m_e-l_i-z_e', 'CAMELIZE', null],
            [PascalCase::class, 'pascal', 'came_li_ze', 'CameLiZe', null],
            [PascalCase::class, 'pascal', '=_camelize', '=Camelize', '_'],
            [PascalCase::class, 'pascal', 'camelize', 'Camelize', '_'],
            [PascalCase::class, 'pascal', 'came_li_ze', 'CameLiZe', '_'],
            [PascalCase::class, 'pascal', 'came#li#ze', 'CameLiZe', '#'],
            [PascalCase::class, 'pascal', 'came li ze', 'CameLiZe', ' '],
            [PascalCase::class, 'pascal', 'came.li^ze', 'CameLiZe', '.^'],
            [PascalCase::class, 'pascal', 'c_a-m_e-l_i-z_e', 'CAMELIZE', '-_'],
            [PascalCase::class, 'pascal', 'came.li.ze', 'CameLiZe', '.'],
            [PascalCase::class, 'pascal', 'came-li-ze', 'CameLiZe', '-'],
            [PascalCase::class, 'pascal', 'c+a+m+e+l+i+z+e', 'CAMELIZE', '+'],
            [PascalCase::class, 'pascal', 'customer-session', 'CustomerSession', null],
            [PascalCase::class, 'pascal', 'customer Session', 'CustomerSession', ' -_'],
            [PascalCase::class, 'pascal', 'customer-Session', 'CustomerSession', ' -_'],
            [KebabCase::class, 'kebab', 'Camelize', 'Camelize', null],
            [KebabCase::class, 'kebab', 'CameLiZe', 'CameLiZe', null],
            [KebabCase::class, 'kebab', 'Camelize', 'Camelize', null],
            [KebabCase::class, 'kebab', '123camelize', '123camelize', null],
            [KebabCase::class, 'kebab', 'c_a_m_e_l_i_z_e', 'c-a-m-e-l-i-z-e', null],
            [KebabCase::class, 'kebab', 'Camelize', 'Camelize', null],
            [KebabCase::class, 'kebab', 'camel_ize', 'camel-ize', null],
            [KebabCase::class, 'kebab', 'CameLize', 'CameLize', null],
            [KebabCase::class, 'kebab', 'c_a-m_e-l_i-z_e', 'c-a-m-e-l-i-z-e', null],
            [KebabCase::class, 'kebab', 'came_li_ze', 'came-li-ze', null],
            [KebabCase::class, 'kebab', '=_camelize', '=-camelize', '_'],
            [KebabCase::class, 'kebab', 'camelize', 'camelize', '_'],
            [KebabCase::class, 'kebab', 'came_li_ze', 'came-li-ze', '_'],
            [KebabCase::class, 'kebab', 'came#li#ze', 'came-li-ze', '#'],
            [KebabCase::class, 'kebab', 'came li ze', 'came-li-ze', ' '],
            [KebabCase::class, 'kebab', 'came.li^ze', 'came-li-ze', '.^'],
            [KebabCase::class, 'kebab', 'c_a-m_e-l_i-z_e', 'c-a-m-e-l-i-z-e', '-_'],
            [KebabCase::class, 'kebab', 'came.li.ze', 'came-li-ze', '.'],
            [KebabCase::class, 'kebab', 'came-li-ze', 'came-li-ze', '-'],
            [KebabCase::class, 'kebab', 'c+a+m+e+l+i+z+e', 'c-a-m-e-l-i-z-e', '+'],
            [KebabCase::class, 'kebab', 'customer-session', 'customer-session', null],
            [KebabCase::class, 'kebab', 'customer Session', 'customer-Session', ' -_'],
            [KebabCase::class, 'kebab', 'customer-Session', 'customer-Session', ' -_'],
        ];
    }
}
