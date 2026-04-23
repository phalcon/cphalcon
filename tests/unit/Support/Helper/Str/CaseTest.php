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

use Phalcon\Support\Helper\Str\KebabCase;
use Phalcon\Support\Helper\Str\PascalCase;
use Phalcon\Support\Helper\Str\SnakeCase;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class CaseTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getSources(): array
    {
        return [
            [SnakeCase::class, 'Camelize', 'Camelize', null],
            [SnakeCase::class, 'CameLiZe', 'CameLiZe', null],
            [SnakeCase::class, 'Camelize', 'Camelize', null],
            [SnakeCase::class, '123camelize', '123camelize', null],
            [SnakeCase::class, 'c_a_m_e_l_i_z_e', 'c_a_m_e_l_i_z_e', null],
            [SnakeCase::class, 'Camelize', 'Camelize', null],
            [SnakeCase::class, 'camel_ize', 'camel_ize', null],
            [SnakeCase::class, 'CameLize', 'CameLize', null],
            [SnakeCase::class, 'c_a-m_e-l_i-z_e', 'c_a_m_e_l_i_z_e', null],
            [SnakeCase::class, 'came_li_ze', 'came_li_ze', null],
            [SnakeCase::class, '=_camelize', '=_camelize', '_'],
            [SnakeCase::class, 'camelize', 'camelize', '_'],
            [SnakeCase::class, 'came_li_ze', 'came_li_ze', '_'],
            [SnakeCase::class, 'came#li#ze', 'came_li_ze', '#'],
            [SnakeCase::class, 'came li ze', 'came_li_ze', ' '],
            [SnakeCase::class, 'came.li^ze', 'came_li_ze', '.^'],
            [SnakeCase::class, 'c_a-m_e-l_i-z_e', 'c_a_m_e_l_i_z_e', '-_'],
            [SnakeCase::class, 'came.li.ze', 'came_li_ze', '.'],
            [SnakeCase::class, 'came-li-ze', 'came_li_ze', '-'],
            [SnakeCase::class, 'c+a+m+e+l+i+z+e', 'c_a_m_e_l_i_z_e', '+'],
            [SnakeCase::class, 'customer-session', 'customer_session', null],
            [SnakeCase::class, 'customer Session', 'customer_Session', ' -_'],
            [SnakeCase::class, 'customer-Session', 'customer_Session', ' -_'],
            [PascalCase::class, 'camelize', 'Camelize', null],
            [PascalCase::class, 'CameLiZe', 'Camelize', null],
            [PascalCase::class, 'cAmeLize', 'Camelize', null],
            [PascalCase::class, '123camelize', '123camelize', null],
            [PascalCase::class, 'c_a_m_e_l_i_z_e', 'CAMELIZE', null],
            [PascalCase::class, 'Camelize', 'Camelize', null],
            [PascalCase::class, 'camel_ize', 'CamelIze', null],
            [PascalCase::class, 'CameLize', 'Camelize', null],
            [PascalCase::class, 'c_a-m_e-l_i-z_e', 'CAMELIZE', null],
            [PascalCase::class, 'came_li_ze', 'CameLiZe', null],
            [PascalCase::class, '=_camelize', '=Camelize', '_'],
            [PascalCase::class, 'camelize', 'Camelize', '_'],
            [PascalCase::class, 'came_li_ze', 'CameLiZe', '_'],
            [PascalCase::class, 'came#li#ze', 'CameLiZe', '#'],
            [PascalCase::class, 'came li ze', 'CameLiZe', ' '],
            [PascalCase::class, 'came.li^ze', 'CameLiZe', '.^'],
            [PascalCase::class, 'c_a-m_e-l_i-z_e', 'CAMELIZE', '-_'],
            [PascalCase::class, 'came.li.ze', 'CameLiZe', '.'],
            [PascalCase::class, 'came-li-ze', 'CameLiZe', '-'],
            [PascalCase::class, 'c+a+m+e+l+i+z+e', 'CAMELIZE', '+'],
            [PascalCase::class, 'customer-session', 'CustomerSession', null],
            [PascalCase::class, 'customer Session', 'CustomerSession', ' -_'],
            [PascalCase::class, 'customer-Session', 'CustomerSession', ' -_'],
            [KebabCase::class, 'Camelize', 'Camelize', null],
            [KebabCase::class, 'CameLiZe', 'CameLiZe', null],
            [KebabCase::class, 'Camelize', 'Camelize', null],
            [KebabCase::class, '123camelize', '123camelize', null],
            [KebabCase::class, 'c_a_m_e_l_i_z_e', 'c-a-m-e-l-i-z-e', null],
            [KebabCase::class, 'Camelize', 'Camelize', null],
            [KebabCase::class, 'camel_ize', 'camel-ize', null],
            [KebabCase::class, 'CameLize', 'CameLize', null],
            [KebabCase::class, 'c_a-m_e-l_i-z_e', 'c-a-m-e-l-i-z-e', null],
            [KebabCase::class, 'came_li_ze', 'came-li-ze', null],
            [KebabCase::class, '=_camelize', '=-camelize', '_'],
            [KebabCase::class, 'camelize', 'camelize', '_'],
            [KebabCase::class, 'came_li_ze', 'came-li-ze', '_'],
            [KebabCase::class, 'came#li#ze', 'came-li-ze', '#'],
            [KebabCase::class, 'came li ze', 'came-li-ze', ' '],
            [KebabCase::class, 'came.li^ze', 'came-li-ze', '.^'],
            [KebabCase::class, 'c_a-m_e-l_i-z_e', 'c-a-m-e-l-i-z-e', '-_'],
            [KebabCase::class, 'came.li.ze', 'came-li-ze', '.'],
            [KebabCase::class, 'came-li-ze', 'came-li-ze', '-'],
            [KebabCase::class, 'c+a+m+e+l+i+z+e', 'c-a-m-e-l-i-z-e', '+'],
            [KebabCase::class, 'customer-session', 'customer-session', null],
            [KebabCase::class, 'customer Session', 'customer-Session', ' -_'],
            [KebabCase::class, 'customer-Session', 'customer-Session', ' -_'],
        ];
    }

    /**
     * @dataProvider getSources
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-01-02
     */
    public function testSupportHelperStrCase(
        string $class,
        string $value,
        string $expected,
        ?string $delimiter,
    ): void {
        $object = new $class();

        $actual = $object($value, $delimiter);
        $this->assertSame($expected, $actual);
    }
}
