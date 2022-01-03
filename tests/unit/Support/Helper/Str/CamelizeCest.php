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
        $lowercase = $example[3];

        $actual = $object($value, $delimiter, $lowercase);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getSources(): array
    {
        return [
            ['camelize', 'Camelize', null, false],
            ['CameLiZe', 'Camelize', null, false],
            ['cAmeLize', 'Camelize', null, false],
            ['123camelize', '123camelize', null, false],
            ['c_a_m_e_l_i_z_e', 'CAMELIZE', null, false],
            ['Camelize', 'Camelize', null, false],
            ['camel_ize', 'CamelIze', null, false],
            ['CameLize', 'Camelize', null, false],
            ['c_a-m_e-l_i-z_e', 'CAMELIZE', null, false],
            ['came_li_ze', 'CameLiZe', null, false],
            ['=_camelize', '=Camelize', '_', false],
            ['camelize', 'Camelize', '_', false],
            ['came_li_ze', 'CameLiZe', '_', false],
            ['came#li#ze', 'CameLiZe', '#', false],
            ['came li ze', 'CameLiZe', ' ', false],
            ['came.li^ze', 'CameLiZe', '.^', false],
            ['c_a-m_e-l_i-z_e', 'CAMELIZE', '-_', false],
            ['came.li.ze', 'CameLiZe', '.', false],
            ['came-li-ze', 'CameLiZe', '-', false],
            ['c+a+m+e+l+i+z+e', 'CAMELIZE', '+', false],
            ['customer-session', 'CustomerSession', null, false],
            ['customer Session', 'CustomerSession', ' -_', false],
            ['customer-Session', 'CustomerSession', ' -_', false],
            ['customer-session', 'customerSession', null, true],
            ['customer Session', 'customerSession', ' -_', true],
            ['customer-Session', 'customerSession', ' -_', true],
        ];
    }
}
