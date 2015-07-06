<?php
/**
 * UnitTest.php
 * \Phalcon\Translate\Adapter\Gettext\UnitTest
 *
 * Tests the \Phalcon\Translate\Adapter\Gettext component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Thien Tran <fcduythien@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\Translate\Adapter\Gettext;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Translate\Exception as PhTranslateException;
use \Phalcon\Translate\Adapter\Gettext as PhTranslateAdapterGettext;

class UnitTest extends PhTestUnitTestCase
{
    /**
     * Tests testQueryVietNam
     *
     * @since  2015-06-25
     */
    public function testQueryVietNam()
    {
        $translator = new PhTranslateAdapterGettext([
            'locale'             => 'vi_VN',
            'defaultDomain'      => 'messages',
            'directory'          => __DIR__ .'/locale'
        ]);
        $name  =  "Thien";
        $textA =  printf("Xin chào, Thien, nó là tốt đẹp để xem bạn ngày hôm nay\n", $name);
        $textB =  printf($translator->t("Hello, %s, it is nice to see you today\n"), $name);

        $this->assertEquals('Xin chào', $translator->t('Hello'));
        $this->assertEquals($textA, $textB);


    }
    /**
     * Tests testQueryGermany
     *
     * @since  2015-06-25
     */
    public function testQueryGermany()
    {
        $translator = new PhTranslateAdapterGettext([
            'locale'             => 'de_DE',
            'defaultDomain'      => 'messages',
            'directory'          => __DIR__. '/locale'
        ]);
        $this->assertEquals('Hallo', $translator->t('Hello'));
    }

    /**
     * Tests Spanish
     *
     * @since  2015-06-25
     */
    public function testQuerySpanish()
    {
        $translator = new PhTranslateAdapterGettext([
            'locale'             => 'es_ES',
            'defaultDomain'      => 'messages',
            'directory'          => __DIR__. '/locale'
        ]);
        $this->assertEquals('Hallo', $translator->t('Hello'));
    }
}