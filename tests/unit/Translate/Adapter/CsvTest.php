<?php

namespace Phalcon\Test\Unit\Translate\Adapter;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Translate\Adapter\Csv;

/**
 * \Phalcon\Test\Unit\Translate\Adapter\CsvTest
 * Tests the \Phalcon\Translate\Adapter\Csv component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Ivan Zubok <chi_no@ukr.net>
 * @package   Phalcon\Test\Unit\Translate\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CsvTest extends UnitTest
{
    private $config = null;

    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        $this->config = ['ru' => ['content' => PATH_DATA . 'translation/csv/ru_RU.csv']];
    }

    /**
     * Catch Exception
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function testContentParamExist()
    {
        $this->specify(
            "Parameter 'content' is required",
            function () {
                new Csv([]);
            },
            ['throws' => ['Phalcon\Translate\Exception']]
        );
    }

    /**
     * Tests whether a key not exists in the array
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-04
     */
    public function testNotExists()
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
    public function testExists()
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
    public function testRuTranslate()
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
