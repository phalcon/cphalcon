<?php

namespace Phalcon\Tests\unit\Phalcon\Translate\Adapter;

use Phalcon\Translate\Adapter\Gettext;
use Codeception\TestCase\Test as CdTest;
use Codeception\Specify as CdSpecify;

/**
 * GettextTest.php
 * \Phalcon\Translate\Adapter\GettextTest
 *
 * Tests the \Phalcon\Translate\Adapter\Gettext component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <chi_no@ukr.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class GettextTest extends CdTest
{
    use CdSpecify;

    /**
     * Tests whether a key exists in the array
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-15
     */
    public function testExists()
    {
        $this->specify(
            "The key does not exist with exists",
            function () {
                $translator = new Gettext(
                    [
                        'locale'    => 'uk_UA.utf8',
                        'directory' => dirname(ROOT_PATH) . '/unit-tests/locale'
                    ]
                );

                expect($translator->exists('Hello'))->true();
                expect($translator->exists('Some string'))->false();
            }
        );
    }

    /**
     * Tests variable substitution in string with no variables - English
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-15
     */
    public function testVariableSubstitutionInStringWithNoVariablesEnglish()
    {
        $this->specify(
            "Translator does not translate English correctly with passed params and no variables",
            function () {
                $translator = new Gettext(
                    [
                        'locale'        => 'en_US.utf8',
                        'defaultDomain' => 'messages',
                        'directory'     => dirname(ROOT_PATH) . '/unit-tests/locale'
                    ]
                );

                expect($translator->_("你好 %name%！", ['name' => 'Phalcon']))->equals('Hello Phalcon!');
            }
        );
    }

    /**
     * Tests the query with Ukranian
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-15
     */
    public function testQueryUkranian()
    {
        $this->specify(
            "The key does not exist with query in Ukranian",
            function () {
                $translator = new Gettext(
                    [
                        'locale'        => 'uk_UA.utf8',
                        'defaultDomain' => 'messages',
                        'directory'     => dirname(ROOT_PATH) . '/unit-tests/locale'
                    ]
                );

                expect($translator->query('Hello'))->equals('Привіт');
            }
        );

        $this->specify(
            "The key does not exist with query in Ukranian with alternative syntax",
            function () {
                $translator = new Gettext(
                    [
                        'locale'        => 'uk_UA.utf8',
                        'defaultDomain' => 'messages',
                        'directory'     => dirname(ROOT_PATH) . '/unit-tests/locale'
                    ]
                );

                expect($translator->_('Hello'))->equals('Привіт');
            }
        );
    }

    /**
     * Tests translator with array access in Chinese
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-15
     */
    public function testWithArrayAccess()
    {
        $this->specify(
            "Incorrect result with array access in Chinese",
            function () {
                $translator = new Gettext(
                    [
                        'locale'        => 'en_US.utf8',
                        'defaultDomain' => 'messages',
                        'directory'     => dirname(ROOT_PATH) . '/unit-tests/locale'
                    ]
                );

                expect(isset($translator['你好！']))->true();
                expect(isset($translator['更多的中国']))->false();
                expect($translator['你好！'])->equals('Hello!');
            }
        );
    }
}
