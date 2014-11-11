<?php
/**
 * Csv.php
 * \Phalcon\Translate\Adapter\Csv
 *
 * Tests the \Phalcon\Translate\Adapter\Csv component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Ivan Zubok <chi_no@ukr.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Translate\Adapter\Csv;

use Phalcon\Translate\Adapter\Csv as PhTTranslateAdapterCsv;
use Phalcon\Translate\Exception as PhTTranslateException;
use \Codeception\TestCase\Test as CdTest;
use \Codeception\Specify as CdSpecify;

class TranslateCsvTest extends CdTest
{
    use CdSpecify;

    private $config = null;

    /**
     * Initialize data for the tests
     */
    public function _before()
    {
        $this->config = array(
            'ru' => array(
                'content' => PATH_DATA . 'translation/csv/ru_RU.csv',
            ),
        );
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
                new PhTTranslateAdapterCsv(array());
            },
            ['throws' => new PhTTranslateException]
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
                $translator = new PhTTranslateAdapterCsv($params);

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
                $translator = new PhTTranslateAdapterCsv($params);

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
                $translator = new PhTTranslateAdapterCsv($params);

                expect($translator->query('Hello!'))->equals('Привет!');
                expect($translator->query(
                    'Hello %fname% %mname% %lname%!',
                    array("fname" => "TestFname", "mname" => "TestMname", "lname" => "TestLname")
                ))->equals('Привет, TestFname TestMname TestLname!');
            }
        );
    }

}
