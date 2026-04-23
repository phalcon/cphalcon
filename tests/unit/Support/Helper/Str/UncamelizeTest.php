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

use Phalcon\Support\Helper\Str\Uncamelize;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class UncamelizeTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getSources(): array
    {
        return [
            ['camelize', 'camelize', '_'],
            ['CameLiZe', 'came_li_ze', '_'],
            ['cAmeLize', 'c_ame_lize', '_'],
            ['_camelize', '_camelize', '_'],
            ['123camelize', '123camelize', '_'],
            ['c_a_m_e_l_i_z_e', 'c_a_m_e_l_i_z_e', '_'],
            ['Camelize', 'camelize', '_'],
            ['camel_ize', 'camel_ize', '_'],
            ['CameLize', 'came_lize', '_'],
            ['Camelize', 'camelize', '_'],
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

    /**
     * @dataProvider getSources
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getSources')]
    public function testSupportHelperStrUncamelize(
        string $value,
        string $expected,
        string $delimiter,
    ): void {
        $object = new Uncamelize();
        $actual = $object($value, $delimiter);

        $this->assertSame($expected, $actual);
    }
}
