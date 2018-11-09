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

class CsvTest
{
    private $config = null;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->config = ['ru' => ['content' => PATH_DATA . 'translation/csv/ru_RU.csv']];
    }

    /**
     * Catch Exception
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     *
     * @expectedException        \Phalcon\Translate\Exception
     * @expectedExceptionMessage Parameter 'content' is required
     */
    public function testContentParamExist(UnitTester $I)
    {
        $this->specify(
            "Parameter 'content' is required",
            function () {
                new Csv([]);
            }
        );
    }

    /**
     * Tests whether a key not exists in the array
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function testNotExists(UnitTester $I)
    {
        $this->specify(
            "The key does not exist with exists",
            function () {
                $params = $this->config['ru'];
                $translator = new Csv($params);

                expect($translator->exists('Hi!'))->false();
            }
        );
    }

    /**
     * Tests whether a key exists in the array
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function testExists(UnitTester $I)
    {
        $this->specify(
            "The key exist with expect",
            function () {
                $params = $this->config['ru'];
                $translator = new Csv($params);

                expect($translator->exists('Hello!'))->true();
            }
        );
    }

    /**
     * Translate into russian
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function testRuTranslate(UnitTester $I)
    {
        $this->specify(
            "The key exist with expect with additional params",
            function () {
                $params = $this->config['ru'];
                $translator = new Csv($params);

                expect($translator->query('Hello!'))->equals('Привет!');
                expect($translator->query(
                    'Hello %fname% %mname% %lname%!',
                    ["fname" => "TestFname", "mname" => "TestMname", "lname" => "TestLname"]
                ))->equals('Привет, TestFname TestMname TestLname!');
            }
        );
    }
}
