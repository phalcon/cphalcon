<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter;

use Phalcon\Translate\Adapter\Csv;
use UnitTester;
use function dataFolder;

class CsvCest
{
    private $config = null;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->config = ['ru' => ['content' => dataFolder('assets/translation/csv/ru_RU.csv')]];
    }


    /**
     * Translate into russian
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function testRuTranslate(UnitTester $I)
    {
        $params     = $this->config['ru'];
        $translator = new Csv($params);

        $expect = 'Привет!';
        $actual = $translator->query('Hello!');
        $I->assertEquals($expect, $actual);

        $expect = 'Привет, TestFname TestMname TestLname!';
        $actual = $translator->query(
            'Hello %fname% %mname% %lname%!',
            ["fname" => "TestFname", "mname" => "TestMname", "lname" => "TestLname"]
        );
        $I->assertEquals($expect, $actual);
    }
}
